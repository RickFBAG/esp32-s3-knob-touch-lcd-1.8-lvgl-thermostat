#include "../ui.h"

#define UI_TEMP_MIN_C 10
#define UI_TEMP_MAX_C 30
#define UI_TEMP_DEFAULT_C 20

#define UI_SCREEN_SIZE 360
#define UI_ARC_SIZE 360
#define UI_ARC_BG_WIDTH 56
#define UI_ARC_MAIN_WIDTH 23
#define UI_ARC_OFFSET 5

#define UI_DOT_NORMAL_SIZE 8
#define UI_DOT_SELECTED_SIZE 15
#define UI_DOT_EXTREME_SIZE 22
#define UI_KNOB_PAD 16

#define UI_ICON_ROW_Y_OFFSET -52
#define UI_ICON_GAP 18
#define UI_ICON_ZOOM 224

#define UI_VALUE_LABEL_X_OFFSET 4
#define UI_VALUE_LABEL_Y_OFFSET -15

#define UI_ARC_RANGE ((UI_TEMP_MAX_C - UI_TEMP_MIN_C) + 1)

typedef struct {
    lv_obj_t * dot;
    int32_t value;
} arc_dot_t;

static arc_dot_t s_arc_dots[UI_ARC_RANGE];
static int s_arc_dot_count = 0;
static lv_obj_t * s_last_selected_dot = NULL;

lv_obj_t * uic_Arc1 = NULL;
lv_obj_t * ui_Screen1 = NULL;
lv_obj_t * ui_ArcDoel = NULL;
lv_obj_t * ui_ArcHuidig = NULL;
lv_obj_t * ui_Temp = NULL;
lv_obj_t * ui_TempIndicatorC = NULL;
lv_obj_t * ui_Temperature = NULL;
lv_obj_t * ui_Temperature1 = NULL;
lv_obj_t * ui_Temperature2 = NULL;

static int clamp_temp_c(int temp_c)
{
    if(temp_c < UI_TEMP_MIN_C) return UI_TEMP_MIN_C;
    if(temp_c > UI_TEMP_MAX_C) return UI_TEMP_MAX_C;
    return temp_c;
}

static void set_temp_labels(int temp_c)
{
    if(ui_Temp && lv_obj_is_valid(ui_Temp)) {
        lv_label_set_text_fmt(ui_Temp, "%d", temp_c);
    }

    if(ui_Temperature1 && ui_Temperature1 != ui_Temp && lv_obj_is_valid(ui_Temperature1)) {
        lv_label_set_text_fmt(ui_Temperature1, "%d", temp_c);
    }
}

static void dot_set_size_centered(lv_obj_t * dot, lv_coord_t size)
{
    lv_coord_t cx = lv_obj_get_x(dot) + (lv_obj_get_width(dot) / 2);
    lv_coord_t cy = lv_obj_get_y(dot) + (lv_obj_get_height(dot) / 2);

    lv_obj_set_size(dot, size, size);
    lv_obj_set_pos(dot, cx - (size / 2), cy - (size / 2));
}

static int32_t find_dot_value(const lv_obj_t * dot)
{
    int i;
    for(i = 0; i < s_arc_dot_count; i++) {
        if(s_arc_dots[i].dot == dot) return s_arc_dots[i].value;
    }
    return -1;
}

