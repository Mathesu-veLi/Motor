#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

class Motor {
  private:
    int pinL;
    int pinR;
    int defaultSpeed;
    
  public:
    Motor(int pinL, int pinR);
    Motor(int pinL, int pinR, int defaultSpeed);

    void forward();
    void forward(int speed);

    void back();
    void back(int speed);

    void stop();
};

#endif