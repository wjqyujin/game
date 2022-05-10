//
//  game.cpp
//  game
//
//  Created by wang on 2022/4/28.
//

#include "game.h"
#include <iostream>
#include <string>
#include <ctime>
#include <array>
using namespace std;
//-----------------------------------------Games 类具体实现
Games::Games()
:plWin(0),pcWin(0),total(0)
{
    int s;
    cout<<"请输入玩家名:";
    cin>>s;
    cin.clear();             //错误位重置
    cin.ignore(100, '\n');     //忽略100个字符，直到遇到'\n'
    name=s;
}
int Games::getPlWin()
{
    return plWin;
}
int Games::getPcWin()
{
    return pcWin;
}
int Games::getTotal()
{
    return total;
}
void Games::addPlWin()
{
    plWin++;
}
void Games::addPcWin()
{
    pcWin++;
}
void Games::setTotal(int t)
{
    total=t;
}
void Games::print()
{
    cout<<"比分为---------"<<endl;
    cout<<"玩家:"<<plWin<<"电脑："<<pcWin<<endl;
    cout<<"平局:"<<total-plWin-pcWin<<"场"<<endl;
}


//-----------------------------------------Poker 类具体实现
Poker::Poker()
:scoreP(0),scoreC(0)
{
}
void Poker::play(int t)
{
    setTotal(t);
    for(int i=0;i<getTotal();i++)
 {
    saveCard();              //先存牌
    shuffleCard();           //后洗牌
    dealCardPlayer_hand();   //给玩家发手牌
    dealCardComputer_hand(); //给电脑发手牌
    dealCardPlayer();        //给玩家发桌面牌
    dealCardComputer();      //给电脑发桌面牌
    selectPlayer();          //玩家选牌
    selectComputer();        //电脑选牌
    Sortcard(cardP, 5);
    Sortcard(cardC, 5); //将玩家和电脑的牌按牌面从大到小排列
    cardMax(cardP);
    judge(cardP);
    scoreP = score();
    cardMax(cardC); //判断玩家和电脑的最大单牌
    judge(cardC);
    scoreC = score();
    cout << "玩家的牌为:" << endl;
    printCard(cardP);
    cout << "电脑的牌为:" << endl;
    printCard(cardC); //打印玩家和电脑的牌
     if (scoreP == scoreC)
    {
        scoreP += KEY2[0] + KEY3[0] + KEY4[0];
        scoreC += KEY2[1] + KEY3[1] + KEY4[1];
    }
    if (scoreP > scoreC)
    {
        cout << "玩家获胜"<<endl;
        addPlWin();
    }
    else if (scoreP < scoreC)
    {
        cout << "电脑获胜"<<endl;
        addPcWin();
    }
    else if (scoreP == scoreC)
        cout << "平局";
}
    print();
    
}



void Poker::saveCard()
{
    int m = 2;
    for (int n = 1; n <= 4; n++)
    {
        int counter = 0;
        static int z = 0;
        for (; counter != 13; z++)
        {
            card[z].face = m;
            card[z].suit = n;
            if (m == 14)
            {
                m = 1;
            }
            m++;
            counter++;
        }
    }
}


void Poker::shuffleCard()
{
    int t, f;
    for (int z = 1; z <= 40; z++)
    {
        t = rand() % 52;
        f = rand() % 52;
        swap(card[t], card[f]);
    }
}


void Poker::dealCardPlayer_hand()
{
    for (int z = 0; z <= 1; i++)
    {
        handPlayer[z] = card[i];
        z++;
    }
}


void Poker::dealCardComputer_hand()
{
    for (int z = 0; z <= 1; i++)
    {
        handComputer[z] = card[i];
        z++;
    }
}


void Poker::dealCardPlayer()
{
    for (int z = 0; z <= 4; i++)
    {
        cardPlayer[z] = card[i];
        z++;
    }
}


void Poker::dealCardComputer()
{
    for (int z = 0; z <= 4; i++)
    {
        cardComputer[z] = card[i];
        z++;
    }
}


