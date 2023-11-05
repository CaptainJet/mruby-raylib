//-------
// Audio Device Management Functions
//-------

// InitAudioDevice
mrb_value mrb_init_audio_device(mrb_state *mrb, mrb_value self)
{
    InitAudioDevice();
    return mrb_nil_value();
}

// CloseAudioDevice
mrb_value mrb_close_audio_device(mrb_state *mrb, mrb_value self)
{
    CloseAudioDevice();
    return mrb_nil_value();
}

// IsAudioDeviceReady
mrb_value mrb_is_audio_device_ready(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsAudioDeviceReady());
}

// SetMasterVolume
mrb_value mrb_set_master_volume(mrb_state *mrb, mrb_value self)
{
    mrb_float volume;
    mrb_get_args(mrb, "f", &volume);
    SetMasterVolume(volume);
    return mrb_nil_value();
}

// GetMasterVolume
mrb_value mrb_get_master_volume(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetMasterVolume());
}

void mrb_raylib_setup_audio_device_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "init_audio_device", mrb_init_audio_device, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "close_audio_device", mrb_close_audio_device, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_audio_device_ready?", mrb_is_audio_device_ready, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_master_volume", mrb_set_master_volume, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_master_volume", mrb_get_master_volume, MRB_ARGS_NONE());
}