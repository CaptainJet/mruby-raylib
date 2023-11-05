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

mrb_data_type Raylib_Ray_type = {"Ray", mrb_free};
struct RClass *Raylib_Ray_class;

mrb_data_type Raylib_RayCollision_type = {"RayCollision", mrb_free};
struct RClass *Raylib_RayCollision_class;

mrb_data_type Raylib_BoundingBox_type = {"BoundingBox", mrb_free};
struct RClass *Raylib_BoundingBox_class;

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

    Raylib_RayCollision_class = mrb_define_class_under(mrb, raylib_module, "RayCollision", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_RayCollision_class, MRB_TT_CDATA);

    Raylib_BoundingBox_class = mrb_define_class_under(mrb, raylib_module, "BoundingBox", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_BoundingBox_class, MRB_TT_CDATA);

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

    Raylib_AutomationEvent_class = mrb_define_class_under(mrb, raylib_module, "AutomationEvent", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_AutomationEvent_class, MRB_TT_CDATA);

    Raylib_AutomationEventList_class = mrb_define_class_under(mrb, raylib_module, "AutomationEventList", mrb->object_class);
    MRB_SET_INSTANCE_TT(Raylib_AutomationEventList_class, MRB_TT_CDATA);
}