#include <stdlib.h>
#include "raylib.h"
#include "mruby.h"
#include "mruby/string.h"
#include "mruby/numeric.h"
#include "mruby/variable.h"
#include "mruby/class.h"
#include "mruby/array.h"
#include "mruby/compile.h"
#include "mruby/data.h"

mrb_data_type Raylib_Vector2_type = {"Vector2", mrb_free};
struct RClass *Raylib_Vector2_class;

mrb_data_type Raylib_Vector3_type = {"Vector3", mrb_free};
struct RClass *Raylib_Vector3_class;

mrb_data_type Raylib_Vector4_type = {"Vector4", mrb_free};
struct RClass *Raylib_Vector4_class;

mrb_data_type Raylib_Matrix_type = {"Matrix", mrb_free};
struct RClass *Raylib_Matrix_class;

mrb_data_type Raylib_Color_type = {"Color", mrb_free};
struct RClass *Raylib_Color_class;

mrb_data_type Raylib_Rectangle_type = {"Rectangle", mrb_free};
struct RClass *Raylib_Rectangle_class;

void mrb_free_raylib_image(mrb_state *mrb, void *ptr)
{
    Image *image = (Image *)ptr;
    UnloadImage(*image);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Image_type = {"Image", mrb_free_raylib_image};
struct RClass *Raylib_Image_class;

void mrb_free_raylib_texture(mrb_state *mrb, void *ptr)
{
    Texture *texture = (Texture *)ptr;
    UnloadTexture(*texture);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Texture_type = {"Texture", mrb_free_raylib_texture};
struct RClass *Raylib_Texture_class;

void mrb_free_raylib_rendertexture(mrb_state *mrb, void *ptr)
{
    RenderTexture *rendertexture = (RenderTexture *)ptr;
    UnloadRenderTexture(*rendertexture);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_RenderTexture_type = {"RenderTexture", mrb_free_raylib_rendertexture};
struct RClass *Raylib_RenderTexture_class;

mrb_data_type Raylib_NPatchInfo_type = {"NPatchInfo", mrb_free};
struct RClass *Raylib_NPatchInfo_class;

mrb_data_type Raylib_GlyphInfo_type = {"GlyphInfo", mrb_free};
struct RClass *Raylib_GlyphInfo_class;

void mrb_free_raylib_font(mrb_state *mrb, void *ptr)
{
    Font *font = (Font *)ptr;
    UnloadFont(*font);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Font_type = {"Font", mrb_free_raylib_font};
struct RClass *Raylib_Font_class;

mrb_data_type Raylib_Camera_type = {"Camera", mrb_free};
struct RClass *Raylib_Camera_class;

mrb_data_type Raylib_Camera2D_type = {"Camera2D", mrb_free};
struct RClass *Raylib_Camera2D_class;

//-----------------------------------------------------------------------------------

void mrb_free_raylib_mesh(mrb_state *mrb, void *ptr)
{
    Mesh *mesh = (Mesh *)ptr;
    UnloadMesh(*mesh);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Mesh_type = {"Mesh", mrb_free_raylib_mesh};
struct RClass *Raylib_Mesh_class;

void mrb_free_raylib_shader(mrb_state *mrb, void *ptr)
{
    Shader *shader = (Shader *)ptr;
    UnloadShader(*shader);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Shader_type = {"Shader", mrb_free_raylib_shader};
struct RClass *Raylib_Shader_class;

mrb_data_type Raylib_MaterialMap_type = {"MaterialMap", mrb_free};
struct RClass *Raylib_MaterialMap_class;

void mrb_free_raylib_material(mrb_state *mrb, void *ptr)
{
    Material *material = (Material *)ptr;
    UnloadMaterial(*material);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Material_type = {"Material", mrb_free_raylib_material};
struct RClass *Raylib_Material_class;

void mrb_free_raylib_model(mrb_state *mrb, void *ptr)
{
    Model *model = (Model *)ptr;
    UnloadModel(*model);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Model_type = {"Model", mrb_free_raylib_model};
struct RClass *Raylib_Model_class;

mrb_data_type Raylib_Transform_type = {"Transform", mrb_free};
struct RClass *Raylib_Transform_class;

mrb_data_type Raylib_BoneInfo_type = {"BoneInfo", mrb_free};
struct RClass *Raylib_BoneInfo_class;

void mrb_free_raylib_model_animation(mrb_state *mrb, void *ptr)
{
    ModelAnimation *modelAnimation = (ModelAnimation *)ptr;
    UnloadModelAnimation(*modelAnimation);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_ModelAnimation_type = {"ModelAnimation", mrb_free_raylib_model_animation};
struct RClass *Raylib_ModelAnimation_class;

//-----------------------------------------------------------------------------------

mrb_data_type Raylib_Ray_type = {"Ray", mrb_free};
struct RClass *Raylib_Ray_class;

mrb_data_type Raylib_RayCollision_type = {"RayCollision", mrb_free};
struct RClass *Raylib_RayCollision_class;

mrb_data_type Raylib_BoundingBox_type = {"BoundingBox", mrb_free};
struct RClass *Raylib_BoundingBox_class;

//-----------------------------------------------------------------------------------

void mrb_free_raylib_wave(mrb_state *mrb, void *ptr)
{
    Wave *wave = (Wave *)ptr;
    UnloadWave(*wave);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Wave_type = {"Wave", mrb_free_raylib_wave};
struct RClass *Raylib_Wave_class;

void mrb_free_raylib_sound(mrb_state *mrb, void *ptr)
{
    Sound *sound = (Sound *)ptr;
    UnloadSound(*sound);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Sound_type = {"Sound", mrb_free_raylib_sound};
struct RClass *Raylib_Sound_class;

void mrb_free_raylib_music(mrb_state *mrb, void *ptr)
{
    Music *music = (Music *)ptr;
    UnloadMusicStream(*music);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_Music_type = {"Music", mrb_free_raylib_music};
struct RClass *Raylib_Music_class;

mrb_data_type Raylib_AudioStream_type = {"AudioStream", mrb_free};
struct RClass *Raylib_AudioStream_class;

mrb_data_type Raylib_VrDeviceInfo_type = {"VrDeviceInfo", mrb_free};
struct RClass *Raylib_VrDeviceInfo_class;

void mrb_free_raylib_vrstreoconfig(mrb_state *mrb, void *ptr)
{
    VrStereoConfig *vrstreoconfig = (VrStereoConfig *)ptr;
    UnloadVrStereoConfig(*vrstreoconfig);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_VrStereoConfig_type = {"VrStereoConfig", mrb_free_raylib_vrstreoconfig};
struct RClass *Raylib_VrStereoConfig_class;

//-----------------------------------------------------------------------------------

void mrb_free_raylib_filepathlist(mrb_state *mrb, void *ptr)
{
    FilePathList *filepathlist = (FilePathList *)ptr;
    UnloadDirectoryFiles(*filepathlist);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_FilePathList_type = {"FilePathList", mrb_free_raylib_filepathlist};
struct RClass *Raylib_FilePathList_class;

mrb_data_type Raylib_AutomationEvent_type = {"AutomationEvent", mrb_free};
struct RClass *Raylib_AutomationEvent_class;

void mrb_free_raylib_automation_event_list(mrb_state *mrb, void *ptr)
{
    AutomationEventList *list = (AutomationEventList *)ptr;
    UnloadAutomationEventList(list);
    mrb_free(mrb, ptr);
}
mrb_data_type Raylib_AutomationEventList_type = {"AutomationEventList", mrb_free_raylib_automation_event_list};
struct RClass *Raylib_AutomationEventList_class;

//----------------------------------------------------------------------------------------------

mrb_value mrb_Vector2_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y;
    mrb_get_args(mrb, "ii", &x, &y);

    Vector2 *vector2 = (Vector2 *)DATA_PTR(self);
    if (vector2)
    {
        mrb_free(mrb, vector2);
    }
    mrb_data_init(self, NULL, &Raylib_Vector2_type);
    vector2 = (Vector2 *)mrb_malloc(mrb, sizeof(Vector2));

    vector2->x = x;
    vector2->y = y;

    mrb_data_init(self, vector2, &Raylib_Vector2_type);
    return self;
}

mrb_value mrb_Vector2_set_x(mrb_state *mrb, mrb_value self)
{
    mrb_int x;
    mrb_get_args(mrb, "i", &x);
    Vector2 *vector2 = (Vector2 *)DATA_PTR(self);
    vector2->x = x;
    return mrb_nil_value();
}

mrb_value mrb_Vector2_set_y(mrb_state *mrb, mrb_value self)
{
    mrb_int y;
    mrb_get_args(mrb, "i", &y);
    Vector2 *vector2 = (Vector2 *)DATA_PTR(self);
    vector2->y = y;
    return mrb_nil_value();
}

mrb_value mrb_Vector2_get_x(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector2->x);
}

mrb_value mrb_Vector2_get_y(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector2->y);
}

mrb_value mrb_Vector3_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y, z;
    mrb_get_args(mrb, "iii", &x, &y, &z);

    Vector3 *vector3 = (Vector3 *)DATA_PTR(self);
    if (vector3)
    {
        mrb_free(mrb, vector3);
    }
    mrb_data_init(self, NULL, &Raylib_Vector3_type);
    vector3 = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));

    vector3->x = x;
    vector3->y = y;
    vector3->z = z;

    mrb_data_init(self, vector3, &Raylib_Vector3_type);
    return self;
}

mrb_value mrb_Vector3_set_x(mrb_state *mrb, mrb_value self)
{
    mrb_int x;
    mrb_get_args(mrb, "i", &x);
    Vector3 *vector3 = (Vector3 *)DATA_PTR(self);
    vector3->x = x;
    return mrb_nil_value();
}

mrb_value mrb_Vector3_set_y(mrb_state *mrb, mrb_value self)
{
    mrb_int y;
    mrb_get_args(mrb, "i", &y);
    Vector3 *vector3 = (Vector3 *)DATA_PTR(self);
    vector3->y = y;
    return mrb_nil_value();
}

mrb_value mrb_Vector3_set_z(mrb_state *mrb, mrb_value self)
{
    mrb_int z;
    mrb_get_args(mrb, "i", &z);
    Vector3 *vector3 = (Vector3 *)DATA_PTR(self);
    vector3->z = z;
    return mrb_nil_value();
}

mrb_value mrb_Vector3_get_x(mrb_state *mrb, mrb_value self)
{
    Vector3 *vector3 = (Vector3 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector3->x);
}

mrb_value mrb_Vector3_get_y(mrb_state *mrb, mrb_value self)
{
    Vector3 *vector3 = (Vector3 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector3->y);
}

mrb_value mrb_Vector3_get_z(mrb_state *mrb, mrb_value self)
{
    Vector3 *vector3 = (Vector3 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector3->z);
}

mrb_value mrb_Vector4_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y, z, w;
    mrb_get_args(mrb, "iiii", &x, &y, &z, &w);

    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    if (vector4)
    {
        mrb_free(mrb, vector4);
    }
    mrb_data_init(self, NULL, &Raylib_Vector4_type);
    vector4 = (Vector4 *)mrb_malloc(mrb, sizeof(Vector4));

    vector4->x = x;
    vector4->y = y;
    vector4->z = z;
    vector4->w = w;

    mrb_data_init(self, vector4, &Raylib_Vector4_type);
    return self;
}

mrb_value mrb_Vector4_set_x(mrb_state *mrb, mrb_value self)
{
    mrb_int x;
    mrb_get_args(mrb, "i", &x);
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    vector4->x = x;
    return mrb_nil_value();
}

mrb_value mrb_Vector4_set_y(mrb_state *mrb, mrb_value self)
{
    mrb_int y;
    mrb_get_args(mrb, "i", &y);
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    vector4->y = y;
    return mrb_nil_value();
}

mrb_value mrb_Vector4_set_z(mrb_state *mrb, mrb_value self)
{
    mrb_int z;
    mrb_get_args(mrb, "i", &z);
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    vector4->z = z;
    return mrb_nil_value();
}

mrb_value mrb_Vector4_set_w(mrb_state *mrb, mrb_value self)
{
    mrb_int w;
    mrb_get_args(mrb, "i", &w);
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    vector4->w = w;
    return mrb_nil_value();
}

mrb_value mrb_Vector4_get_x(mrb_state *mrb, mrb_value self)
{
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector4->x);
}

mrb_value mrb_Vector4_get_y(mrb_state *mrb, mrb_value self)
{
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector4->y);
}

mrb_value mrb_Vector4_get_z(mrb_state *mrb, mrb_value self)
{
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector4->z);
}

mrb_value mrb_Vector4_get_w(mrb_state *mrb, mrb_value self)
{
    Vector4 *vector4 = (Vector4 *)DATA_PTR(self);
    return mrb_int_value(mrb, vector4->w);
}

mrb_value mrb_Matrix_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;
    mrb_get_args(mrb, "iiiiiiiiiiiiiiii", &m0, &m1, &m2, &m3, &m4, &m5, &m6, &m7, &m8, &m9, &m10, &m11, &m12, &m13, &m14, &m15);

    Matrix *matrix = (Matrix *)DATA_PTR(self);
    if (matrix)
    {
        mrb_free(mrb, matrix);
    }
    mrb_data_init(self, NULL, &Raylib_Matrix_type);
    matrix = (Matrix *)mrb_malloc(mrb, sizeof(Matrix));

    matrix->m0 = m0;
    matrix->m1 = m1;
    matrix->m2 = m2;
    matrix->m3 = m3;
    matrix->m4 = m4;
    matrix->m5 = m5;
    matrix->m6 = m6;
    matrix->m7 = m7;
    matrix->m8 = m8;
    matrix->m9 = m9;
    matrix->m10 = m10;
    matrix->m11 = m11;
    matrix->m12 = m12;
    matrix->m13 = m13;
    matrix->m14 = m14;
    matrix->m15 = m15;

    mrb_data_init(self, matrix, &Raylib_Matrix_type);
    return self;
}

mrb_value mrb_Matrix_set_m0(mrb_state *mrb, mrb_value self)
{
    mrb_int m0;
    mrb_get_args(mrb, "i", &m0);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m0 = m0;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m1(mrb_state *mrb, mrb_value self)
{
    mrb_int m1;
    mrb_get_args(mrb, "i", &m1);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m1 = m1;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m2(mrb_state *mrb, mrb_value self)
{
    mrb_int m2;
    mrb_get_args(mrb, "i", &m2);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m2 = m2;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m3(mrb_state *mrb, mrb_value self)
{
    mrb_int m3;
    mrb_get_args(mrb, "i", &m3);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m3 = m3;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m4(mrb_state *mrb, mrb_value self)
{
    mrb_int m4;
    mrb_get_args(mrb, "i", &m4);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m4 = m4;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m5(mrb_state *mrb, mrb_value self)
{
    mrb_int m5;
    mrb_get_args(mrb, "i", &m5);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m5 = m5;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m6(mrb_state *mrb, mrb_value self)
{
    mrb_int m6;
    mrb_get_args(mrb, "i", &m6);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m6 = m6;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m7(mrb_state *mrb, mrb_value self)
{
    mrb_int m7;
    mrb_get_args(mrb, "i", &m7);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m7 = m7;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m8(mrb_state *mrb, mrb_value self)
{
    mrb_int m8;
    mrb_get_args(mrb, "i", &m8);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m8 = m8;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m9(mrb_state *mrb, mrb_value self)
{
    mrb_int m9;
    mrb_get_args(mrb, "i", &m9);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m9 = m9;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m10(mrb_state *mrb, mrb_value self)
{
    mrb_int m10;
    mrb_get_args(mrb, "i", &m10);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m10 = m10;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m11(mrb_state *mrb, mrb_value self)
{
    mrb_int m11;
    mrb_get_args(mrb, "i", &m11);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m11 = m11;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m12(mrb_state *mrb, mrb_value self)
{
    mrb_int m12;
    mrb_get_args(mrb, "i", &m12);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m12 = m12;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m13(mrb_state *mrb, mrb_value self)
{
    mrb_int m13;
    mrb_get_args(mrb, "i", &m13);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m13 = m13;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m14(mrb_state *mrb, mrb_value self)
{
    mrb_int m14;
    mrb_get_args(mrb, "i", &m14);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m14 = m14;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_set_m15(mrb_state *mrb, mrb_value self)
{
    mrb_int m15;
    mrb_get_args(mrb, "i", &m15);
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    matrix->m15 = m15;
    return mrb_nil_value();
}

mrb_value mrb_Matrix_get_m0(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m0);
}

mrb_value mrb_Matrix_get_m1(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m1);
}

mrb_value mrb_Matrix_get_m2(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m2);
}

mrb_value mrb_Matrix_get_m3(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m3);
}

mrb_value mrb_Matrix_get_m4(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m4);
}

mrb_value mrb_Matrix_get_m5(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m5);
}

mrb_value mrb_Matrix_get_m6(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m6);
}

mrb_value mrb_Matrix_get_m7(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m7);
}

mrb_value mrb_Matrix_get_m8(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m8);
}

mrb_value mrb_Matrix_get_m9(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m9);
}

mrb_value mrb_Matrix_get_m10(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m10);
}

mrb_value mrb_Matrix_get_m11(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m11);
}

mrb_value mrb_Matrix_get_m12(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m12);
}

mrb_value mrb_Matrix_get_m13(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m13);
}

mrb_value mrb_Matrix_get_m14(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m14);
}

mrb_value mrb_Matrix_get_m15(mrb_state *mrb, mrb_value self)
{
    Matrix *matrix = (Matrix *)DATA_PTR(self);
    return mrb_int_value(mrb, matrix->m15);
}

mrb_value mrb_Color_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int r, g, b, a;
    mrb_get_args(mrb, "iiii", &r, &g, &b, &a);

    Color *color = (Color *)DATA_PTR(self);
    if (color)
    {
        mrb_free(mrb, color);
    }
    mrb_data_init(self, NULL, &Raylib_Color_type);
    color = (Color *)mrb_malloc(mrb, sizeof(Color));

    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;

    mrb_data_init(self, color, &Raylib_Color_type);
    return self;
}

mrb_value mrb_Color_get_r(mrb_state *mrb, mrb_value self)
{
    Color *color = (Color *)DATA_PTR(self);
    return mrb_int_value(mrb, color->r);
}

mrb_value mrb_Color_get_g(mrb_state *mrb, mrb_value self)
{
    Color *color = (Color *)DATA_PTR(self);
    return mrb_int_value(mrb, color->g);
}

mrb_value mrb_Color_get_b(mrb_state *mrb, mrb_value self)
{
    Color *color = (Color *)DATA_PTR(self);
    return mrb_int_value(mrb, color->b);
}

mrb_value mrb_Color_get_a(mrb_state *mrb, mrb_value self)
{
    Color *color = (Color *)DATA_PTR(self);
    return mrb_int_value(mrb, color->a);
}

mrb_value mrb_Color_set_r(mrb_state *mrb, mrb_value self)
{
    mrb_int r;
    mrb_get_args(mrb, "i", &r);
    Color *color = (Color *)DATA_PTR(self);
    color->r = r;
    return mrb_nil_value();
}

mrb_value mrb_Color_set_g(mrb_state *mrb, mrb_value self)
{
    mrb_int g;
    mrb_get_args(mrb, "i", &g);
    Color *color = (Color *)DATA_PTR(self);
    color->g = g;
    return mrb_nil_value();
}

mrb_value mrb_Color_set_b(mrb_state *mrb, mrb_value self)
{
    mrb_int b;
    mrb_get_args(mrb, "i", &b);
    Color *color = (Color *)DATA_PTR(self);
    color->b = b;
    return mrb_nil_value();
}

mrb_value mrb_Color_set_a(mrb_state *mrb, mrb_value self)
{
    mrb_int a;
    mrb_get_args(mrb, "i", &a);
    Color *color = (Color *)DATA_PTR(self);
    color->a = a;
    return mrb_nil_value();
}

mrb_value mrb_Rectangle_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, width, height;
    mrb_get_args(mrb, "ffff", &x, &y, &width, &height);

    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    if (rectangle)
    {
        mrb_free(mrb, rectangle);
    }
    mrb_data_init(self, NULL, &Raylib_Rectangle_type);
    rectangle = (Rectangle *)mrb_malloc(mrb, sizeof(Rectangle));

    rectangle->x = x;
    rectangle->y = y;
    rectangle->width = width;
    rectangle->height = height;

    mrb_data_init(self, rectangle, &Raylib_Rectangle_type);
    return self;
}

mrb_value mrb_Rectangle_set_x(mrb_state *mrb, mrb_value self)
{
    mrb_float x;
    mrb_get_args(mrb, "f", &x);
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    rectangle->x = x;
    return mrb_nil_value();
}

mrb_value mrb_Rectangle_set_y(mrb_state *mrb, mrb_value self)
{
    mrb_float y;
    mrb_get_args(mrb, "f", &y);
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    rectangle->y = y;
    return mrb_nil_value();
}

mrb_value mrb_Rectangle_set_width(mrb_state *mrb, mrb_value self)
{
    mrb_float width;
    mrb_get_args(mrb, "f", &width);
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    rectangle->width = width;
    return mrb_nil_value();
}

mrb_value mrb_Rectangle_set_height(mrb_state *mrb, mrb_value self)
{
    mrb_float height;
    mrb_get_args(mrb, "f", &height);
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    rectangle->height = height;
    return mrb_nil_value();
}

mrb_value mrb_Rectangle_get_x(mrb_state *mrb, mrb_value self)
{
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    return mrb_float_value(mrb, rectangle->x);
}

mrb_value mrb_Rectangle_get_y(mrb_state *mrb, mrb_value self)
{
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    return mrb_float_value(mrb, rectangle->y);
}

mrb_value mrb_Rectangle_get_width(mrb_state *mrb, mrb_value self)
{
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    return mrb_float_value(mrb, rectangle->width);
}

mrb_value mrb_Rectangle_get_height(mrb_state *mrb, mrb_value self)
{
    Rectangle *rectangle = (Rectangle *)DATA_PTR(self);
    return mrb_float_value(mrb, rectangle->height);
}

mrb_value mrb_Image_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height, mipmaps, format;
    mrb_get_args(mrb, "iiii", &width, &height, &mipmaps, &format);

    Image *image = (Image *)DATA_PTR(self);
    if (image)
    {
        mrb_free(mrb, image);
    }
    mrb_data_init(self, NULL, &Raylib_Image_type);
    image = (Image *)mrb_malloc(mrb, sizeof(Image));

    image->width = width;
    image->height = height;
    image->mipmaps = mipmaps;
    image->format = format;

    mrb_data_init(self, image, &Raylib_Image_type);
    return self;
}

mrb_value mrb_Image_get_width(mrb_state *mrb, mrb_value self)
{
    Image *image = (Image *)DATA_PTR(self);
    return mrb_int_value(mrb, image->width);
}

mrb_value mrb_Image_get_height(mrb_state *mrb, mrb_value self)
{
    Image *image = (Image *)DATA_PTR(self);
    return mrb_int_value(mrb, image->height);
}

mrb_value mrb_Image_get_mipmaps(mrb_state *mrb, mrb_value self)
{
    Image *image = (Image *)DATA_PTR(self);
    return mrb_int_value(mrb, image->mipmaps);
}

mrb_value mrb_Image_get_format(mrb_state *mrb, mrb_value self)
{
    Image *image = (Image *)DATA_PTR(self);
    return mrb_int_value(mrb, image->format);
}

mrb_value mrb_Image_set_width(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_get_args(mrb, "i", &width);
    Image *image = (Image *)DATA_PTR(self);
    image->width = width;
    return mrb_nil_value();
}

mrb_value mrb_Image_set_height(mrb_state *mrb, mrb_value self)
{
    mrb_int height;
    mrb_get_args(mrb, "i", &height);
    Image *image = (Image *)DATA_PTR(self);
    image->height = height;
    return mrb_nil_value();
}

mrb_value mrb_Image_set_mipmaps(mrb_state *mrb, mrb_value self)
{
    mrb_int mipmaps;
    mrb_get_args(mrb, "i", &mipmaps);
    Image *image = (Image *)DATA_PTR(self);
    image->mipmaps = mipmaps;
    return mrb_nil_value();
}

mrb_value mrb_Image_set_format(mrb_state *mrb, mrb_value self)
{
    mrb_int format;
    mrb_get_args(mrb, "i", &format);
    Image *image = (Image *)DATA_PTR(self);
    image->format = format;
    return mrb_nil_value();
}

mrb_value mrb_Texture_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int id, width, height, mipmaps, format;
    mrb_get_args(mrb, "iiiii", &id, &width, &height, &mipmaps, &format);

    Texture *texture = (Texture *)DATA_PTR(self);
    if (texture)
    {
        mrb_free(mrb, texture);
    }
    mrb_data_init(self, NULL, &Raylib_Texture_type);
    texture = (Texture *)mrb_malloc(mrb, sizeof(Texture));

    texture->id = id;
    texture->width = width;
    texture->height = height;
    texture->mipmaps = mipmaps;
    texture->format = format;

    mrb_data_init(self, texture, &Raylib_Texture_type);
    return self;
}

mrb_value mrb_Texture_get_id(mrb_state *mrb, mrb_value self)
{
    Texture *texture = (Texture *)DATA_PTR(self);
    return mrb_int_value(mrb, texture->id);
}

mrb_value mrb_Texture_get_width(mrb_state *mrb, mrb_value self)
{
    Texture *texture = (Texture *)DATA_PTR(self);
    return mrb_int_value(mrb, texture->width);
}

mrb_value mrb_Texture_get_height(mrb_state *mrb, mrb_value self)
{
    Texture *texture = (Texture *)DATA_PTR(self);
    return mrb_int_value(mrb, texture->height);
}

mrb_value mrb_Texture_get_mipmaps(mrb_state *mrb, mrb_value self)
{
    Texture *texture = (Texture *)DATA_PTR(self);
    return mrb_int_value(mrb, texture->mipmaps);
}

mrb_value mrb_Texture_get_format(mrb_state *mrb, mrb_value self)
{
    Texture *texture = (Texture *)DATA_PTR(self);
    return mrb_int_value(mrb, texture->format);
}

mrb_value mrb_Texture_set_id(mrb_state *mrb, mrb_value self)
{
    mrb_int id;
    mrb_get_args(mrb, "i", &id);
    Texture *texture = (Texture *)DATA_PTR(self);
    texture->id = id;
    return mrb_nil_value();
}

mrb_value mrb_Texture_set_width(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_get_args(mrb, "i", &width);
    Texture *texture = (Texture *)DATA_PTR(self);
    texture->width = width;
    return mrb_nil_value();
}

mrb_value mrb_Texture_set_height(mrb_state *mrb, mrb_value self)
{
    mrb_int height;
    mrb_get_args(mrb, "i", &height);
    Texture *texture = (Texture *)DATA_PTR(self);
    texture->height = height;
    return mrb_nil_value();
}

mrb_value mrb_Texture_set_mipmaps(mrb_state *mrb, mrb_value self)
{
    mrb_int mipmaps;
    mrb_get_args(mrb, "i", &mipmaps);
    Texture *texture = (Texture *)DATA_PTR(self);
    texture->mipmaps = mipmaps;
    return mrb_nil_value();
}

mrb_value mrb_Texture_set_format(mrb_state *mrb, mrb_value self)
{
    mrb_int format;
    mrb_get_args(mrb, "i", &format);
    Texture *texture = (Texture *)DATA_PTR(self);
    texture->format = format;
    return mrb_nil_value();
}

mrb_value mrb_RenderTexture_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int id;
    Texture *texture;
    Texture *depth;
    mrb_get_args(mrb, "idd", &id, &texture, &Raylib_Texture_type, &depth, &Raylib_Texture_type);

    RenderTexture *rendertexture = (RenderTexture *)DATA_PTR(self);
    if (rendertexture)
    {
        mrb_free(mrb, rendertexture);
    }
    mrb_data_init(self, NULL, &Raylib_RenderTexture_type);
    rendertexture = (RenderTexture *)mrb_malloc(mrb, sizeof(RenderTexture));

    rendertexture->id = id;
    rendertexture->texture = *texture;
    rendertexture->depth = *depth;

    mrb_data_init(self, rendertexture, &Raylib_RenderTexture_type);
    return self;
}

mrb_value mrb_RenderTexture_get_id(mrb_state *mrb, mrb_value self)
{
    RenderTexture *rendertexture = (RenderTexture *)DATA_PTR(self);
    return mrb_int_value(mrb, rendertexture->id);
}

mrb_value mrb_RenderTexture_get_texture(mrb_state *mrb, mrb_value self)
{
    RenderTexture *rendertexture = (RenderTexture *)DATA_PTR(self);
    Texture *texture = (Texture *)mrb_malloc(mrb, sizeof(Texture));
    *texture = rendertexture->texture;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));
    return obj;
}

mrb_value mrb_RenderTexture_get_depth(mrb_state *mrb, mrb_value self)
{
    RenderTexture *rendertexture = (RenderTexture *)DATA_PTR(self);
    Texture *depth = (Texture *)mrb_malloc(mrb, sizeof(Texture));
    *depth = rendertexture->depth;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, depth));
    return obj;
}

mrb_value mrb_RenderTexture_set_id(mrb_state *mrb, mrb_value self)
{
    mrb_int id;
    mrb_get_args(mrb, "i", &id);
    RenderTexture *rendertexture = (RenderTexture *)DATA_PTR(self);
    rendertexture->id = id;
    return mrb_nil_value();
}

mrb_value mrb_RenderTexture_set_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    RenderTexture *rendertexture = (RenderTexture *)DATA_PTR(self);
    rendertexture->texture = *texture;
    return mrb_nil_value();
}

mrb_value mrb_RenderTexture_set_depth(mrb_state *mrb, mrb_value self)
{
    Texture *depth;
    mrb_get_args(mrb, "d", &depth, &Raylib_Texture_type);
    RenderTexture *rendertexture = (RenderTexture *)DATA_PTR(self);
    rendertexture->depth = *depth;
    return mrb_nil_value();
}

