//-------
// Misc Functions
//-------

// GetRandomValue
mrb_value mrb_get_random_value(mrb_state *mrb, mrb_value self)
{
    mrb_int min, max;
    mrb_get_args(mrb, "ii", &min, &max);
    return mrb_int_value(mrb, GetRandomValue(min, max));
}

// SetRandomSeed
mrb_value mrb_set_random_seed(mrb_state *mrb, mrb_value self)
{
    mrb_int seed;
    mrb_get_args(mrb, "i", &seed);
    SetRandomSeed(seed);
    return mrb_nil_value();
}

// LoadRandomSequence
mrb_value mrb_load_random_sequence(mrb_state *mrb, mrb_value self)
{
    mrb_int count, min, max;
    mrb_get_args(mrb, "iii", &count, &min, &max);
    mrb_value ary = mrb_ary_new(mrb);
    int *sequence = LoadRandomSequence(count, min, max);
    for (int i = 0; i < count; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_int_value(mrb, sequence[i]));
    }
    return ary;
}

// UnloadRandomSequence
mrb_value mrb_unload_random_sequence(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

// TakeScreenshot
mrb_value mrb_take_screenshot(mrb_state *mrb, mrb_value self)
{
    char *filename;
    mrb_get_args(mrb, "z", &filename);
    TakeScreenshot(filename);
    return mrb_nil_value();
}

// SetConfigFlags
mrb_value mrb_set_config_flags(mrb_state *mrb, mrb_value self)
{
    mrb_int flags;
    mrb_get_args(mrb, "i", &flags);
    SetConfigFlags(flags);
    return mrb_nil_value();
}

// SetTraceLogLevel
mrb_value mrb_set_trace_log_level(mrb_state *mrb, mrb_value self)
{
    mrb_int log_level;
    mrb_get_args(mrb, "i", &log_level);
    SetTraceLogLevel(log_level);
    return mrb_nil_value();
}

// OpenURL
mrb_value mrb_open_url(mrb_state *mrb, mrb_value self)
{
    char *url;
    mrb_get_args(mrb, "z", &url);
    OpenURL(url);
    return mrb_nil_value();
}

void mrb_raylib_setup_misc(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "get_random_value", mrb_get_random_value, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_random_seed", mrb_set_random_seed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_random_sequence", mrb_load_random_sequence, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "unload_random_sequence", mrb_unload_random_sequence, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "take_screenshot", mrb_take_screenshot, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_config_flags", mrb_set_config_flags, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_trace_log_level", mrb_set_trace_log_level, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "open_url", mrb_open_url, MRB_ARGS_REQ(1));
}