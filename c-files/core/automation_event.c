//-------
// Automation Event Functions
//-------

// LoadAutomationEventList
mrb_value mrb_load_automation_event_list(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z!", &filename);

    AutomationEventList *list = (AutomationEventList *)malloc(sizeof(AutomationEventList));
    *list = LoadAutomationEventList(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_AutomationEventList_class, &Raylib_AutomationEventList_type, list));

    return obj;
}

// UnloadAutomationEventList
mrb_value mrb_unload_automation_event_list(mrb_state *mrb, mrb_value self)
{
    AutomationEventList *list;
    mrb_get_args(mrb, "d", &list, &Raylib_AutomationEventList_type);
    UnloadAutomationEventList(list);
    return mrb_nil_value();
}

// ExportAutomationEventList
mrb_value mrb_export_automation_event_list(mrb_state *mrb, mrb_value self)
{
    AutomationEventList *list;
    const char *filename;
    mrb_get_args(mrb, "dz", &list, &Raylib_AutomationEventList_type, &filename);
    return mrb_bool_value(ExportAutomationEventList(*list, filename));
}

// SetAutomationEventList
mrb_value mrb_set_automation_event_list(mrb_state *mrb, mrb_value self)
{
    AutomationEventList *list;
    mrb_get_args(mrb, "d", &list, &Raylib_AutomationEventList_type);
    SetAutomationEventList(list);
    return mrb_nil_value();
}

// SetAutomationEventBaseFrame
mrb_value mrb_set_automation_event_base_frame(mrb_state *mrb, mrb_value self)
{
    mrb_int frame;
    mrb_get_args(mrb, "i", &frame);
    SetAutomationEventBaseFrame(frame);
    return mrb_nil_value();
}

// StartAutomationEventRecording
mrb_value mrb_start_automation_event_recording(mrb_state *mrb, mrb_value self)
{
    StartAutomationEventRecording();
    return mrb_nil_value();
}

// StopAutomationEventRecording
mrb_value mrb_stop_automation_event_recording(mrb_state *mrb, mrb_value self)
{
    StopAutomationEventRecording();
    return mrb_nil_value();
}

// PlayAutomationEvent
mrb_value mrb_play_automation_event(mrb_state *mrb, mrb_value self)
{
    AutomationEvent *event;
    mrb_get_args(mrb, "d", &event, &Raylib_AutomationEvent_type);
    PlayAutomationEvent(*event);
    return mrb_nil_value();
}

void mrb_raylib_setup_automation_event(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_automation_event_list", mrb_load_automation_event_list, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_automation_event_list", mrb_unload_automation_event_list, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_automation_event_list", mrb_export_automation_event_list, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_automation_event_list", mrb_set_automation_event_list, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_automation_event_base_frame", mrb_set_automation_event_base_frame, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "start_automation_event_recording", mrb_start_automation_event_recording, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "stop_automation_event_recording", mrb_stop_automation_event_recording, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "play_automation_event", mrb_play_automation_event, MRB_ARGS_REQ(1));
}