#include "header.h"
#include "Screen.h"

// OK

Screen :: Screen ()
{
    time_show = 0;
    time_stop = 0;
    sc_time_buf = 0;
    initscr ();
    cbreak ();
    noecho ();
    keypad (stdscr, TRUE);
    get_max_x_y ();
    score = 0;
    nodelay(stdscr, TRUE);
    curs_set(0);
}

void Screen :: Start_Screen (void)
{
    clear();
    int choice = 0;
    int c;
    int center_x = width/2 - 7;
    int sub1_y = height/2 - 2;
    int sub2_y = height/2 - 1;
    int sub3_y = height/2;
    mvaddstr (height/2 - 2, width/2 - 9, "> ");
    start_color();
    init_pair (1, COLOR_YELLOW, COLOR_BLUE); // Pair 1 ¶À¦rÂÅ©³
    attrset (A_BOLD|COLOR_PAIR(1));
    for (int i = 0; i <= width ; i++)
        mvaddstr (0, i, " ");
    mvaddstr (0, center_x, "Sanke Game");
    mvaddstr (0, width-14, "By F74024062");
    attrset (A_NORMAL);
    mvaddstr (sub1_y, center_x, "Start Game");
    mvaddstr (sub2_y, center_x, "Help");
    mvaddstr (sub3_y, center_x, "Exit");
    while ( ( c = getch() ) != '\n' )
    {
        if ( c == KEY_DOWN )
            choice++;
        if ( c == KEY_UP )
            choice--;
        choice = ( choice + 3 ) % 3;
        if ( choice == 0 )
        {
            mvaddstr (height/2 - 2, width/2 - 9, "> ");
            mvaddstr (height/2 - 1, width/2 - 9, "  ");
            mvaddstr (height/2, width/2 - 9, "  ");
        }
        if ( choice == 1 )
        {
            mvaddstr (height/2 - 2, width/2 - 9, "  ");
            mvaddstr (height/2 - 1, width/2 - 9, "> ");
            mvaddstr (height/2, width/2 - 9, "  ");
        }
        if ( choice == 2 )
        {
            mvaddstr (height/2 - 2, width/2 - 9, "  ");
            mvaddstr (height/2 - 1, width/2 - 9, "  ");
            mvaddstr (height/2, width/2 - 9, "> ");
        }
        move (height - 2, width - 1);
    }
    if ( choice == 0 )
        Game_Start();
    if ( choice == 1 )
        Show_Help();
    if ( choice == 2 )
        Exit_win();

}
void Screen :: Exit_win (void)
{
    char c;
    clear();
    attrset (A_BOLD|COLOR_PAIR(1));
    mvaddstr (height/2 , width/2 - 18, "     Are you sure to quit ?  Y/N    ");
    while (1)
    {
        c = getch();
        if ( c == 'Y' || c == 'y' || c == 'n' || c == 'N' )
            break;
    }
    if ( c == 'Y' || c == 'y' )
    {
        endwin();
        exit(0);
    }
    if ( c == 'N' || c == 'n')
    {
        attrset (A_NORMAL);
        clear();
        Start_Screen ();
    }
}
void Screen :: Game_Start (void)
{
    int center_x = width/2 - 7;
    clear();
    attrset (A_BOLD|COLOR_PAIR(1));
    for (int i = 0; i <= width ; i++)
        mvaddstr (0, i, " ");
    mvaddstr (0, center_x, "Sanke Game   ");
    mvaddstr (0, width-14, "By F74024062");
    attrset (A_NORMAL);

    attrset (A_REVERSE);
    for (int i = 0; i <= width ; i++)
    {
        mvaddstr (1, i, " ");
        mvaddstr (2, i, " ");
    }
    mvaddstr (1, 3, " SCORE : ");
    mvaddstr (2, 3, " TIME  :       s");
    mvaddstr (1, width - 22 , " Status :         ");
    attrset (A_NORMAL);
    start = time (NULL);
}
void Screen :: change_score (int r, int num)
{
    score += r*num;
}
void Screen :: show_score (void)
{
    attrset (A_REVERSE);
    mvprintw (1, 13, "%5d", score);
    attrset (A_NORMAL);
}
void Screen :: get_time (void)
{
    end = time (NULL);
}
void Screen :: Show_Help (void)
{
    clear();
    init_pair (1, COLOR_YELLOW, COLOR_BLUE);
    attrset (A_BOLD|COLOR_PAIR(1));
    for (int i = 0; i <= width ; i++)
        mvaddstr (0, i, " ");
    int center_x = width/2 - 7;
    mvaddstr (0, center_x, "Sanke Game");
    mvaddstr (0, width-14, "By F74024062");
    attrset (A_BOLD);

    mvaddstr (2, 5, "Things :");

    init_pair (4, COLOR_RED, COLOR_BLACK);
    attrset (A_BOLD|COLOR_PAIR(4));
    mvaddstr (3, 15, r_f_char);
    init_pair (3, COLOR_GREEN, COLOR_BLACK);
    attrset (A_BOLD|COLOR_PAIR(3));
    mvaddstr (5, 15, g_f_char);
    init_pair (5, COLOR_BLUE, COLOR_BLACK);
    attrset (A_BOLD|COLOR_PAIR(5));
    mvaddstr (8, 15, un_char);
    init_pair (10, COLOR_YELLOW, COLOR_BLACK);
    attrset (A_BOLD|COLOR_PAIR(10));
    mvaddstr (11, 15, inv_char);
    attrset (A_NORMAL);
    mvaddstr (14,15, obstacle_char);
    attrset (A_BOLD);
    mvaddstr (3, 17, "If you eat it, you will die");
    mvprintw (5, 17, "If you eat it, your body will be added one");
    mvprintw (6, 17, "and score be added %d", UNIT_SCORE);
    mvaddstr (8, 17, "If you eat it, you will be able to go through wall");
    mvaddstr (9, 17, "or body be added 4 or 5");
    mvaddstr (11, 17, "If you eat it, snake go opposite direction if");
    mvaddstr (12, 17, "you make it turn RIGHT/LEFT/UP/DOWN");
    mvaddstr (14, 17, "The wall. If you touch it, you die, except for");
    mvaddstr (15, 17, "SUPER mode");

    mvaddstr (17, 5, "Mode   :    The number in () is the time the MODE will be in");
    mvaddstr (19, 17, "SUPER   : Snkae can go through wall");
    mvaddstr (21, 17, "INVERSE : Snkae go opposite direction when");
    mvaddstr (22, 17, "          you change direction");
    attrset (A_NORMAL);
    mvaddstr (23, 5, "Press ENTER to leave...");
    while (getch()!='\n'){}
    Start_Screen ();
}
int Screen :: get_elapsed_time (void)
{
    get_time();
    if (!time_stop)
        time_show = sc_time_buf + (int)(end - start);
    if (time_stop)
    {
        start = time(NULL);
        sc_time_buf = time_show;
        return sc_time_buf;
    }
    return time_show;
}
void Screen :: show_time (void)
{
    attrset (A_REVERSE);
    mvprintw (2, 13, "%5d", get_elapsed_time());
    attrset (A_NORMAL);
}
void Screen :: get_max_x_y (void)
{
    getmaxyx (stdscr, height, width);
}
void Screen :: show_mode (int super, int su,bool debug, int time_to_map, bool debug_map,bool inverse, int db)
{
    attrset (A_REVERSE);
    if (debug)
        mvaddstr (1, width - 12, "Debug       ");
    else if (inverse)
        mvprintw (1, width - 12, "Inverse (%2d)", db);
    else if (super)
        mvprintw (1, width - 12, "Super   (%2d)", su);
    else
        mvaddstr (1, width - 12, "Normal      ");
    if (debug)
    {
        if (time_to_map >= time_show)
            mvprintw (2, width - 13, "!!%2d!!",  time_to_map - time_show);
        else
            mvprintw (2, width - 13, "      ");
    }
    attrset (A_NORMAL);
    move (height - 1, width - 1);
}
void Screen :: show_body (int body, int add_time,bool debug)
{
    attrset (A_REVERSE);
    if (!debug)
        mvprintw (1, width/2 -11, "Body  :    %4d(%2d) ", body, add_time - time_show);
    else
        mvprintw (1, width/2 -11, "Body  :    %4d     ",body);
    attrset (A_NORMAL);
    move (height - 1, width - 1);
}
void Screen :: show_speed (double speed, int add_time,bool debug,double tmp_speed)
{
    attrset (A_REVERSE);
    if (!debug)
        if (speed == 0)
            mvprintw (2, width/2 -11, "Speed : %.5lf(%2d)", tmp_speed, add_time - time_show);
        else
            mvprintw (2, width/2 -11, "Speed : %.5lf(%2d)", speed, add_time - time_show);
    else
        mvprintw (2, width/2 -11, "Speed : DEBUG      ");
    attrset (A_NORMAL);
    move (height - 1, width - 1);
}
