//-------
// Mesh Management Functions
//-------

// UploadMesh
mrb_value mrb_upload_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_bool dynamic;
    mrb_get_args(mrb, "db", &mesh, &Raylib_Mesh_type, &dynamic);
    UploadMesh(mesh, dynamic);
    return mrb_nil_value();
}

// UnloadMesh
mrb_value mrb_unload_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    UnloadMesh(*mesh);
    return mrb_nil_value();
}

// DrawMesh
mrb_value mrb_draw_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    Material *material;
    Matrix *transform;
    mrb_get_args(mrb, "ddd", &mesh, &Raylib_Mesh_type, &material, &Raylib_Material_type, &transform, &Raylib_Matrix_type);
    DrawMesh(*mesh, *material, *transform);
    return mrb_nil_value();
}

// DrawMeshInstanced
mrb_value mrb_draw_mesh_instanced(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    Material *material;
    mrb_value transforms;
    mrb_int instances;
    mrb_get_args(mrb, "ddAi", &mesh, &Raylib_Mesh_type, &material, &Raylib_Material_type, &transforms, &instances);
    Matrix out_transforms[instances];
    for (int i = 0; i < instances; ++i)
    {
        out_transforms[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(transforms, i), &Raylib_Matrix_type, Matrix);
    }
    DrawMeshInstanced(*mesh, *material, out_transforms, instances);
    return mrb_nil_value();
}

// GetMeshBoundingBox
mrb_value mrb_get_mesh_bounding_box(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    BoundingBox *out = (BoundingBox *)malloc(sizeof(BoundingBox));
    *out = GetMeshBoundingBox(*mesh);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_BoundingBox_class, &Raylib_BoundingBox_type, out));
    return obj;
}

// GenMeshTangents
mrb_value mrb_gen_mesh_tangents(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    GenMeshTangents(mesh);
    return mrb_nil_value();
}

// ExportMesh
mrb_value mrb_export_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    const char *filename;
    mrb_get_args(mrb, "dz", &mesh, &Raylib_Mesh_type, &filename);
    return mrb_bool_value(ExportMesh(*mesh, filename));
}

// ExportMeshAsCode
mrb_value mrb_export_mesh_as_code(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    const char *filename;
    mrb_get_args(mrb, "dz", &mesh, &Raylib_Mesh_type, &filename);
    return mrb_bool_value(ExportMeshAsCode(*mesh, filename));
}

void mrb_raylib_setup_mesh_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "upload_mesh", mrb_upload_mesh, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_mesh", mrb_unload_mesh, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "draw_mesh", mrb_draw_mesh, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_mesh_instanced", mrb_draw_mesh_instanced, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_mesh_bounding_box", mrb_get_mesh_bounding_box, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_tangents", mrb_gen_mesh_tangents, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_mesh", mrb_export_mesh, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "export_mesh_as_code", mrb_export_mesh_as_code, MRB_ARGS_REQ(2));
}