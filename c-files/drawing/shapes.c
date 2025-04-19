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
    Color *color;
    mrb_get_args(mrb, "dfid", &rec, &Raylib_Rectangle_type, &roundness, &segments, &color, &Raylib_Color_type);
    DrawRectangleRoundedLines(*rec, roundness, segments, *color);
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
    mrb_define_module_function(mrb, raylib_module, "draw_rectangle_rounded_lines", mrb_draw_rectangle_rounded_lines, MRB_ARGS_REQ(4));
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