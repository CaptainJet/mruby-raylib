//-------
// Mesh Generation Functions
//-------

// GenMeshPoly
mrb_value mrb_gen_mesh_poly(mrb_state *mrb, mrb_value self)
{
    mrb_int sides;
    mrb_float radius;
    mrb_get_args(mrb, "if", &sides, &radius);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshPoly(sides, radius);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshPlane
mrb_value mrb_gen_mesh_plane(mrb_state *mrb, mrb_value self)
{
    mrb_float width;
    mrb_float length;
    mrb_int resx;
    mrb_int resz;
    mrb_get_args(mrb, "ffii", &width, &length, &resx, &resz);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshPlane(width, length, resx, resz);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCube
mrb_value mrb_gen_mesh_cube(mrb_state *mrb, mrb_value self)
{
    mrb_float width;
    mrb_float height;
    mrb_float length;
    mrb_get_args(mrb, "fff", &width, &height, &length);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCube(width, height, length);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshSphere
mrb_value mrb_gen_mesh_sphere(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    mrb_get_args(mrb, "fii", &radius, &rings, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshSphere(radius, rings, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshHemiSphere
mrb_value mrb_gen_mesh_hemi_sphere(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    mrb_get_args(mrb, "fii", &radius, &rings, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshHemiSphere(radius, rings, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCyclinder
mrb_value mrb_gen_mesh_cylinder(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float height;
    mrb_int slices;
    mrb_get_args(mrb, "ffi", &radius, &height, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCylinder(radius, height, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCone
mrb_value mrb_gen_mesh_cone(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float height;
    mrb_int slices;
    mrb_get_args(mrb, "ffi", &radius, &height, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCone(radius, height, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshTorus
mrb_value mrb_gen_mesh_torus(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float size;
    mrb_int radseg;
    mrb_int sides;
    mrb_get_args(mrb, "ffii", &radius, &size, &radseg, &sides);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshTorus(radius, size, radseg, sides);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshKnot
mrb_value mrb_gen_mesh_knot(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float size;
    mrb_int radseg;
    mrb_int sides;
    mrb_get_args(mrb, "ffii", &radius, &size, &radseg, &sides);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshKnot(radius, size, radseg, sides);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshHeightmap
mrb_value mrb_gen_mesh_heightmap(mrb_state *mrb, mrb_value self)
{
    Image *heightmap;
    Vector3 *size;
    mrb_get_args(mrb, "dd", &heightmap, &Raylib_Image_type, &size, &Raylib_Vector3_type);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshHeightmap(*heightmap, *size);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCubicmap
mrb_value mrb_gen_mesh_cubicmap(mrb_state *mrb, mrb_value self)
{
    Image *cubicmap;
    Vector3 *cubesize;
    mrb_get_args(mrb, "dd", &cubicmap, &Raylib_Image_type, &cubesize, &Raylib_Vector3_type);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCubicmap(*cubicmap, *cubesize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

void mrb_raylib_setup_mesh_generation(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_poly", mrb_gen_mesh_poly, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_plane", mrb_gen_mesh_plane, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cube", mrb_gen_mesh_cube, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_sphere", mrb_gen_mesh_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_hemi_sphere", mrb_gen_mesh_hemi_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cylinder", mrb_gen_mesh_cylinder, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cone", mrb_gen_mesh_cone, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_torus", mrb_gen_mesh_torus, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_knot", mrb_gen_mesh_knot, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_heightmap", mrb_gen_mesh_heightmap, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cubicmap", mrb_gen_mesh_cubicmap, MRB_ARGS_REQ(2));
}