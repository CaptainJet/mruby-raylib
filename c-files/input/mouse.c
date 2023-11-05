//-------
// Mouse Functions
//-------

// IsMouseButtonPressed
mrb_value mrb_is_mouse_button_pressed(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonPressed(button));
}

// IsMouseButtonDown
mrb_value mrb_is_mouse_button_down(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonDown(button));
}

// IsMouseButtonReleased
mrb_value mrb_is_mouse_button_released(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonReleased(button));
}

// IsMouseButtonUp
mrb_value mrb_is_mouse_button_up(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonUp(button));
}

// GetMouseX
mrb_value mrb_get_mouse_x(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetMouseX());
}

// GetMouseY
mrb_value mrb_get_mouse_y(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetMouseY());
}

// GetMousePosition
mrb_value mrb_get_mouse_position(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMousePosition();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetMouseDelta
mrb_value mrb_get_mouse_delta(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMouseDelta();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// SetMousePosition
mrb_value mrb_set_mouse_position(mrb_state *mrb, mrb_value self)
{
    mrb_int x;
    mrb_int y;
    mrb_get_args(mrb, "ii", &x, &y);
    SetMousePosition(x, y);
    return mrb_nil_value();
}

// SetMouseOffset
mrb_value mrb_set_mouse_offset(mrb_state *mrb, mrb_value self)
{
    mrb_int offsetx;
    mrb_int offsety;
    mrb_get_args(mrb, "ii", &offsetx, &offsety);
    SetMouseOffset(offsetx, offsety);
    return mrb_nil_value();
}

// SetMouseScale
mrb_value mrb_set_mouse_scale(mrb_state *mrb, mrb_value self)
{
    mrb_float scalex;
    mrb_float scaley;
    mrb_get_args(mrb, "ii", &scalex, &scaley);
    SetMouseScale(scalex, scaley);
    return mrb_nil_value();
}

// GetMouseWheelMove
mrb_value mrb_get_mouse_wheel_move(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetMouseWheelMove());
}

// GetMouseWheelMove
mrb_value mrb_get_mouse_wheel_move_v(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMouseWheelMoveV();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// SetMouseCursor
mrb_value mrb_set_mouse_cursor(mrb_state *mrb, mrb_value self)
{
    mrb_int cursor;
    mrb_get_args(mrb, "i", &cursor);
    SetMouseCursor(cursor);
    return mrb_nil_value();
}

void mrb_raylib_setup_mouse(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_pressed?", mrb_is_mouse_button_pressed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_down?", mrb_is_mouse_button_down, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_released?", mrb_is_mouse_button_released, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_up?", mrb_is_mouse_button_up, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_mouse_x", mrb_get_mouse_x, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_y", mrb_get_mouse_y, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_position", mrb_get_mouse_position, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_delta", mrb_get_mouse_delta, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_mouse_position", mrb_set_mouse_position, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_mouse_offset", mrb_set_mouse_offset, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_mouse_scale", mrb_set_mouse_scale, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_mouse_wheel_move", mrb_get_mouse_wheel_move, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_wheel_move_v", mrb_get_mouse_wheel_move_v, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_mouse_cursor", mrb_set_mouse_cursor, MRB_ARGS_REQ(1));
}