static void restore_dot_style(lv_obj_t * dot, int32_t value)
{
    if(value == UI_TEMP_MIN_C || value == UI_TEMP_MAX_C) {
        dot_set_size_centered(dot, UI_DOT_EXTREME_SIZE);
        lv_obj_set_style_bg_color(dot, lv_color_hex(0xAFBDF5), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else {
        dot_set_size_centered(dot, UI_DOT_NORMAL_SIZE);
        lv_obj_set_style_bg_color(dot, lv_color_hex(0x5F75B5), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

static void update_dot_selection(int32_t current_value)
{
    int i;
    for(i = 0; i < s_arc_dot_count; i++) {
        if(s_arc_dots[i].value != current_value) continue;

        if(s_arc_dots[i].dot != s_last_selected_dot) {
            if(s_last_selected_dot && lv_obj_is_valid(s_last_selected_dot)) {
                int32_t last_value = find_dot_value(s_last_selected_dot);
                if(last_value >= UI_TEMP_MIN_C) {
                    restore_dot_style(s_last_selected_dot, last_value);
                }
            }

            lv_obj_set_style_bg_color(s_arc_dots[i].dot, lv_color_hex(0xFDFEFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            if(current_value != UI_TEMP_MIN_C && current_value != UI_TEMP_MAX_C) {
                dot_set_size_centered(s_arc_dots[i].dot, UI_DOT_SELECTED_SIZE);
            }

            s_last_selected_dot = s_arc_dots[i].dot;
        }

        break;
    }
}

static void arc_value_changed_cb(lv_event_t * e)
{
    if(lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED) return;

    lv_obj_t * arc = lv_event_get_target(e);
    int32_t value = lv_arc_get_value(arc);

    update_dot_selection(value);
    set_temp_labels((int)value);
}

static void add_arc_step_dots(lv_obj_t * arc, lv_obj_t * container)
{
    int32_t original = lv_arc_get_value(arc);
    int32_t min = lv_arc_get_min_value(arc);
    int32_t max = lv_arc_get_max_value(arc);
    int32_t val;

    s_arc_dot_count = 0;
    s_last_selected_dot = NULL;

    for(val = min; val <= max && s_arc_dot_count < UI_ARC_RANGE; val++) {
        lv_obj_t * dot;

        lv_arc_set_value(arc, val);

        dot = lv_obj_create(container);
        s_arc_dots[s_arc_dot_count].dot = dot;
        s_arc_dots[s_arc_dot_count].value = val;
        s_arc_dot_count++;

        lv_obj_clear_flag(dot, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(dot, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_scrollbar_mode(dot, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_radius(dot, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(dot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        if(val == min || val == max) {
            lv_obj_t * dot_label;
            dot_set_size_centered(dot, UI_DOT_EXTREME_SIZE);
            lv_obj_set_style_bg_color(dot, lv_color_hex(0xAFBDF5), LV_PART_MAIN | LV_STATE_DEFAULT);

            dot_label = lv_label_create(dot);
            lv_obj_set_style_text_color(dot_label, lv_color_hex(0x2C4587), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(dot_label, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(dot_label, (val == min) ? "L" : "H");
            lv_obj_center(dot_label);
        }
        else {
            dot_set_size_centered(dot, UI_DOT_NORMAL_SIZE);
            lv_obj_set_style_bg_color(dot, lv_color_hex(0x5F75B5), LV_PART_MAIN | LV_STATE_DEFAULT);
        }

        lv_arc_align_obj_to_angle(arc, dot, 0);
    }

    lv_arc_set_value(arc, original);
}

static lv_obj_t * create_bottom_icon_item(lv_obj_t * parent, const char * symbol, const char * text)
{
    lv_obj_t * item = lv_obj_create(parent);
    lv_obj_t * icon_bg = lv_obj_create(item);
    lv_obj_t * icon = lv_label_create(icon_bg);
    lv_obj_t * label = lv_label_create(item);

    lv_obj_set_size(item, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(item, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(item, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_all(item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_gap(item, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(item, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_size(icon_bg, 36, 36);
    lv_obj_set_style_radius(icon_bg, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(icon_bg, lv_color_hex(0x1E5FB7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(icon_bg, LV_OPA_70, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(icon_bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(icon_bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(icon_bg, LV_OBJ_FLAG_SCROLLABLE);

    lv_label_set_text(icon, symbol);
    lv_obj_set_style_text_font(icon, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(icon, lv_color_hex(0xE8F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_center(icon);

    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label, lv_color_hex(0xE8F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label, LV_OPA_80, LV_PART_MAIN | LV_STATE_DEFAULT);

    return item;
}

void ui_Screen1_screen_init(void)
{
    lv_coord_t arc_main_size = UI_ARC_SIZE - ((UI_ARC_BG_WIDTH / 2) + (UI_ARC_MAIN_WIDTH / 2)) + UI_ARC_OFFSET;
    lv_obj_t * icon_row;
    lv_obj_t * list_item;
    lv_obj_t * fan_item;

    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_set_size(ui_Screen1, UI_SCREEN_SIZE, UI_SCREEN_SIZE);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x01174A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Screen1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcHuidig = lv_arc_create(ui_Screen1);
    lv_obj_set_size(ui_ArcHuidig, UI_ARC_SIZE, UI_ARC_SIZE);
    lv_obj_center(ui_ArcHuidig);
    lv_obj_clear_flag(ui_ArcHuidig, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_style(ui_ArcHuidig, NULL, LV_PART_KNOB);
    lv_obj_set_style_arc_width(ui_ArcHuidig, UI_ARC_BG_WIDTH, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcHuidig, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_ArcHuidig, lv_color_hex(0x2C4587), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcDoel = lv_arc_create(ui_Screen1);
    lv_obj_set_size(ui_ArcDoel, arc_main_size, arc_main_size);
    lv_obj_center(ui_ArcDoel);
    lv_arc_set_range(ui_ArcDoel, UI_TEMP_MIN_C, UI_TEMP_MAX_C);
    lv_arc_set_value(ui_ArcDoel, UI_TEMP_DEFAULT_C);

    lv_obj_set_style_arc_width(ui_ArcDoel, UI_ARC_MAIN_WIDTH, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcDoel, UI_ARC_MAIN_WIDTH, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_ArcDoel, lv_color_hex(0x20345F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_ArcDoel, lv_color_hex(0x0854FE), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ArcDoel, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ArcDoel, lv_color_hex(0xFDFEFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ArcDoel, UI_KNOB_PAD, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ArcDoel, lv_color_hex(0x0854FE), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_ArcDoel, arc_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);

    add_arc_step_dots(ui_ArcDoel, ui_Screen1);

    ui_Temp = lv_label_create(ui_Screen1);
    lv_obj_set_style_text_font(ui_Temp, &lv_font_roboto_extralight_150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Temp, lv_color_hex(0xFBFCFE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Temp, LV_ALIGN_CENTER, UI_VALUE_LABEL_X_OFFSET, UI_VALUE_LABEL_Y_OFFSET);

    /* Keep compatibility with existing encoder update code expectations */
    ui_Temperature1 = ui_Temp;
    ui_TempIndicatorC = NULL;
    ui_Temperature = NULL;
    ui_Temperature2 = NULL;
    uic_Arc1 = ui_ArcDoel;

    icon_row = lv_obj_create(ui_Screen1);
    lv_obj_set_size(icon_row, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(icon_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_gap(icon_row, UI_ICON_GAP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(icon_row, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(icon_row, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(icon_row, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(icon_row, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_align(icon_row, LV_ALIGN_BOTTOM_MID, 0, UI_ICON_ROW_Y_OFFSET);

    list_item = create_bottom_icon_item(icon_row, LV_SYMBOL_LIST, "MENU");
    fan_item = create_bottom_icon_item(icon_row, LV_SYMBOL_REFRESH, "FAN");

    LV_UNUSED(list_item);
    LV_UNUSED(fan_item);

    ui_Screen1_set_temperature(UI_TEMP_DEFAULT_C);
}

void ui_Screen1_set_temperature(int temp_c)
{
    int clamped = clamp_temp_c(temp_c);

    if(ui_ArcDoel == NULL || !lv_obj_is_valid(ui_ArcDoel)) {
        return;
    }

    lv_arc_set_value(ui_ArcDoel, clamped);
    update_dot_selection(clamped);
    set_temp_labels(clamped);
}

void ui_Screen1_screen_destroy(void)
{
    int i;

    if(ui_Screen1 && lv_obj_is_valid(ui_Screen1)) {
        lv_obj_del(ui_Screen1);
    }

    ui_Screen1 = NULL;
    uic_Arc1 = NULL;
    ui_ArcDoel = NULL;
    ui_ArcHuidig = NULL;
    ui_Temp = NULL;
    ui_TempIndicatorC = NULL;
    ui_Temperature = NULL;
    ui_Temperature1 = NULL;
    ui_Temperature2 = NULL;

    s_last_selected_dot = NULL;
    s_arc_dot_count = 0;
    for(i = 0; i < UI_ARC_RANGE; i++) {
        s_arc_dots[i].dot = NULL;
        s_arc_dots[i].value = 0;
    }
}
