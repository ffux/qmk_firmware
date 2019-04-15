#pragma once

#include "dactyl_manuform.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);

#ifndef FLIP_HALF
#define LAYOUT( \
	L00, L01, L02, L03, L04,                     R01, R02, R03, R04, R05, \
	L10, L11, L12, L13, L14,                     R11, R12, R13, R14, R15, \
	L20, L21, L22, L23, L24,                     R21, R22, R23, R24, R25, \
	     L31, L32,                                         R33, R34,      \
                       L33, L43,                     R42, R32,                \
                                 L44, L45, R40, R41,                          \
                                 L34, L35, R30, R31                           \
	) \
	{ \
		{ L00, L01, L02, L03, L04, KC_NO }, \
		{ L10, L11, L12, L13, L14, KC_NO }, \
		{ L20, L21, L22, L23, L24, KC_NO }, \
		{ KC_NO, L31, L32, L33, L34, L35 }, \
		{ KC_NO, KC_NO, KC_NO, L43, L44, L45 }, \
\
		{ R05, R04, R03, R02, R01, KC_NO },    \
		{ R15, R14, R13, R12, R11, KC_NO },    \
		{ R25, R24, R23, R22, R21, KC_NO },    \
		{ KC_NO, R34, R33, R32, R31, R30},  \
		{ KC_NO, KC_NO, KC_NO, R42, R41, R40 }  \
	}
#else



#define LAYOUT( \
	L00, L01, L02, L03, L04,                     R01, R02, R03, R04, R05, \
	L10, L11, L12, L13, L14,                     R11, R12, R13, R14, R15, \
	L20, L21, L22, L23, L24,                     R21, R22, R23, R24, R25, \
	     L31, L32,                                         R33, R34,      \
                       L33, L43,                     R42, R32,                \
                                 L44, L45, R40, R41,                          \
                                 L34, L35, R30, R31                           \
	) \
	{ \
		{ R05, R04, R03, R02, R01, KC_NO },    \
		{ R15, R14, R13, R12, R11, KC_NO },    \
		{ R25, R24, R23, R22, R21, KC_NO },    \
		{ KC_NO, R34, R33, R32, R31, R30},  \
		{ KC_NO, KC_NO, KC_NO, R42, R41, R40 }  \
\
		{ L00, L01, L02, L03, L04, KC_NO }, \
		{ L10, L11, L12, L13, L14, KC_NO }, \
		{ L20, L21, L22, L23, L24, KC_NO }, \
		{ KC_NO, L31, L32, L33, L34, L35 }, \
		{ KC_NO, KC_NO, KC_NO, L43, L44, L45 }, \
\
	}
#endif
