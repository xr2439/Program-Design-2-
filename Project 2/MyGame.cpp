#include "header.h"
#include "MyGame.h"
class STAIR;
using namespace std;

STAIR * MyGame :: Find_Stair(int &x, int &y)
{
    STAIR * ptr = dynamic_cast <STAIR *> ( childAt (GAME_START_X + x + 2 , GAME_START_Y + y + MAN_HEIGHT) );
    if (ptr == NULL)
        ptr = dynamic_cast <STAIR *> ( childAt (GAME_START_X + x  + MAN_WIDTH - 2 , GAME_START_Y + y + MAN_HEIGHT) );
    return ptr;
}

bool MyGame :: Check_Man_x ()
{
    if (man_x > GAME_WIDTH - MAN_WIDTH)
    {
        man_x = GAME_WIDTH - MAN_WIDTH;
        update();
        return false;
    }
    if (man_x < 0)
    {
        man_x = 0;
        update();
        return false;
    }
    return true;
}

MyGame :: MyGame (QWidget *parent) : QMainWindow (parent)
{

    //QCoreApplication::addLibraryPath(QString("."));
    /* 設置編碼 */
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Big5-ETen"));

    /* 設Windows標題 */
    setWindowTitle(tr("小朋友下樓梯"));

    /* 接收 Tab 及 點擊事件 */
    setFocusPolicy(Qt::StrongFocus);

    /* 設置選單  PS 選單功能未完成*/
    gameMenu = new QMenu (tr("遊戲"));
//   helpMenu = new QMenu (tr("說明"));
    gameMenu->addAction(tr("開始"), this, SLOT(NewGame()), Qt::CTRL + Qt::Key_N);
    gameMenu->addAction(tr("暫停"),this,SLOT(SetPause()), Qt::Key_P);
    gameMenu->addAction(tr("背景/無背景"),this,SLOT(SetBlack()), Qt::CTRL + Qt::Key_B);
    gameMenu->addAction(tr("離開"), this, SLOT(close()), Qt::CTRL + Qt::Key_X);
    //helpMenu->addAction(tr("說明"));
    //helpMenu->addAction(tr("關於"));
    menuBar()->addMenu(gameMenu);
    //menuBar()->addMenu(helpMenu);

    /* 設置初始狀態 */
    man = NULL;
    stand_for_num = 1;
    //man_x = GAME_START_X+5;
    man_x = GAME_WIDTH/2;
    srand(time(NULL));
    man_y = 9;
    pause = 0;
    GameOver = 0;
    game_start_x = GAME_START_X;
    game_start_y = GAME_START_Y;
  //  start_t = time(NULL);
    pre_x= pos().x();
    pre_y = pos().y();
    for_num = 1;
//    speed = SPEED;
    first = 0;
    stand = 0;
    timeid = 0;
    step_num = 0;
//    status = 1;
  //  deg = 0;
    flag = 0;
    warn = 0;
    blood = 12;
    on_stair = 0;
    stand_timer = 18;
    timeid = startTimer(stand_timer);
    NewGame();
  //  turn_drop = 0;
    sharp = new Stair_Sharp (this);
    HP.push_back (QPixmap (HP0_BMP));
    HP.push_back (QPixmap (HP1_BMP));
    HP.push_back (QPixmap (HP2_BMP));
    HP.push_back (QPixmap (HP3_BMP));
    HP.push_back (QPixmap (HP4_BMP));
    HP.push_back (QPixmap (HP5_BMP));
    HP.push_back (QPixmap (HP6_BMP));
    HP.push_back (QPixmap (HP7_BMP));
    HP.push_back (QPixmap (HP8_BMP));
    HP.push_back (QPixmap (HP9_BMP));
    HP.push_back (QPixmap (HP10_BMP));
    HP.push_back (QPixmap (HP11_BMP));
    HP.push_back (QPixmap (HP12_BMP));
    num.push_back (QPixmap (n0_BMP));
    num.push_back (QPixmap (n1_BMP));
    num.push_back (QPixmap (n2_BMP));
    num.push_back (QPixmap (n3_BMP));
    num.push_back (QPixmap (n4_BMP));
    num.push_back (QPixmap (n5_BMP));
    num.push_back (QPixmap (n6_BMP));
    num.push_back (QPixmap (n7_BMP));
    num.push_back (QPixmap (n8_BMP));
    num.push_back (QPixmap (n9_BMP));
//    man_up_timer = 0;
    black = 0;
    stand_timer_timer = 0;
    turn_id  = NULL;
    right = 1;

}

