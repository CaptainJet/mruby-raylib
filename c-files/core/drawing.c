//-------
// Drawing Functions
//-------

// ClearBackground
mrb_value mrb_clear_background(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    ClearBackground(*color);
    return mrb_nil_value();
}

// BeginDrawing
mrb_value mrb_begin_drawing(mrb_state *mrb, mrb_value self)
{
    BeginDrawing();
    return mrb_nil_value();
}

// EndDrawing
mrb_value mrb_end_drawing(mrb_state *mrb, mrb_value self)
{
    EndDrawing();
    return mrb_nil_value();
}

// BeginMode2D
mrb_value mrb_begin_mode2d(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera2d;
    mrb_get_args(mrb, "d", &camera2d, &Raylib_Camera2D_type);
    BeginMode2D(*camera2d);
    return mrb_nil_value();
}

// EndMode2D
mrb_value mrb_end_mode2d(mrb_state *mrb, mrb_value self)
{
    EndMode2D();
    return mrb_nil_value();
}

// BeginMode3D
mrb_value mrb_begin_mode3d(mrb_state *mrb, mrb_value self)
{
    Camera3D *camera;
    mrb_get_args(mrb, "d", &camera, &Raylib_Camera_type);
    BeginMode3D(*camera);
    return mrb_nil_value();
}

// EndMode3D
mrb_value mrb_end_mode3d(mrb_state *mrb, mrb_value self)
{
    EndMode3D();
    return mrb_nil_value();
}

// BeginTextureMode
mrb_value mrb_begin_texture_mode(mrb_state *mrb, mrb_value self)
{
    RenderTexture *rendertexture;
    mrb_get_args(mrb, "d", &rendertexture, &Raylib_RenderTexture_type);
    BeginTextureMode(*rendertexture);
    return mrb_nil_value();
}

// EndTextureMode
mrb_value mrb_end_texture_mode(mrb_state *mrb, mrb_value self)
{
    EndTextureMode();
    return mrb_nil_value();
}

// BeginShaderMode
mrb_value mrb_begin_shader_mode(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_get_args(mrb, "d", &shader, &Raylib_Shader_type);
    BeginShaderMode(*shader);
    return mrb_nil_value();
}

// EndShaderMode
mrb_value mrb_end_shader_mode(mrb_state *mrb, mrb_value self)
{
    EndShaderMode();
    return mrb_nil_value();
}

// BeginBlendMode
mrb_value mrb_begin_blend_mode(mrb_state *mrb, mrb_value self)
{
    mrb_int mode;
    mrb_get_args(mrb, "i", &mode);
    BeginBlendMode(mode);
    return mrb_nil_value();
}

// EndBlendMode
mrb_value mrb_end_blend_mode(mrb_state *mrb, mrb_value self)
{
    EndBlendMode();
    return mrb_nil_value();
}

// BeginScissorMode
mrb_value mrb_begin_scissor_mode(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y, width, height;
    mrb_get_args(mrb, "iiii", &x, &y, &width, &height);
    BeginScissorMode(x, y, width, height);
    return mrb_nil_value();
}

// EndScissorMode
mrb_value mrb_end_scissor_mode(mrb_state *mrb, mrb_value self)
{
    EndScissorMode();
    return mrb_nil_value();
}

// BeginVrStereoMode
mrb_value mrb_begin_vr_stereo_mode(mrb_state *mrb, mrb_value self)
{
    VrStereoConfig *config;
    mrb_get_args(mrb, "d", &config, &Raylib_VrStereoConfig_type);
    BeginVrStereoMode(*config);
    return mrb_nil_value();
}

// EndVrStereoMode
mrb_value mrb_end_vr_stereo_mode(mrb_state *mrb, mrb_value self)
{
    EndVrStereoMode();
    return mrb_nil_value();
}

void mrb_raylib_setup_drawing(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "clear_background", mrb_clear_background, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "begin_drawing", mrb_begin_drawing, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "end_drawing", mrb_end_drawing, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_mode2d", mrb_begin_mode2d, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_mode2d", mrb_end_mode2d, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_mode3d", mrb_begin_mode3d, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_mode3d", mrb_end_mode3d, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_texture_mode", mrb_begin_texture_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_texture_mode", mrb_end_texture_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_shader_mode", mrb_begin_shader_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_shader_mode", mrb_end_shader_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_blend_mode", mrb_begin_blend_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_blend_mode", mrb_end_blend_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_scissor_mode", mrb_begin_scissor_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_scissor_mode", mrb_end_scissor_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_vr_stereo_mode", mrb_begin_vr_stereo_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_vr_stereo_mode", mrb_end_vr_stereo_mode, MRB_ARGS_NONE());
}
