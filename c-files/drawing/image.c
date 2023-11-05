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