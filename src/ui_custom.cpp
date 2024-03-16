#include "ui_custom.h"
#include "http_client.h"

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
    lv_obj_t * target = lv_event_get_target(e);
    uint32_t id = lv_btnmatrix_get_selected_btn(target);
    auto txt = std::string(lv_btnmatrix_get_btn_text(target, id));
    ui_writeLog("clicked button "+txt);
    http_req_relais_toggle(id);
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

    // button matrix
    lv_obj_t * matrix = lv_btnmatrix_create(wholeScreen);
    lv_obj_set_grid_cell(matrix, LV_GRID_ALIGN_STRETCH, 0, 1,
                                 LV_GRID_ALIGN_STRETCH, 1, 1);
    //lv_obj_clear_flag(matrix, LV_OBJ_FLAG_SCROLLABLE);
    static const char * btnm_map[] = {
        "3D Printer", "AmbiL Decke", "\n",
        "AmbiL TV",   "Drucker",     "\n", 
        "TV",         "AMP",         ""
    };
    lv_btnmatrix_set_map(matrix, btnm_map);
    lv_obj_add_event_cb(matrix, ui_event_Button, LV_EVENT_CLICKED, NULL);

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