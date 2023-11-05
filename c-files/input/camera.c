//-------
// Camera Functions
//-------

// UpdateCamera
mrb_value mrb_update_camera(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    mrb_int mode;
    mrb_get_args(mrb, "di", &camera, &Raylib_Camera_type, &mode);
    UpdateCamera(camera, mode);
    return mrb_nil_value();
}

// UpdateCameraPro
mrb_value mrb_update_camera_pro(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    Vector3 movement;
    Vector3 rotation;
    mrb_float zoom;
    mrb_get_args(mrb, "dddf", &camera, &Raylib_Camera_type, &movement, &Raylib_Vector3_type, &rotation, &Raylib_Vector3_type, &zoom);
    UpdateCameraPro(camera, movement, rotation, zoom);
    return mrb_nil_value();
}

void mrb_raylib_setup_camera(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "update_camera", mrb_update_camera, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "update_camera_pro", mrb_update_camera_pro, MRB_ARGS_REQ(4));
}