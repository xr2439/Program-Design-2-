#ifndef HEADER_H
#define HEADER_H

#include <ctime>
#include <QPainter>
#include <QWidget>
#include <QMenuBar>
#include <QMainWindow>
#include <QtGui>
#include <QTextCodec>
#include <vector>
#include <cstdlib>

#define INFO_BMP ":/images/info.bmp"
#define BACKGROUND_BMP ":/images/background.bmp"
#define MAN_DROP1_BMP ":/images/man_drop_1.bmp"
#define MAN_DROP2_BMP ":/images/man_drop_2.bmp"
#define MAN_DROP3_BMP ":/images/man_drop_3.bmp"
#define MAN_DROP4_BMP ":/images/man_drop_4.bmp"
#define MAN_DROP_LEFT1_BMP ":/images/man_drop_left_1.bmp"
#define MAN_DROP_LEFT2_BMP ":/images/man_drop_left_2.bmp"
#define MAN_DROP_LEFT3_BMP ":/images/man_drop_left_3.bmp"
#define MAN_DROP_LEFT4_BMP ":/images/man_drop_left_4.bmp"
#define MAN_DROP_RIGHT1_BMP ":/images/man_drop_right_1.bmp"
#define MAN_DROP_RIGHT2_BMP ":/images/man_drop_right_2.bmp"
#define MAN_DROP_RIGHT3_BMP ":/images/man_drop_right_3.bmp"
#define MAN_DROP_RIGHT4_BMP ":/images/man_drop_right_4.bmp"
#define MAN_LEFT1_BMP ":/images/man_left_1.bmp"
#define MAN_LEFT2_BMP ":/images/man_left_2.bmp"
#define MAN_LEFT3_BMP ":/images/man_left_3.bmp"
#define MAN_LEFT4_BMP ":/images/man_left_4.bmp"
#define MAN_RIGHT1_BMP ":/images/man_right_1.bmp"
#define MAN_RIGHT2_BMP ":/images/man_right_2.bmp"
#define MAN_RIGHT3_BMP ":/images/man_right_3.bmp"
#define MAN_RIGHT4_BMP ":/images/man_right_4.bmp"
#define MAN_STAND_BMP ":/images/man_stand.bmp"

#define MAN_DROP_WARN1_BMP ":/images/man_drop_warn_1.bmp"
#define MAN_DROP_WARN2_BMP ":/images/man_drop_warn_2.bmp"
#define MAN_DROP_WARN3_BMP ":/images/man_drop_warn_3.bmp"
#define MAN_DROP_WARN4_BMP ":/images/man_drop_warn_4.bmp"
#define MAN_DROP_LEFT_WARN1_BMP ":/images/man_drop_left_warn_1.bmp"
#define MAN_DROP_LEFT_WARN2_BMP ":/images/man_drop_left_warn_2.bmp"
#define MAN_DROP_LEFT_WARN3_BMP ":/images/man_drop_left_warn_3.bmp"
#define MAN_DROP_LEFT_WARN4_BMP ":/images/man_drop_left_warn_4.bmp"
#define MAN_DROP_RIGHT_WARN1_BMP ":/images/man_drop_right_warn_1.bmp"
#define MAN_DROP_RIGHT_WARN2_BMP ":/images/man_drop_right_warn_2.bmp"
#define MAN_DROP_RIGHT_WARN3_BMP ":/images/man_drop_right_warn_3.bmp"
#define MAN_DROP_RIGHT_WARN4_BMP ":/images/man_drop_right_warn_4.bmp"
#define MAN_LEFT_WARN1_BMP ":/images/man_left_warn_1.bmp"
#define MAN_LEFT_WARN2_BMP ":/images/man_left_warn_2.bmp"
#define MAN_LEFT_WARN3_BMP ":/images/man_left_warn_3.bmp"
#define MAN_LEFT_WARN4_BMP ":/images/man_left_warn_4.bmp"
#define MAN_RIGHT_WARN1_BMP ":/images/man_right_warn_1.bmp"
#define MAN_RIGHT_WARN2_BMP ":/images/man_right_warn_2.bmp"
#define MAN_RIGHT_WARN3_BMP ":/images/man_right_warn_3.bmp"
#define MAN_RIGHT_WARN4_BMP ":/images/man_right_warn_4.bmp"
#define MAN_STAND_WARN_BMP ":/images/man_stand_warn.bmp"

