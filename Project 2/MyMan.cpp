#include "header.h"
#include "MyMan.h"

using namespace std;

MyMan :: MyMan (QWidget *parent) : QWidget (parent)
{

    /* ���� Tab �� �I���ƥ� */
    setFocusPolicy(Qt::StrongFocus);

    /* �]�m��l���A */
    //man_x = GAME_START_X+5;
    status = 1;
    warn = 0;
    warn_num = 0;
    blood = 5;
    man_up = 0;

pause = 0;
    /* �H���ɸ��J��vector�x�s */
    man_pic.push_back (QPixmap (MAN_STAND_BMP));
    man_pic.push_back (QPixmap (MAN_DROP1_BMP));
    man_pic.push_back (QPixmap (MAN_DROP2_BMP));
    man_pic.push_back (QPixmap (MAN_DROP3_BMP));
    man_pic.push_back (QPixmap (MAN_DROP4_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT1_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT2_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT3_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT4_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT1_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT2_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT3_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT4_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_LEFT1_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_LEFT2_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_LEFT3_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_LEFT4_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_RIGHT1_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_RIGHT2_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_RIGHT3_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_RIGHT4_BMP));
    man_pic.push_back (QPixmap (MAN_STAND_WARN_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_WARN1_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_WARN2_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_WARN3_BMP));
    man_pic.push_back (QPixmap (MAN_DROP_WARN4_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT_WARN1_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT_WARN2_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT_WARN3_BMP));
    man_pic.push_back (QPixmap (MAN_LEFT_WARN4_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT_WARN1_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT_WARN2_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT_WARN3_BMP));
    man_pic.push_back (QPixmap (MAN_RIGHT_WARN4_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_LEFT_WARN1_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_LEFT_WARN2_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_LEFT_WARN3_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_LEFT_WARN4_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_RIGHT_WARN1_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_RIGHT_WARN2_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_RIGHT_WARN3_BMP));
    man_pic.push_back (QPixmap ( MAN_DROP_RIGHT_WARN4_BMP));
    startTimer(100);

}

void MyMan :: paintEvent (QPaintEvent *event)
{
    // �إ�QPainter
    /* �إ� QPainter */
    QPainter painter(this);

    /* TEST */
    if (status == 42)
        status = 0;


    /*  �e�X���T���A���H PS �H���M�� status�ܼ� �w�M�w���J��� */
    //status = 21;
    QBitmap mask= man_pic[status].createMaskFromColor(QColor(254,255,0),Qt::MaskInColor);
    man_pic[status].setMask(mask);
    painter.drawPixmap (0, 0, man_pic[status]);
}

void MyMan :: timerEvent (QTimerEvent *)
{
    if (pause)
        return;
    if (warn)
        // �I��]�n�N�޳N�k�s
        warn_num++;
    if (warn_num == 2)
        warn = 0, warn_num = 0;
    if (st == 0 || st == 21)
        status = st;
    if (status!=0 && status != 21)
        status++;
    if (status < st || status > st +3 )
        status = st;
  //  if (status!=0)
  //      if (status > )
   // if (status == 42)
     //   status = 0;
    //status = 1;
}
