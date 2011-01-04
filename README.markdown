# RubyXMacro

## A ruby gem to automate the mouse and keyboard in X Windows.

## Install

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

## Author

    Matthew Downey (http://www.writehack.com)
