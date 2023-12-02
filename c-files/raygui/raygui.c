//-------
// RayGUI Functions
//-------

// GuiEnable
mrb_value mrb_gui_enable(mrb_state *mrb, mrb_value self)
{
    GuiEnable();
    return mrb_nil_value();
}

// GuiDisable
mrb_value mrb_gui_disable(mrb_state *mrb, mrb_value self)
{
    GuiDisable();
    return mrb_nil_value();
}

// GuiLock
mrb_value mrb_gui_lock(mrb_state *mrb, mrb_value self)
{
    GuiLock();
    return mrb_nil_value();
}

// GuiUnlock
mrb_value mrb_gui_unlock(mrb_state *mrb, mrb_value self)
{
    GuiUnlock();
    return mrb_nil_value();
}

// GuiIsLocked
mrb_value mrb_gui_is_locked(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(GuiIsLocked());
}

// GuiSetAlpha
mrb_value mrb_gui_set_alpha(mrb_state *mrb, mrb_value self)
{
    mrb_float alpha;
    mrb_get_args(mrb, "f", &alpha);
    GuiSetAlpha(alpha);
    return mrb_nil_value();
}

// GuiSetState
mrb_value mrb_gui_set_state(mrb_state *mrb, mrb_value self)
{
    mrb_int state;
    mrb_get_args(mrb, "i", &state);
    GuiSetState(state);
    return mrb_nil_value();
}

// GuiGetState
mrb_value mrb_gui_get_state(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GuiGetState());
}

// GuiSetFont
mrb_value mrb_gui_set_font(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_get_args(mrb, "d", &font, &Raylib_Font_type);
    GuiSetFont(*font);
    return mrb_nil_value();
}

// GuiGetFont
mrb_value mrb_gui_get_font(mrb_state *mrb, mrb_value self)
{
    Font *font = (Font *)malloc(sizeof(Font));
    *font = GuiGetFont();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, font));

    return obj;
}

// GuiSetStyle
mrb_value mrb_gui_set_style(mrb_state *mrb, mrb_value self)
{
    mrb_int control;
    mrb_int property;
    mrb_int value;
    mrb_get_args(mrb, "iii", &control, &property, &value);
    GuiSetStyle(control, property, value);
    return mrb_nil_value();
}

// GuiGetStyle
mrb_value mrb_gui_get_style(mrb_state *mrb, mrb_value self)
{
    mrb_int control;
    mrb_int property;
    mrb_get_args(mrb, "ii", &control, &property);
    return mrb_int_value(mrb, GuiGetStyle(control, property));
}

// GuiLoadStyle
mrb_value mrb_gui_load_style(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    GuiLoadStyle(filename);
    return mrb_nil_value();
}

// GuiLoadStyleDefault
mrb_value mrb_gui_load_style_default(mrb_state *mrb, mrb_value self)
{
    GuiLoadStyleDefault();
    return mrb_nil_value();
}

// GuiEnableTooltip
mrb_value mrb_gui_enable_tooltip(mrb_state *mrb, mrb_value self)
{
    GuiEnableTooltip();
    return mrb_nil_value();
}

// GuiDisableTooltip
mrb_value mrb_gui_disable_tooltip(mrb_state *mrb, mrb_value self)
{
    GuiDisableTooltip();
    return mrb_nil_value();
}

// GuiSetTooltip
mrb_value mrb_gui_set_tooltip(mrb_state *mrb, mrb_value self)
{
    const char *tooltip;
    mrb_get_args(mrb, "z", &tooltip);
    GuiSetTooltip(tooltip);
    return mrb_nil_value();
}

// GuiIconText
mrb_value mrb_gui_icon_text(mrb_state *mrb, mrb_value self)
{
    int iconid;
    const char *text;
    mrb_get_args(mrb, "iz", &iconid, &text);
    return mrb_str_new_cstr(mrb, GuiIconText(iconid, text));
}

// GuiSetIconScale
mrb_value mrb_gui_set_icon_scale(mrb_state *mrb, mrb_value self)
{
    int scale;
    mrb_get_args(mrb, "i", &scale);
    GuiSetIconScale(scale);
    return mrb_nil_value();
}

