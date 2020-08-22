#ifndef LIBGETKEY_H
#define LIBGETKEY_H

#define BACKSPACE_KEY   010
#define ESCAPE_KEY      033
#define ARROW_DOWN_KEY  0402
#define ARROW_UP_KEY    0403
#define ARROW_LEFT_KEY  0404
#define ARROW_RIGHT_KEY 0405
#define HOME_KEY        0406
#define FN_KEY(x)       (x + 0410)
#define DELETE_KEY      0512
#define INSERT_KEY      0513
#define PAGE_DOWN_KEY   0522
#define PAGE_UP_KEY     0523
#define END_KEY         0550

#ifndef CTRL
#define CTRL(X) (X & 037)
#endif

typedef signed int utf8;

utf8 getkey (int);

#ifdef NEED_TERM

int term_raw_mode (int);
int term_orig_mode (int);

#endif /* NEED_TERM */

#endif /* LIBGETKEY_H */