#define SHARP_BMP ":/images/sharp.bmp"
#define SIDE_BMP ":/images/side.bmp"
#define STAIR_NORMAL_BMP ":/images/stair_normal.bmp"
#define STAIR_LEFT1_BMP ":/images/stair_left_1.bmp"
#define STAIR_LEFT2_BMP ":/images/stair_left_2.bmp"
#define STAIR_LEFT3_BMP ":/images/stair_left_3.bmp"
#define STAIR_LEFT4_BMP ":/images/stair_left_4.bmp"
#define STAIR_RIGHT1_BMP ":/images/stair_right_1.bmp"
#define STAIR_RIGHT2_BMP ":/images/stair_right_2.bmp"
#define STAIR_RIGHT3_BMP ":/images/stair_right_3.bmp"
#define STAIR_RIGHT4_BMP ":/images/stair_right_4.bmp"
#define STAIR_SPRING1_BMP ":/images/stair_spring_1.bmp"
#define STAIR_SPRING2_BMP ":/images/stair_spring_2.bmp"
#define STAIR_SPRING3_BMP ":/images/stair_spring_3.bmp"
#define STAIR_SPRING4_BMP ":/images/stair_spring_4.bmp"
#define STAIR_ONETIME1_BMP ":/images/stair_onetime_1.bmp"
#define STAIR_ONETIME2_BMP ":/images/stair_onetime_2.bmp"
#define STAIR_ONETIME3_BMP ":/images/stair_onetime_3.bmp"
#define STAIR_ONETIME4_BMP ":/images/stair_onetime_4.bmp"
#define STAIR_ONETIME5_BMP ":/images/stair_onetime_5.bmp"
#define STAIR_ONETIME6_BMP ":/images/stair_onetime_6.bmp"
#define STAIR_SPIKE_UP_BMP ":/images/stair_spiked_up.bmp"
#define STAIR_SPIKE_DOWN_BMP ":/images/stair_spiked_down.bmp"
#define HP0_BMP ":/images/HP0.bmp"
#define HP1_BMP ":/images/HP1.bmp"
#define HP2_BMP ":/images/HP2.bmp"
#define HP3_BMP ":/images/HP3.bmp"
#define HP4_BMP ":/images/HP4.bmp"
#define HP5_BMP ":/images/HP5.bmp"
#define HP6_BMP ":/images/HP6.bmp"
#define HP7_BMP ":/images/HP7.bmp"
#define HP8_BMP ":/images/HP8.bmp"
#define HP9_BMP ":/images/HP9.bmp"
#define HP10_BMP ":/images/HP10.bmp"
#define HP11_BMP ":/images/HP11.bmp"
#define HP12_BMP ":/images/HP12.bmp"
#define LIFE_BMP ":/images/LIFE.bmp"
#define n1_BMP ":/images/1.bmp"
#define n2_BMP ":/images/2.bmp"
#define n3_BMP ":/images/3.bmp"
#define n4_BMP ":/images/4.bmp"
#define n5_BMP ":/images/5.bmp"
#define n6_BMP ":/images/6.bmp"
#define n7_BMP ":/images/7.bmp"
#define n8_BMP ":/images/8.bmp"
#define n9_BMP ":/images/9.bmp"
#define n0_BMP ":/images/0.bmp"
#define BASEMENT_BMP ":/images/BASEMENT.bmp"
#define FLOOR_BMP ":/images/FLOOR.bmp"
#define GAMEOVER_BMP ":/images/GAMEOVER.bmp"
//#define WIN_WIDTH 640
#define WIN_HEIGHT 448
#define WIN_WIDTH 480
#define GAME_WIDTH 416
#define GAME_HEIGHT 376
#define GAME_START_X 28
#define GAME_START_Y 64
#define MAN_WIDTH 32
#define MAN_HEIGHT 32
#define BACKGROUND_WIDTH 128
#define BACKGROUND_HEIGHT 128
#define SIDE_X 16
#define SIDE_Y 128
#define STAIR_Y1 16
#define STAIR_X 96
#define SHARP_X 384
#define SHARP_Y 16
#define HP_X 96
#define HP_Y 16
#define STAIR_Y2 32
#define BLOOD 40
#define SPEED 1
#define G 10
#define STATUS_NUM 13
#define STATUS_LEFT_BEGIN 5
#define STATUS_LEFT_END 8
#define STATUS_RIGHT_BEGIN 9
#define STATUS_RIGHT_END 12
#define STAIR_NUM 6

#endif // HEADER_H
