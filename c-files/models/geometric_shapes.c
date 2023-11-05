//-------
// Geometric Shapes Functions
//-------

// DrawLine3D
mrb_value mrb_draw_line_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    Color *color;
    mrb_get_args(mrb, "ddd", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawLine3D(*startpos, *endpos, *color);
    return mrb_nil_value();
}

// DrawPoint3D
mrb_value mrb_draw_point_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Color *color;
    mrb_get_args(mrb, "dd", &position, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawPoint3D(*position, *color);
    return mrb_nil_value();
}

// DrawCircle3D
mrb_value mrb_draw_circle_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *center;
    mrb_float radius;
    Vector3 *rotationaxis;
    mrb_float rotationangle;
    Color *color;
    mrb_get_args(mrb, "dfdfd", &center, &Raylib_Vector3_type, &radius, &rotationaxis, &Raylib_Vector3_type, &rotationangle, &color, &Raylib_Color_type);
    DrawCircle3D(*center, radius, *rotationaxis, rotationangle, *color);
    return mrb_nil_value();
}

// DrawTriangle3D
mrb_value mrb_draw_triangle_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *v1;
    Vector3 *v2;
    Vector3 *v3;
    Color *color;
    mrb_get_args(mrb, "dddd", &v1, &Raylib_Vector3_type, &v2, &Raylib_Vector3_type, &v3, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawTriangle3D(*v1, *v2, *v3, *color);
    return mrb_nil_value();
}

// DrawTriangleStrip3D
mrb_value mrb_draw_triangle_strip_3d(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    Color *color;
    mrb_get_args(mrb, "Aid", &points, &pointcount, &color, &Raylib_Color_type);
    Vector3 out_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        out_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector3_type, Vector3);
    }
    DrawTriangleStrip3D(out_points, pointcount, *color);
    return mrb_nil_value();
}

// DrawCube
mrb_value mrb_draw_cube(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float width;
    mrb_float height;
    mrb_float length;
    Color *color;
    mrb_get_args(mrb, "dfffd", &position, &Raylib_Vector3_type, &width, &height, &length, &color, &Raylib_Color_type);
    DrawCube(*position, width, height, length, *color);
    return mrb_nil_value();
}

// DrawCubeV
mrb_value mrb_draw_cube_v(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Vector3 *size;
    Color *color;
    mrb_get_args(mrb, "ddd", &position, &Raylib_Vector3_type, &size, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawCubeV(*position, *size, *color);
    return mrb_nil_value();
}

// DrawCubeWires
mrb_value mrb_draw_cube_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float width;
    mrb_float height;
    mrb_float length;
    Color *color;
    mrb_get_args(mrb, "dfffd", &position, &Raylib_Vector3_type, &width, &height, &length, &color, &Raylib_Color_type);
    DrawCubeWires(*position, width, height, length, *color);
    return mrb_nil_value();
}

// DrawCubeWiresV
mrb_value mrb_draw_cube_wires_v(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Vector3 *size;
    Color *color;
    mrb_get_args(mrb, "ddd", &position, &Raylib_Vector3_type, &size, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawCubeWiresV(*position, *size, *color);
    return mrb_nil_value();
}

// DrawSphere
mrb_value mrb_draw_sphere(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    mrb_float radius;
    Color *color;
    mrb_get_args(mrb, "dfd", &centerpos, &Raylib_Vector3_type, &radius, &color, &Raylib_Color_type);
    DrawSphere(*centerpos, radius, *color);
    return mrb_nil_value();
}

// DrawSphereEx
mrb_value mrb_draw_sphere_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfiid", &centerpos, &Raylib_Vector3_type, &radius, &rings, &slices, &color, &Raylib_Color_type);
    DrawSphereEx(*centerpos, radius, rings, slices, *color);
    return mrb_nil_value();
}

// DrawSphereWires
mrb_value mrb_draw_sphere_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfiid", &centerpos, &Raylib_Vector3_type, &radius, &rings, &slices, &color, &Raylib_Color_type);
    DrawSphereWires(*centerpos, radius, rings, slices, *color);
    return mrb_nil_value();
}

