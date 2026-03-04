#include "lcd_bsp.h"
#include "esp_lcd_sh8601.h"
#include "lcd_config.h"
#include "cst816.h"
#include "esp_idf_version.h"
#include "esp_heap_caps.h"
#include "esp_log.h"
#include <stdio.h>
static SemaphoreHandle_t lvgl_mux = NULL; //mutex semaphores
#define LCD_HOST    SPI2_HOST
static const char *TAG = "lcd_bsp";
#if LCD_DEBUG_LOGS
#define DBG_PRINTF(...) do { printf(__VA_ARGS__); fflush(stdout); } while (0)
#else
#define DBG_PRINTF(...) do { } while (0)
#endif
static volatile bool s_lvgl_flush_ready_enabled = false;
extern void ui_init(void) __attribute__((weak));
extern lv_obj_t *ui_ArcDoel __attribute__((weak));
extern lv_obj_t *ui_Temp __attribute__((weak));
extern lv_obj_t *ui_Temperature1 __attribute__((weak));

static void encoder_init(void);
static void encoder_poll_update_ui(void);

static uint8_t s_encoder_a_level = 0;
static uint8_t s_encoder_b_level = 0;
static uint8_t s_encoder_a_debounce = 0;
static uint8_t s_encoder_b_debounce = 0;
static int8_t s_encoder_step_accum = 0;
static uint32_t s_encoder_last_poll_ms = 0;
static bool s_encoder_ui_missing_logged = false;

#define SH8601_ID 0x86
#define CO5300_ID 0xff

#if LCD_ENCODER_USE_ALT_PINSET
#define LCD_ENCODER_PIN_A EXAMPLE_PIN_NUM_ENCODER_A_ALT
#define LCD_ENCODER_PIN_B EXAMPLE_PIN_NUM_ENCODER_B_ALT
#else
#define LCD_ENCODER_PIN_A EXAMPLE_PIN_NUM_ENCODER_A
#define LCD_ENCODER_PIN_B EXAMPLE_PIN_NUM_ENCODER_B
#endif

#if LCD_ENCODER_DEBUG_LOGS
#define ENCODER_LOGI(...) ESP_LOGI(TAG, __VA_ARGS__)
#else
#define ENCODER_LOGI(...) do { } while (0)
#endif

#define LCD_ENCODER_EXAMPLE_DEBOUNCE_TICKS 2



static esp_lcd_panel_io_handle_t amoled_panel_io_handle = NULL; 

