#include "IRClass.h"

bool MeasureDistance::initDistance()
{
    if (digitalRead(this->IRPin) == LOW)
        return true;

    else
        return false;
}
