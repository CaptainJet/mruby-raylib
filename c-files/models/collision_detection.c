//-------
// Collision Detection Functions
//-------

// CheckCollisionSpheres
mrb_value mrb_check_collision_spheres(mrb_state *mrb, mrb_value self)
{
    Vector3 *center1;
    mrb_float radius1;
    Vector3 *center2;
    mrb_float radius2;
    mrb_get_args(mrb, "dfdf", &center1, &Raylib_Vector3_type, &radius1, &center2, &Raylib_Vector3_type, &radius2);
    return mrb_bool_value(CheckCollisionSpheres(*center1, radius1, *center2, radius2));
}

// CheckCollisionBoxes
mrb_value mrb_check_collision_boxes(mrb_state *mrb, mrb_value self)
{
    BoundingBox *box1;
    BoundingBox *box2;
    mrb_get_args(mrb, "dd", &box1, &Raylib_BoundingBox_type, &box2, &Raylib_BoundingBox_type);
    return mrb_bool_value(CheckCollisionBoxes(*box1, *box2));
}

// CheckCollisionBoxSphere
mrb_value mrb_check_collision_box_sphere(mrb_state *mrb, mrb_value self)
{
    BoundingBox *box;
    Vector3 *center;
    mrb_float radius;
    mrb_get_args(mrb, "ddf", &box, &Raylib_BoundingBox_type, &center, &Raylib_Vector3_type, &radius);
    return mrb_bool_value(CheckCollisionBoxSphere(*box, *center, radius));
}

// GetRayCollisionSphere
mrb_value mrb_get_ray_collision_sphere(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Vector3 *center;
    mrb_float radius;
    mrb_get_args(mrb, "ddf", &ray, &Raylib_Ray_type, &center, &Raylib_Vector3_type, &radius);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionSphere(*ray, *center, radius);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionBox
mrb_value mrb_get_ray_collision_box(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    BoundingBox *box;
    mrb_get_args(mrb, "dd", &ray, &Raylib_Ray_type, &box, &Raylib_BoundingBox_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionBox(*ray, *box);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionMesh
mrb_value mrb_get_ray_collision_mesh(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Mesh *mesh;
    Matrix *transform;
    mrb_get_args(mrb, "ddd", &ray, &Raylib_Ray_type, &mesh, &Raylib_Mesh_type, &transform, &Raylib_Matrix_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionMesh(*ray, *mesh, *transform);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionTriangle
mrb_value mrb_get_ray_collision_triangle(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Vector3 *p1;
    Vector3 *p2;
    Vector3 *p3;
    mrb_get_args(mrb, "dddd", &ray, &Raylib_Ray_type, &p1, &Raylib_Vector3_type, &p2, &Raylib_Vector3_type, &p3, &Raylib_Vector3_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionTriangle(*ray, *p1, *p2, *p3);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionQuad
mrb_value mrb_get_ray_collision_quad(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Vector3 *p1;
    Vector3 *p2;
    Vector3 *p3;
    Vector3 *p4;
    mrb_get_args(mrb, "ddddd", &ray, &Raylib_Ray_type, &p1, &Raylib_Vector3_type, &p2, &Raylib_Vector3_type, &p3, &Raylib_Vector3_type, &p4, &Raylib_Vector3_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionQuad(*ray, *p1, *p2, *p3, *p4);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

void mrb_raylib_setup_collision_detection(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "check_collision_spheres", mrb_check_collision_spheres, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "check_collision_boxes", mrb_check_collision_boxes, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "check_collision_box_sphere", mrb_check_collision_box_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_sphere", mrb_get_ray_collision_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_box", mrb_get_ray_collision_box, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_mesh", mrb_get_ray_collision_mesh, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_triangle", mrb_get_ray_collision_triangle, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_quad", mrb_get_ray_collision_quad, MRB_ARGS_REQ(5));
}