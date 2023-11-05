//-------
// Text Drawing Functions
//-------

// DrawFPS
mrb_value mrb_draw_fps(mrb_state *mrb, mrb_value self)
{
    mrb_int posx;
    mrb_int posy;
    mrb_get_args(mrb, "ii", &posx, &posy);
    DrawFPS(posx, posy);
    return mrb_nil_value();
}

// DrawText
mrb_value mrb_draw_text(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_int posx;
    mrb_int posy;
    mrb_int fontsize;
    Color *color;
    mrb_get_args(mrb, "ziiid", &text, &posx, &posy, &fontsize, &color, &Raylib_Color_type);
    DrawText(text, posx, posy, fontsize, *color);
    return mrb_nil_value();
}

// DrawTextEx
mrb_value mrb_draw_text_ex(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *text;
    Vector2 *position;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "dzdffd", &font, &Raylib_Font_type, &text, &position, &Raylib_Vector2_type, &fontsize, &spacing, &tint, &Raylib_Color_type);
    DrawTextEx(*font, text, *position, fontsize, spacing, *tint);
    return mrb_nil_value();
}

// DrawTextPro
mrb_value mrb_draw_text_pro(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *text;
    Vector2 *position;
    Vector2 *origin;
    mrb_float rotation;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "dzddfffd", &font, &Raylib_Font_type, &text, &position, &Raylib_Vector2_type, &origin, &Raylib_Vector2_type, &rotation,
                 &fontsize, &spacing, &tint, &Raylib_Color_type);
    DrawTextPro(*font, text, *position, *origin, rotation, fontsize, spacing, *tint);
    return mrb_nil_value();
}

// DrawTextCodepoint
mrb_value mrb_draw_text_codepoint(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    Vector2 *position;
    mrb_float fontsize;
    Color *tint;
    mrb_get_args(mrb, "didfd", &font, &Raylib_Font_type, &codepoint, &position, &Raylib_Vector2_type, &fontsize, &tint, &Raylib_Color_type);
    DrawTextCodepoint(*font, codepoint, *position, fontsize, *tint);
    return mrb_nil_value();
}

// DrawTextCodepoints
mrb_value mrb_draw_text_codepoints(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_value codepoints;
    mrb_int count;
    Vector2 *position;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "dAidffd", &font, &Raylib_Font_type, &codepoints, &count, &position, &Raylib_Vector2_type, &fontsize, &spacing, &tint, &Raylib_Color_type);
    int codepoints_values[count];
    for (int i = 0; i < count; ++i)
    {
        codepoints_values[i] = mrb_int(mrb, mrb_ary_entry(codepoints, i));
    }
    DrawTextCodepoints(*font, codepoints_values, count, *position, fontsize, spacing, *tint);
    return mrb_nil_value();
}

void mrb_raylib_setup_text_drawing(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "draw_fps", mrb_draw_fps, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_text", mrb_draw_text, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_text_ex", mrb_draw_text_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_text_pro", mrb_draw_text_pro, MRB_ARGS_REQ(8));
    mrb_define_module_function(mrb, raylib_module, "draw_text_codepoint", mrb_draw_text_codepoint, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_text_codepoints", mrb_draw_text_codepoints, MRB_ARGS_REQ(7));
}