// DrawCylinder
mrb_value mrb_draw_cylinder(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float radiustop;
    mrb_float radiusbottom;
    mrb_float height;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfffid", &position, &Raylib_Vector3_type, &radiustop, &radiusbottom, &height, &slices, &color, &Raylib_Color_type);
    DrawCylinder(*position, radiustop, radiusbottom, height, slices, *color);
    return mrb_nil_value();
}

// DrawCylinderEx
mrb_value mrb_draw_cylinder_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float startradius;
    mrb_float endradius;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfffid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &startradius, &endradius, &slices, &color, &Raylib_Color_type);
    DrawCylinderEx(*startpos, *endpos, startradius, endradius, slices, *color);
    return mrb_nil_value();
}

// DrawCylinderWires
mrb_value mrb_draw_cylinder_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float radiustop;
    mrb_float radiusbottom;
    mrb_float height;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfffid", &position, &Raylib_Vector3_type, &radiustop, &radiusbottom, &height, &slices, &color, &Raylib_Color_type);
    DrawCylinderWires(*position, radiustop, radiusbottom, height, slices, *color);
    return mrb_nil_value();
}

// DrawCylinderWiresEx
mrb_value mrb_draw_cylinder_wires_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float startradius;
    mrb_float endradius;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "ddffid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &startradius, &endradius, &slices, &color, &Raylib_Color_type);
    DrawCylinderWiresEx(*startpos, *endpos, startradius, endradius, slices, *color);
    return mrb_nil_value();
}

// DrawCapsule
mrb_value mrb_draw_capsule(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float radius;
    mrb_int slices;
    mrb_int rings;
    Color *color;
    mrb_get_args(mrb, "ddfiid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &radius, &slices, &rings, &color, &Raylib_Color_type);
    DrawCapsule(*startpos, *endpos, radius, slices, rings, *color);
    return mrb_nil_value();
}

// DrawCapsuleWires
mrb_value mrb_draw_capsule_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float radius;
    mrb_int slices;
    mrb_int rings;
    Color *color;
    mrb_get_args(mrb, "ddfiid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &radius, &slices, &rings, &color, &Raylib_Color_type);
    DrawCapsuleWires(*startpos, *endpos, radius, slices, rings, *color);
    return mrb_nil_value();
}

// DrawPlane
mrb_value mrb_draw_plane(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    Vector2 *size;
    Color *color;
    mrb_get_args(mrb, "ddd", &centerpos, &Raylib_Vector3_type, &size, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    DrawPlane(*centerpos, *size, *color);
    return mrb_nil_value();
}

// DrawRay
mrb_value mrb_draw_ray(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Color *color;
    mrb_get_args(mrb, "dd", &ray, &Raylib_Ray_type, &color, &Raylib_Color_type);
    DrawRay(*ray, *color);
    return mrb_nil_value();
}

// DrawGrid
mrb_value mrb_draw_grid(mrb_state *mrb, mrb_value self)
{
    mrb_int slices;
    mrb_float spacing;
    mrb_get_args(mrb, "if", &slices, &spacing);
    DrawGrid(slices, spacing);
    return mrb_nil_value();
}

void mrb_raylib_setup_geometric_shapes(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "draw_line_3d", mrb_draw_line_3d, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_point_3d", mrb_draw_point_3d, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_3d", mrb_draw_circle_3d, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle_3d", mrb_draw_triangle_3d, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle_strip_3d", mrb_draw_triangle_strip_3d, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_cube", mrb_draw_cube, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_cube_v", mrb_draw_cube_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_cube_wires", mrb_draw_cube_wires, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_cube_wires_v", mrb_draw_cube_wires_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_sphere", mrb_draw_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_sphere_ex", mrb_draw_sphere_ex, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_sphere_wires", mrb_draw_sphere_wires, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder", mrb_draw_cylinder, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder_ex", mrb_draw_cylinder_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder_wires", mrb_draw_cylinder_wires, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder_wires_ex", mrb_draw_cylinder_wires_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_capsule", mrb_draw_capsule, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_capsule_wires", mrb_draw_capsule_wires, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_plane", mrb_draw_plane, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_ray", mrb_draw_ray, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_grid", mrb_draw_grid, MRB_ARGS_REQ(2));
}