#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

class MeasureDistance
{
  private:
    short echoPin;
    short trigPin;
    unsigned long duration{};
    int distance{};
    void initDistance();

  public:
    MeasureDistance(const short echo,const short trig) : echoPin{echo} , trigPin{trig} {}
    int getDistance();

};

#endif