void MyGame :: paintEvent (QPaintEvent *event)
{
    /* 建立 QPainter */
    QPainter painter(this);
    if (!black)
        painter.drawTiledPixmap(GAME_START_X , game_start_y , GAME_WIDTH , GAME_HEIGHT + GAME_START_Y - game_start_y, QPixmap(BACKGROUND_BMP));
    else
        painter.drawTiledPixmap(GAME_START_X , game_start_y , GAME_WIDTH , GAME_HEIGHT + GAME_START_Y - game_start_y, QPixmap(":/images/black.bmp"));
    painter.drawTiledPixmap(GAME_START_X - SIDE_X ,game_start_y , SIDE_X, GAME_HEIGHT + GAME_START_Y - game_start_y, QPixmap(SIDE_BMP));
    painter.drawTiledPixmap(GAME_START_X+GAME_WIDTH,game_start_y , SIDE_X, GAME_HEIGHT + GAME_START_Y - game_start_y, QPixmap(SIDE_BMP));

    for (int i = 0; i< stair.size(); i++)
    {
        QPixmap stair_spike_up(STAIR_SPIKE_UP_BMP);
        QBitmap mask= stair_spike_up.createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
        stair_spike_up.setMask(mask);
        if (dynamic_cast  <Stair_Spike *> (stair[i]) != NULL)
        {
            if (stair[i]->pos().y() != GAME_START_Y)
                painter.drawPixmap (stair[i]->pos().x(), stair[i]->pos().y() - STAIR_Y1, stair_spike_up);
        }
    }

    /* 將其餘部分用黑色背景覆蓋 */
    painter.drawTiledPixmap(0, 0, WIN_WIDTH, GAME_START_Y, QPixmap(INFO_BMP));
    painter.drawTiledPixmap(0, GAME_START_Y + GAME_HEIGHT, WIN_WIDTH, WIN_HEIGHT - GAME_START_Y + GAME_HEIGHT, QPixmap(INFO_BMP));
    painter.drawTiledPixmap(0, 0, GAME_START_X - SIDE_X, WIN_HEIGHT, QPixmap(INFO_BMP));
    painter.drawTiledPixmap(GAME_START_X + GAME_WIDTH + SIDE_X, 0, WIN_HEIGHT - GAME_START_X + GAME_WIDTH + SIDE_X, WIN_HEIGHT, QPixmap(INFO_BMP));


    QPixmap Life(LIFE_BMP);
    QBitmap mask= Life.createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    Life.setMask(mask);

    painter.drawPixmap (10 , GAME_START_Y - 2*HP_Y  , Life);
    if (!GameOver)
        painter.drawPixmap (GAME_START_X+40, GAME_START_Y - 2*HP_Y , HP_X, HP_Y, HP[blood]);
    QPixmap base (BASEMENT_BMP);
    mask= base.createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    base.setMask(mask);
    painter.drawPixmap (GAME_START_X+60 + 100, GAME_START_Y -2*HP_Y -5  , base);
    sharp -> resize (GAME_WIDTH, SHARP_Y);
    sharp -> move (GAME_START_X, GAME_START_Y);
    sharp->show();
    sharp->raise();


    mask= num[(step/1000)%10].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    num[(step/1000)%10].setMask(mask);
    painter.drawPixmap (GAME_START_X+60 + 100 + 72 , GAME_START_Y -2*HP_Y -5  , num[(step/1000)%10]);
    mask= num[(step/100)%10].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    num[(step/100)%10].setMask(mask);
    painter.drawPixmap (GAME_START_X+60 + 100 + 72 +32 , GAME_START_Y -2*HP_Y -5  , num[(step/100)%10]);
    mask= num[(step/10)%10].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    num[(step/10)%10].setMask(mask);
    painter.drawPixmap (GAME_START_X+60 + 100 + 72 +32 +32, GAME_START_Y -2*HP_Y -5  , num[(step/10)%10]);
    mask= num[step%10 ].createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    num[step%10].setMask(mask);
    painter.drawPixmap (GAME_START_X+60 + 100 + 72 +32 +32+ 32, GAME_START_Y -2*HP_Y -5  , num[step%10]);
    QPixmap Floor (FLOOR_BMP);
    mask= Floor.createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
    Floor.setMask(mask);
    painter.drawPixmap (GAME_START_X+60 + 100 + 72 +32 +32+ 32+32, GAME_START_Y -2*HP_Y -5  , Floor);
    if (GameOver)
    {
        man->setVisible(0);
        QPixmap GAMEover(GAMEOVER_BMP);
        QBitmap mask= GAMEover.createMaskFromColor(QColor(0,0,255),Qt::MaskInColor);
        GAMEover.setMask(mask);

        painter.drawPixmap (GAME_START_X+40, GAME_START_Y - 2*HP_Y  , GAMEover);
        //GameOver = 0;
    }
}

