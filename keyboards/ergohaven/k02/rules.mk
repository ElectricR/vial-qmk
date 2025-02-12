# MCU name
MCU = RP2040
BOARD = GENERIC_RP_RP2040
BOOTLOADER = rp2040

# Bootloader selection
ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend

# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
#RGBLIGHT_DRIVER = WS2812
WS2812_DRIVER = vendor
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

VIALRGB_ENABLE = yes
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
LTO_ENABLE = no
VIA_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
UNICODE_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
