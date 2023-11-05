//-------
// Text Font Info Functions
//-------

// SetTextLineSpacing
mrb_value mrb_set_text_line_spacing(mrb_state *mrb, mrb_value self)
{
    mrb_int spacing;
    mrb_get_args(mrb, "i", &spacing);
    SetTextLineSpacing(spacing);
    return mrb_nil_value();
}

// MeasureText
mrb_value mrb_measure_text(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_int fontsize;
    mrb_get_args(mrb, "zi", &text, &fontsize);
    return mrb_int_value(mrb, MeasureText(text, fontsize));
}

// MeasureTextEx
mrb_value mrb_measure_text_ex(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *text;
    mrb_float fontsize;
    mrb_float spacing;
    mrb_get_args(mrb, "dzff", &font, &Raylib_Font_type, &text, &fontsize, &spacing);
    Vector2 *out = (Vector2 *)malloc(sizeof(Vector2));
    *out = MeasureTextEx(*font, text, fontsize, spacing);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, out));

    return obj;
}

// GetGlyphIndex
mrb_value mrb_get_glyph_index(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    mrb_get_args(mrb, "di", &font, &Raylib_Font_type, &codepoint);
    return mrb_int_value(mrb, GetGlyphIndex(*font, codepoint));
}

// GetGlyphInfo
mrb_value mrb_get_glyph_info(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    mrb_get_args(mrb, "di", &font, &Raylib_Font_type, &codepoint);
    GlyphInfo *out = (GlyphInfo *)malloc(sizeof(GlyphInfo));
    *out = GetGlyphInfo(*font, codepoint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_GlyphInfo_class, &Raylib_GlyphInfo_type, out));

    return obj;
}

// GetGlyphAtlasRec
mrb_value mrb_get_glyph_atlas_rec(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    mrb_get_args(mrb, "di", &font, &Raylib_Font_type, &codepoint);
    Rectangle *out = (Rectangle *)malloc(sizeof(Rectangle));
    *out = GetGlyphAtlasRec(*font, codepoint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Rectangle_class, &Raylib_Rectangle_type, out));

    return obj;
}

void mrb_raylib_setup_text_font_info(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "set_text_line_spacing", mrb_set_text_line_spacing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "measure_text", mrb_measure_text, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "measure_text_ex", mrb_measure_text_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_glyph_index", mrb_get_glyph_index, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_glyph_info", mrb_get_glyph_info, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_glyph_atlas_rec", mrb_get_glyph_atlas_rec, MRB_ARGS_REQ(2));
}