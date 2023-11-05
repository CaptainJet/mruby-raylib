//-------
// Model Animation Loading Functions
//-------

// LoadModelAnimations
mrb_value mrb_load_model_animations(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int animcount;
    mrb_get_args(mrb, "zi", &filename, &animcount);
    ModelAnimation *animations = LoadModelAnimations(filename, (int *)animcount);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < animcount; ++i)
    {
        ModelAnimation *animation = (ModelAnimation *)malloc(sizeof(ModelAnimation));
        *animation = animations[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_ModelAnimation_class, &Raylib_ModelAnimation_type, animation)));
    }
    return ary;
}

// UpdateModelAnimation
mrb_value mrb_update_model_animation(mrb_state *mrb, mrb_value self)
{
    Model *model;
    ModelAnimation *anim;
    mrb_int frame;
    mrb_get_args(mrb, "ddi", &model, &Raylib_Model_type, &anim, &Raylib_ModelAnimation_type, &frame);
    UpdateModelAnimation(*model, *anim, frame);
    return mrb_nil_value();
}

// UnloadModelAnimation
mrb_value mrb_unload_model_animation(mrb_state *mrb, mrb_value self)
{
    ModelAnimation *anim;
    mrb_get_args(mrb, "d", &anim, &Raylib_ModelAnimation_type);
    UnloadModelAnimation(*anim);
    return mrb_nil_value();
}

// UnloadModelAnimations
mrb_value mrb_unload_model_animations(mrb_state *mrb, mrb_value self)
{
    mrb_value animations;
    mrb_int count;
    mrb_get_args(mrb, "Ai", &animations, &count);
    ModelAnimation out_anims[count];
    for (int i = 0; i < count; ++i)
    {
        out_anims[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(animations, i), &Raylib_ModelAnimation_type, ModelAnimation);
    }
    UnloadModelAnimations(out_anims, count);
    return mrb_nil_value();
}

// IsModelAnimationValid
mrb_value mrb_is_model_animation_valid(mrb_state *mrb, mrb_value self)
{
    Model *model;
    ModelAnimation *anim;
    mrb_get_args(mrb, "dd", &model, &Raylib_Model_type, &anim, &Raylib_ModelAnimation_type);
    return mrb_bool_value(IsModelAnimationValid(*model, *anim));
}

void mrb_raylib_setup_model_animation_loading(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_model_animations", mrb_load_model_animations, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "update_model_animation", mrb_update_model_animation, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "unload_model_animation", mrb_unload_model_animation, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_model_animations", mrb_unload_model_animations, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_model_animation_valid?", mrb_is_model_animation_valid, MRB_ARGS_REQ(2));
}