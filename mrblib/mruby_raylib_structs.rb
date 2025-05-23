module Raylib
  class Vector2
    def to_a
      [x, y]
    end

    def initialize_copy
      Vector2.new(*to_a)
    end

    def ==(other)
      other.class == self.class && other.to_a == to_a
    end
    alias_method :eql?, :==

    def hash
      to_a.hash
    end
  end

  class Vector3
    def to_a
      [x, y, z]
    end

    def initialize_copy
      Vector3.new(*to_a)
    end

    def ==(other)
      other.class == self.class && other.to_a == to_a
    end
    alias_method :eql?, :==

    def hash
      to_a.hash
    end
  end

  class Vector4
    def to_a
      [x, y, z, w]
    end

    def initialize_copy
      Vector4.new(*to_a)
    end

    def ==(other)
      other.class == self.class && other.to_a == to_a
    end
    alias_method :eql?, :==

    def hash
      to_a.hash
    end
  end

  class Matrix
    def to_a
      [m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15]
    end

    def initialize_copy
      Matrix.new(*to_a)
    end

    def ==(other)
      other.class == self.class && other.to_a == to_a
    end
    alias_method :eql?, :==

    def hash
      to_a.hash
    end
  end

  class Color
    def to_a
      [r, g, b, a]
    end

    def initialize_copy
      Color.new(*to_a)
    end

    def ==(other)
      other.class == self.class && other.to_a == to_a
    end
    alias_method :eql?, :==

    def hash
      to_a.hash
    end
  end

  class Rectangle
    def to_a
      [x, y, width, height]
    end

    def initialize_copy
      Rectangle.new(*to_a)
    end

    def ==(other)
      other.class == self.class && other.to_a == to_a
    end
    alias_method :eql?, :==

    def hash
      to_a.hash
    end
  end

  class RenderTexture
    alias_method :r_texture, :texture
    def texture
      @texture ||= r_texture
    end

    alias_method :r_depth, :depth
    def depth
      @depth ||= r_depth
    end

    alias_method :r_texture_set, :texture=
    def texture=(texture)
      r_texture_set(texture)
      @texture = texture
    end

    alias_method :r_depth_set, :depth=
    def depth=(depth)
      r_depth_set(depth)
      @depth = depth
    end
  end

  class NPatchInfo
    alias_method :r_source, :source
    def source
      @source ||= r_source
    end

    alias_method :r_source_set, :source=
    def source=(source)
      r_source_set(source)
      @source = source
    end

    def to_a
      [source, left, top, right, bottom, layout]
    end

    def initialize_copy
      NPatchInfo.new(*to_a.collect { |a| a.clone })
    end

    def ==(other)
      other.class == self.class && other.to_a == to_a
    end
    alias_method :eql?, :==

    def hash
      to_a.hash
    end
  end

  class GlyphInfo
    alias_method :r_image, :image
    def image
      @image ||= r_image
    end

    alias_method :r_image_set, :image=
    def image=(image)
      r_image_set(image)
      @image = image
    end
  end

  class Font
    alias_method :r_texture, :texture
    def texture
      @texture ||= r_texture
    end

    alias_method :r_texture_set, :texture=
    def texture=(texture)
      r_texture_set(texture)
      @texture = texture
    end
  end

  class Camera
    alias_method :r_position, :position
    def position
      @position ||= r_position
    end

    alias_method :r_target, :target
    def target
      @target ||= r_target
    end

    alias_method :r_up, :up
    def up
      @up ||= r_up
    end

    alias_method :r_position_set, :position=
    def position=(position)
      r_position_set(position)
      @position = position
    end

    alias_method :r_target_set, :target=
    def target=(target)
      r_target_set(target)
      @target = target
    end

    alias_method :r_up_set, :up=
    def up=(up)
      r_up_set(up)
      @up = up
    end
  end

  class Camera2D
    alias_method :r_offset, :offset
    def offset
      @offset ||= r_offset
    end
    alias_method :r_target, :target
    def target
      @target ||= r_target
    end

    alias_method :r_offset_set, :offset=
    def offset=(offset)
      r_offset_set(offset)
      @offset = offset
    end

    alias_method :r_target_set, :target=
    def target=(target)
      r_target_set(target)
      @target = target
    end
  end

  class Ray
    alias_method :r_position, :position
    def position
      @position ||= r_position
    end
    alias_method :r_direction, :direction
    def direction
      @direction ||= r_direction
    end

    alias_method :r_position_set, :position=
    def position=(position)
      r_position_set(position)
      @position = position
    end

    alias_method :r_direction_set, :direction=
    def direction=(direction)
      r_direction_set(direction)
      @direction = direction
    end
  end

  class RayCollision
    alias_method :r_point, :point
    def point
      @point ||= r_point
    end
    alias_method :r_normal, :normal
    def normal
      @normal ||= r_normal
    end

    alias_method :r_point_set, :point=
    def point=(point)
      r_point_set(point)
      @point = point
    end

    alias_method :r_normal_set, :normal=
    def normal=(normal)
      r_normal_set(normal)
      @normal = normal
    end
  end

  class BoundingBox
    alias_method :r_min, :min
    def min
      @min ||= r_min
    end
    alias_method :r_max, :max
    def max
      @max ||= r_max
    end

    alias_method :r_min_set, :min=
    def min=(min)
      r_min_set(min)
      @min = min
    end

    alias_method :r_max_set, :max=
    def max=(max)
      r_max_set(max)
      @max = max
    end
  end

  class AutomationEventList
    alias_method :r_events, :events
    def events
      @events ||= r_events
    end

    alias_method :r_events_set, :events=
    def events=(events)
      r_events_set(events)
      @events = events
    end
  end
end
