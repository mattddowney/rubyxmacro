# extconf.rb
# Copyright (C) 2010 Matthew Downey <mattddowney@gmail-NOSPAM-.com>
#	
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

require 'mkmf'
if have_library("Xtst") then
	create_makefile("rubyxmacro")
else
	puts "Cannot find Xtst library."
	puts "Try apt-get install libxtst-dev"
end