static const sh8601_lcd_init_cmd_t lcd_init_cmds[] = 
{
  {0xF0, (uint8_t[]){0x28}, 1, 0},
  {0xF2, (uint8_t[]){0x28}, 1, 0},
  {0x73, (uint8_t[]){0xF0}, 1, 0},
  {0x7C, (uint8_t[]){0xD1}, 1, 0},
  {0x83, (uint8_t[]){0xE0}, 1, 0},
  {0x84, (uint8_t[]){0x61}, 1, 0},
  {0xF2, (uint8_t[]){0x82}, 1, 0},
  {0xF0, (uint8_t[]){0x00}, 1, 0},
  {0xF0, (uint8_t[]){0x01}, 1, 0},
  {0xF1, (uint8_t[]){0x01}, 1, 0},
  {0xB0, (uint8_t[]){0x56}, 1, 0},
  {0xB1, (uint8_t[]){0x4D}, 1, 0},
  {0xB2, (uint8_t[]){0x24}, 1, 0},
  {0xB4, (uint8_t[]){0x87}, 1, 0},
  {0xB5, (uint8_t[]){0x44}, 1, 0},
  {0xB6, (uint8_t[]){0x8B}, 1, 0},
  {0xB7, (uint8_t[]){0x40}, 1, 0},
  {0xB8, (uint8_t[]){0x86}, 1, 0},
  {0xBA, (uint8_t[]){0x00}, 1, 0},
  {0xBB, (uint8_t[]){0x08}, 1, 0},
  {0xBC, (uint8_t[]){0x08}, 1, 0},
  {0xBD, (uint8_t[]){0x00}, 1, 0},
  {0xC0, (uint8_t[]){0x80}, 1, 0},
  {0xC1, (uint8_t[]){0x10}, 1, 0},
  {0xC2, (uint8_t[]){0x37}, 1, 0},
  {0xC3, (uint8_t[]){0x80}, 1, 0},
  {0xC4, (uint8_t[]){0x10}, 1, 0},
  {0xC5, (uint8_t[]){0x37}, 1, 0},
  {0xC6, (uint8_t[]){0xA9}, 1, 0},
  {0xC7, (uint8_t[]){0x41}, 1, 0},
  {0xC8, (uint8_t[]){0x01}, 1, 0},
  {0xC9, (uint8_t[]){0xA9}, 1, 0},
  {0xCA, (uint8_t[]){0x41}, 1, 0},
  {0xCB, (uint8_t[]){0x01}, 1, 0},
  {0xD0, (uint8_t[]){0x91}, 1, 0},
  {0xD1, (uint8_t[]){0x68}, 1, 0},
  {0xD2, (uint8_t[]){0x68}, 1, 0},
  {0xF5, (uint8_t[]){0x00, 0xA5}, 2, 0},
  {0xDD, (uint8_t[]){0x4F}, 1, 0},
  {0xDE, (uint8_t[]){0x4F}, 1, 0},
  {0xF1, (uint8_t[]){0x10}, 1, 0},
  {0xF0, (uint8_t[]){0x00}, 1, 0},
  {0xF0, (uint8_t[]){0x02}, 1, 0},
  {0xE0, (uint8_t[]){0xF0, 0x0A, 0x10, 0x09, 0x09, 0x36, 0x35, 0x33, 0x4A, 0x29, 0x15, 0x15, 0x2E, 0x34}, 14, 0},
  {0xE1, (uint8_t[]){0xF0, 0x0A, 0x0F, 0x08, 0x08, 0x05, 0x34, 0x33, 0x4A, 0x39, 0x15, 0x15, 0x2D, 0x33}, 14, 0},
  {0xF0, (uint8_t[]){0x10}, 1, 0},
  {0xF3, (uint8_t[]){0x10}, 1, 0},
  {0xE0, (uint8_t[]){0x07}, 1, 0},
  {0xE1, (uint8_t[]){0x00}, 1, 0},
  {0xE2, (uint8_t[]){0x00}, 1, 0},
  {0xE3, (uint8_t[]){0x00}, 1, 0},
  {0xE4, (uint8_t[]){0xE0}, 1, 0},
  {0xE5, (uint8_t[]){0x06}, 1, 0},
  {0xE6, (uint8_t[]){0x21}, 1, 0},
  {0xE7, (uint8_t[]){0x01}, 1, 0},
  {0xE8, (uint8_t[]){0x05}, 1, 0},
  {0xE9, (uint8_t[]){0x02}, 1, 0},
  {0xEA, (uint8_t[]){0xDA}, 1, 0},
  {0xEB, (uint8_t[]){0x00}, 1, 0},
  {0xEC, (uint8_t[]){0x00}, 1, 0},
  {0xED, (uint8_t[]){0x0F}, 1, 0},
  {0xEE, (uint8_t[]){0x00}, 1, 0},
  {0xEF, (uint8_t[]){0x00}, 1, 0},
  {0xF8, (uint8_t[]){0x00}, 1, 0},
  {0xF9, (uint8_t[]){0x00}, 1, 0},
  {0xFA, (uint8_t[]){0x00}, 1, 0},
  {0xFB, (uint8_t[]){0x00}, 1, 0},
  {0xFC, (uint8_t[]){0x00}, 1, 0},
  {0xFD, (uint8_t[]){0x00}, 1, 0},
  {0xFE, (uint8_t[]){0x00}, 1, 0},
  {0xFF, (uint8_t[]){0x00}, 1, 0},
  {0x60, (uint8_t[]){0x40}, 1, 0},
  {0x61, (uint8_t[]){0x04}, 1, 0},
  {0x62, (uint8_t[]){0x00}, 1, 0},
  {0x63, (uint8_t[]){0x42}, 1, 0},
  {0x64, (uint8_t[]){0xD9}, 1, 0},
  {0x65, (uint8_t[]){0x00}, 1, 0},
  {0x66, (uint8_t[]){0x00}, 1, 0},
  {0x67, (uint8_t[]){0x00}, 1, 0},
  {0x68, (uint8_t[]){0x00}, 1, 0},
  {0x69, (uint8_t[]){0x00}, 1, 0},
  {0x6A, (uint8_t[]){0x00}, 1, 0},
  {0x6B, (uint8_t[]){0x00}, 1, 0},
  {0x70, (uint8_t[]){0x40}, 1, 0},
  {0x71, (uint8_t[]){0x03}, 1, 0},
  {0x72, (uint8_t[]){0x00}, 1, 0},
  {0x73, (uint8_t[]){0x42}, 1, 0},
  {0x74, (uint8_t[]){0xD8}, 1, 0},
  {0x75, (uint8_t[]){0x00}, 1, 0},
  {0x76, (uint8_t[]){0x00}, 1, 0},
  {0x77, (uint8_t[]){0x00}, 1, 0},
  {0x78, (uint8_t[]){0x00}, 1, 0},
  {0x79, (uint8_t[]){0x00}, 1, 0},
  {0x7A, (uint8_t[]){0x00}, 1, 0},
  {0x7B, (uint8_t[]){0x00}, 1, 0},
  {0x80, (uint8_t[]){0x48}, 1, 0},
  {0x81, (uint8_t[]){0x00}, 1, 0},
  {0x82, (uint8_t[]){0x06}, 1, 0},
  {0x83, (uint8_t[]){0x02}, 1, 0},
  {0x84, (uint8_t[]){0xD6}, 1, 0},
  {0x85, (uint8_t[]){0x04}, 1, 0},
  {0x86, (uint8_t[]){0x00}, 1, 0},
  {0x87, (uint8_t[]){0x00}, 1, 0},
  {0x88, (uint8_t[]){0x48}, 1, 0},
  {0x89, (uint8_t[]){0x00}, 1, 0},
  {0x8A, (uint8_t[]){0x08}, 1, 0},
  {0x8B, (uint8_t[]){0x02}, 1, 0},
  {0x8C, (uint8_t[]){0xD8}, 1, 0},
  {0x8D, (uint8_t[]){0x04}, 1, 0},
  {0x8E, (uint8_t[]){0x00}, 1, 0},
  {0x8F, (uint8_t[]){0x00}, 1, 0},
  {0x90, (uint8_t[]){0x48}, 1, 0},
  {0x91, (uint8_t[]){0x00}, 1, 0},
  {0x92, (uint8_t[]){0x0A}, 1, 0},
  {0x93, (uint8_t[]){0x02}, 1, 0},
  {0x94, (uint8_t[]){0xDA}, 1, 0},
  {0x95, (uint8_t[]){0x04}, 1, 0},
  {0x96, (uint8_t[]){0x00}, 1, 0},
  {0x97, (uint8_t[]){0x00}, 1, 0},
  {0x98, (uint8_t[]){0x48}, 1, 0},
  {0x99, (uint8_t[]){0x00}, 1, 0},
  {0x9A, (uint8_t[]){0x0C}, 1, 0},
  {0x9B, (uint8_t[]){0x02}, 1, 0},
  {0x9C, (uint8_t[]){0xDC}, 1, 0},
  {0x9D, (uint8_t[]){0x04}, 1, 0},
  {0x9E, (uint8_t[]){0x00}, 1, 0},
  {0x9F, (uint8_t[]){0x00}, 1, 0},
  {0xA0, (uint8_t[]){0x48}, 1, 0},
  {0xA1, (uint8_t[]){0x00}, 1, 0},
  {0xA2, (uint8_t[]){0x05}, 1, 0},
  {0xA3, (uint8_t[]){0x02}, 1, 0},
  {0xA4, (uint8_t[]){0xD5}, 1, 0},
  {0xA5, (uint8_t[]){0x04}, 1, 0},
  {0xA6, (uint8_t[]){0x00}, 1, 0},
  {0xA7, (uint8_t[]){0x00}, 1, 0},
  {0xA8, (uint8_t[]){0x48}, 1, 0},
  {0xA9, (uint8_t[]){0x00}, 1, 0},
  {0xAA, (uint8_t[]){0x07}, 1, 0},
  {0xAB, (uint8_t[]){0x02}, 1, 0},
  {0xAC, (uint8_t[]){0xD7}, 1, 0},
  {0xAD, (uint8_t[]){0x04}, 1, 0},
  {0xAE, (uint8_t[]){0x00}, 1, 0},
  {0xAF, (uint8_t[]){0x00}, 1, 0},
  {0xB0, (uint8_t[]){0x48}, 1, 0},
  {0xB1, (uint8_t[]){0x00}, 1, 0},
  {0xB2, (uint8_t[]){0x09}, 1, 0},
  {0xB3, (uint8_t[]){0x02}, 1, 0},
  {0xB4, (uint8_t[]){0xD9}, 1, 0},
  {0xB5, (uint8_t[]){0x04}, 1, 0},
  {0xB6, (uint8_t[]){0x00}, 1, 0},
  {0xB7, (uint8_t[]){0x00}, 1, 0},
  {0xB8, (uint8_t[]){0x48}, 1, 0},
  {0xB9, (uint8_t[]){0x00}, 1, 0},
  {0xBA, (uint8_t[]){0x0B}, 1, 0},
  {0xBB, (uint8_t[]){0x02}, 1, 0},
  {0xBC, (uint8_t[]){0xDB}, 1, 0},
  {0xBD, (uint8_t[]){0x04}, 1, 0},
  {0xBE, (uint8_t[]){0x00}, 1, 0},
  {0xBF, (uint8_t[]){0x00}, 1, 0},
  {0xC0, (uint8_t[]){0x10}, 1, 0},
  {0xC1, (uint8_t[]){0x47}, 1, 0},
  {0xC2, (uint8_t[]){0x56}, 1, 0},
  {0xC3, (uint8_t[]){0x65}, 1, 0},
  {0xC4, (uint8_t[]){0x74}, 1, 0},
  {0xC5, (uint8_t[]){0x88}, 1, 0},
  {0xC6, (uint8_t[]){0x99}, 1, 0},
  {0xC7, (uint8_t[]){0x01}, 1, 0},
  {0xC8, (uint8_t[]){0xBB}, 1, 0},
  {0xC9, (uint8_t[]){0xAA}, 1, 0},
  {0xD0, (uint8_t[]){0x10}, 1, 0},
  {0xD1, (uint8_t[]){0x47}, 1, 0},
  {0xD2, (uint8_t[]){0x56}, 1, 0},
  {0xD3, (uint8_t[]){0x65}, 1, 0},
  {0xD4, (uint8_t[]){0x74}, 1, 0},
  {0xD5, (uint8_t[]){0x88}, 1, 0},
  {0xD6, (uint8_t[]){0x99}, 1, 0},
  {0xD7, (uint8_t[]){0x01}, 1, 0},
  {0xD8, (uint8_t[]){0xBB}, 1, 0},
  {0xD9, (uint8_t[]){0xAA}, 1, 0},
  {0xF3, (uint8_t[]){0x01}, 1, 0},
  {0xF0, (uint8_t[]){0x00}, 1, 0},
  {0x21, (uint8_t[]){0x00}, 1, 0},
  {0x11, (uint8_t[]){0x00}, 1, 120},
  {0x29, (uint8_t[]){0x00}, 1, 0},
#ifdef EXAMPLE_Rotate_90
  {0x36, (uint8_t[]){0x60}, 1, 0},
#else
  {0x36, (uint8_t[]){0x00}, 1, 0},
#endif
};

