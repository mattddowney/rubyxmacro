/***************************************************************************** 
 *
 * rubyxmacro.c
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

#include "ruby.h"
#include "controlx.h"

/*****************************
 *                           *
 *  Methods Exposed to Ruby  *
 *                           *
 *****************************/

/*
 * Document-method: initialize
 * 
 * Get a RubyXMacro object with the default display.
 * The default display is stored in the $DISPLAY environment variable.
 * 
 *   display = RubyXMacro.new
 */
static VALUE init(VALUE self)
{
	openDefaultDisplay();
	return Qnil;
}

/*******************
 *                 *
 *  Mouse Related  *
 *                 *
 *******************/

/*
 * Document-method: move
 * 
 * Move the mouse pointer to position (x,y).
 * 
 *   display.move(int_x, int_y)
 */
static VALUE method_moveMouse(VALUE self, VALUE x, VALUE y)
{
	moveMouse(NUM2INT(x), NUM2INT(y));
	return Qnil;
}

/*
 * Document-method: click
 * 
 * Left-click the mouse.
 * 
 *   display.click
 */
static VALUE method_click(VALUE self)
{
	click();
	return Qnil;
}

/*
 * Document-method: mouseDown
 * 
 * Hold the left mouse button down until mouseUp.
 * 
 *   display.mouseDown
 */
static VALUE method_mouseDown(VALUE self)
{
	mouseDown();
	return Qnil;
}

/*
 * Document-method: mouseUp
 * 
 * Release the left mouse button. Usually used after mouseDown.
 * 
 *   display.mouseUp
 */
static VALUE method_mouseUp(VALUE self)
{
	mouseUp();
	return Qnil;
}

/*
 * Document-method: rightClick
 * 
 * Right-click the mouse.
 * 
 *   display.rightClick
 */
static VALUE method_rightClick(VALUE self)
{
	rightClick();
	return Qnil;
}

/*
 * Document-method: rightMouseDown
 * 
 * Hold the right mouse button down until rightMouseUp.
 * 
 *   display.rightMouseDown
 */
static VALUE method_rightMouseDown(VALUE self)
{
	rightMouseDown();
	return Qnil;
}

/*
 * Document-method: rightMouseUp
 * 
 * Release the right mouse button. Usually used after rightMouseDown.
 * 
 *   display.rightMouseUp
 */
static VALUE method_rightMouseUp(VALUE self)
{
	rightMouseUp();
	return Qnil;
}

/**********************
 *                    *
 *  Keyboard Related  *
 *                    *
 **********************/

/*
 * Document-method: keycodeDown
 * 
 * Hold down the key with the value keycode until keycodeUp.
 * 
 *   display.keycodeDown(int_keycode)
 */
static VALUE method_keycodeDown(VALUE self, VALUE keycode)
{
	keycodeDown(NUM2INT(keycode));
	return Qnil;
}

/*
 * Document-method: keycodeUp
 * 
 * Release the key with the value keycode. Usually used after keycodeDown.
 * 
 *   display.keycodeUp(int_keycode)
 */
static VALUE method_keycodeUp(VALUE self, VALUE keycode)
{
	keycodeUp(NUM2INT(keycode));
	return Qnil;
}

/*
 * Document-method: keycodePress
 * 
 * Press and release the key with the value keycode.
 * 
 *   display.keycodePress(int_keycode)
 */
static VALUE method_keycodePress(VALUE self, VALUE keycode)
{
	keycodePress(NUM2INT(keycode));
	return Qnil;
}

/*
 * Document-method: keycodeShiftPress
 *
 * Hold down shift, then press and release the key with the value keycode.
 *
 *   display.keycodeShiftPress(int_keycode)
 */
static VALUE method_keycodeShiftPress(VALUE self, VALUE keycode)
{
	keycodeShiftPress(NUM2INT(keycode));
	return Qnil;
}

/*
 * Document-method: keyDown
 * 
 * Hold down the key until keyUp.
 * 
 *   display.keyDown(str_key)
 */
static VALUE method_keyDown(VALUE self, VALUE keycode)
{
	keyDown(StringValuePtr(keycode));
	return Qnil;
}

/*
 * Document-method: keyUp
 * 
 * Release the key. Usually used after keyDown.
 * 
 *   display.keyUp(str_key)
 */
static VALUE method_keyUp(VALUE self, VALUE keycode)
{
	keyUp(StringValuePtr(keycode));
	return Qnil;
}

/*
 * Document-method: keyPress
 * 
 * Press and release the key.
 * 
 *   display.keyPress(str_key)
 */
static VALUE method_keyPress(VALUE self, VALUE key)
{
	keyPress(StringValuePtr(key));
	return Qnil;
}

/******************
 *                *
 *  Ruby Related  *
 *                *
 ******************/

VALUE rubyXMacro;
VALUE displayClass;

/* Automate the mouse and keyboard in X. */
void Init_rubyxmacro()
{
	rubyXMacro = rb_define_module("RubyXMacro");
	displayClass = rb_define_class_under(rubyXMacro, "Display", rb_cObject);
	rb_define_method(displayClass, "initialize", init, 0);
	rb_define_method(displayClass, "moveMouse", method_moveMouse, 2);
	rb_define_method(displayClass, "click", method_click, 0);
	rb_define_method(displayClass, "mouseDown", method_mouseDown, 0);
	rb_define_method(displayClass, "mouseUp", method_mouseUp, 0);
	rb_define_method(displayClass, "rightClick", method_rightClick, 0);
	rb_define_method(displayClass, "rightMouseDown", method_rightMouseDown, 0);
	rb_define_method(displayClass, "rightMouseUp", method_rightMouseUp, 0);
	rb_define_method(displayClass, "keycodeDown", method_keycodeDown, 1);
	rb_define_method(displayClass, "keycodeUp", method_keycodeUp, 1);
	rb_define_method(displayClass, "keycodePress", method_keycodePress, 1);
	rb_define_method(displayClass, "keycodeShiftPress", method_keycodeShiftPress, 1);
	rb_define_method(displayClass, "keyDown", method_keyDown, 1);
	rb_define_method(displayClass, "keyUp", method_keyUp, 1);
	rb_define_method(displayClass, "keyPress", method_keyPress, 1);;
}
