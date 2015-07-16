#ifndef MY_MAN_H
#define MY_MAN_H
/*---------------------------------------------*/
#include "header.h"
#include "STAIR.h"

using namespace std;

//class STAIR;
class QLabel;
class MyMan : public QWidget
{
    Q_OBJECT

    public:
    MyMan (QWidget *parent = 0);
    int status;
    int blood;
    int st;
    bool warn;
    int warn_num;
    bool man_up;
    bool pause;

    protected:
    void paintEvent(QPaintEvent *);
  //  void keyPressEvent(QKeyEvent *);
   void timerEvent (QTimerEvent *);
 //   void keyReleaseEvent (QKeyEvent *);

    private:
    vector <QPixmap> man_pic;
    int pre_ststus;
};

/*---------------------------------------------*/
#endif // MY_GAME_H
