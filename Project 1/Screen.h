#include "header.h"

// OK

class Screen {
	public:
	Screen ();
	void Start_Screen (void);
	void Exit_win (void);
	void Show_Help (void);
	void Game_Start (void);
	void change_score (int, int);
	void show_score (void);
	void get_time (void);
	void show_time (void);
	void get_max_x_y (void);
	void show_mode (int, int, bool, int , bool,bool,int);
	void show_body (int, int, bool);
	void show_speed (double , int, bool,double);
	int get_elapsed_time (void);
	int score;
	int width;
	int height;
	int time_show;                      // use to tell outside what time it is
	time_t start;
	time_t end;
	bool time_stop;                     // determine if time should be stop
	int sc_time_buf;                    // when stop, it record the time the moment stop
};

