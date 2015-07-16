#ifndef SM_H
#define SM_H

//--------------------------------------------------------------------------------------//

#include "header.h"
class Map;
class Snake;
class Map {
	friend class Snake;
	public:
	Map ();
	void set_red_food (Snake &,int);
	void set_green_food (Snake &);
	void set_unknow (Snake &,int&);
	void set_obstacle (void);
	void set_inverse (Snake &,int&);
	void show_obstacle (void);
	void show_inverse (int &);
	void show_green_food (bool);
	void show_red_food (int &);
	void show_unknow (int&);
	int width, height;

	vector <vector <int> > obstacle;
	vector <vector <int> > g_f;
	vector <vector <int> > r_f;
	vector <vector <int> > un;
	vector <vector <int> > inv;
	vector <int> o_x, o_y;
	vector <int> g_x, g_y;
	vector <int> u_x, u_y, u_t;
	vector <int> r_x, r_y, r_t;
	vector <int> i_x, i_y, i_t;

};

class Snake {
        friend class Map;
        public:

        Snake ();
        int get_body (void);
        int get_su_time(void);
        int get_direction (void);
        int get_super (void);
        int get_time_to_add_long (void);
        int get_time_to_map(void);
        int get_inv_time(void);
        int get_go_on (void);
        bool get_debug (void);
        bool get_debug_map(void);
        bool get_inverse (void);
        double get_speed (void);
        void turn (int, int);
        void eat (Map &);
        void die (void);
        void set_super (int, int);
        void set_inverse (int, int);
        void set_Snake (void);
        void show_run_snake (Map &);
        void check_snake (Map &, Snake &,int);
        void readin_score (int);

        int body;                        // BODY of snake , just use to DISP
        double speed;                    // real speed of snake, it effect snake
        double head_x, head_y;           // real position of head, not on screen one
        vector < vector <int> > s_map;   // the map record snake
        vector <int> s_x;                // use to show snake
        vector <int> s_y;
        int height, width;

        int direction;                  // 0 = up , 1 = down , 2 = left , 3 = right
        int d_x[4];                     // to decide the dir num
        int d_y[4];

        int first;
        int go_on;
        int score;
        int tmp_time_st1;               // tmp
        int tmp_time_st2;

        int super;                      // just mode
        int su_time;                    // time in super mode
        bool inverse;                   // done to there
        int inv_time;                   // time in inverse mode

        int time_to_add_long;           // if time go as it, then add long and speed

        int s_time;                     // snake's time (int) , which decide the color when super
        double st_buf;                  // use to record snake's time (real)
        double time_add;                // every while loop the amount add to snake's time

        int r;                          // 0: original snake place refresh, 1 : force directly, 2: use for loop to force

        int num;                        // num of unit score to be added

        bool debug;                     // if in debug mode
        bool debug_map;                 // if in debug map mode
        bool debug_map_done;            // if debug map has done, avoid it repeat printf debug map
        int time_to_map;                // if time meet it, then go in debug map

        vector < vector <int> > db_map1;    //  DEBUG MODE map to record char
        vector < vector <int> > db_map2;    //                    record num which decide color
};

#endif

//------------------------------------------------------------------------------------------------------//
