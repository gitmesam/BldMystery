
extern "C" {

typedef struct
{
    char params[4];
} Params4;

typedef struct
{
    char params[8];
} Params8;

typedef struct
{
    char params[12];
} Params12;

typedef struct
{
    char params[16];
} Params16;

typedef struct
{
    char params[20];
} Params20;

typedef struct
{
    char params[24];
} Params24;

typedef struct
{
    char params[28];
} Params28;

__declspec(dllexport) void __stdcall AIL_3D_speaker_type(Params4 params);
__declspec(dllexport) void __stdcall AIL_close_3D_provider(Params4 params);
__declspec(dllexport) void __stdcall AIL_close_3D_listener(Params4 params);
__declspec(dllexport) void __stdcall AIL_quick_shutdown();
__declspec(dllexport) void __stdcall AIL_quick_startup(Params20 params);
__declspec(dllexport) void __stdcall AIL_open_3D_provider(Params4 params);
__declspec(dllexport) void __stdcall AIL_digital_master_volume(Params4 params);
__declspec(dllexport) void __stdcall AIL_quick_handles(Params12 params);
__declspec(dllexport) void __stdcall AIL_allocate_3D_sample_handle(Params4 params);
__declspec(dllexport) void __stdcall AIL_allocate_sample_handle(Params4 params);
__declspec(dllexport) void __stdcall AIL_open_3D_listener(Params4 params);
__declspec(dllexport) void __stdcall AIL_3D_room_type(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_preference(Params8 params);
__declspec(dllexport) void __stdcall AIL_get_preference(Params4 params);
__declspec(dllexport) void __stdcall AIL_last_error();
__declspec(dllexport) void __stdcall AIL_shutdown();
__declspec(dllexport) void __stdcall AIL_set_redist_directory(Params4 params);
__declspec(dllexport) void __stdcall AIL_startup();
__declspec(dllexport) void __stdcall AIL_enumerate_3D_providers(Params12 params);
__declspec(dllexport) void __stdcall AIL_end_3D_sample(Params4 params);
__declspec(dllexport) void __stdcall AIL_3D_sample_status(Params4 params);
__declspec(dllexport) void __stdcall AIL_open_stream(Params12 params);
__declspec(dllexport) void __stdcall AIL_set_stream_volume(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_stream_loop_count(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_stream_playback_rate(Params8 params);
__declspec(dllexport) void __stdcall AIL_stream_playback_rate(Params4 params);
__declspec(dllexport) void __stdcall AIL_stream_info(Params20 params);
__declspec(dllexport) void __stdcall AIL_start_stream(Params4 params);
__declspec(dllexport) void __stdcall AIL_pause_stream(Params8 params);
__declspec(dllexport) void __stdcall AIL_close_stream(Params4 params);
__declspec(dllexport) void __stdcall AIL_stream_position(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_stream_position(Params8 params);
__declspec(dllexport) void __stdcall AIL_stream_status(Params4 params);
__declspec(dllexport) void __stdcall AIL_start_sample(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_3D_speaker_type(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_3D_provider_preference(Params12 params);
__declspec(dllexport) void __stdcall AIL_set_3D_sample_effects_level(Params8 params);
__declspec(dllexport) void __stdcall AIL_start_3D_sample(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_3D_sample_loop_count(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_3D_sample_file(Params8 params);
__declspec(dllexport) void __stdcall AIL_3D_sample_loop_count(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_sample_volume(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_3D_sample_volume(Params8 params);
__declspec(dllexport) void __stdcall AIL_stop_sample(Params4 params);
__declspec(dllexport) void __stdcall AIL_resume_3D_sample(Params4 params);
__declspec(dllexport) void __stdcall AIL_stop_3D_sample(Params4 params);
__declspec(dllexport) void __stdcall AIL_sample_playback_rate(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_sample_playback_rate(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_sample_reverb(Params16 params);
__declspec(dllexport) void __stdcall AIL_set_3D_velocity_vector(Params16 params);
__declspec(dllexport) void __stdcall AIL_set_3D_sample_cone(Params16 params);
__declspec(dllexport) void __stdcall AIL_set_3D_sample_playback_rate(Params8 params);
__declspec(dllexport) void __stdcall AIL_3D_sample_playback_rate(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_3D_sample_distances(Params12 params);
__declspec(dllexport) void __stdcall AIL_redbook_open_drive(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_open(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_play(Params12 params);
__declspec(dllexport) void __stdcall AIL_redbook_track_info(Params16 params);
__declspec(dllexport) void __stdcall AIL_redbook_tracks(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_position(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_volume(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_set_volume(Params8 params);
__declspec(dllexport) void __stdcall AIL_redbook_status(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_pause(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_resume(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_stop(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_close(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_eject(Params4 params);
__declspec(dllexport) void __stdcall AIL_redbook_retract(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_digital_master_volume(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_3D_room_type(Params8 params);
__declspec(dllexport) void __stdcall AIL_decompress_ASI(Params24 params);
__declspec(dllexport) void __stdcall AIL_mem_free_lock(Params4 params);
__declspec(dllexport) void __stdcall AIL_decompress_ADPCM(Params12 params);
__declspec(dllexport) void __stdcall AIL_WAV_info(Params8 params);
__declspec(dllexport) void __stdcall AIL_file_type(Params8 params);
__declspec(dllexport) void __stdcall AIL_file_read(Params8 params);
__declspec(dllexport) void __stdcall AIL_file_size(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_3D_orientation(Params28 params);
__declspec(dllexport) void __stdcall AIL_set_3D_position(Params16 params);
__declspec(dllexport) void __stdcall AIL_end_sample(Params4 params);
__declspec(dllexport) void __stdcall AIL_sample_status(Params4 params);
__declspec(dllexport) void __stdcall AIL_set_sample_loop_count(Params8 params);
__declspec(dllexport) void __stdcall AIL_set_sample_file(Params12 params);
__declspec(dllexport) void __stdcall AIL_redbook_track(Params4 params);
__declspec(dllexport) void __stdcall AIL_resume_sample(Params4 params);

}/* extern "C" */

void __stdcall AIL_3D_speaker_type(Params4 params)
{
}

void __stdcall AIL_close_3D_provider(Params4 params)
{
}

void __stdcall AIL_close_3D_listener(Params4 params)
{
}

void __stdcall AIL_quick_shutdown()
{
}

void __stdcall AIL_quick_startup(Params20 params)
{
}

void __stdcall AIL_open_3D_provider(Params4 params)
{
}

void __stdcall AIL_digital_master_volume(Params4 params)
{
}

void __stdcall AIL_quick_handles(Params12 params)
{
}

void __stdcall AIL_allocate_3D_sample_handle(Params4 params)
{
}

void __stdcall AIL_allocate_sample_handle(Params4 params)
{
}

void __stdcall AIL_open_3D_listener(Params4 params)
{
}

void __stdcall AIL_3D_room_type(Params4 params)
{
}

void __stdcall AIL_set_preference(Params8 params)
{
}

void __stdcall AIL_get_preference(Params4 params)
{
}

void __stdcall AIL_last_error()
{
}

void __stdcall AIL_shutdown()
{
}

void __stdcall AIL_set_redist_directory(Params4 params)
{
}

void __stdcall AIL_startup()
{
}

void __stdcall AIL_enumerate_3D_providers(Params12 params)
{
}

void __stdcall AIL_end_3D_sample(Params4 params)
{
}

void __stdcall AIL_3D_sample_status(Params4 params)
{
}

void __stdcall AIL_open_stream(Params12 params)
{
}

void __stdcall AIL_set_stream_volume(Params8 params)
{
}

void __stdcall AIL_set_stream_loop_count(Params8 params)
{
}

void __stdcall AIL_set_stream_playback_rate(Params8 params)
{
}

void __stdcall AIL_stream_playback_rate(Params4 params)
{
}

void __stdcall AIL_stream_info(Params20 params)
{
}

void __stdcall AIL_start_stream(Params4 params)
{
}

void __stdcall AIL_pause_stream(Params8 params)
{
}

void __stdcall AIL_close_stream(Params4 params)
{
}

void __stdcall AIL_stream_position(Params4 params)
{
}

void __stdcall AIL_set_stream_position(Params8 params)
{
}

void __stdcall AIL_stream_status(Params4 params)
{
}

void __stdcall AIL_start_sample(Params4 params)
{
}

void __stdcall AIL_set_3D_speaker_type(Params8 params)
{
}

void __stdcall AIL_set_3D_provider_preference(Params12 params)
{
}

void __stdcall AIL_set_3D_sample_effects_level(Params8 params)
{
}

void __stdcall AIL_start_3D_sample(Params4 params)
{
}

void __stdcall AIL_set_3D_sample_loop_count(Params8 params)
{
}

void __stdcall AIL_set_3D_sample_file(Params8 params)
{
}

void __stdcall AIL_3D_sample_loop_count(Params4 params)
{
}

void __stdcall AIL_set_sample_volume(Params8 params)
{
}

void __stdcall AIL_set_3D_sample_volume(Params8 params)
{
}

void __stdcall AIL_stop_sample(Params4 params)
{
}

void __stdcall AIL_resume_3D_sample(Params4 params)
{
}

void __stdcall AIL_stop_3D_sample(Params4 params)
{
}

void __stdcall AIL_sample_playback_rate(Params4 params)
{
}

void __stdcall AIL_set_sample_playback_rate(Params8 params)
{
}

void __stdcall AIL_set_sample_reverb(Params16 params)
{
}

void __stdcall AIL_set_3D_velocity_vector(Params16 params)
{
}

void __stdcall AIL_set_3D_sample_cone(Params16 params)
{
}

void __stdcall AIL_set_3D_sample_playback_rate(Params8 params)
{
}

void __stdcall AIL_3D_sample_playback_rate(Params4 params)
{
}

void __stdcall AIL_set_3D_sample_distances(Params12 params)
{
}

void __stdcall AIL_redbook_open_drive(Params4 params)
{
}

void __stdcall AIL_redbook_open(Params4 params)
{
}

void __stdcall AIL_redbook_play(Params12 params)
{
}

void __stdcall AIL_redbook_track_info(Params16 params)
{
}

void __stdcall AIL_redbook_tracks(Params4 params)
{
}

void __stdcall AIL_redbook_position(Params4 params)
{
}

void __stdcall AIL_redbook_volume(Params4 params)
{
}

void __stdcall AIL_redbook_set_volume(Params8 params)
{
}

void __stdcall AIL_redbook_status(Params4 params)
{
}

void __stdcall AIL_redbook_pause(Params4 params)
{
}

void __stdcall AIL_redbook_resume(Params4 params)
{
}

void __stdcall AIL_redbook_stop(Params4 params)
{
}

void __stdcall AIL_redbook_close(Params4 params)
{
}

void __stdcall AIL_redbook_eject(Params4 params)
{
}

void __stdcall AIL_redbook_retract(Params4 params)
{
}

void __stdcall AIL_set_digital_master_volume(Params8 params)
{
}

void __stdcall AIL_set_3D_room_type(Params8 params)
{
}

void __stdcall AIL_decompress_ASI(Params24 params)
{
}

void __stdcall AIL_mem_free_lock(Params4 params)
{
}

void __stdcall AIL_decompress_ADPCM(Params12 params)
{
}

void __stdcall AIL_WAV_info(Params8 params)
{
}

void __stdcall AIL_file_type(Params8 params)
{
}

void __stdcall AIL_file_read(Params8 params)
{
}

void __stdcall AIL_file_size(Params4 params)
{
}

void __stdcall AIL_set_3D_orientation(Params28 params)
{
}

void __stdcall AIL_set_3D_position(Params16 params)
{
}

void __stdcall AIL_end_sample(Params4 params)
{
}

void __stdcall AIL_sample_status(Params4 params)
{
}

void __stdcall AIL_set_sample_loop_count(Params8 params)
{
}

void __stdcall AIL_set_sample_file(Params12 params)
{
}

void __stdcall AIL_redbook_track(Params4 params)
{
}

void __stdcall AIL_resume_sample(Params4 params)
{
}