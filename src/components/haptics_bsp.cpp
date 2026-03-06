#include "components/haptics_bsp.h"

#include <Arduino.h>
#include <Wire.h>

#include "SensorDRV2605.hpp"
#include "esp_log.h"
#include "lcd_config.h"

namespace {

constexpr char TAG[] = "haptics_bsp";
constexpr uint32_t kHapticI2cClockHz = 300000U;

SensorDRV2605 s_drv2605;
bool s_haptics_ready = false;

void haptics_bsp_play_effect(uint8_t effect)
{
#if !LCD_HAPTIC_FEEDBACK_ENABLED
  (void)effect;
  return;
#else
  if (!s_haptics_ready || effect == 0) {
    return;
  }

  s_drv2605.stop();
  s_drv2605.setWaveform(0, effect);
  s_drv2605.setWaveform(1, 0);
  s_drv2605.run();
#endif
}

} // namespace

extern "C" bool haptics_bsp_init(void)
{
#if !LCD_HAPTIC_FEEDBACK_ENABLED
  return false;
#else
  if (s_haptics_ready) {
    return true;
  }

  if (!s_drv2605.begin(Wire, EXAMPLE_PIN_NUM_TOUCH_SDA, EXAMPLE_PIN_NUM_TOUCH_SCL)) {
    ESP_LOGW(TAG, "DRV2605 not detected, haptic feedback disabled");
    return false;
  }

  Wire.setClock(kHapticI2cClockHz);
  s_drv2605.selectLibrary(1);
  s_drv2605.setMode(SensorDRV2605::MODE_INTTRIG);
  s_haptics_ready = true;

  ESP_LOGI(TAG, "DRV2605 initialized for encoder haptics");
  return true;
#endif
}

extern "C" void haptics_bsp_play_standard_tick(void)
{
  haptics_bsp_play_effect(LCD_HAPTIC_EFFECT_TICK);
}

extern "C" void haptics_bsp_play_limit_tick(void)
{
  haptics_bsp_play_effect(LCD_HAPTIC_EFFECT_LIMIT);
}
