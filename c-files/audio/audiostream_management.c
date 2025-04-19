//-------
// AudioStream Management Functions
//-------

// LoadAudioStream
mrb_value mrb_load_audio_stream(mrb_state *mrb, mrb_value self)
{
    mrb_int samplerate;
    mrb_int samplesize;
    mrb_int channels;
    mrb_get_args(mrb, "iii", &samplerate, &samplesize, &channels);
    AudioStream *out = (AudioStream *)malloc(sizeof(AudioStream));
    *out = LoadAudioStream(samplerate, samplesize, channels);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_AudioStream_class, &Raylib_AudioStream_type, out));

    return obj;
}

// IsAudioStreamValid
mrb_value mrb_is_audio_stream_valid(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    return mrb_bool_value(IsAudioStreamValid(*audiostream));
}

// UnloadAudioStream
mrb_value mrb_unload_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    UnloadAudioStream(*audiostream);
    return mrb_nil_value();
}

// IsAudioStreamProcessed
mrb_value mrb_is_audio_stream_processed(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    return mrb_bool_value(IsAudioStreamProcessed(*audiostream));
}

// PlayAudioStream
mrb_value mrb_play_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    PlayAudioStream(*audiostream);
    return mrb_nil_value();
}

// PauseAudioStream
mrb_value mrb_pause_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    PauseAudioStream(*audiostream);
    return mrb_nil_value();
}

// ResumeAudioStream
mrb_value mrb_resume_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    ResumeAudioStream(*audiostream);
    return mrb_nil_value();
}

// IsAudioStreamPlaying
mrb_value mrb_is_audio_stream_playing(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    return mrb_bool_value(IsAudioStreamPlaying(*audiostream));
}

// StopAudioStream
mrb_value mrb_stop_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    StopAudioStream(*audiostream);
    return mrb_nil_value();
}

// SetAudioStreamVolume
mrb_value mrb_set_audio_stream_volume(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_float volume;
    mrb_get_args(mrb, "df", &audiostream, &Raylib_AudioStream_type, &volume);
    SetAudioStreamVolume(*audiostream, volume);
    return mrb_nil_value();
}

// SetAudioStreamPitch
mrb_value mrb_set_audio_stream_pitch(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_float pitch;
    mrb_get_args(mrb, "df", &audiostream, &Raylib_AudioStream_type, &pitch);
    SetAudioStreamPitch(*audiostream, pitch);
    return mrb_nil_value();
}

// SetAudioStreamPan
mrb_value mrb_set_audio_stream_pan(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_float pan;
    mrb_get_args(mrb, "df", &audiostream, &Raylib_AudioStream_type, &pan);
    SetAudioStreamPan(*audiostream, pan);
    return mrb_nil_value();
}

// SetAudioStreamBufferSizeDefault
mrb_value mrb_set_audio_stream_buffer_size_default(mrb_state *mrb, mrb_value self)
{
    mrb_int size;
    mrb_get_args(mrb, "i", &size);
    SetAudioStreamBufferSizeDefault(size);
    return mrb_nil_value();
}

void mrb_raylib_setup_audiostream_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_audio_stream", mrb_load_audio_stream, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "is_audio_stream_valid?", mrb_is_audio_stream_valid, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_audio_stream", mrb_unload_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_audio_stream_processed?", mrb_is_audio_stream_processed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "play_audio_stream", mrb_play_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "pause_audio_stream", mrb_pause_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "resume_audio_stream", mrb_resume_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_audio_stream_playing?", mrb_is_audio_stream_playing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "stop_audio_stream", mrb_stop_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_volume", mrb_set_audio_stream_volume, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_pitch", mrb_set_audio_stream_pitch, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_pan", mrb_set_audio_stream_pan, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_buffer_size_default", mrb_set_audio_stream_buffer_size_default, MRB_ARGS_REQ(2));
}