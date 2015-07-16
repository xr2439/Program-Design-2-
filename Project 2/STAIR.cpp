#include "header.h"
#include "STAIR.h"

STAIR* getSTAIR (QWidget* main)
{
    /* 隨機產生階梯 並傳回ptr */

    STAIR * ptr;
    for (int i = 0; i < rand()%10; i++);
    int STAIR_type = (rand() )%STAIR_NUM;
    STAIR_type %= 6;
    if (STAIR_type == 0)
       ptr = new Stair_Normal(main);
    if (STAIR_type == 1)
        ptr = new Stair_Right(main);
    if (STAIR_type == 2)
        ptr = new Stair_Left(main);
    if (STAIR_type == 3)
        ptr = new Stair_Spike(main);
    if (STAIR_type == 4)
     ptr = new Stair_Turn(main);
    if (STAIR_type == 5)
        ptr = new Stair_Spring(main);

    ptr->move (GAME_START_X+ptr->position, GAME_START_Y + GAME_HEIGHT - 1);
    ptr->resize (STAIR_X,1);
    ptr->show();
    return ptr;
}

STAIR :: STAIR(QWidget *parent,int inti) : choice(inti), QWidget(parent)
{
    /* 設置樓梯出現的 x 座標 */
    position = rand()% (GAME_WIDTH-STAIR_X);
    startTimer(100);
    through = 0;
    pause = 0;
}

void STAIR :: timerEvent (QTimerEvent * event)
{
    if (pause)
        return;
    //paintEvent(NULL);
    //QMessageBox :: about ( NULL , "About Me" , "My blog is www.awuit.com." ) ;
    status++;
    if (status == choice)
        status = 0;
    update();
}
Stair_Normal :: Stair_Normal(QWidget *parent) : STAIR(parent,1)
{
    stair  = new QString(choice);
    stair_pic.push_back (QPixmap(STAIR_NORMAL_BMP));
    status = 0;
}
void Stair_Normal :: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBitmap mask= stair_pic[status].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    stair_pic[status].setMask(mask);
    if (this->pos().y() == GAME_START_Y )
        painter.drawPixmap (0, height()-STAIR_Y1, STAIR_X, STAIR_Y1, stair_pic[status]);
    else
        painter.drawPixmap (0, 0, STAIR_X, STAIR_Y1,stair_pic[status]);
}

void Stair_Normal :: dothing (int & man_x, int & man_y, int & blood, bool & on_stair, bool &  man_up, int & man_status, bool & warn, int  &warn_num)
{
    if (!on_stair)
    {
        on_stair = 1;
        if (blood !=12)
            blood++;
    }
}

Stair_Right :: Stair_Right(QWidget *parent) : STAIR(parent,4)
{

    stair  = new QString(choice);
    stair_pic.push_back (QPixmap(STAIR_RIGHT1_BMP));
    stair_pic.push_back (QPixmap(STAIR_RIGHT2_BMP));
    stair_pic.push_back (QPixmap(STAIR_RIGHT3_BMP));
    stair_pic.push_back (QPixmap(STAIR_RIGHT4_BMP));
    status = 0;

}
void Stair_Right :: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBitmap mask= stair_pic[status].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    stair_pic[status].setMask(mask);
    if (this->pos().y() == GAME_START_Y )
        painter.drawPixmap (0, height()-STAIR_Y1, STAIR_X, STAIR_Y1, stair_pic[status]);
    else
        painter.drawPixmap (0, 0, STAIR_X, STAIR_Y1, stair_pic[status]);
}

void Stair_Right :: dothing (int & man_x, int & man_y, int & blood, bool & on_stair, bool &  man_up, int & man_status, bool & warn, int  &warn_num)
{
    if (!on_stair)
    {
        on_stair = 1;
        if (blood !=12)
            blood++;
    }
    man_x ++;
    if (man_x > GAME_WIDTH - MAN_WIDTH)
        man_x = GAME_WIDTH - MAN_WIDTH;
}

Stair_Left :: Stair_Left(QWidget *parent) : STAIR(parent,4)
{
    stair  = new QString(choice);
    stair_pic.push_back (QPixmap(STAIR_LEFT1_BMP));
    stair_pic.push_back (QPixmap(STAIR_LEFT2_BMP));
    stair_pic.push_back (QPixmap(STAIR_LEFT3_BMP));
    stair_pic.push_back (QPixmap(STAIR_LEFT4_BMP));
    status = 0;
}
void Stair_Left :: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBitmap mask= stair_pic[status].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    stair_pic[status].setMask(mask);
    if (this->pos().y() == GAME_START_Y )
        painter.drawPixmap (0, height()-STAIR_Y1, STAIR_X, STAIR_Y1, stair_pic[status]);
    else
        painter.drawPixmap (0, 0, STAIR_X, STAIR_Y1, stair_pic[status]);
}

void Stair_Left :: dothing (int & man_x, int & man_y, int & blood, bool & on_stair, bool &  man_up, int & man_status, bool & warn, int  &warn_num)
{
    if (!on_stair)
    {
        on_stair = 1;
        if (blood !=12)
            blood++;
    }
    man_x --;
    if (man_x < 0)
        man_x = 0;
}