// GuiGetIcons
mrb_value mrb_gui_get_icons(mrb_state *mrb, mrb_value self)
{
    mrb_value ary = mrb_ary_new(mrb);
    unsigned int *icons = GuiGetIcons();
    for (int i = 0; i < RAYGUI_ICON_MAX_ICONS*RAYGUI_ICON_DATA_ELEMENTS; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_int_value(mrb, icons[i]));
    }
    return ary;
}

// GuiLoadIcons
mrb_value mrb_gui_load_icons(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_bool loadiconsname;
    mrb_get_args(mrb, "zb", &filename, &loadiconsname);
    GuiLoadIcons(filename, loadiconsname);
    /*
    char **icons = GuiLoadIcons(filename, loadiconsname);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < RAYGUI_ICON_MAX_ICONS*RAYGUI_ICON_DATA_ELEMENTS; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_str_new_cstr(mrb, icons[i]));
    }
    return ary;
    */
   return mrb_nil_value();
}

// GuiDrawIcon
mrb_value mrb_gui_draw_icon(mrb_state *mrb, mrb_value self)
{
    int iconid;
    int posx;
    int posy;
    int pixelsize;
    Color *color;
    mrb_get_args(mrb, "iiiid", &iconid, &posx, &posy, &pixelsize, &color, &Raylib_Color_type);
    GuiDrawIcon(iconid, posx, posy, pixelsize, *color);
    return mrb_nil_value();
}

// GuiWindowBox
mrb_value mrb_gui_window_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiWindowBox(*bounds, text));
}

// GuiGroupBox
mrb_value mrb_gui_group_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiGroupBox(*bounds, text));
}

// GuiLine
mrb_value mrb_gui_line(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiLine(*bounds, text));
}

// GuiPanel
mrb_value mrb_gui_panel(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiPanel(*bounds, text));
}

// GuiTabBar
mrb_value mrb_gui_tab_bar(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    mrb_value text;
    int count;
    mrb_int active;
    mrb_get_args(mrb, "dAii", &bounds, &Raylib_Rectangle_type, &text, &count, &active);
    const char *text_values[count];
    for (int i = 0; i < count; ++i)
    {
        text_values[i] = mrb_str_to_cstr(mrb, mrb_ary_entry(text, i));
    }
    int value = active;
    int tabbar = GuiTabBar(*bounds, text_values, count, &value);
    
    mrb_value ary = mrb_ary_new(mrb);
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, tabbar));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, value));
    return ary;
}

// GuiScrollPanel
mrb_value mrb_gui_scroll_panel(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    Rectangle *content;
    Vector2 *scroll;
    Rectangle *view;
    mrb_get_args(mrb, "dzddd", &bounds, &Raylib_Rectangle_type, &text, &content, &Raylib_Rectangle_type, &scroll, &Raylib_Vector2_type, &view, &Raylib_Rectangle_type);
    return mrb_int_value(mrb, GuiScrollPanel(*bounds, text, *content, scroll, view));
}

// GuiLabel
mrb_value mrb_gui_label(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiLabel(*bounds, text));
}

// GuiButton
mrb_value mrb_gui_button(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiButton(*bounds, text));
}

// GuiLabelButton
mrb_value mrb_gui_label_button(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiLabelButton(*bounds, text));
}

// GuiToggle
mrb_value mrb_gui_toggle(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_bool active;
    mrb_get_args(mrb, "dzb", &bounds, &Raylib_Rectangle_type, &text, &active);
    GuiToggle(*bounds, text, &active);
    return mrb_bool_value(active);
}

// GuiToggleGroup
mrb_value mrb_gui_toggle_group(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_int active;
    mrb_get_args(mrb, "dzi", &bounds, &Raylib_Rectangle_type, &text, &active);
    int value = active;
    GuiToggleGroup(*bounds, text, &value);
    return mrb_int_value(mrb, value);
}

// GuiToggleSlider
mrb_value mrb_gui_toggle_slider(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_int active;
    mrb_get_args(mrb, "dzi", &bounds, &Raylib_Rectangle_type, &text, &active);
    int value = active;
    GuiToggleSlider(*bounds, text, &value);
    return mrb_int_value(mrb, value);
}

