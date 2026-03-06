#ifndef UI_SCREEN1_H
#define UI_SCREEN1_H

#ifdef __cplusplus
extern "C" {
#endif

extern void ui_Screen1_screen_init(void);
extern void ui_Screen1_screen_destroy(void);
extern void ui_Screen1_set_temperature(int temp_c);

extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_ArcDoel;
extern lv_obj_t * ui_ArcHuidig;
extern lv_obj_t * ui_Temp;
extern lv_obj_t * ui_TempIndicatorC;
extern lv_obj_t * ui_Temperature;
extern lv_obj_t * ui_Temperature1;
extern lv_obj_t * ui_Temperature2;
extern lv_obj_t * uic_Arc1;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