Stair_Spike :: Stair_Spike(QWidget *parent) : STAIR(parent,1)
{

    stair  = new QString(choice);
    stair_pic.push_back (QPixmap(STAIR_SPIKE_DOWN_BMP));
    status = 0;

}
void Stair_Spike :: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBitmap mask= stair_pic[status].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    stair_pic[status].setMask(mask);
    if (this->pos().y() == GAME_START_Y )
        painter.drawPixmap (0, height()-STAIR_Y1, STAIR_X, STAIR_Y1, stair_pic[status]);
    else
        painter.drawPixmap (0, 0, STAIR_X, STAIR_Y1, stair_pic[status]);
}

void Stair_Spike :: dothing (int & man_x, int & man_y, int & blood, bool & on_stair, bool &  man_up, int & man_status, bool & warn, int  &warn_num)
{
    if (!on_stair)
    {
        warn = 1;
        warn_num = 0;
        //man_status+=21;
        on_stair = 1;
        if (blood !=0)
            blood-=5;
        if (blood < 0)
            blood = 0;
    }
}

Stair_Turn :: Stair_Turn(QWidget *parent) : STAIR(parent,6)
{
    change_to_through = 0;
    stand_time = 0;
    stair  = new QString(choice);
    stair_pic.push_back (QPixmap(STAIR_ONETIME1_BMP));
    stair_pic.push_back (QPixmap(STAIR_ONETIME2_BMP));
    stair_pic.push_back (QPixmap(STAIR_ONETIME3_BMP));
    stair_pic.push_back (QPixmap(STAIR_ONETIME4_BMP));
    stair_pic.push_back (QPixmap(STAIR_ONETIME5_BMP));
    stair_pic.push_back (QPixmap(STAIR_ONETIME6_BMP));
    stair_height.push_back (16);
    stair_height.push_back (30);
    stair_height.push_back (36);
    stair_height.push_back (32);
    stair_height.push_back (36);
    stair_height.push_back (30);
    status = 0;

}
void Stair_Turn :: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBitmap mask= stair_pic[status].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    stair_pic[status].setMask(mask);
    if (this->pos().y() != GAME_START_Y && this->pos().y()- (GAME_START_Y + GAME_HEIGHT - STAIR_Y1) <=0 )
        resize (STAIR_X, stair_height[status]);
    if (this->pos().y() == GAME_START_Y )
        painter.drawPixmap (0, height()-stair_height[status], STAIR_X, stair_height[status], stair_pic[status]);
    else
        painter.drawPixmap (0, 0,STAIR_X,stair_height[status],stair_pic[status]);
}
void Stair_Turn :: timerEvent(QTimerEvent *)
{
    if (pause)
        return;
        if (status != 0)
    {
 status++;
        if (status >= choice)
            through = 0,status = 0;
    }
}
void Stair_Turn :: dothing (int & man_x, int & man_y, int & blood, bool & on_stair, bool &  man_up, int & man_status, bool & warn, int  &warn_num)
{
    change_to_through++;
    if (change_to_through == 10)
        through = 1;
    if (!on_stair)
    {
        on_stair = 1;
        if (blood !=12)
            blood++;
        status++;
        if (status >= choice)
            status = 0;
    }

}


Stair_Spring :: Stair_Spring(QWidget *parent) : STAIR(parent,4)
{
    pre_pos_y  = 0;
    stair  = new QString(choice);
    stair_pic.push_back (QPixmap(STAIR_SPRING1_BMP));
    stair_pic.push_back (QPixmap(STAIR_SPRING2_BMP));
    stair_pic.push_back (QPixmap(STAIR_SPRING3_BMP));
    stair_pic.push_back (QPixmap(STAIR_SPRING4_BMP));
    stair_height.push_back (16);
    stair_height.push_back (18);
    stair_height.push_back (20);
    stair_height.push_back (22);
    status = 0;
    normal = 1;
}
void Stair_Spring :: paintEvent(QPaintEvent *)
{
  //  status = 0;
    QPainter painter(this);
    QBitmap mask= stair_pic[status].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    stair_pic[status].setMask(mask);
    if (this->pos().y() == GAME_START_Y )
        painter.drawPixmap (0, height()-stair_height[status], STAIR_X, stair_height[status], stair_pic[status]);
    else
        painter.drawPixmap (0, 0,STAIR_X,stair_height[status],stair_pic[status]);
    if (status == 0 && normal)
    {
        pos_y = pos().y();
        pre_pos_y = pos_y;
    }
}

void Stair_Spring :: dothing (int & man_x, int & man_y, int & blood, bool & on_stair, bool &  man_up, int & man_status, bool & warn, int  &warn_num)
{
    if (!on_stair)
    {
       on_stair = 0;
        man_up = 1;
        if (blood !=12)
            blood++;
//        status++;
        if (status >= choice)
            status = 0;
   }
}

void Stair_Spring :: timerEvent (QTimerEvent * e)
{
    if (pause)
        return;
    killTimer(e->timerId());
    startTimer(25);
        if (status != 0)
    {
        normal = 0;
           status_pre = status,status++;
        if (status >= choice)
            status = 0;
    }
}

Stair_Sharp :: Stair_Sharp(QWidget* parent) : QWidget (parent) {};
void Stair_Sharp :: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap Sharp(SHARP_BMP);
    QBitmap mask= Sharp.createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    Sharp.setMask(mask);
    painter.drawTiledPixmap (0, 0, GAME_WIDTH, SHARP_Y,Sharp);
}
