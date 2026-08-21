RGB_MATRIX_EFFECT(LAYER_INDICATOR)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool LAYER_INDICATOR(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    const rgb_t layer_colors[] = {
        {RGB_ORANGE}, // Layer 0
        {RGB_GREEN},  // Layer 1
        {RGB_BLUE}, // Layer 2
        {RGB_RED},  // Layer 3
        {RGB_WHITE} // Layer 4
    };

    rgb_t rgb;

    if (layer < sizeof(layer_colors) / sizeof(layer_colors[0])) {
        rgb = layer_colors[layer];
    } else {
        rgb = (rgb_t){RGB_WHITE};
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
