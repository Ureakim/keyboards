# Halcyon Kyria — Keymap

This directory contains the QMK configuration for the **Kyria** keyboard.

The layout is designed around a simple idea: **keep the frequently used keys on the base layer and move numbers, symbols, controls, and mouse functions into dedicated layers**. This keeps the physical keyboard compact while making common programming and desktop operations accessible without reaching for a conventional number row or navigation cluster.

The layout is split into five layers:

* **BASE** — normal typing and primary modifiers
* **NUM** — numbers, navigation, and mouse movement
* **SYM** — symbols and shifted symbols
* **CTL** — function keys, system controls, and RGB controls
* **PTG** — pointing-device controls

## Layers

### Thumb cluster

The thumb keys are deliberately assigned to functions that are useful while typing:

* **Num** — momentary access to the number/navigation layer; tapping it also provides the Num layer's toggle behavior.
* **Sym** — momentary access to symbols.
* **Space / Enter** — primary typing keys.
* **Backspace / Delete** — editing.
* **Shift / Ctrl / Alt / GUI** — modifiers positioned close to the thumbs.

The left outer thumb key also provides access to the control layer through the `Ctrl` key position.

### 1. BASE — typing

The base layer contains the standard QWERTY alphabet.

```text
┌─────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Tab │  Q  │  W  │  E  │  R  │  T  │                           │  Y  │  U  │  I  │  O  │  P  │  \  │
├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
│ Esc │  A  │  S  │  D  │  F  │  G  │                           │  H  │  J  │  K  │  L  │  ;  │  '  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐   ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ ~   │  Z  │  X  │  C  │  V  │  B  │Space│LGUI │   │ Ctrl│Enter│  N  │  M  │  ,  │  .  │  /  │  `  │
└─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
                  │ Num │LAlt │Shift│Bksp │LCtrl│   │RCtrl│ Del │Shift│ RAlt│ Sym │
                  └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
```

### 2. NUM — numbers, navigation, and mouse

The Num layer combines three related functions:

1. A compact number block.
2. Keyboard navigation.
3. Mouse movement and scrolling.

```text
┌─────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Tab │     │  7  │  8  │  9  │     │                           │ Home│PDown│ PUP │ END │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
│ Esc │     │  4  │  5  │  6  │     │                           │  ←  │  ↓  │  ↑  │  →  │Scl ↑│     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐   ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ PTG │  0  │  1  │  2  │  3  │     │Space│LGUI │   │ Ctrl│Enter│  M← │  M↓ │  M↑ │  M→ │Scl ↓│     │
└─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
                  │ Num │LAlt │Shift│Bksp │LCtrl│   │RCtrl│ Del │Clic1│Clic2│Clic3│
                  └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
```

### 3. SYM — symbols

The Sym layer provides symbols in a layout optimized around their relationships to the number row and common programming punctuation.

```text
┌─────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Tab │  1  │  2  │  3  │  4  │  5  │                           │  6  │  7  │  8  │  9  │  0  │  `  │
├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
│ Esc │  !  │  @  │  #  │  $  │  %  │                           │  ^  │  &  │  *  │  (  │  )  │  _  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐   ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│  ~  │  /  │  *  │  -  │  +  │  =  │Space│LGUI │   │ Ctrl│Enter│  <  │  {  │  [  │  ]  │  }  │  >  │
└─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
                  │ Num │LAlt │Shift│Bksp │LCtrl│   │RCtrl│ Del │Shift│ RAlt│ Sym │
                  └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
```

### 4. CTL — function and system controls

The Control layer contains function keys and less frequently used system commands.

```text
┌─────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │                           │  F7 │  F8 │  F9 │ F10 │ F11 │ F12 │
├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
│CLREE│     │Reset│DBGTG│     │     │                           │     │     │HSVH↓│HSVH↑│HSVS↓│HSVS↑│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐   ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│Pause│PrScr│ScLck│Insrt│NmLck│LEDTG│     │     │   │ Ctrl│     │LED ←│LED →│LEDB↓│LEDB↑│LEDS↓│LEDS↑│
└─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
                  │ Num │LAlt │Shift│Bksp │LCtrl│   │     │     │     │     │     │
                  └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
```

This layer intentionally keeps rarely used functions out of the base layer while retaining direct access to them.

It also provides controls for the keyboard's RGB matrix:

* Hue
* Saturation
* Brightness
* Animation speed
* RGB toggle

### 5. PTG — pointing device

The Pointing layer is dedicated to mouse buttons and pointer configuration.

```text
┌─────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │                           │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │Clic2│Clic3│Clic1│     │                           │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐   ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ PTG │     │     │     │     │     │     │     │   │Clic1│Clic2│     │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │     │CPI L│     │   │Clic3│     │     │     │     │
                  └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
```

The layer is also configured as the QMK **auto-mouse layer**, so pointing-device activity can activate it automatically. The default pointing-device CPI is 400, while the dedicated CPI key temporarily lowers it to 200 for more precise cursor movement.

## Rotary encoders

The two rotary encoders are configured consistently on the Base, Num, Sym, and Pointing layers:

| Encoder | Counter-clockwise | Clockwise      |
| ------- | ----------------- | -------------- |
| First   | Volume down       | Volume up      |
| Second  | Mouse wheel down  | Mouse wheel up |

On the Control layer the encoders instead control RGB:

| Encoder | Counter-clockwise        | Clockwise              |
| ------- | ------------------------ | ---------------------- |
| First   | RGB animation speed down | RGB animation speed up |
| Second  | RGB brightness down      | RGB brightness up      |

## Layer philosophy

```text
                    ┌───────────────┐
                    │     BASE      │
                    │    Typing     │
                    └───────┬───────┘
                            │
             ┌──────────────┼──────────────┐
             │              │              │
             ▼              ▼              ▼
        ┌─────────┐    ┌─────────┐   ┌─────────┐
        │   NUM   │    │   SYM   │   │   CTL   │
        │ Numbers │    │ Symbols │   │ Control │
        │ Nav     │    │         │   │   F-keys│
        │ Mouse   │    │         │   │   RGB   │
        └────┬────┘    └─────────┘   └─────────┘
             │
             ▼
        ┌─────────┐
        │   PTG   │
        │  Mouse  │
        │ Buttons │
        └─────────┘
```

