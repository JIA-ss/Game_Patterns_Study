/*起一些函数名字，方便其他文件编译和代码的可读*/
#include <iostream>
#define BUTTON_X 1
#define BUTTON_Y 1
#define BUTTON_A 1
#define BUTTON_B 1
bool isPressed(int x);
class GameActor
{
public:
    void action();
};

class Unit
{
public:
    int x();
    int y();
    void MoveTo(int x, int y);
};