//-------
// Keyboard Functions
//-------

// IsKeyPressed
mrb_value mrb_is_key_pressed(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyPressed(key));
}

// IsKeyPressedRepeat
mrb_value mrb_is_key_pressed_repeat(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyPressed(key));
}

// IsKeyDown
mrb_value mrb_is_key_down(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyDown(key));
}

// IsKeyReleased
mrb_value mrb_is_key_released(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyReleased(key));
}

// IsKeyUp
mrb_value mrb_is_key_up(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyUp(key));
}

// SetExitKey
mrb_value mrb_set_exit_key(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    SetExitKey(key);
    return mrb_nil_value();
}

// GetKeyPressed
mrb_value mrb_get_key_pressed(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetKeyPressed());
}

// GetCharPressed
mrb_value mrb_get_char_pressed(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetCharPressed());
}

// GetKeyName
mrb_value mrb_get_key_name(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_str_new_cstr(mrb, GetKeyName(key));
}

void mrb_raylib_setup_keyboard(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "is_key_pressed?", mrb_is_key_pressed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_pressed_repeat?", mrb_is_key_pressed_repeat, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_down?", mrb_is_key_down, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_released?", mrb_is_key_released, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_up?", mrb_is_key_up, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_exit_key", mrb_set_exit_key, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_key_pressed", mrb_get_key_pressed, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_char_pressed", mrb_get_char_pressed, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_key_name", mrb_get_char_pressed, MRB_ARGS_REQ(1));
}