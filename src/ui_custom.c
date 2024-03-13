#include "ui_custom.h"

lv_obj_t * ui_ScreenButtons;

void ui_screen_buttons_init(void)
{
    ui_ScreenButtons = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenButtons, LV_OBJ_FLAG_SCROLLABLE); 

    lv_obj_t * cont = lv_obj_create(ui_ScreenButtons);
    lv_obj_set_size(cont, 300, 240);
    lv_obj_align(cont, LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_layout(cont, LV_LAYOUT_GRID);

    static lv_coord_t col_dsc[] = {100, 100, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {80, 80, LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(cont, col_dsc, row_dsc);

    lv_obj_t * label;
    lv_obj_t * obj;

    obj = lv_btn_create(cont);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 0, 1,
                              LV_GRID_ALIGN_STRETCH, 0, 1);

    label = lv_label_create(obj);
    lv_label_set_text(label, "1");
    lv_obj_center(label);

    obj = lv_btn_create(cont);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 1, 1,
                              LV_GRID_ALIGN_STRETCH, 0, 1);

    label = lv_label_create(obj);
    lv_label_set_text(label, "2");
    lv_obj_center(label);

    // uint32_t i;
    // for(i = 0; i < 6; i++) {
    //     uint8_t col = i % 3;
    //     uint8_t row = i / 3;

    //     obj = lv_btn_create(cont);
    //     /*Stretch the cell horizontally and vertically too
    //      *Set span to 1 to make the cell 1 column/row sized*/
    //     lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, 1,
    //                               LV_GRID_ALIGN_STRETCH, row, 1);

    //     label = lv_label_create(obj);
    //     lv_label_set_text_fmt(label, "c%d, r%d", col, row);
    //     lv_obj_center(label);
    // }
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