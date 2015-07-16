#ifndef MY_GAME_H
#define MY_GAME_H
/*---------------------------------------------*/
#include "header.h"
#include "STAIR.h"
#include "MyMan.h"

using namespace std;
//class STAIR;
class QLabel;
class MyGame : public QMainWindow
{
    Q_OBJECT

    public:
    MyGame (QWidget *parent = 0);
    void operator ++( int );
    void Update ();
    int spike_up_x;
    int spike_up_y;
    int step_num;
    public slots:
    void NewGame();
    void SetPause();
    void addspeed ();
    void SetBlack();
    protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void timerEvent (QTimerEvent *);
    void keyReleaseEvent (QKeyEvent *);

    private:
    STAIR * Find_Stair (int& x, int &y);
    bool Check_Man_x();
    bool Check_Man_y();
    bool warn;
    bool Move_Man();
    bool Bump_Stair();
    bool Drop_TouchStair();
    void Show_Man();
    bool Man_Through();
    bool Man_Up();
    void Chech_Man_Status();
    void Change_Status(int);
    int pre_x, pre_y;
    bool right;
    bool black;
    QMenu *gameMenu;
    QMenu *helpMenu;
    QAction *quitAction;
    int man_x;//,* man_y;
    int man_y;
    int timeid;
    Stair_Turn* turn_id;
    int  game_start_x, game_start_y;
    int  win_width, win_height;
    int game_width, game_height;
    double  for_num;
    int *status;
    bool stand;
   // double speed;
   // time_t start_t;
    int first;
   // double deg;
  //  int action;
    int flag;
    int time_num;
    //bool test;
    int key_press;
    bool bump_stair;
    bool on_stair;
    int blood;
    MyMan * man;
    bool GameOver;
    bool pause;
    int step;
    //int turn_drop;
    int stand_timer;
    double stand_timer_timer;
    Stair_Sharp * sharp;
    double stand_for_num;
    vector <QPixmap> HP;
    vector <STAIR *> stair;
    vector <QPixmap> man_pic;
    vector <QPixmap> num;
};


/*---------------------------------------------*/
#endif // MY_GAME_H
