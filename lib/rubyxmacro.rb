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

  KEYCODES = {
    '`' => '49l',
    '~' => '49u',
    '1' => '10l',
    '!' => '10u',
    '2' => '11l',
    '@' => '11u',
    '3' => '12l',
    '#' => '12u',
    '4' => '13l',
    '$' => '13u',
    '5' => '14l',
    '%' => '14u',
    '6' => '15l',
    '^' => '15u',
    '7' => '16l',
    '&' => '16u',
    '8' => '17l',
    '*' => '17u',
    '9' => '18l',
    '(' => '18u',
    '0' => '19l',
    ')' => '19u',
    '-' => '20l',
    '_' => '20u',
    '=' => '21l',
    '+' => '21u',
    '[' => '34l',
    '{' => '34u',
    ']' => '35l',
    '}' => '35u',
    '\\' => '51l',
    '|' => '51u',
    ';' => '47l',
    ':' => '47u',
    "'" => '48l',
    '"' => '48u',
    ',' => '59l',
    '<' => '59u',
    '.' => '60l',
    '>' => '60u',
    '/' => '61l',
    '?' => '61u'
  }
end