void MyGame :: keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left)
    {
        flag = 1;
        key_press = 1;
    }
    if(event->key() == Qt::Key_Right)
    {
        flag = 2;
        key_press = 2;
    }
}

void MyGame :: keyReleaseEvent (QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left)
    {
        if (flag == 1)
            if (event->isAutoRepeat() == false)
                key_press = 0;
    }
    if(event->key() == Qt::Key_Right)
    {
        if (flag == 2)
            if (event->isAutoRepeat() == false)
                key_press = 0;
    }
}


bool MyGame :: Bump_Stair ()
{
        STAIR * ptr = Find_Stair(man_x, man_y);
        if ( ptr!= NULL )
            if (ptr -> pos().y() < GAME_START_Y + man_y + MAN_HEIGHT)
                return true;
        return false;
}

void MyGame :: Show_Man ()
{
    man->move (GAME_START_X+ man_x, GAME_START_Y + man_y);
    man->show();
    man->raise();
}
bool MyGame :: Move_Man ()
{
    if (key_press == 1)
        man_x--;
    if (key_press == 2)
        man_x++;
    if (Bump_Stair() || !Check_Man_x ())
        return false;
    //Show_Man ();
    return true;
}

bool MyGame ::Drop_TouchStair()
{
    if (!Man_Through()) {
        if (Find_Stair(man_x, man_y) && !Bump_Stair())
        {
            for_num = 1;
            Find_Stair(man_x, man_y)->dothing(man_x, man_y, blood, on_stair, man->man_up, *(status), man->warn, man->warn_num);
            return false;
        }
    }
    for (int i = 0; i < (int) for_num ; i++) {
        man_y++;
        STAIR * ptr = Find_Stair(man_x, man_y);

        if (Bump_Stair())
            ptr = NULL;
        if (Man_Through())  /*  穿過的優先權比較高 */
            ptr = NULL;
        on_stair = 0;
        if (ptr != NULL)
        {
            //on_stair = 0;
            ptr->dothing(man_x, man_y, blood, on_stair, man->man_up, *(status), man->warn, man->warn_num);
            for_num = 1;
            return false;
        }

        //Show_Man ();
    }
    for_num+= 0.08;
    return true;
}

bool MyGame :: Man_Through()
{
    STAIR * ptr = Find_Stair(man_x, man_y);
    if (ptr!=NULL)
        if (ptr->through)
            return true;
    return false;
}

bool MyGame :: Man_Up()
{
    if (!man->man_up)
        return false;
    static int man_up_timer = 0;
    man_up_timer++;
    for_num = 3;
    //if ( ! ( man_up_timer % 2 ) )
        for (int i = 0; i < for_num; i++)
            man_y = man_y -1,Show_Man();
    for_num-=0.08;
    if (!Check_Man_y())
    {
        man_up_timer = 0;
        for_num = 1;
        man->man_up = 0;
        return false;
    }
    if (man_up_timer == 20)
    {
        man->man_up = 0;
        man_up_timer = 0;
        for_num = 1;
    }
    //Show_Man();
    return true;
}

void MyGame :: Change_Status(int tmp)
{
   // (*status)++;
   // if (*status != 0)

    man->st = tmp + man->warn*21;
    return;
    /*
   if (tmp == 0)    {
        (*status) = 0;
        return;
   }
   if (*status < tmp || *status > tmp + 3)
        (*status) = tmp;
*/
}

void MyGame :: Chech_Man_Status()
{
 //   Change_Status(9);
 //   return;
    if (key_press == 1) {
        if (Find_Stair(man_x, man_y)!=NULL && !Bump_Stair() && !Man_Through())
            Change_Status(5);
        else
            Change_Status(13);
    }
     if (key_press == 2)  {
        if (Find_Stair(man_x, man_y)!=NULL && !Bump_Stair() && !Man_Through())
            Change_Status(9);
        else
            Change_Status(17);
     }
    if (key_press == 0) {
        if (Find_Stair(man_x, man_y)!=NULL && !Bump_Stair() && !Man_Through())
            Change_Status(0);
        else
            Change_Status(1);
    }
}

bool MyGame :: Check_Man_y()
{
    if (man_y <= 8)
    {
        man->warn_num = 0,man->warn = 1,blood = (blood < 5) ? 0 : blood - 5 ,man_y = 10;
        return false;
    }
    if (man_y > GAME_START_Y + GAME_HEIGHT)
    {
        man_y = GAME_START_Y + GAME_HEIGHT,blood = 0;
        return false;
    }
    return true;
}