mrb_value mrb_NPatchInfo_initialize(mrb_state *mrb, mrb_value self)
{
    Rectangle *source;
    mrb_int left, top, right, bottom, layout;
    mrb_get_args(mrb, "diiiii", &source, &Raylib_Rectangle_type, &left, &top, &right, &bottom, &layout);

    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    if (npatchinfo)
    {
        mrb_free(mrb, npatchinfo);
    }
    mrb_data_init(self, NULL, &Raylib_NPatchInfo_type);
    npatchinfo = (NPatchInfo *)mrb_malloc(mrb, sizeof(NPatchInfo));

    npatchinfo->source = *source;
    npatchinfo->left = left;
    npatchinfo->top = top;
    npatchinfo->right = right;
    npatchinfo->bottom = bottom;
    npatchinfo->layout = layout;

    mrb_data_init(self, npatchinfo, &Raylib_NPatchInfo_type);
    return self;
}

mrb_value mrb_NPatchInfo_get_left(mrb_state *mrb, mrb_value self)
{
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, npatchinfo->left);
}

mrb_value mrb_NPatchInfo_get_top(mrb_state *mrb, mrb_value self)
{
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, npatchinfo->top);
}

mrb_value mrb_NPatchInfo_get_right(mrb_state *mrb, mrb_value self)
{
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, npatchinfo->right);
}

mrb_value mrb_NPatchInfo_get_bottom(mrb_state *mrb, mrb_value self)
{
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, npatchinfo->bottom);
}

mrb_value mrb_NPatchInfo_get_layout(mrb_state *mrb, mrb_value self)
{
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, npatchinfo->layout);
}

mrb_value mrb_NPatchInfo_get_source(mrb_state *mrb, mrb_value self)
{
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    Rectangle *rectangle = (Rectangle *)mrb_malloc(mrb, sizeof(Rectangle));
    *rectangle = npatchinfo->source;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Rectangle_class, &Raylib_Rectangle_type, rectangle));
    return obj;
}

mrb_value mrb_NPatchInfo_set_source(mrb_state *mrb, mrb_value self)
{
    Rectangle *rectangle;
    mrb_get_args(mrb, "d", &rectangle, &Raylib_Rectangle_type);
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    npatchinfo->source = *rectangle;
    return mrb_nil_value();
}

mrb_value mrb_NPatchInfo_set_left(mrb_state *mrb, mrb_value self)
{
    mrb_int left;
    mrb_get_args(mrb, "i", &left);
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    npatchinfo->left = left;
    return mrb_nil_value();
}

mrb_value mrb_NPatchInfo_set_top(mrb_state *mrb, mrb_value self)
{
    mrb_int top;
    mrb_get_args(mrb, "i", &top);
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    npatchinfo->top = top;
    return mrb_nil_value();
}

mrb_value mrb_NPatchInfo_set_right(mrb_state *mrb, mrb_value self)
{
    mrb_int right;
    mrb_get_args(mrb, "i", &right);
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    npatchinfo->right = right;
    return mrb_nil_value();
}

mrb_value mrb_NPatchInfo_set_bottom(mrb_state *mrb, mrb_value self)
{
    mrb_int bottom;
    mrb_get_args(mrb, "i", &bottom);
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    npatchinfo->bottom = bottom;
    return mrb_nil_value();
}

mrb_value mrb_NPatchInfo_set_layout(mrb_state *mrb, mrb_value self)
{
    mrb_int layout;
    mrb_get_args(mrb, "i", &layout);
    NPatchInfo *npatchinfo = (NPatchInfo *)DATA_PTR(self);
    npatchinfo->layout = layout;
    return mrb_nil_value();
}

mrb_value mrb_GlyphInfo_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int value, offsetX, offsetY, advanceX;
    Image *image;
    mrb_get_args(mrb, "iiiid", &value, &offsetX, &offsetY, &advanceX, &image, &Raylib_Image_type);

    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    if (glyphinfo)
    {
        mrb_free(mrb, glyphinfo);
    }
    mrb_data_init(self, NULL, &Raylib_GlyphInfo_type);
    glyphinfo = (GlyphInfo *)mrb_malloc(mrb, sizeof(GlyphInfo));

    glyphinfo->value = value;
    glyphinfo->offsetX = offsetX;
    glyphinfo->offsetY = offsetY;
    glyphinfo->advanceX = advanceX;
    glyphinfo->image = *image;

    mrb_data_init(self, glyphinfo, &Raylib_GlyphInfo_type);
    return self;
}

mrb_value mrb_GlyphInfo_get_value(mrb_state *mrb, mrb_value self)
{
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, glyphinfo->value);
}

mrb_value mrb_GlyphInfo_get_advanceX(mrb_state *mrb, mrb_value self)
{
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, glyphinfo->advanceX);
}

mrb_value mrb_GlyphInfo_get_offsetX(mrb_state *mrb, mrb_value self)
{
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, glyphinfo->offsetX);
}

mrb_value mrb_GlyphInfo_get_offsetY(mrb_state *mrb, mrb_value self)
{
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    return mrb_int_value(mrb, glyphinfo->offsetY);
}

mrb_value mrb_GlyphInfo_get_image(mrb_state *mrb, mrb_value self)
{
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    Image *image = (Image *)mrb_malloc(mrb, sizeof(Image));
    *image = glyphinfo->image;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));
    return obj;
}

mrb_value mrb_GlyphInfo_set_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    glyphinfo->image = *image;
    return mrb_nil_value();
}

mrb_value mrb_GlyphInfo_set_value(mrb_state *mrb, mrb_value self)
{
    mrb_int value;
    mrb_get_args(mrb, "i", &value);
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    glyphinfo->value = value;
    return mrb_nil_value();
}

mrb_value mrb_GlyphInfo_set_advanceX(mrb_state *mrb, mrb_value self)
{
    mrb_int advanceX;
    mrb_get_args(mrb, "i", &advanceX);
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    glyphinfo->advanceX = advanceX;
    return mrb_nil_value();
}

mrb_value mrb_GlyphInfo_set_offsetX(mrb_state *mrb, mrb_value self)
{
    mrb_int offsetX;
    mrb_get_args(mrb, "i", &offsetX);
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    glyphinfo->offsetX = offsetX;
    return mrb_nil_value();
}

mrb_value mrb_GlyphInfo_set_offsetY(mrb_state *mrb, mrb_value self)
{
    mrb_int offsetY;
    mrb_get_args(mrb, "i", &offsetY);
    GlyphInfo *glyphinfo = (GlyphInfo *)DATA_PTR(self);
    glyphinfo->offsetY = offsetY;
    return mrb_nil_value();
}

mrb_value mrb_Font_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int baseSize, glyphCount, glyphPadding;
    Texture2D *texture;
    mrb_value recs, glyphs;
    mrb_get_args(mrb, "iiidAA", &baseSize, &glyphCount, &glyphPadding, &texture, &Raylib_Texture_type, &recs, &glyphs);

    Font *font = (Font *)DATA_PTR(self);
    if (font)
    {
        mrb_free(mrb, font);
    }
    mrb_data_init(self, NULL, &Raylib_Font_type);
    font = (Font *)mrb_malloc(mrb, sizeof(Font));
    GlyphInfo glyph_values[glyphCount];
    Rectangle recs_values[glyphCount];
    for (int i = 0; i < glyphCount; ++i)
    {
        glyph_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(glyphs, i), &Raylib_GlyphInfo_type, GlyphInfo);
        recs_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(recs, i), &Raylib_Rectangle_type, Rectangle);
    }
    font->baseSize = baseSize;
    font->glyphCount = glyphCount;
    font->glyphPadding = glyphPadding;
    font->texture = *texture;
    font->recs = recs_values;
    font->glyphs = glyph_values;

    mrb_data_init(self, font, &Raylib_Font_type);
    return self;
}

mrb_value mrb_Font_get_baseSize(mrb_state *mrb, mrb_value self)
{
    Font *font = (Font *)DATA_PTR(self);
    return mrb_int_value(mrb, font->baseSize);
}

mrb_value mrb_Font_get_glyphCount(mrb_state *mrb, mrb_value self)
{
    Font *font = (Font *)DATA_PTR(self);
    return mrb_int_value(mrb, font->glyphCount);
}

mrb_value mrb_Font_get_glyphPadding(mrb_state *mrb, mrb_value self)
{
    Font *font = (Font *)DATA_PTR(self);
    return mrb_int_value(mrb, font->glyphPadding);
}

mrb_value mrb_Font_get_texture(mrb_state *mrb, mrb_value self)
{
    Font *font = (Font *)DATA_PTR(self);
    Texture *texture = (Texture *)mrb_malloc(mrb, sizeof(Texture));
    *texture = font->texture;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));
    return obj;
}

mrb_value mrb_Font_get_recs(mrb_state *mrb, mrb_value self)
{
    Font *font = (Font *)DATA_PTR(self);
    mrb_value ary = mrb_ary_new(mrb);
    Rectangle *rectangles = font->recs;
    for (int i = 0; i < font->glyphCount; ++i)
    {
        Rectangle *rect = (Rectangle *)mrb_malloc(mrb, sizeof(Rectangle));
        *rect = rectangles[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Rectangle_class, &Raylib_Rectangle_type, rect)));
    }
    return ary;
}

mrb_value mrb_Font_get_glyphs(mrb_state *mrb, mrb_value self)
{
    Font *font = (Font *)DATA_PTR(self);
    mrb_value ary = mrb_ary_new(mrb);
    GlyphInfo *glyphs = font->glyphs;
    for (int i = 0; i < font->glyphCount; ++i)
    {
        GlyphInfo *glyph = (GlyphInfo *)mrb_malloc(mrb, sizeof(GlyphInfo));
        *glyph = glyphs[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_GlyphInfo_class, &Raylib_GlyphInfo_type, glyph)));
    }
    return ary;
}

mrb_value mrb_Font_set_baseSize(mrb_state *mrb, mrb_value self)
{
    mrb_int baseSize;
    mrb_get_args(mrb, "i", &baseSize);
    Font *font = (Font *)DATA_PTR(self);
    font->baseSize = baseSize;
    return mrb_nil_value();
}

mrb_value mrb_Font_set_glyphCount(mrb_state *mrb, mrb_value self)
{
    mrb_int glyphCount;
    mrb_get_args(mrb, "i", &glyphCount);
    Font *font = (Font *)DATA_PTR(self);
    font->glyphCount = glyphCount;
    return mrb_nil_value();
}

mrb_value mrb_Font_set_glyphPadding(mrb_state *mrb, mrb_value self)
{
    mrb_int glyphPadding;
    mrb_get_args(mrb, "i", &glyphPadding);
    Font *font = (Font *)DATA_PTR(self);
    font->glyphPadding = glyphPadding;
    return mrb_nil_value();
}

mrb_value mrb_Font_set_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    Font *font = (Font *)DATA_PTR(self);
    font->texture = *texture;
    return mrb_nil_value();
}

mrb_value mrb_Font_set_recs(mrb_state *mrb, mrb_value self)
{
    mrb_value recs;
    mrb_get_args(mrb, "A", &recs);
    Font *font = (Font *)DATA_PTR(self);
    Rectangle recs_values[font->glyphCount];
    for (int i = 0; i < font->glyphCount; ++i)
    {
        recs_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(recs, i), &Raylib_Rectangle_type, Rectangle);
    }
    font->recs = recs_values;
    return mrb_nil_value();
}

mrb_value mrb_Font_set_glyphs(mrb_state *mrb, mrb_value self)
{
    mrb_value glyphs;
    mrb_get_args(mrb, "A", &glyphs);
    Font *font = (Font *)DATA_PTR(self);
    GlyphInfo glyphs_values[font->glyphCount];
    for (int i = 0; i < font->glyphCount; ++i)
    {
        glyphs_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(glyphs, i), &Raylib_GlyphInfo_type, GlyphInfo);
    }
    font->glyphs = glyphs_values;
    return mrb_nil_value();
}

mrb_value mrb_Camera_initialize(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Vector3 *target;
    Vector3 *up;
    mrb_float fovy;
    mrb_int projection;
    mrb_get_args(mrb, "dddfi", &position, &Raylib_Vector3_type, &target, &Raylib_Vector3_type, &up, &Raylib_Vector3_type, &fovy, &projection);

    Camera *camera = (Camera *)DATA_PTR(self);
    if (camera)
    {
        mrb_free(mrb, camera);
    }
    mrb_data_init(self, NULL, &Raylib_Camera_type);
    camera = (Camera *)mrb_malloc(mrb, sizeof(Camera));

    camera->position = *position;
    camera->target = *target;
    camera->up = *up;
    camera->fovy = fovy;
    camera->projection = projection;

    mrb_data_init(self, camera, &Raylib_Camera_type);
    return self;
}

mrb_value mrb_Camera_get_position(mrb_state *mrb, mrb_value self)
{
    Camera *camera = (Camera *)DATA_PTR(self);
    Vector3 *position = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *position = camera->position;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, position));
    return obj;
}

mrb_value mrb_Camera_get_target(mrb_state *mrb, mrb_value self)
{
    Camera *camera = (Camera *)DATA_PTR(self);
    Vector3 *target = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *target = camera->target;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, target));
    return obj;
}

mrb_value mrb_Camera_get_up(mrb_state *mrb, mrb_value self)
{
    Camera *camera = (Camera *)DATA_PTR(self);
    Vector3 *up = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *up = camera->up;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, up));
    return obj;
}

mrb_value mrb_Camera_get_fovy(mrb_state *mrb, mrb_value self)
{
    Camera *camera = (Camera *)DATA_PTR(self);
    return mrb_float_value(mrb, camera->fovy);
}

mrb_value mrb_Camera_get_projection(mrb_state *mrb, mrb_value self)
{
    Camera *camera = (Camera *)DATA_PTR(self);
    return mrb_int_value(mrb, camera->projection);
}

mrb_value mrb_Camera_set_position(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_get_args(mrb, "d", &position, &Raylib_Vector3_type);
    Camera *camera = (Camera *)DATA_PTR(self);
    camera->position = *position;
    return mrb_nil_value();
}

mrb_value mrb_Camera_set_target(mrb_state *mrb, mrb_value self)
{
    Vector3 *target;
    mrb_get_args(mrb, "d", &target, &Raylib_Vector3_type);
    Camera *camera = (Camera *)DATA_PTR(self);
    camera->target = *target;
    return mrb_nil_value();
}

mrb_value mrb_Camera_set_up(mrb_state *mrb, mrb_value self)
{
    Vector3 *up;
    mrb_get_args(mrb, "d", &up, &Raylib_Vector3_type);
    Camera *camera = (Camera *)DATA_PTR(self);
    camera->up = *up;
    return mrb_nil_value();
}

mrb_value mrb_Camera_set_fovy(mrb_state *mrb, mrb_value self)
{
    mrb_float fovy;
    mrb_get_args(mrb, "f", &fovy);
    Camera *camera = (Camera *)DATA_PTR(self);
    camera->fovy = fovy;
    return mrb_nil_value();
}

mrb_value mrb_Camera_set_projection(mrb_state *mrb, mrb_value self)
{
    mrb_float projection;
    mrb_get_args(mrb, "i", &projection);
    Camera *camera = (Camera *)DATA_PTR(self);
    camera->projection = projection;
    return mrb_nil_value();
}

mrb_value mrb_Camera2D_initialize(mrb_state *mrb, mrb_value self)
{
    Vector2 *offset;
    Vector2 *target;
    mrb_float rotation;
    mrb_float zoom;
    mrb_get_args(mrb, "ddff", &offset, &Raylib_Vector2_type, &target, &Raylib_Vector2_type, &rotation, &zoom);

    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    if (camera2d)
    {
        mrb_free(mrb, camera2d);
    }
    mrb_data_init(self, NULL, &Raylib_Camera2D_type);
    camera2d = (Camera2D *)mrb_malloc(mrb, sizeof(Camera2D));

    camera2d->offset = *offset;
    camera2d->target = *target;
    camera2d->rotation = rotation;
    camera2d->zoom = zoom;

    mrb_data_init(self, camera2d, &Raylib_Camera2D_type);
    return self;
}

mrb_value mrb_Camera2D_get_offset(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    Vector2 *offset = (Vector2 *)mrb_malloc(mrb, sizeof(Vector2));
    *offset = camera2d->offset;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, offset));
    return obj;
}

mrb_value mrb_Camera2D_get_target(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    Vector2 *target = (Vector2 *)mrb_malloc(mrb, sizeof(Vector2));
    *target = camera2d->target;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, target));
    return obj;
}

mrb_value mrb_Camera2D_get_rotation(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    return mrb_float_value(mrb, camera2d->rotation);
}

mrb_value mrb_Camera2D_get_zoom(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    return mrb_float_value(mrb, camera2d->zoom);
}

mrb_value mrb_Camera2D_set_offset(mrb_state *mrb, mrb_value self)
{
    Vector2 *offset;
    mrb_get_args(mrb, "d", &offset, &Raylib_Vector2_type);
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    camera2d->offset = *offset;
    return mrb_nil_value();
}

mrb_value mrb_Camera2D_set_target(mrb_state *mrb, mrb_value self)
{
    Vector2 *target;
    mrb_get_args(mrb, "d", &target, &Raylib_Vector2_type);
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    camera2d->target = *target;
    return mrb_nil_value();
}

mrb_value mrb_Camera2D_set_rotation(mrb_state *mrb, mrb_value self)
{
    mrb_float rotation;
    mrb_get_args(mrb, "f", &rotation);
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    camera2d->rotation = rotation;
    return mrb_nil_value();
}

mrb_value mrb_Camera2D_set_zoom(mrb_state *mrb, mrb_value self)
{
    mrb_float zoom;
    mrb_get_args(mrb, "f", &zoom);
    Camera2D *camera2d = (Camera2D *)DATA_PTR(self);
    camera2d->zoom = zoom;
    return mrb_nil_value();
}

mrb_value mrb_Ray_initialize(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Vector3 *direction;
    mrb_get_args(mrb, "dd", &position, &Raylib_Vector3_type, &direction, &Raylib_Vector3_type);

    Ray *ray = (Ray *)DATA_PTR(self);
    if (ray)
    {
        mrb_free(mrb, ray);
    }
    mrb_data_init(self, NULL, &Raylib_Ray_type);
    ray = (Ray *)mrb_malloc(mrb, sizeof(Ray));

    ray->position = *position;
    ray->direction = *direction;

    mrb_data_init(self, ray, &Raylib_Ray_type);
    return self;
}

mrb_value mrb_Ray_get_position(mrb_state *mrb, mrb_value self)
{
    Ray *ray = (Ray *)DATA_PTR(self);
    Vector3 *position = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *position = ray->position;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, position));
    return obj;
}

mrb_value mrb_Ray_get_direction(mrb_state *mrb, mrb_value self)
{
    Ray *ray = (Ray *)DATA_PTR(self);
    Vector3 *direction = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *direction = ray->direction;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, direction));
    return obj;
}

mrb_value mrb_Ray_set_position(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_get_args(mrb, "d", &position, &Raylib_Vector3_type);
    Ray *ray = (Ray *)DATA_PTR(self);
    ray->position = *position;
    return mrb_nil_value();
}

mrb_value mrb_Ray_set_direction(mrb_state *mrb, mrb_value self)
{
    Vector3 *direction;
    mrb_get_args(mrb, "d", &direction, &Raylib_Vector3_type);
    Ray *ray = (Ray *)DATA_PTR(self);
    ray->direction = *direction;
    return mrb_nil_value();
}

mrb_value mrb_RayCollision_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_bool hit;
    mrb_float distance;
    Vector3 *point;
    Vector3 *normal;
    mrb_get_args(mrb, "bfdd", &hit, &distance, &point, &Raylib_Vector3_type, &normal, &Raylib_Vector3_type);

    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    if (raycollision)
    {
        mrb_free(mrb, raycollision);
    }
    mrb_data_init(self, NULL, &Raylib_RayCollision_type);
    raycollision = (RayCollision *)mrb_malloc(mrb, sizeof(RayCollision));

    raycollision->hit = hit;
    raycollision->distance = distance;
    raycollision->point = *point;
    raycollision->normal = *normal;

    mrb_data_init(self, raycollision, &Raylib_RayCollision_type);
    return self;
}

mrb_value mrb_RayCollision_get_hit(mrb_state *mrb, mrb_value self)
{
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    return mrb_bool_value(raycollision->hit);
}

mrb_value mrb_RayCollision_get_distance(mrb_state *mrb, mrb_value self)
{
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    return mrb_float_value(mrb, raycollision->distance);
}

mrb_value mrb_RayCollision_get_point(mrb_state *mrb, mrb_value self)
{
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    Vector3 *point = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *point = raycollision->point;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, point));
    return obj;
}

mrb_value mrb_RayCollision_get_normal(mrb_state *mrb, mrb_value self)
{
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    Vector3 *normal = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *normal = raycollision->normal;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, normal));
    return obj;
}

mrb_value mrb_RayCollision_set_hit(mrb_state *mrb, mrb_value self)
{
    mrb_bool hit;
    mrb_get_args(mrb, "b", &hit);
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    raycollision->hit = hit;
    return mrb_nil_value();
}

mrb_value mrb_RayCollision_set_distance(mrb_state *mrb, mrb_value self)
{
    mrb_float distance;
    mrb_get_args(mrb, "f", &distance);
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    raycollision->distance = distance;
    return mrb_nil_value();
}

mrb_value mrb_RayCollision_set_point(mrb_state *mrb, mrb_value self)
{
    Vector3 *point;
    mrb_get_args(mrb, "d", &point, &Raylib_Vector3_type);
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    raycollision->point = *point;
    return mrb_nil_value();
}

mrb_value mrb_RayCollision_set_normal(mrb_state *mrb, mrb_value self)
{
    Vector3 *normal;
    mrb_get_args(mrb, "d", &normal, &Raylib_Vector3_type);
    RayCollision *raycollision = (RayCollision *)DATA_PTR(self);
    raycollision->normal = *normal;
    return mrb_nil_value();
}

mrb_value mrb_BoundingBox_initialize(mrb_state *mrb, mrb_value self)
{
    Vector3 *min;
    Vector3 *max;
    mrb_get_args(mrb, "dd", &min, &Raylib_Vector3_type, &max, &Raylib_Vector3_type);

    BoundingBox *boundingbox = (BoundingBox *)DATA_PTR(self);
    if (boundingbox)
    {
        mrb_free(mrb, boundingbox);
    }
    mrb_data_init(self, NULL, &Raylib_BoundingBox_type);
    boundingbox = (BoundingBox *)mrb_malloc(mrb, sizeof(BoundingBox));

    boundingbox->min = *min;
    boundingbox->max = *max;

    mrb_data_init(self, boundingbox, &Raylib_BoundingBox_type);
    return self;
}

mrb_value mrb_BoundingBox_get_min(mrb_state *mrb, mrb_value self)
{
    BoundingBox *boundingbox = (BoundingBox *)DATA_PTR(self);
    Vector3 *min = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *min = boundingbox->min;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, min));
    return obj;
}

mrb_value mrb_BoundingBox_get_max(mrb_state *mrb, mrb_value self)
{
    BoundingBox *boundingbox = (BoundingBox *)DATA_PTR(self);
    Vector3 *max = (Vector3 *)mrb_malloc(mrb, sizeof(Vector3));
    *max = boundingbox->max;
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, max));
    return obj;
}

mrb_value mrb_BoundingBox_set_min(mrb_state *mrb, mrb_value self)
{
    Vector3 *min;
    mrb_get_args(mrb, "d", &min, &Raylib_Vector3_type);
    BoundingBox *boundingbox = (BoundingBox *)DATA_PTR(self);
    boundingbox->min = *min;
    return mrb_nil_value();
}

mrb_value mrb_BoundingBox_set_max(mrb_state *mrb, mrb_value self)
{
    Vector3 *max;
    mrb_get_args(mrb, "d", &max, &Raylib_Vector3_type);
    BoundingBox *boundingbox = (BoundingBox *)DATA_PTR(self);
    boundingbox->max = *max;
    return mrb_nil_value();
}

mrb_value mrb_FilePathList_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int capacity;
    mrb_int count;
    mrb_value paths;
    mrb_get_args(mrb, "iiA", &capacity, &count, &paths);

    FilePathList *filepathlist = (FilePathList *)DATA_PTR(self);
    if (filepathlist)
    {
        mrb_free(mrb, filepathlist);
    }
    mrb_data_init(self, NULL, &Raylib_FilePathList_type);
    filepathlist = (FilePathList *)mrb_malloc(mrb, sizeof(FilePathList));

    filepathlist->capacity = capacity;
    filepathlist->count = count;
    
    char *path_values[count];
    for (int i = 0; i < count; ++i)
    {
        path_values[i] = (char *)mrb_string_cstr(mrb, mrb_ary_entry(paths, i));
    }
    filepathlist->paths = path_values;


    mrb_data_init(self, filepathlist, &Raylib_FilePathList_type);
    return self;
}

mrb_value mrb_FilePathList_get_capacity(mrb_state *mrb, mrb_value self)
{
    FilePathList *filepathlist = (FilePathList *)DATA_PTR(self);
    return mrb_int_value(mrb, filepathlist->capacity);
}

mrb_value mrb_FilePathList_get_count(mrb_state *mrb, mrb_value self)
{
    FilePathList *filepathlist = (FilePathList *)DATA_PTR(self);
    return mrb_int_value(mrb, filepathlist->count);
}

mrb_value mrb_FilePathList_get_paths(mrb_state *mrb, mrb_value self)
{
    FilePathList *filepathlist = (FilePathList *)DATA_PTR(self);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < filepathlist->count; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_str_new_cstr(mrb, filepathlist->paths[i]));
    }
    return ary;
}

mrb_value mrb_FilePathList_set_capacity(mrb_state *mrb, mrb_value self)
{
    mrb_int capacity;
    mrb_get_args(mrb, "i", &capacity);
    FilePathList *filepathlist = (FilePathList *)DATA_PTR(self);
    filepathlist->capacity = capacity;
    return mrb_nil_value();
}

mrb_value mrb_FilePathList_set_count(mrb_state *mrb, mrb_value self)
{
    mrb_int count;
    mrb_get_args(mrb, "i", &count);
    FilePathList *filepathlist = (FilePathList *)DATA_PTR(self);
    filepathlist->count = count;
    return mrb_nil_value();
}

mrb_value mrb_FilePathList_set_paths(mrb_state *mrb, mrb_value self)
{
    mrb_value paths;
    mrb_get_args(mrb, "A", &paths);
    char *path_values[RARRAY_LEN(paths)];
    for (int i = 0; i < RARRAY_LEN(paths); ++i)
    {
        path_values[i] = (char *)mrb_string_cstr(mrb, mrb_ary_entry(paths, i));
    }
    FilePathList *filepathlist = (FilePathList *)DATA_PTR(self);
    filepathlist->paths = path_values;
    return mrb_nil_value();
}

mrb_value mrb_AutomationEvent_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int frame;
    mrb_int type;
    mrb_value params;
    mrb_get_args(mrb, "iiA", &frame, &type, &params);

    AutomationEvent *automationevent = (AutomationEvent *)DATA_PTR(self);
    if (automationevent)
    {
        mrb_free(mrb, automationevent);
    }
    mrb_data_init(self, NULL, &Raylib_AutomationEvent_type);
    automationevent = (AutomationEvent *)mrb_malloc(mrb, sizeof(AutomationEvent));

    automationevent->frame = frame;
    automationevent->type = type;
    
    int params_values[4];
    for (int i = 0; i < 4; ++i)
    { 
        params_values[i] = mrb_int(mrb, mrb_ary_entry(params, i));
    }
    *automationevent->params = *params_values;


    mrb_data_init(self, automationevent, &Raylib_AutomationEvent_type);
    return self;
}

mrb_value mrb_AutomationEvent_get_frame(mrb_state *mrb, mrb_value self)
{
    AutomationEvent *automationevent = (AutomationEvent *)DATA_PTR(self);
    return mrb_int_value(mrb, automationevent->frame);
}

mrb_value mrb_AutomationEvent_get_type(mrb_state *mrb, mrb_value self)
{
    AutomationEvent *automationevent = (AutomationEvent *)DATA_PTR(self);
    return mrb_int_value(mrb, automationevent->type);
}

mrb_value mrb_AutomationEvent_get_params(mrb_state *mrb, mrb_value self)
{
    AutomationEvent *automationevent = (AutomationEvent *)DATA_PTR(self);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < 4; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_int_value(mrb, automationevent->params[i]));
    }
    return ary;
}

mrb_value mrb_AutomationEvent_set_frame(mrb_state *mrb, mrb_value self)
{
    mrb_int frame;
    mrb_get_args(mrb, "i", &frame);
    AutomationEvent *automationevent = (AutomationEvent *)DATA_PTR(self);
    automationevent->frame = frame;
    return mrb_nil_value();
}

mrb_value mrb_AutomationEvent_set_type(mrb_state *mrb, mrb_value self)
{
    mrb_int type;
    mrb_get_args(mrb, "i", &type);
    AutomationEvent *automationevent = (AutomationEvent *)DATA_PTR(self);
    automationevent->type = type;
    return mrb_nil_value();
}

mrb_value mrb_AutomationEvent_set_params(mrb_state *mrb, mrb_value self)
{
    mrb_value params;
    mrb_get_args(mrb, "A", &params);
    int param_values[4];
    for (int i = 0; i < 4; ++i)
    {
        param_values[i] = mrb_int(mrb, mrb_ary_entry(params, i));
    }
    AutomationEvent *automationevent = (AutomationEvent *)DATA_PTR(self);
    *automationevent->params = *param_values;
    return mrb_nil_value();
}

mrb_value mrb_AutomationEventList_initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int capacity;
    mrb_int count;
    mrb_value events;
    mrb_get_args(mrb, "iiA", &capacity, &count, &events);

    AutomationEventList *automationeventlist = (AutomationEventList *)DATA_PTR(self);
    if (automationeventlist)
    {
        mrb_free(mrb, automationeventlist);
    }
    mrb_data_init(self, NULL, &Raylib_AutomationEventList_type);
    automationeventlist = (AutomationEventList *)mrb_malloc(mrb, sizeof(AutomationEventList));

    automationeventlist->capacity = capacity;
    automationeventlist->count = count;
    
    AutomationEvent events_values[count];
    for (int i = 0; i < count; ++i)
    {
        events_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(events, i), &Raylib_AutomationEvent_type, AutomationEvent);
    }
    automationeventlist->events = events_values;


    mrb_data_init(self, automationeventlist, &Raylib_AutomationEventList_type);
    return self;
}

