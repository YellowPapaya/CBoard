#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <unordered_map>

class CBoard {
	private:
		Display* display = XOpenDisplay(NULL);
		std::string shiftSet = "~!@#$%^&*()_+{}|:\"<>?";
	public:
		void keyDown(std::string key) {
			if ((key.length() == 1) && (isupper(key[0]) || (shiftSet.find(key) != std::string::npos))) {
				XTestFakeKeyEvent(display, keyboardMapping["shift"], true, 0);
			}
			XTestFakeKeyEvent(display, keyboardMapping[key], True, 0);
			XSync(display, True); // Flush queue without ending other events
		}

		void keyUp (std::string key) {
			if ((key.length() == 1) && (isupper(key[0]) || (shiftSet.find(key) != std::string::npos))) {
				XTestFakeKeyEvent(display, keyboardMapping["shift"], false, 0);
			}
			XTestFakeKeyEvent(display, keyboardMapping[key], False, 0); 
			XSync(display, True); 
		}

		void press(std::string key) {
			keyDown(key);
			keyUp(key);
		}

		void typewrite (std::string text) {
			for (char c:text) {
				std::string str(1, c);
				press(str);
			}
				
		}
	private:
		std::unordered_map<std::string, KeyCode> keyboardMapping = {
		{"1", XKeysymToKeycode(display, XStringToKeysym("1"))},
		{"2", XKeysymToKeycode(display, XStringToKeysym("2"))},
		{"3", XKeysymToKeycode(display, XStringToKeysym("3"))},
		{"4", XKeysymToKeycode(display, XStringToKeysym("4"))},
		{"5", XKeysymToKeycode(display, XStringToKeysym("5"))},
		{"6", XKeysymToKeycode(display, XStringToKeysym("6"))},
		{"7", XKeysymToKeycode(display, XStringToKeysym("7"))},
		{"8", XKeysymToKeycode(display, XStringToKeysym("8"))},
		{"9", XKeysymToKeycode(display, XStringToKeysym("9"))},
		{"a", XKeysymToKeycode(display, XStringToKeysym("a"))},
		{"b", XKeysymToKeycode(display, XStringToKeysym("b"))},
		{"c", XKeysymToKeycode(display, XStringToKeysym("c"))},
		{"d", XKeysymToKeycode(display, XStringToKeysym("d"))},
		{"e", XKeysymToKeycode(display, XStringToKeysym("e"))},
		{"f", XKeysymToKeycode(display, XStringToKeysym("f"))},
		{"g", XKeysymToKeycode(display, XStringToKeysym("g"))},
		{"h", XKeysymToKeycode(display, XStringToKeysym("h"))},
		{"i", XKeysymToKeycode(display, XStringToKeysym("i"))},
		{"j", XKeysymToKeycode(display, XStringToKeysym("j"))},
		{"k", XKeysymToKeycode(display, XStringToKeysym("k"))},
		{"l", XKeysymToKeycode(display, XStringToKeysym("l"))},
		{"m", XKeysymToKeycode(display, XStringToKeysym("m"))},
		{"n", XKeysymToKeycode(display, XStringToKeysym("n"))},
		{"o", XKeysymToKeycode(display, XStringToKeysym("o"))},
		{"p", XKeysymToKeycode(display, XStringToKeysym("p"))},
		{"q", XKeysymToKeycode(display, XStringToKeysym("q"))},
		{"r", XKeysymToKeycode(display, XStringToKeysym("r"))},
		{"s", XKeysymToKeycode(display, XStringToKeysym("s"))},
		{"t", XKeysymToKeycode(display, XStringToKeysym("t"))},
		{"u", XKeysymToKeycode(display, XStringToKeysym("u"))},
		{"v", XKeysymToKeycode(display, XStringToKeysym("v"))},
		{"w", XKeysymToKeycode(display, XStringToKeysym("w"))},
		{"x", XKeysymToKeycode(display, XStringToKeysym("x"))},
		{"y", XKeysymToKeycode(display, XStringToKeysym("y"))},
		{"z", XKeysymToKeycode(display, XStringToKeysym("z"))},
		{"A", XKeysymToKeycode(display, XStringToKeysym("A"))},
		{"B", XKeysymToKeycode(display, XStringToKeysym("B"))},
		{"C", XKeysymToKeycode(display, XStringToKeysym("C"))},
		{"D", XKeysymToKeycode(display, XStringToKeysym("D"))},
		{"E", XKeysymToKeycode(display, XStringToKeysym("E"))},
		{"F", XKeysymToKeycode(display, XStringToKeysym("F"))},
		{"G", XKeysymToKeycode(display, XStringToKeysym("G"))},
		{"H", XKeysymToKeycode(display, XStringToKeysym("H"))},
		{"I", XKeysymToKeycode(display, XStringToKeysym("I"))},
		{"J", XKeysymToKeycode(display, XStringToKeysym("J"))},
		{"K", XKeysymToKeycode(display, XStringToKeysym("K"))},
		{"L", XKeysymToKeycode(display, XStringToKeysym("L"))},
		{"M", XKeysymToKeycode(display, XStringToKeysym("M"))},
		{"N", XKeysymToKeycode(display, XStringToKeysym("N"))},
		{"O", XKeysymToKeycode(display, XStringToKeysym("O"))},
		{"P", XKeysymToKeycode(display, XStringToKeysym("P"))},
		{"Q", XKeysymToKeycode(display, XStringToKeysym("Q"))},
		{"R", XKeysymToKeycode(display, XStringToKeysym("R"))},
		{"S", XKeysymToKeycode(display, XStringToKeysym("S"))},
		{"T", XKeysymToKeycode(display, XStringToKeysym("T"))},
		{"U", XKeysymToKeycode(display, XStringToKeysym("U"))},
		{"V", XKeysymToKeycode(display, XStringToKeysym("V"))},
		{"W", XKeysymToKeycode(display, XStringToKeysym("W"))},
		{"X", XKeysymToKeycode(display, XStringToKeysym("X"))},
		{"Y", XKeysymToKeycode(display, XStringToKeysym("Y"))},
		{"Z", XKeysymToKeycode(display, XStringToKeysym("Z"))},
		{"backspace",         XKeysymToKeycode(display, XStringToKeysym("BackSpace"))},
		{"\b",                XKeysymToKeycode(display, XStringToKeysym("BackSpace"))},
		{"tab",               XKeysymToKeycode(display, XStringToKeysym("Tab"))},
		{"enter",             XKeysymToKeycode(display, XStringToKeysym("Return"))},
		{"return",            XKeysymToKeycode(display, XStringToKeysym("Return"))},
		{"shift",             XKeysymToKeycode(display, XStringToKeysym("Shift_L"))},
		{"ctrl",              XKeysymToKeycode(display, XStringToKeysym("Control_L"))},
		{"alt",               XKeysymToKeycode(display, XStringToKeysym("Alt_L"))},
		{"pause",             XKeysymToKeycode(display, XStringToKeysym("Pause"))},
		{"capslock",          XKeysymToKeycode(display, XStringToKeysym("Caps_Lock"))},
		{"esc",               XKeysymToKeycode(display, XStringToKeysym("Escape"))},
		{"escape",            XKeysymToKeycode(display, XStringToKeysym("Escape"))},
		{"pgup",              XKeysymToKeycode(display, XStringToKeysym("Page_Up"))},
		{"pgdn",              XKeysymToKeycode(display, XStringToKeysym("Page_Down"))},
		{"pageup",            XKeysymToKeycode(display, XStringToKeysym("Page_Up"))},
		{"pagedown",          XKeysymToKeycode(display, XStringToKeysym("Page_Down"))},
		{"end",               XKeysymToKeycode(display, XStringToKeysym("End"))},
		{"home",              XKeysymToKeycode(display, XStringToKeysym("Home"))},
		{"left",              XKeysymToKeycode(display, XStringToKeysym("Left"))},
		{"up",                XKeysymToKeycode(display, XStringToKeysym("Up"))},
		{"right",             XKeysymToKeycode(display, XStringToKeysym("Right"))},
		{"down",              XKeysymToKeycode(display, XStringToKeysym("Down"))},
		{"select",            XKeysymToKeycode(display, XStringToKeysym("Select"))},
		{"print",             XKeysymToKeycode(display, XStringToKeysym("Print"))},
		{"execute",           XKeysymToKeycode(display, XStringToKeysym("Execute"))},
		{"prtsc",             XKeysymToKeycode(display, XStringToKeysym("Print"))},
		{"prtscr",            XKeysymToKeycode(display, XStringToKeysym("Print"))},
		{"prntscrn",          XKeysymToKeycode(display, XStringToKeysym("Print"))},
		{"printscreen",       XKeysymToKeycode(display, XStringToKeysym("Print"))},
		{"insert",            XKeysymToKeycode(display, XStringToKeysym("Insert"))},
		{"del",               XKeysymToKeycode(display, XStringToKeysym("Delete"))},
		{"delete",            XKeysymToKeycode(display, XStringToKeysym("Delete"))},
		{"help",              XKeysymToKeycode(display, XStringToKeysym("Help"))},
		{"winleft",           XKeysymToKeycode(display, XStringToKeysym("Super_L"))},
		{"winright",          XKeysymToKeycode(display, XStringToKeysym("Super_R"))},
		{"apps",              XKeysymToKeycode(display, XStringToKeysym("Super_L"))},
		{"num0",              XKeysymToKeycode(display, XStringToKeysym("KP_0"))},
		{"num1",              XKeysymToKeycode(display, XStringToKeysym("KP_1"))},
		{"num2",              XKeysymToKeycode(display, XStringToKeysym("KP_2"))},
		{"num3",              XKeysymToKeycode(display, XStringToKeysym("KP_3"))},
		{"num4",              XKeysymToKeycode(display, XStringToKeysym("KP_4"))},
		{"num5",              XKeysymToKeycode(display, XStringToKeysym("KP_5"))},
		{"num6",              XKeysymToKeycode(display, XStringToKeysym("KP_6"))},
		{"num7",              XKeysymToKeycode(display, XStringToKeysym("KP_7"))},
		{"num8",              XKeysymToKeycode(display, XStringToKeysym("KP_8"))},
		{"num9",              XKeysymToKeycode(display, XStringToKeysym("KP_9"))},
		{"multiply",          XKeysymToKeycode(display, XStringToKeysym("KP_Multiply"))},
		{"add",               XKeysymToKeycode(display, XStringToKeysym("KP_Add"))},
		{"separator",         XKeysymToKeycode(display, XStringToKeysym("KP_Separator"))},
		{"subtract",          XKeysymToKeycode(display, XStringToKeysym("KP_Subtract"))},
		{"decimal",           XKeysymToKeycode(display, XStringToKeysym("KP_Decimal"))},
		{"divide",            XKeysymToKeycode(display, XStringToKeysym("KP_Divide"))},
		{"f1",                XKeysymToKeycode(display, XStringToKeysym("F1"))},
		{"f2",                XKeysymToKeycode(display, XStringToKeysym("F2"))},
		{"f3",                XKeysymToKeycode(display, XStringToKeysym("F3"))},
		{"f4",                XKeysymToKeycode(display, XStringToKeysym("F4"))},
		{"f5",                XKeysymToKeycode(display, XStringToKeysym("F5"))},
		{"f6",                XKeysymToKeycode(display, XStringToKeysym("F6"))},
		{"f7",                XKeysymToKeycode(display, XStringToKeysym("F7"))},
		{"f8",                XKeysymToKeycode(display, XStringToKeysym("F8"))},
		{"f9",                XKeysymToKeycode(display, XStringToKeysym("F9"))},
		{"f10",               XKeysymToKeycode(display, XStringToKeysym("F10"))},
		{"f11",               XKeysymToKeycode(display, XStringToKeysym("F11"))},
		{"f12",               XKeysymToKeycode(display, XStringToKeysym("F12"))},
		{"f13",               XKeysymToKeycode(display, XStringToKeysym("F13"))},
		{"f14",               XKeysymToKeycode(display, XStringToKeysym("F14"))},
		{"f15",               XKeysymToKeycode(display, XStringToKeysym("F15"))},
		{"f16",               XKeysymToKeycode(display, XStringToKeysym("F16"))},
		{"f17",               XKeysymToKeycode(display, XStringToKeysym("F17"))},
		{"f18",               XKeysymToKeycode(display, XStringToKeysym("F18"))},
		{"f19",               XKeysymToKeycode(display, XStringToKeysym("F19"))},
		{"f20",               XKeysymToKeycode(display, XStringToKeysym("F20"))},
		{"f21",               XKeysymToKeycode(display, XStringToKeysym("F21"))},
		{"f22",               XKeysymToKeycode(display, XStringToKeysym("F22"))},
		{"f23",               XKeysymToKeycode(display, XStringToKeysym("F23"))},
		{"f24",               XKeysymToKeycode(display, XStringToKeysym("F24"))},
		{"numlock",           XKeysymToKeycode(display, XStringToKeysym("Num_Lock"))},
		{"scrolllock",        XKeysymToKeycode(display, XStringToKeysym("Scroll_Lock"))},
		{"shiftleft",         XKeysymToKeycode(display, XStringToKeysym("Shift_L"))},
		{"shiftright",        XKeysymToKeycode(display, XStringToKeysym("Shift_R"))},
		{"ctrlleft",          XKeysymToKeycode(display, XStringToKeysym("Control_L"))},
		{"ctrlright",         XKeysymToKeycode(display, XStringToKeysym("Control_R"))},
		{"altleft",           XKeysymToKeycode(display, XStringToKeysym("Alt_L"))},
		{"altright",          XKeysymToKeycode(display, XStringToKeysym("Alt_R"))},
		{" ", XKeysymToKeycode(display, XStringToKeysym("space"))},
		{"space", XKeysymToKeycode(display, XStringToKeysym("space"))},
		{"\t", XKeysymToKeycode(display, XStringToKeysym("Tab"))},
		{"\n", XKeysymToKeycode(display, XStringToKeysym("Return"))},
		{"\r", XKeysymToKeycode(display, XStringToKeysym("Return"))},
		{"\e", XKeysymToKeycode(display, XStringToKeysym("Escape"))},
		{"!", XKeysymToKeycode(display, XStringToKeysym("exclam"))},
		{"#", XKeysymToKeycode(display, XStringToKeysym("numbersign"))},
		{"%", XKeysymToKeycode(display, XStringToKeysym("percent"))},
		{"$", XKeysymToKeycode(display, XStringToKeysym("dollar"))},
		{"&", XKeysymToKeycode(display, XStringToKeysym("ampersand"))},
		{"\"", XKeysymToKeycode(display, XStringToKeysym("quotedbl"))},
		{"'", XKeysymToKeycode(display, XStringToKeysym("apostrophe"))},
		{"(", XKeysymToKeycode(display, XStringToKeysym("parenleft"))},
		{")", XKeysymToKeycode(display, XStringToKeysym("parenright"))},
		{"*", XKeysymToKeycode(display, XStringToKeysym("asterisk"))},
		{"=", XKeysymToKeycode(display, XStringToKeysym("equal"))},
		{"+", XKeysymToKeycode(display, XStringToKeysym("plus"))},
		{",", XKeysymToKeycode(display, XStringToKeysym("comma"))},
		{"-", XKeysymToKeycode(display, XStringToKeysym("minus"))},
		{".", XKeysymToKeycode(display, XStringToKeysym("period"))},
		{"/", XKeysymToKeycode(display, XStringToKeysym("slash"))},
		{":", XKeysymToKeycode(display, XStringToKeysym("colon"))},
		{";", XKeysymToKeycode(display, XStringToKeysym("semicolon"))},
		{"<", XKeysymToKeycode(display, XStringToKeysym("less"))},
		{">", XKeysymToKeycode(display, XStringToKeysym("greater"))},
		{"?", XKeysymToKeycode(display, XStringToKeysym("question"))},
		{"@", XKeysymToKeycode(display, XStringToKeysym("at"))},
		{"[", XKeysymToKeycode(display, XStringToKeysym("bracketleft"))},
		{"]", XKeysymToKeycode(display, XStringToKeysym("bracketright"))},
		{"\\", XKeysymToKeycode(display, XStringToKeysym("backslash"))},
		{"^", XKeysymToKeycode(display, XStringToKeysym("asciicircum"))},
		{"_", XKeysymToKeycode(display, XStringToKeysym("underscore"))},
		{"`", XKeysymToKeycode(display, XStringToKeysym("grave"))},
		{"{", XKeysymToKeycode(display, XStringToKeysym("braceleft"))},
		{"|", XKeysymToKeycode(display, XStringToKeysym("bar"))},
		{"}", XKeysymToKeycode(display, XStringToKeysym("braceright"))},
		{"~", XKeysymToKeycode(display, XStringToKeysym("asciitilde"))}
		};
};
 
int main () {
	CBoard cb;
	cb.typewrite("Hello World!");
}
