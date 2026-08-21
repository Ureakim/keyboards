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

enum {
    TD_RALT_OSL,
};


// Global variable
#define CURSOR_CPI_BASE 400
#define CURSOR_CPI_LOW  200

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer
 */
    [_BASE] = LAYOUT_split_3x6_5(
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                            KC_Y ,           KC_U ,   KC_I ,   KC_O ,   KC_P , KC_BSLS,
     KC_ESC  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                            KC_H ,           KC_J ,   KC_K ,   KC_L ,KC_SCLN , KC_QUOT,
 LSFT(KC_GRV), KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , TT(_NUM), KC_BSPC,     KC_DEL  , MO(_SYM),  KC_N ,          KC_M , KC_COMM, KC_DOT ,KC_SLSH , KC_GRV ,
                                 KC_LGUI, KC_LALT, KC_LSFT,  KC_SPC , KC_LCTL,     KC_RCTL ,KC_ENTER ,KC_RSFT,TD(TD_RALT_OSL), KC_RGUI
    ),

/*
 * Numove Layer
 */
    [_NUM] = LAYOUT_split_3x6_5(
     _______ ,XXXXXXX , KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX    ,                                         KC_HOME , KC_PGDN, KC_PGUP, KC_END ,XXXXXXX ,XXXXXXX ,
     _______ ,XXXXXXX , KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX    ,                                         KC_LEFT , KC_DOWN,  KC_UP ,KC_RIGHT, MS_WHLU,XXXXXXX ,
     TG(_PTG), KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_NUM_LOCK, _______, _______,     _______ ,TG(_CTL),MS_LEFT , MS_DOWN,  MS_UP , MS_RGHT, MS_WHLD,XXXXXXX ,
                                 XXXXXXX, XXXXXXX, XXXXXXX    , _______, XXXXXXX,     XXXXXXX ,_______ ,MS_BTN1 , MS_BTN2, MS_BTN3
    ),

/*
 * Symbols Layer
 */
    [_SYM] = LAYOUT_split_3x6_5(
     _______ ,   KC_1   ,   KC_2   ,   KC_3   ,   KC_4     ,   KC_5   ,                                                 KC_6   ,     KC_7    ,   KC_8   ,   KC_9   ,     KC_0    ,    KC_GRV   ,
     _______ ,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4)  ,LSFT(KC_5),                                             LSFT(KC_6) ,  LSFT(KC_7) ,LSFT(KC_8),LSFT(KC_9),  LSFT(KC_0) ,LSFT(KC_MINS),
 LSFT(KC_GRV), KC_SLSH  ,LSFT(KC_8),  KC_MINS ,LSFT(KC_EQL),  KC_EQL  ,XXXXXXX ,_______ ,     _______ , _______  ,LSFT(KC_COMM),LSFT(KC_LBRC),  KC_LBRC ,  KC_RBRC ,LSFT(KC_RBRC), LSFT(KC_DOT),
                                       XXXXXXX,     XXXXXXX,   XXXXXXX,_______ ,XXXXXXX ,     XXXXXXX , _______  ,      XXXXXXX,      XXXXXXX, XXXXXXX
    ),

/*
 * Control Layer
 */
    [_CTL] = LAYOUT_split_3x6_5(
       KC_F1 ,   KC_F2  ,   KC_F3  ,   KC_F4  ,   KC_F5    ,   KC_F6  ,                                                 KC_F7  ,     KC_F8   ,   KC_F9  ,  KC_F10  ,     KC_F11  ,    KC_F12   ,
      EE_CLR , XXXXXXX ,   QK_RBT  ,  DB_TOGG ,   XXXXXXX  ,  XXXXXXX ,                                                XXXXXXX ,     XXXXXXX ,  RM_HUED ,  RM_HUEU ,     RM_SATD ,    RM_SATU  ,
     KC_PAUSE, KC_PSCR ,   KC_SCRL ,   KC_INS , KC_NUM_LOCK,  RM_TOGG ,XXXXXXX ,XXXXXXX ,     XXXXXXX , TG(_CTL) ,     RM_PREV ,     RM_NEXT ,  RM_VALD ,  RM_VALU ,     RM_SPDD ,    RM_SPDU  ,
                                      XXXXXXX ,  XXXXXXX   ,  _______ ,XXXXXXX ,_______ ,     _______ , XXXXXXX  ,   _______   ,   XXXXXXX   ,   _______
    ),

/*
 * Pointing Layer
 */
    [_PTG] = LAYOUT_split_3x6_5(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX, XXXXXXX, MS_BTN2, MS_BTN3, MS_BTN1, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    TG(_PTG), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      MS_BTN1 ,MS_BTN2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                XXXXXXX, XXXXXXX, XXXXXXX, CPI_LOW, XXXXXXX,      MS_BTN3 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),

};

/*
 * New Layer
    [_PTG] = LAYOUT_split_3x6_5(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),

};
*/

// Encoders
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_NUM] =  { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_SYM] =  { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_CTL] =  { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_PTG] =  { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP), ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
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

void ralt_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        // Double tap: one-shot Right Alt
        add_oneshot_mods(MOD_BIT(KC_RALT));
    } else if (state->pressed) {
        // Hold: normal Right Alt
        register_code(KC_RALT);
    } else {
        // Single tap: normal Right Alt
        tap_code(KC_RALT);
    }
}

void ralt_reset(tap_dance_state_t *state, void *user_data) {
    // Release Right Alt if it was held
    unregister_code(KC_RALT);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_RALT_OSL] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL,
        ralt_finished,
        ralt_reset
    ),
};
