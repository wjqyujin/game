#include <iostream>
#include <ctime>
#include <array>
#include "game.h"
#include <string>
using namespace std;
int main()
{
    srand(time(0));
    int b;
    cout<<"请输入想要玩的游戏类型:1.德州扑克2.(未开发敬请等待)"<<endl;
    cin>>b;
    cin.clear();             //错误位重置
    cin.ignore(100, '\n');     //忽略100个字符，直到遇到'\n'
    if(b==1)
    {
    Poker p;
    p.play(2);
    }
}

