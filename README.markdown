# RubyXMacro

## A ruby gem to automate the mouse and keyboard in X Windows.

Rubyxmacro allows you to automate mouse and keyboard movements on Linux with Ruby. It was created in order to test flash websites, but it could be used for many other purposes.

## Install

Your system needs to have the Xtst library installed.
On Ubuntu, this is as easy as:
    sudo apt-get install libxtst-dev

Then, just install with rubygems:

    gem install rubyxmacro

## Usage

Create a display:

    require 'rubyxmacro'
    d = RubyXMacro::Display.new

Move the mouse:

    d.moveMouse(100,100)

Click the mouse:

    d.click
    d.rightClick

Press a key:

    d.keyPress('a')

Send a string of keys:

    d.sendKeys('Thisisastring') \#only upper and lowercase QWERTY and numerals ATM

Other methods:

    d.mouseDown      \#press and hold the mouse button down until mouseUp
    d.mouseUp        \#release the mouse button
    d.rightMouseDown \#press and hold the right mouse button down until rightMouseUp
    d.rightMouseUp   \#release the right mouse button

    d.keycodeDown(keycodeNum) \#press and hold down key with the specified keycode
    d.keycodeUp(keycodeNum)   \#release the key with the specified keycode

## Author

Matthew Downey
[http://www.writehack.com]
