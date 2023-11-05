//-------
// Texture Functions
//-------

// LoadTexture
mrb_value mrb_load_texture(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Texture *texture = (Texture *)malloc(sizeof(Texture));
    *texture = LoadTexture(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));

    return obj;
}

// LoadTextureFromImage
mrb_value mrb_load_texture_from_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    Texture *texture = (Texture *)malloc(sizeof(Texture));
    *texture = LoadTextureFromImage(*image);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));

    return obj;
}

// LoadTextureCubemap
mrb_value mrb_load_texture_cubemap(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int layout;
    mrb_get_args(mrb, "di", &image, &Raylib_Image_type, &layout);
    Texture *texture = (Texture *)malloc(sizeof(Texture));
    *texture = LoadTextureCubemap(*image, layout);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));

    return obj;
}

// LoadRenderTexture
mrb_value mrb_load_render_texture(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_get_args(mrb, "ii", &width, &height);
    RenderTexture *rendertexture = (RenderTexture *)malloc(sizeof(RenderTexture));
    *rendertexture = LoadRenderTexture(width, height);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RenderTexture_class, &Raylib_RenderTexture_type, rendertexture));

    return obj;
}

// IsTextureReady
mrb_value mrb_is_texture_ready(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    return mrb_bool_value(IsTextureReady(*texture));
}

// UnloadTexture
mrb_value mrb_unload_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    UnloadTexture(*texture);

    return mrb_nil_value();
}

// IsRenderTextureReady
mrb_value mrb_is_render_texture_ready(mrb_state *mrb, mrb_value self)
{
    RenderTexture *target;
    mrb_get_args(mrb, "d", &target, &Raylib_RenderTexture_type);
    return mrb_bool_value(IsRenderTextureReady(*target));
}

// UnloadRenderTexture
mrb_value mrb_unload_render_texture(mrb_state *mrb, mrb_value self)
{
    RenderTexture *target;
    mrb_get_args(mrb, "d", &target, &Raylib_RenderTexture_type);
    UnloadRenderTexture(*target);

    return mrb_nil_value();
}

// GenTextureMipmaps
mrb_value mrb_gen_texture_mipmaps(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    GenTextureMipmaps(texture);

    return mrb_nil_value();
}

// SetTextureFilter
mrb_value mrb_set_texture_filter(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_int filter;
    mrb_get_args(mrb, "di", &texture, &Raylib_Texture_type, &filter);
    SetTextureFilter(*texture, filter);

    return mrb_nil_value();
}

// SetTextureWrap
mrb_value mrb_set_texture_wrap(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_int wrap;
    mrb_get_args(mrb, "di", &texture, &Raylib_Texture_type, &wrap);
    SetTextureWrap(*texture, wrap);

    return mrb_nil_value();
}

// DrawTexture
mrb_value mrb_draw_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_int posx;
    mrb_int posy;
    Color *tint;
    mrb_get_args(mrb, "diid", &texture, &Raylib_Texture_type, &posx, &posy, &tint, &Raylib_Color_type);
    DrawTexture(*texture, posx, posy, *tint);

    return mrb_nil_value();
}

// DrawTextureV
mrb_value mrb_draw_texture_v(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Vector2 *position;
    Color *tint;
    mrb_get_args(mrb, "ddd", &texture, &Raylib_Texture_type, &position, &Raylib_Vector2_type, &tint, &Raylib_Color_type);
    DrawTextureV(*texture, *position, *tint);

    return mrb_nil_value();
}

// DrawTextureEx
mrb_value mrb_draw_texture_ex(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Vector2 *position;
    mrb_float rotation;
    mrb_float scale;
    Color *tint;
    mrb_get_args(mrb, "ddffd", &texture, &Raylib_Texture_type, &position, &Raylib_Vector2_type, &rotation, &scale, &tint, &Raylib_Color_type);
    DrawTextureEx(*texture, *position, rotation, scale, *tint);

    return mrb_nil_value();
}

// DrawTextureRec
mrb_value mrb_draw_texture_rec(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Rectangle *source;
    Vector2 *position;
    Color *tint;
    mrb_get_args(mrb, "dddd", &texture, &Raylib_Texture_type, &source, &Raylib_Rectangle_type, &position, &Raylib_Vector2_type, &tint, &Raylib_Color_type);
    DrawTextureRec(*texture, *source, *position, *tint);

    return mrb_nil_value();
}

// DrawTexturePro
mrb_value mrb_draw_texture_pro(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Rectangle *source;
    Rectangle *dest;
    Vector2 *origin;
    mrb_float rotation;
    Color *tint;
    mrb_get_args(mrb, "ddddfd", &texture, &Raylib_Texture_type, &source, &Raylib_Rectangle_type, &dest, &Raylib_Rectangle_type, &origin, &Raylib_Vector2_type,
                 &rotation, &tint, &Raylib_Color_type);
    DrawTexturePro(*texture, *source, *dest, *origin, rotation, *tint);

    return mrb_nil_value();
}

// DrawTextureNPatch
mrb_value mrb_draw_texture_npatch(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    NPatchInfo *npatchinfo;
    Rectangle *dest;
    Vector2 *origin;
    mrb_float rotation;
    Color *tint;
    mrb_get_args(mrb, "ddddfd", &texture, &Raylib_Texture_type, &npatchinfo, &Raylib_NPatchInfo_type, &dest, &Raylib_Rectangle_type, &origin, &Raylib_Vector2_type,
                 &rotation, &tint, &Raylib_Color_type);
    DrawTextureNPatch(*texture, *npatchinfo, *dest, *origin, rotation, *tint);

    return mrb_nil_value();
}

void mrb_raylib_setup_texture(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_texture", mrb_load_texture, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_texture_from_image", mrb_load_texture_from_image, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_texture_cubemap", mrb_load_texture_cubemap, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "load_render_texture", mrb_load_render_texture, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_texture_ready?", mrb_is_texture_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_texture", mrb_unload_texture, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_render_texture_ready?", mrb_is_render_texture_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_render_texture", mrb_unload_render_texture, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "gen_texture_mipmaps", mrb_gen_texture_mipmaps, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_texture_filter", mrb_set_texture_filter, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_texture_wrap", mrb_set_texture_wrap, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_texture", mrb_draw_texture, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_v", mrb_draw_texture_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_ex", mrb_draw_texture_ex, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_rec", mrb_draw_texture_rec, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_pro", mrb_draw_texture_pro, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_npatch", mrb_draw_texture_npatch, MRB_ARGS_REQ(6));
}