static void panel_fill_solid_color(esp_lcd_panel_handle_t panel_handle, uint16_t color565)
{
  static uint16_t *line_buf = NULL;
  if (line_buf == NULL) {
    line_buf = heap_caps_malloc(EXAMPLE_LCD_H_RES * sizeof(uint16_t), MALLOC_CAP_DMA);
    if (!line_buf) {
      ESP_LOGE(TAG, "Failed to allocate panel test line buffer");
      return;
    }
  }

  for (int x = 0; x < EXAMPLE_LCD_H_RES; x++) {
    line_buf[x] = color565;
  }

  for (int y = 0; y < EXAMPLE_LCD_V_RES; y++) {
    esp_lcd_panel_draw_bitmap(panel_handle, 0, y, EXAMPLE_LCD_H_RES, y + 1, line_buf);
    // tx_param blocks until pending tx_color queue is drained; keeps line_buf reuse safe.
    esp_lcd_panel_io_tx_param(amoled_panel_io_handle, LCD_CMD_NOP, NULL, 0);
  }
}

static void panel_known_good_render_test(esp_lcd_panel_handle_t panel_handle)
{
#if LCD_RUN_PANEL_SOLID_COLOR_TEST
  DBG_PRINTF("[DBG] panel: solid color test start\r\n");
  static const uint16_t colors[] = {0xF800, 0x07E0, 0x001F, 0xFFFF, 0x0000};
  static const char *names[] = {"RED", "GREEN", "BLUE", "WHITE", "BLACK"};
  const int count = sizeof(colors) / sizeof(colors[0]);

  for (int i = 0; i < count; i++) {
    ESP_LOGI(TAG, "Panel solid test color: %s", names[i]);
    DBG_PRINTF("[DBG] panel: fill %s\r\n", names[i]);
    panel_fill_solid_color(panel_handle, colors[i]);
    vTaskDelay(pdMS_TO_TICKS(LCD_PANEL_TEST_COLOR_HOLD_MS));
  }
  DBG_PRINTF("[DBG] panel: solid color test done\r\n");

#if !LCD_START_LV_DEMO_WIDGETS
  // Keep a visible end-state when demo is disabled.
  DBG_PRINTF("[DBG] panel: hold WHITE (demo disabled)\r\n");
  panel_fill_solid_color(panel_handle, 0xFFFF);
#endif
#else
  (void)panel_handle;
#endif
}