mrb_value mrb_AutomationEventList_get_capacity(mrb_state *mrb, mrb_value self)
{
    AutomationEventList *automationeventlist = (AutomationEventList *)DATA_PTR(self);
    return mrb_int_value(mrb, automationeventlist->capacity);
}

mrb_value mrb_AutomationEventList_get_count(mrb_state *mrb, mrb_value self)
{
    AutomationEventList *automationeventlist = (AutomationEventList *)DATA_PTR(self);
    return mrb_int_value(mrb, automationeventlist->count);
}

mrb_value mrb_AutomationEventList_get_events(mrb_state *mrb, mrb_value self)
{
    AutomationEventList *automationeventlist = (AutomationEventList *)DATA_PTR(self);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < automationeventlist->count; ++i)
    {
        AutomationEvent *automationevent = (AutomationEvent *)malloc(sizeof(AutomationEvent));
        *automationevent = automationeventlist->events[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_AutomationEvent_class, &Raylib_AutomationEvent_type, automationevent)));
    }
    return ary;
}

mrb_value mrb_AutomationEventList_set_capacity(mrb_state *mrb, mrb_value self)
{
    mrb_int capacity;
    mrb_get_args(mrb, "i", &capacity);
    AutomationEventList *automationeventlist = (AutomationEventList *)DATA_PTR(self);
    automationeventlist->capacity = capacity;
    return mrb_nil_value();
}

mrb_value mrb_AutomationEventList_set_count(mrb_state *mrb, mrb_value self)
{
    mrb_int count;
    mrb_get_args(mrb, "i", &count);
    AutomationEventList *automationeventlist = (AutomationEventList *)DATA_PTR(self);
    automationeventlist->count = count;
    return mrb_nil_value();
}

mrb_value mrb_AutomationEventList_set_events(mrb_state *mrb, mrb_value self)
{
    mrb_value events;
    mrb_get_args(mrb, "A", &events);
    AutomationEvent event_values[RARRAY_LEN(events)];
    for (int i = 0; i < RARRAY_LEN(events); ++i)
    {
        event_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(events, i), &Raylib_AutomationEvent_type, AutomationEvent);
    }
    AutomationEventList *automationeventlist = (AutomationEventList *)DATA_PTR(self);
    automationeventlist->events = event_values;
    return mrb_nil_value();
}

void mrb_raylib_setup_structs(mrb_state *mrb, struct RClass *raylib_module)
{

    Raylib_Vector2_class = mrb_define_class_under(mrb, raylib_module, "Vector2", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Vector2_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Vector2_class, "initialize", mrb_Vector2_initialize, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, Raylib_Vector2_class, "x=", mrb_Vector2_set_x, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector2_class, "y=", mrb_Vector2_set_y, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector2_class, "x", mrb_Vector2_get_x, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Vector2_class, "y", mrb_Vector2_get_y, MRB_ARGS_NONE());

    Raylib_Vector3_class = mrb_define_class_under(mrb, raylib_module, "Vector3", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Vector3_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Vector3_class, "initialize", mrb_Vector3_initialize, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, Raylib_Vector3_class, "x=", mrb_Vector3_set_x, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector3_class, "y=", mrb_Vector3_set_y, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector3_class, "z=", mrb_Vector3_set_z, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector3_class, "x", mrb_Vector3_get_x, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Vector3_class, "y", mrb_Vector3_get_y, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Vector3_class, "z", mrb_Vector3_get_z, MRB_ARGS_NONE());

    Raylib_Vector4_class = mrb_define_class_under(mrb, raylib_module, "Vector4", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Vector4_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Vector4_class, "initialize", mrb_Vector4_initialize, MRB_ARGS_REQ(4));
    mrb_define_method(mrb, Raylib_Vector4_class, "x=", mrb_Vector4_set_x, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector4_class, "y=", mrb_Vector4_set_y, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector4_class, "z=", mrb_Vector4_set_z, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector4_class, "w=", mrb_Vector4_set_w, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Vector4_class, "x", mrb_Vector4_get_x, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Vector4_class, "y", mrb_Vector4_get_y, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Vector4_class, "z", mrb_Vector4_get_z, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Vector4_class, "w", mrb_Vector4_get_w, MRB_ARGS_NONE());

    Raylib_Matrix_class = mrb_define_class_under(mrb, raylib_module, "Matrix", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Matrix_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Matrix_class, "initialize", mrb_Matrix_initialize, MRB_ARGS_REQ(16));
    mrb_define_method(mrb, Raylib_Matrix_class, "m0=", mrb_Matrix_set_m0, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m1=", mrb_Matrix_set_m1, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m2=", mrb_Matrix_set_m2, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m3=", mrb_Matrix_set_m3, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m4=", mrb_Matrix_set_m4, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m5=", mrb_Matrix_set_m5, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m6=", mrb_Matrix_set_m6, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m7=", mrb_Matrix_set_m7, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m8=", mrb_Matrix_set_m8, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m9=", mrb_Matrix_set_m9, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m10=", mrb_Matrix_set_m10, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m11=", mrb_Matrix_set_m11, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m12=", mrb_Matrix_set_m12, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m13=", mrb_Matrix_set_m13, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m14=", mrb_Matrix_set_m14, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m15=", mrb_Matrix_set_m15, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Matrix_class, "m0", mrb_Matrix_get_m0, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m1", mrb_Matrix_get_m1, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m2", mrb_Matrix_get_m2, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m3", mrb_Matrix_get_m3, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m4", mrb_Matrix_get_m4, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m5", mrb_Matrix_get_m5, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m6", mrb_Matrix_get_m6, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m7", mrb_Matrix_get_m7, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m8", mrb_Matrix_get_m8, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m9", mrb_Matrix_get_m9, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m10", mrb_Matrix_get_m10, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m11", mrb_Matrix_get_m11, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m12", mrb_Matrix_get_m12, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m13", mrb_Matrix_get_m13, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m14", mrb_Matrix_get_m14, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Matrix_class, "m15", mrb_Matrix_get_m15, MRB_ARGS_NONE());

    Raylib_Color_class = mrb_define_class_under(mrb, raylib_module, "Color", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Color_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Color_class, "initialize", mrb_Color_initialize, MRB_ARGS_REQ(4));
    mrb_define_method(mrb, Raylib_Color_class, "r=", mrb_Color_set_r, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Color_class, "g=", mrb_Color_set_g, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Color_class, "b=", mrb_Color_set_b, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Color_class, "a=", mrb_Color_set_a, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Color_class, "r", mrb_Color_get_r, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Color_class, "g", mrb_Color_get_g, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Color_class, "b", mrb_Color_get_b, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Color_class, "a", mrb_Color_get_a, MRB_ARGS_NONE());

    Raylib_Rectangle_class = mrb_define_class_under(mrb, raylib_module, "Rectangle", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Rectangle_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Rectangle_class, "initialize", mrb_Rectangle_initialize, MRB_ARGS_REQ(4));
    mrb_define_method(mrb, Raylib_Rectangle_class, "x=", mrb_Rectangle_set_x, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Rectangle_class, "y=", mrb_Rectangle_set_y, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Rectangle_class, "width=", mrb_Rectangle_set_width, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Rectangle_class, "height=", mrb_Rectangle_set_height, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Rectangle_class, "x", mrb_Rectangle_get_x, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Rectangle_class, "y", mrb_Rectangle_get_y, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Rectangle_class, "width", mrb_Rectangle_get_width, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Rectangle_class, "height", mrb_Rectangle_get_height, MRB_ARGS_NONE());

    Raylib_Image_class = mrb_define_class_under(mrb, raylib_module, "Image", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Image_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Image_class, "initialize", mrb_Image_initialize, MRB_ARGS_REQ(4));
    mrb_define_method(mrb, Raylib_Image_class, "format=", mrb_Image_set_format, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Image_class, "width=", mrb_Image_set_width, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Image_class, "height=", mrb_Image_set_height, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Image_class, "mipmaps=", mrb_Image_set_mipmaps, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Image_class, "format", mrb_Image_get_format, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Image_class, "width", mrb_Image_get_width, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Image_class, "height", mrb_Image_get_height, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Image_class, "mipmaps", mrb_Image_get_mipmaps, MRB_ARGS_NONE());

    Raylib_Texture_class = mrb_define_class_under(mrb, raylib_module, "Texture", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Texture_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Texture_class, "initialize", mrb_Texture_initialize, MRB_ARGS_REQ(5));
    mrb_define_method(mrb, Raylib_Texture_class, "id=", mrb_Texture_set_id, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Texture_class, "format=", mrb_Texture_set_format, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Texture_class, "width=", mrb_Texture_set_width, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Texture_class, "height=", mrb_Texture_set_height, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Texture_class, "mipmaps=", mrb_Texture_set_mipmaps, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Texture_class, "id", mrb_Texture_get_id, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Texture_class, "format", mrb_Texture_get_format, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Texture_class, "width", mrb_Texture_get_width, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Texture_class, "height", mrb_Texture_get_height, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Texture_class, "mipmaps", mrb_Texture_get_mipmaps, MRB_ARGS_NONE());

    Raylib_RenderTexture_class = mrb_define_class_under(mrb, raylib_module, "RenderTexture", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_RenderTexture_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_RenderTexture_class, "initialize", mrb_RenderTexture_initialize, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, Raylib_RenderTexture_class, "id=", mrb_RenderTexture_set_id, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_RenderTexture_class, "texture=", mrb_RenderTexture_set_texture, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_RenderTexture_class, "depth=", mrb_RenderTexture_set_depth, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_RenderTexture_class, "id", mrb_RenderTexture_get_id, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_RenderTexture_class, "texture", mrb_RenderTexture_get_texture, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_RenderTexture_class, "depth", mrb_RenderTexture_get_depth, MRB_ARGS_NONE());

    Raylib_NPatchInfo_class = mrb_define_class_under(mrb, raylib_module, "NPatchInfo", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_NPatchInfo_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "initialize", mrb_NPatchInfo_initialize, MRB_ARGS_REQ(6));
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "source=", mrb_NPatchInfo_set_source, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "top=", mrb_NPatchInfo_set_top, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "left=", mrb_NPatchInfo_set_left, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "right=", mrb_NPatchInfo_set_right, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "bottom=", mrb_NPatchInfo_set_bottom, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "layout=", mrb_NPatchInfo_set_layout, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "source", mrb_NPatchInfo_get_source, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "top", mrb_NPatchInfo_get_top, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "left", mrb_NPatchInfo_get_left, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "right", mrb_NPatchInfo_get_right, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "bottom", mrb_NPatchInfo_get_bottom, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_NPatchInfo_class, "layout", mrb_NPatchInfo_get_layout, MRB_ARGS_NONE());

    Raylib_GlyphInfo_class = mrb_define_class_under(mrb, raylib_module, "GlyphInfo", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_GlyphInfo_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "initialize", mrb_GlyphInfo_initialize, MRB_ARGS_REQ(5));
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "value=", mrb_GlyphInfo_set_value, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "offset_x=", mrb_GlyphInfo_set_offsetX, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "offset_y=", mrb_GlyphInfo_set_offsetY, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "advance_x=", mrb_GlyphInfo_set_advanceX, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "image=", mrb_GlyphInfo_set_image, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "value", mrb_GlyphInfo_get_value, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "offset_x", mrb_GlyphInfo_get_offsetX, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "offset_y", mrb_GlyphInfo_get_offsetY, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "advance_x", mrb_GlyphInfo_get_advanceX, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_GlyphInfo_class, "image", mrb_GlyphInfo_get_image, MRB_ARGS_NONE());

    Raylib_Font_class = mrb_define_class_under(mrb, raylib_module, "Font", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Font_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Font_class, "initialize", mrb_Font_initialize, MRB_ARGS_REQ(6));
    mrb_define_method(mrb, Raylib_Font_class, "base_size=", mrb_Font_set_baseSize, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Font_class, "glyph_count=", mrb_Font_set_glyphCount, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Font_class, "glyph_padding=", mrb_Font_set_glyphPadding, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Font_class, "texture=", mrb_Font_set_texture, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Font_class, "recs=", mrb_Font_set_recs, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Font_class, "glyphs=", mrb_Font_set_glyphs, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Font_class, "base_size", mrb_Font_get_baseSize, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Font_class, "glyph_count", mrb_Font_get_glyphCount, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Font_class, "glyph_padding", mrb_Font_get_glyphPadding, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Font_class, "texture", mrb_Font_get_texture, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Font_class, "recs", mrb_Font_get_recs, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Font_class, "glyphs", mrb_Font_get_glyphs, MRB_ARGS_NONE());

    Raylib_Camera_class = mrb_define_class_under(mrb, raylib_module, "Camera", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Camera_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Camera_class, "initialize", mrb_Camera_initialize, MRB_ARGS_REQ(5));
    mrb_define_method(mrb, Raylib_Camera_class, "position=", mrb_Camera_set_position, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera_class, "target=", mrb_Camera_set_target, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera_class, "up=", mrb_Camera_set_up, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera_class, "fovy=", mrb_Camera_set_fovy, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera_class, "projection=", mrb_Camera_set_projection, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera_class, "position", mrb_Camera_get_position, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Camera_class, "target", mrb_Camera_get_target, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Camera_class, "up", mrb_Camera_get_up, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Camera_class, "fovy", mrb_Camera_get_fovy, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Camera_class, "projection", mrb_Camera_get_projection, MRB_ARGS_NONE());

    Raylib_Camera2D_class = mrb_define_class_under(mrb, raylib_module, "Camera2D", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Camera2D_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Camera2D_class, "initialize", mrb_Camera2D_initialize, MRB_ARGS_REQ(4));
    mrb_define_method(mrb, Raylib_Camera2D_class, "offset=", mrb_Camera2D_set_offset, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera2D_class, "target=", mrb_Camera2D_set_target, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera2D_class, "rotation=", mrb_Camera2D_set_rotation, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera2D_class, "zoom=", mrb_Camera2D_set_zoom, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Camera2D_class, "offset", mrb_Camera2D_get_offset, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Camera2D_class, "target", mrb_Camera2D_get_target, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Camera2D_class, "rotation", mrb_Camera2D_get_rotation, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Camera2D_class, "zoom", mrb_Camera2D_get_zoom, MRB_ARGS_NONE());

    Raylib_Mesh_class = mrb_define_class_under(mrb, raylib_module, "Mesh", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Mesh_class, MRB_TT_CDATA);

    Raylib_Shader_class = mrb_define_class_under(mrb, raylib_module, "Shader", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Shader_class, MRB_TT_CDATA);

    Raylib_MaterialMap_class = mrb_define_class_under(mrb, raylib_module, "MaterialMap", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_MaterialMap_class, MRB_TT_CDATA);

    Raylib_Material_class = mrb_define_class_under(mrb, raylib_module, "Material", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Material_class, MRB_TT_CDATA);

    Raylib_Transform_class = mrb_define_class_under(mrb, raylib_module, "Transform", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Transform_class, MRB_TT_CDATA);

    Raylib_BoneInfo_class = mrb_define_class_under(mrb, raylib_module, "BoneInfo", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_BoneInfo_class, MRB_TT_CDATA);

    Raylib_Model_class = mrb_define_class_under(mrb, raylib_module, "Model", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Model_class, MRB_TT_CDATA);

    Raylib_ModelAnimation_class = mrb_define_class_under(mrb, raylib_module, "ModelAnimation", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_ModelAnimation_class, MRB_TT_CDATA);

    Raylib_Ray_class = mrb_define_class_under(mrb, raylib_module, "Ray", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Ray_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_Ray_class, "initialize", mrb_Ray_initialize, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, Raylib_Ray_class, "position=", mrb_Ray_set_position, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Ray_class, "direction=", mrb_Ray_set_direction, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_Ray_class, "position", mrb_Ray_get_position, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_Ray_class, "direction", mrb_Ray_get_direction, MRB_ARGS_NONE());

    Raylib_RayCollision_class = mrb_define_class_under(mrb, raylib_module, "RayCollision", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_RayCollision_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_RayCollision_class, "initialize", mrb_RayCollision_initialize, MRB_ARGS_REQ(4));
    mrb_define_method(mrb, Raylib_RayCollision_class, "hit=", mrb_RayCollision_set_hit, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_RayCollision_class, "distance=", mrb_RayCollision_set_distance, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_RayCollision_class, "point=", mrb_RayCollision_set_point, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_RayCollision_class, "normal=", mrb_RayCollision_set_normal, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_RayCollision_class, "hit", mrb_RayCollision_get_hit, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_RayCollision_class, "distance", mrb_RayCollision_get_distance, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_RayCollision_class, "point", mrb_RayCollision_get_point, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_RayCollision_class, "normal", mrb_RayCollision_get_normal, MRB_ARGS_NONE());

    Raylib_BoundingBox_class = mrb_define_class_under(mrb, raylib_module, "BoundingBox", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_BoundingBox_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_BoundingBox_class, "initialize", mrb_BoundingBox_initialize, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, Raylib_BoundingBox_class, "min=", mrb_BoundingBox_set_min, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_BoundingBox_class, "max=", mrb_BoundingBox_set_max, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_BoundingBox_class, "min", mrb_BoundingBox_get_min, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_BoundingBox_class, "max", mrb_BoundingBox_get_max, MRB_ARGS_NONE());

    Raylib_Wave_class = mrb_define_class_under(mrb, raylib_module, "Wave", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Wave_class, MRB_TT_CDATA);

    Raylib_AudioStream_class = mrb_define_class_under(mrb, raylib_module, "AudioStream", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_AudioStream_class, MRB_TT_CDATA);

    Raylib_Sound_class = mrb_define_class_under(mrb, raylib_module, "Sound", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Sound_class, MRB_TT_CDATA);

    Raylib_Music_class = mrb_define_class_under(mrb, raylib_module, "Music", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_Music_class, MRB_TT_CDATA);

    Raylib_VrDeviceInfo_class = mrb_define_class_under(mrb, raylib_module, "VrDeviceInfo", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_VrDeviceInfo_class, MRB_TT_CDATA);

    Raylib_VrStereoConfig_class = mrb_define_class_under(mrb, raylib_module, "VrStereoConfig", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_VrStereoConfig_class, MRB_TT_CDATA);

    Raylib_FilePathList_class = mrb_define_class_under(mrb, raylib_module, "FilePathList", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_FilePathList_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_FilePathList_class, "initialize", mrb_FilePathList_initialize, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, Raylib_FilePathList_class, "capacity=", mrb_FilePathList_set_capacity, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_FilePathList_class, "count=", mrb_FilePathList_set_count, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_FilePathList_class, "paths=", mrb_FilePathList_set_paths, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_FilePathList_class, "capacity", mrb_FilePathList_get_capacity, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_FilePathList_class, "count", mrb_FilePathList_get_count, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_FilePathList_class, "paths", mrb_FilePathList_get_paths, MRB_ARGS_NONE());

    Raylib_AutomationEvent_class = mrb_define_class_under(mrb, raylib_module, "AutomationEvent", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_AutomationEvent_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_AutomationEvent_class, "initialize", mrb_AutomationEvent_initialize, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, Raylib_AutomationEvent_class, "frame=", mrb_AutomationEvent_set_frame, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_AutomationEvent_class, "type=", mrb_AutomationEvent_set_type, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_AutomationEvent_class, "params=", mrb_AutomationEvent_set_params, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_AutomationEvent_class, "frame", mrb_AutomationEvent_get_frame, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_AutomationEvent_class, "type", mrb_AutomationEvent_get_type, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_AutomationEvent_class, "params", mrb_AutomationEvent_get_params, MRB_ARGS_NONE());

    Raylib_AutomationEventList_class = mrb_define_class_under(mrb, raylib_module, "AutomationEventList", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_AutomationEventList_class, MRB_TT_CDATA);
    mrb_define_method(mrb, Raylib_AutomationEventList_class, "initialize", mrb_AutomationEventList_initialize, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, Raylib_AutomationEventList_class, "capacity=", mrb_AutomationEventList_set_capacity, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_AutomationEventList_class, "count=", mrb_AutomationEventList_set_count, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_AutomationEventList_class, "events=", mrb_AutomationEventList_set_events, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, Raylib_AutomationEventList_class, "capacity", mrb_AutomationEventList_get_capacity, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_AutomationEventList_class, "count", mrb_AutomationEventList_get_count, MRB_ARGS_NONE());
    mrb_define_method(mrb, Raylib_AutomationEventList_class, "events", mrb_AutomationEventList_get_events, MRB_ARGS_NONE());
}

//-------
// Audio Device Management Functions
//-------

// InitAudioDevice
mrb_value mrb_init_audio_device(mrb_state *mrb, mrb_value self)
{
    InitAudioDevice();
    return mrb_nil_value();
}

// CloseAudioDevice
mrb_value mrb_close_audio_device(mrb_state *mrb, mrb_value self)
{
    CloseAudioDevice();
    return mrb_nil_value();
}

// IsAudioDeviceReady
mrb_value mrb_is_audio_device_ready(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsAudioDeviceReady());
}

// SetMasterVolume
mrb_value mrb_set_master_volume(mrb_state *mrb, mrb_value self)
{
    mrb_float volume;
    mrb_get_args(mrb, "f", &volume);
    SetMasterVolume(volume);
    return mrb_nil_value();
}

// GetMasterVolume
mrb_value mrb_get_master_volume(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetMasterVolume());
}

void mrb_raylib_setup_audio_device_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "init_audio_device", mrb_init_audio_device, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "close_audio_device", mrb_close_audio_device, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_audio_device_ready?", mrb_is_audio_device_ready, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_master_volume", mrb_set_master_volume, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_master_volume", mrb_get_master_volume, MRB_ARGS_NONE());
}

//-------
// AudioStream Management Functions
//-------

// LoadAudioStream
mrb_value mrb_load_audio_stream(mrb_state *mrb, mrb_value self)
{
    mrb_int samplerate;
    mrb_int samplesize;
    mrb_int channels;
    mrb_get_args(mrb, "iii", &samplerate, &samplesize, &channels);
    AudioStream *out = (AudioStream *)malloc(sizeof(AudioStream));
    *out = LoadAudioStream(samplerate, samplesize, channels);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_AudioStream_class, &Raylib_AudioStream_type, out));

    return obj;
}

// IsAudioStreamReady
mrb_value mrb_is_audio_stream_ready(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    return mrb_bool_value(IsAudioStreamReady(*audiostream));
}

// UnloadAudioStream
mrb_value mrb_unload_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    UnloadAudioStream(*audiostream);
    return mrb_nil_value();
}

// IsAudioStreamProcessed
mrb_value mrb_is_audio_stream_processed(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    return mrb_bool_value(IsAudioStreamProcessed(*audiostream));
}

// PlayAudioStream
mrb_value mrb_play_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    PlayAudioStream(*audiostream);
    return mrb_nil_value();
}

// PauseAudioStream
mrb_value mrb_pause_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    PauseAudioStream(*audiostream);
    return mrb_nil_value();
}

// ResumeAudioStream
mrb_value mrb_resume_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    ResumeAudioStream(*audiostream);
    return mrb_nil_value();
}

// IsAudioStreamPlaying
mrb_value mrb_is_audio_stream_playing(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    return mrb_bool_value(IsAudioStreamPlaying(*audiostream));
}

// StopAudioStream
mrb_value mrb_stop_audio_stream(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_get_args(mrb, "d", &audiostream, &Raylib_AudioStream_type);
    StopAudioStream(*audiostream);
    return mrb_nil_value();
}

// SetAudioStreamVolume
mrb_value mrb_set_audio_stream_volume(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_float volume;
    mrb_get_args(mrb, "df", &audiostream, &Raylib_AudioStream_type, &volume);
    SetAudioStreamVolume(*audiostream, volume);
    return mrb_nil_value();
}

// SetAudioStreamPitch
mrb_value mrb_set_audio_stream_pitch(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_float pitch;
    mrb_get_args(mrb, "df", &audiostream, &Raylib_AudioStream_type, &pitch);
    SetAudioStreamPitch(*audiostream, pitch);
    return mrb_nil_value();
}

// SetAudioStreamPan
mrb_value mrb_set_audio_stream_pan(mrb_state *mrb, mrb_value self)
{
    AudioStream *audiostream;
    mrb_float pan;
    mrb_get_args(mrb, "df", &audiostream, &Raylib_AudioStream_type, &pan);
    SetAudioStreamPan(*audiostream, pan);
    return mrb_nil_value();
}

// SetAudioStreamBufferSizeDefault
mrb_value mrb_set_audio_stream_buffer_size_default(mrb_state *mrb, mrb_value self)
{
    mrb_int size;
    mrb_get_args(mrb, "i", &size);
    SetAudioStreamBufferSizeDefault(size);
    return mrb_nil_value();
}

void mrb_raylib_setup_audiostream_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_audio_stream", mrb_load_audio_stream, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "is_audio_stream_ready?", mrb_is_audio_stream_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_audio_stream", mrb_unload_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_audio_stream_processed?", mrb_is_audio_stream_processed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "play_audio_stream", mrb_play_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "pause_audio_stream", mrb_pause_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "resume_audio_stream", mrb_resume_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_audio_stream_playing?", mrb_is_audio_stream_playing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "stop_audio_stream", mrb_stop_audio_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_volume", mrb_set_audio_stream_volume, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_pitch", mrb_set_audio_stream_pitch, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_pan", mrb_set_audio_stream_pan, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_audio_stream_buffer_size_default", mrb_set_audio_stream_buffer_size_default, MRB_ARGS_REQ(2));
}

//-------
// Music Management Functions
//-------

// LoadMusicStream
mrb_value mrb_load_music_stream(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Music *out = (Music *)malloc(sizeof(Music));
    *out = LoadMusicStream(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Music_class, &Raylib_Music_type, out));

    return obj;
}

// LoadMusicStreamFromMemory
mrb_value mrb_load_music_stream_from_memory(mrb_state *mrb, mrb_value self)
{
    const char *filetype;
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_get_args(mrb, "zzi", &filetype, &filedata, &datasize);
    Music *out = (Music *)malloc(sizeof(Music));
    *out = LoadMusicStreamFromMemory(filetype, filedata, datasize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Music_class, &Raylib_Music_type, out));

    return obj;
}

// IsMusicReady
mrb_value mrb_is_music_ready(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_bool_value(IsMusicReady(*music));
}

// UnloadMusicStream
mrb_value mrb_unload_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    UnloadMusicStream(*music);
    return mrb_nil_value();
}

// UpdateMusicStream
mrb_value mrb_update_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    UpdateMusicStream(*music);
    return mrb_nil_value();
}

// PlayMusicStream
mrb_value mrb_play_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    PlayMusicStream(*music);
    return mrb_nil_value();
}

// IsMusicStreamPlaying
mrb_value mrb_is_music_stream_playing(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_bool_value(IsMusicStreamPlaying(*music));
}

// StopMusicStream
mrb_value mrb_stop_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    StopMusicStream(*music);
    return mrb_nil_value();
}

// PauseMusicStream
mrb_value mrb_pause_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    PauseMusicStream(*music);
    return mrb_nil_value();
}

// ResumeMusicStream
mrb_value mrb_resume_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    ResumeMusicStream(*music);
    return mrb_nil_value();
}

// SeekMusicStream
mrb_value mrb_seek_music_stream(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float position;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &position);
    SeekMusicStream(*music, position);
    return mrb_nil_value();
}

// SetMusicVolume
mrb_value mrb_set_music_volume(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float volume;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &volume);
    SetMusicVolume(*music, volume);
    return mrb_nil_value();
}

// SetMusicPitch
mrb_value mrb_set_music_pitch(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float pitch;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &pitch);
    SetMusicPitch(*music, pitch);
    return mrb_nil_value();
}

// SetMusicPan
mrb_value mrb_set_music_pan(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_float pan;
    mrb_get_args(mrb, "df", &music, &Raylib_Music_type, &pan);
    SetMusicPan(*music, pan);
    return mrb_nil_value();
}

// GetMusicTimeLength
mrb_value mrb_get_music_time_length(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_float_value(mrb, GetMusicTimeLength(*music));
}

// GetMusicTimePlayed
mrb_value mrb_get_music_time_played(mrb_state *mrb, mrb_value self)
{
    Music *music;
    mrb_get_args(mrb, "d", &music, &Raylib_Music_type);
    return mrb_float_value(mrb, GetMusicTimePlayed(*music));
}

void mrb_raylib_setup_music_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_music_stream", mrb_load_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_music_stream_from_memory", mrb_load_music_stream_from_memory, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "is_music_ready?", mrb_is_music_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_music_stream", mrb_unload_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "play_music_stream", mrb_play_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_music_stream_playing?", mrb_is_music_stream_playing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "update_music_stream", mrb_update_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "stop_music_stream", mrb_stop_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "pause_music_stream", mrb_pause_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "resume_music_stream", mrb_resume_music_stream, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "seek_music_stream", mrb_seek_music_stream, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_music_volume", mrb_set_music_volume, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_music_pitch", mrb_set_music_pitch, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_music_pan", mrb_set_music_pan, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_music_time_length", mrb_get_music_time_length, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_music_time_played", mrb_get_music_time_played, MRB_ARGS_REQ(1));
}

//-------
// Wave Loading Functions
//-------

// LoadWave
mrb_value mrb_load_wave(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Wave *out = (Wave *)malloc(sizeof(Wave));
    *out = LoadWave(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Wave_class, &Raylib_Wave_type, out));

    return obj;
}

// LoadWaveFromMemory
mrb_value mrb_load_wave_from_memory(mrb_state *mrb, mrb_value self)
{
    const char *filetype;
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_get_args(mrb, "zzi", &filetype, &filedata, &datasize);
    Wave *out = (Wave *)malloc(sizeof(Wave));
    *out = LoadWaveFromMemory(filetype, filedata, datasize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Wave_class, &Raylib_Wave_type, out));

    return obj;
}