// GuiCheckBox
mrb_value mrb_gui_check_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_bool checked;
    mrb_get_args(mrb, "dzb", &bounds, &Raylib_Rectangle_type, &text, &checked);
    GuiToggle(*bounds, text, &checked);
    return mrb_bool_value(checked);
}

// GuiComboBox
mrb_value mrb_gui_combo_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_int active;
    mrb_get_args(mrb, "dzi", &bounds, &Raylib_Rectangle_type, &text, &active);
    int value = active;
    GuiComboBox(*bounds, text, &value);
    return mrb_int_value(mrb, value);
}

// GuiDropdownBox
mrb_value mrb_gui_dropdown_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_int active;
    mrb_bool editmode;
    mrb_get_args(mrb, "dzib", &bounds, &Raylib_Rectangle_type, &text, &active, &editmode);
    int value = active;
    int out = GuiDropdownBox(*bounds, text, &value, editmode);
    mrb_value ary = mrb_ary_new(mrb);
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, out));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, value));
    return ary;
}

// GuiSpinner
mrb_value mrb_gui_spinner(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_int value;
    int minvalue;
    int maxvalue;
    mrb_bool editmode;
    mrb_get_args(mrb, "dziiib", &bounds, &Raylib_Rectangle_type, &text, &value, &minvalue, &maxvalue, &editmode);
    int index = value;
    int out = GuiSpinner(*bounds, text, &index, minvalue, maxvalue, editmode);
    mrb_value ary = mrb_ary_new(mrb);
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, out));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, index));
    return ary;
}

// GuiValueBox
mrb_value mrb_gui_value_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_int value;
    int minvalue;
    int maxvalue;
    mrb_bool editmode;
    mrb_get_args(mrb, "dziiib", &bounds, &Raylib_Rectangle_type, &text, &value, &minvalue, &maxvalue, &editmode);
    int index = value;
    int out = GuiValueBox(*bounds, text, &index, minvalue, maxvalue, editmode);
    mrb_value ary = mrb_ary_new(mrb);
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, out));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, index));
    return ary;
}

// GuiTextBox
mrb_value mrb_gui_text_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    mrb_value text;
    mrb_int textsize;
    mrb_bool editmode;
    mrb_get_args(mrb, "dSib", &bounds, &Raylib_Rectangle_type, &text, &textsize, &editmode);
    struct RString *s = mrb_str_ptr(text);
    char *p = RSTR_PTR(s);
    int out = GuiTextBox(*bounds, p, textsize, editmode);
    RSTR_SET_LEN(s, strlen(p));
    return mrb_int_value(mrb, out);
}

// GuiSlider
mrb_value mrb_gui_slider(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *left;
    const char *right;
    mrb_float value;
    mrb_float minvalue;
    mrb_float maxvalue;
    mrb_get_args(mrb, "dzzfff", &bounds, &Raylib_Rectangle_type, &left, &right, &value, &minvalue, &maxvalue);
    float index = value;
    GuiSlider(*bounds, left, right, &index, minvalue, maxvalue);
    return mrb_float_value(mrb, index);
}

// GuiSliderBar
mrb_value mrb_gui_slider_bar(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *left;
    const char *right;
    mrb_float value;
    mrb_float minvalue;
    mrb_float maxvalue;
    mrb_get_args(mrb, "dzzfff", &bounds, &Raylib_Rectangle_type, &left, &right, &value, &minvalue, &maxvalue);
    float index = value;
    GuiSliderBar(*bounds, left, right, &index, minvalue, maxvalue);
    return mrb_float_value(mrb, index);
}

// GuiProgressBar
mrb_value mrb_gui_progress_bar(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *left;
    const char *right;
    mrb_float value;
    mrb_float minvalue;
    mrb_float maxvalue;
    mrb_get_args(mrb, "dzzfff", &bounds, &Raylib_Rectangle_type, &left, &right, &value, &minvalue, &maxvalue);
    float index = value;
    GuiProgressBar(*bounds, left, right, &index, minvalue, maxvalue);
    return mrb_float_value(mrb, index);
}

// GuiStatusBar
mrb_value mrb_gui_status_bar(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiStatusBar(*bounds, text));
}