static void create_fallback_ui(void)
{
  lv_obj_t *scr = lv_scr_act();
  lv_obj_set_style_bg_color(scr, lv_color_hex(0x0D1B2A), 0);
  lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);

  lv_obj_t *label = lv_label_create(scr);
  lv_label_set_text(label, "ESP32-S3 Knob Touch\nUI fallback actief");
  lv_obj_set_style_text_color(label, lv_color_hex(0xE0E1DD), 0);
  lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_center(label);
}

static int8_t encoder_process_channel(uint8_t current_level, uint8_t *prev_level, uint8_t *debounce_cnt, int8_t event_delta)
{
  if (current_level == 0) {
    if (current_level != *prev_level) {
      *debounce_cnt = 0;
    } else {
      (*debounce_cnt)++;
    }
  } else {
    if (current_level != *prev_level && ++(*debounce_cnt) >= LCD_ENCODER_EXAMPLE_DEBOUNCE_TICKS) {
      *debounce_cnt = 0;
      *prev_level = current_level;
      return event_delta;
    }
    *debounce_cnt = 0;
  }

  *prev_level = current_level;
  return 0;
}

static void encoder_init(void)
{
#if LCD_USE_ROTARY_ENCODER
  const gpio_config_t cfg = {
      .pin_bit_mask = (1ULL << LCD_ENCODER_PIN_A) | (1ULL << LCD_ENCODER_PIN_B),
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .intr_type = GPIO_INTR_DISABLE,
  };
  if (gpio_config(&cfg) != ESP_OK) {
    ESP_LOGW(TAG, "Failed to init rotary GPIO");
    return;
  }
  const uint8_t a = (uint8_t)gpio_get_level((gpio_num_t)LCD_ENCODER_PIN_A);
  const uint8_t b = (uint8_t)gpio_get_level((gpio_num_t)LCD_ENCODER_PIN_B);
  s_encoder_a_level = a;
  s_encoder_b_level = b;
  s_encoder_a_debounce = 0;
  s_encoder_b_debounce = 0;
  s_encoder_step_accum = 0;
  s_encoder_last_poll_ms = 0;
  s_encoder_ui_missing_logged = false;
  ENCODER_LOGI("ENC init: pinA=%d pinB=%d A=%u B=%u steps=%d invert=%d poll=%dms altPins=%d",
               LCD_ENCODER_PIN_A, LCD_ENCODER_PIN_B, s_encoder_a_level, s_encoder_b_level,
               LCD_ENCODER_STEPS_PER_DETENT, LCD_ENCODER_INVERT_DIRECTION,
               LCD_ENCODER_POLL_INTERVAL_MS, LCD_ENCODER_USE_ALT_PINSET);
#endif
}

