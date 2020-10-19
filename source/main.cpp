#include<QApplication>
#include"game.h"
#include"QtDebug"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qsrand((time(nullptr)));
    Game *game=new Game();
    game->show();
    return app.exec();
}

//art by Sithjester, telles0808, Rommeu, Amysaurus121
