require 'rubyxmacro/rubyxmacro'

module RubyXMacro
  class Display
    # Press and release a string of keys.
    def sendKeys(keyString)
      keyString.split('').each do |key|
        self.keyPress(key)
      end
    end
  end
end
