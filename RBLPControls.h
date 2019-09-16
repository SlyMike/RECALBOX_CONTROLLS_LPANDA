#include <arduino.h>
#include <Keyboard.h>

#define BUTTON_COUNT         17

#define BTN_P1_START		2	//			KEY_1
#define BTN_P1_SELECT		3	//			KEY_3
#define BTN_P1_UP			  4	//			KEY_UP
#define BTN_P1_DOWN			5	//			KEY_DOWN
#define BTN_P1_LEFT			6	//			KEY_LEFT
#define BTN_P1_RIGHT		7	//			KEY_RIGHT
#define BTN_P1_A			  8	//			KEY_Z
#define BTN_P1_B			  9	//			LEFT_SHIFT
#define BTN_P1_X			  10	//		LEFT_ALT
#define BTN_P1_Y			  11	//		LEFT_CTRL
#define BTN_P1_L1			  12	//		KEY_SPACE
#define BTN_P1_R1			  A0  //		KEY_X
#define BTN_FE_HOTKEY		A1  //		KEY_C
#define BTN_FE_ACCEPT		A2  //		KEY_A
#define BTN_FE_BACK			A3  //		KEY_S
#define BTN_FE_MENU			A4  //		KEY_RETURN
#define BTN_FE_QUITEM		A5  //		KEY_ESC


typedef struct
{
  uint8_t state; // what state was the input last in ( HIGH/LOW )
  unsigned long last_change;
} button_state;


/*
#define KEY_LEFT_CTRL			  0x80
#define KEY_LEFT_SHIFT			0x81
#define KEY_LEFT_ALT			  0x82
#define KEY_LEFT_GUI			  0x83
#define KEY_RIGHT_CTRL			0x84
#define KEY_RIGHT_SHIFT			0x85
#define KEY_RIGHT_ALT			  0x86
#define KEY_RIGHT_GUI			  0x87

#define KEY_UP_ARROW			  0xDA
#define KEY_DOWN_ARROW			0xD9
#define KEY_LEFT_ARROW			0xD8
#define KEY_RIGHT_ARROW			0xD7
#define KEY_BACKSPACE			  0xB2
#define KEY_TAB					    0xB3
#define KEY_RETURN				  0xB0
#define KEY_ESC					    0xB1
#define KEY_INSERT				  0xD1
#define KEY_DELETE				  0xD4
#define KEY_PAGE_UP				  0xD3
#define KEY_PAGE_DOWN			  0xD6
#define KEY_HOME				    0xD2
#define KEY_END					    0xD5	
#define KEY_CAPS_LOCK			  0xC1

#define KEY_F1					    0xC2
#define KEY_F2					    0xC3
#define KEY_F3					    0xC4
#define KEY_F4					    0xC5
#define KEY_F5					    0xC6
#define KEY_F6					    0xC7
#define KEY_F7					    0xC8
#define KEY_F8					    0xC9
#define KEY_F9					    0xCA
#define KEY_F10					    0xCB
#define KEY_F11					    0xCC
#define KEY_F12					    0xCD

#define KEY_F13					    0xF0	240
#define KEY_F14					    0xF1	241
#define KEY_F15					    0xF2	242
#define KEY_F16					    0xF3	243
#define KEY_F17					    0xF4	244
#define KEY_F18					    0xF5	245
#define KEY_F19					    0xF6	246
#define KEY_F20					    0xF7	247
#define KEY_F21					    0xF8	248
#define KEY_F22					    0xF9	249
#define KEY_F23					    0xFA	250
#define KEY_F24					    0xFB	251

Space is decimal 32, or 0x20 in Hexadecimal.
Keyboard.write(' '); should work - as should Keyboard.write((char) 32); or Keyboard.write((char) 0x20);.
*/
