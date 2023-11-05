SETUP = "
void mrb_mruby_raylib_gem_init(mrb_state* mrb) {
    struct RClass *Raylib_Raylib_module;
    Raylib_Raylib_module = mrb_define_module(mrb, \"Raylib\");
%s
}

void mrb_mruby_raylib_gem_final(mrb_state* mrb) {
    /* finalizer */
}".freeze

str = ""
setups = []
Dir["**/*.c"].each do |a|
  setups << File.basename(a, ".c") unless a.include?("mruby_raylib.c")
  if a.include?("structs.c")
    str.prepend(File.read(a), "\n\n")
    next
  elsif a.include?("mruby_raylib.c") || a.include?("holder.c")
    next
  end
  str << File.read(a) << "\n\n"
end
setups_str = ""
setups.each do |a|
  setups_str << "    mrb_raylib_setup_#{a}(mrb, Raylib_Raylib_module);\n" unless a == "holder"
end
str << format(SETUP, setups_str)
File.write("../src/mruby_raylib.c", str)
