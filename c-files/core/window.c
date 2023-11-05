//-------
// Window Functions
//-------

// InitWindow
mrb_value mrb_init_window(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    char *title;
    mrb_get_args(mrb, "iiz", &width, &height, &title);
    InitWindow(width, height, title);
    return mrb_nil_value();
}

// WindowShouldClose
mrb_value mrb_window_should_close(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(WindowShouldClose());
}

// CloseWindow
mrb_value mrb_close_window(mrb_state *mrb, mrb_value self)
{
    CloseWindow();
    return mrb_nil_value();
}

// IsWindowReady
mrb_value mrb_is_window_ready(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowReady());
}

// IsWindowFullscreen
mrb_value mrb_is_window_fullscreen(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowFullscreen());
}

// IsWindowHidden
mrb_value mrb_is_window_hidden(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowHidden());
}

// IsWindowMinimized
mrb_value mrb_is_window_minimized(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowMinimized());
}

// IsWindowMaximized
mrb_value mrb_is_window_maximized(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowMaximized());
}

// IsWindowFocused
mrb_value mrb_is_window_focused(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowFocused());
}

// IsWindowResized
mrb_value mrb_is_window_resized(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowResized());
}

// IsWindowState
mrb_value mrb_is_window_state(mrb_state *mrb, mrb_value self)
{
    mrb_int state;
    mrb_get_args(mrb, "i", &state);
    return mrb_bool_value(IsWindowState(state));
}

// SetWindowState
mrb_value mrb_set_window_state(mrb_state *mrb, mrb_value self)
{
    mrb_int state;
    mrb_get_args(mrb, "i", &state);
    SetWindowState(state);
    return mrb_nil_value();
}

// ClearWindowState
mrb_value mrb_clear_window_state(mrb_state *mrb, mrb_value self)
{
    mrb_int state;
    mrb_get_args(mrb, "i", &state);
    ClearWindowState(state);
    return mrb_nil_value();
}

// ToggleFullscreen
mrb_value mrb_toggle_fullscreen(mrb_state *mrb, mrb_value self)
{
    ToggleFullscreen();
    return mrb_nil_value();
}

// MaximizeWindow
mrb_value mrb_maximize_window(mrb_state *mrb, mrb_value self)
{
    MaximizeWindow();
    return mrb_nil_value();
}

// MinimizeWindow
mrb_value mrb_minimize_window(mrb_state *mrb, mrb_value self)
{
    MinimizeWindow();
    return mrb_nil_value();
}

// RestoreWindow
mrb_value mrb_restore_window(mrb_state *mrb, mrb_value self)
{
    RestoreWindow();
    return mrb_nil_value();
}

// SetWindowIcon
mrb_value mrb_set_window_icon(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    SetWindowIcon(*image);
    return mrb_nil_value();
}

// SetWindowIcons
mrb_value mrb_set_window_icons(mrb_state *mrb, mrb_value self)
{
    mrb_value icons;
    mrb_int iconcount;
    mrb_get_args(mrb, "Ai", &icons, &iconcount);
    Image image_icons[iconcount];
    for (int i = 0; i < iconcount; ++i)
    {
        image_icons[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(icons, i), &Raylib_Image_type, Image);
    }
    SetWindowIcons(image_icons, iconcount);
    return mrb_nil_value();
}

// SetWindowTitle
mrb_value mrb_set_window_title(mrb_state *mrb, mrb_value self)
{
    char *title;
    mrb_get_args(mrb, "z", &title);
    SetWindowTitle(title);
    return mrb_nil_value();
}

// SetWindowPosition
mrb_value mrb_set_window_position(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y;
    mrb_get_args(mrb, "ii", &x, &y);
    SetWindowPosition(x, y);
    return mrb_nil_value();
}

// SetWindowMonitor
mrb_value mrb_set_window_monitor(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    SetWindowMonitor(monitor);
    return mrb_nil_value();
}

// SetWindowMinSize
mrb_value mrb_set_window_min_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    mrb_get_args(mrb, "ii", &width, &height);
    SetWindowMinSize(width, height);
    return mrb_nil_value();
}

// SetWindowMaxSize
mrb_value mrb_set_window_max_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    mrb_get_args(mrb, "ii", &width, &height);
    SetWindowMaxSize(width, height);
    return mrb_nil_value();
}

// SetWindowSize
mrb_value mrb_set_window_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    mrb_get_args(mrb, "ii", &width, &height);
    SetWindowSize(width, height);
    return mrb_nil_value();
}

// SetWindowOpacity
mrb_value mrb_set_window_opacity(mrb_state *mrb, mrb_value self)
{
    mrb_float opacity;
    mrb_get_args(mrb, "f", &opacity);
    SetWindowOpacity(opacity);
    return mrb_nil_value();
}

// SetWindowFocused
mrb_value mrb_set_window_focused(mrb_state *mrb, mrb_value self)
{
    SetWindowFocused();
    return mrb_nil_value();
}

