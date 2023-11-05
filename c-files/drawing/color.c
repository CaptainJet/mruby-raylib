//-------
// Color Functions
//-------

// Fade
mrb_value mrb_fade(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float alpha;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &alpha);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = Fade(*color, alpha);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorToInt
mrb_value mrb_color_to_int(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    return mrb_int_value(mrb, ColorToInt(*color));
}

// ColorNormalize
mrb_value mrb_color_normalize(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    Vector4 *out = (Vector4 *)malloc(sizeof(Vector4));
    *out = ColorNormalize(*color);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector4_class, &Raylib_Vector4_type, out));

    return obj;
}

// ColorFromNormalized
mrb_value mrb_color_from_normalized(mrb_state *mrb, mrb_value self)
{
    Vector4 *normalized;
    mrb_get_args(mrb, "d", &normalized, &Raylib_Vector4_type);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorFromNormalized(*normalized);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorToHSV
mrb_value mrb_color_to_hsv(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    Vector3 *out = (Vector3 *)malloc(sizeof(Vector3));
    *out = ColorToHSV(*color);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, out));

    return obj;
}

// ColorFromHSV
mrb_value mrb_color_from_hsv(mrb_state *mrb, mrb_value self)
{
    mrb_float hue;
    mrb_float saturation;
    mrb_float value;
    mrb_get_args(mrb, "fff", &hue, &saturation, &value);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorFromHSV(hue, saturation, value);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorTint
mrb_value mrb_color_tint(mrb_state *mrb, mrb_value self)
{
    Color *color;
    Color *tint;
    mrb_get_args(mrb, "dd", &color, &Raylib_Color_type, &tint, &Raylib_Color_type);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorTint(*color, *tint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorBrightness
mrb_value mrb_color_brightness(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float factor;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &factor);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorBrightness(*color, factor);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorContrast
mrb_value mrb_color_contrast(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float contrast;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &contrast);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorContrast(*color, contrast);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorAlpha
mrb_value mrb_color_alpha(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float alpha;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &alpha);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorAlpha(*color, alpha);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorAlphaBlend
mrb_value mrb_color_alpha_blend(mrb_state *mrb, mrb_value self)
{
    Color *dst;
    Color *src;
    Color *tint;
    mrb_get_args(mrb, "ddd", &dst, &Raylib_Color_type, &src, &Raylib_Color_type, &tint, &Raylib_Color_type);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorAlphaBlend(*dst, *src, *tint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// GetColor
mrb_value mrb_get_color(mrb_state *mrb, mrb_value self)
{
    mrb_int hexvalue;
    mrb_get_args(mrb, "i", &hexvalue);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = GetColor(hexvalue);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// GetPixelDataSize
mrb_value mrb_get_pixel_data_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_int format;
    mrb_get_args(mrb, "iii", &width, &height, &format);
    return mrb_int_value(mrb, GetPixelDataSize(width, height, format));
}

void mrb_raylib_setup_color(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "fade", mrb_fade, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_to_int", mrb_color_to_int, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_normalize", mrb_color_normalize, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_from_normalized", mrb_color_from_normalized, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_to_hsv", mrb_color_to_hsv, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_from_hsv", mrb_color_from_hsv, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "color_tint", mrb_color_tint, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_brightness", mrb_color_brightness, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_contrast", mrb_color_contrast, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_alpha", mrb_color_alpha, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_alpha_blend", mrb_color_alpha_blend, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_color", mrb_get_color, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_pixel_data_size", mrb_get_pixel_data_size, MRB_ARGS_REQ(3));
}