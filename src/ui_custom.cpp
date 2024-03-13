#include "ui_custom.h"

lv_obj_t * ui_ScreenButtons;
lv_obj_t * ui_TextArea1;

void ui_writeLog(const std::string& message)
{
    auto ended = message;
    ended += "\n";
    lv_textarea_add_text(ui_TextArea1, ended.c_str());
}

void ui_event_Button(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    //const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    ui_writeLog("button clicked");
}

void ui_screen_buttons_init(void)
{
    ui_ScreenButtons = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenButtons, LV_OBJ_FLAG_SCROLLABLE); 

    lv_obj_t * wholeScreen = lv_obj_create(ui_ScreenButtons);
    lv_obj_clear_flag(wholeScreen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(wholeScreen, 320, 480);
    lv_obj_set_layout(wholeScreen, LV_LAYOUT_GRID);
    static lv_coord_t col_dsc_1[] = {290, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc_1[] = {120, 320, LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(wholeScreen, col_dsc_1, row_dsc_1);

    // text field
    ui_TextArea1 = lv_textarea_create(wholeScreen);
    lv_obj_set_grid_cell(ui_TextArea1, LV_GRID_ALIGN_STRETCH, 0, 1,
                                       LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_textarea_set_placeholder_text(ui_TextArea1, "Placeholder...");
    lv_obj_clear_flag(ui_TextArea1, LV_OBJ_FLAG_CLICKABLE);

    // button grid
    lv_obj_t * cont = lv_obj_create(wholeScreen);
    lv_obj_set_grid_cell(cont, LV_GRID_ALIGN_STRETCH, 0, 1,
                               LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_layout(cont, LV_LAYOUT_GRID);

    static lv_coord_t col_dsc[] = {125, 125, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {90, 90, 90, LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(cont, col_dsc, row_dsc);

    lv_obj_t * label;
    lv_obj_t * obj;

    uint32_t i;
    for(i = 0; i < 9; i++) {
        uint8_t col = i % 3;
        uint8_t row = i / 3;

        obj = lv_btn_create(cont);
        lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, 1,
                                  LV_GRID_ALIGN_STRETCH, row, 1);

        label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "c%d, r%d", col, row);
        lv_obj_center(label);
        lv_obj_add_event_cb(obj, ui_event_Button, LV_EVENT_PRESSED, NULL);
    }
}

void ui_init(void) {
    // lv_disp_t * dispp = lv_disp_get_default();
    // lv_theme_t * theme = lv_theme_default_init(
    //     dispp,
    //     lv_palette_main(LV_PALETTE_BLUE),
    //     lv_palette_main(LV_PALETTE_RED),
    //     false,
    //     LV_FONT_DEFAULT);
    // lv_disp_set_theme(dispp, theme);
    ui_screen_buttons_init();
    lv_disp_load_scr(ui_ScreenButtons);
}