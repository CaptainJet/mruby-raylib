//-------
// Gamepad Functions
//-------

// IsGamepadAvailable
mrb_value mrb_is_gamepad_available(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_get_args(mrb, "i", &gamepad);
    return mrb_bool_value(IsGamepadAvailable(gamepad));
}

// GetGamepadName
mrb_value mrb_get_gamepad_name(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_get_args(mrb, "i", &gamepad);
    return mrb_str_new_cstr(mrb, GetGamepadName(gamepad));
}

// IsGamepadButtonPressed
mrb_value mrb_is_gamepad_button_pressed(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonPressed(gamepad, button));
}

// IsGamepadButtonDown
mrb_value mrb_is_gamepad_button_down(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonDown(gamepad, button));
}

// IsGamepadButtonReleased
mrb_value mrb_is_gamepad_button_released(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonReleased(gamepad, button));
}

// IsGamepadButtonUp
mrb_value mrb_is_gamepad_button_up(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonUp(gamepad, button));
}

// GetGamepadButtonPressed
mrb_value mrb_get_gamepad_button_pressed(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetGamepadButtonPressed());
}

// GetGamepadAxisCount
mrb_value mrb_get_gamepad_axis_count(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_get_args(mrb, "i", &gamepad);
    return mrb_int_value(mrb, GetGamepadAxisCount(gamepad));
}

// GetGamepadAxisMovement
mrb_value mrb_get_gamepad_axis_movement(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int axis;
    mrb_get_args(mrb, "ii", &gamepad, &axis);
    return mrb_float_value(mrb, GetGamepadAxisMovement(gamepad, axis));
}

// SetGamepadMappings
mrb_value mrb_set_gamepad_mappings(mrb_state *mrb, mrb_value self)
{
    const char *mappings;
    mrb_get_args(mrb, "z", &mappings);
    return mrb_int_value(mrb, SetGamepadMappings(mappings));
}

void mrb_raylib_setup_gamepad(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_available?", mrb_is_gamepad_available, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_name", mrb_get_gamepad_name, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_pressed?", mrb_is_gamepad_button_pressed, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_down?", mrb_is_gamepad_button_down, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_released?", mrb_is_gamepad_button_released, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_up?", mrb_is_gamepad_button_up, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_button_pressed", mrb_get_gamepad_button_pressed, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_axis_count", mrb_get_gamepad_axis_count, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_axis_movement", mrb_get_gamepad_axis_movement, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_gamepad_mappings", mrb_set_gamepad_mappings, MRB_ARGS_REQ(1));
}