static void encoder_poll_update_ui(void)
{
#if LCD_USE_ROTARY_ENCODER
  if (ui_ArcDoel == NULL || !lv_obj_is_valid(ui_ArcDoel) || lv_obj_get_screen(ui_ArcDoel) != lv_scr_act()) {
    if (!s_encoder_ui_missing_logged) {
      ENCODER_LOGI("ENC ui not ready/active: arc=%p valid=%d on_active_screen=%d",
                   (void *)ui_ArcDoel,
                   (ui_ArcDoel != NULL) ? lv_obj_is_valid(ui_ArcDoel) : 0,
                   (ui_ArcDoel != NULL && lv_obj_is_valid(ui_ArcDoel) && lv_obj_get_screen(ui_ArcDoel) == lv_scr_act()) ? 1 : 0);
      s_encoder_ui_missing_logged = true;
    }
    return;
  }
  s_encoder_ui_missing_logged = false;

  const uint8_t a = (uint8_t)gpio_get_level((gpio_num_t)LCD_ENCODER_PIN_A);
  const uint8_t b = (uint8_t)gpio_get_level((gpio_num_t)LCD_ENCODER_PIN_B);
  const uint8_t prev_a = s_encoder_a_level;
  const uint8_t prev_b = s_encoder_b_level;
  int8_t delta = 0;
  delta += encoder_process_channel(a, &s_encoder_a_level, &s_encoder_a_debounce, 1);
  delta += encoder_process_channel(b, &s_encoder_b_level, &s_encoder_b_debounce, -1);
  if (delta != 0 || a != prev_a || b != prev_b) {
    ENCODER_LOGI("ENC raw: A=%u B=%u prevA=%u prevB=%u a_db=%u b_db=%u delta=%d",
                 a, b, prev_a, prev_b, s_encoder_a_debounce, s_encoder_b_debounce, delta);
  }
#if LCD_ENCODER_INVERT_DIRECTION
  delta = (int8_t)(-delta);
#endif
  if (delta == 0) {
    return;
  }
  s_encoder_step_accum += delta;
  ENCODER_LOGI("ENC accum: delta=%d accum=%d", delta, s_encoder_step_accum);

  while (s_encoder_step_accum >= LCD_ENCODER_STEPS_PER_DETENT || s_encoder_step_accum <= -LCD_ENCODER_STEPS_PER_DETENT) {
    const int detent = (s_encoder_step_accum > 0) ? 1 : -1;
    s_encoder_step_accum -= (int8_t)(detent * LCD_ENCODER_STEPS_PER_DETENT);

    int value = lv_arc_get_value(ui_ArcDoel);
    const int min = lv_arc_get_min_value(ui_ArcDoel);
    const int max = lv_arc_get_max_value(ui_ArcDoel);
    const int old_value = value;
    value += detent;
    if (value < min) value = min;
    if (value > max) value = max;
    lv_arc_set_value(ui_ArcDoel, value);
    ENCODER_LOGI("ENC detent: detent=%d old=%d new=%d min=%d max=%d accum_rem=%d",
                 detent, old_value, value, min, max, s_encoder_step_accum);

    // Keep thermostat labels synced with the target arc value.
    if (ui_Temp) {
      char buf[8];
      lv_snprintf(buf, sizeof(buf), "%d", value);
      lv_label_set_text(ui_Temp, buf);
    }
    if (ui_Temperature1) {
      char buf[8];
      lv_snprintf(buf, sizeof(buf), "%d", value);
      lv_label_set_text(ui_Temperature1, buf);
    }
    ENCODER_LOGI("ENC write: arc=%d temp=%d", value, value);
  }
#endif
}

