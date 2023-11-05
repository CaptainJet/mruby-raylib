//-------
// Gesture Functions
//-------

// SetGesturesEnabled
mrb_value mrb_set_gestures_enabled(mrb_state *mrb, mrb_value self)
{
    mrb_int flags;
    mrb_get_args(mrb, "i", &flags);
    SetGesturesEnabled(flags);
    return mrb_nil_value();
}

// IsGestureDetected
mrb_value mrb_is_gesture_detected(mrb_state *mrb, mrb_value self)
{
    mrb_int gesture;
    mrb_get_args(mrb, "i", &gesture);
    return mrb_bool_value(IsGestureDetected(gesture));
}

// GetGestureDetected
mrb_value mrb_get_gesture_detected(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetGestureDetected());
}

// GetGestureHoldDuration
mrb_value mrb_get_gesture_hold_duration(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetGestureHoldDuration());
}

// GetGestureDragVector
mrb_value mrb_get_gesture_drag_vector(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetGestureDragVector();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetGestureHoldAngle
mrb_value mrb_get_gesture_drag_angle(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetGestureDragAngle());
}

// GetGesturePinchVector
mrb_value mrb_get_gesture_pinch_vector(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetGesturePinchVector();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetGesturePinchAngle
mrb_value mrb_get_gesture_pinch_angle(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetGesturePinchAngle());
}

void mrb_raylib_setup_gestures(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "set_gestures_enabled", mrb_set_gestures_enabled, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_gesture_detected?", mrb_is_gesture_detected, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_gesture_detected", mrb_get_gesture_detected, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_gesture_hold_duration", mrb_get_gesture_hold_duration, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_gesture_drag_vector", mrb_get_gesture_drag_vector, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_gesture_drag_angle", mrb_get_gesture_drag_angle, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_gesture_pinch_vector", mrb_get_gesture_pinch_vector, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_gesture_pinch_angle", mrb_get_gesture_pinch_angle, MRB_ARGS_NONE());
}