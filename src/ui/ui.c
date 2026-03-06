#include "ui.h"

lv_obj_t * ui____initial_actions0 = NULL;

lv_anim_t * test_Animation(lv_obj_t * TargetObject, int delay)
{
    LV_UNUSED(TargetObject);
    LV_UNUSED(delay);
    return NULL;
}

void ui_init(void)
{
    ui_Screen1_screen_init();

    if(ui_Screen1 && lv_obj_is_valid(ui_Screen1)) {
        lv_scr_load(ui_Screen1);
    }
}

void ui_destroy(void)
{
    ui_Screen1_screen_destroy();
}

void ui_update_temperature(int new_temp)
{
    ui_Screen1_set_temperature(new_temp);
}