void lcd_lvgl_Init(void)
{
  static lv_disp_draw_buf_t disp_buf; // contains internal graphic buffer(s) called draw buffer(s)
  static lv_disp_drv_t disp_drv;      // contains callback functions

  s_lvgl_flush_ready_enabled = false;
  DBG_PRINTF("[DBG] lcd_lvgl_Init: enter\r\n");
  ESP_LOGI(TAG, "LCD config: mode=%s color_order=%s pclk=%dMHz flush=%s qspi_cmd=%s qspi_cmd_bits=%d qspi_octal=%d dc_as_cmd=%d init=%s",
           LCD_USE_QSPI ? "QSPI" : "SPI",
           LCD_COLOR_ORDER_BGR ? "BGR" : "RGB",
           LCD_QSPI_PCLK_40MHZ ? 40 : (LCD_QSPI_PCLK_10MHZ ? 10 : 20),
           LCD_LVGL_ASYNC_FLUSH ? "ASYNC_CB" : "SYNC",
           LCD_QSPI_CMD_PACKING_ALT ? "ALT" : "DEFAULT",
           LCD_QSPI_CMD_BITS_8 ? 8 : 32,
           LCD_QSPI_OCTAL_MODE ? 1 : 0,
           LCD_DC_AS_CMD_PHASE ? 1 : 0,
           LCD_USE_CUSTOM_INIT_CMDS ? "CUSTOM" : "DRIVER_DEFAULT");

  const spi_bus_config_t buscfg =
#if LCD_USE_QSPI
      SH8601_PANEL_BUS_QSPI_CONFIG(EXAMPLE_PIN_NUM_LCD_PCLK,
                                   EXAMPLE_PIN_NUM_LCD_DATA0,
                                   EXAMPLE_PIN_NUM_LCD_DATA1,
                                   EXAMPLE_PIN_NUM_LCD_DATA2,
                                   EXAMPLE_PIN_NUM_LCD_DATA3,
                                   EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES * LCD_BIT_PER_PIXEL / 8);
#else
      SH8601_PANEL_BUS_SPI_CONFIG(EXAMPLE_PIN_NUM_LCD_PCLK,
                                  EXAMPLE_PIN_NUM_LCD_DATA0,
                                  EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES * LCD_BIT_PER_PIXEL / 8);
#endif
  ESP_ERROR_CHECK_WITHOUT_ABORT(spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO));
  DBG_PRINTF("[DBG] lcd_lvgl_Init: spi_bus_initialize done\r\n");
  esp_lcd_panel_io_handle_t io_handle = NULL;

  const esp_lcd_panel_io_spi_config_t io_config =
#if LCD_USE_QSPI
      SH8601_PANEL_IO_QSPI_CONFIG(EXAMPLE_PIN_NUM_LCD_CS,
#if LCD_LVGL_ASYNC_FLUSH
                                  example_notify_lvgl_flush_ready,
                                  &disp_drv);
#else
                                  NULL,
                                  NULL);
#endif
#else
      SH8601_PANEL_IO_SPI_CONFIG(EXAMPLE_PIN_NUM_LCD_CS,
                                 EXAMPLE_PIN_NUM_LCD_DC,
#if LCD_LVGL_ASYNC_FLUSH
                                 example_notify_lvgl_flush_ready,
                                 &disp_drv);
#else
                                 NULL,
                                 NULL);
