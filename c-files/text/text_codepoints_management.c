//-------
// Text Codepoints Management Functions
//-------

// LoadUTF8
mrb_value mrb_load_utf8(mrb_state *mrb, mrb_value self)
{
    mrb_value codepoints;
    mrb_int length;
    mrb_get_args(mrb, "Ai", &codepoints, &length);
    int out_codepoints[length];
    for (int i = 0; i < length; ++i)
    {
        out_codepoints[i] = mrb_int(mrb, mrb_ary_entry(codepoints, i));
    }
    char *out = LoadUTF8(out_codepoints, length);
    mrb_value return_value = mrb_str_new_cstr(mrb, out);
    UnloadUTF8(out);
    return return_value;
}

// UnloadUTF8
mrb_value mrb_unload_utf8(mrb_state *mrb, mrb_value self)
{
    char *text;
    mrb_get_args(mrb, "z", &text);
    UnloadUTF8(text);
    return mrb_nil_value();
}

// LoadCodepoints
mrb_value mrb_load_codepoints(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_int scount;
    mrb_get_args(mrb, "zi", &text, &scount);
    int count = 0;
    int *codepoints = LoadCodepoints(text, &count);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < count; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_int_value(mrb, codepoints[i]));
    }
    UnloadCodepoints(codepoints);
    return ary;
}

// UnloadCodepoints
mrb_value mrb_unload_codepoints(mrb_state *mrb, mrb_value self)
{
    // mrb_value codepoints;
    // mrb_get_args(mrb, "A", &codepoints);
    // int *out_codepoints;
    // for (int i = 0; i < RARRAY_LEN(codepoints); ++i) {
    //     out_codepoints[i] = (int *)DATA_PTR(mrb_ary_entry(codepoints, i));
    // }
    // UnloadCodepoints(out_codepoints);
    return mrb_nil_value();
}

// GetCodepointCount
mrb_value mrb_get_codepoint_count(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_get_args(mrb, "z", &text);
    return mrb_int_value(mrb, GetCodepointCount(text));
}

// GetCodepoint
mrb_value mrb_get_codepoint(mrb_state *mrb, mrb_value self)
{
    const char *text;
    int bytes_processed;
    mrb_get_args(mrb, "zi", &text, &bytes_processed);
    return mrb_int_value(mrb, GetCodepoint(text, &bytes_processed));
}

// GetCodepointNext
mrb_value mrb_get_codepoint_next(mrb_state *mrb, mrb_value self)
{
    const char *text;
    int bytes_processed;
    mrb_get_args(mrb, "zi", &text, &bytes_processed);
    return mrb_int_value(mrb, GetCodepointNext(text, &bytes_processed));
}

// GetCodepointPrevious
mrb_value mrb_get_codepoint_previous(mrb_state *mrb, mrb_value self)
{
    const char *text;
    int bytes_processed;
    mrb_get_args(mrb, "zi", &text, &bytes_processed);
    return mrb_int_value(mrb, GetCodepointPrevious(text, &bytes_processed));
}

// CodepointToUTF8
mrb_value mrb_codepoint_to_utf8(mrb_state *mrb, mrb_value self)
{
    mrb_int codepoint;
    int bytesize;
    mrb_get_args(mrb, "ii", &codepoint, &bytesize);
    return mrb_str_new_cstr(mrb, CodepointToUTF8(codepoint, &bytesize));
}

void mrb_raylib_setup_text_codepoints_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_utf8", mrb_load_utf8, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_utf8", mrb_unload_utf8, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_codepoints", mrb_load_codepoints, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_codepoints", mrb_unload_codepoints, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint_count", mrb_get_codepoint_count, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint", mrb_get_codepoint, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint_next", mrb_get_codepoint_next, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint_previous", mrb_get_codepoint_previous, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "codepoint_to_utf8", mrb_codepoint_to_utf8, MRB_ARGS_REQ(2));
}