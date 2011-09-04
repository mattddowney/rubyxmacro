require "rubygems"
require "rake"
require "bundler"
require "rake/extensiontask"

Rake::ExtensionTask.new("rubyxmacro") do |extension|
  extension.lib_dir = "lib/rubyxmacro"
end

task :chmod do
  File.chmod(0775, 'lib/rubyxmacro/rubyxmacro.so')
end

task :build => [:clean, :compile, :chmod]

Bundler::GemHelper.install_tasks
