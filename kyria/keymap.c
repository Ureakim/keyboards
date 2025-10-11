// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
	_BASE = 0,
	_NUMOVE,
	_SYM,
	_CTRL,
};


// Aliases for readability
#define MO_NUM     MO(_NUMOVE)
#define MO_SYM     MO(_SYM)
#define MO_CTRL     MO(_CTRL)

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
 * |   ~    |   Z  |   X  |   C  |   V  |   B  |BackSp|Numove|  |  Sym |  Del |   N  |   M  | ,  < | . >  | /  ? |  ` ~   |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        | LGUI |L Alt |L Sft |Space |L Ctrl|  |R Ctrl| Enter| R Sft| R Alt| CTRL |
 *                        .----------------------------------.  .----------------------------------.
 */
    [_BASE] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                            KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , KC_BSLS,
     KC_ESC  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                            KC_H ,   KC_J ,   KC_K ,   KC_L ,KC_SCLN , KC_QUOT,
 LSFT(KC_GRV), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_BSPC, MO_NUM ,     MO_SYM  , KC_DEL ,   KC_N ,   KC_M , KC_COMM, KC_DOT ,KC_SLSH , KC_GRV ,
                                 KC_LGUI, KC_LALT, KC_LSFT, KC_SPC , KC_LCTL,     KC_RCTL ,KC_ENTER, KC_RSFT, KC_RALT, MO_CTRL,

	 XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

/*
 * Numove Layer
 *
 * .-------------------------------------------.                              .-------------------------------------------.
 * |        | xxxx | xxxx |   7  |   8  |   9  |                              | HOME |P DOWN| PG UP|  END | xxxx |  xxxx  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | xxxx | xxxx |   4  |   5  |   6  |                              |   ←  |   ↓  |   ↑  |   →  |Scrl ↑|  xxxx  |
 * |--------+------+------+------+------+------+-------------.  .-------------+------+------+------+------+------+--------|
 * |  xxxx  | xxxx |   0  |   1  |   2  |   3  |      |      |  | xxxx |      |Mouse←|Mouse↓|Mouse↑|Mouse→|Scrl ↓|  xxxx  |
 * .----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------.
 *                        |      |      |      |      |      |  |      |      |Clic 1|Clic 2|Clic 3|
 *                        .----------------------------------.  .----------------------------------.
 */
    [_NUMOVE] = LAYOUT_split_3x6_5_hlc(
     _______ ,XXXXXXX ,XXXXXXX , KC_7   , KC_8   , KC_9   ,                                         KC_HOME , KC_PGDN, KC_PGUP, KC_END ,XXXXXXX ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX , KC_4   , KC_5   , KC_6   ,                                         KC_LEFT , KC_DOWN,  KC_UP ,KC_RIGHT, MS_WHLU,XXXXXXX ,
     XXXXXXX ,XXXXXXX , KC_0   , KC_1   , KC_2   , KC_3   , _______, _______,     XXXXXXX ,_______ ,MS_LEFT , MS_DOWN,  MS_UP , MS_RGHT, MS_WHLD,XXXXXXX ,
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
    [_CTRL] = LAYOUT_split_3x6_5_hlc(
       KC_F1 ,   KC_F2  ,   KC_F3  ,   KC_F4  ,   KC_F5    ,   KC_F6  ,                                                 KC_F7  ,     KC_F8   ,   KC_F9  ,  KC_F10  ,     KC_F11  ,    KC_F12   ,
      EE_CLR , XXXXXXX ,   QK_RBT  ,  DB_TOGG ,   XXXXXXX  ,  XXXXXXX ,                                                XXXXXXX ,     XXXXXXX ,  RM_HUED ,  RM_HUEU ,     RM_SATD ,    RM_SATU  ,
     KC_PAUSE, KC_PSCR ,   KC_SCRL ,   KC_INS , KC_NUM_LOCK,  RM_TOGG ,XXXXXXX ,XXXXXXX ,     XXXXXXX , XXXXXXX  ,     RM_PREV ,     RM_NEXT ,  RM_VALD ,  RM_VALU ,     RM_SPDD ,    RM_SPDU  ,
                                      _______ ,  _______   ,  _______ ,_______ ,_______ ,     XXXXXXX , XXXXXXX  ,   XXXXXXX   ,   XXXXXXX   , _______,

     XXXXXXX , XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,                                                                          XXXXXXX,  XXXXXXX ,  XXXXXXX ,     XXXXXXX , XXXXXXX
    ),

};

// Encoders
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN),  ENCODER_CCW_CW(QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_DOWN)  },
    [_NUMOVE] = { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN),  ENCODER_CCW_CW(QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_DOWN)  },
    [_SYM] = { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN),  ENCODER_CCW_CW(QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_DOWN)  },
    [_CTRL] = { ENCODER_CCW_CW(QK_LED_MATRIX_BRIGHTNESS_UP, QK_LED_MATRIX_BRIGHTNESS_DOWN),  ENCODER_CCW_CW(QK_LED_MATRIX_SPEED_UP, QK_LED_MATRIX_SPEED_DOWN)  },
};
#endif

void keyboard_post_init_user(void) {
    #if defined(RGB_MATRIX_CUSTOM_USER)
    // Start with a defined RGB matrix effect
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_LAYER_INDICATOR);
    #endif
}