// LoadSound
mrb_value mrb_load_sound(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Sound *out = (Sound *)malloc(sizeof(Sound));
    *out = LoadSound(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Sound_class, &Raylib_Sound_type, out));

    return obj;
}

// LoadSoundFromWave
mrb_value mrb_load_sound_from_wave(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    Sound *out = (Sound *)malloc(sizeof(Sound));
    *out = LoadSoundFromWave(*wave);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Sound_class, &Raylib_Sound_type, out));

    return obj;
}

// LoadSoundAlias
mrb_value mrb_load_sound_alias(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    Sound *out = (Sound *)malloc(sizeof(Sound));
    *out = LoadSoundAlias(*sound);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Sound_class, &Raylib_Sound_type, out));

    return obj;
}

// IsSoundReady
mrb_value mrb_is_sound_ready(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    return mrb_bool_value(IsSoundReady(*sound));
}

// IsWaveReady
mrb_value mrb_is_wave_ready(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    return mrb_bool_value(IsWaveReady(*wave));
}

// UnloadWave
mrb_value mrb_unload_wave(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    UnloadWave(*wave);
    return mrb_nil_value();
}

// UnloadSound
mrb_value mrb_unload_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    UnloadSound(*sound);
    return mrb_nil_value();
}

// UnloadSoundAlias
mrb_value mrb_unload_sound_alias(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    UnloadSoundAlias(*sound);
    return mrb_nil_value();
}

// ExportWave
mrb_value mrb_export_wave(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    const char *filename;
    mrb_get_args(mrb, "dz", &wave, &Raylib_Wave_type, &filename);
    return mrb_bool_value(ExportWave(*wave, filename));
}

// ExportWaveAsCode
mrb_value mrb_export_wave_as_code(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    const char *filename;
    mrb_get_args(mrb, "dz", &wave, &Raylib_Wave_type, &filename);
    return mrb_bool_value(ExportWaveAsCode(*wave, filename));
}

void mrb_raylib_setup_wave_loading(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_wave", mrb_load_wave, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_wave_from_memory", mrb_load_wave_from_memory, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_sound", mrb_load_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_sound_from_wave", mrb_load_sound_from_wave, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_sound_alias", mrb_load_sound_alias, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_sound_ready?", mrb_is_sound_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_wave_ready?", mrb_is_wave_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_sound", mrb_unload_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_sound_alias", mrb_unload_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_wave", mrb_unload_wave, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_wave", mrb_export_wave, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "export_wave_as_code", mrb_export_wave_as_code, MRB_ARGS_REQ(2));
}

//-------
// Wave Management Functions
//-------

// PlaySound
mrb_value mrb_play_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    PlaySound(*sound);
    return mrb_nil_value();
}

// StopSound
mrb_value mrb_stop_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    StopSound(*sound);
    return mrb_nil_value();
}

// PauseSound
mrb_value mrb_pause_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    PauseSound(*sound);
    return mrb_nil_value();
}

// ResumeSound
mrb_value mrb_resume_sound(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    ResumeSound(*sound);
    return mrb_nil_value();
}

// IsSoundPlaying
mrb_value mrb_is_sound_playing(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_get_args(mrb, "d", &sound, &Raylib_Sound_type);
    return mrb_bool_value(IsSoundPlaying(*sound));
}

// SetSoundVolume
mrb_value mrb_set_sound_volume(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_float volume;
    mrb_get_args(mrb, "df", &sound, &Raylib_Sound_type, &volume);
    SetSoundVolume(*sound, volume);
    return mrb_nil_value();
}

// SetSoundPitch
mrb_value mrb_set_sound_pitch(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_float pitch;
    mrb_get_args(mrb, "df", &sound, &Raylib_Sound_type, &pitch);
    SetSoundPitch(*sound, pitch);
    return mrb_nil_value();
}

// SetSoundPan
mrb_value mrb_set_sound_pan(mrb_state *mrb, mrb_value self)
{
    Sound *sound;
    mrb_float pan;
    mrb_get_args(mrb, "df", &sound, &Raylib_Sound_type, &pan);
    SetSoundPan(*sound, pan);
    return mrb_nil_value();
}

// WaveCopy
mrb_value mrb_wave_copy(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    Wave *out = (Wave *)malloc(sizeof(Wave));
    *out = WaveCopy(*wave);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Wave_class, &Raylib_Wave_type, out));

    return obj;
}

// WaveCrop
mrb_value mrb_wave_crop(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_int initsample;
    mrb_int finalsample;
    mrb_get_args(mrb, "dii", &wave, &Raylib_Wave_type, &initsample, &finalsample);
    WaveCrop(wave, initsample, finalsample);
    return mrb_nil_value();
}

// WaveFormat
mrb_value mrb_wave_format(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_int samplerate;
    mrb_int samplesize;
    mrb_int channels;
    mrb_get_args(mrb, "diii", &wave, &Raylib_Wave_type, &samplerate, &samplesize, &channels);
    WaveFormat(wave, samplerate, samplesize, channels);
    return mrb_nil_value();
}

// LoadWaveSamples
mrb_value mrb_load_wave_samples(mrb_state *mrb, mrb_value self)
{
    Wave *wave;
    mrb_get_args(mrb, "d", &wave, &Raylib_Wave_type);
    float *values = LoadWaveSamples(*wave);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < (sizeof(*values) / sizeof(values[0])); ++i)
    {
        mrb_ary_push(mrb, ary, mrb_float_value(mrb, values[i]));
    }
    UnloadWaveSamples(values);
    return ary;
}

// UnloadWaveSamples
mrb_value mrb_unload_wave_samples(mrb_state *mrb, mrb_value self)
{
    // mrb_value samples;
    // mrb_get_args(mrb, "A", &samples);
    // float *values[RARRAY_LEN(samples)];
    // for (int i = 0; i < RARRAY_LEN(samples); ++i)
    //{
    //     values[i] = (float *)DATA_PTR(mrb_ary_entry(samples, i));
    // }
    // UnloadWaveSamples(values);
    return mrb_nil_value();
}

void mrb_raylib_setup_wave_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "play_sound", mrb_play_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "stop_sound", mrb_stop_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "pause_sound", mrb_pause_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "resume_sound", mrb_resume_sound, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_sound_playing?", mrb_is_sound_playing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_sound_volume", mrb_set_sound_volume, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_sound_pitch", mrb_set_sound_pitch, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_sound_pan", mrb_set_sound_pan, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "wave_copy", mrb_wave_copy, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "wave_crop", mrb_wave_crop, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "wave_format", mrb_wave_format, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "load_wave_samples", mrb_load_wave_samples, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_wave_samples", mrb_unload_wave_samples, MRB_ARGS_REQ(1));
}

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

//-------
// Compression Functions
//-------

// CompressData
mrb_value mrb_compress_data(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    mrb_int datasize;
    int *compdatasize;
    mrb_get_args(mrb, "zii", &data, &datasize, &compdatasize);
    unsigned char *compressed = CompressData(data, datasize, compdatasize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)compressed);
    MemFree(compressed);
    return obj;
}

// DecompressData
mrb_value mrb_decompress_data(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    mrb_int compdatasize;
    int *datasize;
    mrb_get_args(mrb, "zii", &data, &compdatasize, &datasize);
    unsigned char *decompressed = DecompressData(data, compdatasize, datasize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)decompressed);
    MemFree(decompressed);
    return obj;
}

// EncodeDataBase64
mrb_value mrb_encode_data_base64(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    mrb_int datasize;
    int *outputsize;
    mrb_get_args(mrb, "zii", &data, &datasize, &outputsize);
    char *base64 = EncodeDataBase64(data, datasize, outputsize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)base64);
    MemFree(base64);
    return obj;
}

// DecodeDataBase64
mrb_value mrb_decode_data_base64(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    int *outputsize;
    mrb_get_args(mrb, "zi", &data, &outputsize);
    unsigned char *base64 = DecodeDataBase64(data, outputsize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)base64);
    MemFree(base64);
    return obj;
}

void mrb_raylib_setup_compression(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "compress_data", mrb_compress_data, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "decompress_data", mrb_decompress_data, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "encode_data_base64", mrb_encode_data_base64, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "decode_data_base64", mrb_decode_data_base64, MRB_ARGS_REQ(2));
}


//-------
// Cursor Functions
//-------

// ShowCursor
mrb_value mrb_show_cursor(mrb_state *mrb, mrb_value self)
{
    ShowCursor();
    return mrb_nil_value();
}

// HideCursor
mrb_value mrb_hide_cursor(mrb_state *mrb, mrb_value self)
{
    HideCursor();
    return mrb_nil_value();
}

// IsCursorHidden
mrb_value mrb_is_cursor_hidden(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsCursorHidden());
}

// EnableCursor
mrb_value mrb_enable_cursor(mrb_state *mrb, mrb_value self)
{
    EnableCursor();
    return mrb_nil_value();
}

// DisableCursor
mrb_value mrb_disable_cursor(mrb_state *mrb, mrb_value self)
{
    DisableCursor();
    return mrb_nil_value();
}

// IsCursorOnScreen
mrb_value mrb_is_cursor_on_screen(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsCursorOnScreen());
}

void mrb_raylib_setup_cursor(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "show_cursor", mrb_show_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "hide_cursor", mrb_hide_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_cursor_hidden?", mrb_is_cursor_hidden, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "enable_cursor", mrb_enable_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "disable_cursor", mrb_disable_cursor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_cursor_on_screen?", mrb_is_cursor_on_screen, MRB_ARGS_NONE());
}

//-------
// Drawing Functions
//-------

// ClearBackground
mrb_value mrb_clear_background(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    ClearBackground(*color);
    return mrb_nil_value();
}

// BeginDrawing
mrb_value mrb_begin_drawing(mrb_state *mrb, mrb_value self)
{
    BeginDrawing();
    return mrb_nil_value();
}

// EndDrawing
mrb_value mrb_end_drawing(mrb_state *mrb, mrb_value self)
{
    EndDrawing();
    return mrb_nil_value();
}

// BeginMode2D
mrb_value mrb_begin_mode2d(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera2d;
    mrb_get_args(mrb, "d", &camera2d, &Raylib_Camera2D_type);
    BeginMode2D(*camera2d);
    return mrb_nil_value();
}

// EndMode2D
mrb_value mrb_end_mode2d(mrb_state *mrb, mrb_value self)
{
    EndMode2D();
    return mrb_nil_value();
}

// BeginMode3D
mrb_value mrb_begin_mode3d(mrb_state *mrb, mrb_value self)
{
    Camera3D *camera;
    mrb_get_args(mrb, "d", &camera, &Raylib_Camera_type);
    BeginMode3D(*camera);
    return mrb_nil_value();
}

// EndMode3D
mrb_value mrb_end_mode3d(mrb_state *mrb, mrb_value self)
{
    EndMode3D();
    return mrb_nil_value();
}

// BeginTextureMode
mrb_value mrb_begin_texture_mode(mrb_state *mrb, mrb_value self)
{
    RenderTexture *rendertexture;
    mrb_get_args(mrb, "d", &rendertexture, &Raylib_RenderTexture_type);
    BeginTextureMode(*rendertexture);
    return mrb_nil_value();
}

// EndTextureMode
mrb_value mrb_end_texture_mode(mrb_state *mrb, mrb_value self)
{
    EndTextureMode();
    return mrb_nil_value();
}

// BeginShaderMode
mrb_value mrb_begin_shader_mode(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_get_args(mrb, "d", &shader, &Raylib_Shader_type);
    BeginShaderMode(*shader);
    return mrb_nil_value();
}

// EndShaderMode
mrb_value mrb_end_shader_mode(mrb_state *mrb, mrb_value self)
{
    EndShaderMode();
    return mrb_nil_value();
}

// BeginBlendMode
mrb_value mrb_begin_blend_mode(mrb_state *mrb, mrb_value self)
{
    mrb_int mode;
    mrb_get_args(mrb, "i", &mode);
    BeginBlendMode(mode);
    return mrb_nil_value();
}

// EndBlendMode
mrb_value mrb_end_blend_mode(mrb_state *mrb, mrb_value self)
{
    EndBlendMode();
    return mrb_nil_value();
}

// BeginScissorMode
mrb_value mrb_begin_scissor_mode(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y, width, height;
    mrb_get_args(mrb, "iiii", &x, &y, &width, &height);
    BeginScissorMode(x, y, width, height);
    return mrb_nil_value();
}

// EndScissorMode
mrb_value mrb_end_scissor_mode(mrb_state *mrb, mrb_value self)
{
    EndScissorMode();
    return mrb_nil_value();
}

// BeginVrStereoMode
mrb_value mrb_begin_vr_stereo_mode(mrb_state *mrb, mrb_value self)
{
    VrStereoConfig *config;
    mrb_get_args(mrb, "d", &config, &Raylib_VrStereoConfig_type);
    BeginVrStereoMode(*config);
    return mrb_nil_value();
}

// EndVrStereoMode
mrb_value mrb_end_vr_stereo_mode(mrb_state *mrb, mrb_value self)
{
    EndVrStereoMode();
    return mrb_nil_value();
}

void mrb_raylib_setup_drawing(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "clear_background", mrb_clear_background, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "begin_drawing", mrb_begin_drawing, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "end_drawing", mrb_end_drawing, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_mode2d", mrb_begin_mode2d, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_mode2d", mrb_end_mode2d, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_mode3d", mrb_begin_mode3d, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_mode3d", mrb_end_mode3d, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_texture_mode", mrb_begin_texture_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_texture_mode", mrb_end_texture_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_shader_mode", mrb_begin_shader_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_shader_mode", mrb_end_shader_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_blend_mode", mrb_begin_blend_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_blend_mode", mrb_end_blend_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_scissor_mode", mrb_begin_scissor_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_scissor_mode", mrb_end_scissor_mode, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "begin_vr_stereo_mode", mrb_begin_vr_stereo_mode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "end_vr_stereo_mode", mrb_end_vr_stereo_mode, MRB_ARGS_NONE());
}


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


//-------
// Frame Control Functions
//-------

// SwapScreenBuffer
mrb_value mrb_swap_screen_buffer(mrb_state *mrb, mrb_value self)
{
    SwapScreenBuffer();
    return mrb_nil_value();
}

// PollInputEvents
mrb_value mrb_poll_input_events(mrb_state *mrb, mrb_value self)
{
    PollInputEvents();
    return mrb_nil_value();
}

// WaitTime
mrb_value mrb_wait_time(mrb_state *mrb, mrb_value self)
{
    mrb_float seconds;
    mrb_get_args(mrb, "f", &seconds);
    WaitTime(seconds);
    return mrb_nil_value();
}

void mrb_raylib_setup_frame_control(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "swap_screen_buffer", mrb_swap_screen_buffer, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "poll_input_events", mrb_poll_input_events, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "wait_time", mrb_wait_time, MRB_ARGS_REQ(1));
}

//-------
// Misc Functions
//-------

// GetRandomValue
mrb_value mrb_get_random_value(mrb_state *mrb, mrb_value self)
{
    mrb_int min, max;
    mrb_get_args(mrb, "ii", &min, &max);
    return mrb_int_value(mrb, GetRandomValue(min, max));
}

// SetRandomSeed
mrb_value mrb_set_random_seed(mrb_state *mrb, mrb_value self)
{
    mrb_int seed;
    mrb_get_args(mrb, "i", &seed);
    SetRandomSeed(seed);
    return mrb_nil_value();
}

// LoadRandomSequence
mrb_value mrb_load_random_sequence(mrb_state *mrb, mrb_value self)
{
    mrb_int count, min, max;
    mrb_get_args(mrb, "iii", &count, &min, &max);
    mrb_value ary = mrb_ary_new(mrb);
    int *sequence = LoadRandomSequence(count, min, max);
    for (int i = 0; i < count; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_int_value(mrb, sequence[i]));
    }
    return ary;
}

// UnloadRandomSequence
mrb_value mrb_unload_random_sequence(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

// TakeScreenshot
mrb_value mrb_take_screenshot(mrb_state *mrb, mrb_value self)
{
    char *filename;
    mrb_get_args(mrb, "z", &filename);
    TakeScreenshot(filename);
    return mrb_nil_value();
}

// SetConfigFlags
mrb_value mrb_set_config_flags(mrb_state *mrb, mrb_value self)
{
    mrb_int flags;
    mrb_get_args(mrb, "i", &flags);
    SetConfigFlags(flags);
    return mrb_nil_value();
}

// SetTraceLogLevel
mrb_value mrb_set_trace_log_level(mrb_state *mrb, mrb_value self)
{
    mrb_int log_level;
    mrb_get_args(mrb, "i", &log_level);
    SetTraceLogLevel(log_level);
    return mrb_nil_value();
}

// OpenURL
mrb_value mrb_open_url(mrb_state *mrb, mrb_value self)
{
    char *url;
    mrb_get_args(mrb, "z", &url);
    OpenURL(url);
    return mrb_nil_value();
}

void mrb_raylib_setup_misc(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "get_random_value", mrb_get_random_value, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_random_seed", mrb_set_random_seed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_random_sequence", mrb_load_random_sequence, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "unload_random_sequence", mrb_unload_random_sequence, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "take_screenshot", mrb_take_screenshot, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_config_flags", mrb_set_config_flags, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_trace_log_level", mrb_set_trace_log_level, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "open_url", mrb_open_url, MRB_ARGS_REQ(1));
}

//-------
// Screen Space Functions
//-------

// GetMouseRay
mrb_value mrb_get_mouse_ray(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2;
    Camera *camera;
    mrb_get_args(mrb, "dd", &vector2, &Raylib_Vector2_type, &camera, &Raylib_Camera_type);

    Ray *ray = (Ray *)malloc(sizeof(Ray));
    *ray = GetMouseRay(*vector2, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Ray_class, &Raylib_Ray_type, ray));

    return obj;
}

// GetCameraMatrix
mrb_value mrb_get_camera_matrix(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    mrb_get_args(mrb, "d", &camera, &Raylib_Camera_type);

    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    *matrix = GetCameraMatrix(*camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Matrix_class, &Raylib_Matrix_type, matrix));

    return obj;
}

// GetCameraMatrix2D
mrb_value mrb_get_camera_matrix2D(mrb_state *mrb, mrb_value self)
{
    Camera2D *camera;
    mrb_get_args(mrb, "d", &camera, &Raylib_Camera2D_type);

    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    *matrix = GetCameraMatrix2D(*camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Matrix_class, &Raylib_Matrix_type, matrix));

    return obj;
}

// GetWorldToScreen
mrb_value mrb_get_world_to_screen(mrb_state *mrb, mrb_value self)
{
    Vector3 *vector;
    Camera *camera;
    mrb_get_args(mrb, "dd", &vector, &Raylib_Vector3_type, &camera, &Raylib_Camera_type);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWorldToScreen(*vector, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetWorldToScreenEx
mrb_value mrb_get_world_to_screen_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *vector;
    Camera *camera;
    mrb_int width;
    mrb_int height;
    mrb_get_args(mrb, "ddii", &vector, &Raylib_Vector3_type, &camera, &Raylib_Camera_type, &width, &height);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWorldToScreenEx(*vector, *camera, width, height);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetWorldToScreen2D
mrb_value mrb_get_world_to_screen2d(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector;
    Camera2D *camera;
    mrb_get_args(mrb, "dd", &vector, &Raylib_Vector2_type, &camera, &Raylib_Camera2D_type);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWorldToScreen2D(*vector, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetScreenToWorld2D
mrb_value mrb_get_screen_to_world2d(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector;
    Camera2D *camera;
    mrb_get_args(mrb, "dd", &vector, &Raylib_Vector2_type, &camera, &Raylib_Camera2D_type);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetScreenToWorld2D(*vector, *camera);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

void mrb_raylib_setup_screen_space(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "get_mouse_ray", mrb_get_mouse_ray, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_camera_matrix", mrb_get_camera_matrix, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_camera_matrix2d", mrb_get_camera_matrix2D, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_world_to_screen", mrb_get_world_to_screen, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_world_to_screen_ex", mrb_get_world_to_screen_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_world_to_screen2d", mrb_get_world_to_screen2d, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_screen_to_world2d", mrb_get_screen_to_world2d, MRB_ARGS_REQ(2));
}

//-------
// Shader Functions
//-------

// LoadShader
mrb_value mrb_load_shader(mrb_state *mrb, mrb_value self)
{
    char *vsfilename, *fsfilename;
    mrb_get_args(mrb, "zz", &vsfilename, &fsfilename);

    Shader *shader = (Shader *)malloc(sizeof(Shader));
    *shader = LoadShader(vsfilename, fsfilename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Shader_class, &Raylib_Shader_type, shader));

    return obj;
}

// LoadShaderFromMemory
mrb_value mrb_load_shader_from_memory(mrb_state *mrb, mrb_value self)
{
    char *vscode, *fscode;
    mrb_get_args(mrb, "zz", &vscode, &fscode);

    Shader *shader = (Shader *)malloc(sizeof(Shader));
    *shader = LoadShaderFromMemory(vscode, fscode);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Shader_class, &Raylib_Shader_type, shader));

    return obj;
}

// IsShaderReady
mrb_value mrb_is_shader_ready(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_get_args(mrb, "d", &shader, &Raylib_Shader_type);
    return mrb_bool_value(IsShaderReady(*shader));
}

// GetShaderLocation
mrb_value mrb_get_shader_location(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    char *uniformname;
    mrb_get_args(mrb, "dz", &shader, &Raylib_Shader_type, &uniformname);
    return mrb_int_value(mrb, GetShaderLocation(*shader, uniformname));
}

// GetShaderLocationAttrib
mrb_value mrb_get_shader_location_attrib(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    char *attribname;
    mrb_get_args(mrb, "dz", &shader, &Raylib_Shader_type, &attribname);
    return mrb_int_value(mrb, GetShaderLocationAttrib(*shader, attribname));
}

// SetShaderValueMatrix
mrb_value mrb_set_shader_value_matrix(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_int locindex;
    Matrix *mat;
    mrb_get_args(mrb, "did", &shader, &Raylib_Shader_type, &locindex, &mat, &Raylib_Matrix_type);
    SetShaderValueMatrix(*shader, locindex, *mat);
    return mrb_nil_value();
}

// SetShaderValueTexture
mrb_value mrb_set_shader_value_texture(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_int locindex;
    Texture *texture;
    mrb_get_args(mrb, "did", &shader, &Raylib_Shader_type, &locindex, &texture, &Raylib_Texture_type);
    SetShaderValueTexture(*shader, locindex, *texture);
    return mrb_nil_value();
}

// UnloadShader
mrb_value mrb_unload_shader(mrb_state *mrb, mrb_value self)
{
    Shader *shader;
    mrb_get_args(mrb, "d", &shader, &Raylib_Shader_type);
    UnloadShader(*shader);
    return mrb_nil_value();
}

void mrb_raylib_setup_shader(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_shader", mrb_load_shader, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "load_shader_from_memory", mrb_load_shader_from_memory, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_shader_ready?", mrb_is_shader_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_shader_location", mrb_get_shader_location, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_shader_location_attrib", mrb_get_shader_location_attrib, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_shader_value_matrix", mrb_set_shader_value_matrix, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "set_shader_value_texture", mrb_set_shader_value_texture, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "unload_shader", mrb_unload_shader, MRB_ARGS_REQ(1));
}

//-------
// Timing Functions
//-------

// SetTargetFPS
mrb_value mrb_set_target_fps(mrb_state *mrb, mrb_value self)
{
    mrb_int fps;
    mrb_get_args(mrb, "i", &fps);
    SetTargetFPS(fps);
    return mrb_nil_value();
}

// GetFPS
mrb_value mrb_get_fps(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetFPS());
}

// GetFrameTime
mrb_value mrb_get_frame_time(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetFrameTime());
}

// GetTime
mrb_value mrb_get_time(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetTime());
}

void mrb_raylib_setup_timing(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "set_target_fps", mrb_set_target_fps, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_fps", mrb_get_fps, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_frame_time", mrb_get_frame_time, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_time", mrb_get_time, MRB_ARGS_NONE());
}

//-------
// VR Functions
//-------

// LoadVrStereoConfig
mrb_value mrb_load_vr_stereo_config(mrb_state *mrb, mrb_value self)
{
    VrDeviceInfo *device;
    mrb_get_args(mrb, "d", &device, &Raylib_VrDeviceInfo_type);

    VrStereoConfig *vrstereoconfig = (VrStereoConfig *)malloc(sizeof(VrStereoConfig));
    *vrstereoconfig = LoadVrStereoConfig(*device);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_VrStereoConfig_class, &Raylib_VrStereoConfig_type, vrstereoconfig));

    return obj;
}

// UnloadVrStereoConfig
mrb_value mrb_unload_vr_stereo_config(mrb_state *mrb, mrb_value self)
{
    VrStereoConfig *config;
    mrb_get_args(mrb, "d", &config, &Raylib_VrStereoConfig_type);
    UnloadVrStereoConfig(*config);
    return mrb_nil_value();
}

void mrb_raylib_setup_vr(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_vr_stereo_config", mrb_load_vr_stereo_config, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_vr_stereo_config", mrb_unload_vr_stereo_config, MRB_ARGS_REQ(1));
}

//-------
// Window Functions
//-------

// InitWindow
mrb_value mrb_init_window(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    char *title;
    mrb_get_args(mrb, "iiz", &width, &height, &title);
    InitWindow(width, height, title);
    return mrb_nil_value();
}

// WindowShouldClose
mrb_value mrb_window_should_close(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(WindowShouldClose());
}

// CloseWindow
mrb_value mrb_close_window(mrb_state *mrb, mrb_value self)
{
    CloseWindow();
    return mrb_nil_value();
}

// IsWindowReady
mrb_value mrb_is_window_ready(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowReady());
}

// IsWindowFullscreen
mrb_value mrb_is_window_fullscreen(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowFullscreen());
}

// IsWindowHidden
mrb_value mrb_is_window_hidden(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowHidden());
}

// IsWindowMinimized
mrb_value mrb_is_window_minimized(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowMinimized());
}

// IsWindowMaximized
mrb_value mrb_is_window_maximized(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowMaximized());
}

// IsWindowFocused
mrb_value mrb_is_window_focused(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowFocused());
}

// IsWindowResized
mrb_value mrb_is_window_resized(mrb_state *mrb, mrb_value self)
{
    return mrb_bool_value(IsWindowResized());
}

// IsWindowState
mrb_value mrb_is_window_state(mrb_state *mrb, mrb_value self)
{
    mrb_int state;
    mrb_get_args(mrb, "i", &state);
    return mrb_bool_value(IsWindowState(state));
}

// SetWindowState
mrb_value mrb_set_window_state(mrb_state *mrb, mrb_value self)
{
    mrb_int state;
    mrb_get_args(mrb, "i", &state);
    SetWindowState(state);
    return mrb_nil_value();
}

// ClearWindowState
mrb_value mrb_clear_window_state(mrb_state *mrb, mrb_value self)
{
    mrb_int state;
    mrb_get_args(mrb, "i", &state);
    ClearWindowState(state);
    return mrb_nil_value();
}

// ToggleFullscreen
mrb_value mrb_toggle_fullscreen(mrb_state *mrb, mrb_value self)
{
    ToggleFullscreen();
    return mrb_nil_value();
}

// MaximizeWindow
mrb_value mrb_maximize_window(mrb_state *mrb, mrb_value self)
{
    MaximizeWindow();
    return mrb_nil_value();
}

// MinimizeWindow
mrb_value mrb_minimize_window(mrb_state *mrb, mrb_value self)
{
    MinimizeWindow();
    return mrb_nil_value();
}

// RestoreWindow
mrb_value mrb_restore_window(mrb_state *mrb, mrb_value self)
{
    RestoreWindow();
    return mrb_nil_value();
}

// SetWindowIcon
mrb_value mrb_set_window_icon(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    SetWindowIcon(*image);
    return mrb_nil_value();
}

// SetWindowIcons
mrb_value mrb_set_window_icons(mrb_state *mrb, mrb_value self)
{
    mrb_value icons;
    mrb_int iconcount;
    mrb_get_args(mrb, "Ai", &icons, &iconcount);
    Image image_icons[iconcount];
    for (int i = 0; i < iconcount; ++i)
    {
        image_icons[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(icons, i), &Raylib_Image_type, Image);
    }
    SetWindowIcons(image_icons, iconcount);
    return mrb_nil_value();
}

// SetWindowTitle
mrb_value mrb_set_window_title(mrb_state *mrb, mrb_value self)
{
    char *title;
    mrb_get_args(mrb, "z", &title);
    SetWindowTitle(title);
    return mrb_nil_value();
}

// SetWindowPosition
mrb_value mrb_set_window_position(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y;
    mrb_get_args(mrb, "ii", &x, &y);
    SetWindowPosition(x, y);
    return mrb_nil_value();
}

// SetWindowMonitor
mrb_value mrb_set_window_monitor(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    SetWindowMonitor(monitor);
    return mrb_nil_value();
}

// SetWindowMinSize
mrb_value mrb_set_window_min_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    mrb_get_args(mrb, "ii", &width, &height);
    SetWindowMinSize(width, height);
    return mrb_nil_value();
}

// SetWindowMaxSize
mrb_value mrb_set_window_max_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    mrb_get_args(mrb, "ii", &width, &height);
    SetWindowMaxSize(width, height);
    return mrb_nil_value();
}

// SetWindowSize
mrb_value mrb_set_window_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width, height;
    mrb_get_args(mrb, "ii", &width, &height);
    SetWindowSize(width, height);
    return mrb_nil_value();
}

// SetWindowOpacity
mrb_value mrb_set_window_opacity(mrb_state *mrb, mrb_value self)
{
    mrb_float opacity;
    mrb_get_args(mrb, "f", &opacity);
    SetWindowOpacity(opacity);
    return mrb_nil_value();
}

// SetWindowFocused
mrb_value mrb_set_window_focused(mrb_state *mrb, mrb_value self)
{
    SetWindowFocused();
    return mrb_nil_value();
}

