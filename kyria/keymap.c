// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
	_BASE = 0,
	_NUM,
	_SYM,
	_CTL,
	_PTG,
};

enum custom_keycodes {
    CPI_LOW = SAFE_RANGE,
};

// Global variable
#define CURSOR_CPI_BASE 800
#define CURSOR_CPI_LOW  400

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer
 *
 * .-------------------------------------------.                              .-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Esc   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ´ "   |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |   ~    |   Z  |   X  |   C  |   V  |   B  |BackSp| LGUI |  |  Ctl |  Del |   N  |   M  | ,  < | . >  | /  ? |  ` ~   |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        |  Num |L Alt |L Sft |Space |L Ctrl|  |R Ctrl| Enter| R Sft| R Alt| Sym |
 *                        .----------------------------------.  .----------------------------------.
 */
    [_BASE] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                            KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , KC_BSLS,
     KC_ESC  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                            KC_H ,   KC_J ,   KC_K ,   KC_L ,KC_SCLN , KC_QUOT,
 LSFT(KC_GRV), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_BSPC, KC_LGUI,     MO(_CTL) , KC_DEL ,   KC_N ,   KC_M , KC_COMM, KC_DOT ,KC_SLSH , KC_GRV ,
                                TT(_NUM), KC_LALT, KC_LSFT, KC_SPC , KC_LCTL,     KC_RCTL ,KC_ENTER, KC_RSFT, KC_RALT,MO(_SYM),

     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/*
 * Numove Layer
 *
 * .-------------------------------------------.                              .-------------------------------------------.
 * |        | xxxx |   7  |   8  |   9  | xxxx |                              | HOME |P DOWN| PG UP|  END | xxxx |  xxxx  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | xxxx |   4  |   5  |   6  | xxxx |                              |   ←  |   ↓  |   ↑  |   →  |Scrl ↑|  xxxx  |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |  PTG  |   0  |   1  |   2  |   3  | xxxx |      |      |  |      |      |Mouse←|Mouse↓|Mouse↑|Mouse→|Scrl ↓|  xxxx  |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        |      |      |      |      |      |  |      |      |Clic 1|Clic 2|Clic 3|
 *                        .----------------------------------.  .----------------------------------.
 */
    [_NUM] = LAYOUT_split_3x6_5_hlc(
     _______ ,XXXXXXX , KC_7   , KC_8   , KC_9   , XXXXXXX,                                         KC_HOME , KC_PGDN, KC_PGUP, KC_END ,XXXXXXX ,XXXXXXX ,
     _______ ,XXXXXXX , KC_4   , KC_5   , KC_6   , XXXXXXX,                                         KC_LEFT , KC_DOWN,  KC_UP ,KC_RIGHT, MS_WHLU,XXXXXXX ,
     TG(_PTG), KC_0   , KC_1   , KC_2   , KC_3   , XXXXXXX, _______, _______,     _______ ,_______ ,MS_LEFT , MS_DOWN,  MS_UP , MS_RGHT, MS_WHLD,XXXXXXX ,
                                 _______, _______, _______, _______, _______,     _______ ,_______ ,MS_BTN1 , MS_BTN2, MS_BTN3,

     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/*
 * Symbols Layer
 *
 * .-------------------------------------------.                              .-------------------------------------------.
 * |        | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |                              |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |    `   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   &  |   *  |   (  |   )  |    _   |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |    ~   |   /  |   *  |   -  |   +  |   =  |      | xxxx |  |      |      |   <  |   {  |   [  |   ]  |   }  |    >   |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        |      |      |      |      |      |  |      |      |      |      | xxxx |
 *                        .----------------------------------.  .----------------------------------.
 */
    [_SYM] = LAYOUT_split_3x6_5_hlc(
     _______ ,   KC_1   ,   KC_2   ,   KC_3   ,   KC_4     ,   KC_5   ,                                                 KC_6   ,     KC_7    ,   KC_8   ,   KC_9   ,     KC_0    ,    KC_GRV   ,
     _______ ,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4)  ,LSFT(KC_5),                                             LSFT(KC_6) ,  LSFT(KC_7) ,LSFT(KC_8),LSFT(KC_9),  LSFT(KC_0) ,LSFT(KC_MINS),
 LSFT(KC_GRV), KC_SLSH  ,LSFT(KC_8),  KC_MINS ,LSFT(KC_EQL),  KC_EQL  ,_______ ,XXXXXXX ,     _______ , _______  ,LSFT(KC_COMM),LSFT(KC_LBRC),  KC_LBRC ,  KC_RBRC ,LSFT(KC_RBRC), LSFT(KC_DOT),
                                      _______ ,  _______   ,  _______ ,_______ ,_______ ,     _______ , _______  ,   _______   ,   _______   , _______,

     XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,    XXXXXXX ,                                                                       XXXXXXX   ,  XXXXXXX ,  XXXXXXX , XXXXXXX  , XXXXXXX
    ),

