//
// Created by Mz on 2021/12/4.
//
//#include <string.h>
#include "string"
#include "iostream"
#include<cstdlib>
#include<time.h>
#ifndef CINEMA_TICKETS_H
#define CINEMA_TICKETS_H
using namespace std;

class Tickets {
    //电影票,存着电影的所有信息
protected:
    char moviename[66];
    double price;
    int num;//场次
    bool map[40][40];//座位
    int rest;//余票
    int month, day, hour;//开始时间
    string minute;
    //std::string minute="";
};


#endif //CINEMA_TICKETS_H