void MyGame :: timerEvent (QTimerEvent * event)
{
    /* IF GAMEOVER SKIP ALL */
    if (!GameOver)   {
        //return;

    /* IF PAUSE SKIP ALL */
    if (pause)
    {
        update();
        return;
        //return;
    }
    Chech_Man_Status();

    /* MAKE MAN MOVE */
    for (int i = 0; i < 3 ; i++)
        if (!Move_Man())
            break;

    /* MAKE MAN DROP AND DO THINGS IF TOUCH STAIR */
    if (!Man_Up())
        if (!Drop_TouchStair())
            man_y--, Show_Man ();


    Show_Man();
    Check_Man_y();
    if (blood == 0)
        GameOver = 1;
    //GameOver = 0;
    addspeed ();
    }
    Update();
    update();

}
void MyGame :: Update ()
{

    /* 使背景移動 */
    game_start_y -- ;
    if (GAME_START_Y - game_start_y == BACKGROUND_HEIGHT)
        game_start_y = GAME_START_Y;

    /* 若樓梯高度為0 刪除它 */
    if (stair.size() != 0)
        if (stair[0]->height() == 0)  {
            delete stair[0], stair.erase(stair.begin());
        step_num++;
        if (!GameOver)
            if (step_num == 7)
                step_num = 0, (*this)++;
        }
    /* 若樓梯數為零則產生一個樓梯 */
    if (stair.size() == 0)
        stair.push_back(getSTAIR(this));

    /* 樓梯在底下高度不夠時則增加其高度*/
    if (stair.size() != 0)  {
        if (stair[stair.size()-1]->pos().y() - (GAME_START_Y + GAME_HEIGHT - STAIR_Y1) > 0 )
            stair[stair.size()-1]->resize (STAIR_X, stair[stair.size()-1]->height()+1);
    }

    /* 樓梯跑到一定高度後生產新樓梯 */
    if (stair.size() != 0)  {
        if (stair[stair.size()-1]->pos().y() - (GAME_START_Y + GAME_HEIGHT ) < -32-16 )
            stair.push_back(getSTAIR(this));
    }

    /* 移動樓梯  若樓梯到頂 則停止移動 開始縮小高度*/
    for (int i = 0; i < stair.size() ; i++) {
        if (stair[i]->pos().y() == GAME_START_Y)
            stair[i]->resize (STAIR_X, stair[i]->height()-1);
        else
            stair[i]->move (GAME_START_X + stair[i]->position, stair[i]->pos().y()-1);
    }

}
void MyGame :: NewGame ()
{
    stand_for_num = 1;
    if (man != NULL)
        delete man;
    for (int i = 0 ; i < stair.size(); i++)
        delete stair[i];
    stand_timer = 18;
    if (timeid !=0)
    {
        killTimer(timeid);
        timeid = startTimer(stand_timer);
    }
    stair.clear();
    right = 1;
    man_x = GAME_WIDTH/2;
    man_y = 9;
    step = 0;
    key_press = 0;
    game_start_x = GAME_START_X;
    game_start_y = GAME_START_Y;
    for_num = 1;
//    speed = SPEED;
    first = 0;
    GameOver = 0;
    stand = 0;
//   status = 1;
 //   deg = 0;
    step_num = 0;
    flag = 0;
    blood = 12;
    pause = 0;
    on_stair = 0;
    turn_id  = NULL;
    stand_timer_timer = 0;
    blood = 12;
    stand_timer = 18;
 //   turn_drop = 0;
    warn = 0;
//    man_up_timer = 0;
    man = new MyMan(this);
    man->resize (MAN_WIDTH, MAN_HEIGHT);
    man->move (GAME_START_X+ man_x, GAME_START_Y + man_y);
    status = &man->status;
    man->raise();
    man->show();
}

void MyGame :: SetPause ()
{
    if (GameOver)
        return;
    pause = (pause) ? 0 : 1;
    for (int i = 0; i < stair.size(); i++)
        stair[i]->pause = (stair[i]->pause) ? 0 : 1;
    man->pause  = (man->pause) ? 0 : 1;
}

void  MyGame :: operator ++( int )
{
    this->step++;
}
void MyGame ::  addspeed ()
{
    static int speed_up_timer = 0;
    speed_up_timer++;
    if (speed_up_timer > 200)
        speed_up_timer = 0;
    else
        return;
    killTimer(timeid);
    stand_timer--;
    if (stand_timer <= 5)
        stand_timer = 5;
    timeid = startTimer (stand_timer);

}

void MyGame :: SetBlack()
{
    black = (black) ? 0 : 1;
}
