#include"map_cafe.h"

Cafe::Cafe()
{
    number=1;
    pixmap=QPixmap(":/images/cafe.png");
    cafewall=QPixmap(":/images/cafewall.png");
    setBackgroundBrush(pixmap.copy(0, 0, 32, 32));
    addRect(0, 0, 800, 64, Qt::NoPen, pixmap.copy(8, 64, 80, 64));
    addPixmap(cafewall.copy(0, 32, 10, 16))->setPos(0,0);
    addPixmap(cafewall.copy(86, 32, 10, 16))->setPos(790, 0);
    addPixmap(cafewall.copy(0, 112, 10, 16))->setPos(0, 584);
    addPixmap(cafewall.copy(86, 112, 10, 16))->setPos(790, 584);
    addPixmap(cafewall.copy(86, 32, 10, 16))->setPos(374, 584);
    addPixmap(cafewall.copy(0, 32, 10, 16))->setPos(416, 584);
    addRect(0, 0, 780, 16, Qt::NoPen, cafewall.copy(10, 32, 76, 16))->setPos(10, 0);
    addRect(0, 0, 10, 568, Qt::NoPen, cafewall.copy(0, 48, 10, 64))->setPos(0, 16);
    addRect(0, 0, 10, 568, Qt::NoPen, cafewall.copy(86, 48, 10, 64))->setPos(790, 16);
    addRect(0, 0, 364, 16, Qt::NoPen, cafewall.copy(10, 112, 76, 16))->setPos(10, 584);
    addRect(0, 0, 364, 16, Qt::NoPen, cafewall.copy(10, 112, 76, 16))->setPos(426, 584);
    addPixmap(pixmap.copy(225, 418, 31, 26))->setPos(16, 16);
    addPixmap(pixmap.copy(230, 361, 22, 19))->setPos(176, 16);
    addPixmap(pixmap.copy(196, 393, 22, 19))->setPos(592, 16);
    addPixmap(pixmap.copy(162, 353, 27, 30))->setPos(752, 16);
    addPixmap(pixmap.copy(19, 363, 60, 45))->setPos(366, 48);
    addPixmap(pixmap.copy(70, 144, 22, 36))->setPos(176, 160);
    addPixmap(pixmap.copy(4, 143, 58, 48))->setPos(160, 196);
    addPixmap(pixmap.copy(102, 145, 22, 23))->setPos(176, 244);
    addPixmap(pixmap.copy(70, 144, 22, 36))->setPos(592, 160);
    addPixmap(pixmap.copy(4, 143, 58, 48))->setPos(576, 196);
    addPixmap(pixmap.copy(102, 145, 22, 23))->setPos(592, 244);
    addPixmap(pixmap.copy(70, 144, 22, 36))->setPos(176, 384);
    addPixmap(pixmap.copy(4, 143, 58, 48))->setPos(160, 416);
    addPixmap(pixmap.copy(102, 145, 22, 23))->setPos(176, 464);
    addPixmap(pixmap.copy(70, 144, 22, 36))->setPos(592, 384);
    addPixmap(pixmap.copy(4, 143, 58, 48))->setPos(576, 416);
    addPixmap(pixmap.copy(102, 145, 22, 23))->setPos(592, 464);
}
