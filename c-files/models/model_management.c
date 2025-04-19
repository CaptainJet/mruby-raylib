//-------
// Model Management Functions
//-------

// LoadModel
mrb_value mrb_load_model(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Model *out = (Model *)malloc(sizeof(Model));
    *out = LoadModel(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Model_class, &Raylib_Model_type, out));

    return obj;
}

// LoadModelFromMesh
mrb_value mrb_load_model_from_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    Model *out = (Model *)malloc(sizeof(Model));
    *out = LoadModelFromMesh(*mesh);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Model_class, &Raylib_Model_type, out));

    return obj;
}

// IsModelValid
mrb_value mrb_is_model_valid(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_get_args(mrb, "d", &model, &Raylib_Model_type);
    return mrb_bool_value(IsModelValid(*model));
}

// UnloadModel
mrb_value mrb_unload_model(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_get_args(mrb, "d", &model, &Raylib_Model_type);
    UnloadModel(*model);
    return mrb_nil_value();
}

// GetModelBoundingBox
mrb_value mrb_get_model_bounding_box(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_get_args(mrb, "d", &model, &Raylib_Model_type);
    BoundingBox *out = (BoundingBox *)malloc(sizeof(BoundingBox));
    *out = GetModelBoundingBox(*model);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_BoundingBox_class, &Raylib_BoundingBox_type, out));

    return obj;
}

void mrb_raylib_setup_model_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_model", mrb_load_model, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_model_from_mesh", mrb_load_model_from_mesh, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_model_valid?", mrb_is_model_valid, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_model", mrb_unload_model, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_model_bounding_box", mrb_get_model_bounding_box, MRB_ARGS_REQ(1));
}