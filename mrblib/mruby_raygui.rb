
module RayGUI

  RAYGUI_VERSION_MAJOR = 4
  RAYGUI_VERSION_MINOR = 5
  RAYGUI_VERSION_PATCH = 0
  RAYGUI_VERSION = "5.0-dev"
  SCROLLBAR_LEFT_SIDE = 0
  SCROLLBAR_RIGHT_SIDE = 1
  RAYGUI_ICON_SIZE = 16
  RAYGUI_ICON_MAX_ICONS = 256
  RAYGUI_ICON_MAX_NAME_LENGTH = 32
  RAYGUI_MAX_CONTROLS = 16
  RAYGUI_MAX_PROPS_BASE = 16
  RAYGUI_MAX_PROPS_EXTENDED = 8
  KEY_RIGHT = 262
  KEY_LEFT = 263
  KEY_DOWN = 264
  KEY_UP = 265
  KEY_BACKSPACE = 259
  KEY_ENTER = 257
  MOUSE_LEFT_BUTTON = 0
  RAYGUI_WINDOWBOX_STATUSBAR_HEIGHT = 24
  RAYGUI_WINDOWBOX_CLOSEBUTTON_HEIGHT = 18
  RAYGUI_GROUPBOX_LINE_THICK = 1
  RAYGUI_LINE_MARGIN_TEXT = 12
  RAYGUI_LINE_TEXT_PADDING = 4
  RAYGUI_PANEL_BORDER_WIDTH = 1
  RAYGUI_TABBAR_ITEM_WIDTH = 160
  RAYGUI_MIN_SCROLLBAR_WIDTH = 40
  RAYGUI_MIN_SCROLLBAR_HEIGHT = 40
  RAYGUI_MIN_MOUSE_WHEEL_SPEED = 20
  RAYGUI_TOGGLEGROUP_MAX_ITEMS = 32
  RAYGUI_TEXTBOX_AUTO_CURSOR_COOLDOWN = 30
  RAYGUI_TEXTBOX_AUTO_CURSOR_DELAY = 2
  RAYGUI_VALUEBOX_MAX_CHARS = 32
  RAYGUI_COLORBARALPHA_CHECKED_SIZE = 10
  RAYGUI_MESSAGEBOX_BUTTON_HEIGHT = 24
  RAYGUI_MESSAGEBOX_BUTTON_PADDING = 12
  RAYGUI_TEXTINPUTBOX_BUTTON_HEIGHT = 24
  RAYGUI_TEXTINPUTBOX_BUTTON_PADDING = 12
  RAYGUI_TEXTINPUTBOX_HEIGHT = 26
  RAYGUI_GRID_ALPHA = 0.15
  MAX_LINE_BUFFER_SIZE = 256
  ICON_TEXT_PADDING = 4
  RAYGUI_MAX_TEXT_LINES = 128
  RAYGUI_TEXTSPLIT_MAX_ITEMS = 128
  RAYGUI_TEXTSPLIT_MAX_TEXT_SIZE = 1024
  RAYGUI_TEXTFORMAT_MAX_SIZE = 256

  module GuiState

    STATE_NORMAL = 0 # 
    STATE_FOCUSED = 1 # 
    STATE_PRESSED = 2 # 
    STATE_DISABLED = 3 # 

  end

  module GuiTextAlignment

    TEXT_ALIGN_LEFT = 0 # 
    TEXT_ALIGN_CENTER = 1 # 
    TEXT_ALIGN_RIGHT = 2 # 

  end

  module GuiTextAlignmentVertical

    TEXT_ALIGN_TOP = 0 # 
    TEXT_ALIGN_MIDDLE = 1 # 
    TEXT_ALIGN_BOTTOM = 2 # 

  end

  module GuiTextWrapMode

    TEXT_WRAP_NONE = 0 # 
    TEXT_WRAP_CHAR = 1 # 
    TEXT_WRAP_WORD = 2 # 

  end

  module GuiControl

    DEFAULT = 0 # 
    LABEL = 1 # Used also for: LABELBUTTON
    BUTTON = 2 # 
    TOGGLE = 3 # Used also for: TOGGLEGROUP
    SLIDER = 4 # Used also for: SLIDERBAR, TOGGLESLIDER
    PROGRESSBAR = 5 # 
    CHECKBOX = 6 # 
    COMBOBOX = 7 # 
    DROPDOWNBOX = 8 # 
    TEXTBOX = 9 # Used also for: TEXTBOXMULTI
    VALUEBOX = 10 # 
    CONTROL11 = 11 # 
    LISTVIEW = 12 # 
    COLORPICKER = 13 # 
    SCROLLBAR = 14 # 
    STATUSBAR = 15 # 

  end

  module GuiControlProperty

    BORDER_COLOR_NORMAL = 0 # Control border color in STATE_NORMAL
    BASE_COLOR_NORMAL = 1 # Control base color in STATE_NORMAL
    TEXT_COLOR_NORMAL = 2 # Control text color in STATE_NORMAL
    BORDER_COLOR_FOCUSED = 3 # Control border color in STATE_FOCUSED
    BASE_COLOR_FOCUSED = 4 # Control base color in STATE_FOCUSED
    TEXT_COLOR_FOCUSED = 5 # Control text color in STATE_FOCUSED
    BORDER_COLOR_PRESSED = 6 # Control border color in STATE_PRESSED
    BASE_COLOR_PRESSED = 7 # Control base color in STATE_PRESSED
    TEXT_COLOR_PRESSED = 8 # Control text color in STATE_PRESSED
    BORDER_COLOR_DISABLED = 9 # Control border color in STATE_DISABLED
    BASE_COLOR_DISABLED = 10 # Control base color in STATE_DISABLED
    TEXT_COLOR_DISABLED = 11 # Control text color in STATE_DISABLED
    BORDER_WIDTH = 12 # Control border size, 0 for no border
    TEXT_PADDING = 13 # Control text padding, not considering border
    TEXT_ALIGNMENT = 14 # Control text horizontal alignment inside control text bound (after border and padding)

  end

  module GuiDefaultProperty

    TEXT_SIZE = 16 # Text size (glyphs max height)
    TEXT_SPACING = 17 # Text spacing between glyphs
    LINE_COLOR = 18 # Line control color
    BACKGROUND_COLOR = 19 # Background color
    TEXT_LINE_SPACING = 20 # Text spacing between lines
    TEXT_ALIGNMENT_VERTICAL = 21 # Text vertical alignment inside text bounds (after border and padding)
    TEXT_WRAP_MODE = 22 # Text wrap-mode inside text bounds

  end

  module GuiToggleProperty

    GROUP_PADDING = 16 # ToggleGroup separation between toggles

  end

  module GuiSliderProperty

    SLIDER_WIDTH = 16 # Slider size of internal bar
    SLIDER_PADDING = 17 # Slider/SliderBar internal bar padding

  end

  module GuiProgressBarProperty

    PROGRESS_PADDING = 16 # ProgressBar internal padding

  end

  module GuiScrollBarProperty

    ARROWS_SIZE = 16 # ScrollBar arrows size
    ARROWS_VISIBLE = 17 # ScrollBar arrows visible
    SCROLL_SLIDER_PADDING = 18 # ScrollBar slider internal padding
    SCROLL_SLIDER_SIZE = 19 # ScrollBar slider size
    SCROLL_PADDING = 20 # ScrollBar scroll padding from arrows
    SCROLL_SPEED = 21 # ScrollBar scrolling speed

  end

  module GuiCheckBoxProperty

    CHECK_PADDING = 16 # CheckBox internal check padding

  end

  module GuiComboBoxProperty

    COMBO_BUTTON_WIDTH = 16 # ComboBox right button width
    COMBO_BUTTON_SPACING = 17 # ComboBox button separation

  end

  module GuiDropdownBoxProperty

    ARROW_PADDING = 16 # DropdownBox arrow separation from border and items
    DROPDOWN_ITEMS_SPACING = 17 # DropdownBox items separation
    DROPDOWN_ARROW_HIDDEN = 18 # DropdownBox arrow hidden
    DROPDOWN_ROLL_UP = 19 # DropdownBox roll up flag (default rolls down)

  end

  module GuiTextBoxProperty

    TEXT_READONLY = 16 # TextBox in read-only mode: 0-text editable, 1-text no-editable

  end

  module GuiValueBoxProperty

    SPINNER_BUTTON_WIDTH = 16 # Spinner left/right buttons width
    SPINNER_BUTTON_SPACING = 17 # Spinner buttons separation

  end

  module GuiListViewProperty

    LIST_ITEMS_HEIGHT = 16 # ListView items height
    LIST_ITEMS_SPACING = 17 # ListView items separation
    SCROLLBAR_WIDTH = 18 # ListView scrollbar size (usually width)
    SCROLLBAR_SIDE = 19 # ListView scrollbar side (0-SCROLLBAR_LEFT_SIDE, 1-SCROLLBAR_RIGHT_SIDE)
    LIST_ITEMS_BORDER_NORMAL = 20 # ListView items border enabled in normal state
    LIST_ITEMS_BORDER_WIDTH = 21 # ListView items border width

  end

  module GuiColorPickerProperty

    COLOR_SELECTOR_SIZE = 16 # 
    HUEBAR_WIDTH = 17 # ColorPicker right hue bar width
    HUEBAR_PADDING = 18 # ColorPicker right hue bar separation from panel
    HUEBAR_SELECTOR_HEIGHT = 19 # ColorPicker right hue bar selector height
    HUEBAR_SELECTOR_OVERFLOW = 20 # ColorPicker right hue bar selector overflow

  end

  module GuiIconName

    ICON_NONE = 0 # 
    ICON_FOLDER_FILE_OPEN = 1 # 
    ICON_FILE_SAVE_CLASSIC = 2 # 
    ICON_FOLDER_OPEN = 3 # 
    ICON_FOLDER_SAVE = 4 # 
    ICON_FILE_OPEN = 5 # 
    ICON_FILE_SAVE = 6 # 
    ICON_FILE_EXPORT = 7 # 
    ICON_FILE_ADD = 8 # 
    ICON_FILE_DELETE = 9 # 
    ICON_FILETYPE_TEXT = 10 # 
    ICON_FILETYPE_AUDIO = 11 # 
    ICON_FILETYPE_IMAGE = 12 # 
    ICON_FILETYPE_PLAY = 13 # 
    ICON_FILETYPE_VIDEO = 14 # 
    ICON_FILETYPE_INFO = 15 # 
    ICON_FILE_COPY = 16 # 
    ICON_FILE_CUT = 17 # 
    ICON_FILE_PASTE = 18 # 
    ICON_CURSOR_HAND = 19 # 
    ICON_CURSOR_POINTER = 20 # 
    ICON_CURSOR_CLASSIC = 21 # 
    ICON_PENCIL = 22 # 
    ICON_PENCIL_BIG = 23 # 
    ICON_BRUSH_CLASSIC = 24 # 
    ICON_BRUSH_PAINTER = 25 # 
    ICON_WATER_DROP = 26 # 
    ICON_COLOR_PICKER = 27 # 
    ICON_RUBBER = 28 # 
    ICON_COLOR_BUCKET = 29 # 
    ICON_TEXT_T = 30 # 
    ICON_TEXT_A = 31 # 
    ICON_SCALE = 32 # 
    ICON_RESIZE = 33 # 
    ICON_FILTER_POINT = 34 # 
    ICON_FILTER_BILINEAR = 35 # 
    ICON_CROP = 36 # 
    ICON_CROP_ALPHA = 37 # 
    ICON_SQUARE_TOGGLE = 38 # 
    ICON_SYMMETRY = 39 # 
    ICON_SYMMETRY_HORIZONTAL = 40 # 
    ICON_SYMMETRY_VERTICAL = 41 # 
    ICON_LENS = 42 # 
    ICON_LENS_BIG = 43 # 
    ICON_EYE_ON = 44 # 
    ICON_EYE_OFF = 45 # 
    ICON_FILTER_TOP = 46 # 
    ICON_FILTER = 47 # 
    ICON_TARGET_POINT = 48 # 
    ICON_TARGET_SMALL = 49 # 
    ICON_TARGET_BIG = 50 # 
    ICON_TARGET_MOVE = 51 # 
    ICON_CURSOR_MOVE = 52 # 
    ICON_CURSOR_SCALE = 53 # 
    ICON_CURSOR_SCALE_RIGHT = 54 # 
    ICON_CURSOR_SCALE_LEFT = 55 # 
    ICON_UNDO = 56 # 
    ICON_REDO = 57 # 
    ICON_REREDO = 58 # 
    ICON_MUTATE = 59 # 
    ICON_ROTATE = 60 # 
    ICON_REPEAT = 61 # 
    ICON_SHUFFLE = 62 # 
    ICON_EMPTYBOX = 63 # 
    ICON_TARGET = 64 # 
    ICON_TARGET_SMALL_FILL = 65 # 
    ICON_TARGET_BIG_FILL = 66 # 
    ICON_TARGET_MOVE_FILL = 67 # 
    ICON_CURSOR_MOVE_FILL = 68 # 
    ICON_CURSOR_SCALE_FILL = 69 # 
    ICON_CURSOR_SCALE_RIGHT_FILL = 70 # 
    ICON_CURSOR_SCALE_LEFT_FILL = 71 # 
    ICON_UNDO_FILL = 72 # 
    ICON_REDO_FILL = 73 # 
    ICON_REREDO_FILL = 74 # 
    ICON_MUTATE_FILL = 75 # 
    ICON_ROTATE_FILL = 76 # 
    ICON_REPEAT_FILL = 77 # 
    ICON_SHUFFLE_FILL = 78 # 
    ICON_EMPTYBOX_SMALL = 79 # 
    ICON_BOX = 80 # 
    ICON_BOX_TOP = 81 # 
    ICON_BOX_TOP_RIGHT = 82 # 
    ICON_BOX_RIGHT = 83 # 
    ICON_BOX_BOTTOM_RIGHT = 84 # 
    ICON_BOX_BOTTOM = 85 # 
    ICON_BOX_BOTTOM_LEFT = 86 # 
    ICON_BOX_LEFT = 87 # 
    ICON_BOX_TOP_LEFT = 88 # 
    ICON_BOX_CENTER = 89 # 
    ICON_BOX_CIRCLE_MASK = 90 # 
    ICON_POT = 91 # 
    ICON_ALPHA_MULTIPLY = 92 # 
    ICON_ALPHA_CLEAR = 93 # 
    ICON_DITHERING = 94 # 
    ICON_MIPMAPS = 95 # 
    ICON_BOX_GRID = 96 # 
    ICON_GRID = 97 # 
    ICON_BOX_CORNERS_SMALL = 98 # 
    ICON_BOX_CORNERS_BIG = 99 # 
    ICON_FOUR_BOXES = 100 # 
    ICON_GRID_FILL = 101 # 
    ICON_BOX_MULTISIZE = 102 # 
    ICON_ZOOM_SMALL = 103 # 
    ICON_ZOOM_MEDIUM = 104 # 
    ICON_ZOOM_BIG = 105 # 
    ICON_ZOOM_ALL = 106 # 
    ICON_ZOOM_CENTER = 107 # 
    ICON_BOX_DOTS_SMALL = 108 # 
    ICON_BOX_DOTS_BIG = 109 # 
    ICON_BOX_CONCENTRIC = 110 # 
    ICON_BOX_GRID_BIG = 111 # 
    ICON_OK_TICK = 112 # 
    ICON_CROSS = 113 # 
    ICON_ARROW_LEFT = 114 # 
    ICON_ARROW_RIGHT = 115 # 
    ICON_ARROW_DOWN = 116 # 
    ICON_ARROW_UP = 117 # 
    ICON_ARROW_LEFT_FILL = 118 # 
    ICON_ARROW_RIGHT_FILL = 119 # 
    ICON_ARROW_DOWN_FILL = 120 # 
    ICON_ARROW_UP_FILL = 121 # 
    ICON_AUDIO = 122 # 
    ICON_FX = 123 # 
    ICON_WAVE = 124 # 
    ICON_WAVE_SINUS = 125 # 
    ICON_WAVE_SQUARE = 126 # 
    ICON_WAVE_TRIANGULAR = 127 # 
    ICON_CROSS_SMALL = 128 # 
    ICON_PLAYER_PREVIOUS = 129 # 
    ICON_PLAYER_PLAY_BACK = 130 # 
    ICON_PLAYER_PLAY = 131 # 
    ICON_PLAYER_PAUSE = 132 # 
    ICON_PLAYER_STOP = 133 # 
    ICON_PLAYER_NEXT = 134 # 
    ICON_PLAYER_RECORD = 135 # 
    ICON_MAGNET = 136 # 
    ICON_LOCK_CLOSE = 137 # 
    ICON_LOCK_OPEN = 138 # 
    ICON_CLOCK = 139 # 
    ICON_TOOLS = 140 # 
    ICON_GEAR = 141 # 
    ICON_GEAR_BIG = 142 # 
    ICON_BIN = 143 # 
    ICON_HAND_POINTER = 144 # 
    ICON_LASER = 145 # 
    ICON_COIN = 146 # 
    ICON_EXPLOSION = 147 # 
    ICON_1UP = 148 # 
    ICON_PLAYER = 149 # 
    ICON_PLAYER_JUMP = 150 # 
    ICON_KEY = 151 # 
    ICON_DEMON = 152 # 
    ICON_TEXT_POPUP = 153 # 
    ICON_GEAR_EX = 154 # 
    ICON_CRACK = 155 # 
    ICON_CRACK_POINTS = 156 # 
    ICON_STAR = 157 # 
    ICON_DOOR = 158 # 
    ICON_EXIT = 159 # 
    ICON_MODE_2D = 160 # 
    ICON_MODE_3D = 161 # 
    ICON_CUBE = 162 # 
    ICON_CUBE_FACE_TOP = 163 # 
    ICON_CUBE_FACE_LEFT = 164 # 
    ICON_CUBE_FACE_FRONT = 165 # 
    ICON_CUBE_FACE_BOTTOM = 166 # 
    ICON_CUBE_FACE_RIGHT = 167 # 
    ICON_CUBE_FACE_BACK = 168 # 
    ICON_CAMERA = 169 # 
    ICON_SPECIAL = 170 # 
    ICON_LINK_NET = 171 # 
    ICON_LINK_BOXES = 172 # 
    ICON_LINK_MULTI = 173 # 
    ICON_LINK = 174 # 
    ICON_LINK_BROKE = 175 # 
    ICON_TEXT_NOTES = 176 # 
    ICON_NOTEBOOK = 177 # 
    ICON_SUITCASE = 178 # 
    ICON_SUITCASE_ZIP = 179 # 
    ICON_MAILBOX = 180 # 
    ICON_MONITOR = 181 # 
    ICON_PRINTER = 182 # 
    ICON_PHOTO_CAMERA = 183 # 
    ICON_PHOTO_CAMERA_FLASH = 184 # 
    ICON_HOUSE = 185 # 
    ICON_HEART = 186 # 
    ICON_CORNER = 187 # 
    ICON_VERTICAL_BARS = 188 # 
    ICON_VERTICAL_BARS_FILL = 189 # 
    ICON_LIFE_BARS = 190 # 
    ICON_INFO = 191 # 
    ICON_CROSSLINE = 192 # 
    ICON_HELP = 193 # 
    ICON_FILETYPE_ALPHA = 194 # 
    ICON_FILETYPE_HOME = 195 # 
    ICON_LAYERS_VISIBLE = 196 # 
    ICON_LAYERS = 197 # 
    ICON_WINDOW = 198 # 
    ICON_HIDPI = 199 # 
    ICON_FILETYPE_BINARY = 200 # 
    ICON_HEX = 201 # 
    ICON_SHIELD = 202 # 
    ICON_FILE_NEW = 203 # 
    ICON_FOLDER_ADD = 204 # 
    ICON_ALARM = 205 # 
    ICON_CPU = 206 # 
    ICON_ROM = 207 # 
    ICON_STEP_OVER = 208 # 
    ICON_STEP_INTO = 209 # 
    ICON_STEP_OUT = 210 # 
    ICON_RESTART = 211 # 
    ICON_BREAKPOINT_ON = 212 # 
    ICON_BREAKPOINT_OFF = 213 # 
    ICON_BURGER_MENU = 214 # 
    ICON_CASE_SENSITIVE = 215 # 
    ICON_REG_EXP = 216 # 
    ICON_FOLDER = 217 # 
    ICON_FILE = 218 # 
    ICON_SAND_TIMER = 219 # 
    ICON_WARNING = 220 # 
    ICON_HELP_BOX = 221 # 
    ICON_INFO_BOX = 222 # 
    ICON_PRIORITY = 223 # 
    ICON_LAYERS_ISO = 224 # 
    ICON_LAYERS2 = 225 # 
    ICON_MLAYERS = 226 # 
    ICON_MAPS = 227 # 
    ICON_HOT = 228 # 
    ICON_LABEL = 229 # 
    ICON_NAME_ID = 230 # 
    ICON_SLICING = 231 # 
    ICON_MANUAL_CONTROL = 232 # 
    ICON_COLLISION = 233 # 
    ICON_234 = 234 # 
    ICON_235 = 235 # 
    ICON_236 = 236 # 
    ICON_237 = 237 # 
    ICON_238 = 238 # 
    ICON_239 = 239 # 
    ICON_240 = 240 # 
    ICON_241 = 241 # 
    ICON_242 = 242 # 
    ICON_243 = 243 # 
    ICON_244 = 244 # 
    ICON_245 = 245 # 
    ICON_246 = 246 # 
    ICON_247 = 247 # 
    ICON_248 = 248 # 
    ICON_249 = 249 # 
    ICON_250 = 250 # 
    ICON_251 = 251 # 
    ICON_252 = 252 # 
    ICON_253 = 253 # 
    ICON_254 = 254 # 
    ICON_255 = 255 # 

  end

  def self.include_enums
    include GuiState
    include GuiTextAlignment
    include GuiTextAlignmentVertical
    include GuiTextWrapMode
    include GuiControl
    include GuiControlProperty
    include GuiDefaultProperty
    include GuiToggleProperty
    include GuiSliderProperty
    include GuiProgressBarProperty
    include GuiScrollBarProperty
    include GuiCheckBoxProperty
    include GuiComboBoxProperty
    include GuiDropdownBoxProperty
    include GuiTextBoxProperty
    include GuiValueBoxProperty
    include GuiListViewProperty
    include GuiColorPickerProperty
    include GuiIconName
  end

end