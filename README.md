# CBoard
Simulate keyboard inputs in C++. Inspired by PyAutoGui after a complaint about how much more difficult it was to simulate key events in C++ with X11.

## Requirements
X11 and X11/extensions

## Compile
Make sure to add -lX11 and -lXtst as your flags. If you're going to use this as a header file, make sure to add header guards and get rid of int main().
