# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "rubyxmacro/version"

Gem::Specification.new do |s|
  s.name        = "rubyxmacro"
  s.version     = RubyXMacro::VERSION
  s.platform    = Gem::Platform::RUBY
  s.authors     = ["Matthew Downey"]
  s.email       = ["mattddowney@gmail.com"]
  s.homepage    = "http://www.writehack.com"
  s.summary     = ""
  s.description = ""

  #s.rubyforge_project = "rubyxmacro"

  s.files         = `git ls-files`.split("\n")
  #s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  #s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]
  s.extensions = ["ext/rubyxmacro/extconf.rb"]
end
