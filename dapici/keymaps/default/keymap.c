#include "kb.h"

enum custom_keycodes {
    MAC11 = SAFE_RANGE,
    MAC12,
    MAC13,
    MAC14,
    MAC15,
    MAC16,
    MAC17,
    MAC18,
    MAC19,
    MAC01,
    MAC02,
    MAC03,
    MAC04,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_picipad(
			     MO(1),
		MAC01  , KC_DELETE, MAC02,
		MAC03  , KC_UP    , MAC04,
		KC_LEFT, KC_DOWN  , KC_RIGHT
		)
	,
	[1] = LAYOUT_picipad(
			   KC_TRNS,
		MAC11, MAC12  , MAC13,
        MAC14, MAC15  , MAC16,
        MAC17, MAC18  , MAC19
		)
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
	switch (keycode) {

    case MAC01:
        if (record->event.pressed) {
            tap_code16(C(KC_LSHIFT));
        } else {
            // when keycode is released
        }
        break;

    case MAC02:
        if (record->event.pressed) {
            tap_code16(A(KC_TAB));
        } else {
            // when keycode is released
        }
        break;

    case MAC03:
        if (record->event.pressed) {
        } else {
            tap_code16(C(S(KC_TAB)));
        }
        break;

    case MAC04:
        if (record->event.pressed) {
            tap_code16(C(KC_TAB));
        } else {
            // when keycode is released
        }
        break;

    case MAC11:
        if (record->event.pressed) {
            tap_code(KC_ENTER);
            SEND_STRING("gaf");
            tap_code(KC_ENTER);
        } else {
            // released
        }
        break;

    case MAC12:
        if (record->event.pressed) {
            tap_code(KC_ENTER);
            SEND_STRING("NGU");
            tap_code(KC_ENTER);
        } 
        break;

    case MAC13:
        if (record->event.pressed) {
            SEND_STRING("sucs vaatj");
            tap_code(KC_ENTER);
        } 
        break;

    case MAC14:
        if (record->event.pressed) {
            SEND_STRING("im mej moomf vaof");
            tap_code(KC_ENTER);
        } 
        break;

    case MAC15:
        if (record->event.pressed) {
            SEND_STRING("PICI15 ");
        } 
        break;

    case MAC16:
        if (record->event.pressed) {
            SEND_STRING("PICI16 ");
        } 
        break;

    case MAC17:
        if (record->event.pressed) {
            SEND_STRING("PICI17 ");
        } 
        break;

    case MAC18:
        if (record->event.pressed) {
            SEND_STRING("PICI18 ");
        } 
        break;

    case MAC19:
        if (record->event.pressed) {
            SEND_STRING("PICI19 ");
        } 
        break;
    }
    return true;
}

// encoders
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    }
    return false;
}

// encoders push button
bool dip_switch_update_user(uint8_t index, bool active) 
{ 
 	switch (index) {
        case 0:		//ENC0_SW
        	if (active) //ENC0 pressed
				{ 
					SEND_STRING("yuh-cun ngu vcl! ");
					//tap_code(KC_RIGHT);
				} 
			else //ENC0 released
                {
					//do nothing
				}
            break;
        case 1: 	//ENC0_SW
        	if (active) //ENC0 pressed
				{ 
					//SEND_STRING("pici provjp123 <3 ");
				} 
			else //ENC0 released
                {
					//do nothing
				}
            break;
	}
	return true;
}	