require 'rubyxmacro'
require 'test/unit'

class TestRubyXMacro < Test::Unit::TestCase

  def setup
    @d = RubyXMacro::Display.new
  end

  def test_display
    assert_instance_of(RubyXMacro::Display, @d)
  end

  def test_mouse_1
    assert_nil(@d.moveMouse(100,200))
    assert_nil(@d.click)
    sleep 0.1
  end

  def test_special
    assert_nil(@d.sendKeys '~!@#$%^&*()_+{}|:"<>?{ENTER}')
    assert_nil(@d.sendKeys "`1234567890-=[]\;',./{ENTER}")
    assert_nil(@d.sendKeys "This text should be highlighted")
    3.times do
      assert_nil(@d.click)
    end
  end

end
