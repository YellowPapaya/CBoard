#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include <iostream>
#include <string>

class CBoard {
	private:
		Display* display = XOpenDisplay(NULL);
	public:
		void keyDown(const char* key) {
			KeySym keysym = XStringToKeysym (key);
			KeyCode keycode = XKeysymToKeycode (display, keysym);
			XTestFakeKeyEvent(display, keycode, True, 0);
			XSync(display, True); // Flush queue without ending other events
		}

		void keyUp (const char* key) {
			KeySym keysym = XStringToKeysym (key);
			KeyCode keycode = XKeysymToKeycode (display, keysym);
			XTestFakeKeyEvent(display, keycode, False, 0); 
			XSync(display, True); 
		}

		void press(const char* key) {
			keyDown(key);
			keyUp(key);
		}

		void typewrite (std::string text) {
			for (char c:text) {
				std::string str(1, c);
				const char* cstr = str.c_str();
				press(cstr);
			}
				
		}
};
 
int main () {
	sleep(1);
	CBoard cb;
	cb.typewrite("the quick brown fox jumps over the lazy dog");
	cb.press("Return");
}
