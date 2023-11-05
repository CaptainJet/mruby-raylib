//-------
// Wave Loading Functions
//-------

// LoadWave
mrb_value mrb_load_wave(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Wave *out = (Wave *)malloc(sizeof(Wave));
    *out = LoadWave(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Wave_class, &Raylib_Wave_type, out));

    return obj;
}

// LoadWaveFromMemory
mrb_value mrb_load_wave_from_memory(mrb_state *mrb, mrb_value self)
{
    const char *filetype;
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_get_args(mrb, "zzi", &filetype, &filedata, &datasize);
    Wave *out = (Wave *)malloc(sizeof(Wave));
    *out = LoadWaveFromMemory(filetype, filedata, datasize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Wave_class, &Raylib_Wave_type, out));

    return obj;
}

// LoadSound
mrb_value mrb_load_sound(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Sound *out = (Sound *)malloc(sizeof(Sound));
    *out = LoadSound(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Sound_class, &Raylib_Sound_type, out));

    return obj;
}

// LoadSoundFromWave
mrb_value mrb_load_sound_from_wave(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    Sound *out = (Sound *)malloc(sizeof(Sound));
    *out = LoadSoundFromWave(*wave);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Sound_class, &Raylib_Sound_type, out));

    return obj;
}

// LoadSoundAlias
mrb_value mrb_load_sound_alias(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    Sound *out = (Sound *)malloc(sizeof(Sound));
    *out = LoadSoundAlias(*sound);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Sound_class, &Raylib_Sound_type, out));

    return obj;
}

// IsSoundReady
mrb_value mrb_is_sound_ready(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    return mrb_bool_value(IsSoundReady(*sound));
}

// IsWaveReady
mrb_value mrb_is_wave_ready(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    return mrb_bool_value(IsWaveReady(*wave));
}

// UnloadWave
mrb_value mrb_unload_wave(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    UnloadWave(*wave);
    return mrb_nil_value();
}

// UnloadSound
mrb_value mrb_unload_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    UnloadSound(*sound);
    return mrb_nil_value();
}

// UnloadSoundAlias
mrb_value mrb_unload_sound_alias(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    UnloadSoundAlias(*sound);
    return mrb_nil_value();
}

// ExportWave
mrb_value mrb_export_wave(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    const char *filename;
    mrb_get_args(mrb, "dz", &wave, &Raylib_Wave_type, &filename);
    return mrb_bool_value(ExportWave(*wave, filename));
}

// ExportWaveAsCode
mrb_value mrb_export_wave_as_code(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    const char *filename;
    mrb_get_args(mrb, "dz", &wave, &Raylib_Wave_type, &filename);
    return mrb_bool_value(ExportWaveAsCode(*wave, filename));
}

void mrb_raylib_setup_wave_loading(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_wave", mrb_load_wave, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_wave_from_memory", mrb_load_wave_from_memory, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_sound", mrb_load_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_sound_from_wave", mrb_load_sound_from_wave, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_sound_alias", mrb_load_sound_alias, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_sound_ready?", mrb_is_sound_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_wave_ready?", mrb_is_wave_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_sound", mrb_unload_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_sound_alias", mrb_unload_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_wave", mrb_unload_wave, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_wave", mrb_export_wave, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "export_wave_as_code", mrb_export_wave_as_code, MRB_ARGS_REQ(2));
}