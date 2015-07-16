#ifndef STAIR_H
#define STAIR_H
/*---------------------------------------------*/
#include "header.h"
#include "MyMan.h"
using namespace std;

class MyMan;

class STAIR : public QWidget
{
    Q_OBJECT

    public:
    int position;
    int status;
    bool pause;
    bool through;
    STAIR (QWidget *parent ,int inti);
    virtual void dothing (int &, int &, int &, bool&, bool&, int &, bool &, int &)= 0;
    protected:
    virtual void paintEvent(QPaintEvent *) = 0;
    void timerEvent (QTimerEvent *);
    int choice;

};

class Stair_Normal : public STAIR
{
    public:
    Stair_Normal (QWidget *parent = 0);
    virtual void dothing (int &, int &, int &, bool &, bool & , int &, bool &, int &);
    protected:
    virtual void paintEvent(QPaintEvent *);

    private:
    QString *stair;
    vector <QPixmap> stair_pic;
};

class Stair_Right : public STAIR
{
    public:
    Stair_Right (QWidget *parent = 0);
    virtual void dothing (int &, int &, int &, bool &, bool & , int &, bool &, int &);
    protected:
    virtual void paintEvent(QPaintEvent *);
    //void timerEvent (QPainte)
    private:
    QString *stair;
    vector <QPixmap> stair_pic;
};

class Stair_Left : public STAIR
{
    public:
    Stair_Left (QWidget *parent = 0);
    virtual void dothing (int &, int &, int &, bool &, bool & , int &, bool &, int &);
    protected:
    virtual void paintEvent(QPaintEvent *);

    private:
    QString *stair;
    vector <QPixmap> stair_pic;
};

class Stair_Spike : public STAIR
{
    public:
    Stair_Spike (QWidget *parent = 0);
    virtual void dothing (int &, int &, int &, bool &, bool & , int &, bool &, int &);
    protected:
    virtual void paintEvent(QPaintEvent *);

    private:
    QString *stair;
    vector <QPixmap> stair_pic;
};

class Stair_Turn : public STAIR
{
    public:
    vector <int> stair_height;
    int stand_time;
    Stair_Turn (QWidget *parent = 0);
    virtual void dothing (int &, int &, int &, bool &, bool & , int &, bool &, int &);
    protected:
    virtual void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    private:
    QString *stair;
    vector <QPixmap> stair_pic;
    int change_to_through;
};

class Stair_Spring : public STAIR
{
    public:
    vector <int> stair_height;
    Stair_Spring (QWidget *parent = 0);
    int pos_y;
    int status_pre;
    int pre_pos_y;
    bool normal;
    virtual void dothing (int &, int &, int &, bool &, bool & , int &, bool &, int &);
    protected:
    virtual void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    private:
    QString *stair;
    vector <QPixmap> stair_pic;

};

class Stair_Sharp : public QWidget
{
public:
    Stair_Sharp (QWidget * parent);
    protected:
    void paintEvent(QPaintEvent *);
};

STAIR* getSTAIR (QWidget*);


/*---------------------------------------------*/
#endif // START_H
