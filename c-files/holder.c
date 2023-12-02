//
// Created by robro on 6/4/2022.
//

#include "structs.c"

#include "audio/audio_device_management.c"
#include "audio/wave_loading.c"
#include "audio/wave_management.c"
#include "audio/music_management.c"
#include "audio/audiostream_management.c"

#include "core/automation_event.c"
#include "core/compression.c"
#include "core/cursor.c"
#include "core/drawing.c"
#include "core/file_management.c"
#include "core/frame_control.c"
#include "core/misc.c"
#include "core/screen_space.c"
#include "core/shader.c"
#include "core/timing.c"
#include "core/vr.c"
#include "core/window.c"

#include "models/geometric_shapes.c"
#include "models/model_management.c"
#include "models/model_drawing.c"
#include "models/mesh_management.c"
#include "models/mesh_generation.c"
#include "models/material_loading.c"
#include "models/model_animation_loading.c"
#include "models/collision_detection.c"

#include "drawing/shapes.c"
#include "drawing/image.c"
#include "drawing/texture.c"
#include "drawing/color.c"

#include "text/font_loading.c"
#include "text/text_drawing.c"
#include "text/text_font_info.c"
#include "text/text_codepoints_management.c"

#include "input/camera.c"
#include "input/gamepad.c"
#include "input/gestures.c"
#include "input/keyboard.c"
#include "input/mouse.c"
#include "input/touch.c"

#include "raygui/raygui.c"