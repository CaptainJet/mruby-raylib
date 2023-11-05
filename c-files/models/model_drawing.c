//-------
// Model Drawing Functions
//-------

// DrawModel
mrb_value mrb_draw_model(mrb_state *mrb, mrb_value self)
{
    Model *model;
    Vector3 *position;
    mrb_float scale;
    Color *tint;
    mrb_get_args(mrb, "ddfd", &model, &Raylib_Model_type, &position, &Raylib_Vector3_type, &scale, &tint, &Raylib_Color_type);
    DrawModel(*model, *position, scale, *tint);
    return mrb_nil_value();
}

// DrawModelEx
mrb_value mrb_draw_model_ex(mrb_state *mrb, mrb_value self)
{
    Model *model;
    Vector3 *position;
    Vector3 *rotation_axis;
    mrb_float rotation_angle;
    Vector3 *scale;
    Color *tint;
    mrb_get_args(mrb, "dddfdd", &model, &Raylib_Model_type, &position, &Raylib_Vector3_type, &rotation_axis, &Raylib_Vector3_type, &rotation_angle, &scale, &Raylib_Vector3_type, &tint, &Raylib_Color_type);
    DrawModelEx(*model, *position, *rotation_axis, rotation_angle, *scale, *tint);
    return mrb_nil_value();
}

// DrawModelWires
mrb_value mrb_draw_model_wires(mrb_state *mrb, mrb_value self)
{
    Model *model;
    Vector3 *position;
    mrb_float scale;
    Color *tint;
    mrb_get_args(mrb, "ddfd", &model, &Raylib_Model_type, &position, &Raylib_Vector3_type, &scale, &tint, &Raylib_Color_type);
    DrawModelWires(*model, *position, scale, *tint);
    return mrb_nil_value();
}

// DrawModelWiresEx
mrb_value mrb_draw_model_wires_ex(mrb_state *mrb, mrb_value self)
{
    Model *model;
    Vector3 *position;
    Vector3 *rotation_axis;
    mrb_float rotation_angle;
    Vector3 *scale;
    Color *tint;
    mrb_get_args(mrb, "dddfdd", &model, &Raylib_Model_type, &position, &Raylib_Vector3_type, &rotation_axis, &Raylib_Vector3_type, &rotation_angle, &scale, &Raylib_Vector3_type, &tint, &Raylib_Color_type);
    DrawModelWiresEx(*model, *position, *rotation_axis, rotation_angle, *scale, *tint);
    return mrb_nil_value();
}

// DrawBoundingBox
mrb_value mrb_draw_bounding_box(mrb_state *mrb, mrb_value self)
{
    BoundingBox *box;
    Color *color;
    mrb_get_args(mrb, "dd", &box, &Raylib_BoundingBox_type, &color, &Raylib_Color_type);
    DrawBoundingBox(*box, *color);
    return mrb_nil_value();
}

// DrawBillboard
mrb_value mrb_draw_billboard(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    Texture2D *texture;
    Vector3 *position;
    mrb_float size;
    Color *tint;
    mrb_get_args(mrb, "dddfd", &camera, &Raylib_Camera_type, &texture, &Raylib_Texture_type, &position, &Raylib_Vector3_type, &size, &tint, &Raylib_Color_type);
    DrawBillboard(*camera, *texture, *position, size, *tint);
    return mrb_nil_value();
}

// DrawBillboardRec
mrb_value mrb_draw_billboard_rec(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    Texture2D *texture;
    Rectangle *source;
    Vector3 *position;
    Vector2 *size;
    Color *tint;
    mrb_get_args(mrb, "dddddd", &camera, &Raylib_Camera_type, &texture, &Raylib_Texture_type, &source, &Raylib_Rectangle_type, &position, &Raylib_Vector3_type, &size, &Raylib_Vector2_type, &tint, &Raylib_Color_type);
    DrawBillboardRec(*camera, *texture, *source, *position, *size, *tint);
    return mrb_nil_value();
}

// DrawBillboardPro
mrb_value mrb_draw_billboard_pro(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    Texture2D *texture;
    Rectangle *source;
    Vector3 *position;
    Vector3 *up;
    Vector2 *size;
    Vector2 *origin;
    mrb_float rotation;
    Color *tint;
    mrb_get_args(mrb, "dddddddfd", &camera, &Raylib_Camera_type, &texture, &Raylib_Texture_type, &source, &Raylib_Rectangle_type, &position, &Raylib_Vector3_type,
                 &up, &Raylib_Vector3_type, &size, &Raylib_Vector2_type, &origin, &Raylib_Vector2_type, &rotation, &tint, &Raylib_Color_type);
    DrawBillboardPro(*camera, *texture, *source, *position, *up, *size, *origin, rotation, *tint);
    return mrb_nil_value();
}

void mrb_raylib_setup_model_drawing(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "draw_model", mrb_draw_model, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_model_ex", mrb_draw_model_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_model_wires", mrb_draw_model_wires, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_model_wires_ex", mrb_draw_model_wires_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_bounding_box", mrb_draw_bounding_box, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_billboard", mrb_draw_billboard, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_billboard_rec", mrb_draw_billboard_rec, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_billboard_pro", mrb_draw_billboard_pro, MRB_ARGS_REQ(9));
}