// GetScreenWidth
mrb_value mrb_get_screen_width(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetScreenWidth());
}

// GetScreenHeight
mrb_value mrb_get_screen_height(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetScreenHeight());
}

// GetRenderWidth
mrb_value mrb_get_render_width(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetRenderWidth());
}

// GetRenderHeight
mrb_value mrb_get_render_height(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetRenderHeight());
}

// GetMonitorCount
mrb_value mrb_get_monitor_count(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetMonitorCount());
}

// GetCurrentMonitor
mrb_value mrb_get_current_monitor(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetCurrentMonitor());
}

// GetMonitorPosition
mrb_value mrb_get_monitor_position(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMonitorPosition(monitor);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetMonitorWidth
mrb_value mrb_get_monitor_width(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorWidth(monitor));
}

// GetMonitorHeight
mrb_value mrb_get_monitor_height(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorHeight(monitor));
}

// GetMonitorPhysicalWidth
mrb_value mrb_get_monitor_physical_width(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorPhysicalWidth(monitor));
}

// GetMonitorPhysicalHeight
mrb_value mrb_get_monitor_physical_height(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorPhysicalHeight(monitor));
}

// GetMonitorRefreshRate
mrb_value mrb_get_monitor_refresh_rate(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_int_value(mrb, GetMonitorRefreshRate(monitor));
}

// GetWindowPosition
mrb_value mrb_get_window_position(mrb_state *mrb, mrb_value self)
{

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWindowPosition();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetWindowScaleDPI
mrb_value mrb_get_window_scale_dpi(mrb_state *mrb, mrb_value self)
{

    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetWindowScaleDPI();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetMonitorName
mrb_value mrb_get_monitor_name(mrb_state *mrb, mrb_value self)
{
    mrb_int monitor;
    mrb_get_args(mrb, "i", &monitor);
    return mrb_str_new_cstr(mrb, GetMonitorName(monitor));
}

// SetClipboardText
mrb_value mrb_set_clipboard_text(mrb_state *mrb, mrb_value self)
{
    char *clipboard;
    mrb_get_args(mrb, "z", &clipboard);
    SetClipboardText(clipboard);
    return mrb_nil_value();
}

// GetClipboardText
mrb_value mrb_get_clipboard_text(mrb_state *mrb, mrb_value self)
{
    return mrb_str_new_cstr(mrb, GetClipboardText());
}

// EnableEventWaiting
mrb_value mrb_enable_event_waiting(mrb_state *mrb, mrb_value self)
{
    EnableEventWaiting();
    return mrb_nil_value();
}

// DisableEventWaiting
mrb_value mrb_disable_event_waiting(mrb_state *mrb, mrb_value self)
{
    DisableEventWaiting();
    return mrb_nil_value();
}

void mrb_raylib_setup_window(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "init_window", mrb_init_window, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "window_should_close?", mrb_window_should_close, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "close_window", mrb_close_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_ready?", mrb_is_window_ready, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_fullscreen?", mrb_is_window_fullscreen, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_hidden?", mrb_is_window_hidden, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_minimized?", mrb_is_window_minimized, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_maximized?", mrb_is_window_maximized, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_focused?", mrb_is_window_focused, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_resized?", mrb_is_window_resized, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_window_state?", mrb_is_window_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_state", mrb_set_window_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "clear_window_state", mrb_clear_window_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "toggle_fullscreen", mrb_toggle_fullscreen, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "maximize_window", mrb_maximize_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "minimize_window", mrb_minimize_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "restore_window", mrb_restore_window, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_window_icon", mrb_set_window_icon, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_icons", mrb_set_window_icons, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_title", mrb_set_window_title, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_position", mrb_set_window_position, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_monitor", mrb_set_window_monitor, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_min_size", mrb_set_window_min_size, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_max_size", mrb_set_window_max_size, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_size", mrb_set_window_size, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_window_opacity", mrb_set_window_opacity, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_window_focused", mrb_set_window_focused, MRB_ARGS_NONE());

    mrb_define_module_function(mrb, raylib_module, "get_screen_width", mrb_get_screen_width, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_screen_height", mrb_get_screen_height, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_render_width", mrb_get_render_width, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_render_height", mrb_get_render_height, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_monitor_count", mrb_get_monitor_count, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_current_monitor", mrb_get_current_monitor, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_monitor_position", mrb_get_monitor_position, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_width", mrb_get_monitor_width, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_height", mrb_get_monitor_height, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_physical_width", mrb_get_monitor_physical_width, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_physical_height", mrb_get_monitor_physical_height, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_monitor_refresh_rate", mrb_get_monitor_refresh_rate, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_window_position", mrb_get_window_position, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_window_scale_dpi", mrb_get_window_scale_dpi, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_monitor_name", mrb_get_monitor_name, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_clipboard_text", mrb_set_clipboard_text, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_clipboard_text", mrb_get_clipboard_text, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "enable_event_waiting", mrb_enable_event_waiting, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "disable_event_waiting", mrb_disable_event_waiting, MRB_ARGS_NONE());
}

//-------
// Color Functions
//-------

// Fade
mrb_value mrb_fade(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float alpha;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &alpha);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = Fade(*color, alpha);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorToInt
mrb_value mrb_color_to_int(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    return mrb_int_value(mrb, ColorToInt(*color));
}

// ColorNormalize
mrb_value mrb_color_normalize(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    Vector4 *out = (Vector4 *)malloc(sizeof(Vector4));
    *out = ColorNormalize(*color);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector4_class, &Raylib_Vector4_type, out));

    return obj;
}

// ColorFromNormalized
mrb_value mrb_color_from_normalized(mrb_state *mrb, mrb_value self)
{
    Vector4 *normalized;
    mrb_get_args(mrb, "d", &normalized, &Raylib_Vector4_type);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorFromNormalized(*normalized);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorToHSV
mrb_value mrb_color_to_hsv(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_get_args(mrb, "d", &color, &Raylib_Color_type);
    Vector3 *out = (Vector3 *)malloc(sizeof(Vector3));
    *out = ColorToHSV(*color);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector3_class, &Raylib_Vector3_type, out));

    return obj;
}

// ColorFromHSV
mrb_value mrb_color_from_hsv(mrb_state *mrb, mrb_value self)
{
    mrb_float hue;
    mrb_float saturation;
    mrb_float value;
    mrb_get_args(mrb, "fff", &hue, &saturation, &value);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorFromHSV(hue, saturation, value);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorTint
mrb_value mrb_color_tint(mrb_state *mrb, mrb_value self)
{
    Color *color;
    Color *tint;
    mrb_get_args(mrb, "dd", &color, &Raylib_Color_type, &tint, &Raylib_Color_type);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorTint(*color, *tint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorBrightness
mrb_value mrb_color_brightness(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float factor;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &factor);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorBrightness(*color, factor);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorContrast
mrb_value mrb_color_contrast(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float contrast;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &contrast);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorContrast(*color, contrast);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorAlpha
mrb_value mrb_color_alpha(mrb_state *mrb, mrb_value self)
{
    Color *color;
    mrb_float alpha;
    mrb_get_args(mrb, "df", &color, &Raylib_Color_type, &alpha);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorAlpha(*color, alpha);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// ColorAlphaBlend
mrb_value mrb_color_alpha_blend(mrb_state *mrb, mrb_value self)
{
    Color *dst;
    Color *src;
    Color *tint;
    mrb_get_args(mrb, "ddd", &dst, &Raylib_Color_type, &src, &Raylib_Color_type, &tint, &Raylib_Color_type);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = ColorAlphaBlend(*dst, *src, *tint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// GetColor
mrb_value mrb_get_color(mrb_state *mrb, mrb_value self)
{
    mrb_int hexvalue;
    mrb_get_args(mrb, "i", &hexvalue);
    Color *out = (Color *)malloc(sizeof(Color));
    *out = GetColor(hexvalue);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, out));

    return obj;
}

// GetPixelDataSize
mrb_value mrb_get_pixel_data_size(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_int format;
    mrb_get_args(mrb, "iii", &width, &height, &format);
    return mrb_int_value(mrb, GetPixelDataSize(width, height, format));
}

void mrb_raylib_setup_color(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "fade", mrb_fade, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_to_int", mrb_color_to_int, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_normalize", mrb_color_normalize, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_from_normalized", mrb_color_from_normalized, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_to_hsv", mrb_color_to_hsv, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "color_from_hsv", mrb_color_from_hsv, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "color_tint", mrb_color_tint, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_brightness", mrb_color_brightness, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_contrast", mrb_color_contrast, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_alpha", mrb_color_alpha, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "color_alpha_blend", mrb_color_alpha_blend, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_color", mrb_get_color, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_pixel_data_size", mrb_get_pixel_data_size, MRB_ARGS_REQ(3));
}

//-------
// Image Functions
//-------

// LoadImage
mrb_value mrb_load_image(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = LoadImage(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// LoadImageRaw
mrb_value mrb_load_image_raw(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int width;
    mrb_int height;
    mrb_int format;
    mrb_int headersize;
    mrb_get_args(mrb, "ziiii", &filename, &width, &height, &format, &headersize);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = LoadImageRaw(filename, width, height, format, headersize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// LoadImageSvg
mrb_value mrb_load_image_svg(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int width;
    mrb_int height;
    mrb_get_args(mrb, "zii", &filename, &width, &height);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = LoadImageSvg(filename, width, height);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// LoadImageAnim
mrb_value mrb_load_image_anim(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    int *frames;
    mrb_get_args(mrb, "zi", &filename, &frames);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = LoadImageAnim(filename, frames);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// LoadImageFromMemory
mrb_value mrb_load_image_from_memory(mrb_state *mrb, mrb_value self)
{
    const char *filetype;
    const unsigned char *fileData;
    mrb_int datasize;
    mrb_get_args(mrb, "zzi", &filetype, &fileData, &datasize);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = LoadImageFromMemory(filetype, fileData, datasize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// LoadImageFromTexture
mrb_value mrb_load_image_from_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = LoadImageFromTexture(*texture);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// LoadImageFromScreen
mrb_value mrb_load_image_from_screen(mrb_state *mrb, mrb_value self)
{
    Image *image = (Image *)malloc(sizeof(Image));
    *image = LoadImageFromScreen();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// IsImageReady
mrb_value mrb_is_image_ready(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    return mrb_bool_value(IsImageReady(*image));
}

// UnloadImage
mrb_value mrb_unload_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    UnloadImage(*image);
    return mrb_nil_value();
}

// ExportImage
mrb_value mrb_export_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    const char *fileName;
    mrb_get_args(mrb, "dz", &image, &Raylib_Image_type, &fileName);
    return mrb_bool_value(ExportImage(*image, fileName));
}

// ExportImageToMemory
mrb_value mrb_export_image_to_memory(mrb_state *mrb, mrb_value self)
{
    Image *image;
    const char *filetype;
    int *filesize;
    mrb_get_args(mrb, "dzi", &image, &Raylib_Image_type, &filetype, &filesize);
    return mrb_str_new_cstr(mrb, (const char *)ExportImageToMemory(*image, filetype, filesize));
}

// ExportImageAsCode
mrb_value mrb_export_image_as_code(mrb_state *mrb, mrb_value self)
{
    Image *image;
    const char *fileName;
    mrb_get_args(mrb, "dz", &image, &Raylib_Image_type, &fileName);
    return mrb_bool_value(ExportImageAsCode(*image, fileName));
}

// GenImageColor
mrb_value mrb_gen_image_color(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    Color *color;
    mrb_get_args(mrb, "iid", &width, &height, &color, &Raylib_Color_type);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageColor(width, height, *color);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImageGradientLinear
mrb_value mrb_gen_image_gradient_linear(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_int direction;
    Color *start;
    Color *end;
    mrb_get_args(mrb, "iiidd", &width, &height, &direction, &start, &Raylib_Color_type, &end, &Raylib_Color_type);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageGradientLinear(width, height, direction, *start, *end);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImageGradientRadial
mrb_value mrb_gen_image_gradient_radial(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_float density;
    Color *inner;
    Color *outer;
    mrb_get_args(mrb, "iifdd", &width, &height, &density, &inner, &Raylib_Color_type, &outer, &Raylib_Color_type);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageGradientRadial(width, height, density, *inner, *outer);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImageGradientSquare
mrb_value mrb_gen_image_gradient_square(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_float density;
    Color *inner;
    Color *outer;
    mrb_get_args(mrb, "iifdd", &width, &height, &density, &inner, &Raylib_Color_type, &outer, &Raylib_Color_type);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageGradientSquare(width, height, density, *inner, *outer);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImageChecked
mrb_value mrb_gen_image_checked(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_int checksx;
    mrb_int checksy;
    Color *col1;
    Color *col2;
    mrb_get_args(mrb, "iiiidd", &width, &height, &checksx, &checksy, &col1, &Raylib_Color_type, &col2, &Raylib_Color_type);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageChecked(width, height, checksx, checksy, *col1, *col2);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImageWhiteNoise
mrb_value mrb_gen_image_white_noise(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_float factor;
    mrb_get_args(mrb, "iif", &width, &height, &factor);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageWhiteNoise(width, height, factor);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImagePerlinNoise
mrb_value mrb_gen_image_perlin_noise(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_int offsetx;
    mrb_int offsety;
    mrb_float scale;
    mrb_get_args(mrb, "iiiif", &width, &height, &offsetx, &offsety, &scale);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImagePerlinNoise(width, height, offsetx, offsety, scale);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImageCellular
mrb_value mrb_gen_image_cellular(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_int tilesize;
    mrb_get_args(mrb, "iii", &width, &height, &tilesize);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageCellular(width, height, tilesize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// GenImageText
mrb_value mrb_gen_image_text(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    const char *text;
    mrb_get_args(mrb, "iiz", &width, &height, &text);
    Image *image = (Image *)malloc(sizeof(Image));
    *image = GenImageText(width, height, text);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, image));

    return obj;
}

// ImageCopy
mrb_value mrb_image_copy(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    Image *out_image = (Image *)malloc(sizeof(Image));
    *out_image = ImageCopy(*image);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, out_image));

    return obj;
}

// ImageFromImage
mrb_value mrb_image_from_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Rectangle *rec;
    mrb_get_args(mrb, "dd", &image, &Raylib_Image_type, &rec, &Raylib_Rectangle_type);
    Image *out_image = (Image *)malloc(sizeof(Image));
    *out_image = ImageFromImage(*image, *rec);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, out_image));

    return obj;
}

// ImageText
mrb_value mrb_image_text(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_int fontsize;
    Color *color;
    mrb_get_args(mrb, "zid", &text, &fontsize, &color, &Raylib_Color_type);
    Image *out_image = (Image *)malloc(sizeof(Image));
    *out_image = ImageText(text, fontsize, *color);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, out_image));

    return obj;
}

// ImageTextEx
mrb_value mrb_image_text_ex(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *text;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "dzffd", &font, &Raylib_Font_type, &text, &fontsize, &spacing, &tint, &Raylib_Color_type);
    Image *out_image = (Image *)malloc(sizeof(Image));
    *out_image = ImageTextEx(*font, text, fontsize, spacing, *tint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, out_image));

    return obj;
}

// ImageFormat
mrb_value mrb_image_format(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int newformat;
    mrb_get_args(mrb, "di", &image, &Raylib_Image_type, &newformat);
    ImageFormat(image, newformat);
    return mrb_nil_value();
}

// ImageToPOT
mrb_value mrb_image_to_pot(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Color *fill;
    mrb_get_args(mrb, "dd", &image, &Raylib_Image_type, &fill, &Raylib_Color_type);
    ImageToPOT(image, *fill);
    return mrb_nil_value();
}

// ImageCrop
mrb_value mrb_image_crop(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Rectangle *crop;
    mrb_get_args(mrb, "dd", &image, &Raylib_Image_type, &crop, &Raylib_Rectangle_type);
    ImageCrop(image, *crop);
    return mrb_nil_value();
}

// ImageAlphaCrop
mrb_value mrb_image_alpha_crop(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_float threshold;
    mrb_get_args(mrb, "df", &image, &Raylib_Image_type, &threshold);
    ImageAlphaCrop(image, threshold);
    return mrb_nil_value();
}

// ImageAlphaClear
mrb_value mrb_image_alpha_clear(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Color *color;
    mrb_float threshold;
    mrb_get_args(mrb, "ddf", &image, &Raylib_Image_type, &color, &Raylib_Color_type, &threshold);
    ImageAlphaClear(image, *color, threshold);
    return mrb_nil_value();
}

// ImageAlphaMask
mrb_value mrb_image_alpha_mask(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Image *alphamask;
    mrb_get_args(mrb, "dd", &image, &Raylib_Image_type, &alphamask, &Raylib_Image_type);
    ImageAlphaMask(image, *alphamask);
    return mrb_nil_value();
}

// ImageAlphaPremultiply
mrb_value mrb_image_alpha_premultiply(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageAlphaPremultiply(image);
    return mrb_nil_value();
}

// ImageBlurGaussian
mrb_value mrb_image_blur_gaussian(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int blursize;
    mrb_get_args(mrb, "di", &image, &Raylib_Image_type, &blursize);
    ImageBlurGaussian(image, blursize);
    return mrb_nil_value();
}

// ImageResize
mrb_value mrb_image_resize(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int newwidth;
    mrb_int newheight;
    mrb_get_args(mrb, "dii", &image, &Raylib_Image_type, &newwidth, &newheight);
    ImageResize(image, newwidth, newheight);
    return mrb_nil_value();
}

// ImageResizeNN
mrb_value mrb_image_resize_nn(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int newwidth;
    mrb_int newheight;
    mrb_get_args(mrb, "dii", &image, &Raylib_Image_type, &newwidth, &newheight);
    ImageResizeNN(image, newwidth, newheight);
    return mrb_nil_value();
}

// ImageResizeCanvas
mrb_value mrb_image_resize_canvas(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int newwidth;
    mrb_int newheight;
    mrb_int offsetx;
    mrb_int offsety;
    Color *fill;
    mrb_get_args(mrb, "diiiid", &image, &Raylib_Image_type, &newwidth, &newheight, &offsetx, &offsety, &fill, &Raylib_Color_type);
    ImageResizeCanvas(image, newwidth, newheight, offsetx, offsety, *fill);
    return mrb_nil_value();
}

// ImageMipmaps
mrb_value mrb_image_mipmaps(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageMipmaps(image);
    return mrb_nil_value();
}

// ImageDither
mrb_value mrb_image_dither(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int rbpp;
    mrb_int gbpp;
    mrb_int bbpp;
    mrb_int abpp;
    mrb_get_args(mrb, "diiii", &image, &Raylib_Image_type, &rbpp, &gbpp, &bbpp, &abpp);
    ImageDither(image, rbpp, gbpp, bbpp, abpp);
    return mrb_nil_value();
}

// ImageFlipVertical
mrb_value mrb_image_flip_vertical(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageFlipVertical(image);
    return mrb_nil_value();
}

// ImageFlipHorizontal
mrb_value mrb_image_flip_horizontal(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageFlipHorizontal(image);
    return mrb_nil_value();
}

// ImageRotate
mrb_value mrb_image_rotate(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int degrees;
    mrb_get_args(mrb, "di", &image, &Raylib_Image_type, &degrees);
    ImageRotate(image, degrees);
    return mrb_nil_value();
}

// ImageRotateCW
mrb_value mrb_image_rotate_cw(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageRotateCW(image);
    return mrb_nil_value();
}

// ImageRotateCCW
mrb_value mrb_image_rotate_ccw(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageRotateCCW(image);
    return mrb_nil_value();
}

// ImageColorTint
mrb_value mrb_image_color_tint(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Color *color;
    mrb_get_args(mrb, "dd", &image, &Raylib_Image_type, &color, &Raylib_Color_type);
    ImageColorTint(image, *color);
    return mrb_nil_value();
}

// ImageColorInvert
mrb_value mrb_image_color_invert(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageColorInvert(image);
    return mrb_nil_value();
}

// ImageColorGrayscale
mrb_value mrb_image_color_grayscale(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    ImageColorGrayscale(image);
    return mrb_nil_value();
}

// ImageColorContrast
mrb_value mrb_image_color_contrast(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_float contrast;
    mrb_get_args(mrb, "df", &image, &Raylib_Image_type, &contrast);
    ImageColorContrast(image, contrast);
    return mrb_nil_value();
}

// ImageColorBrightness
mrb_value mrb_image_color_brightness(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int brightness;
    mrb_get_args(mrb, "di", &image, &Raylib_Image_type, &brightness);
    ImageColorBrightness(image, brightness);
    return mrb_nil_value();
}

// ImageColorReplace
mrb_value mrb_image_color_replace(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Color *color;
    Color *replace;
    mrb_get_args(mrb, "ddd", &image, &Raylib_Image_type, &color, &Raylib_Color_type, &replace, &Raylib_Color_type);
    ImageColorReplace(image, *color, *replace);
    return mrb_nil_value();
}

// LoadImageColors
mrb_value mrb_load_image_colors(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    Color *colors = LoadImageColors(*image);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < (image->width * image->height); ++i)
    {
        Color *color = (Color *)malloc(sizeof(Color));
        *color = colors[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, color)));
    }
    return ary;
}

// LoadImagePalette
mrb_value mrb_load_image_palette(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int maxpalettesize;
    mrb_int mcolorcount;
    mrb_get_args(mrb, "dii", &image, &Raylib_Image_type, &maxpalettesize, &mcolorcount);
    int colorcount = 0;
    Color *colors = LoadImagePalette(*image, maxpalettesize, &colorcount);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < colorcount; ++i)
    {
        Color *color = (Color *)malloc(sizeof(Color));
        *color = colors[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, color)));
    }
    return ary;
}

// UnloadImageColors
mrb_value mrb_unload_image_colors(mrb_state *mrb, mrb_value self)
{
    mrb_value colors;
    mrb_get_args(mrb, "A", &colors);
    Color color_values[RARRAY_LEN(colors)];
    for (int i = 0; i < RARRAY_LEN(colors); ++i)
    {
        color_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(colors, i), &Raylib_Color_type, Color);
    }
    UnloadImageColors(color_values);
    return mrb_nil_value();
}

// UnloadImagePalette
mrb_value mrb_unload_image_palette(mrb_state *mrb, mrb_value self)
{
    mrb_value colors;
    mrb_get_args(mrb, "A", &colors);
    Color color_values[RARRAY_LEN(colors)];
    for (int i = 0; i < RARRAY_LEN(colors); ++i)
    {
        color_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(colors, i), &Raylib_Color_type, Color);
    }
    UnloadImagePalette(color_values);
    return mrb_nil_value();
}

// GetImageAlphaBorder
mrb_value mrb_get_image_alpha_border(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_float threshold;
    mrb_get_args(mrb, "df", &image, &Raylib_Image_type, &threshold);
    Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));
    *rectangle = GetImageAlphaBorder(*image, threshold);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Rectangle_class, &Raylib_Rectangle_type, rectangle));

    return obj;
}

// GetImageColor
mrb_value mrb_get_image_color(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int x;
    mrb_int y;
    mrb_get_args(mrb, "dii", &image, &Raylib_Image_type, &x, &y);
    Color *color = (Color *)malloc(sizeof(Color));
    *color = GetImageColor(*image, x, y);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Color_class, &Raylib_Color_type, color));

    return obj;
}

// ImageClearBackground
mrb_value mrb_image_clear_background(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Color *color;
    mrb_get_args(mrb, "dd", &image, &Raylib_Image_type, &color, &Raylib_Color_type);
    ImageClearBackground(image, *color);
    return mrb_nil_value();
}

// ImageDrawPixel
mrb_value mrb_image_draw_pixel(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    mrb_int posx;
    mrb_int posy;
    Color *color;
    mrb_get_args(mrb, "diid", &dst, &Raylib_Image_type, &posx, &posy, &color, &Raylib_Color_type);
    ImageDrawPixel(dst, posx, posy, *color);
    return mrb_nil_value();
}

