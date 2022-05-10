//
//  game.h
//  game
//
//  Created by wang on 2022/4/28.
//

#ifndef game_h
#define game_h
#include <iostream>
#include <string>
using namespace std;
class Games
{
public:
    Games();
    int getPlWin();
    int getPcWin();
    int getTotal();
    void addPlWin();
    void addPcWin();
    void setTotal(int);
    void print();
private:
    int plWin;
    int pcWin;
    int total;
    string name;
};


class Poker:public Games
{
public:
    void play(int);
    Poker();
    struct Card
    {
        int face;
        int suit;
    };
    void saveCard();
    void shuffleCard();
    void dealCardPlayer_hand();
    void dealCardComputer_hand();
    void dealCardPlayer();
    void dealCardComputer();
    void selectPlayer();
    void selectComputer();
    void cardMax(Card []);
    void Sortcard(Card [], int);
    void printCard(Card []);
    void judge(Card []);
    int score();
private:
    int flag;
    int flag_;
    int flag4;
    int flag3;
    int flag2;
    int key[2] = {0};
    int KEY2[2] = {0};
    int KEY3[2] = {0};
    int KEY4[2] = {0};
    int i = 0;
    int c = 0;
    int scoreP;
    int scoreC;
    Card card[52] = {};   //牌库
    Card handPlayer[2];   //玩家的手牌
    Card handComputer[2]; //机器人的手牌
    Card cardPlayer[5];   //玩家的桌面牌
    Card cardComputer[5]; //机器人的桌面牌
    Card cardP[5];        //玩家选择的五张牌
    Card cardC[5];        //机器人选择的五张牌
};
#endif /* game_h */
