require 'rubyxmacro/rubyxmacro'

module RubyXMacro
  class Display
    def sendKeys(keyString)
      keyString.split('').each do |key|
        self.keyPress(key)
      end
    end
  end
end
