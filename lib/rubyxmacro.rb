require 'rubyxmacro/rubyxmacro'
require 'keycodes'

module RubyXMacro
  class Display
    # Press and release a string of keys.
    def sendKeys(keyString)
      while keyString.length > 0 do
        keyStringArray = keyString.partition(/\{(.*?)\}/)
        keyString = keyStringArray[0]
        
        keyString.each_char do |key|
          if RubyXMacro::KEYCODES[key] == nil then
            self.keyPress(key)
          else
            keycode = RubyXMacro::KEYCODES[key]
            keyCase = keycode[-1]
            keycode = keycode.chop.to_i
            if keyCase == 'l' then
              keycodePress(keycode)
            else
              keycodeShiftPress(keycode)
            end
          end
        end
       
        specialKey = keyStringArray[1].slice(1..(keyStringArray[1].length - 2))
        if specialKey != nil && specialKey.length > 0 then
          specialKey.upcase!
          keycodePress(RubyXMacro::SPECIAL_KEYCODES[specialKey])
        end
        
        keyString = keyStringArray[2]
      end
    end
  end  
end