// ImageDrawPixelV
mrb_value mrb_image_draw_pixel_v(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Vector2 *position;
    Color *color;
    mrb_get_args(mrb, "ddd", &dst, &Raylib_Image_type, &position, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    ImageDrawPixelV(dst, *position, *color);
    return mrb_nil_value();
}

// ImageDrawLine
mrb_value mrb_image_draw_line(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    mrb_int startposx;
    mrb_int startposy;
    mrb_int endposx;
    mrb_int endposy;
    Color *color;
    mrb_get_args(mrb, "diiiid", &dst, &Raylib_Image_type, &startposx, &startposy, &endposx, &endposy, &color, &Raylib_Color_type);
    ImageDrawLine(dst, startposx, startposy, endposx, endposy, *color);
    return mrb_nil_value();
}

// ImageDrawLineV
mrb_value mrb_image_draw_line_v(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Vector2 *start;
    Vector2 *end;
    Color *color;
    mrb_get_args(mrb, "dddd", &dst, &Raylib_Image_type, &start, &Raylib_Vector2_type, &end, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    ImageDrawLineV(dst, *start, *end, *color);
    return mrb_nil_value();
}

// ImageDrawCircle
mrb_value mrb_image_draw_circle(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    mrb_int centerx;
    mrb_int centery;
    mrb_int radius;
    Color *color;
    mrb_get_args(mrb, "diiid", &dst, &Raylib_Image_type, &centerx, &centery, &radius, &color, &Raylib_Color_type);
    ImageDrawCircle(dst, centerx, centery, radius, *color);
    return mrb_nil_value();
}

// ImageDrawCircleV
mrb_value mrb_image_draw_circle_v(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Vector2 *center;
    mrb_int radius;
    Color *color;
    mrb_get_args(mrb, "ddid", &dst, &Raylib_Image_type, &center, &Raylib_Vector2_type, &radius, &color, &Raylib_Color_type);
    ImageDrawCircleV(dst, *center, radius, *color);
    return mrb_nil_value();
}

// ImageDrawCircleLines
mrb_value mrb_image_draw_circle_lines(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    mrb_int centerx;
    mrb_int centery;
    mrb_int radius;
    Color *color;
    mrb_get_args(mrb, "diiid", &dst, &Raylib_Image_type, &centerx, &centery, &radius, &color, &Raylib_Color_type);
    ImageDrawCircleLines(dst, centerx, centery, radius, *color);
    return mrb_nil_value();
}

// ImageDrawCircleLinesV
mrb_value mrb_image_draw_circle_lines_v(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Vector2 *center;
    mrb_int radius;
    Color *color;
    mrb_get_args(mrb, "ddid", &dst, &Raylib_Image_type, &center, &Raylib_Vector2_type, &radius, &color, &Raylib_Color_type);
    ImageDrawCircleLinesV(dst, *center, radius, *color);
    return mrb_nil_value();
}

// ImageDrawRectangle
mrb_value mrb_image_draw_rectangle(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    mrb_int posx;
    mrb_int posy;
    mrb_int width;
    mrb_int height;
    Color *color;
    mrb_get_args(mrb, "diiiid", &dst, &Raylib_Image_type, &posx, &posy, &width, &height, &color, &Raylib_Color_type);
    ImageDrawRectangle(dst, posx, posy, width, height, *color);
    return mrb_nil_value();
}

// ImageDrawRectangleV
mrb_value mrb_image_draw_rectangle_v(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Vector2 *position;
    Vector2 *size;
    Color *color;
    mrb_get_args(mrb, "dddd", &dst, &Raylib_Image_type, &position, &Raylib_Vector2_type, &size, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    ImageDrawRectangleV(dst, *position, *size, *color);
    return mrb_nil_value();
}

// ImageDrawRectangleRec
mrb_value mrb_image_draw_rectangle_rec(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Rectangle *rec;
    Color *color;
    mrb_get_args(mrb, "ddd", &dst, &Raylib_Image_type, &rec, &Raylib_Rectangle_type, &color, &Raylib_Color_type);
    ImageDrawRectangleRec(dst, *rec, *color);
    return mrb_nil_value();
}

// ImageDrawRectangleLines
mrb_value mrb_image_draw_rectangle_lines(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Rectangle *rec;
    mrb_int thick;
    Color *color;
    mrb_get_args(mrb, "ddid", &dst, &Raylib_Image_type, &rec, &Raylib_Rectangle_type, &thick, &color, &Raylib_Color_type);
    ImageDrawRectangleLines(dst, *rec, thick, *color);
    return mrb_nil_value();
}

// ImageDraw
mrb_value mrb_image_draw(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Image *src;
    Rectangle *srcrec;
    Rectangle *dstrec;
    Color *tint;
    mrb_get_args(mrb, "ddddd", &dst, &Raylib_Image_type, &src, &Raylib_Image_type, &srcrec, &Raylib_Rectangle_type, &dstrec, &Raylib_Rectangle_type, &tint, &Raylib_Color_type);
    ImageDraw(dst, *src, *srcrec, *dstrec, *tint);
    return mrb_nil_value();
}

// ImageDrawText
mrb_value mrb_image_draw_text(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    const char *text;
    mrb_int posx;
    mrb_int posy;
    mrb_int fontsize;
    Color *color;
    mrb_get_args(mrb, "dziiid", &dst, &Raylib_Image_type, &text, &posx, &posy, &fontsize, &color, &Raylib_Color_type);
    ImageDrawText(dst, text, posx, posy, fontsize, *color);
    return mrb_nil_value();
}

// ImageDrawTextEx
mrb_value mrb_image_draw_text_ex(mrb_state *mrb, mrb_value self)
{
    Image *dst;
    Font *font;
    const char *text;
    Vector2 *position;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "ddzdffd", &dst, &Raylib_Image_type, &font, &Raylib_Font_type, &text, &position, &Raylib_Vector2_type, &fontsize, &spacing, &tint, &Raylib_Color_type);
    ImageDrawTextEx(dst, *font, text, *position, fontsize, spacing, *tint);
    return mrb_nil_value();
}

void mrb_raylib_setup_image(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_image", mrb_load_image, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_image_raw", mrb_load_image_raw, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "load_image_svg", mrb_load_image_svg, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_image_anim", mrb_load_image_anim, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "load_image_from_memory", mrb_load_image_from_memory, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_image_from_texture", mrb_load_image_from_texture, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_image_from_screen", mrb_load_image_from_screen, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_image_ready?", mrb_is_image_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_image", mrb_unload_image, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_image", mrb_export_image, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "export_image_to_memory", mrb_export_image_to_memory, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "export_image_as_code", mrb_export_image_as_code, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "gen_image_color", mrb_gen_image_color, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_image_gradient_linear", mrb_gen_image_gradient_linear, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "gen_image_gradient_radial", mrb_gen_image_gradient_radial, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "gen_image_gradient_square", mrb_gen_image_gradient_square, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "gen_image_checked", mrb_gen_image_checked, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "gen_image_white_noise", mrb_gen_image_white_noise, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_image_perlin_noise", mrb_gen_image_perlin_noise, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "gen_image_cellular", mrb_gen_image_cellular, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_image_text", mrb_gen_image_text, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "image_copy", mrb_image_copy, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_from_image", mrb_image_from_image, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_text", mrb_image_text, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "image_text_ex", mrb_image_text_ex, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "image_format", mrb_image_format, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_to_pot", mrb_image_to_pot, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_crop", mrb_image_crop, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_alpha_crop", mrb_image_alpha_crop, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_alpha_clear", mrb_image_alpha_clear, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "image_alpha_mask", mrb_image_alpha_mask, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_alpha_premultiply", mrb_image_alpha_premultiply, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_blur_gaussian", mrb_image_blur_gaussian, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_resize", mrb_image_resize, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "image_resize_nn", mrb_image_resize_nn, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "image_resize_canvas", mrb_image_resize_canvas, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "image_mipmaps", mrb_image_mipmaps, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_dither", mrb_image_dither, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "image_flip_vertical", mrb_image_flip_vertical, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_flip_horizontal", mrb_image_flip_horizontal, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_rotate", mrb_image_rotate, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_rotate_cw", mrb_image_rotate_cw, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_rotate_ccw", mrb_image_rotate_ccw, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_color_tint", mrb_image_color_tint, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_color_invert", mrb_image_color_invert, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_color_grayscale", mrb_image_color_grayscale, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "image_color_contrast", mrb_image_color_contrast, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_color_brightness", mrb_image_color_brightness, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "image_color_replace", mrb_image_color_replace, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_image_colors", mrb_load_image_colors, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_image_palette", mrb_load_image_palette, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "unload_image_colors", mrb_unload_image_colors, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_image_palette", mrb_unload_image_palette, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_image_alpha_border", mrb_get_image_alpha_border, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_image_color", mrb_get_image_color, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "image_clear_background", mrb_image_clear_background, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_pixel", mrb_image_draw_pixel, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_pixel_v", mrb_image_draw_pixel_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_line", mrb_image_draw_line, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_line_v", mrb_image_draw_line_v, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_circle", mrb_image_draw_circle, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_v", mrb_image_draw_circle_v, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_lines", mrb_image_draw_circle_lines, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_lines_v", mrb_image_draw_circle_lines_v, MRB_ARGS_REQ(4));

    mrb_define_module_function(mrb, raylib_module, "draw_rectangle", mrb_image_draw_rectangle, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_v", mrb_image_draw_rectangle_v, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_rec", mrb_image_draw_rectangle_rec, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_lines", mrb_image_draw_rectangle_lines, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "image_draw", mrb_image_draw, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "image_draw_text", mrb_image_draw_text, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "image_draw_text_ex", mrb_image_draw_text_ex, MRB_ARGS_REQ(7));
}

//-------
// Shapes Functions
//-------

// SetShapesTexture
mrb_value mrb_set_shapes_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Rectangle *source;
    mrb_get_args(mrb, "dd", &texture, &Raylib_Texture_type, &source, &Raylib_Rectangle_type);
    SetShapesTexture(*texture, *source);
    return mrb_nil_value();
}

// DrawPixel
mrb_value mrb_draw_pixel(mrb_state *mrb, mrb_value self)
{
    mrb_int posx;
    mrb_int posy;
    Color *color;
    mrb_get_args(mrb, "iid", &posx, &posy, &color, &Raylib_Color_type);
    DrawPixel(posx, posy, *color);
    return mrb_nil_value();
}

// DrawPixelV
mrb_value mrb_draw_pixel_v(mrb_state *mrb, mrb_value self)
{
    Vector2 *position;
    Color *color;
    mrb_get_args(mrb, "dd", &position, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    DrawPixelV(*position, *color);
    return mrb_nil_value();
}

// DrawLine
mrb_value mrb_draw_line(mrb_state *mrb, mrb_value self)
{
    mrb_int startposx;
    mrb_int startposy;
    mrb_int endposx;
    mrb_int endposy;
    Color *color;
    mrb_get_args(mrb, "iiiid", &startposx, &startposy, &endposx, &endposy, &color, &Raylib_Color_type);
    DrawLine(startposx, startposy, endposx, endposy, *color);
    return mrb_nil_value();
}

// DrawLineV
mrb_value mrb_draw_line_v(mrb_state *mrb, mrb_value self)
{
    Vector2 *startpos;
    Vector2 *endpos;
    Color *color;
    mrb_get_args(mrb, "ddd", &startpos, &Raylib_Vector2_type, &endpos, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    DrawLineV(*startpos, *endpos, *color);
    return mrb_nil_value();
}

// DrawLineEx
mrb_value mrb_draw_line_ex(mrb_state *mrb, mrb_value self)
{
    Vector2 *startpos;
    Vector2 *endpos;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "ddfd", &startpos, &Raylib_Vector2_type, &endpos, &Raylib_Vector2_type, &thick, &color, &Raylib_Color_type);
    DrawLineEx(*startpos, *endpos, thick, *color);
    return mrb_nil_value();
}

// DrawLineBezier
mrb_value mrb_draw_line_bezier(mrb_state *mrb, mrb_value self)
{
    Vector2 *startpos;
    Vector2 *endpos;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "ddfd", &startpos, &Raylib_Vector2_type, &endpos, &Raylib_Vector2_type, &thick, &color, &Raylib_Color_type);
    DrawLineBezier(*startpos, *endpos, thick, *color);
    return mrb_nil_value();
}

// DrawLineStrip
mrb_value mrb_draw_line_strip(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    Color *color;
    mrb_get_args(mrb, "Aid", &points, &pointcount, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawLineStrip(vector_points, pointcount, *color);
    return mrb_nil_value();
}

// DrawCircle
mrb_value mrb_draw_circle(mrb_state *mrb, mrb_value self)
{
    mrb_int centerx;
    mrb_int centery;
    mrb_float radius;
    Color *color;
    mrb_get_args(mrb, "iifd", &centerx, &centery, &radius, &color, &Raylib_Color_type);
    DrawCircle(centerx, centery, radius, *color);
    return mrb_nil_value();
}

// DrawCircleSector
mrb_value mrb_draw_circle_sector(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_float radius;
    mrb_float startangle;
    mrb_float endangle;
    mrb_int segments;
    Color *color;
    mrb_get_args(mrb, "dfffid", &center, &Raylib_Vector2_type, &radius, &startangle, &endangle, &segments, &color, &Raylib_Color_type);
    DrawCircleSector(*center, radius, startangle, endangle, segments, *color);
    return mrb_nil_value();
}

// DrawCircleSectorLines
mrb_value mrb_draw_circle_sector_lines(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_float radius;
    mrb_float startangle;
    mrb_float endangle;
    mrb_int segments;
    Color *color;
    mrb_get_args(mrb, "dfffid", &center, &Raylib_Vector2_type, &radius, &startangle, &endangle, &segments, &color, &Raylib_Color_type);
    DrawCircleSectorLines(*center, radius, startangle, endangle, segments, *color);
    return mrb_nil_value();
}

// DrawCircleGradient
mrb_value mrb_draw_circle_gradient(mrb_state *mrb, mrb_value self)
{
    mrb_int centerx;
    mrb_int centery;
    mrb_float radius;
    Color *color1;
    Color *color2;
    mrb_get_args(mrb, "iifdd", &centerx, &centery, &radius, &color1, &Raylib_Color_type, &color2, &Raylib_Color_type);
    DrawCircleGradient(centerx, centery, radius, *color1, *color2);
    return mrb_nil_value();
}

// DrawCircleV
mrb_value mrb_draw_circle_v(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_float radius;
    Color *color;
    mrb_get_args(mrb, "dfd", &center, &Raylib_Vector2_type, &radius, &color, &Raylib_Color_type);
    DrawCircleV(*center, radius, *color);
    return mrb_nil_value();
}

// DrawCircleLines
mrb_value mrb_draw_circle_lines(mrb_state *mrb, mrb_value self)
{
    mrb_int centerx;
    mrb_int centery;
    mrb_float radius;
    Color *color;
    mrb_get_args(mrb, "iifd", &centerx, &centery, &radius, &color, &Raylib_Color_type);
    DrawCircleLines(centerx, centery, radius, *color);
    return mrb_nil_value();
}

// DrawCircleLinesV
mrb_value mrb_draw_circle_lines_v(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_float radius;
    Color *color;
    mrb_get_args(mrb, "dfd", &center, &Raylib_Vector2_type, &radius, &color, &Raylib_Color_type);
    DrawCircleLinesV(*center, radius, *color);
    return mrb_nil_value();
}

// DrawEllipse
mrb_value mrb_draw_ellipse(mrb_state *mrb, mrb_value self)
{
    mrb_int centerx;
    mrb_int centery;
    mrb_float radiush;
    mrb_float radiusv;
    Color *color;
    mrb_get_args(mrb, "iiffd", &centerx, &centery, &radiush, &radiusv, &color, &Raylib_Color_type);
    DrawEllipse(centerx, centery, radiush, radiusv, *color);
    return mrb_nil_value();
}

// DrawEllipseLines
mrb_value mrb_draw_ellipse_lines(mrb_state *mrb, mrb_value self)
{
    mrb_int centerx;
    mrb_int centery;
    mrb_float radiush;
    mrb_float radiusv;
    Color *color;
    mrb_get_args(mrb, "iiffd", &centerx, &centery, &radiush, &radiusv, &color, &Raylib_Color_type);
    DrawEllipseLines(centerx, centery, radiush, radiusv, *color);
    return mrb_nil_value();
}

// DrawRing
mrb_value mrb_draw_ring(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_float inneradius;
    mrb_float outeradius;
    mrb_float startangle;
    mrb_float endangle;
    mrb_int segments;
    Color *color;
    mrb_get_args(mrb, "dffffid", &center, &Raylib_Vector2_type, &inneradius, &outeradius, &startangle, &endangle, &segments, &color, &Raylib_Color_type);
    DrawRing(*center, inneradius, outeradius, startangle, endangle, segments, *color);
    return mrb_nil_value();
}

// DrawRingLines
mrb_value mrb_draw_ring_lines(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_float inneradius;
    mrb_float outeradius;
    mrb_float startangle;
    mrb_float endangle;
    mrb_int segments;
    Color *color;
    mrb_get_args(mrb, "dffffid", &center, &Raylib_Vector2_type, &inneradius, &outeradius, &startangle, &endangle, &segments, &color, &Raylib_Color_type);
    DrawRingLines(*center, inneradius, outeradius, startangle, endangle, segments, *color);
    return mrb_nil_value();
}

// DrawRectangle
mrb_value mrb_draw_rectangle(mrb_state *mrb, mrb_value self)
{
    mrb_int posx;
    mrb_int posy;
    mrb_int width;
    mrb_int height;
    Color *color;
    mrb_get_args(mrb, "iiiid", &posx, &posy, &width, &height, &color, &Raylib_Color_type);
    DrawRectangle(posx, posy, width, height, *color);
    return mrb_nil_value();
}

// DrawRectangleV
mrb_value mrb_draw_rectangle_v(mrb_state *mrb, mrb_value self)
{
    Vector2 *position;
    Vector2 *size;
    Color *color;
    mrb_get_args(mrb, "ddd", &position, &Raylib_Vector2_type, &size, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    DrawRectangleV(*position, *size, *color);
    return mrb_nil_value();
}

// DrawRectangleRec
mrb_value mrb_draw_rectangle_rec(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec;
    Color *color;
    mrb_get_args(mrb, "dd", &rec, &Raylib_Rectangle_type, &color, &Raylib_Color_type);
    DrawRectangleRec(*rec, *color);
    return mrb_nil_value();
}

// DrawRectanglePro
mrb_value mrb_draw_rectangle_pro(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec;
    Vector2 *origin;
    mrb_float rotation;
    Color *color;
    mrb_get_args(mrb, "ddfd", &rec, &Raylib_Rectangle_type, &origin, &Raylib_Vector2_type, &rotation, &color, &Raylib_Color_type);
    DrawRectanglePro(*rec, *origin, rotation, *color);
    return mrb_nil_value();
}

// DrawRectangleGradientV
mrb_value mrb_draw_rectangle_gradient_v(mrb_state *mrb, mrb_value self)
{
    mrb_int posx;
    mrb_int posy;
    mrb_int width;
    mrb_int height;
    Color *color1;
    Color *color2;
    mrb_get_args(mrb, "iiiidd", &posx, &posy, &width, &height, &color1, &Raylib_Color_type, &color2, &Raylib_Color_type);
    DrawRectangleGradientV(posx, posy, width, height, *color1, *color2);
    return mrb_nil_value();
}

// DrawRectangleGradientH
mrb_value mrb_draw_rectangle_gradient_h(mrb_state *mrb, mrb_value self)
{
    mrb_int posx;
    mrb_int posy;
    mrb_int width;
    mrb_int height;
    Color *color1;
    Color *color2;
    mrb_get_args(mrb, "iiiidd", &posx, &posy, &width, &height, &color1, &Raylib_Color_type, &color2, &Raylib_Color_type);
    DrawRectangleGradientH(posx, posy, width, height, *color1, *color2);
    return mrb_nil_value();
}

// DrawRectangleGradientEx
mrb_value mrb_draw_rectangle_gradient_ex(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec;
    Color *col1;
    Color *col2;
    Color *col3;
    Color *col4;
    mrb_get_args(mrb, "ddddd", &rec, &Raylib_Rectangle_type, &col1, &Raylib_Color_type, &col2, &Raylib_Color_type, &col3, &Raylib_Color_type, &col4, &Raylib_Color_type);
    DrawRectangleGradientEx(*rec, *col1, *col2, *col3, *col4);
    return mrb_nil_value();
}

// DrawRectangleLines
mrb_value mrb_draw_rectangle_lines(mrb_state *mrb, mrb_value self)
{
    mrb_int posx;
    mrb_int posy;
    mrb_int width;
    mrb_int height;
    Color *color;
    mrb_get_args(mrb, "iiiid", &posx, &posy, &width, &height, &color, &Raylib_Color_type);
    DrawRectangleLines(posx, posy, width, height, *color);
    return mrb_nil_value();
}

// DrawRectangleLinesEx
mrb_value mrb_draw_rectangle_lines_ex(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec;
    mrb_float linethick;
    Color *color;
    mrb_get_args(mrb, "dfd", &rec, &Raylib_Rectangle_type, &linethick, &color, &Raylib_Color_type);
    DrawRectangleLinesEx(*rec, linethick, *color);
    return mrb_nil_value();
}

// DrawRectangleRounded
mrb_value mrb_draw_rectangle_rounded(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec;
    mrb_float roundness;
    mrb_int segments;
    Color *color;
    mrb_get_args(mrb, "dfid", &rec, &Raylib_Rectangle_type, &roundness, &segments, &color, &Raylib_Color_type);
    DrawRectangleRounded(*rec, roundness, segments, *color);
    return mrb_nil_value();
}

// DrawRectangleRoundedLines
mrb_value mrb_draw_rectangle_rounded_lines(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec;
    mrb_float roundness;
    mrb_int segments;
    mrb_float linethick;
    Color *color;
    mrb_get_args(mrb, "dfifd", &rec, &Raylib_Rectangle_type, &roundness, &segments, &linethick, &color, &Raylib_Color_type);
    DrawRectangleRoundedLines(*rec, roundness, segments, linethick, *color);
    return mrb_nil_value();
}

// DrawTriangle
mrb_value mrb_draw_triangle(mrb_state *mrb, mrb_value self)
{
    Vector2 *v1;
    Vector2 *v2;
    Vector2 *v3;
    Color *color;
    mrb_get_args(mrb, "dddd", &v1, &Raylib_Vector2_type, &v2, &Raylib_Vector2_type, &v3, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    DrawTriangle(*v1, *v2, *v3, *color);
    return mrb_nil_value();
}

// DrawTriangleLines
mrb_value mrb_draw_triangle_lines(mrb_state *mrb, mrb_value self)
{
    Vector2 *v1;
    Vector2 *v2;
    Vector2 *v3;
    Color *color;
    mrb_get_args(mrb, "dddd", &v1, &Raylib_Vector2_type, &v2, &Raylib_Vector2_type, &v3, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    DrawTriangleLines(*v1, *v2, *v3, *color);
    return mrb_nil_value();
}

// DrawTriangleFan
mrb_value mrb_draw_triangle_fan(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    Color *color;
    mrb_get_args(mrb, "Aid", &points, &pointcount, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawTriangleFan(vector_points, pointcount, *color);
    return mrb_nil_value();
}

// DrawTriangleStrip
mrb_value mrb_draw_triangle_strip(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    Color *color;
    mrb_get_args(mrb, "Aid", &points, &pointcount, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawTriangleStrip(vector_points, pointcount, *color);
    return mrb_nil_value();
}

// DrawPoly
mrb_value mrb_draw_poly(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_int sides;
    mrb_float radius;
    mrb_float rotation;
    Color *color;
    mrb_get_args(mrb, "diffd", &center, &Raylib_Vector2_type, &sides, &radius, &rotation, &color, &Raylib_Color_type);
    DrawPoly(*center, sides, radius, rotation, *color);
    return mrb_nil_value();
}

// DrawPolyLines
mrb_value mrb_draw_poly_lines(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_int sides;
    mrb_float radius;
    mrb_float rotation;
    Color *color;
    mrb_get_args(mrb, "diffd", &center, &Raylib_Vector2_type, &sides, &radius, &rotation, &color, &Raylib_Color_type);
    DrawPolyLines(*center, sides, radius, rotation, *color);
    return mrb_nil_value();
}

// DrawPolyLinesEx
mrb_value mrb_draw_poly_lines_ex(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_int sides;
    mrb_float radius;
    mrb_float rotation;
    mrb_float linethick;
    Color *color;
    mrb_get_args(mrb, "difffd", &center, &Raylib_Vector2_type, &sides, &radius, &rotation, &linethick, &color, &Raylib_Color_type);
    DrawPolyLinesEx(*center, sides, radius, rotation, linethick, *color);
    return mrb_nil_value();
}

// DrawSplineLinear
mrb_value mrb_draw_spline_linear(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "Aifd", &points, &pointcount, &thick, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawSplineLinear(vector_points, pointcount, thick, *color);
    return mrb_nil_value();
}

// DrawSplineBasis
mrb_value mrb_draw_spline_basis(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "Aifd", &points, &pointcount, &thick, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawSplineBasis(vector_points, pointcount, thick, *color);
    return mrb_nil_value();
}

// DrawSplineCatmullRom
mrb_value mrb_draw_spline_catmull_rom(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "Aifd", &points, &pointcount, &thick, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawSplineCatmullRom(vector_points, pointcount, thick, *color);
    return mrb_nil_value();
}

// DrawSplineBezierQuadratic
mrb_value mrb_draw_spline_bezier_quadratic(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "Aifd", &points, &pointcount, &thick, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawSplineBezierQuadratic(vector_points, pointcount, thick, *color);
    return mrb_nil_value();
}

// DrawSplineBezierCubic
mrb_value mrb_draw_spline_bezier_cubic(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "Aifd", &points, &pointcount, &thick, &color, &Raylib_Color_type);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    DrawSplineBezierCubic(vector_points, pointcount, thick, *color);
    return mrb_nil_value();
}

// DrawSplineSegmentLinear
mrb_value mrb_draw_spline_segment_linear(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *p2;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "ddfd", &p1, &Raylib_Vector2_type, &p2, &Raylib_Vector2_type, &thick, &color, &Raylib_Color_type);
    DrawSplineSegmentLinear(*p1, *p2, thick, *color);
    return mrb_nil_value();
}

// DrawSplineSegmentBasis
mrb_value mrb_draw_spline_segment_basis(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *p2;
    Vector2 *p3;
    Vector2 *p4;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "ddddfd", &p1, &Raylib_Vector2_type, &p2, &Raylib_Vector2_type, &p3, &Raylib_Vector2_type, &p4, &Raylib_Vector2_type, &thick, &color, &Raylib_Color_type);
    DrawSplineSegmentBasis(*p1, *p2, *p3, *p4, thick, *color);
    return mrb_nil_value();
}

// DrawSplineSegmentCatmullRom
mrb_value mrb_draw_spline_segment_catmull_rom(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *p2;
    Vector2 *p3;
    Vector2 *p4;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "ddddfd", &p1, &Raylib_Vector2_type, &p2, &Raylib_Vector2_type, &p3, &Raylib_Vector2_type, &p4, &Raylib_Vector2_type, &thick, &color, &Raylib_Color_type);
    DrawSplineSegmentCatmullRom(*p1, *p2, *p3, *p4, thick, *color);
    return mrb_nil_value();
}

// DrawSplineSegmentBezierQuadratic
mrb_value mrb_draw_spline_segment_bezier_quadratic(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *c2;
    Vector2 *p3;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "dddfd", &p1, &Raylib_Vector2_type, &c2, &Raylib_Vector2_type, &p3, &Raylib_Vector2_type, &thick, &color, &Raylib_Color_type);
    DrawSplineSegmentBezierQuadratic(*p1, *c2, *p3, thick, *color);
    return mrb_nil_value();
}

// DrawSplineSegmentBezierCubic
mrb_value mrb_draw_spline_segment_bezier_cubic(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *c2;
    Vector2 *c3;
    Vector2 *p4;
    mrb_float thick;
    Color *color;
    mrb_get_args(mrb, "ddddfd", &p1, &Raylib_Vector2_type, &c2, &Raylib_Vector2_type, &c3, &Raylib_Vector2_type, &p4, &Raylib_Vector2_type, &thick, &color, &Raylib_Color_type);
    DrawSplineSegmentBezierCubic(*p1, *c2, *c3, *p4, thick, *color);
    return mrb_nil_value();
}

// GetSplinePointLinear
mrb_value mrb_get_spline_point_linear(mrb_state *mrb, mrb_value self)
{
    Vector2 *start;
    Vector2 *end;
    mrb_float t;
    mrb_get_args(mrb, "ddf", &start, &Raylib_Vector2_type, &end, &Raylib_Vector2_type, &t);
    Vector2 *vector = (Vector2 *)malloc(sizeof(Vector2));
    *vector = GetSplinePointLinear(*start, *end, t);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector));

    return obj;
}

// GetSplinePointBasis
mrb_value mrb_get_spline_point_basis(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *p2;
    Vector2 *p3;
    Vector2 *p4;
    mrb_float t;
    mrb_get_args(mrb, "ddddf", &p1, &Raylib_Vector2_type, &p2, &Raylib_Vector2_type, &p3, &Raylib_Vector2_type, &p4, &Raylib_Vector2_type, &t);
    Vector2 *vector = (Vector2 *)malloc(sizeof(Vector2));
    *vector = GetSplinePointBasis(*p1, *p2, *p3, *p4, t);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector));

    return obj;
}

// GetSplinePointCatmullRom
mrb_value mrb_get_spline_point_catmull_rom(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *p2;
    Vector2 *p3;
    Vector2 *p4;
    mrb_float t;
    mrb_get_args(mrb, "ddddf", &p1, &Raylib_Vector2_type, &p2, &Raylib_Vector2_type, &p3, &Raylib_Vector2_type, &p4, &Raylib_Vector2_type, &t);
    Vector2 *vector = (Vector2 *)malloc(sizeof(Vector2));
    *vector = GetSplinePointCatmullRom(*p1, *p2, *p3, *p4, t);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector));

    return obj;
}

// GetSplinePointBezierQuad
mrb_value mrb_get_spline_point_bezier_quad(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *c2;
    Vector2 *p3;
    mrb_float t;
    mrb_get_args(mrb, "dddf", &p1, &Raylib_Vector2_type, &c2, &Raylib_Vector2_type, &p3, &Raylib_Vector2_type, &t);
    Vector2 *vector = (Vector2 *)malloc(sizeof(Vector2));
    *vector = GetSplinePointBezierQuad(*p1, *c2, *p3, t);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector));

    return obj;
}

// GetSplinePointBezierCubic
mrb_value mrb_get_spline_point_bezier_cubic(mrb_state *mrb, mrb_value self)
{
    Vector2 *p1;
    Vector2 *c2;
    Vector2 *c3;
    Vector2 *p4;
    mrb_float t;
    mrb_get_args(mrb, "ddddf", &p1, &Raylib_Vector2_type, &c2, &Raylib_Vector2_type, &c3, &Raylib_Vector2_type, &p4, &Raylib_Vector2_type, &t);
    Vector2 *vector = (Vector2 *)malloc(sizeof(Vector2));
    *vector = GetSplinePointBezierCubic(*p1, *c2, *c3, *p4, t);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector));

    return obj;
}

// CheckCollisionRecs
mrb_value mrb_check_collision_recs(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec1;
    Rectangle *rec2;
    mrb_get_args(mrb, "dd", &rec1, &Raylib_Rectangle_type, &rec2, &Raylib_Rectangle_type);
    return mrb_bool_value(CheckCollisionRecs(*rec1, *rec2));
}

// CheckCollisionCircles
mrb_value mrb_check_collision_circles(mrb_state *mrb, mrb_value self)
{
    Vector2 *center1;
    mrb_float radius1;
    Vector2 *center2;
    mrb_float radius2;
    mrb_get_args(mrb, "dfdf", &center1, &Raylib_Vector2_type, &radius1, &center2, &Raylib_Vector2_type, &radius2);
    return mrb_bool_value(CheckCollisionCircles(*center1, radius1, *center2, radius2));
}

// CheckCollisionCircleRec
mrb_value mrb_check_collision_circle_rec(mrb_state *mrb, mrb_value self)
{
    Vector2 *center;
    mrb_float radius;
    Rectangle *rec;
    mrb_get_args(mrb, "dfd", &center, &Raylib_Vector2_type, &radius, &rec, &Raylib_Rectangle_type);
    return mrb_bool_value(CheckCollisionCircleRec(*center, radius, *rec));
}

// CheckCollisionPointRec
mrb_value mrb_check_collision_point_rec(mrb_state *mrb, mrb_value self)
{
    Vector2 *point;
    Rectangle *rec;
    mrb_get_args(mrb, "dd", &point, &Raylib_Vector2_type, &rec, &Raylib_Rectangle_type);
    return mrb_bool_value(CheckCollisionPointRec(*point, *rec));
}

// CheckCollisionPointCircle
mrb_value mrb_check_collision_point_circle(mrb_state *mrb, mrb_value self)
{
    Vector2 *point;
    Vector2 *center;
    mrb_float radius;
    mrb_get_args(mrb, "ddf", &point, &Raylib_Vector2_type, &center, &Raylib_Vector2_type, &radius);
    return mrb_bool_value(CheckCollisionPointCircle(*point, *center, radius));
}

// CheckCollisionPointTriangle
mrb_value mrb_check_collision_point_triangle(mrb_state *mrb, mrb_value self)
{
    Vector2 *point;
    Vector2 *p1;
    Vector2 *p2;
    Vector2 *p3;
    mrb_get_args(mrb, "dddd", &point, &Raylib_Vector2_type, &p1, &Raylib_Vector2_type, &p2, &Raylib_Vector2_type, &p3, &Raylib_Vector2_type);
    return mrb_bool_value(CheckCollisionPointTriangle(*point, *p1, *p2, *p3));
}

// CheckCollisionPointPoly
mrb_value mrb_check_collision_point_poly(mrb_state *mrb, mrb_value self)
{
    Vector2 *point;
    mrb_value points;
    mrb_int pointcount;
    mrb_get_args(mrb, "dAi", &point, &Raylib_Vector2_type, &points, &pointcount);
    Vector2 vector_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        vector_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector2_type, Vector2);
    }
    return mrb_bool_value(CheckCollisionPointPoly(*point, vector_points, pointcount));
}

// CheckCollisionLines
mrb_value mrb_check_collision_lines(mrb_state *mrb, mrb_value self)
{
    Vector2 *startpos1;
    Vector2 *endpos1;
    Vector2 *startpos2;
    Vector2 *endpos2;
    Vector2 *collisionpoint;
    mrb_get_args(mrb, "ddddd", &startpos1, &Raylib_Vector2_type, &endpos1, &Raylib_Vector2_type, &startpos2,
                 &Raylib_Vector2_type, &endpos2, &Raylib_Vector2_type, &collisionpoint, &Raylib_Vector2_type);
    return mrb_bool_value(CheckCollisionLines(*startpos1, *endpos1, *startpos2, *endpos2, collisionpoint));
}

// CheckCollisionPointLineTriangle
mrb_value mrb_check_collision_point_line(mrb_state *mrb, mrb_value self)
{
    Vector2 *point;
    Vector2 *p1;
    Vector2 *p2;
    mrb_int threshold;
    mrb_get_args(mrb, "dddi", &point, &Raylib_Vector2_type, &p1, &Raylib_Vector2_type, &p2, &Raylib_Vector2_type, &threshold);
    return mrb_bool_value(CheckCollisionPointLine(*point, *p1, *p2, threshold));
}

// GetCollisionRec
mrb_value mrb_get_collision_rec(mrb_state *mrb, mrb_value self)
{
    Rectangle *rec1;
    Rectangle *rec2;
    mrb_get_args(mrb, "dd", &rec1, &Raylib_Rectangle_type, &rec2, &Raylib_Rectangle_type);
    Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));
    *rectangle = GetCollisionRec(*rec1, *rec2);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Rectangle_class, &Raylib_Rectangle_type, rectangle));

    return obj;
}

