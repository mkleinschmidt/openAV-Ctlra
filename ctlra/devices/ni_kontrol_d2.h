/*
 * Copyright (c) 2016, OpenAV Productions,
 * Harry van Haaren <harryhaaren@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef OPENAV_CTLRA_NI_KONTROL_D2_H
#define OPENAV_CTLRA_NI_KONTROL_D2_H

enum NI_KONTROL_D2_LEDS {
	NI_KONTROL_D2_LED_PAD_1,
	NI_KONTROL_D2_LED_PAD_2,
	NI_KONTROL_D2_LED_PAD_3,
	NI_KONTROL_D2_LED_PAD_4,
	NI_KONTROL_D2_LED_PAD_5,
	NI_KONTROL_D2_LED_PAD_6,
	NI_KONTROL_D2_LED_PAD_7,
	NI_KONTROL_D2_LED_PAD_8,
	NI_KONTROL_D2_LED_FX_SELECT,
	NI_KONTROL_D2_LED_FX_1,
	NI_KONTROL_D2_LED_FX_2,
	NI_KONTROL_D2_LED_FX_3,
	NI_KONTROL_D2_LED_FX_4,
	NI_KONTROL_D2_LED_SCREEN_LEFT_1,
	NI_KONTROL_D2_LED_SCREEN_LEFT_2,
	NI_KONTROL_D2_LED_SCREEN_LEFT_3,
	NI_KONTROL_D2_LED_SCREEN_LEFT_4,
	NI_KONTROL_D2_LED_SCREEN_RIGHT_1,
	NI_KONTROL_D2_LED_SCREEN_RIGHT_2,
	NI_KONTROL_D2_LED_SCREEN_RIGHT_3,
	NI_KONTROL_D2_LED_SCREEN_RIGHT_4,
	NI_KONTROL_D2_LED_BACK,
	NI_KONTROL_D2_LED_CAPTURE,
	NI_KONTROL_D2_LED_EDIT,
	NI_KONTROL_D2_LED_ON_1,
	NI_KONTROL_D2_LED_ON_2,
	NI_KONTROL_D2_LED_ON_3,
	NI_KONTROL_D2_LED_ON_4,
	NI_KONTROL_D2_LED_HOTCUE,
	NI_KONTROL_D2_LED_LOOP,
	NI_KONTROL_D2_LED_FREEZE,
	NI_KONTROL_D2_LED_REMIX,
	NI_KONTROL_D2_LED_FLUX,
	NI_KONTROL_D2_LED_DECK,
	NI_KONTROL_D2_LED_SHIFT,
	NI_KONTROL_D2_LED_SYNC,
	NI_KONTROL_D2_LED_CUE,
	NI_KONTROL_D2_LED_PLAY,
	NI_KONTROL_D2_LED_DECK_A,
	NI_KONTROL_D2_LED_DECK_B,
	NI_KONTROL_D2_LED_DECK_C,
	NI_KONTROL_D2_LED_DECK_D,
	NI_KONTROL_D2_LED_LOOP_CIRCLE_1,
	NI_KONTROL_D2_LED_LOOP_CIRCLE_2,
	NI_KONTROL_D2_LED_LOOP_CIRCLE_3,
	NI_KONTROL_D2_LED_LOOP_CIRCLE_4,
	/* Touchstrip LEDs: 25 bi-color leds, blue or orange. See helper
	 * function below: ni_kontrol_d2_light_touchstrip() */
	NI_KONTROL_D2_LED_TOUCHSTRIP,
	NI_KONTROL_D2_LED_COUNT,
};