#endif
#endif

  sh8601_vendor_config_t vendor_config = 
  {
    .init_cmds = LCD_USE_CUSTOM_INIT_CMDS ? lcd_init_cmds : NULL,
    .init_cmds_size = LCD_USE_CUSTOM_INIT_CMDS ? (sizeof(lcd_init_cmds) / sizeof(lcd_init_cmds[0])) : 0,
    .flags = 
    {
      .use_qspi_interface = LCD_USE_QSPI,
    },
  };
  ESP_ERROR_CHECK_WITHOUT_ABORT(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle));
  DBG_PRINTF("[DBG] lcd_lvgl_Init: panel_io created\r\n");
  amoled_panel_io_handle = io_handle;
  esp_lcd_panel_handle_t panel_handle = NULL;
  const esp_lcd_panel_dev_config_t panel_config = 
  {
    .reset_gpio_num = EXAMPLE_PIN_NUM_LCD_RST,
#if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(5, 3, 0)
    .rgb_ele_order = LCD_COLOR_ORDER_BGR ? LCD_RGB_ELEMENT_ORDER_BGR : LCD_RGB_ELEMENT_ORDER_RGB,
#else
    .color_space = LCD_COLOR_ORDER_BGR ? ESP_LCD_COLOR_SPACE_BGR : ESP_LCD_COLOR_SPACE_RGB,
#endif
    .bits_per_pixel = LCD_BIT_PER_PIXEL,
    .vendor_config = &vendor_config,
  };
  ESP_ERROR_CHECK_WITHOUT_ABORT(esp_lcd_new_panel_sh8601(io_handle, &panel_config, &panel_handle));
  DBG_PRINTF("[DBG] lcd_lvgl_Init: sh8601 panel created\r\n");
  ESP_ERROR_CHECK_WITHOUT_ABORT(esp_lcd_panel_reset(panel_handle));
  DBG_PRINTF("[DBG] lcd_lvgl_Init: panel reset done\r\n");
  ESP_ERROR_CHECK_WITHOUT_ABORT(esp_lcd_panel_init(panel_handle));
  DBG_PRINTF("[DBG] lcd_lvgl_Init: panel init done\r\n");
#if LCD_EXPLICIT_DISP_ON
  ESP_ERROR_CHECK_WITHOUT_ABORT(esp_lcd_panel_disp_on_off(panel_handle, true));
  DBG_PRINTF("[DBG] lcd_lvgl_Init: panel display ON\r\n");
#else
  DBG_PRINTF("[DBG] lcd_lvgl_Init: panel display ON skipped (LCD_EXPLICIT_DISP_ON=0)\r\n");
#endif
  panel_known_good_render_test(panel_handle);
  DBG_PRINTF("[DBG] lcd_lvgl_Init: panel color test returned\r\n");

  lv_init();
  lv_color_t *buf1 = heap_caps_malloc(EXAMPLE_LCD_H_RES * EXAMPLE_LVGL_BUF_HEIGHT * sizeof(lv_color_t), MALLOC_CAP_DMA);
  if (!buf1) {
    ESP_LOGE(TAG, "Failed to allocate LVGL buf1");
    return;
  }
  lv_color_t *buf2 = heap_caps_malloc(EXAMPLE_LCD_H_RES * EXAMPLE_LVGL_BUF_HEIGHT * sizeof(lv_color_t), MALLOC_CAP_DMA);
  if (!buf2) {
    ESP_LOGW(TAG, "LVGL buf2 allocation failed, falling back to single buffer");
  }
  lv_disp_draw_buf_init(&disp_buf, buf1, buf2, EXAMPLE_LCD_H_RES * EXAMPLE_LVGL_BUF_HEIGHT);
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = EXAMPLE_LCD_H_RES;
  disp_drv.ver_res = EXAMPLE_LCD_V_RES;
  disp_drv.flush_cb = example_lvgl_flush_cb;
  disp_drv.rounder_cb = example_lvgl_rounder_cb;
  disp_drv.draw_buf = &disp_buf;
  disp_drv.user_data = panel_handle;
  lv_disp_t *disp = lv_disp_drv_register(&disp_drv);
  s_lvgl_flush_ready_enabled = true;
  DBG_PRINTF("[DBG] lcd_lvgl_Init: lvgl display driver registered\r\n");

  static lv_indev_drv_t indev_drv;    // Input device driver (Touch)
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.disp = disp;
  indev_drv.read_cb = example_lvgl_touch_cb;
  lv_indev_drv_register(&indev_drv);
  DBG_PRINTF("[DBG] lcd_lvgl_Init: touch indev registered\r\n");

  const esp_timer_create_args_t lvgl_tick_timer_args = 
  {
    .callback = &example_increase_lvgl_tick,
    .name = "lvgl_tick"
  };
  esp_timer_handle_t lvgl_tick_timer = NULL;
  ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, EXAMPLE_LVGL_TICK_PERIOD_MS * 1000));
  DBG_PRINTF("[DBG] lcd_lvgl_Init: tick timer started\r\n");

  lvgl_mux = xSemaphoreCreateMutex(); //mutex semaphores
  assert(lvgl_mux);
  encoder_init();
  xTaskCreate(example_lvgl_port_task, "LVGL", EXAMPLE_LVGL_TASK_STACK_SIZE, NULL, EXAMPLE_LVGL_TASK_PRIORITY, NULL);
  DBG_PRINTF("[DBG] lcd_lvgl_Init: lvgl task created\r\n");
  if (example_lvgl_lock(-1)) 
  {   
#if LCD_START_LV_DEMO_WIDGETS
    DBG_PRINTF("[DBG] lcd_lvgl_Init: starting lv_demo_widgets\r\n");
    lv_demo_widgets();      /* A widgets example */
    DBG_PRINTF("[DBG] lcd_lvgl_Init: lv_demo_widgets started\r\n");
#else
    if (ui_init) {
      DBG_PRINTF("[DBG] lcd_lvgl_Init: starting ui_init\r\n");
      ui_init();
      DBG_PRINTF("[DBG] lcd_lvgl_Init: ui_init done\r\n");
    } else {
      DBG_PRINTF("[DBG] lcd_lvgl_Init: ui_init missing, fallback UI\r\n");
      create_fallback_ui();
    }
#endif
    //lv_demo_music();        /* A modern, smartphone-like music player demo. */
    //lv_demo_stress();       /* A stress test for LVGL. */
    //lv_demo_benchmark();    /* A demo to measure the performance of LVGL or to compare different settings. */

    // Release the mutex
    example_lvgl_unlock();
  }
  DBG_PRINTF("[DBG] lcd_lvgl_Init: exit\r\n");
}

