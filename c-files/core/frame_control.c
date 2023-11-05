//-------
// Frame Control Functions
//-------

// SwapScreenBuffer
mrb_value mrb_swap_screen_buffer(mrb_state *mrb, mrb_value self)
{
    SwapScreenBuffer();
    return mrb_nil_value();
}

// PollInputEvents
mrb_value mrb_poll_input_events(mrb_state *mrb, mrb_value self)
{
    PollInputEvents();
    return mrb_nil_value();
}

// WaitTime
mrb_value mrb_wait_time(mrb_state *mrb, mrb_value self)
{
    mrb_float seconds;
    mrb_get_args(mrb, "f", &seconds);
    WaitTime(seconds);
    return mrb_nil_value();
}

void mrb_raylib_setup_frame_control(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "swap_screen_buffer", mrb_swap_screen_buffer, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "poll_input_events", mrb_poll_input_events, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "wait_time", mrb_wait_time, MRB_ARGS_REQ(1));
}