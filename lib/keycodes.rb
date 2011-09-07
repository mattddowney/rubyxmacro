module RubyXMacro
  SPECIAL_KEYCODES = {
	'BACKSPACE' => 22,
	'BS' => 22,
	'BKSP' => 22,
	'BREAK' => 127,
	'CAPSLOCK' => 66,
	'DELETE' => 119,
	'DEL' => 119,
	'DOWN' => 116,
	'END' => 115,
	'ENTER' => 36,
	'ESC' => 9,
	#'HELP' => 
	'HOME' => 110,
	'INSERT' => 118,
	'INS' => 118,
	'LEFT' => 113,
	'NUMLOCK' => 77,
	'PGDN' => 117,
	'PGUP' => 112,
	#'PRTSC' => 
	'RIGHT' => 114,
	#'SCROLLLOCK' =>
	'TAB' => 23,
	'UP' => 111,
	'F1' => 67,
	'F2' => 68,
	'F3' => 69,
	'F4' => 70,
	'F5' => 71,
	'F6' => 72,
	'F7' => 73,
	'F8' => 74,
	'F9' => 75,
	'F10' => 76,
	'F11' => 95,
	'F12' => 96
	#'F13' =>
	#'F14' =>
	#'F15' =>
	#'F16' =>
  }

  KEYCODES = {
    ' ' => '65l',
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
