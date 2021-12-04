//
// Created by Mz on 2021/12/4.
//

#ifndef CINEMA_MANAGER_H
#define CINEMA_MANAGER_H

#include "tickets.h"
#include "iostream"
//using namespace std;

class Manager : public Tickets {
    //管理员类
public:
    Manager() {
        rest = 400;
        minute = ":00";
    }

    void insert();

    void show();

    void change();

    void find();

    void deletee();

    friend ostream &operator<<(ostream &op, Manager &s) {
        //输出电影s的信息
        op.width(10);
        op << s.num;
        op.width(15);
        op << "2021-";
        op << s.month << "- ";
        op << s.day << "";
        op.width(10);
        op << s.hour;
        op << s.minute;
        op.width(10);
        op << s.moviename;
        op.width(10);
        op << s.price;
        op.width(10);
        op << s.rest << endl;
        return op;
    }
};


#endif //CINEMA_MANAGER_H
