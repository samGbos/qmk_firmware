# samGbos ErgoDox EZ keymap

A personal QWERTY keymap for the original ErgoDox EZ (`ergodox_ez/base`), based on the stock default keymap and used mainly with a Mac.

## Goals

- Keep a familiar QWERTY layout with Mac-style modifiers.
- Make the bottom-left key behave like a Mac keyboard's fn/Globe key.
- Keep layer switching simple: the layers I use often are one held key away, and the rare ones are tucked behind Fn.

## Layers

| Layer       | How to reach it                      | What it does
| BASE        | default                              | QWERTY. Ctrl on the left home-row edge, `=` and `-` on the inner keys, arrows bottom right. Inner thumb keys hold F1-F8.
| NUM         | hold the left inner key (`=` on tap) | Right-hand numpad (7-8-9 / 4-5-6 / 1-2-3, `+ - * /`, 0).
| SYMB        | hold the right thumb key             | Shifted number row, brackets and braces, some digits.
| FUNC ("Fn") | hold the bottom-left key             | F1-F12 grid on the right hand, volume, brightness, play/pause, calculator. Arrows become Home / PgDn / PgUp / End, Backspace becomes forward Delete.
| STARCRAFT   | toggle from FUNC + 3rd key from left | Swaps Space and Cmd, and puts Caps Lock on the Ctrl key. Toggle again to leave.

## The Fn / Globe key

The bottom-left key is a layer-tap:

- **Tap:** sends Apple's Globe key (HID consumer usage `0x029D`) for the emoji picker, dictation or input-source switch.
- **Hold:** activates the FUNC layer, which mimics fn+arrows and fn+Backspace on a Mac.

Holding Globe as a modifier (for example the Sequoia window-tiling shortcuts) is not supported.

## Settings (`config.h`)

- `PERMISSIVE_HOLD` is on.
- `TAPPING_TERM` is 175 ms.

## LEDs

The three right-hand LEDs show the active layer: STARCRAFT is LED 1, SYMB is LEDs 1+2, NUM is LEDs 1+3, and FUNC is LEDs 2+3.

## Changes from the stock default

- Replaced the layout with the layers above.
- Removed the Linux and Windows layers and the leader key with its text snippets.
- Updated removed keycode aliases for current QMK (`KC_BSPC`, `KC_LCTL`, `MS_UP`).
- Added the Globe tap behavior and the Mac-style Fn layer.

## Build and flash

```bash
qmk compile -kb ergodox_ez/base -km samGbos
```
(Install qmk using instructions from https://qmk.fm/)

Flash the resulting `ergodox_ez_base_samGbos.hex` with BalenaEtcher

