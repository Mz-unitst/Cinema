//
// Created by Mz on 2021/12/4.
//

#ifndef CINEMA_CUSTOMER_H
#define CINEMA_CUSTOMER_H

#include "tickets.h"

class Customer : public Tickets {
//    顾客类，购票退票
public:
    void buytickets();

    void refundtickets();
    void show();
    friend ostream &operator<<(ostream &op, Customer &s) {
        int i, j = 0;
        op.width(10);
        op << s.num;
        op.width(12);
        op << "2013-";
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
        for (j = 0; j < 10; j++) {
            cout << '\t';
            for (i = 0; i < 10; i++) {
                if (s.map[j][i] != 0)
                    op << "[空闲]";
                else
                    op << "[有人]";
            }
            cout << endl;
        }
        return op;
    }


};


#endif //CINEMA_CUSTOMER_H