void Poker::selectPlayer()
{
    int m;
    cout << "玩家的手牌是:";
    for (int z = 0; z <= 1; z++)
    {
        string str;
        string str1;
        switch (handPlayer[z].suit)
        {
        case 1:
            str = "红桃";
            break;
        case 2:
            str = "方片";
            break;
        case 3:
            str = "黑桃";
            break;
        case 4:
            str = "梅花";
            break;
        }
        switch (handPlayer[z].face)
        {
        case 2:
            str1 = "2";
            break;
        case 3:
            str1 = "3";
            break;
        case 4:
            str1 = "4";
            break;
        case 5:
            str1 = "5";
            break;
        case 6:
            str1 = "6";
            break;
        case 7:
            str1 = "7";
            break;
        case 8:
            str1 = "8";
            break;
        case 9:
            str1 = "9";
            break;
        case 10:
            str1 = "10";
            break;
        case 11:
            str1 = "J";
            break;
        case 12:
            str1 = "Q";
            break;
        case 13:
            str1 = "K";
            break;
        case 14:
            str1 = "A";
            break;
        }
        cout << "【" << str << str1 << "】" << '\t';
    }
    cout << endl;
    cout << "玩家的公共牌是:";
    for (int z = 0; z <= 4; z++)
    {
        string str;
        string str1;
        switch (cardPlayer[z].suit)
        {
        case 1:
            str = "红桃";
            break;
        case 2:
            str = "方片";
            break;
        case 3:
            str = "黑桃";
            break;
        case 4:
            str = "梅花";
            break;
        }
        switch (cardPlayer[z].face)
        {
        case 2:
            str1 = "2";
            break;
        case 3:
            str1 = "3";
            break;
        case 4:
            str1 = "4";
            break;
        case 5:
            str1 = "5";
            break;
        case 6:
            str1 = "6";
            break;
        case 7:
            str1 = "7";
            break;
        case 8:
            str1 = "8";
            break;
        case 9:
            str1 = "9";
            break;
        case 10:
            str1 = "10";
            break;
        case 11:
            str1 = "J";
            break;
        case 12:
            str1 = "Q";
            break;
        case 13:
            str1 = "K";
            break;
        case 14:
            str1 = "A";
            break;
        }
        cout << "【" << str << str1 << "】" << '\t';
    }
    cout << "请输入1～7选择你需要的牌" << endl;
    for (int z = 0; z <= 4; z++)
    {
        cin >> m;
        cin.clear();             //错误位重置
        cin.ignore(100, '\n');     //忽略100个字符，直到遇到'\n'
        switch (m)
        {
        case 1:
            cardP[z] = handPlayer[0];
            break;
        case 2:
            cardP[z] = handPlayer[1];
            break;
        case 3:
            cardP[z] = cardPlayer[0];
            break;
        case 4:
            cardP[z] = cardPlayer[1];
            break;
        case 5:
            cardP[z] = cardPlayer[2];
            break;
        case 6:
            cardP[z] = cardPlayer[3];
            break;
        case 7:
            cardP[z] = cardPlayer[4];
            break;
        }
    }
}


void Poker::selectComputer()
{
    cardC[0] = handComputer[1];
    for (int z = 1; z <= 4; z++)
    {
        cardC[z] = cardComputer[z];
    }
}


void Poker::cardMax(Card M[])
{
    int k = M[0].face;
    for (int z = 1; z <= 4; z++)
    {
        if (M[z].face > k)
        {
            k = M[z].face;
        }
    }
    key[c] = k;
}


void Poker::Sortcard(Card s[],int arraysize)
{
    int z, j;
    for (z = 0; z < arraysize - 1; z++)
    {
        for (j = z + 1; j < arraysize; j++)
        {
            if (s[z].face < s[j].face)
            {
                swap(s[z], s[j]);
            }
        }
    }
}


void Poker::printCard(Card b[])
{
    for (int z = 0; z <= 4; z++)
    {
        string str;
        string str1;
        switch (b[z].suit)
        {
        case 1:
            str = "红桃";
            break;
        case 2:
            str = "方片";
            break;
        case 3:
            str = "黑桃";
            break;
        case 4:
            str = "梅花";
            break;
        }
        switch (b[z].face)
        {
        case 2:
            str1 = "2";
            break;
        case 3:
            str1 = "3";
            break;
        case 4:
            str1 = "4";
            break;
        case 5:
            str1 = "5";
            break;
        case 6:
            str1 = "6";
            break;
        case 7:
            str1 = "7";
            break;
        case 8:
            str1 = "8";
            break;
        case 9:
            str1 = "9";
            break;
        case 10:
            str1 = "10";
            break;
        case 11:
            str1 = "J";
            break;
        case 12:
            str1 = "Q";
            break;
        case 13:
            str1 = "K";
            break;
        case 14:
            str1 = "A";
            break;
        }
        cout << "【" << str << str1 << "】" << '\t';
    }
    cout << endl;
}


void Poker::judge(Card N[])
{
    int counter = 0;
    int m = 0;
    flag_ = 0;
    flag4 = 0;
    flag3 = 0;
    flag2 = 0;
    flag = 0;
    int frequence[5] = {0};
    for (int z = 2; counter != 5 && z <= 14; z++) //判断五张牌结束而且牌面不能超过14(A)
    {
        if (N[m].face == z)
        {
            flag = 1;
            m++;
            counter++;
        }
        else
        {
            if (flag == 1)
            {
                flag = 0;
                break;
            }
            counter++;
        } //判断顺子 是顺子flag==1
    }
    for (int z = 1; z <= 4; z++)
    {
        if (N[0].suit == N[z].suit)
            flag_ = 1;
        else
            flag_ = 0;
        if (flag_ == 0)
            break;
    } //判断同花顺 是同花顺flag_ ==1
    for (int z = 0; z <= 4; z++)
    {
        for (int j = 0; j <= 4; j++)
        {
            if (N[z].face == N[j].face)
                frequence[z]++;
        }
    }
    for (int z = 0; z <= 4; z++)
    {
        switch (frequence[z])
        {
        case 4:
            flag4 = 1;
            KEY4[c] = N[z].face;
            break;
        case 3:
            flag3 = 1;
            KEY3[c] = N[z].face;
            break;
        case 2:
            flag2++;
            if (flag2 <= 2)
                KEY2[c] = N[z].face;
            break;
        }
    }
}


int Poker::score()
{
    int n = 0;
    if (flag == 1 && flag_ == 1)
    {
        n += 100;
    }
    else if (flag == 1)
    {
        n += 60;
    }
    else if (flag4 == 1)
    {
        n += 40;
    }
    else if (flag3 == 1)
    {
        n += 35;
    }
    else if (flag2 == 2)
    {
        n += 15;
    }
    else if (flag2 == 4)
    {
        n += 30;
    }
    else
    {
        n += key[c];
    }
    c++;
    return n;
}
