#include"map_route.h"
#include<QPainter>

Route::Route()
{
    number=2;
    encounterRate=2;
    pixmap=QPixmap(":/images/all.png");
    QPixmap background(800, 600);
    QPainter painter(&background);
    for(int x=0;x<800;x+=32)
    {
        for(int y=0;y<600;y+=32)
        {
            if(x==352||x==384||x==416) painter.drawPixmap(x, y, pixmap, 96, 64, 32, 32);
            else painter.drawPixmap(x, y, pixmap, 192, 64, 32, 32);
        }
    }
    painter.end();
    setBackgroundBrush(background);
    addPixmap(pixmap.copy(32, 992, 32, 32))->setPos(352, 0);
    addPixmap(pixmap.copy(32, 992, 32, 32))->setPos(416, 0);
    addPixmap(pixmap.copy(192, 1056, 32, 32))->setPos(256, 0);
    addPixmap(pixmap.copy(192, 1056, 32, 32))->setPos(288, 0);
    addPixmap(pixmap.copy(192, 1056, 32, 32))->setPos(320, 0);
    addPixmap(pixmap.copy(192, 1056, 32, 32))->setPos(448, 0);
    addPixmap(pixmap.copy(192, 1056, 32, 32))->setPos(480, 0);
    addPixmap(pixmap.copy(192, 1056, 32, 32))->setPos(512, 0);
    addPixmap(pixmap.copy(224, 1056, 32, 32))->setPos(256, 32);
    addPixmap(pixmap.copy(224, 1056, 32, 32))->setPos(512, 32);
    addPixmap(pixmap.copy(224, 1056, 32, 32))->setPos(288, 64);
    addPixmap(pixmap.copy(224, 1056, 32, 32))->setPos(480, 64);
    addPixmap(pixmap.copy(224, 1056, 32, 32))->setPos(320, 96);
    addPixmap(pixmap.copy(224, 1056, 32, 32))->setPos(448, 96);
    addPixmap(pixmap.copy(224, 1024, 32, 32))->setPos(352, 128);
    addPixmap(pixmap.copy(224, 1024, 32, 32))->setPos(384, 128);
    addPixmap(pixmap.copy(224, 1024, 32, 32))->setPos(416, 128);
}
