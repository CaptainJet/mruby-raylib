//-------
// Shader Functions
//-------

// LoadShader
mrb_value mrb_load_shader(mrb_state *mrb, mrb_value self)
{
    char *vsfilename, *fsfilename;
    mrb_get_args(mrb, "zz", &vsfilename, &fsfilename);

    Shader *shader = (Shader *)malloc(sizeof(Shader));
    *shader = LoadShader(vsfilename, fsfilename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Shader_class, &Raylib_Shader_type, shader));

    return obj;
}

// LoadShaderFromMemory
mrb_value mrb_load_shader_from_memory(mrb_state *mrb, mrb_value self)
{
    char *vscode, *fscode;
    mrb_get_args(mrb, "zz", &vscode, &fscode);

    Shader *shader = (Shader *)malloc(sizeof(Shader));
    *shader = LoadShaderFromMemory(vscode, fscode);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Shader_class, &Raylib_Shader_type, shader));

    return obj;
}

// IsShaderValid
mrb_value mrb_is_shader_valid(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_get_args(mrb, "d", &shader, &Raylib_Shader_type);
    return mrb_bool_value(IsShaderValid(*shader));
}

// GetShaderLocation
mrb_value mrb_get_shader_location(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    char *uniformname;
    mrb_get_args(mrb, "dz", &shader, &Raylib_Shader_type, &uniformname);
    return mrb_int_value(mrb, GetShaderLocation(*shader, uniformname));
}

// GetShaderLocationAttrib
mrb_value mrb_get_shader_location_attrib(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    char *attribname;
    mrb_get_args(mrb, "dz", &shader, &Raylib_Shader_type, &attribname);
    return mrb_int_value(mrb, GetShaderLocationAttrib(*shader, attribname));
}

// SetShaderValueMatrix
mrb_value mrb_set_shader_value_matrix(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_int locindex;
    Matrix *mat;
    mrb_get_args(mrb, "did", &shader, &Raylib_Shader_type, &locindex, &mat, &Raylib_Matrix_type);
    SetShaderValueMatrix(*shader, locindex, *mat);
    return mrb_nil_value();
}

// SetShaderValueTexture
mrb_value mrb_set_shader_value_texture(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_int locindex;
    Texture *texture;
    mrb_get_args(mrb, "did", &shader, &Raylib_Shader_type, &locindex, &texture, &Raylib_Texture_type);
    SetShaderValueTexture(*shader, locindex, *texture);
    return mrb_nil_value();
}

// UnloadShader
mrb_value mrb_unload_shader(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_get_args(mrb, "d", &shader, &Raylib_Shader_type);
    UnloadShader(*shader);
    return mrb_nil_value();
}

void mrb_raylib_setup_shader(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_shader", mrb_load_shader, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "load_shader_from_memory", mrb_load_shader_from_memory, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_shader_valid?", mrb_is_shader_valid, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_shader_location", mrb_get_shader_location, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_shader_location_attrib", mrb_get_shader_location_attrib, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_shader_value_matrix", mrb_set_shader_value_matrix, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "set_shader_value_texture", mrb_set_shader_value_texture, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "unload_shader", mrb_unload_shader, MRB_ARGS_REQ(1));
}