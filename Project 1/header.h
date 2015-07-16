#ifndef HEADER_H
#define HEADER_H

//OK

// --------------------------------------------------------------//

#include <ctime>
#include "curses.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <locale.h>

#define SUPER_TIME       30          // The TIME in SUPER for each time you go in SUPER MODE
#define INVERSE_TIME     10          // The TIME in INVERSE for each time you go in INVERSE MODE
#define INVERSE_SHOW_TIME  1          // The TIME INVERSE RAND to show on screen
#define UNKNOW_SHOW_TIME 5          // The TIME UNKNOW RAND to show on screen
#define RED_FOOD_SHOW_TIME 4        // The TIME RED FOOD RAND to show on screen
#define inv_char        "!"         // The INVERSE food char
#define TIME_TO_MAP     10          // The time to DEBUG MAP
#define ADD_SPEED       0.00001      // The SPEED be added
#define CHANGE_BODY     0           // If Change SNAKE BODY or not
#define head_of_snake_x 12          // The original PLACE of snake of head
#define head_of_snake_y 18
#define start_body      10          // The original LENGHT of snake
#define start_speed     0.0001      // The SPEED of snake
#define head_char       "%"       // The HEAD char
#define body_char       "%"         // The BODY char
#define obstacle_char   "X"         // The OBSTACLE char
#define g_f_char	    "$"         // The GREEN FOOD char
#define r_f_char	    "$"         // The RRD FOOD char
#define head_char_change "/"        // The HEAD char if CHANGE BODY
#define body_char_1	    "\\"         // The BODY char 1(ODD) if CHANGE BODY
#define body_char_2	    "/"         // The BODY char 2(EVEN) if CHANGE BODY
#define un_char		    "?"         // The UNKNOW char
#define SHOW_TIME       1          // The TIME things RAND to show on screen
#define ADD_TIME        5          // The TIME to LENGHTEN & SPEED UP
#define GREEN_FOOD_NUM  5           // The NUM OF GREEN FOOD
#define RED_FOOD_NUM    1           // The NUM OF RED FOOD
#define UNKNOW_NUM      5           // The NUM OF UNKNOW FOOD
#define INVERSE_NUM     3           // The NUM OF INVERSE FOOD
#define UNIT_SCORE      10          // The UNIT SCORE

using namespace std;

//---------------------------------------------------------------//

#endif
