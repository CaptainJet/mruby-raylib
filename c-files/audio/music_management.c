//-------
// Music Management Functions
//-------

// LoadMusicStream
mrb_value mrb_load_music_stream(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Music *out = (Music *)malloc(sizeof(Music));
    *out = LoadMusicStream(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Music_class, &Raylib_Music_type, out));

    return obj;
}

// LoadMusicStreamFromMemory
mrb_value mrb_load_music_stream_from_memory(mrb_state *mrb, mrb_value self)
{
    const char *filetype;
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_get_args(mrb, "zzi", &filetype, &filedata, &datasize);
    Music *out = (Music *)malloc(sizeof(Music));
    *out = LoadMusicStreamFromMemory(filetype, filedata, datasize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Music_class, &Raylib_Music_type, out));

    return obj;
}

// IsMusicReady
mrb_value mrb_is_music_ready(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_bool_value(IsMusicReady(*music));
}

// UnloadMusicStream
mrb_value mrb_unload_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    UnloadMusicStream(*music);
    return mrb_nil_value();
}

// UpdateMusicStream
mrb_value mrb_update_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    UpdateMusicStream(*music);
    return mrb_nil_value();
}

// PlayMusicStream
mrb_value mrb_play_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    PlayMusicStream(*music);
    return mrb_nil_value();
}

// IsMusicStreamPlaying
mrb_value mrb_is_music_stream_playing(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_bool_value(IsMusicStreamPlaying(*music));
}

// StopMusicStream
mrb_value mrb_stop_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    StopMusicStream(*music);
    return mrb_nil_value();
}

// PauseMusicStream
mrb_value mrb_pause_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    PauseMusicStream(*music);
    return mrb_nil_value();
}

// ResumeMusicStream
mrb_value mrb_resume_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    ResumeMusicStream(*music);
    return mrb_nil_value();
}

// SeekMusicStream
mrb_value mrb_seek_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float position;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &position);
    SeekMusicStream(*music, position);
    return mrb_nil_value();
}

// SetMusicVolume
mrb_value mrb_set_music_volume(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float volume;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &volume);
    SetMusicVolume(*music, volume);
    return mrb_nil_value();
}

// SetMusicPitch
mrb_value mrb_set_music_pitch(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float pitch;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &pitch);
    SetMusicPitch(*music, pitch);
    return mrb_nil_value();
}

// SetMusicPan
mrb_value mrb_set_music_pan(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float pan;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &pan);
    SetMusicPan(*music, pan);
    return mrb_nil_value();
}

// GetMusicTimeLength
mrb_value mrb_get_music_time_length(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_float_value(mrb, GetMusicTimeLength(*music));
}

// GetMusicTimePlayed
mrb_value mrb_get_music_time_played(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_float_value(mrb, GetMusicTimePlayed(*music));
}

void mrb_raylib_setup_music_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_music_stream", mrb_load_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_music_stream_from_memory", mrb_load_music_stream_from_memory, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "is_music_ready?", mrb_is_music_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_music_stream", mrb_unload_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "play_music_stream", mrb_play_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_music_stream_playing?", mrb_is_music_stream_playing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "update_music_stream", mrb_update_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "stop_music_stream", mrb_stop_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "pause_music_stream", mrb_pause_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "resume_music_stream", mrb_resume_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "seek_music_stream", mrb_seek_music_stream, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_music_volume", mrb_set_music_volume, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_music_pitch", mrb_set_music_pitch, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_music_pan", mrb_set_music_pan, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_music_time_length", mrb_get_music_time_length, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_music_time_played", mrb_get_music_time_played, MRB_ARGS_REQ(1));
}