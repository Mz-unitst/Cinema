//
// Created by Mz on 2021/12/4.
//
//#include <string.h>
#include "string"
#include "iostream"
#include<cstdlib>
#include<time.h>
#include "string.h"

#ifndef CINEMA_TICKETS_H
#define CINEMA_TICKETS_H
using namespace std;

class Tickets {
    //电影票,存着电影的所有信息
protected:
    char moviename[66];
    double price;
    int num;//场次
    bool map[20][10][10];//场次n的电影的座位,20输出不下
    int rest;//余票
    int month, day, hour;//开始时间
    char minute[4];

    //std::string minute="";
    Tickets() {
        memset(map, 0, sizeof(map));
    }
};


#endif //CINEMA_TICKETS_H
