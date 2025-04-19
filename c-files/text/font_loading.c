//-------
// Font Loading Functions
//-------

// GetFontDefault
mrb_value mrb_get_font_default(mrb_state *mrb, mrb_value self)
{
    Font *out = (Font *)malloc(sizeof(Font));
    *out = GetFontDefault();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFont
mrb_value mrb_load_font(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Font *out = (Font *)malloc(sizeof(Font));
    *out = LoadFont(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFontEx
mrb_value mrb_load_font_ex(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int fontsize;
    mrb_value fontchars;
    mrb_int glyphcount;
    mrb_get_args(mrb, "ziA!i", &filename, &fontsize, &fontchars, &glyphcount);
    Font *out = (Font *)malloc(sizeof(Font));
    if (!mrb_nil_p(fontchars))
    {
        int fontchars_values[glyphcount];
        for (int i = 0; i < glyphcount; ++i)
        {
            fontchars_values[i] = mrb_int(mrb, mrb_ary_entry(fontchars, i));
        }
        *out = LoadFontEx(filename, fontsize, fontchars_values, glyphcount);
    }
    else
    {
        *out = LoadFontEx(filename, fontsize, NULL, glyphcount);
    }
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFontFromImage
mrb_value mrb_load_font_from_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Color *key;
    mrb_int firstchar;
    mrb_get_args(mrb, "dds", &image, &Raylib_Image_type, &key, &Raylib_Color_type, &firstchar);
    Font *out = (Font *)malloc(sizeof(Font));
    *out = LoadFontFromImage(*image, *key, firstchar);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFontFromMemory
mrb_value mrb_load_font_from_memory(mrb_state *mrb, mrb_value self)
{
    const char *filetype;
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_int fontsize;
    mrb_value fontchars;
    mrb_int glyphcount;
    mrb_get_args(mrb, "zziiA!i", &filetype, &filedata, &datasize, &fontsize, &fontchars, &glyphcount);
    Font *out = (Font *)malloc(sizeof(Font));
    if (!mrb_nil_p(fontchars))
    {
        int fontchars_values[glyphcount];
        for (int i = 0; i < glyphcount; ++i)
        {
            fontchars_values[i] = mrb_int(mrb, mrb_ary_entry(fontchars, i));
        }
        *out = LoadFontFromMemory(filetype, filedata, datasize, fontsize, fontchars_values, glyphcount);
    }
    else
    {
        *out = LoadFontFromMemory(filetype, filedata, datasize, fontsize, NULL, glyphcount);
    }
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// IsFontValid
mrb_value mrb_is_font_valid(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_get_args(mrb, "d", &font, &Raylib_Font_type);
    return mrb_bool_value(IsFontValid(*font));
}

// LoadFontData
mrb_value mrb_load_font_data(mrb_state *mrb, mrb_value self)
{
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_int fontsize;
    mrb_value fontchars;
    mrb_int glyphcount;
    mrb_int type;
    mrb_get_args(mrb, "ziiA!ii", &filedata, &datasize, &fontsize, &fontchars, &glyphcount, &type);
    GlyphInfo *out;
    if (!mrb_nil_p(fontchars))
    {
        int fontchars_values[glyphcount];
        for (int i = 0; i < glyphcount; ++i)
        {
            fontchars_values[i] = mrb_int(mrb, mrb_ary_entry(fontchars, i));
        }
        out = LoadFontData(filedata, datasize, fontsize, fontchars_values, glyphcount, type);
    }
    else
    {
        out = LoadFontData(filedata, datasize, fontsize, NULL, glyphcount, type);
    }
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < glyphcount; ++i)
    {
        GlyphInfo *glyph = (GlyphInfo *)malloc(sizeof(GlyphInfo));
        *glyph = out[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_GlyphInfo_class, &Raylib_GlyphInfo_type, glyph)));
    }
    return ary;
}

// GenImageFontAtlas
mrb_value mrb_gen_image_font_atlas(mrb_state *mrb, mrb_value self)
{
    mrb_value chars;
    mrb_value recs;
    mrb_int glyphcount;
    mrb_int fontsize;
    mrb_int padding;
    mrb_int packmethod;
    mrb_get_args(mrb, "AAiiii", &chars, &recs, &glyphcount, &fontsize, &padding, &packmethod);

    GlyphInfo chars_values[glyphcount];
    Rectangle *recs_values[glyphcount];
    for (int i = 0; i < glyphcount; ++i)
    {
        chars_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(chars, i), &Raylib_GlyphInfo_type, GlyphInfo);
        recs_values[i] = DATA_GET_PTR(mrb, mrb_ary_entry(recs, i), &Raylib_Rectangle_type, Rectangle);
    }

    Image *out = (Image *)malloc(sizeof(Image));
    *out = GenImageFontAtlas(chars_values, recs_values, glyphcount, fontsize, padding, packmethod);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, out));

    return obj;
}

// UnloadFontData
mrb_value mrb_unload_font_data(mrb_state *mrb, mrb_value self)
{
    mrb_value chars;
    mrb_int glyphcount;
    mrb_get_args(mrb, "Ai", &chars, &glyphcount);
    GlyphInfo chars_values[glyphcount];
    for (int i = 0; i < glyphcount; ++i)
    {
        chars_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(chars, i), &Raylib_GlyphInfo_type, GlyphInfo);
    }
    UnloadFontData(chars_values, glyphcount);
    return mrb_nil_value();
}

// UnloadFont
mrb_value mrb_unload_font(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_get_args(mrb, "d", &font, &Raylib_Font_type);
    UnloadFont(*font);
    return mrb_nil_value();
}

// ExportFontAsCode
mrb_value mrb_export_font_as_code(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *filename;
    mrb_get_args(mrb, "dz", &font, &Raylib_Font_type, &filename);
    return mrb_bool_value(ExportFontAsCode(*font, filename));
}

void mrb_raylib_setup_font_loading(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "get_font_default", mrb_get_font_default, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "load_font", mrb_load_font, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_font_ex", mrb_load_font_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "load_font_from_image", mrb_load_font_from_image, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_font_from_memory", mrb_load_font_from_memory, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "is_font_valid?", mrb_is_font_valid, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_font_data", mrb_load_font_data, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "gen_image_font_atlas", mrb_gen_image_font_atlas, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "unload_font_data", mrb_unload_font_data, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_font", mrb_unload_font, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_font_as_code", mrb_export_font_as_code, MRB_ARGS_REQ(2));
}