static bool example_lvgl_lock(int timeout_ms)
{
  assert(lvgl_mux && "bsp_display_start must be called first");

  const TickType_t timeout_ticks = (timeout_ms == -1) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
  return xSemaphoreTake(lvgl_mux, timeout_ticks) == pdTRUE;
}

static void example_lvgl_unlock(void)
{
  assert(lvgl_mux && "bsp_display_start must be called first");
  xSemaphoreGive(lvgl_mux);
}
static void example_lvgl_port_task(void *arg)
{
  uint32_t task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
  const uint32_t encoder_poll_interval_ms = (LCD_ENCODER_POLL_INTERVAL_MS > 0) ? LCD_ENCODER_POLL_INTERVAL_MS : 1;
  for(;;)
  {
    if (example_lvgl_lock(-1))
    {
      const uint32_t now_ms = (uint32_t)(xTaskGetTickCount() * portTICK_PERIOD_MS);
      if ((now_ms - s_encoder_last_poll_ms) >= encoder_poll_interval_ms) {
        s_encoder_last_poll_ms = now_ms;
        encoder_poll_update_ui();
      }
      task_delay_ms = lv_timer_handler();
      
      example_lvgl_unlock();
    }
    if (task_delay_ms > EXAMPLE_LVGL_TASK_MAX_DELAY_MS)
    {
      task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
    }
    else if (task_delay_ms < EXAMPLE_LVGL_TASK_MIN_DELAY_MS)
    {
      task_delay_ms = EXAMPLE_LVGL_TASK_MIN_DELAY_MS;
    }
#if LCD_USE_ROTARY_ENCODER
    if (task_delay_ms > encoder_poll_interval_ms) {
      task_delay_ms = encoder_poll_interval_ms;
    }
#endif
    vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
  }
}
static void example_increase_lvgl_tick(void *arg)
{
  lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
}
static bool example_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
  (void)panel_io;
  (void)edata;
#if LCD_LVGL_ASYNC_FLUSH
  if (!s_lvgl_flush_ready_enabled || user_ctx == NULL) {
    return false;
  }
  lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
  if (disp_driver->draw_buf == NULL) {
    return false;
  }
  lv_disp_flush_ready(disp_driver);
#else
  (void)user_ctx;
#endif
  return false;
}
static void example_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
  esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t) drv->user_data;
  const int offsetx1 = area->x1;
  const int offsetx2 = area->x2;
  const int offsety1 = area->y1;
  const int offsety2 = area->y2;

  esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
#if !LCD_LVGL_ASYNC_FLUSH
  lv_disp_flush_ready(drv);
#else
  (void)drv;
#endif
}
void example_lvgl_rounder_cb(struct _lv_disp_drv_t *disp_drv, lv_area_t *area)
{
  uint16_t x1 = area->x1;
  uint16_t x2 = area->x2;

  uint16_t y1 = area->y1;
  uint16_t y2 = area->y2;

  // round the start of coordinate down to the nearest 2M number
  area->x1 = (x1 >> 1) << 1;
  area->y1 = (y1 >> 1) << 1;
  // round the end of coordinate up to the nearest 2N+1 number
  area->x2 = ((x2 >> 1) << 1) + 1;
  area->y2 = ((y2 >> 1) << 1) + 1;
}
static void example_lvgl_touch_cb(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
  uint16_t tp_x,tp_y;
  uint8_t win = getTouch(&tp_x,&tp_y);
  if (win)
  {
    #ifdef EXAMPLE_Rotate_90
      data->point.x = tp_y;
      data->point.y = (EXAMPLE_LCD_V_RES - tp_x);
    #else
      data->point.x = tp_x;
      data->point.y = tp_y;
    #endif
    if(data->point.x > EXAMPLE_LCD_H_RES)
    data->point.x = EXAMPLE_LCD_H_RES;
    if(data->point.y > EXAMPLE_LCD_V_RES)
    data->point.y = EXAMPLE_LCD_V_RES;
    data->state = LV_INDEV_STATE_PRESSED;
    //ESP_LOGE("TP","(%d,%d)",data->point.x,data->point.y);
  }
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}
