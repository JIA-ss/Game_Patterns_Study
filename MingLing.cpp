#include "NameTools.h"
/*
 * 命令模式：
 * 讲一个请求封装成一个对象，从而允许你使用不同的请求、队列或者日志将客户端参数化，
 * 同时支持请求操作的撤销与恢复
 *
 */
//比如通过 “按钮” 来完成 跳跃、开火等功能

//命令类
class Command
{
public:
    virtual ~Command(){}
    virtual void execute() = 0;
};

class JumpCommand : Command {
public:
    virtual void execute() { std::cout << "jump" << std::endl; }
};

class FireCommand : Command {
public :
    virtual void execute() { std::cout << "fire" << std::endl; }
};

//输入监控
class InputHandler
{
public:
    void handleInput();
    //bind button
private:
    Command* buttonX_;
    Command* buttonY_;
    Command* buttonA_;
    Command* buttonB_;
};

void InputHandler::handleInput() {
    if(isPressed(BUTTON_X)) { buttonX_->execute(); }
    else if(isPressed(BUTTON_Y)) { buttonY_->execute(); }
    else if(isPressed(BUTTON_A)) { buttonA_->execute(); }
    else if(isPressed(BUTTON_B)) { buttonB_->execute(); }
}


//命令模式的 撤销 和 重做 需要对之前的状态进行保存

class Command_
{
public:
   virtual ~Command_() {}
   virtual void execute() = 0;
   virtual void undo() = 0;
};

class MoveUnitCommand : Command_
{
public:
    MoveUnitCommand(Unit* unit, int x, int y): unit_(unit),x_(x),y_(y),xBefore(0),yBefore(0){}
    virtual void execute()
    {
        xBefore = unit_->x();
        yBefore = unit_->y();
        unit_->MoveTo(x_,y_);
    }
    virtual void undo()
    {
        unit_->MoveTo(xBefore,yBefore);
    }
private:
    Unit* unit_;
    int x_, y_, xBefore, yBefore
};