void mrb_raylib_setup_shapes(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "set_shapes_texture", mrb_set_shapes_texture, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_pixel", mrb_draw_pixel, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_pixel_v", mrb_draw_pixel_v, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_line", mrb_draw_line, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_line_v", mrb_draw_line_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_line_ex", mrb_draw_line_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_line_bezier", mrb_draw_line_bezier, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_line_strip", mrb_draw_line_strip, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_circle", mrb_draw_circle, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_sector", mrb_draw_circle_sector, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_sector_lines", mrb_draw_circle_sector_lines, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_gradient", mrb_draw_circle_gradient, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_v", mrb_draw_circle_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_lines", mrb_draw_circle_lines, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_lines_v", mrb_draw_circle_lines_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_ellipse", mrb_draw_ellipse, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_ellipse_lines", mrb_draw_ellipse_lines, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_ring", mrb_draw_ring, MRB_ARGS_REQ(7));
    mrb_define_module_function(mrb, raylib_module, "draw_ring_lines", mrb_draw_ring_lines, MRB_ARGS_REQ(7));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle", mrb_draw_rectangle, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_v", mrb_draw_rectangle_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_rec", mrb_draw_rectangle_rec, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_pro", mrb_draw_rectangle_pro, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_gradient_v", mrb_draw_rectangle_gradient_v, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_gradient_h", mrb_draw_rectangle_gradient_h, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_gradient_ex", mrb_draw_rectangle_gradient_ex, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_lines", mrb_draw_rectangle_lines, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_lines_ex", mrb_draw_rectangle_lines_ex, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_rounded", mrb_draw_rectangle_rounded, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_rounded_lines", mrb_draw_rectangle_rounded_lines, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle", mrb_draw_triangle, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle_lines", mrb_draw_triangle_lines, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle_fan", mrb_draw_triangle_fan, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle_strip", mrb_draw_triangle_strip, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_poly", mrb_draw_poly, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_poly_lines", mrb_draw_poly_lines, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_poly_lines_ex", mrb_draw_poly_lines_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_linear", mrb_draw_spline_linear, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_basis", mrb_draw_spline_basis, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_catmull_rom", mrb_draw_spline_catmull_rom, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_bezier_quadratic", mrb_draw_spline_bezier_quadratic, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_bezier_cubic", mrb_draw_spline_bezier_cubic, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_segment_linear", mrb_draw_spline_segment_linear, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_segment_basis", mrb_draw_spline_segment_basis, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_segment_catmull_rom", mrb_draw_spline_segment_catmull_rom, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_segment_quadratic", mrb_draw_spline_segment_bezier_quadratic, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_spline_segment_bezier_cubic", mrb_draw_spline_segment_bezier_cubic, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "get_spline_point_linear", mrb_get_spline_point_linear, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_spline_point_basis", mrb_get_spline_point_basis, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "get_spline_point_catmull_rom", mrb_get_spline_point_catmull_rom, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "get_spline_point_bezier_quad", mrb_get_spline_point_bezier_quad, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_spline_point_bezier_cubic", mrb_get_spline_point_bezier_cubic, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "check_collision_recs?", mrb_check_collision_recs, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "check_collision_circles?", mrb_check_collision_circles, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "check_collision_circle_rec?", mrb_check_collision_circle_rec, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "check_collision_point_rec?", mrb_check_collision_point_rec, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "check_collision_point_circle?", mrb_check_collision_point_circle, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "check_collision_point_triangle?", mrb_check_collision_point_triangle, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "check_collision_point_poly?", mrb_check_collision_point_poly, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "check_collision_lines?", mrb_check_collision_lines, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "check_collision_point_line?", mrb_check_collision_point_line, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_collision_rec", mrb_get_collision_rec, MRB_ARGS_REQ(2));
}

//-------
// Texture Functions
//-------

// LoadTexture
mrb_value mrb_load_texture(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Texture *texture = (Texture *)malloc(sizeof(Texture));
    *texture = LoadTexture(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));

    return obj;
}

// LoadTextureFromImage
mrb_value mrb_load_texture_from_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_get_args(mrb, "d", &image, &Raylib_Image_type);
    Texture *texture = (Texture *)malloc(sizeof(Texture));
    *texture = LoadTextureFromImage(*image);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));

    return obj;
}

// LoadTextureCubemap
mrb_value mrb_load_texture_cubemap(mrb_state *mrb, mrb_value self)
{
    Image *image;
    mrb_int layout;
    mrb_get_args(mrb, "di", &image, &Raylib_Image_type, &layout);
    Texture *texture = (Texture *)malloc(sizeof(Texture));
    *texture = LoadTextureCubemap(*image, layout);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Texture_class, &Raylib_Texture_type, texture));

    return obj;
}

// LoadRenderTexture
mrb_value mrb_load_render_texture(mrb_state *mrb, mrb_value self)
{
    mrb_int width;
    mrb_int height;
    mrb_get_args(mrb, "ii", &width, &height);
    RenderTexture *rendertexture = (RenderTexture *)malloc(sizeof(RenderTexture));
    *rendertexture = LoadRenderTexture(width, height);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RenderTexture_class, &Raylib_RenderTexture_type, rendertexture));

    return obj;
}

// IsTextureReady
mrb_value mrb_is_texture_ready(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    return mrb_bool_value(IsTextureReady(*texture));
}

// UnloadTexture
mrb_value mrb_unload_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    UnloadTexture(*texture);

    return mrb_nil_value();
}

// IsRenderTextureReady
mrb_value mrb_is_render_texture_ready(mrb_state *mrb, mrb_value self)
{
    RenderTexture *target;
    mrb_get_args(mrb, "d", &target, &Raylib_RenderTexture_type);
    return mrb_bool_value(IsRenderTextureReady(*target));
}

// UnloadRenderTexture
mrb_value mrb_unload_render_texture(mrb_state *mrb, mrb_value self)
{
    RenderTexture *target;
    mrb_get_args(mrb, "d", &target, &Raylib_RenderTexture_type);
    UnloadRenderTexture(*target);

    return mrb_nil_value();
}

// GenTextureMipmaps
mrb_value mrb_gen_texture_mipmaps(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_get_args(mrb, "d", &texture, &Raylib_Texture_type);
    GenTextureMipmaps(texture);

    return mrb_nil_value();
}

// SetTextureFilter
mrb_value mrb_set_texture_filter(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_int filter;
    mrb_get_args(mrb, "di", &texture, &Raylib_Texture_type, &filter);
    SetTextureFilter(*texture, filter);

    return mrb_nil_value();
}

// SetTextureWrap
mrb_value mrb_set_texture_wrap(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_int wrap;
    mrb_get_args(mrb, "di", &texture, &Raylib_Texture_type, &wrap);
    SetTextureWrap(*texture, wrap);

    return mrb_nil_value();
}

// DrawTexture
mrb_value mrb_draw_texture(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    mrb_int posx;
    mrb_int posy;
    Color *tint;
    mrb_get_args(mrb, "diid", &texture, &Raylib_Texture_type, &posx, &posy, &tint, &Raylib_Color_type);
    DrawTexture(*texture, posx, posy, *tint);

    return mrb_nil_value();
}

// DrawTextureV
mrb_value mrb_draw_texture_v(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Vector2 *position;
    Color *tint;
    mrb_get_args(mrb, "ddd", &texture, &Raylib_Texture_type, &position, &Raylib_Vector2_type, &tint, &Raylib_Color_type);
    DrawTextureV(*texture, *position, *tint);

    return mrb_nil_value();
}

// DrawTextureEx
mrb_value mrb_draw_texture_ex(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Vector2 *position;
    mrb_float rotation;
    mrb_float scale;
    Color *tint;
    mrb_get_args(mrb, "ddffd", &texture, &Raylib_Texture_type, &position, &Raylib_Vector2_type, &rotation, &scale, &tint, &Raylib_Color_type);
    DrawTextureEx(*texture, *position, rotation, scale, *tint);

    return mrb_nil_value();
}

// DrawTextureRec
mrb_value mrb_draw_texture_rec(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Rectangle *source;
    Vector2 *position;
    Color *tint;
    mrb_get_args(mrb, "dddd", &texture, &Raylib_Texture_type, &source, &Raylib_Rectangle_type, &position, &Raylib_Vector2_type, &tint, &Raylib_Color_type);
    DrawTextureRec(*texture, *source, *position, *tint);

    return mrb_nil_value();
}

// DrawTexturePro
mrb_value mrb_draw_texture_pro(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    Rectangle *source;
    Rectangle *dest;
    Vector2 *origin;
    mrb_float rotation;
    Color *tint;
    mrb_get_args(mrb, "ddddfd", &texture, &Raylib_Texture_type, &source, &Raylib_Rectangle_type, &dest, &Raylib_Rectangle_type, &origin, &Raylib_Vector2_type,
                 &rotation, &tint, &Raylib_Color_type);
    DrawTexturePro(*texture, *source, *dest, *origin, rotation, *tint);

    return mrb_nil_value();
}

// DrawTextureNPatch
mrb_value mrb_draw_texture_npatch(mrb_state *mrb, mrb_value self)
{
    Texture *texture;
    NPatchInfo *npatchinfo;
    Rectangle *dest;
    Vector2 *origin;
    mrb_float rotation;
    Color *tint;
    mrb_get_args(mrb, "ddddfd", &texture, &Raylib_Texture_type, &npatchinfo, &Raylib_NPatchInfo_type, &dest, &Raylib_Rectangle_type, &origin, &Raylib_Vector2_type,
                 &rotation, &tint, &Raylib_Color_type);
    DrawTextureNPatch(*texture, *npatchinfo, *dest, *origin, rotation, *tint);

    return mrb_nil_value();
}

void mrb_raylib_setup_texture(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_texture", mrb_load_texture, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_texture_from_image", mrb_load_texture_from_image, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_texture_cubemap", mrb_load_texture_cubemap, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "load_render_texture", mrb_load_render_texture, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_texture_ready?", mrb_is_texture_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_texture", mrb_unload_texture, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_render_texture_ready?", mrb_is_render_texture_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_render_texture", mrb_unload_render_texture, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "gen_texture_mipmaps", mrb_gen_texture_mipmaps, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_texture_filter", mrb_set_texture_filter, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_texture_wrap", mrb_set_texture_wrap, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_texture", mrb_draw_texture, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_v", mrb_draw_texture_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_ex", mrb_draw_texture_ex, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_rec", mrb_draw_texture_rec, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_pro", mrb_draw_texture_pro, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_texture_npatch", mrb_draw_texture_npatch, MRB_ARGS_REQ(6));
}

//-------
// Camera Functions
//-------

// UpdateCamera
mrb_value mrb_update_camera(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    mrb_int mode;
    mrb_get_args(mrb, "di", &camera, &Raylib_Camera_type, &mode);
    UpdateCamera(camera, mode);
    return mrb_nil_value();
}

// UpdateCameraPro
mrb_value mrb_update_camera_pro(mrb_state *mrb, mrb_value self)
{
    Camera *camera;
    Vector3 movement;
    Vector3 rotation;
    mrb_float zoom;
    mrb_get_args(mrb, "dddf", &camera, &Raylib_Camera_type, &movement, &Raylib_Vector3_type, &rotation, &Raylib_Vector3_type, &zoom);
    UpdateCameraPro(camera, movement, rotation, zoom);
    return mrb_nil_value();
}

void mrb_raylib_setup_camera(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "update_camera", mrb_update_camera, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "update_camera_pro", mrb_update_camera_pro, MRB_ARGS_REQ(4));
}

//-------
// Gamepad Functions
//-------

// IsGamepadAvailable
mrb_value mrb_is_gamepad_available(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_get_args(mrb, "i", &gamepad);
    return mrb_bool_value(IsGamepadAvailable(gamepad));
}

// GetGamepadName
mrb_value mrb_get_gamepad_name(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_get_args(mrb, "i", &gamepad);
    return mrb_str_new_cstr(mrb, GetGamepadName(gamepad));
}

// IsGamepadButtonPressed
mrb_value mrb_is_gamepad_button_pressed(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonPressed(gamepad, button));
}

// IsGamepadButtonDown
mrb_value mrb_is_gamepad_button_down(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonDown(gamepad, button));
}

// IsGamepadButtonReleased
mrb_value mrb_is_gamepad_button_released(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonReleased(gamepad, button));
}

// IsGamepadButtonUp
mrb_value mrb_is_gamepad_button_up(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int button;
    mrb_get_args(mrb, "ii", &gamepad, &button);
    return mrb_bool_value(IsGamepadButtonUp(gamepad, button));
}

// GetGamepadButtonPressed
mrb_value mrb_get_gamepad_button_pressed(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetGamepadButtonPressed());
}

// GetGamepadAxisCount
mrb_value mrb_get_gamepad_axis_count(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_get_args(mrb, "i", &gamepad);
    return mrb_int_value(mrb, GetGamepadAxisCount(gamepad));
}

// GetGamepadAxisMovement
mrb_value mrb_get_gamepad_axis_movement(mrb_state *mrb, mrb_value self)
{
    mrb_int gamepad;
    mrb_int axis;
    mrb_get_args(mrb, "ii", &gamepad, &axis);
    return mrb_float_value(mrb, GetGamepadAxisMovement(gamepad, axis));
}

// SetGamepadMappings
mrb_value mrb_set_gamepad_mappings(mrb_state *mrb, mrb_value self)
{
    const char *mappings;
    mrb_get_args(mrb, "z", &mappings);
    return mrb_int_value(mrb, SetGamepadMappings(mappings));
}

void mrb_raylib_setup_gamepad(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_available?", mrb_is_gamepad_available, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_name", mrb_get_gamepad_name, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_pressed?", mrb_is_gamepad_button_pressed, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_down?", mrb_is_gamepad_button_down, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_released?", mrb_is_gamepad_button_released, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "is_gamepad_button_up?", mrb_is_gamepad_button_up, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_button_pressed", mrb_get_gamepad_button_pressed, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_axis_count", mrb_get_gamepad_axis_count, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_gamepad_axis_movement", mrb_get_gamepad_axis_movement, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_gamepad_mappings", mrb_set_gamepad_mappings, MRB_ARGS_REQ(1));
}

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

//-------
// Keyboard Functions
//-------

// IsKeyPressed
mrb_value mrb_is_key_pressed(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyPressed(key));
}

// IsKeyPressedRepeat
mrb_value mrb_is_key_pressed_repeat(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyPressed(key));
}

// IsKeyDown
mrb_value mrb_is_key_down(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyDown(key));
}

// IsKeyReleased
mrb_value mrb_is_key_released(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyReleased(key));
}

// IsKeyUp
mrb_value mrb_is_key_up(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    return mrb_bool_value(IsKeyUp(key));
}

// SetExitKey
mrb_value mrb_set_exit_key(mrb_state *mrb, mrb_value self)
{
    mrb_int key;
    mrb_get_args(mrb, "i", &key);
    SetExitKey(key);
    return mrb_nil_value();
}

// GetKeyPressed
mrb_value mrb_get_key_pressed(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetKeyPressed());
}

// GetCharPressed
mrb_value mrb_get_char_pressed(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetCharPressed());
}

void mrb_raylib_setup_keyboard(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "is_key_pressed?", mrb_is_key_pressed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_pressed_repeat?", mrb_is_key_pressed_repeat, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_down?", mrb_is_key_down, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_released?", mrb_is_key_released, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_key_up?", mrb_is_key_up, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_exit_key", mrb_set_exit_key, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_key_pressed", mrb_get_key_pressed, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_char_pressed", mrb_get_char_pressed, MRB_ARGS_NONE());
}

//-------
// Mouse Functions
//-------

// IsMouseButtonPressed
mrb_value mrb_is_mouse_button_pressed(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonPressed(button));
}

// IsMouseButtonDown
mrb_value mrb_is_mouse_button_down(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonDown(button));
}

// IsMouseButtonReleased
mrb_value mrb_is_mouse_button_released(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonReleased(button));
}

// IsMouseButtonUp
mrb_value mrb_is_mouse_button_up(mrb_state *mrb, mrb_value self)
{
    mrb_int button;
    mrb_get_args(mrb, "i", &button);
    return mrb_bool_value(IsMouseButtonUp(button));
}

// GetMouseX
mrb_value mrb_get_mouse_x(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetMouseX());
}

// GetMouseY
mrb_value mrb_get_mouse_y(mrb_state *mrb, mrb_value self)
{
    return mrb_int_value(mrb, GetMouseY());
}

// GetMousePosition
mrb_value mrb_get_mouse_position(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMousePosition();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// GetMouseDelta
mrb_value mrb_get_mouse_delta(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMouseDelta();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// SetMousePosition
mrb_value mrb_set_mouse_position(mrb_state *mrb, mrb_value self)
{
    mrb_int x;
    mrb_int y;
    mrb_get_args(mrb, "ii", &x, &y);
    SetMousePosition(x, y);
    return mrb_nil_value();
}

// SetMouseOffset
mrb_value mrb_set_mouse_offset(mrb_state *mrb, mrb_value self)
{
    mrb_int offsetx;
    mrb_int offsety;
    mrb_get_args(mrb, "ii", &offsetx, &offsety);
    SetMouseOffset(offsetx, offsety);
    return mrb_nil_value();
}

// SetMouseScale
mrb_value mrb_set_mouse_scale(mrb_state *mrb, mrb_value self)
{
    mrb_float scalex;
    mrb_float scaley;
    mrb_get_args(mrb, "ii", &scalex, &scaley);
    SetMouseScale(scalex, scaley);
    return mrb_nil_value();
}

// GetMouseWheelMove
mrb_value mrb_get_mouse_wheel_move(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, GetMouseWheelMove());
}

// GetMouseWheelMove
mrb_value mrb_get_mouse_wheel_move_v(mrb_state *mrb, mrb_value self)
{
    Vector2 *vector2 = (Vector2 *)malloc(sizeof(Vector2));
    *vector2 = GetMouseWheelMoveV();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, vector2));

    return obj;
}

// SetMouseCursor
mrb_value mrb_set_mouse_cursor(mrb_state *mrb, mrb_value self)
{
    mrb_int cursor;
    mrb_get_args(mrb, "i", &cursor);
    SetMouseCursor(cursor);
    return mrb_nil_value();
}

void mrb_raylib_setup_mouse(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_pressed?", mrb_is_mouse_button_pressed, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_down?", mrb_is_mouse_button_down, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_released?", mrb_is_mouse_button_released, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_mouse_button_up?", mrb_is_mouse_button_up, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_mouse_x", mrb_get_mouse_x, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_y", mrb_get_mouse_y, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_position", mrb_get_mouse_position, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_delta", mrb_get_mouse_delta, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_mouse_position", mrb_set_mouse_position, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_mouse_offset", mrb_set_mouse_offset, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "set_mouse_scale", mrb_set_mouse_scale, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_mouse_wheel_move", mrb_get_mouse_wheel_move, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "get_mouse_wheel_move_v", mrb_get_mouse_wheel_move_v, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "set_mouse_cursor", mrb_set_mouse_cursor, MRB_ARGS_REQ(1));
}

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

//-------
// Collision Detection Functions
//-------

// CheckCollisionSpheres
mrb_value mrb_check_collision_spheres(mrb_state *mrb, mrb_value self)
{
    Vector3 *center1;
    mrb_float radius1;
    Vector3 *center2;
    mrb_float radius2;
    mrb_get_args(mrb, "dfdf", &center1, &Raylib_Vector3_type, &radius1, &center2, &Raylib_Vector3_type, &radius2);
    return mrb_bool_value(CheckCollisionSpheres(*center1, radius1, *center2, radius2));
}

// CheckCollisionBoxes
mrb_value mrb_check_collision_boxes(mrb_state *mrb, mrb_value self)
{
    BoundingBox *box1;
    BoundingBox *box2;
    mrb_get_args(mrb, "dd", &box1, &Raylib_BoundingBox_type, &box2, &Raylib_BoundingBox_type);
    return mrb_bool_value(CheckCollisionBoxes(*box1, *box2));
}

// CheckCollisionBoxSphere
mrb_value mrb_check_collision_box_sphere(mrb_state *mrb, mrb_value self)
{
    BoundingBox *box;
    Vector3 *center;
    mrb_float radius;
    mrb_get_args(mrb, "ddf", &box, &Raylib_BoundingBox_type, &center, &Raylib_Vector3_type, &radius);
    return mrb_bool_value(CheckCollisionBoxSphere(*box, *center, radius));
}

// GetRayCollisionSphere
mrb_value mrb_get_ray_collision_sphere(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Vector3 *center;
    mrb_float radius;
    mrb_get_args(mrb, "ddf", &ray, &Raylib_Ray_type, &center, &Raylib_Vector3_type, &radius);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionSphere(*ray, *center, radius);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionBox
mrb_value mrb_get_ray_collision_box(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    BoundingBox *box;
    mrb_get_args(mrb, "dd", &ray, &Raylib_Ray_type, &box, &Raylib_BoundingBox_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionBox(*ray, *box);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionMesh
mrb_value mrb_get_ray_collision_mesh(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Mesh *mesh;
    Matrix *transform;
    mrb_get_args(mrb, "ddd", &ray, &Raylib_Ray_type, &mesh, &Raylib_Mesh_type, &transform, &Raylib_Matrix_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionMesh(*ray, *mesh, *transform);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionTriangle
mrb_value mrb_get_ray_collision_triangle(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Vector3 *p1;
    Vector3 *p2;
    Vector3 *p3;
    mrb_get_args(mrb, "dddd", &ray, &Raylib_Ray_type, &p1, &Raylib_Vector3_type, &p2, &Raylib_Vector3_type, &p3, &Raylib_Vector3_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionTriangle(*ray, *p1, *p2, *p3);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

// GetRayCollisionQuad
mrb_value mrb_get_ray_collision_quad(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Vector3 *p1;
    Vector3 *p2;
    Vector3 *p3;
    Vector3 *p4;
    mrb_get_args(mrb, "ddddd", &ray, &Raylib_Ray_type, &p1, &Raylib_Vector3_type, &p2, &Raylib_Vector3_type, &p3, &Raylib_Vector3_type, &p4, &Raylib_Vector3_type);
    RayCollision *raycollision = (RayCollision *)malloc(sizeof(RayCollision));
    *raycollision = GetRayCollisionQuad(*ray, *p1, *p2, *p3, *p4);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_RayCollision_class, &Raylib_RayCollision_type, raycollision));

    return obj;
}

void mrb_raylib_setup_collision_detection(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "check_collision_spheres", mrb_check_collision_spheres, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "check_collision_boxes", mrb_check_collision_boxes, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "check_collision_box_sphere", mrb_check_collision_box_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_sphere", mrb_get_ray_collision_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_box", mrb_get_ray_collision_box, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_mesh", mrb_get_ray_collision_mesh, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_triangle", mrb_get_ray_collision_triangle, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_ray_collision_quad", mrb_get_ray_collision_quad, MRB_ARGS_REQ(5));
}

//-------
// Geometric Shapes Functions
//-------

// DrawLine3D
mrb_value mrb_draw_line_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    Color *color;
    mrb_get_args(mrb, "ddd", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawLine3D(*startpos, *endpos, *color);
    return mrb_nil_value();
}

// DrawPoint3D
mrb_value mrb_draw_point_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Color *color;
    mrb_get_args(mrb, "dd", &position, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawPoint3D(*position, *color);
    return mrb_nil_value();
}

// DrawCircle3D
mrb_value mrb_draw_circle_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *center;
    mrb_float radius;
    Vector3 *rotationaxis;
    mrb_float rotationangle;
    Color *color;
    mrb_get_args(mrb, "dfdfd", &center, &Raylib_Vector3_type, &radius, &rotationaxis, &Raylib_Vector3_type, &rotationangle, &color, &Raylib_Color_type);
    DrawCircle3D(*center, radius, *rotationaxis, rotationangle, *color);
    return mrb_nil_value();
}

// DrawTriangle3D
mrb_value mrb_draw_triangle_3d(mrb_state *mrb, mrb_value self)
{
    Vector3 *v1;
    Vector3 *v2;
    Vector3 *v3;
    Color *color;
    mrb_get_args(mrb, "dddd", &v1, &Raylib_Vector3_type, &v2, &Raylib_Vector3_type, &v3, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawTriangle3D(*v1, *v2, *v3, *color);
    return mrb_nil_value();
}

// DrawTriangleStrip3D
mrb_value mrb_draw_triangle_strip_3d(mrb_state *mrb, mrb_value self)
{
    mrb_value points;
    mrb_int pointcount;
    Color *color;
    mrb_get_args(mrb, "Aid", &points, &pointcount, &color, &Raylib_Color_type);
    Vector3 out_points[pointcount];
    for (int i = 0; i < pointcount; ++i)
    {
        out_points[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(points, i), &Raylib_Vector3_type, Vector3);
    }
    DrawTriangleStrip3D(out_points, pointcount, *color);
    return mrb_nil_value();
}

// DrawCube
mrb_value mrb_draw_cube(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float width;
    mrb_float height;
    mrb_float length;
    Color *color;
    mrb_get_args(mrb, "dfffd", &position, &Raylib_Vector3_type, &width, &height, &length, &color, &Raylib_Color_type);
    DrawCube(*position, width, height, length, *color);
    return mrb_nil_value();
}

// DrawCubeV
mrb_value mrb_draw_cube_v(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Vector3 *size;
    Color *color;
    mrb_get_args(mrb, "ddd", &position, &Raylib_Vector3_type, &size, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawCubeV(*position, *size, *color);
    return mrb_nil_value();
}

// DrawCubeWires
mrb_value mrb_draw_cube_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float width;
    mrb_float height;
    mrb_float length;
    Color *color;
    mrb_get_args(mrb, "dfffd", &position, &Raylib_Vector3_type, &width, &height, &length, &color, &Raylib_Color_type);
    DrawCubeWires(*position, width, height, length, *color);
    return mrb_nil_value();
}

// DrawCubeWiresV
mrb_value mrb_draw_cube_wires_v(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    Vector3 *size;
    Color *color;
    mrb_get_args(mrb, "ddd", &position, &Raylib_Vector3_type, &size, &Raylib_Vector3_type, &color, &Raylib_Color_type);
    DrawCubeWiresV(*position, *size, *color);
    return mrb_nil_value();
}

// DrawSphere
mrb_value mrb_draw_sphere(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    mrb_float radius;
    Color *color;
    mrb_get_args(mrb, "dfd", &centerpos, &Raylib_Vector3_type, &radius, &color, &Raylib_Color_type);
    DrawSphere(*centerpos, radius, *color);
    return mrb_nil_value();
}

// DrawSphereEx
mrb_value mrb_draw_sphere_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfiid", &centerpos, &Raylib_Vector3_type, &radius, &rings, &slices, &color, &Raylib_Color_type);
    DrawSphereEx(*centerpos, radius, rings, slices, *color);
    return mrb_nil_value();
}

// DrawSphereWires
mrb_value mrb_draw_sphere_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfiid", &centerpos, &Raylib_Vector3_type, &radius, &rings, &slices, &color, &Raylib_Color_type);
    DrawSphereWires(*centerpos, radius, rings, slices, *color);
    return mrb_nil_value();
}

// DrawCylinder
mrb_value mrb_draw_cylinder(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float radiustop;
    mrb_float radiusbottom;
    mrb_float height;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfffid", &position, &Raylib_Vector3_type, &radiustop, &radiusbottom, &height, &slices, &color, &Raylib_Color_type);
    DrawCylinder(*position, radiustop, radiusbottom, height, slices, *color);
    return mrb_nil_value();
}

// DrawCylinderEx
mrb_value mrb_draw_cylinder_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float startradius;
    mrb_float endradius;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfffid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &startradius, &endradius, &slices, &color, &Raylib_Color_type);
    DrawCylinderEx(*startpos, *endpos, startradius, endradius, slices, *color);
    return mrb_nil_value();
}

// DrawCylinderWires
mrb_value mrb_draw_cylinder_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *position;
    mrb_float radiustop;
    mrb_float radiusbottom;
    mrb_float height;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "dfffid", &position, &Raylib_Vector3_type, &radiustop, &radiusbottom, &height, &slices, &color, &Raylib_Color_type);
    DrawCylinderWires(*position, radiustop, radiusbottom, height, slices, *color);
    return mrb_nil_value();
}

