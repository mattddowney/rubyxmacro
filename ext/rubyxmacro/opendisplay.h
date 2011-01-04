/***************************************************************************** 
 *
 * opendisplay.h - a function to open an X11 display.
 * Portions Copyright (C) 2010 Matthew Downey <mattddowney@gmail-NOSPAM-.com>
 * 
 * This code was copied and modified from:
 * xmacro (http://xmacro.sourceforge.net/) which is:
 * Copyright (C) 2000 Gabor Keresztfalvi <keresztg@mail.com>
 *
 * Which was based heavily on:
 * xremote (http://infa.abo.fi/~chakie/xremote/) which is:
 * Copyright (C) 2000 Jan Ekholm <chakie@infa.abo.fi>
 *	
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 ****************************************************************************/
 
#include <X11/extensions/XTest.h>

// open the X11 display
Display * openDisplay (const char * displayName) {
	int event, error, major, minor;  

	// open the display
	Display * xDisplay = XOpenDisplay(displayName);

	// did we get it?
	if(!xDisplay) {
		// nope, so show error and abort
		fprintf(stderr, "could not open display \"%s\", aborting.\n", XDisplayName(displayName));
		exit(EXIT_FAILURE);
	}

	// does the remote display have the Xtest-extension?
	if(!XTestQueryExtension(xDisplay, &event, &error, &major, &minor)) {
		// nope, extension not supported
		fprintf(stderr, "XTest extension not supported on server \"%s\", aborting.\n", DisplayString(xDisplay));

		// close the display and go away
		XCloseDisplay(xDisplay);
		exit(EXIT_FAILURE);
	}

	// take control of the server
	XTestGrabControl(xDisplay, 1);

	// sync the server
	XSync(xDisplay, 1);
	
	// discard all events
	XTestDiscard (xDisplay);

	// return the display
	return xDisplay;
}
