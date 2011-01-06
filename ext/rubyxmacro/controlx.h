/***************************************************************************** 
 *
 * controlx.h
 * Copyright (C) 2010 Matthew Downey <mattddowney@gmail*NOSPAM*.com>
 *	
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 ****************************************************************************/

#include "opendisplay.h"

/* Globals */
Display * display;
const int DELAY = 10;
const int LEFT_MOUSE_BUTTON = 1;
const int RIGHT_MOUSE_BUTTON = 3;
const int SHIFT_KEYCODE = 50;

/* Open the default display.
 * The default display is contained in the $DISPLAY environment variable. */
void openDefaultDisplay() {
	display = openDisplay(getenv("DISPLAY"));
	return;
}

/*****************
 *               *
 * Mouse Related *
 *               *
 *****************/

/* push a button down on the mouse */
void buttonDown(int buttonNum) {
	XTestFakeButtonEvent(display, buttonNum, 1, DELAY);
	XFlush(display);	/* flush the buffer to actually make the change */
	return;
}

/* release a button on the mouse */
void buttonUp(int buttonNum) {
	XTestFakeButtonEvent(display, buttonNum, 0, DELAY);
	XFlush(display);	/* flush the buffer to actually make the change */
	return;
}

/* click a button on the mouse */
void buttonClick(int buttonNum) {
	buttonDown(buttonNum);
	buttonUp(buttonNum);
	return;
}

/* Move the mouse pointer to position (x,y). */
void moveMouse(int x, int y)
{
	XTestFakeMotionEvent(display, -1, x, y, DELAY);
	XFlush(display);	/* flush the buffer to actually make the change */
	return;
}

/* Left-click the mouse. */
void click()
{
	buttonClick(LEFT_MOUSE_BUTTON);
	return;
}

/* Hold the left mouse button down until mouseUp. */
void mouseDown()
{
	buttonDown(LEFT_MOUSE_BUTTON);
	return;
}

/* Release the left mouse button. Usually used after mouseDown. */
void mouseUp()
{
	buttonUp(LEFT_MOUSE_BUTTON);
	return;
}

/* Right-click the mouse. */
void rightClick()
{
	buttonClick(RIGHT_MOUSE_BUTTON);
	return;
}

/* Hold the right mouse button down until rightMouseUp. */
void rightMouseDown()
{
	buttonDown(RIGHT_MOUSE_BUTTON);
	return;
}

/* Release the right mouse button. Usually used after rightMouseDown. */
void rightMouseUp()
{
	buttonUp(RIGHT_MOUSE_BUTTON);
	return;
}

/********************
 *                  *
 * Keyboard Related *
 *                  *
 ********************/

/* Hold down the key with the value keycode until keycodeUp. */
void keycodeDown(int keycode)
{
	XTestFakeKeyEvent(display, keycode, 1, DELAY);
	XFlush(display);	/* flush the buffer to actually make the change */
	return;
} 

/* Release the key with the value keycode. Usually used after keycodeDown. */
void keycodeUp(int keycode)
{
	XTestFakeKeyEvent(display, keycode, 0, DELAY);
	XFlush(display);	/* flush the buffer to actually make the change */
	return;
}

/* Press and release the key with the value keycode. */
void keycodePress(int keycode)
{
	keycodeDown(keycode);
	keycodeUp(keycode);
	return;
}

/* Hold down shift, then press and release the key with the value keycode. */
void keycodeShiftPress(int keycode)
{
        keycodeDown(SHIFT_KEYCODE);
	keycodePress(keycode);
        keycodeUp(SHIFT_KEYCODE);
	return;
}

/* Convert a string to it's keycode. */
int stringToKeycode(char * key)
{
	KeySym keyS;
	KeyCode keyC;
	
	keyS = XStringToKeysym(key);
	
	if((keyC = XKeysymToKeycode(display, keyS)) == 0)
	{
		fprintf(stderr, "Could not get keycode for %s", key);
		return;
	}
	else
		return ((int)keyC);
}

/* Hold down the key until keyUp. */
void keyDown(char * key)
{
	keycodeDown(stringToKeycode(key));
	return;
}

/* Release the key. Usually used after keyDown. */
void keyUp(char * key)
{
	keycodeUp(stringToKeycode(key));
	return;
}

/* Press and release the key. */
/* needs work to handle special characters */
void keyPress(char * key)
{
	KeySym keyS, lowercase, uppercase;
	
	keyS = XStringToKeysym(key);
	XConvertCase(keyS, &lowercase, &uppercase);
	
	if (keyS == lowercase)
		keycodePress(stringToKeycode(key));
	else	/* uppercase */
		keycodeShiftPress(stringToKeycode(key));

	return;
}
