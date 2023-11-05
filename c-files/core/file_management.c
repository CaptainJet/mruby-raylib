//-------
// File Management Functions
//-------

// LoadFileData
mrb_value mrb_load_file_data(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int bytesRead;
    mrb_get_args(mrb, "zi", &filename, &bytesRead);
    unsigned char *filedata = LoadFileData(filename, (int *)bytesRead);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)filedata);
    UnloadFileData(filedata);
    return obj;
}

// UnloadFileData
mrb_value mrb_unload_file_data(mrb_state *mrb, mrb_value self)
{
    unsigned char *filedata;
    mrb_get_args(mrb, "z", &filedata);
    UnloadFileData(filedata);
    return mrb_nil_value();
}

// ExportDataAsCode
mrb_value mrb_export_data_as_code(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    mrb_int size;
    const char *filename;
    mrb_get_args(mrb, "ziz", &data, &size, &filename);
    return mrb_bool_value(ExportDataAsCode(data, size, filename));
}

// LoadFileText
mrb_value mrb_load_file_text(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    char *filetext = LoadFileText(filename);
    mrb_value str = mrb_str_new_cstr(mrb, filetext);
    UnloadFileText(filetext);
    return str;
}

// UnloadFileText
mrb_value mrb_unload_file_text(mrb_state *mrb, mrb_value self)
{
    char *text;
    mrb_get_args(mrb, "z", &text);
    UnloadFileText(text);
    return mrb_nil_value();
}

// SaveFileText
mrb_value mrb_save_file_text(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    char *text;
    mrb_get_args(mrb, "zz", &filename, &text);
    return mrb_bool_value(SaveFileText(filename, text));
}

// FileExists
mrb_value mrb_file_exists(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    return mrb_bool_value(FileExists(filename));
}

// DirectoryExists
mrb_value mrb_directory_exists(mrb_state *mrb, mrb_value self)
{
    const char *dirpath;
    mrb_get_args(mrb, "z", &dirpath);
    return mrb_bool_value(DirectoryExists(dirpath));
}

// IsFileExtension
mrb_value mrb_is_file_extension(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    const char *ext;
    mrb_get_args(mrb, "zz", &filename, &ext);
    return mrb_bool_value(IsFileExtension(filename, ext));
}

// GetFileLength
mrb_value mrb_get_file_length(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    return mrb_int_value(mrb, GetFileLength(filename));
}

// GetFileExtension
mrb_value mrb_get_file_extension(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    return mrb_str_new_cstr(mrb, GetFileExtension(filename));
}

// GetFileName
mrb_value mrb_get_file_name(mrb_state *mrb, mrb_value self)
{
    const char *filepath;
    mrb_get_args(mrb, "z", &filepath);
    return mrb_str_new_cstr(mrb, GetFileName(filepath));
}

// GetFileNameWithoutExt
mrb_value mrb_get_file_name_without_ext(mrb_state *mrb, mrb_value self)
{
    const char *filepath;
    mrb_get_args(mrb, "z", &filepath);
    return mrb_str_new_cstr(mrb, GetFileNameWithoutExt(filepath));
}

// GetDirectoryPath
mrb_value mrb_get_directory_path(mrb_state *mrb, mrb_value self)
{
    const char *filepath;
    mrb_get_args(mrb, "z", &filepath);
    return mrb_str_new_cstr(mrb, GetDirectoryPath(filepath));
}

// GetPrevDirectoryPath
mrb_value mrb_get_prev_directory_path(mrb_state *mrb, mrb_value self)
{
    const char *dirpath;
    mrb_get_args(mrb, "z", &dirpath);
    return mrb_str_new_cstr(mrb, GetPrevDirectoryPath(dirpath));
}

// GetWorkingDirectory
mrb_value mrb_get_working_directory(mrb_state *mrb, mrb_value self)
{
    return mrb_str_new_cstr(mrb, GetWorkingDirectory());
}

// GetApplicationDirectory
mrb_value mrb_get_application_directory(mrb_state *mrb, mrb_value self)
{
    return mrb_str_new_cstr(mrb, GetApplicationDirectory());
}

