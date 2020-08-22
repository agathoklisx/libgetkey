This is a tiny function for POSIX systems, that returns the integer represantation of a key.

Optionally it can save the original terminal settings and place the terminal in raw mode.

Included also an interactive test unit. Issue make to build it.

This function, it should work the same, under the rxvt-unicode, xterm, st (from suckless) and Linux terminals.

It is derived from the kilo editor, so it has the same license, attached in this repository.

The main difference, besides the enhancements to handle more cases, is that it has support for UTF-8 byte sequences.

References:

https://github.com/antirez/kilo
