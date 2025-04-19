//-------
// Screen Space Functions
//-------

// GetScreenToWorldRay
mrb_value mrb_get_screen_to_world_ray(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2;
    Camera *camera;
    mrb_get_args(mrb, "dd", &vector2, &Raylib_Vector2_type, &camera, &Raylib_Camera_type);

    Ray *ray = (Ray *)malloc(sizeof(Ray));
    *ray = GetScreenToWorldRay(*vector2, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Ray_class, &Raylib_Ray_type, ray));

    return obj;
}

// GetScreenToWorldRayEx
mrb_value mrb_get_screen_to_world_ray_ex(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2;
    Camera *camera;
    mrb_int width;
    mrb_int height;
    mrb_get_args(mrb, "ddii", &vector2, &Raylib_Vector2_type, &camera, &Raylib_Camera_type, &width, &height);

    Ray *ray = (Ray *)malloc(sizeof(Ray));
    *ray = GetScreenToWorldRayEx(*vector2, *camera, width, height);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Ray_class, &Raylib_Ray_type, ray));

    return obj;
}

// GetCameraMatrix
mrb_value mrb_get_camera_matrix(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    mrb_get_args(mrb, "d", &camera, &Raylib_Camera_type);

    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    *matrix = GetCameraMatrix(*camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Matrix_class, &Raylib_Matrix_type, matrix));

    return obj;
}

// GetCameraMatrix2D
mrb_value mrb_get_camera_matrix2D(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera;
    mrb_get_args(mrb, "d", &camera, &Raylib_Camera2D_type);

    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    *matrix = GetCameraMatrix2D(*camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Matrix_class, &Raylib_Matrix_type, matrix));

    return obj;
}

// GetWorldToScreen
mrb_value mrb_get_world_to_screen(mrb_state *mrb, mrb_value self)
{
    Vector3 *vector;
    Camera *camera;
    mrb_get_args(mrb, "dd", &vector, &Raylib_Vector3_type, &camera, &Raylib_Camera_type);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWorldToScreen(*vector, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetWorldToScreenEx
mrb_value mrb_get_world_to_screen_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *vector;
    Camera *camera;
    mrb_int width;
    mrb_int height;
    mrb_get_args(mrb, "ddii", &vector, &Raylib_Vector3_type, &camera, &Raylib_Camera_type, &width, &height);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWorldToScreenEx(*vector, *camera, width, height);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetWorldToScreen2D
mrb_value mrb_get_world_to_screen2d(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector;
    Camera2D *camera;
    mrb_get_args(mrb, "dd", &vector, &Raylib_Vector2_type, &camera, &Raylib_Camera2D_type);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWorldToScreen2D(*vector, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetScreenToWorld2D
mrb_value mrb_get_screen_to_world2d(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector;
    Camera2D *camera;
    mrb_get_args(mrb, "dd", &vector, &Raylib_Vector2_type, &camera, &Raylib_Camera2D_type);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetScreenToWorld2D(*vector, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

void mrb_raylib_setup_screen_space(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "get_screen_to_world_ray", mrb_get_screen_to_world_ray, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_screen_to_world_ray_ex", mrb_get_screen_to_world_ray_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_camera_matrix", mrb_get_camera_matrix, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_camera_matrix2d", mrb_get_camera_matrix2D, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_world_to_screen", mrb_get_world_to_screen, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_world_to_screen_ex", mrb_get_world_to_screen_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_world_to_screen2d", mrb_get_world_to_screen2d, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_screen_to_world2d", mrb_get_screen_to_world2d, MRB_ARGS_REQ(2));
}