//-------
// Cursor Functions
//-------

// ShowCursor
mrb_value mrb_show_cursor(mrb_state *mrb, mrb_value self)
{
    ShowCursor();
    return mrb_nil_value();
}

// HideCursor
mrb_value mrb_hide_cursor(mrb_state *mrb, mrb_value self)
{
    HideCursor();
    return mrb_nil_value();
}

// IsCursorHidden
mrb_value mrb_is_cursor_hidden(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsCursorHidden());
}

// EnableCursor
mrb_value mrb_enable_cursor(mrb_state *mrb, mrb_value self)
{
    EnableCursor();
    return mrb_nil_value();
}

// DisableCursor
mrb_value mrb_disable_cursor(mrb_state *mrb, mrb_value self)
{
    DisableCursor();
    return mrb_nil_value();
}

// IsCursorOnScreen
mrb_value mrb_is_cursor_on_screen(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsCursorOnScreen());
}

void mrb_raylib_setup_cursor(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "show_cursor", mrb_show_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "hide_cursor", mrb_hide_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_cursor_hidden?", mrb_is_cursor_hidden, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "enable_cursor", mrb_enable_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "disable_cursor", mrb_disable_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_cursor_on_screen?", mrb_is_cursor_on_screen, MRB_ARGS_NONE());
}