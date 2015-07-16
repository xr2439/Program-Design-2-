#include "header.h"
#include "SM.h"
#include "Screen.h"

//OK

int main ()
{
    while (1)
    {
        int ch;
        int g_f_num = GREEN_FOOD_NUM;
        int r_f_num = RED_FOOD_NUM;
        int un_num = UNKNOW_NUM;
        int inv_num = INVERSE_NUM;
        double tmp_speed;
        double time_add_tmp;
        bool pasue = 0;
        vector <char> buf;                    // record char keyboard enter when stop
        vector <char> cmp1;                   // using to compare to if the password is right
        vector <char> cmp2;
        char t[9] = {' ','7','4','0','2','4','0','6','2'};  // the password
        for (int i = 0; i < 9; i++)                         // complish the vector to compare password
        {
            if ( i == 0)
                cmp1.push_back('f'), cmp2.push_back('F');
            else
                cmp1.push_back(t[i]), cmp2.push_back(t[i]);
        }
        Screen s;
        Map m;
        Snake ss;

        s.Start_Screen ();
        m.set_obstacle ();
        m.show_obstacle();
        while ( ss.get_go_on() )
        {
            ch = getch();
            if (!pasue)
                if (ss.get_inverse())
                {
                    if ( ss.get_direction() < 2)
                    {
                        if ( ch == KEY_DOWN)
                            if ( ss.get_direction() == 0 )
                                ss.turn (0, 2);
                        if ( ch == KEY_UP)
                            if ( ss.get_direction() == 1 )
                                ss.turn (1, 2);
                        if ( ch == KEY_LEFT )
                            ss.turn (3, 1);
                        if ( ch == KEY_RIGHT )
                            ss.turn (2, 1);
                    }
                    if ( ss.get_direction() > 1)
                    {
                        if ( ch == KEY_LEFT )
                            if ( ss.get_direction() == 3 )
                                ss.turn (3, 2);
                        if ( ch == KEY_RIGHT )
                            if ( ss.get_direction() == 2 )
                                ss.turn (2, 2);
                        if ( ch == KEY_DOWN)
                            ss.turn (0, 1);
                        if ( ch == KEY_UP)
                            ss.turn (1, 1);
                    }
                }
                else
                {
                    if ( ss.get_direction() < 2)
                    {
                        if ( ch == KEY_UP)
                            if ( ss.get_direction() == 0 )
                                ss.turn (0, 2);
                        if ( ch == KEY_DOWN)
                            if ( ss.get_direction() == 1 )
                                ss.turn (1, 2);
                        if ( ch == KEY_RIGHT )
                            ss.turn (3, 1);
                        if ( ch == KEY_LEFT )
                            ss.turn (2, 1);
                    }
                    if ( ss.get_direction() > 1)
                    {
                        if ( ch == KEY_RIGHT )
                            if ( ss.get_direction() == 3 )
                                ss.turn (3, 2);
                        if ( ch == KEY_LEFT )
                            if ( ss.get_direction() == 2 )
                                ss.turn (2, 2);
                        if ( ch == KEY_UP)
                            ss.turn (0, 1);
                        if ( ch == KEY_DOWN)
                            ss.turn (1, 1);
                    }
                }

            if ( ch == 'p' || ch == 'P')
            {
                if (!pasue)
                    pasue = 1;
                else
                    buf.clear() ,pasue = 0;
                if (ss.speed != 0)
                {
                    tmp_speed = ss.speed;
                    ss.speed = 0;
                }
                else
                    ss.speed = tmp_speed;
                if (s.time_stop)
                    s.time_stop = 0;
                else
                    s.time_stop = 1;
                if ( ss.time_add != 0 )
                    time_add_tmp = ss.time_add, ss.time_add = 0;
                else
                    ss.time_add = time_add_tmp;
            }
            if (pasue)                                                      // if stop, to compare if the words are right
            {
                if (ch == 'f' || ch == 'F' || ( ch <= '9' && ch >= '0'))
                    buf.push_back (ch);                                     // only record some words
                if (buf == cmp1 || buf == cmp2)
                {
                    buf.clear();
                    if (!ss.debug)                                          // if not in debug mode, then go in
                        ss.debug = 1, ss.set_super (-1, s.time_show);       // open debug and set super time be -1 to be inf
                    inv_num = r_f_num = 0;
                }
            }
                                            // key use to debug
            //if ( ch == '\n')
            //	ss.eat(m);
            //if ( ch == '+')
            //	g_f_num++;
            //if ( ch == '*')
            //	g_f_num*=2;
            //if ( ch == 'a')
            //	r_f_num--;
            //if ( ch == 's')
            //	r_f_num++;
            //if ( ch == 'z')
            //	ss.speed -= 0.00001;
            //if ( ch == 'x')
            //	ss.speed += 0.00001;

            if ( (int)m.g_x.size() < g_f_num )      // if food less then some num, then set it
                m.set_green_food(ss);
            if ( (int)m.r_x.size() < r_f_num )
                m.set_red_food (ss, s.time_show);
            if ( (int)m.u_x.size() < un_num )
                m.set_unknow (ss, s.time_show);
            if ( (int)m.i_x.size() < inv_num )
                m.set_inverse (ss, s.time_show);

            s.show_time();
            s.show_score();
            s.show_body (ss.get_body(),ss.get_time_to_add_long(), ss.get_debug());
            s.show_speed (ss.get_speed(),ss.get_time_to_add_long(),ss.get_debug(),tmp_speed);

            s.show_mode (ss.get_super(), ss.get_su_time(), ss.get_debug(),ss.get_time_to_map(),ss.get_debug_map(),ss.get_inverse(),ss.get_inv_time());
            m.show_green_food(ss.get_debug_map());
            m.show_red_food(s.time_show);
            m.show_unknow(s.time_show);
            m.show_inverse(s.time_show);

            ss.show_run_snake(m);

            ss.check_snake(m, ss, s.time_show);

            s.change_score (ss.num, UNIT_SCORE);            // the first is the number of unit score to be added, and the last is unit score
            ss.num = 0;                             // clear num
            ss.readin_score (s.score);

        }
    }
    getch();
    endwin();
    return 0;
}





