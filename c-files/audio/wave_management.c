//-------
// Wave Management Functions
//-------

// PlaySound
mrb_value mrb_play_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    PlaySound(*sound);
    return mrb_nil_value();
}

// StopSound
mrb_value mrb_stop_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    StopSound(*sound);
    return mrb_nil_value();
}

// PauseSound
mrb_value mrb_pause_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    PauseSound(*sound);
    return mrb_nil_value();
}

// ResumeSound
mrb_value mrb_resume_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    ResumeSound(*sound);
    return mrb_nil_value();
}

// IsSoundPlaying
mrb_value mrb_is_sound_playing(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    return mrb_bool_value(IsSoundPlaying(*sound));
}

// SetSoundVolume
mrb_value mrb_set_sound_volume(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_float volume;
    mrb_get_args(mrb, "df", &sound, &Raylib_Sound_type, &volume);
    SetSoundVolume(*sound, volume);
    return mrb_nil_value();
}

// SetSoundPitch
mrb_value mrb_set_sound_pitch(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_float pitch;
    mrb_get_args(mrb, "df", &sound, &Raylib_Sound_type, &pitch);
    SetSoundPitch(*sound, pitch);
    return mrb_nil_value();
}

// SetSoundPan
mrb_value mrb_set_sound_pan(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_float pan;
    mrb_get_args(mrb, "df", &sound, &Raylib_Sound_type, &pan);
    SetSoundPan(*sound, pan);
    return mrb_nil_value();
}

// WaveCopy
mrb_value mrb_wave_copy(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    Wave *out = (Wave *)malloc(sizeof(Wave));
    *out = WaveCopy(*wave);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Wave_class, &Raylib_Wave_type, out));

    return obj;
}

// WaveCrop
mrb_value mrb_wave_crop(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_int initsample;
    mrb_int finalsample;
    mrb_get_args(mrb, "dii", &wave, &Raylib_Wave_type, &initsample, &finalsample);
    WaveCrop(wave, initsample, finalsample);
    return mrb_nil_value();
}

// WaveFormat
mrb_value mrb_wave_format(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_int samplerate;
    mrb_int samplesize;
    mrb_int channels;
    mrb_get_args(mrb, "diii", &wave, &Raylib_Wave_type, &samplerate, &samplesize, &channels);
    WaveFormat(wave, samplerate, samplesize, channels);
    return mrb_nil_value();
}

// LoadWaveSamples
mrb_value mrb_load_wave_samples(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    float *values = LoadWaveSamples(*wave);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < (sizeof(*values) / sizeof(values[0])); ++i)
    {
        mrb_ary_push(mrb, ary, mrb_float_value(mrb, values[i]));
    }
    UnloadWaveSamples(values);
    return ary;
}

// UnloadWaveSamples
mrb_value mrb_unload_wave_samples(mrb_state *mrb, mrb_value self)
{
    // mrb_value samples;
    // mrb_get_args(mrb, "A", &samples);
    // float *values[RARRAY_LEN(samples)];
    // for (int i = 0; i < RARRAY_LEN(samples); ++i)
    //{
    //     values[i] = (float *)DATA_PTR(mrb_ary_entry(samples, i));
    // }
    // UnloadWaveSamples(values);
    return mrb_nil_value();
}

void mrb_raylib_setup_wave_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "play_sound", mrb_play_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "stop_sound", mrb_stop_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "pause_sound", mrb_pause_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "resume_sound", mrb_resume_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_sound_playing?", mrb_is_sound_playing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_sound_volume", mrb_set_sound_volume, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_sound_pitch", mrb_set_sound_pitch, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_sound_pan", mrb_set_sound_pan, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "wave_copy", mrb_wave_copy, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "wave_crop", mrb_wave_crop, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "wave_format", mrb_wave_format, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "load_wave_samples", mrb_load_wave_samples, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_wave_samples", mrb_unload_wave_samples, MRB_ARGS_REQ(1));
}