#ifndef CAFE_H
#define CAFE_H

#include"map.h"

class Cafe: public Map
{
private:
    QPixmap cafewall;
public:
    Cafe();
};

#endif // CAFE_H