// GuiDummyRec
mrb_value mrb_gui_dummy_rec(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_get_args(mrb, "dz", &bounds, &Raylib_Rectangle_type, &text);
    return mrb_int_value(mrb, GuiDummyRec(*bounds, text));
}

// GuiGrid
mrb_value mrb_gui_grid(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_float spacing;
    mrb_int subdivs;
    Vector2 *mousecell;
    mrb_get_args(mrb, "dzfid", &bounds, &Raylib_Rectangle_type, &text, &spacing, &subdivs, &mousecell, &Raylib_Vector2_type);
    return mrb_int_value(mrb, GuiGrid(*bounds, text, spacing, subdivs, mousecell));
}

// GuiListView
mrb_value mrb_gui_list_view(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    int sindex;
    int active;
    mrb_get_args(mrb, "dzii", &bounds, &Raylib_Rectangle_type, &text, &sindex, &active);
    int r1 = sindex;
    int r2 = active;
    int out = GuiListView(*bounds, text, &r1, &r2);
    mrb_value ary = mrb_ary_new(mrb);
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, out));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, r1));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, r2));
    return ary;
}

// GuiListViewEx
mrb_value mrb_gui_list_view_ex(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    mrb_value text;
    int count;
    int sindex;
    int active;
    int focus;
    mrb_get_args(mrb, "dAiiii", &bounds, &Raylib_Rectangle_type, &text, &count, &sindex, &active, &focus);
    const char *text_values[count];
    for (int i = 0; i < count; ++i)
    {
        text_values[i] = mrb_str_to_cstr(mrb, mrb_ary_entry(text, i));
    }
    int r1 = sindex;
    int r2 = active;
    int r3 = focus;
    int out = GuiListViewEx(*bounds, text_values, count, &r1, &r2, &r3);
    
    mrb_value ary = mrb_ary_new(mrb);
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, out));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, r1));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, r2));
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, r3));
    return ary;
}

// GuiMessageBox
mrb_value mrb_gui_message_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *title;
    const char *message;
    const char *buttons;
    mrb_get_args(mrb, "dzzz", &bounds, &Raylib_Rectangle_type, &title, &message, &buttons);
    return mrb_int_value(mrb, GuiMessageBox(*bounds, title, message, buttons));
}

// GuiTextInputBox
mrb_value mrb_gui_text_input_box(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *title;
    const char *message;
    const char *buttons;
    mrb_value text;
    mrb_int textmax;
    mrb_bool secretactive;
    mrb_get_args(mrb, "dzzzSib", &bounds, &Raylib_Rectangle_type, &title, &message, &buttons, &text, &textmax, &secretactive);
    struct RString *s = mrb_str_ptr(text);
    char *p = RSTR_PTR(s);
    int out = GuiTextInputBox(*bounds, title, message, buttons, p, textmax, &secretactive);
    RSTR_SET_LEN(s, strlen(p));
    mrb_value ary = mrb_ary_new(mrb);
    mrb_ary_push(mrb, ary, mrb_int_value(mrb, out));
    mrb_ary_push(mrb, ary, mrb_bool_value(secretactive));
    return ary;
}

// GuiColorPicker
mrb_value mrb_gui_color_picker(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    Color *color;
    mrb_get_args(mrb, "dzd", &bounds, &Raylib_Rectangle_type, &text, &color, &Raylib_Color_type);
    return mrb_int_value(mrb, GuiColorPicker(*bounds, text, color));
}

// GuiColorPanel
mrb_value mrb_gui_color_panel(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    Color *color;
    mrb_get_args(mrb, "dzd", &bounds, &Raylib_Rectangle_type, &text, &color, &Raylib_Color_type);
    return mrb_int_value(mrb, GuiColorPanel(*bounds, text, color));
}

// GuiColorBarAlpha
mrb_value mrb_gui_color_bar_alpha(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_float alpha;
    mrb_get_args(mrb, "dzf", &bounds, &Raylib_Rectangle_type, &text, &alpha);
    float r1 = alpha;
    GuiColorBarAlpha(*bounds, text, &r1);
    return mrb_float_value(mrb, r1);
}

