//-------
// Timing Functions
//-------

// SetTargetFPS
mrb_value mrb_set_target_fps(mrb_state *mrb, mrb_value self)
{
    mrb_int fps;
    mrb_get_args(mrb, "i", &fps);
    SetTargetFPS(fps);
    return mrb_nil_value();
}

// GetFPS
mrb_value mrb_get_fps(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetFPS());
}

// GetFrameTime
mrb_value mrb_get_frame_time(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetFrameTime());
}

// GetTime
mrb_value mrb_get_time(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetTime());
}

void mrb_raylib_setup_timing(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "set_target_fps", mrb_set_target_fps, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_fps", mrb_get_fps, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_frame_time", mrb_get_frame_time, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_time", mrb_get_time, MRB_ARGS_NONE());
}