#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

char rocket[12][20] ={
"    _\n\
",
"   /^\\\n\
",
"   |-|\n\
",
"   |M|\n\
",
"   |N|\n\
",
"   |K|\n\
",
"   | |\n\
",
"   |4|\n\
",
"  /|0|\\\n\
",
" / |0| \\\n\
",
"|  | |  |\n\
",
" *-\"\"\"-*\n\
"
};

int main()
{
    system("clear");

    struct winsize win;                                   //struct winsize to get the window's width and height.
    ioctl(0, TIOCGWINSZ, &win);
    int columns = win.ws_col;
    int stringLength[12],i;
    for(i = 0; i < 12; i ++)
    {
      stringLength[i]=strlen(rocket[i]);
      //printf("%d\n",stringLength[i]);
    }
    //printf("%*s\n", columns / 2 + stringLength, string );
    for (i = 0; i < win.ws_row; i ++)
    printf("\n");
    for (i = 0; i < 12; i ++)
    {
      printf("%*s", columns/2 + stringLength[i] - 4, rocket[i]);
    }
  //  printf("%s", columns/2 + string rocket);
    //printf("%s",rocket);
    int j = 300000;
    for (int i = 0; i < win.ws_row; i++) {
        usleep(j);
        j = (int)(j * 0.3);
        printf("\n");
    }
    return 0;

}