// GetScreenWidth
mrb_value mrb_get_screen_width(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetScreenWidth());
}

// GetScreenHeight
mrb_value mrb_get_screen_height(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetScreenHeight());
}

// GetRenderWidth
mrb_value mrb_get_render_width(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetRenderWidth());
}

// GetRenderHeight
mrb_value mrb_get_render_height(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetRenderHeight());
}

// GetMonitorCount
mrb_value mrb_get_monitor_count(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetMonitorCount());
}

// GetCurrentMonitor
mrb_value mrb_get_current_monitor(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetCurrentMonitor());
}

// GetMonitorPosition
mrb_value mrb_get_monitor_position(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMonitorPosition(monitor);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetMonitorWidth
mrb_value mrb_get_monitor_width(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorWidth(monitor));
}

// GetMonitorHeight
mrb_value mrb_get_monitor_height(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorHeight(monitor));
}

// GetMonitorPhysicalWidth
mrb_value mrb_get_monitor_physical_width(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorPhysicalWidth(monitor));
}

// GetMonitorPhysicalHeight
mrb_value mrb_get_monitor_physical_height(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorPhysicalHeight(monitor));
}

// GetMonitorRefreshRate
mrb_value mrb_get_monitor_refresh_rate(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorRefreshRate(monitor));
}

// GetWindowPosition
mrb_value mrb_get_window_position(mrb_state *mrb, mrb_value self)
{

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWindowPosition();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetWindowScaleDPI
mrb_value mrb_get_window_scale_dpi(mrb_state *mrb, mrb_value self)
{

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWindowScaleDPI();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetMonitorName
mrb_value mrb_get_monitor_name(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_str_new_cstr(mrb, GetMonitorName(monitor));
}

// SetClipboardText
mrb_value mrb_set_clipboard_text(mrb_state *mrb, mrb_value self)
{
    char *clipboard;
    mrb_get_args(mrb, "z", &clipboard);
    SetClipboardText(clipboard);
    return mrb_nil_value();
}

// GetClipboardText
mrb_value mrb_get_clipboard_text(mrb_state *mrb, mrb_value self)
{
    return mrb_str_new_cstr(mrb, GetClipboardText());
}

// EnableEventWaiting
mrb_value mrb_enable_event_waiting(mrb_state *mrb, mrb_value self)
{
    EnableEventWaiting();
    return mrb_nil_value();
}

// DisableEventWaiting
mrb_value mrb_disable_event_waiting(mrb_state *mrb, mrb_value self)
{
    DisableEventWaiting();
    return mrb_nil_value();
}

void mrb_raylib_setup_window(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "init_window", mrb_init_window, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "window_should_close?", mrb_window_should_close, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "close_window", mrb_close_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_ready?", mrb_is_window_ready, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_fullscreen?", mrb_is_window_fullscreen, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_hidden?", mrb_is_window_hidden, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_minimized?", mrb_is_window_minimized, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_maximized?", mrb_is_window_maximized, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_focused?", mrb_is_window_focused, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_resized?", mrb_is_window_resized, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_state?", mrb_is_window_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_state", mrb_set_window_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "clear_window_state", mrb_clear_window_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "toggle_fullscreen", mrb_toggle_fullscreen, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "maximize_window", mrb_maximize_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "minimize_window", mrb_minimize_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "restore_window", mrb_restore_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_window_icon", mrb_set_window_icon, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_icons", mrb_set_window_icons, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_title", mrb_set_window_title, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_position", mrb_set_window_position, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_monitor", mrb_set_window_monitor, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_min_size", mrb_set_window_min_size, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_max_size", mrb_set_window_max_size, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_size", mrb_set_window_size, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_opacity", mrb_set_window_opacity, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_focused", mrb_set_window_focused, MRB_ARGS_NONE());

    mrb_define_module_function(mrb, raylib_module, "get_screen_width", mrb_get_screen_width, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_screen_height", mrb_get_screen_height, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_render_width", mrb_get_render_width, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_render_height", mrb_get_render_height, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_monitor_count", mrb_get_monitor_count, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_current_monitor", mrb_get_current_monitor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_monitor_position", mrb_get_monitor_position, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_width", mrb_get_monitor_width, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_height", mrb_get_monitor_height, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_physical_width", mrb_get_monitor_physical_width, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_physical_height", mrb_get_monitor_physical_height, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_refresh_rate", mrb_get_monitor_refresh_rate, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_window_position", mrb_get_window_position, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_window_scale_dpi", mrb_get_window_scale_dpi, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_monitor_name", mrb_get_monitor_name, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_clipboard_text", mrb_set_clipboard_text, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_clipboard_text", mrb_get_clipboard_text, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "enable_event_waiting", mrb_enable_event_waiting, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "disable_event_waiting", mrb_disable_event_waiting, MRB_ARGS_NONE());
}