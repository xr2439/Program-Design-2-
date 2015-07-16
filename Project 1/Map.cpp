#include "SM.h"

//OK

Map :: Map ()
{
    getmaxyx (stdscr, height, width);
    obstacle.resize (height);
    g_f.resize (height);
    r_f.resize (height);
    un.resize (height);
    inv.resize (height);
    for (int i = 0; i < height; i++)
    {
        obstacle[i].resize (width);
        g_f[i].resize (width);
        r_f[i].resize (width);
        un[i].resize (width);
        inv[i].resize (width);
    }
}
void Map :: set_red_food (Snake & s,int c_time)
{
    int show_time;
    int stop, x, y;
    srand(time(NULL));
    while (1)
    {
        stop = 1;
        show_time = rand() % RED_FOOD_SHOW_TIME + 1 + c_time;
        x = rand()%width;
        y = 3 + rand()%(height-3);
        int s_size = s.s_x.size();
        for (int i = 0; i < s_size ; i++)
            if ( x == s.s_x[i] && y == s.s_y[i] )
                stop = 0;
        int o_size = o_x.size();
        for (int i = 0; i < o_size ; i++)
            if ( x == o_x[i] && y == o_y[i] )
                stop = 0;
        int r_size = r_x.size();
        for (int i = 0; i < r_size ; i++)
            if ( x == r_x[i] && y == r_y[i] )
                stop = 0;
        int g_size = g_x.size();
        for (int i = 0; i < g_size ; i++)
            if ( x == g_x[i] && y == g_y[i] )
                stop = 0;
        int u_size = u_x.size();
        for (int i = 0; i < u_size ; i++)
            if ( x == u_x[i] && y == u_y[i] )
                stop = 0;
        int i_size = i_x.size();
        for (int i = 0; i < i_size ; i++)
            if ( x == i_x[i] && y == i_y[i] )
                stop = 0;
        if (stop)
            break;
    }
    r_f[y][x] = 1;
    r_x.push_back (x);
    r_y.push_back (y);
    r_t.push_back (show_time);
}
void Map :: set_green_food (Snake & s)
{
    int stop, x, y;
    srand(time(NULL));
    while (1)
    {
        stop = 1;
        x = rand()%width;
        y = 3 + rand()%(height-3);
        int s_size = s.s_x.size();
        for (int i = 0; i < s_size ; i++)
            if ( x == s.s_x[i] && y == s.s_y[i] )
                stop = 0;
        int o_size = o_x.size();
        for (int i = 0; i < o_size ; i++)
            if ( x == o_x[i] && y == o_y[i] )
                stop = 0;
        int g_size = g_x.size();
        for (int i = 0; i < g_size ; i++)
            if ( x == g_x[i] && y == g_y[i] )
                stop = 0;
        int r_size = r_x.size();
        for (int i = 0; i < r_size ; i++)
            if ( x == r_x[i] && y == r_y[i] )
                stop = 0;
        int u_size = u_x.size();
        for (int i = 0; i < u_size ; i++)
            if ( x == u_x[i] && y == u_y[i] )
                stop = 0;
        int i_size = i_x.size();
        for (int i = 0; i < i_size ; i++)
            if ( x == i_x[i] && y == i_y[i] )
                stop = 0;
        if (stop)
            break;
    }
    g_f[y][x] = 1;
    g_x.push_back (x);
    g_y.push_back (y);
}
void Map :: set_unknow (Snake & s,int & c_time)
{
    int show_time;
    int stop, x, y;
    srand(time(NULL));
    while (1)
    {
        stop = 1;
        show_time = rand() % UNKNOW_SHOW_TIME + 1 + c_time;    // must +1 otherwise it may fail wheen rand()%SHOW_TIME == 0
        x = rand()%width;
        y = 3 + rand()%(height-3);
        int s_size = s.s_x.size();
        for (int i = 0; i < s_size ; i++)
            if ( x == s.s_x[i] && y == s.s_y[i] )
                stop = 0;
        int o_size = o_x.size();
        for (int i = 0; i < o_size ; i++)
            if ( x == o_x[i] && y == o_y[i] )
                stop = 0;
        int r_size = r_x.size();
        for (int i = 0; i < r_size ; i++)
            if ( x == r_x[i] && y == r_y[i] )
                stop = 0;
        int g_size = g_x.size();
        for (int i = 0; i < g_size ; i++)
            if ( x == g_x[i] && y == g_y[i] )
                stop = 0;
        int u_size = u_x.size();
        for (int i = 0; i < u_size ; i++)
            if ( x == u_x[i] && y == u_y[i] )
                stop = 0;
        int i_size = i_x.size();
        for (int i = 0; i < i_size ; i++)
            if ( x == i_x[i] && y == i_y[i] )
                stop = 0;
        if (stop)
            break;
    }
    un[y][x] = 1;
    u_x.push_back (x);
    u_y.push_back (y);
    u_t.push_back (show_time);
}
void Map ::  set_obstacle (void)
{
    for (int i = 0; i < width/3; i++)
    {
        obstacle[3+2*height/3][i] = 1;
        o_x.push_back(i);
        o_y.push_back(3+2*height/3);
        obstacle[3+height/3][width-1-i] = 1;
        o_x.push_back(width-1-i);
        o_y.push_back(3+height/3);
    }
    for (int i = 0; i < height/3; i++)
    {
        obstacle[3+i][width/3] = 1;
        o_x.push_back(width/3);
        o_y.push_back(3+i);
        obstacle[height-1-i][2*width/3] = 1;
        o_x.push_back(2*width/3);
        o_y.push_back(height-1-i);
    }
}
void Map :: show_obstacle (void)
{
    for (int i = 0; i < (int)o_x.size(); i++)
        mvaddstr (o_y[i], o_x[i], obstacle_char);
    move (height - 1, width - 1);
}
void Map :: show_green_food (bool debug_map)
{
    init_pair (3, COLOR_GREEN, COLOR_BLACK);
    init_pair (9, COLOR_CYAN, COLOR_BLACK);
    if (debug_map)
        attrset (A_BOLD|COLOR_PAIR(9));
    else
        attrset (A_BOLD|COLOR_PAIR(3));
    for (int i = 0; i < (int)g_x.size(); i++)
        mvaddstr (g_y[i], g_x[i], g_f_char);
    attrset (A_NORMAL);
    move (height - 1, width - 1);
}
void Map :: show_red_food (int & c_time)
{
    for (int i = 0; i < (int)r_x.size(); i++)
        if (c_time == r_t[i])
        {
            r_f[r_y[i]][r_x[i]] = 0;
            mvaddstr (r_y[i], r_x[i], " ");
            for (int j = i; j < (int)r_x.size()-1; j++)
            {
                r_y[j] = r_y[j+1];
                r_x[j] = r_x[j+1];
                r_t[j] = r_t[j+1];
            }
            r_y.pop_back();
            r_x.pop_back();
            r_t.pop_back();
        }

    init_pair (4, COLOR_RED, COLOR_BLACK);
    attrset (A_BOLD|COLOR_PAIR(4));
    for (int i = 0; i < (int)r_x.size(); i++)
        mvaddstr (r_y[i], r_x[i], r_f_char);
    attrset (A_NORMAL);
    move (height - 1, width - 1);
}
void Map :: show_unknow (int & c_time)
{
    for (int i = 0; i < (int)u_x.size(); i++)
        if (c_time == u_t[i])
        {
            un[u_y[i]][u_x[i]] = 0;
            mvaddstr (u_y[i], u_x[i], " ");
            for (int j = i; j < (int)u_x.size()-1; j++)
            {
                u_y[j] = u_y[j+1];
                u_x[j] = u_x[j+1];
                u_t[j] = u_t[j+1];
            }
            u_y.pop_back();
            u_x.pop_back();
            u_t.pop_back();
        }

    init_pair (5, COLOR_BLUE, COLOR_BLACK);
    attrset (A_BOLD|COLOR_PAIR(5));
    for (int i = 0; i < (int)u_x.size(); i++)
        mvaddstr (u_y[i], u_x[i], un_char);
    attrset (A_NORMAL);
    move (height - 1, width - 1);
}
void Map :: show_inverse (int & c_time)
{
    for (int i = 0; i < (int)i_x.size(); i++)
        if (c_time == i_t[i])
        {
            inv[i_y[i]][i_x[i]] = 0;
            mvaddstr (i_y[i], i_x[i], " ");
            for (int j = i; j < (int)i_x.size()-1; j++)
            {
                i_y[j] = i_y[j+1];
                i_x[j] = i_x[j+1];
                i_t[j] = i_t[j+1];
            }
            i_y.pop_back();
            i_x.pop_back();
            i_t.pop_back();
        }

    init_pair (10, COLOR_YELLOW, COLOR_BLACK);
    attrset (A_BOLD|COLOR_PAIR(10));
    for (int i = 0; i < (int)i_x.size(); i++)
        mvaddstr (i_y[i], i_x[i], inv_char);
    attrset (A_NORMAL);
    move (height - 1, width - 1);
}
void Map :: set_inverse (Snake & s,int & c_time)
{
    int show_time;
    int stop, x, y;
    srand(time(NULL));
    while (1)
    {
        stop = 1;
        show_time = INVERSE_SHOW_TIME + c_time;
        x = rand()%width;
        y = 3 + rand()%(height-3);
        int s_size = s.s_x.size();
        for (int i = 0; i < s_size ; i++)
            if ( x == s.s_x[i] && y == s.s_y[i] )
                stop = 0;
        int o_size = o_x.size();
        for (int i = 0; i < o_size ; i++)
            if ( x == o_x[i] && y == o_y[i] )
                stop = 0;
        int r_size = r_x.size();
        for (int i = 0; i < r_size ; i++)
            if ( x == r_x[i] && y == r_y[i] )
                stop = 0;
        int g_size = g_x.size();
        for (int i = 0; i < g_size ; i++)
            if ( x == g_x[i] && y == g_y[i] )
                stop = 0;
        int u_size = u_x.size();
        for (int i = 0; i < u_size ; i++)
            if ( x == u_x[i] && y == u_y[i] )
                stop = 0;
        int i_size = i_x.size();
        for (int i = 0; i < i_size ; i++)
            if ( x == i_x[i] && y == i_y[i] )
                stop = 0;
        if (stop)
            break;
    }
    inv[y][x] = 1;
    i_x.push_back (x);
    i_y.push_back (y);
    i_t.push_back (show_time);
}
