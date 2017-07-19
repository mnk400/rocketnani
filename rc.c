#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

//String which a rocket using ASCII characters
char rocket[12][20] ={
"    _\n\
",
"   /^\\\n\
",
"   |-|\n\
",
"   |R|\n\
",
"   |O|\n\
",
"   |C|\n\
",
"   |K|\n\
",
"   |E|\n\
",
"  /|T|\\\n\
",
" / | | \\\n\
",
"|  | |  |\n\
",
" *-\"\"\"-*\n\
"
};

int main()
{
    system("clear");

    struct winsize win;    //struct winsize to get the window's width and height.
    ioctl(0, TIOCGWINSZ, &win);
    int columns = win.ws_col;
    int stringLength[12],i,j=300000;

    for(i = 0; i < 12; i ++)
    {
        stringLength[i]=strlen(rocket[i]);
    }
 
    for (i = 0; i < win.ws_col; i ++)
    printf("\n");
    for (i = 0; i < 12; i ++)
    {
        printf("%*s", columns/2 + stringLength[i] - 4, rocket[i]);
    }
    
    for ( i = 0; i < win.ws_row; i++) 
    {
        usleep(j);
        j = (int)(j * 0.9);
        printf("\n");
    }

    system("clear");
    return 0;

}