// GuiColorBarHue
mrb_value mrb_gui_color_bar_hue(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    mrb_float value;
    mrb_get_args(mrb, "dzf", &bounds, &Raylib_Rectangle_type, &text, &value);
    float r1 = value;
    GuiColorBarHue(*bounds, text, &r1);
    return mrb_float_value(mrb, r1);
}

// GuiColorPickerHSV
mrb_value mrb_gui_color_picker_hsv(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    Vector3 *colorhsv;
    mrb_get_args(mrb, "dzd", &bounds, &Raylib_Rectangle_type, &text, &colorhsv, &Raylib_Vector3_type);
    return mrb_int_value(mrb, GuiColorPickerHSV(*bounds, text, colorhsv));
}

// GuiColorPanelHSV
mrb_value mrb_gui_color_panel_hsv(mrb_state *mrb, mrb_value self)
{
    Rectangle *bounds;
    const char *text;
    Vector3 *colorhsv;
    mrb_get_args(mrb, "dzd", &bounds, &Raylib_Rectangle_type, &text, &colorhsv, &Raylib_Vector3_type);
    return mrb_int_value(mrb, GuiColorPanelHSV(*bounds, text, colorhsv));
}

void mrb_raylib_setup_raygui(mrb_state *mrb, struct RClass *raylib_module)
{
    struct RClass *Raylib_Raygui_module;
    Raylib_Raygui_module = mrb_define_module(mrb, "RayGUI");
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_enable", mrb_gui_enable, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_disable", mrb_gui_disable, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_lock", mrb_gui_lock, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_unlock", mrb_gui_unlock, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_is_locked?", mrb_gui_is_locked, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_set_alpha", mrb_gui_set_alpha, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_set_state", mrb_gui_set_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_get_state", mrb_gui_get_state, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_set_font", mrb_gui_set_font, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_get_font", mrb_gui_get_font, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_set_style", mrb_gui_set_style, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_get_style", mrb_gui_get_style, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_load_style", mrb_gui_load_style, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_load_style_default", mrb_gui_load_style_default, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_enable_tooltip", mrb_gui_enable_tooltip, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_disable_tooltip", mrb_gui_disable_tooltip, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_set_tooltip", mrb_gui_set_tooltip, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_icon_text", mrb_gui_icon_text, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_set_icon_scale", mrb_gui_set_icon_scale, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_get_icons", mrb_gui_get_icons, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_load_icons", mrb_gui_load_icons, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_draw_icon", mrb_gui_draw_icon, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_window_box", mrb_gui_window_box, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_group_box", mrb_gui_group_box, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_line", mrb_gui_line, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_panel", mrb_gui_panel, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_tab_bar", mrb_gui_tab_bar, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_scroll_panel", mrb_gui_scroll_panel, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_label", mrb_gui_label, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_button", mrb_gui_button, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_label_button", mrb_gui_label_button, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_toggle", mrb_gui_toggle, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_toggle_group", mrb_gui_toggle_group, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_toggle_slider", mrb_gui_toggle_slider, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_check_box", mrb_gui_check_box, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_combo_box", mrb_gui_combo_box, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_dropdown_box", mrb_gui_dropdown_box, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_spinner", mrb_gui_spinner, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_value_box", mrb_gui_value_box, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_text_box", mrb_gui_text_box, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_slider", mrb_gui_slider, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_slider_bar", mrb_gui_slider_bar, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_progress_bar", mrb_gui_progress_bar, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_status_bar", mrb_gui_status_bar, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_dummy_rec", mrb_gui_dummy_rec, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_grid", mrb_gui_grid, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_list_view", mrb_gui_list_view, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_list_view_ex", mrb_gui_list_view_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_message_box", mrb_gui_message_box, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_text_input_box", mrb_gui_text_input_box, MRB_ARGS_REQ(7));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_text_input_box", mrb_gui_text_input_box, MRB_ARGS_REQ(7));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_color_picker", mrb_gui_color_picker, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_color_panel", mrb_gui_color_panel, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_color_bar_alpha", mrb_gui_color_bar_alpha, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_color_bar_hue", mrb_gui_color_bar_hue, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_color_picker_hsv", mrb_gui_color_picker_hsv, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, Raylib_Raygui_module, "gui_color_panel_hsv", mrb_gui_color_panel_hsv, MRB_ARGS_REQ(3));
}