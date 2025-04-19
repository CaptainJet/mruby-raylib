//-------
// Material Loading Functions
//-------

// LoadMaterials
mrb_value mrb_load_materials(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int mmaterialcount;
    mrb_get_args(mrb, "zi", &filename, &mmaterialcount);
    int materialcount = 0;
    Material *materials = LoadMaterials(filename, &materialcount);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < materialcount; ++i)
    {
        Material *material = (Material *)malloc(sizeof(Material));
        *material = materials[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Material_class, &Raylib_Material_type, material)));
    }
    return ary;
}

// LoadMaterialDefault
mrb_value mrb_load_material_default(mrb_state *mrb, mrb_value self)
{
    Material *out = (Material *)malloc(sizeof(Material));
    *out = LoadMaterialDefault();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Material_class, &Raylib_Material_type, out));
    return obj;
}

// IsMaterialValid
mrb_value mrb_is_material_valid(mrb_state *mrb, mrb_value self)
{
    Material *material;
    mrb_get_args(mrb, "d", &material, &Raylib_Material_type);
    return mrb_bool_value(IsMaterialValid(*material));
}

// UnloadMaterial
mrb_value mrb_unload_material(mrb_state *mrb, mrb_value self)
{
    Material *material;
    mrb_get_args(mrb, "d", &material, &Raylib_Material_type);
    UnloadMaterial(*material);
    return mrb_nil_value();
}

// SetMaterialTexture
mrb_value mrb_set_material_texture(mrb_state *mrb, mrb_value self)
{
    Material *material;
    mrb_int maptype;
    Texture *texture;
    mrb_get_args(mrb, "did", &material, &Raylib_Material_type, &maptype, &texture, &Raylib_Texture_type);
    SetMaterialTexture(material, maptype, *texture);
    return mrb_nil_value();
}

// SetModelMeshMaterial
mrb_value mrb_set_model_mesh_material(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_int meshid;
    mrb_int materialid;
    mrb_get_args(mrb, "dii", &model, &Raylib_Model_type, &meshid, &materialid);
    SetModelMeshMaterial(model, meshid, materialid);
    return mrb_nil_value();
}

void mrb_raylib_setup_material_loading(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_materials", mrb_load_materials, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "load_material_default", mrb_load_material_default, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_material_valid?", mrb_is_material_valid, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_material", mrb_unload_material, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_material_texture", mrb_set_material_texture, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "set_model_mesh_material", mrb_set_model_mesh_material, MRB_ARGS_REQ(3));
}