// IsPathFile
mrb_value mrb_is_path_file(mrb_state *mrb, mrb_value self)
{
    const char *path;
    mrb_get_args(mrb, "z", &path);
    return mrb_bool_value(IsPathFile(path));
}

// LoadDirectoryFiles
mrb_value mrb_load_directory_files(mrb_state *mrb, mrb_value self)
{
    const char *dirpath;
    mrb_get_args(mrb, "z", &dirpath);
    FilePathList *filepathlist = (FilePathList *)malloc(sizeof(FilePathList));
    *filepathlist = LoadDirectoryFiles(dirpath);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_FilePathList_class, &Raylib_FilePathList_type, filepathlist));

    return obj;
}

// LoadDirectoryFilesEx
mrb_value mrb_load_directory_files_ex(mrb_state *mrb, mrb_value self)
{
    const char *basepath;
    const char *filter;
    mrb_bool scandir;
    mrb_get_args(mrb, "zzb", &basepath, &filter, &scandir);
    FilePathList *filepathlist = (FilePathList *)malloc(sizeof(FilePathList));
    *filepathlist = LoadDirectoryFilesEx(basepath, filter, scandir);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_FilePathList_class, &Raylib_FilePathList_type, filepathlist));

    return obj;
}

// UnloadDirectoryFiles
mrb_value mrb_unload_directory_files(mrb_state *mrb, mrb_value self)
{
    FilePathList *filePathList;
    mrb_get_args(mrb, "d", &filePathList, &Raylib_FilePathList_type);
    UnloadDirectoryFiles(*filePathList);
    return mrb_nil_value();
}

// ChangeDirectory
mrb_value mrb_change_directory(mrb_state *mrb, mrb_value self)
{
    const char *dir;
    mrb_get_args(mrb, "z", &dir);
    return mrb_bool_value(ChangeDirectory(dir));
}

// IsFileDropped
mrb_value mrb_is_file_dropped(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsFileDropped());
}

// LoadDroppedFiles
mrb_value mrb_load_dropped_files(mrb_state *mrb, mrb_value self)
{
    FilePathList *filepathlist = (FilePathList *)malloc(sizeof(FilePathList));
    *filepathlist = LoadDroppedFiles();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_FilePathList_class, &Raylib_FilePathList_type, filepathlist));

    return obj;
}

// UnloadDroppedFiles
mrb_value mrb_unload_dropped_files(mrb_state *mrb, mrb_value self)
{
    FilePathList *filePathList;
    mrb_get_args(mrb, "d", &filePathList, &Raylib_FilePathList_type);
    UnloadDroppedFiles(*filePathList);
    return mrb_nil_value();
}

// GetFileModTime
mrb_value mrb_get_file_mod_time(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    return mrb_int_value(mrb, GetFileModTime(filename));
}

void mrb_raylib_setup_file_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_file_data", mrb_load_file_data, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_file_data", mrb_unload_file_data, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_data_as_code", mrb_export_data_as_code, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_file_text", mrb_load_file_text, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_file_text", mrb_unload_file_text, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "save_file_text", mrb_save_file_text, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "file_exists?", mrb_file_exists, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "directory_exists?", mrb_directory_exists, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_file_extension?", mrb_is_file_extension, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_file_length", mrb_get_file_length, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_file_extension", mrb_get_file_extension, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_file_name", mrb_get_file_name, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_file_name_without_ext", mrb_get_file_name_without_ext, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_directory_path", mrb_get_directory_path, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_prev_directory_path", mrb_get_prev_directory_path, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_working_directory", mrb_get_working_directory, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_application_directory", mrb_get_application_directory, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "change_directory", mrb_change_directory, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_path_file?", mrb_is_path_file, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_directory_files", mrb_load_directory_files, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_directory_files_ex", mrb_load_directory_files_ex, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "unload_directory_files", mrb_unload_directory_files, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_file_dropped?", mrb_is_file_dropped, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "load_dropped_files", mrb_load_dropped_files, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "unload_dropped_files", mrb_unload_dropped_files, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_file_mod_time", mrb_get_file_mod_time, MRB_ARGS_REQ(1));
}
