MRuby::Gem::Specification.new("mruby_raylib") do |spec|
  spec.license = "MIT"
  spec.author = "mruby developers"

  spec.cc.include_paths << "#{dir}/include"
  if for_windows?
    spec.linker.library_paths << "#{dir}/deps/windows"
    spec.linker.libraries << %w[raylib opengl32 gdi32 winmm pthread]
  elsif cc.command == "emcc" || cc.command == "em++"
    spec.linker.flags << "-s USE_GLFW=3 -s FORCE_FILESYSTEM=1"
    spec.linker.library_paths << "#{dir}/deps/webassembly"
    spec.linker.libraries << %w[raylib]
  elsif (android = cc.flags.find { |a| a.include?("linux-android") })
    case android
    when /armv7a/
      spec.linker.library_paths << "#{dir}/deps/android/armv7a"
    when /aarch64/
      spec.linker.library_paths << "#{dir}/deps/android/aarch64"
    when /x86_64/
      spec.linker.library_paths << "#{dir}/deps/android/x86_64"
    when /i686/
      spec.linker.library_paths << "#{dir}/deps/android/i686"
    end
    spec.linker.libraries << %w[raylib log android EGL GLESv2 OpenSLES m c]
  else
    spec.linker.library_paths << "#{dir}/deps/linux"
    spec.linker.libraries << %w[raylib GL m pthread dl rt X11]
  end
end
