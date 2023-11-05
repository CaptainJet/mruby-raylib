//-------
// Touch Functions
//-------

// GetTouchX
mrb_value mrb_get_touch_x(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetTouchX());
}

// GetTouchY
mrb_value mrb_get_touch_y(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetTouchY());
}

// GetTouchPosition
mrb_value mrb_get_touch_position(mrb_state *mrb, mrb_value self)
{
    mrb_int index;
    mrb_get_args(mrb, "i", &index);
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetTouchPosition(index);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetTouchPointId
mrb_value mrb_get_touch_point_id(mrb_state *mrb, mrb_value self)
{
    mrb_int index;
    mrb_get_args(mrb, "i", &index);
    return mrb_int_value(mrb, GetTouchPointId(index));
}

// GetTouchPointCount
mrb_value mrb_get_touch_point_count(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetTouchPointCount());
}

void mrb_raylib_setup_touch(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "get_touch_x", mrb_get_touch_x, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_touch_y", mrb_get_touch_y, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_touch_position", mrb_get_touch_position, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_touch_point_id", mrb_get_touch_point_id, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_touch_point_count", mrb_get_touch_point_count, MRB_ARGS_NONE());
}