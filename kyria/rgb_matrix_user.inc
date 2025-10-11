RGB_MATRIX_EFFECT(LAYER_INDICATOR)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool LAYER_INDICATOR(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);

    hsv_t hsv = rgb_matrix_config.hsv;
    switch(layer) {
        case 1:
            hsv.h = 132;
            break;
        case 2:
            hsv.h = 36;
            break;
        case 3:
            hsv.h = 0;
            break;
        default:
            hsv.h = 106;
            break;
    }
    rgb_t rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
