#include "header.h"
#include "MyGame.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);
    int width = WIN_WIDTH, height = WIN_HEIGHT;
    MyGame game;
    game.setFixedSize(width, height);
    game.show();
    return app.exec();
}