// DrawCylinderWiresEx
mrb_value mrb_draw_cylinder_wires_ex(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float startradius;
    mrb_float endradius;
    mrb_int slices;
    Color *color;
    mrb_get_args(mrb, "ddffid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &startradius, &endradius, &slices, &color, &Raylib_Color_type);
    DrawCylinderWiresEx(*startpos, *endpos, startradius, endradius, slices, *color);
    return mrb_nil_value();
}

// DrawCapsule
mrb_value mrb_draw_capsule(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float radius;
    mrb_int slices;
    mrb_int rings;
    Color *color;
    mrb_get_args(mrb, "ddfiid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &radius, &slices, &rings, &color, &Raylib_Color_type);
    DrawCapsule(*startpos, *endpos, radius, slices, rings, *color);
    return mrb_nil_value();
}

// DrawCapsuleWires
mrb_value mrb_draw_capsule_wires(mrb_state *mrb, mrb_value self)
{
    Vector3 *startpos;
    Vector3 *endpos;
    mrb_float radius;
    mrb_int slices;
    mrb_int rings;
    Color *color;
    mrb_get_args(mrb, "ddfiid", &startpos, &Raylib_Vector3_type, &endpos, &Raylib_Vector3_type, &radius, &slices, &rings, &color, &Raylib_Color_type);
    DrawCapsuleWires(*startpos, *endpos, radius, slices, rings, *color);
    return mrb_nil_value();
}

// DrawPlane
mrb_value mrb_draw_plane(mrb_state *mrb, mrb_value self)
{
    Vector3 *centerpos;
    Vector2 *size;
    Color *color;
    mrb_get_args(mrb, "ddd", &centerpos, &Raylib_Vector3_type, &size, &Raylib_Vector2_type, &color, &Raylib_Color_type);
    DrawPlane(*centerpos, *size, *color);
    return mrb_nil_value();
}

// DrawRay
mrb_value mrb_draw_ray(mrb_state *mrb, mrb_value self)
{
    Ray *ray;
    Color *color;
    mrb_get_args(mrb, "dd", &ray, &Raylib_Ray_type, &color, &Raylib_Color_type);
    DrawRay(*ray, *color);
    return mrb_nil_value();
}

// DrawGrid
mrb_value mrb_draw_grid(mrb_state *mrb, mrb_value self)
{
    mrb_int slices;
    mrb_float spacing;
    mrb_get_args(mrb, "if", &slices, &spacing);
    DrawGrid(slices, spacing);
    return mrb_nil_value();
}

void mrb_raylib_setup_geometric_shapes(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "draw_line_3d", mrb_draw_line_3d, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_point_3d", mrb_draw_point_3d, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_circle_3d", mrb_draw_circle_3d, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle_3d", mrb_draw_triangle_3d, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "draw_triangle_strip_3d", mrb_draw_triangle_strip_3d, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_cube", mrb_draw_cube, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_cube_v", mrb_draw_cube_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_cube_wires", mrb_draw_cube_wires, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_cube_wires_v", mrb_draw_cube_wires_v, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_sphere", mrb_draw_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_sphere_ex", mrb_draw_sphere_ex, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_sphere_wires", mrb_draw_sphere_wires, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder", mrb_draw_cylinder, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder_ex", mrb_draw_cylinder_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder_wires", mrb_draw_cylinder_wires, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_cylinder_wires_ex", mrb_draw_cylinder_wires_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_capsule", mrb_draw_capsule, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_capsule_wires", mrb_draw_capsule_wires, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_plane", mrb_draw_plane, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_ray", mrb_draw_ray, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_grid", mrb_draw_grid, MRB_ARGS_REQ(2));
}

//-------
// Material Loading Functions
//-------

// LoadMaterials
mrb_value mrb_load_materials(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int mmaterialcount;
    mrb_get_args(mrb, "zi", &filename, &mmaterialcount);
    int materialcount = 0;
    Material *materials = LoadMaterials(filename, &materialcount);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < materialcount; ++i)
    {
        Material *material = (Material *)malloc(sizeof(Material));
        *material = materials[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Material_class, &Raylib_Material_type, material)));
    }
    return ary;
}

// LoadMaterialDefault
mrb_value mrb_load_material_default(mrb_state *mrb, mrb_value self)
{
    Material *out = (Material *)malloc(sizeof(Material));
    *out = LoadMaterialDefault();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Material_class, &Raylib_Material_type, out));
    return obj;
}

// IsMaterialReady
mrb_value mrb_is_material_ready(mrb_state *mrb, mrb_value self)
{
    Material *material;
    mrb_get_args(mrb, "d", &material, &Raylib_Material_type);
    return mrb_bool_value(IsMaterialReady(*material));
}

// UnloadMaterial
mrb_value mrb_unload_material(mrb_state *mrb, mrb_value self)
{
    Material *material;
    mrb_get_args(mrb, "d", &material, &Raylib_Material_type);
    UnloadMaterial(*material);
    return mrb_nil_value();
}

// SetMaterialTexture
mrb_value mrb_set_material_texture(mrb_state *mrb, mrb_value self)
{
    Material *material;
    mrb_int maptype;
    Texture *texture;
    mrb_get_args(mrb, "did", &material, &Raylib_Material_type, &maptype, &texture, &Raylib_Texture_type);
    SetMaterialTexture(material, maptype, *texture);
    return mrb_nil_value();
}

// SetModelMeshMaterial
mrb_value mrb_set_model_mesh_material(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_int meshid;
    mrb_int materialid;
    mrb_get_args(mrb, "dii", &model, &Raylib_Model_type, &meshid, &materialid);
    SetModelMeshMaterial(model, meshid, materialid);
    return mrb_nil_value();
}

void mrb_raylib_setup_material_loading(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_materials", mrb_load_materials, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "load_material_default", mrb_load_material_default, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "is_material_ready?", mrb_is_material_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_material", mrb_unload_material, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "set_material_texture", mrb_set_material_texture, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "set_model_mesh_material", mrb_set_model_mesh_material, MRB_ARGS_REQ(3));
}

//-------
// Mesh Generation Functions
//-------

// GenMeshPoly
mrb_value mrb_gen_mesh_poly(mrb_state *mrb, mrb_value self)
{
    mrb_int sides;
    mrb_float radius;
    mrb_get_args(mrb, "if", &sides, &radius);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshPoly(sides, radius);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshPlane
mrb_value mrb_gen_mesh_plane(mrb_state *mrb, mrb_value self)
{
    mrb_float width;
    mrb_float length;
    mrb_int resx;
    mrb_int resz;
    mrb_get_args(mrb, "ffii", &width, &length, &resx, &resz);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshPlane(width, length, resx, resz);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCube
mrb_value mrb_gen_mesh_cube(mrb_state *mrb, mrb_value self)
{
    mrb_float width;
    mrb_float height;
    mrb_float length;
    mrb_get_args(mrb, "fff", &width, &height, &length);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCube(width, height, length);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshSphere
mrb_value mrb_gen_mesh_sphere(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    mrb_get_args(mrb, "fii", &radius, &rings, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshSphere(radius, rings, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshHemiSphere
mrb_value mrb_gen_mesh_hemi_sphere(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_int rings;
    mrb_int slices;
    mrb_get_args(mrb, "fii", &radius, &rings, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshHemiSphere(radius, rings, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCyclinder
mrb_value mrb_gen_mesh_cylinder(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float height;
    mrb_int slices;
    mrb_get_args(mrb, "ffi", &radius, &height, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCylinder(radius, height, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCone
mrb_value mrb_gen_mesh_cone(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float height;
    mrb_int slices;
    mrb_get_args(mrb, "ffi", &radius, &height, &slices);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCone(radius, height, slices);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshTorus
mrb_value mrb_gen_mesh_torus(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float size;
    mrb_int radseg;
    mrb_int sides;
    mrb_get_args(mrb, "ffii", &radius, &size, &radseg, &sides);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshTorus(radius, size, radseg, sides);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshKnot
mrb_value mrb_gen_mesh_knot(mrb_state *mrb, mrb_value self)
{
    mrb_float radius;
    mrb_float size;
    mrb_int radseg;
    mrb_int sides;
    mrb_get_args(mrb, "ffii", &radius, &size, &radseg, &sides);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshKnot(radius, size, radseg, sides);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshHeightmap
mrb_value mrb_gen_mesh_heightmap(mrb_state *mrb, mrb_value self)
{
    Image *heightmap;
    Vector3 *size;
    mrb_get_args(mrb, "dd", &heightmap, &Raylib_Image_type, &size, &Raylib_Vector3_type);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshHeightmap(*heightmap, *size);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

// GenMeshCubicmap
mrb_value mrb_gen_mesh_cubicmap(mrb_state *mrb, mrb_value self)
{
    Image *cubicmap;
    Vector3 *cubesize;
    mrb_get_args(mrb, "dd", &cubicmap, &Raylib_Image_type, &cubesize, &Raylib_Vector3_type);
    Mesh *out = (Mesh *)malloc(sizeof(Mesh));
    *out = GenMeshCubicmap(*cubicmap, *cubesize);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Mesh_class, &Raylib_Mesh_type, out));
    return obj;
}

void mrb_raylib_setup_mesh_generation(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_poly", mrb_gen_mesh_poly, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_plane", mrb_gen_mesh_plane, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cube", mrb_gen_mesh_cube, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_sphere", mrb_gen_mesh_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_hemi_sphere", mrb_gen_mesh_hemi_sphere, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cylinder", mrb_gen_mesh_cylinder, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cone", mrb_gen_mesh_cone, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_torus", mrb_gen_mesh_torus, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_knot", mrb_gen_mesh_knot, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_heightmap", mrb_gen_mesh_heightmap, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_cubicmap", mrb_gen_mesh_cubicmap, MRB_ARGS_REQ(2));
}

//-------
// Mesh Management Functions
//-------

// UploadMesh
mrb_value mrb_upload_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_bool dynamic;
    mrb_get_args(mrb, "db", &mesh, &Raylib_Mesh_type, &dynamic);
    UploadMesh(mesh, dynamic);
    return mrb_nil_value();
}

// UnloadMesh
mrb_value mrb_unload_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    UnloadMesh(*mesh);
    return mrb_nil_value();
}

// DrawMesh
mrb_value mrb_draw_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    Material *material;
    Matrix *transform;
    mrb_get_args(mrb, "ddd", &mesh, &Raylib_Mesh_type, &material, &Raylib_Material_type, &transform, &Raylib_Matrix_type);
    DrawMesh(*mesh, *material, *transform);
    return mrb_nil_value();
}

// DrawMeshInstanced
mrb_value mrb_draw_mesh_instanced(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    Material *material;
    mrb_value transforms;
    mrb_int instances;
    mrb_get_args(mrb, "ddAi", &mesh, &Raylib_Mesh_type, &material, &Raylib_Material_type, &transforms, &instances);
    Matrix out_transforms[instances];
    for (int i = 0; i < instances; ++i)
    {
        out_transforms[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(transforms, i), &Raylib_Matrix_type, Matrix);
    }
    DrawMeshInstanced(*mesh, *material, out_transforms, instances);
    return mrb_nil_value();
}

// ExportMesh
mrb_value mrb_export_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    const char *filename;
    mrb_get_args(mrb, "dz", &mesh, &Raylib_Mesh_type, &filename);
    return mrb_bool_value(ExportMesh(*mesh, filename));
}

// GetMeshBoundingBox
mrb_value mrb_get_mesh_bounding_box(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    BoundingBox *out = (BoundingBox *)malloc(sizeof(BoundingBox));
    *out = GetMeshBoundingBox(*mesh);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_BoundingBox_class, &Raylib_BoundingBox_type, out));
    return obj;
}

// GenMeshTangents
mrb_value mrb_gen_mesh_tangents(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    GenMeshTangents(mesh);
    return mrb_nil_value();
}

void mrb_raylib_setup_mesh_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "upload_mesh", mrb_upload_mesh, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_mesh", mrb_unload_mesh, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "draw_mesh", mrb_draw_mesh, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "draw_mesh_instanced", mrb_draw_mesh_instanced, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "export_mesh", mrb_export_mesh, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_mesh_bounding_box", mrb_get_mesh_bounding_box, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "gen_mesh_tangents", mrb_gen_mesh_tangents, MRB_ARGS_REQ(1));
}

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

//-------
// Model Management Functions
//-------

// LoadModel
mrb_value mrb_load_model(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Model *out = (Model *)malloc(sizeof(Model));
    *out = LoadModel(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Model_class, &Raylib_Model_type, out));

    return obj;
}

// LoadModelFromMesh
mrb_value mrb_load_model_from_mesh(mrb_state *mrb, mrb_value self)
{
    Mesh *mesh;
    mrb_get_args(mrb, "d", &mesh, &Raylib_Mesh_type);
    Model *out = (Model *)malloc(sizeof(Model));
    *out = LoadModelFromMesh(*mesh);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Model_class, &Raylib_Model_type, out));

    return obj;
}

// IsModelReady
mrb_value mrb_is_model_ready(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_get_args(mrb, "d", &model, &Raylib_Model_type);
    return mrb_bool_value(IsModelReady(*model));
}

// UnloadModel
mrb_value mrb_unload_model(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_get_args(mrb, "d", &model, &Raylib_Model_type);
    UnloadModel(*model);
    return mrb_nil_value();
}

// GetModelBoundingBox
mrb_value mrb_get_model_bounding_box(mrb_state *mrb, mrb_value self)
{
    Model *model;
    mrb_get_args(mrb, "d", &model, &Raylib_Model_type);
    BoundingBox *out = (BoundingBox *)malloc(sizeof(BoundingBox));
    *out = GetModelBoundingBox(*model);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_BoundingBox_class, &Raylib_BoundingBox_type, out));

    return obj;
}

void mrb_raylib_setup_model_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_model", mrb_load_model, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_model_from_mesh", mrb_load_model_from_mesh, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "is_model_ready?", mrb_is_model_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "unload_model", mrb_unload_model, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_model_bounding_box", mrb_get_model_bounding_box, MRB_ARGS_REQ(1));
}

//-------
// Font Loading Functions
//-------

// GetFontDefault
mrb_value mrb_get_font_default(mrb_state *mrb, mrb_value self)
{
    Font *out = (Font *)malloc(sizeof(Font));
    *out = GetFontDefault();
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFont
mrb_value mrb_load_font(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_get_args(mrb, "z", &filename);
    Font *out = (Font *)malloc(sizeof(Font));
    *out = LoadFont(filename);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFontEx
mrb_value mrb_load_font_ex(mrb_state *mrb, mrb_value self)
{
    const char *filename;
    mrb_int fontsize;
    mrb_value fontchars;
    mrb_int glyphcount;
    mrb_get_args(mrb, "ziA!i", &filename, &fontsize, &fontchars, &glyphcount);
    Font *out = (Font *)malloc(sizeof(Font));
    if (!mrb_nil_p(fontchars))
    {
        int fontchars_values[glyphcount];
        for (int i = 0; i < glyphcount; ++i)
        {
            fontchars_values[i] = mrb_int(mrb, mrb_ary_entry(fontchars, i));
        }
        *out = LoadFontEx(filename, fontsize, fontchars_values, glyphcount);
    }
    else
    {
        *out = LoadFontEx(filename, fontsize, NULL, glyphcount);
    }
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFontFromImage
mrb_value mrb_load_font_from_image(mrb_state *mrb, mrb_value self)
{
    Image *image;
    Color *key;
    mrb_int firstchar;
    mrb_get_args(mrb, "dds", &image, &Raylib_Image_type, &key, &Raylib_Color_type, &firstchar);
    Font *out = (Font *)malloc(sizeof(Font));
    *out = LoadFontFromImage(*image, *key, firstchar);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// LoadFontFromMemory
mrb_value mrb_load_font_from_memory(mrb_state *mrb, mrb_value self)
{
    const char *filetype;
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_int fontsize;
    mrb_value fontchars;
    mrb_int glyphcount;
    mrb_get_args(mrb, "zziiA!i", &filetype, &filedata, &datasize, &fontsize, &fontchars, &glyphcount);
    Font *out = (Font *)malloc(sizeof(Font));
    if (!mrb_nil_p(fontchars))
    {
        int fontchars_values[glyphcount];
        for (int i = 0; i < glyphcount; ++i)
        {
            fontchars_values[i] = mrb_int(mrb, mrb_ary_entry(fontchars, i));
        }
        *out = LoadFontFromMemory(filetype, filedata, datasize, fontsize, fontchars_values, glyphcount);
    }
    else
    {
        *out = LoadFontFromMemory(filetype, filedata, datasize, fontsize, NULL, glyphcount);
    }
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Font_class, &Raylib_Font_type, out));

    return obj;
}

// IsFontReady
mrb_value mrb_is_font_ready(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_get_args(mrb, "d", &font, &Raylib_Font_type);
    return mrb_bool_value(IsFontReady(*font));
}

// LoadFontData
mrb_value mrb_load_font_data(mrb_state *mrb, mrb_value self)
{
    const unsigned char *filedata;
    mrb_int datasize;
    mrb_int fontsize;
    mrb_value fontchars;
    mrb_int glyphcount;
    mrb_int type;
    mrb_get_args(mrb, "ziiA!ii", &filedata, &datasize, &fontsize, &fontchars, &glyphcount, &type);
    GlyphInfo *out;
    if (!mrb_nil_p(fontchars))
    {
        int fontchars_values[glyphcount];
        for (int i = 0; i < glyphcount; ++i)
        {
            fontchars_values[i] = mrb_int(mrb, mrb_ary_entry(fontchars, i));
        }
        out = LoadFontData(filedata, datasize, fontsize, fontchars_values, glyphcount, type);
    }
    else
    {
        out = LoadFontData(filedata, datasize, fontsize, NULL, glyphcount, type);
    }
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < glyphcount; ++i)
    {
        GlyphInfo *glyph = (GlyphInfo *)malloc(sizeof(GlyphInfo));
        *glyph = out[i];
        mrb_ary_push(mrb, ary, mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_GlyphInfo_class, &Raylib_GlyphInfo_type, glyph)));
    }
    return ary;
}

// GenImageFontAtlas
mrb_value mrb_gen_image_font_atlas(mrb_state *mrb, mrb_value self)
{
    mrb_value chars;
    mrb_value recs;
    mrb_int glyphcount;
    mrb_int fontsize;
    mrb_int padding;
    mrb_int packmethod;
    mrb_get_args(mrb, "AAiiii", &chars, &recs, &glyphcount, &fontsize, &padding, &packmethod);

    GlyphInfo chars_values[glyphcount];
    Rectangle *recs_values[glyphcount];
    for (int i = 0; i < glyphcount; ++i)
    {
        chars_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(chars, i), &Raylib_GlyphInfo_type, GlyphInfo);
        recs_values[i] = DATA_GET_PTR(mrb, mrb_ary_entry(recs, i), &Raylib_Rectangle_type, Rectangle);
    }

    Image *out = (Image *)malloc(sizeof(Image));
    *out = GenImageFontAtlas(chars_values, recs_values, glyphcount, fontsize, padding, packmethod);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Image_class, &Raylib_Image_type, out));

    return obj;
}

// UnloadFontData
mrb_value mrb_unload_font_data(mrb_state *mrb, mrb_value self)
{
    mrb_value chars;
    mrb_int glyphcount;
    mrb_get_args(mrb, "Ai", &chars, &glyphcount);
    GlyphInfo chars_values[glyphcount];
    for (int i = 0; i < glyphcount; ++i)
    {
        chars_values[i] = *DATA_GET_PTR(mrb, mrb_ary_entry(chars, i), &Raylib_GlyphInfo_type, GlyphInfo);
    }
    UnloadFontData(chars_values, glyphcount);
    return mrb_nil_value();
}

// UnloadFont
mrb_value mrb_unload_font(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_get_args(mrb, "d", &font, &Raylib_Font_type);
    UnloadFont(*font);
    return mrb_nil_value();
}

// ExportFontAsCode
mrb_value mrb_export_font_as_code(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *filename;
    mrb_get_args(mrb, "dz", &font, &Raylib_Font_type, &filename);
    return mrb_bool_value(ExportFontAsCode(*font, filename));
}

void mrb_raylib_setup_font_loading(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "get_font_default", mrb_get_font_default, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, raylib_module, "load_font", mrb_load_font, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_font_ex", mrb_load_font_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "load_font_from_image", mrb_load_font_from_image, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "load_font_from_memory", mrb_load_font_from_memory, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "is_font_ready?", mrb_is_font_ready, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_font_data", mrb_load_font_data, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "gen_image_font_atlas", mrb_gen_image_font_atlas, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "unload_font_data", mrb_unload_font_data, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_font", mrb_unload_font, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "export_font_as_code", mrb_export_font_as_code, MRB_ARGS_REQ(2));
}

//-------
// Text Codepoints Management Functions
//-------

// LoadUTF8
mrb_value mrb_load_utf8(mrb_state *mrb, mrb_value self)
{
    mrb_value codepoints;
    mrb_int length;
    mrb_get_args(mrb, "Ai", &codepoints, &length);
    int out_codepoints[length];
    for (int i = 0; i < length; ++i)
    {
        out_codepoints[i] = mrb_int(mrb, mrb_ary_entry(codepoints, i));
    }
    char *out = LoadUTF8(out_codepoints, length);
    mrb_value return_value = mrb_str_new_cstr(mrb, out);
    UnloadUTF8(out);
    return return_value;
}

// UnloadUTF8
mrb_value mrb_unload_utf8(mrb_state *mrb, mrb_value self)
{
    char *text;
    mrb_get_args(mrb, "z", &text);
    UnloadUTF8(text);
    return mrb_nil_value();
}

// LoadCodepoints
mrb_value mrb_load_codepoints(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_int scount;
    mrb_get_args(mrb, "zi", &text, &scount);
    int count = 0;
    int *codepoints = LoadCodepoints(text, &count);
    mrb_value ary = mrb_ary_new(mrb);
    for (int i = 0; i < count; ++i)
    {
        mrb_ary_push(mrb, ary, mrb_int_value(mrb, codepoints[i]));
    }
    UnloadCodepoints(codepoints);
    return ary;
}

// UnloadCodepoints
mrb_value mrb_unload_codepoints(mrb_state *mrb, mrb_value self)
{
    // mrb_value codepoints;
    // mrb_get_args(mrb, "A", &codepoints);
    // int *out_codepoints;
    // for (int i = 0; i < RARRAY_LEN(codepoints); ++i) {
    //     out_codepoints[i] = (int *)DATA_PTR(mrb_ary_entry(codepoints, i));
    // }
    // UnloadCodepoints(out_codepoints);
    return mrb_nil_value();
}

// GetCodepointCount
mrb_value mrb_get_codepoint_count(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_get_args(mrb, "z", &text);
    return mrb_int_value(mrb, GetCodepointCount(text));
}

// GetCodepoint
mrb_value mrb_get_codepoint(mrb_state *mrb, mrb_value self)
{
    const char *text;
    int bytes_processed;
    mrb_get_args(mrb, "zi", &text, &bytes_processed);
    return mrb_int_value(mrb, GetCodepoint(text, &bytes_processed));
}

// GetCodepointNext
mrb_value mrb_get_codepoint_next(mrb_state *mrb, mrb_value self)
{
    const char *text;
    int bytes_processed;
    mrb_get_args(mrb, "zi", &text, &bytes_processed);
    return mrb_int_value(mrb, GetCodepointNext(text, &bytes_processed));
}

// GetCodepointPrevious
mrb_value mrb_get_codepoint_previous(mrb_state *mrb, mrb_value self)
{
    const char *text;
    int bytes_processed;
    mrb_get_args(mrb, "zi", &text, &bytes_processed);
    return mrb_int_value(mrb, GetCodepointPrevious(text, &bytes_processed));
}

// CodepointToUTF8
mrb_value mrb_codepoint_to_utf8(mrb_state *mrb, mrb_value self)
{
    mrb_int codepoint;
    int bytesize;
    mrb_get_args(mrb, "ii", &codepoint, &bytesize);
    return mrb_str_new_cstr(mrb, CodepointToUTF8(codepoint, &bytesize));
}

void mrb_raylib_setup_text_codepoints_management(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "load_utf8", mrb_load_utf8, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_utf8", mrb_unload_utf8, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "load_codepoints", mrb_load_codepoints, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "unload_codepoints", mrb_unload_codepoints, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint_count", mrb_get_codepoint_count, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint", mrb_get_codepoint, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint_next", mrb_get_codepoint_next, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_codepoint_previous", mrb_get_codepoint_previous, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "codepoint_to_utf8", mrb_codepoint_to_utf8, MRB_ARGS_REQ(2));
}

//-------
// Text Drawing Functions
//-------

// DrawFPS
mrb_value mrb_draw_fps(mrb_state *mrb, mrb_value self)
{
    mrb_int posx;
    mrb_int posy;
    mrb_get_args(mrb, "ii", &posx, &posy);
    DrawFPS(posx, posy);
    return mrb_nil_value();
}

// DrawText
mrb_value mrb_draw_text(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_int posx;
    mrb_int posy;
    mrb_int fontsize;
    Color *color;
    mrb_get_args(mrb, "ziiid", &text, &posx, &posy, &fontsize, &color, &Raylib_Color_type);
    DrawText(text, posx, posy, fontsize, *color);
    return mrb_nil_value();
}

// DrawTextEx
mrb_value mrb_draw_text_ex(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *text;
    Vector2 *position;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "dzdffd", &font, &Raylib_Font_type, &text, &position, &Raylib_Vector2_type, &fontsize, &spacing, &tint, &Raylib_Color_type);
    DrawTextEx(*font, text, *position, fontsize, spacing, *tint);
    return mrb_nil_value();
}

// DrawTextPro
mrb_value mrb_draw_text_pro(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *text;
    Vector2 *position;
    Vector2 *origin;
    mrb_float rotation;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "dzddfffd", &font, &Raylib_Font_type, &text, &position, &Raylib_Vector2_type, &origin, &Raylib_Vector2_type, &rotation,
                 &fontsize, &spacing, &tint, &Raylib_Color_type);
    DrawTextPro(*font, text, *position, *origin, rotation, fontsize, spacing, *tint);
    return mrb_nil_value();
}

// DrawTextCodepoint
mrb_value mrb_draw_text_codepoint(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    Vector2 *position;
    mrb_float fontsize;
    Color *tint;
    mrb_get_args(mrb, "didfd", &font, &Raylib_Font_type, &codepoint, &position, &Raylib_Vector2_type, &fontsize, &tint, &Raylib_Color_type);
    DrawTextCodepoint(*font, codepoint, *position, fontsize, *tint);
    return mrb_nil_value();
}

// DrawTextCodepoints
mrb_value mrb_draw_text_codepoints(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_value codepoints;
    mrb_int count;
    Vector2 *position;
    mrb_float fontsize;
    mrb_float spacing;
    Color *tint;
    mrb_get_args(mrb, "dAidffd", &font, &Raylib_Font_type, &codepoints, &count, &position, &Raylib_Vector2_type, &fontsize, &spacing, &tint, &Raylib_Color_type);
    int codepoints_values[count];
    for (int i = 0; i < count; ++i)
    {
        codepoints_values[i] = mrb_int(mrb, mrb_ary_entry(codepoints, i));
    }
    DrawTextCodepoints(*font, codepoints_values, count, *position, fontsize, spacing, *tint);
    return mrb_nil_value();
}

void mrb_raylib_setup_text_drawing(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "draw_fps", mrb_draw_fps, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "draw_text", mrb_draw_text, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_text_ex", mrb_draw_text_ex, MRB_ARGS_REQ(6));
    mrb_define_module_function(mrb, raylib_module, "draw_text_pro", mrb_draw_text_pro, MRB_ARGS_REQ(8));
    mrb_define_module_function(mrb, raylib_module, "draw_text_codepoint", mrb_draw_text_codepoint, MRB_ARGS_REQ(5));
    mrb_define_module_function(mrb, raylib_module, "draw_text_codepoints", mrb_draw_text_codepoints, MRB_ARGS_REQ(7));
}

//-------
// Text Font Info Functions
//-------

// SetTextLineSpacing
mrb_value mrb_set_text_line_spacing(mrb_state *mrb, mrb_value self)
{
    mrb_int spacing;
    mrb_get_args(mrb, "i", &spacing);
    SetTextLineSpacing(spacing);
    return mrb_nil_value();
}

// MeasureText
mrb_value mrb_measure_text(mrb_state *mrb, mrb_value self)
{
    const char *text;
    mrb_int fontsize;
    mrb_get_args(mrb, "zi", &text, &fontsize);
    return mrb_int_value(mrb, MeasureText(text, fontsize));
}

// MeasureTextEx
mrb_value mrb_measure_text_ex(mrb_state *mrb, mrb_value self)
{
    Font *font;
    const char *text;
    mrb_float fontsize;
    mrb_float spacing;
    mrb_get_args(mrb, "dzff", &font, &Raylib_Font_type, &text, &fontsize, &spacing);
    Vector2 *out = (Vector2 *)malloc(sizeof(Vector2));
    *out = MeasureTextEx(*font, text, fontsize, spacing);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Vector2_class, &Raylib_Vector2_type, out));

    return obj;
}

// GetGlyphIndex
mrb_value mrb_get_glyph_index(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    mrb_get_args(mrb, "di", &font, &Raylib_Font_type, &codepoint);
    return mrb_int_value(mrb, GetGlyphIndex(*font, codepoint));
}

// GetGlyphInfo
mrb_value mrb_get_glyph_info(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    mrb_get_args(mrb, "di", &font, &Raylib_Font_type, &codepoint);
    GlyphInfo *out = (GlyphInfo *)malloc(sizeof(GlyphInfo));
    *out = GetGlyphInfo(*font, codepoint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_GlyphInfo_class, &Raylib_GlyphInfo_type, out));

    return obj;
}

// GetGlyphAtlasRec
mrb_value mrb_get_glyph_atlas_rec(mrb_state *mrb, mrb_value self)
{
    Font *font;
    mrb_int codepoint;
    mrb_get_args(mrb, "di", &font, &Raylib_Font_type, &codepoint);
    Rectangle *out = (Rectangle *)malloc(sizeof(Rectangle));
    *out = GetGlyphAtlasRec(*font, codepoint);
    mrb_value obj = mrb_obj_value(Data_Wrap_Struct(mrb, Raylib_Rectangle_class, &Raylib_Rectangle_type, out));

    return obj;
}

void mrb_raylib_setup_text_font_info(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "set_text_line_spacing", mrb_set_text_line_spacing, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, raylib_module, "measure_text", mrb_measure_text, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "measure_text_ex", mrb_measure_text_ex, MRB_ARGS_REQ(4));
    mrb_define_module_function(mrb, raylib_module, "get_glyph_index", mrb_get_glyph_index, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_glyph_info", mrb_get_glyph_info, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, raylib_module, "get_glyph_atlas_rec", mrb_get_glyph_atlas_rec, MRB_ARGS_REQ(2));
}


void mrb_mruby_raylib_gem_init(mrb_state* mrb) {
    struct RClass *Raylib_Raylib_module;
    Raylib_Raylib_module = mrb_define_module(mrb, "Raylib");
    mrb_raylib_setup_audio_device_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_audiostream_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_music_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_wave_loading(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_wave_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_automation_event(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_compression(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_cursor(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_drawing(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_file_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_frame_control(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_misc(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_screen_space(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_shader(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_timing(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_vr(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_window(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_color(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_image(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_shapes(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_texture(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_camera(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_gamepad(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_gestures(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_keyboard(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_mouse(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_touch(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_collision_detection(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_geometric_shapes(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_material_loading(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_mesh_generation(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_mesh_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_model_animation_loading(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_model_drawing(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_model_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_structs(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_font_loading(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_text_codepoints_management(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_text_drawing(mrb, Raylib_Raylib_module);
    mrb_raylib_setup_text_font_info(mrb, Raylib_Raylib_module);

}

void mrb_mruby_raylib_gem_final(mrb_state* mrb) {
    /* finalizer */
}