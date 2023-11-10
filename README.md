## mruby-raylib
Another mruby binding to raylib. This gem takes a barebones approach at the moment.
Functions are bound to snake_case. Raylib build for Windows, Linux, WebAssembly, and Android included.

```Ruby
conf.gem :github => 'captainjet/mruby-raylib', :branch => 'main'
```

## Usage

```Ruby
Raylib.init_window(800, 600, "raylib [core] example - basic window")
Raylib.set_target_fps(60)
until Raylib.window_should_close?    # Detect window close button or ESC key
  Raylib.begin_drawing
  Raylib.clear_background(Raylib::RAYWHITE)
  Raylib.draw_text("Congrats! You created your first window!", 190, 200, 20, Raylib::LIGHTGRAY)
  Raylib.end_drawing
end
Raylib.close_window
```

Enum values of the libary are stored as module constants of the same name.
So MOUSE_LEFT_BUTTON is found as Raylib::MouseButton::MOUSE_LEFT_BUTTON.
You can include all of these modules with a convenience method.

```Ruby
module Raylib
self.include_enums
end
```

After that, you should be able to just use Raylib::MOUSE_LEFT_BUTTON.

Also includes a module Raylib::Colors that includes a pre-built color for every color [here](https://www.w3.org/wiki/CSS/Properties/color/keywords).

## Structure

All the files are located in the c-files directory. I just run single_file.rb to combine structs.c and all the *.c files, besides holder.c, into one file placed in src/mruby_raylib.c
Enums are read from the raylib_api.json file and recreated in mruby_raylib.rb by the read_json.rb

It's not great. But it works for me, and I understand it. If you'd like to help, please edit files inside c-files, not the single file in src.

## Raylib Binaries

There's a pre-built raylib included for various platforms. They were built with all options in config.h enabled, besides the following:
```
SUPPORT_TRACELOG_DEBUG
RLGL_SHOW_GL_DETAILS_INFO
RLGL_ENABLE_OPENGL_DEBUG_CONTEXT
SUPPORT_CUSTOM_FRAME_CONTROL
SUPPORT_BUSY_WAIT_LOOP
```

and compiled with the following commands on Arch Linux:

```Ruby
make # Linux
emmake make PLATFORM=PLATFORM_WEB # WebAssembly
make CC=x86_64-w64-mingw32-gcc PLATFORM=PLATFORM_DESKTOP PLATFORM_OS=WINDOWS # Windows
make PLATFORM=PLATFORM_ANDROID ANDROID_API_VERSION=33 ANDROID_NDK=/opt/android-sdk/ndk/26.0.10792818 ANDROID_ARCH=arm64 # Android aarch64
make PLATFORM=PLATFORM_ANDROID ANDROID_API_VERSION=33 ANDROID_NDK=/opt/android-sdk/ndk/26.0.10792818 ANDROID_ARCH=arm # Android armv7a
make PLATFORM=PLATFORM_ANDROID ANDROID_API_VERSION=33 ANDROID_NDK=/opt/android-sdk/ndk/26.0.10792818 ANDROID_ARCH=x86_64 # Android X86_64
make PLATFORM=PLATFORM_ANDROID ANDROID_API_VERSION=33 ANDROID_NDK=/opt/android-sdk/ndk/26.0.10792818 ANDROID_ARCH=x86 # Android i686
```

## Notes

The Following Raylib methods are currently not bound:

```
WILL NOT IMPLENT
----------------
TextCopy
TextIsEqual
TextLength
TextFormat
TextSubtext
TextReplace
TextInsert
TextJoin
TextSplit
TextAppend
TextFindIndex
TextToUpper
TextToLower
TextToPascal
TextToInteger
MemAlloc
MemRealloc
MemFree
GetWindowHandle
SetTraceLogCallback
SetLoadFileDataCallback
SetSaveFileDataCallback
SetLoadFileTextCallback
SetAudioStreamCallback
AttachAudioStreamProcessor
DetachAudioStreamProcessor
AttachAudioMixedProcessor
DetachAudioMixedProcessor

NEED HELP IMPLEMENTING
----------------
SetShaderValue
SetShaderValueV
SaveFileData
UpdateTexture
UpdateTextureRec
GetPixelColor
SetPixelColor
UpdateMeshBuffer
UpdateSound
UpdateAudioStream
```

The following do not perform a function, but are bound, as the GC will handle cleanup:
```
UnloadCodepoints
UnloadWaveSamples
UnloadRandomSequence
```

The following structs can be passed around as references, but you cannot manually read or write attributes of them:
```
Mesh
Shader
MaterialMap
Material
Model
Transform
BoneInfo
ModelAnimation
Wave
Sound
Music
AudioStream
VrDeviceInfo
VrStereoConfig
```

## License

MIT