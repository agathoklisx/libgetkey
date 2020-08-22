#include <stdio.h>

#include "libgetkey.h"

static void println (utf8 c, char *msg) {
  fprintf (stdout, "Pressed (int): %d, char |%s|\r\n", c, msg);
}

static char *ustring_character (utf8 c, char *buf, int *len) {
  *len = 1;
  if (c < 0x80) {
    buf[0] = (char) c;
  } else if (c < 0x800) {
    buf[0] = (c >> 6) | 0xC0;
    buf[1] = (c & 0x3F) | 0x80;
    (*len)++;
  } else if (c < 0x10000) {
    buf[0] = (c >> 12) | 0xE0;
    buf[1] = ((c >> 6) & 0x3F) | 0x80;
    buf[2] = (c & 0x3F) | 0x80;
    (*len) += 2;
  } else if (c < 0x110000) {
    buf[0] = (c >> 18) | 0xF0;
    buf[1] = ((c >> 12) & 0x3F) | 0x80;
    buf[2] = ((c >> 6) & 0x3F) | 0x80;
    buf[3] = (c & 0x3F) | 0x80;
    (*len) += 3;
  } else
    return 0;

  buf[*len] = '\0';
  return buf;
}

int main (int argc, char **argv) {
  if (-1 == term_raw_mode (0))
    return 1;

  utf8 c;

  fprintf (stdout, "Press 'q' to quit\r\n");

  char buf[5];
  int len;

  while ('q' != (c = getkey(0))) {
    switch (c) {
      case (FN_KEY(1)):      println (c, "FN-1"); break;
      case (FN_KEY(2)):      println (c, "FN-2"); break;
      case (FN_KEY(3)):      println (c, "FN-3"); break;
      case (FN_KEY(4)):      println (c, "FN-4"); break;
      case (FN_KEY(5)):      println (c, "FN-5"); break;
      case (FN_KEY(6)):      println (c, "FN-6"); break;
      case (FN_KEY(7)):      println (c, "FN-7"); break;
      case (FN_KEY(8)):      println (c, "FN-8"); break;
      case (FN_KEY(9)):      println (c, "FN-9"); break;
      case (FN_KEY(10)):     println (c, "FN-10"); break;
      case (FN_KEY(11)):     println (c, "FN-11"); break;
      case (FN_KEY(12)):     println (c, "FN-12"); break;
      case (BACKSPACE_KEY):  println (c, "CTRL-h/Backspace"); break;
      case (ESCAPE_KEY):     println (c, "Escape"); break;
      case (ARROW_DOWN_KEY): println (c, "Down Arrow"); break;
      case (ARROW_UP_KEY):   println (c, "Up Arrow"); break;
      case (ARROW_LEFT_KEY): println (c, "Left Arrow"); break;
      case (ARROW_RIGHT_KEY):println (c, "Right Arrow"); break;
      case (HOME_KEY):       println (c, "Home"); break;
      case (DELETE_KEY):     println (c, "Delete"); break;
      case (INSERT_KEY):     println (c, "Insert"); break;
      case (PAGE_DOWN_KEY):  println (c, "Page down"); break;
      case (PAGE_UP_KEY):    println (c, "Page up"); break;
      case (END_KEY):        println (c, "End"); break;
      case (CTRL(0)):        println (c, "NULL");   break;
      case (CTRL(1)):        println (c, "CTRL-a"); break;
      case (CTRL(2)):        println (c, "CTRL-b"); break;
      case (CTRL(3)):        println (c, "CTRL-x"); break;
      case (CTRL(4)):        println (c, "CTRL-d"); break;
      case (CTRL(5)):        println (c, "CTRL-e"); break;
      case (CTRL(6)):        println (c, "CTRL-f"); break;
      case (CTRL(7)):        println (c, "CTRL-g"); break;
      case (CTRL(9)):        println (c, "CTRL-i/tab"); break;
      case (CTRL(10)):       println (c, "CTRL-j"); break;
      case (CTRL(11)):       println (c, "CTRL-k"); break;
      case (CTRL(12)):       println (c, "CTRL-l"); break;
      case (CTRL(13)):       println (c, "CTRL-m/CR");     break;
      case (CTRL(14)):       println (c, "CTRL-n"); break;
      case (CTRL(15)):       println (c, "CTRL-o"); break;
      case (CTRL(16)):       println (c, "CTRL-p"); break;
      case (CTRL(17)):       println (c, "CTRL-q"); break;
      case (CTRL(18)):       println (c, "CTRL-r"); break;
      case (CTRL(19)):       println (c, "CTRL-s"); break;
      case (CTRL(20)):       println (c, "CTRL-t");break;
      case (CTRL(21)):       println (c, "CTRL-u");break;
      case (CTRL(22)):       println (c, "CTRL-v");break;
      case (CTRL(23)):       println (c, "CTRL-w");break;
      case (CTRL(24)):       println (c, "CTRL-x");break;
      case (CTRL(25)):       println (c, "CTRL-y");break;
      case (CTRL(26)):       println (c, "CTRL-z");break;
      case (CTRL(28)):       println (c, "CTRL-$");break;
      case (CTRL(29)):       println (c, "CTRL-%");break;
      case (CTRL(30)):       println (c, "CTRL-^");break;
      case (CTRL(31)):       println (c, "CTRL-_");break;

      default:
        println (c, ustring_character (c, buf, &len));
    }
  }

  println (c, ustring_character (c, buf, &len));

  term_orig_mode (0);

  return 0;
}
