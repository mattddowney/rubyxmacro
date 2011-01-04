require "rubygems"
require "rake"
require "bundler"

require "rake/extensiontask"
Rake::ExtensionTask.new("rubyxmacro") do |extension|
  extension.lib_dir = "lib/rubyxmacro"
end

task :build => [:clean, :compile]
Bundler::GemHelper.install_tasks
