#include "SM.h"
Snake :: Snake ()
{
    debug_map_done = 0;
    debug_map = 0;
    inverse = 0;
    inv_time = 0;                            // time in inverse mode
    time_to_add_long = ADD_TIME;             // if time go as it, then add long and speed
    debug = 0;
    num = 0;                                 // num of unit score which get ready to add to score
    su_time = 0;                             // time in super mode


    getmaxyx (stdscr, height, width);

    speed = start_speed;
    first = 1;                               // don't know
    super = 0;
    time_add = 0.0001;                       // every while loop the amount add to snake's time
    st_buf = 0;                              // use to record snake's time (real)
    direction = 3;                           // the direction
    d_x[0] = d_x[1] = d_y[2] = d_y[3] = 0;   // trans direction to actual move x, y unit
    d_y[1] = d_x[3] = 1;
    d_x[2] = d_y[0] = -1;
    go_on = 1;
    s_map.resize(height);
    for (int i = 0; i < height; i++)
        s_map[i].resize(width);

    //--------------------SET DEBUG MAP---------------------------------------//
    char map1[94] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                     'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
                     'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                     'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                     'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8',
                     '9', '0', '~', '`', '!', '@', '#', '$', '%', '\'',
                     '&', '*', '(', ')', '_', '-', '=', '+', '[', '\\',
                     '{', '}', ';', ':', ',', '.', '<', '>', '/', '\"',
                     ']', '^', '?', '|'
                    };
    char map2[4] = {'0','1','2','3'};
    db_map1.resize (height);
    db_map2.resize (height);
    for (int i = 0; i < height; i++)
        db_map1[i].resize(width), db_map2[i].resize(width);
    srand (time(NULL));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a = rand()%94;
            db_map1[i][j] = map1[a];
        }
    }
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            int a = rand()%4;
            db_map2[i][j] = map2[a];
        }
    //------END-----------SET DEBUG MAP---------------------------------------//

    set_Snake();
}
void Snake :: turn (int direct,int t) // make snake turn
{
    direction = direct;
    r = t;
}
void Snake :: eat (Map & m)
{
    int size = s_x.size();
    body++;
    int add_x = s_x[size-1] - s_x[size-2];      // get the vector
    int add_y = s_y[size-1] - s_y[size-2];
    int tmpx = s_x[size-1] + add_x;
    if (tmpx < 0 || tmpx > width - 1)           // if outside screen then set it to original tail
        tmpx = s_x[size-1];                     // make it not show new body now
    int tmpy = s_y[size-1] + add_y;
    if (tmpy < 3 || tmpy > height - 1)
        tmpy = s_y[size-1];
    if (s_map[tmpy][tmpx] == 1)                 // if new body touch snake's body then set it to original tail
        tmpy = s_y[size-1], tmpx = s_x[size-1]; // make it not show new body now
    if (!super)                                 // if new body touch wall and not in super mode,
        if (m.obstacle[tmpy][tmpx] == 1)        // set it to original tail make it not show new body now
            tmpy = s_y[size-1], tmpx = s_x[size-1];
    s_x.push_back ( tmpx);
    s_y.push_back ( tmpy);
    s_map[tmpy][tmpx] = 1;                      // must set 1 not to add it, because the action done above
    mvaddstr (tmpy, tmpx, body_char);
    num++;
    refresh();
}
void Snake :: die (void)
{
    refresh();
    go_on = 0;
    speed = 0;
    clear();
    int sub_y1 = height/2 - 1, sub_x1 = width/2 -5;
    int sub_y2 = height - height/4, sub_x2 = width/2 -13;
    mvprintw (5, sub_x1+1, "SCORE : %d", score);
    mvaddstr (sub_y1, sub_x1, "Game Over!");
    mvaddstr (sub_y2, sub_x2, "Press ENTER to continue...");
    init_pair (1, COLOR_YELLOW, COLOR_BLUE);
    attrset (A_BOLD|COLOR_PAIR(1));
    for (int i = 0; i <= width ; i++)
        mvaddstr (0, i, " ");
    int center_x = width/2 - 7;
    mvaddstr (0, center_x, "Sanke Game");
    mvaddstr (0, width-14, "By F74024062");
    attrset (A_NORMAL);
    while (getch() != '\n'){}
}
void Snake :: set_Snake (void)
{
    head_x = head_of_snake_x;
    head_y = head_of_snake_y;
    body = start_body;
    s_x.push_back (head_x);
    s_y.push_back (head_y);
    s_map[s_y[0]][s_x[0]] = 1;
    for (int i = 1 ; i < body ; i++)
    {
        s_x.push_back (head_x - i);
        s_y.push_back (head_y);
        s_map[s_y[i]][s_x[i]] = 1;
    }
}
void Snake :: show_run_snake (Map & m)  // wait to wirte comment
{
    srand (time(NULL));
    init_pair (7, COLOR_WHITE, COLOR_BLACK);
    init_pair (8, COLOR_GREEN, COLOR_BLACK);
    if (debug_map)
        if (!debug_map_done)
        {
            for (int i = 3; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (s_map[i][j] != 1 && m.g_f[i][j] != 1 && m.r_f[i][j] != 1 && m.un[i][j] != 1 && m.inv[i][j] != 1)
                    {

                        if (db_map2[i][j]-'0' == 1)
                            attrset (COLOR_PAIR(7));
                        if (db_map2[i][j]-'0' == 2)
                            attrset (COLOR_PAIR(8));
                        if (db_map2[i][j]-'0' == 3)
                            attrset (A_BOLD|COLOR_PAIR(8));

                        if (db_map2[i][j]-'0' == 0)
                            mvprintw (i,j, " ");
                        else
                            mvprintw (i,j, "%c", db_map1[i][j]);
                        attrset (A_NORMAL);
                    }
                }
            }
            debug_map_done = 1;
        }
    s_time = (int)st_buf;
    st_buf += time_add;
    init_pair (6, COLOR_YELLOW, COLOR_BLACK);

    if (first)
        first = 0;
    int pre_x = s_x[0], pre_y = s_y[0];

    if ( r == 1)
        while ( (int)head_x == s_x[0] && int(head_y) == s_y[0] )
            head_x += speed*d_x[direction], head_y += speed*d_y[direction];
    else if ( r == 0)
        head_x += speed*d_x[direction], head_y += speed*d_y[direction];
    else
        head_x += d_x[direction], head_y += d_y[direction];
    r = 0;
    while ( (int)head_x < 0 )	head_x = width-1;
    while ( (int)head_x > width - 1)	head_x = 0;
    while ( (int)head_y < 3 )    head_y = height-1;
    while ( (int)head_y > height-1)     head_y = 3; // do know why (int)
    if ( first == 0 && (((int)head_x) != pre_x || ((int)head_y) != pre_y ))
    {
        int tail_x = s_x[s_x.size()-1], tail_y = s_y[s_y.size()-1];
        for (int i = 0; i < (int)s_x.size(); i++)
        {
            if ( m.obstacle[s_y[i]][s_x[i]] != 1)
                mvaddstr (s_y[i], s_x[i], " ");
            if (debug_map)
            {
                if (db_map2[s_y[i]][s_x[i]]-'0' == 1)
                    attrset (COLOR_PAIR(7));
                if (db_map2[s_y[i]][s_x[i]]-'0' == 2)
                    attrset (COLOR_PAIR(8));
                if (db_map2[s_y[i]][s_x[i]]-'0' == 3)
                    attrset (A_BOLD|COLOR_PAIR(8));
                if (db_map2[s_y[i]][s_x[i]]-'0' == 0)
                    mvprintw (s_y[i],s_x[i], " ");
                else
                    mvprintw (s_y[i],s_x[i], "%c", db_map1[s_y[i]][s_x[i]]);
                attrset (A_NORMAL);
            }
            //else
            //if (super)
            //   if (s_time % 3)
            //       attrset (A_BOLD|COLOR_PAIR(6)), mvaddstr (s_y[i], s_x[i], "O"), attrset (A_NORMAL);
            //   else
            //        attrset (COLOR_PAIR(6)), mvaddstr (s_y[i], s_x[i], "O"), attrset (A_NORMAL);
            //else
            //      mvaddstr (s_y[i], s_x[i], "O");

            //else
            //  mvaddstr (s_y[i], s_x[i], " ");
            s_map[s_y[i]][s_x[i]] = 0;
        }
        for (int i = s_x.size()-1 ; i > 0; i--)
        {
            s_x[i] = s_x[i-1];
            s_y[i] = s_y[i-1];
            s_map[s_y[i]][s_x[i]] = 1;
        }
        s_x[0] = head_x;
        s_y[0] = head_y;
        s_map[s_y[0]][s_x[0]] ++;
        srand (time(NULL));
        for (int i = 0; i < (int)m.o_x.size(); i++)
        {
            if (!debug_map)
                if ( s_map[m.o_y[i]][m.o_x[i]] != 1)
                    mvaddstr (m.o_y[i], m.o_x[i], "X");
        }
        if ( s_map[s_y[0]][s_x[0]] != 1 )
        {
            for (int i = 2; i < (int)s_x.size(); i++)
            {
                if (CHANGE_BODY)
                    if ( i % 2)
                        mvaddstr (s_y[i], s_x[i], body_char_1);
                    else
                        mvaddstr (s_y[i], s_x[i], body_char_2);
                else
                    mvaddstr (s_y[i], s_x[i], body_char);
            }
            mvaddstr (s_y[1], s_x[1], head_char);
            mvaddstr (tail_y, tail_x, body_char);
            move (height - 1, width - 1);
            die();
            return;
        }
    }
    //if ( m.obstacle[s_y[0]][s_x[0]] != 1 )
    if (CHANGE_BODY)
        mvaddstr (s_y[0], s_x[0], head_char_change);
    else if (super)
        if (s_time % 2)
            attrset (A_BOLD|COLOR_PAIR(6)), mvaddstr (s_y[0], s_x[0], head_char), attrset (A_NORMAL);
        else
            attrset (COLOR_PAIR(6)), mvaddstr (s_y[0], s_x[0], head_char), attrset (A_NORMAL);
    else
        mvaddstr (s_y[0], s_x[0], head_char);
    if (debug_map)
    {
        if (db_map2[s_y[0]][s_x[0]]-'0' == 0)
            attrset (COLOR_PAIR(7));
        if (db_map2[s_y[0]][s_x[0]]-'0' == 1)
            attrset (COLOR_PAIR(8));
        if (db_map2[s_y[0]][s_x[0]]-'0' == 2)
            attrset (A_BOLD|COLOR_PAIR(8));
        if (db_map2[s_y[0]][s_x[0]]-'0' == 3)
            mvprintw (s_y[0],s_x[0], " ");
        else
            mvprintw (s_y[0],s_x[0], "%c", db_map1[s_y[0]][s_x[0]]);
        attrset (A_NORMAL);
    }
    //else
    //        mvaddstr (s_y[0], s_x[0], obstacle_char);
    for (int i = 1; i < (int)s_x.size(); i++)
    {
        if (CHANGE_BODY)
            if ( i % 2)
                mvaddstr (s_y[i], s_x[i], body_char_1);
            else
                mvaddstr (s_y[i], s_x[i], body_char_2);
        else if (super)
            if (s_time % 2 )
                attrset (A_BOLD|COLOR_PAIR(6)), mvaddstr (s_y[i], s_x[i], body_char), attrset (A_NORMAL);
            else
                attrset (COLOR_PAIR(6)), mvaddstr (s_y[i], s_x[i], body_char), attrset (A_NORMAL);
        else
            mvaddstr (s_y[i], s_x[i], body_char);
        if (debug_map)
        {
            if (db_map2[s_y[i]][s_x[i]]-'0' == 0)
                attrset (COLOR_PAIR(7));
            if (db_map2[s_y[i]][s_x[i]]-'0' == 1)
                attrset (COLOR_PAIR(8));
            if (db_map2[s_y[i]][s_x[i]]-'0' == 2)
                attrset (A_BOLD|COLOR_PAIR(8));
            if (db_map2[s_y[i]][s_x[i]]-'0' == 3)
                mvprintw (s_y[i],s_x[i], " ");
            else
                mvprintw (s_y[i],s_x[i], "%c", db_map1[s_y[i]][s_x[i]]);
            attrset (A_NORMAL);
        }
    }
}
int Snake :: get_go_on (void)
{
    return go_on;
}
int Snake :: get_super (void)
{
    return super;
}
int Snake :: get_direction (void)
{
    return direction;
}
void Snake :: check_snake (Map & m, Snake &s,int c_time)
{
    if (!super)                                 // if not in super mode, examine if snake touch wall
        if (m.obstacle[s_y[0]][s_x[0]] == 1)
            die();
    if (m.r_f[s_y[0]][s_x[0]] == 1)             // if touch red food, die
        die();
    if (m.g_f[s_y[0]][s_x[0]] == 1)             // if touch green food, call eat to longer and
    {                                           // add num to add score
        m.g_f[s_y[0]][s_x[0]] = 0;
        for (int i = 0; i < (int)m.g_x.size(); i++)
            if ( s_y[0] == m.g_y[i] && s_x[0] == m.g_x[i] )
            {
                for (int j = i; j < (int)m.g_x.size()-1; j++)
                {
                    m.g_y[j] = m.g_y[j+1];
                    m.g_x[j] = m.g_x[j+1];
                }
                m.g_y.pop_back();
                m.g_x.pop_back();
            }
        eat(m);
    }
    if (m.un[s_y[0]][s_x[0]] == 1)
    {
        m.un[s_y[0]][s_x[0]] = 0;
        for (int i = 0; i < (int)m.u_x.size(); i++)
            if ( s_y[0] == m.u_y[i] && s_x[0] == m.u_x[i] )
            {
                for (int j = i; j < (int)m.u_x.size()-1; j++)
                {
                    m.u_y[j] = m.u_y[j+1];
                    m.u_x[j] = m.u_x[j+1];
                    m.u_t[j] = m.u_t[j+1];
                }
                m.u_y.pop_back();
                m.u_x.pop_back();
                m.u_t.pop_back();
            }
        srand (time(NULL));
        int a = rand() % 3;
        if ( a == 0)
            for (int i = 0; i < 4; i++)
                eat(m);
        if ( a == 1)
            for (int i = 0; i < 5; i++)
                eat(m);
        if ( a == 2)
            set_super (SUPER_TIME, c_time);
    }
    if (m.inv[s_y[0]][s_x[0]] == 1)
    {
        m.inv[s_y[0]][s_x[0]] = 0;
        for (int i = 0; i < (int)m.i_x.size(); i++)
            if ( s_y[0] == m.i_y[i] && s_x[0] == m.i_x[i] )
            {
                set_inverse (INVERSE_TIME, c_time);
                for (int j = i; j < (int)m.u_x.size()-1; j++)
                {
                    m.i_y[j] = m.i_y[j+1];
                    m.i_x[j] = m.i_x[j+1];
                    m.i_t[j] = m.i_t[j+1];
                }
                m.i_y.pop_back();
                m.i_x.pop_back();
                m.i_t.pop_back();
            }
    }

    if (!debug)
    {
        time_to_map = TIME_TO_MAP + c_time;
        if (super < 0) super = 0;
        if (super == 0)
            tmp_time_st1 = c_time;
        else if ( c_time - tmp_time_st1 == 1)
            tmp_time_st1 = c_time, su_time--;
        if (su_time == 0)
            super = 0;
        if (time_to_add_long == c_time)
            time_to_add_long += ADD_TIME, eat(m), speed += ADD_SPEED;
    }

    if (debug)
    {
        if ( time_to_map == c_time )
            debug_map = 1;
    }

    //------set inverse------------------------------------------------//

    if (inverse == 0)
        tmp_time_st2 = c_time;
    else if ( c_time - tmp_time_st2 == 1)
        tmp_time_st2 = c_time, inv_time--;
    if (inv_time == 0)
        inverse = 0;
    //--END-set inverse------------------------------------------------//

}
void Snake :: set_super (int su, int c_time)
{
    super = 1;
    su_time = su;
}
void Snake :: set_inverse (int inv, int c_time)
{
    inverse = 1;
    inv_time = inv;
}
int Snake :: get_su_time(void)
{
    return su_time;
}
bool Snake :: get_debug (void)
{
    return debug;
}
int Snake :: get_body (void)
{
    return body;
}
int Snake :: get_time_to_add_long (void)
{
    return time_to_add_long;
}
double Snake :: get_speed (void)
{
    return speed;
}
bool Snake :: get_debug_map (void)
{
    return debug_map;
}
int Snake :: get_time_to_map (void)
{
    return time_to_map;
}
bool Snake :: get_inverse (void)
{
    return inverse;
}
int Snake :: get_inv_time (void)
{
    return inv_time;
}
void Snake :: readin_score (int score_in)
{
    score = score_in;
}
