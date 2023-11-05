//-------
// VR Functions
//-------

// LoadVrStereoConfig
mrb_value mrb_load_vr_stereo_config(mrb_state *mrb, mrb_value self)
{
    VrDeviceInfo *device;
    mrb_get_args(mrb, "d", &device, &Raylib_VrDeviceInfo_type);

    VrStereoConfig *vrstereoconfig = (VrStereoConfig *)malloc(sizeof(VrStereoConfig));
    *vrstereoconfig = LoadVrStereoConfig(*device);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_VrStereoConfig_class, &Raylib_VrStereoConfig_type, vrstereoconfig));

    return obj;
}

// UnloadVrStereoConfig
mrb_value mrb_unload_vr_stereo_config(mrb_state *mrb, mrb_value self)
{
    VrStereoConfig *config;
    mrb_get_args(mrb, "d", &config, &Raylib_VrStereoConfig_type);
    UnloadVrStereoConfig(*config);
    return mrb_nil_value();
}

void mrb_raylib_setup_vr(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_vr_stereo_config", mrb_load_vr_stereo_config, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_vr_stereo_config", mrb_unload_vr_stereo_config, MRB_ARGS_REQ(1));
}