enum NI_KONTROL_D2_BUTTONS {
	NI_KONTROL_D2_BTN_DECK_A,
	NI_KONTROL_D2_BTN_DECK_B,
	NI_KONTROL_D2_BTN_DECK_C,
	NI_KONTROL_D2_BTN_DECK_D,
	NI_KONTROL_D2_BTN_FX_1,
	NI_KONTROL_D2_BTN_FX_2,
	NI_KONTROL_D2_BTN_FX_3,
	NI_KONTROL_D2_BTN_FX_4,
	NI_KONTROL_D2_BTN_FX_DIAL_TOUCH_1,
	NI_KONTROL_D2_BTN_FX_DIAL_TOUCH_2,
	NI_KONTROL_D2_BTN_FX_DIAL_TOUCH_3,
	NI_KONTROL_D2_BTN_FX_DIAL_TOUCH_4,
	NI_KONTROL_D2_BTN_FX_SELECT,
	/* Screen */
	NI_KONTROL_D2_BTN_SCREEN_LEFT_1,
	NI_KONTROL_D2_BTN_SCREEN_LEFT_2,
	NI_KONTROL_D2_BTN_SCREEN_LEFT_3,
	NI_KONTROL_D2_BTN_SCREEN_LEFT_4,
	NI_KONTROL_D2_BTN_SCREEN_RIGHT_1,
	NI_KONTROL_D2_BTN_SCREEN_RIGHT_2,
	NI_KONTROL_D2_BTN_SCREEN_RIGHT_3,
	NI_KONTROL_D2_BTN_SCREEN_RIGHT_4,
	NI_KONTROL_D2_BTN_SCREEN_ENCODER_TOUCH_1,
	NI_KONTROL_D2_BTN_SCREEN_ENCODER_TOUCH_2,
	NI_KONTROL_D2_BTN_SCREEN_ENCODER_TOUCH_3,
	NI_KONTROL_D2_BTN_SCREEN_ENCODER_TOUCH_4,
	NI_KONTROL_D2_BTN_ENCODER_BROWSE_PRESS,
	NI_KONTROL_D2_BTN_ENCODER_BROWSE_TOUCH,
	NI_KONTROL_D2_BTN_BACK,
	NI_KONTROL_D2_BTN_CAPTURE,
	NI_KONTROL_D2_BTN_EDIT,
	NI_KONTROL_D2_BTN_ENCODER_LOOP_PRESS,
	NI_KONTROL_D2_BTN_ENCODER_LOOP_TOUCH,
	/* Performance */
	NI_KONTROL_D2_BTN_ON_1,
	NI_KONTROL_D2_BTN_ON_2,
	NI_KONTROL_D2_BTN_ON_3,
	NI_KONTROL_D2_BTN_ON_4,
	NI_KONTROL_D2_BTN_FADER_TOUCH_1,
	NI_KONTROL_D2_BTN_FADER_TOUCH_2,
	NI_KONTROL_D2_BTN_FADER_TOUCH_3,
	NI_KONTROL_D2_BTN_FADER_TOUCH_4,
	NI_KONTROL_D2_BTN_PAD_1,
	NI_KONTROL_D2_BTN_PAD_2,
	NI_KONTROL_D2_BTN_PAD_3,
	NI_KONTROL_D2_BTN_PAD_4,
	NI_KONTROL_D2_BTN_PAD_5,
	NI_KONTROL_D2_BTN_PAD_6,
	NI_KONTROL_D2_BTN_PAD_7,
	NI_KONTROL_D2_BTN_PAD_8,
	/* Global */
	NI_KONTROL_D2_BTN_HOTCUE,
	NI_KONTROL_D2_BTN_LOOP,
	NI_KONTROL_D2_BTN_FREEZE,
	NI_KONTROL_D2_BTN_REMIX,
	NI_KONTROL_D2_BTN_FLUX,
	NI_KONTROL_D2_BTN_DECK,
	/* Playback */
	NI_KONTROL_D2_BTN_SHIFT,
	NI_KONTROL_D2_BTN_SYNC,
	NI_KONTROL_D2_BTN_CUE,
	NI_KONTROL_D2_BTN_PLAY,
	/* Meta-button, touchstrip touch detection */
	NI_KONTROL_D2_BTN_TOUCHSTRIP_TOUCH,
};

enum NI_KONTROL_D2_SLIDERS {
	/* Sliders */
	NI_KONTROL_D2_SLIDER_FADER_1,
	NI_KONTROL_D2_SLIDER_FADER_2,
	NI_KONTROL_D2_SLIDER_FADER_3,
	NI_KONTROL_D2_SLIDER_FADER_4,
	NI_KONTROL_D2_SLIDER_FX_DIAL_1,
	NI_KONTROL_D2_SLIDER_FX_DIAL_2,
	NI_KONTROL_D2_SLIDER_FX_DIAL_3,
	NI_KONTROL_D2_SLIDER_FX_DIAL_4,
	NI_KONTROL_D2_SLIDER_TOUCHSTRIP,
};

enum NI_KONTROL_D2_ENCODERS {
	/* Rotary Endless Encoders (float message type) */
	NI_KONTROL_D2_ENCODER_SCREEN_1,
	NI_KONTROL_D2_ENCODER_SCREEN_2,
	NI_KONTROL_D2_ENCODER_SCREEN_3,
	NI_KONTROL_D2_ENCODER_SCREEN_4,
	/* Notched Encoders (int message type) */
	NI_KONTROL_D2_ENCODER_BROWSE,
	NI_KONTROL_D2_ENCODER_LOOP,
};

/* forward declaration only */
struct ctlra_dev_t;

/* Helper: set the touchstrip LEDs in a convienient way.
 * Dev is the device, orange and blue, are pointers to an array
 * of uint8_ts, both 25 elements long. The value of each element is
 * the brightness of the LEDs. Element 0 is the leftmost LED for both
 * arrays */
void ni_kontrol_d2_light_touchstrip(struct ctlra_dev_t *dev,
				    uint8_t *orange,
				    uint8_t *blue);

/* This function returns the location of *EXACTLY* (480 * 272 * 2) bytes,
 * which the application must fill in. Writing one byte out of bounds in
 * EITHER direction will cause the screen-write to fail: here be dragons!
 *
 * The data format is as follows:
 * - BGR 565 encoding:
 *   - 2 bytes per pixel
 *   - 5 bits blue
 *   - 6 bits green
 *   - 5 bits red 
 *
 * The application is expected to write this format directly the the
 * pointer returned by this function.
 */
uint8_t *ni_kontrol_d2_screen_get_pixels(struct ctlra_dev_t *base);

/* Blit data to the screen. */
void ni_kontrol_d2_screen_blit(struct ctlra_dev_t *base);

#endif /* OPENAV_CTLRA_NI_KONTROL_D2_H */