/*
 * Control Layer
 *
 * .-------------------------------------------.                              .-------------------------------------------.
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |                              |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CLR EE | xxxx |Reboot|DBGTOG| xxxx | xxxx |                              | xxxx | xxxx |HSV H↓|HSV H↑|HSV S↓| HSV S↑ |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * | Pause  |PrScrn|ScrLck|Insert|NumLck|LEDTOG| xxxx | xxxx |  | xxxx | xxxx | LED ←| LED →|LED B↓|LED B↑|LED S↓| LED S↑ |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        |      |      |      |      |      |  | xxxx | xxxx | xxxx | xxxx |      |
 *                        .----------------------------------.  .----------------------------------.
 */
    [_CTL] = LAYOUT_split_3x6_5_hlc(
       KC_F1 ,   KC_F2  ,   KC_F3  ,   KC_F4  ,   KC_F5    ,   KC_F6  ,                                                 KC_F7  ,     KC_F8   ,   KC_F9  ,  KC_F10  ,     KC_F11  ,    KC_F12   ,
      EE_CLR , XXXXXXX ,   QK_RBT  ,  DB_TOGG ,   XXXXXXX  ,  XXXXXXX ,                                                XXXXXXX ,     XXXXXXX ,  RM_HUED ,  RM_HUEU ,     RM_SATD ,    RM_SATU  ,
     KC_PAUSE, KC_PSCR ,   KC_SCRL ,   KC_INS , KC_NUM_LOCK,  RM_TOGG ,XXXXXXX ,XXXXXXX ,     XXXXXXX , XXXXXXX  ,     RM_PREV ,     RM_NEXT ,  RM_VALD ,  RM_VALU ,     RM_SPDD ,    RM_SPDU  ,
                                      _______ ,  _______   ,  _______ ,_______ ,_______ ,     XXXXXXX , XXXXXXX  ,   XXXXXXX   ,   XXXXXXX   , _______,

     XXXXXXX , XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,                                                                          XXXXXXX,  XXXXXXX ,  XXXXXXX ,     XXXXXXX , XXXXXXX
    ),

/*
 * Pointing Layer
 *
 * .-------------------------------------------.                              .-------------------------------------------.
 * |  xxxx  | xxxx | xxxx | xxxx | xxxx | xxxx |                              | xxxx | xxxx | xxxx | xxxx | xxxx |  xxxx  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  xxxx  | xxxx |Clic 2|Clic 3|Clic 1| xxxx |                              | xxxx | xxxx | xxxx | xxxx | xxxx |  xxxx  |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |   PTG  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |  |Clic 1|Clic 2| xxxx | xxxx | xxxx | xxxx | xxxx |  xxxx  |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        | xxxx | xxxx | xxxx | xxxx | xxxx |  |Clic 3| xxxx | xxxx | xxxx | xxxx |
 *                        .----------------------------------.  .----------------------------------.
 */
    [_PTG] = LAYOUT_split_3x6_5_hlc(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX, XXXXXXX, MS_BTN2, MS_BTN3, MS_BTN1, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    TG(_PTG), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MS_BTN1 ,MS_BTN2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                XXXXXXX, XXXXXXX, XXXXXXX, CPI_LOW, XXXXXXX,      MS_BTN3 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,

     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),

};

/*
 * New Layer
 *
 * .-------------------------------------------.                              .-------------------------------------------.
 * |  xxxx  | xxxx | xxxx | xxxx | xxxx | xxxx |                              | xxxx | xxxx | xxxx | xxxx | xxxx |  xxxx  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  xxxx  | xxxx | xxxx | xxxx | xxxx | xxxx |                              | xxxx | xxxx | xxxx | xxxx | xxxx |  xxxx  |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |  xxxx  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |  xxxx  |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        | xxxx | xxxx | xxxx | xxxx | xxxx |  | xxxx | xxxx | xxxx | xxxx | xxxx |
 *                        .----------------------------------.  .----------------------------------.
    [_PTG] = LAYOUT_split_3x6_5_hlc(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,

     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),

};
*/

// Encoders
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_NUM] =  { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_SYM] =  { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_CTL] = { ENCODER_CCW_CW(QK_LED_MATRIX_BRIGHTNESS_DOWN, QK_LED_MATRIX_BRIGHTNESS_UP),  ENCODER_CCW_CW(QK_LED_MATRIX_SPEED_DOWN, QK_LED_MATRIX_SPEED_UP)  },
    [_PTG] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
};
#endif

void keyboard_post_init_user(void) {
}

void matrix_init_user(void) {
    // Start with a defined RGB matrix effect
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_LAYER_INDICATOR);
}

void pointing_device_init_user(void) {
    pointing_device_set_cpi(CURSOR_CPI_BASE);
    set_auto_mouse_layer(_PTG);
    set_auto_mouse_enable(true);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CPI_LOW:
            if (record->event.pressed) {
                pointing_device_set_cpi(CURSOR_CPI_LOW);
            } else {
                pointing_device_set_cpi(CURSOR_CPI_BASE);
            }
            return false;
    }
    return true;
}
