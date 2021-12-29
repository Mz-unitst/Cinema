//
// Created by Mz on 2021/12/4.
//

#include "Customer.h"
#include "cstring"
#include "fstream"
#include "manager.h"

void Customer::buytickets() { //购票函数
    Customer cus;
    Manager tmp;
    char f[20] = "";
    int n;
    while (1) { //循环判断电影是否过时
        time_t systime; //获取系统时间的一些格式
        struct tm *timeinfo;
        time(&systime);
        timeinfo = localtime(&systime);
        tmp.show();
        cout << "输入你要买的场次（如 5）：";

        cin >> n;
        char f1[20] = "";
        int tmp[20];
        int k = 0;
        while (n) {
            tmp[k] = (n % 10);
            ++k;
            n /= 10;
        }
        for (int i = 0; i < k; i++) {
            f1[i] = '0' + tmp[k - i - 1];
        }
        strcat(f1, ".dat");
        fstream in(f1, ios::in | ios::binary);
        if (!in.is_open()) {
            remove(f);
            cout << "无该场次电影\n";
            continue;
        }
        in.read((char *) &cus, sizeof(cus));
        in.close(); //将时间比较转换成数值比较
        int curtime = (timeinfo->tm_mon + 1) * 1000 + timeinfo->tm_mday * 24 + timeinfo->tm_hour; //给系统时间赋权值
        int movietime = cus.month * 1000 + cus.day * 24 + cus.hour;
        if (curtime < movietime) {
            strcpy(f, f1);
            break;
        } //将文件 f1 的名字复制给 f，可以重新打开
        cout << "\n 该影片已经播放，请重新选择\n\n";
        system("pause");
    }
    cout << "当前场次的订票情况：" << endl;
    cout << cus << endl; //输出当前的订票情况，哪个座位有人，那个座位没人
    int i = 0, j = 0;
    for (i = 0; i < 9; i++) {
        cout << '\t';
        for (j = 0; j < 10; j++) {
            if (cus.map[n][i][j] == 0)
                cout << "[空闲]";
            else
                cout << "[有人]";
        }
        cout << endl;
    }
    cout << "\t";
    for (i = 0; i < 5; i++) {
        cout.width(11);
        if (cus.map[n][9][i * 2] == 0) {
            cout << "[空    闲]";
        } else {
            cout << "[有    人]";
        }
    }
    cout << endl;
//    system("pause");
    cout << "输入你想要的座位（如 3 5,输入0 0退出当前模块）：";
//    int i, j = 0;
    cin >> i >> j;
    if (i == 0 && j == 0) return;
    while ((!(i > 0 && i < 11 && j > 0 && j < 11)) || (i == 10 && (j < 1 || j > 5))) {
        cout << "座位非法\n";
        cout << "输入你想要的座位（如 3 5）：";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    while (cus.map[n][i - 1][j - 1] == 1) { //判断座位是否已经被购买
        cout << "您输入的座位已被购买，请重新输入！" << endl;
        cout << "输入你想要的座位（如 3 5,输入0 0退出当前模块）：";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    if (i == 10) {
        cout << "您选择的是情侣座，售价为" << cus.price * 2 << "元";
        cus.map[n][i - 1][j * 2 - 1] = 1;
        cus.map[n][i - 1][j * 2 - 2] = 1;
        cus.rest -= 2;
    } else {
        cout << "售价为" << cus.price << "元";
        cus.map[n][i - 1][j - 1] = 1;
        --cus.rest;
    }
    fstream out(f, ios::out | ios::binary);
    out.write((char *) &cus, sizeof(cus)); //将已经更改的信息重新保存到文件中
    out.close();
    cout << "购票成功" << endl;
    system("pause");
}


void Customer::refundtickets() {
    Customer cus;
    cout << "输入你想要退票的场次（如 2）：";
    int n; //输入退票的场次
    cin >> n;
    char f[20] = "";
    int tmp[20];
    int k = 0;
    while (n) {
        tmp[k] = (n % 10);
        ++k;
        n /= 10;
    }
    for (int i = 0; i < k; i++) {
        f[i] = '0' + tmp[k - i - 1];
    }
    strcat(f, ".dat");
    fstream in(f, ios::in | ios::binary);
    in.read((char *) &cus, sizeof(cus));
    in.close();
    int i = 0, j = 0;
    for (i = 0; i < 9; i++) {
        cout << '\t';
        for (j = 0; j < 10; j++) {
            if (cus.map[n][i][j] == 0)
                cout << "[空闲]";
            else
                cout << "[有人]";
        }
        cout << endl;
    }
    cout << "\t";
    for (i = 0; i < 5; i++) {
        cout.width(11);
        if (cus.map[n][9][i * 2] == 0) {
            cout << "[空    闲]";
        } else {
            cout << "[有    人]";
        }
    }
    cout << endl;
    cout << "输入你退票的座位（如 3 5,输入0 0退出当前模块）：";
//    int i, j = 0; //退票的座位
    cin >> i >> j;
    if (i == 0 && j == 0) return;
    while ((!(i > 0 && i < 11 && j > 0 && j < 11)) || (i == 10 && (j < 1 || j > 5))) {
        cout << "座位非法\n";
        cout << "输入你想要退票的座位（如 3 5,输入0 0退出当前模块）：";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    while (cus.map[n][i - 1][j - 1] == 0) { //判断退票的座位是否被购票
        cout << "您输入的座位未被购买，请重新输入！" << endl;
        cout << "输入你退票的座位（如 3 5,输入0 0退出当前模块）：";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    cout << ".\n.\n.\n";
    if (i == 10) {
        if (j % 2 == 0)j--;
        cus.map[n][i - 1][j - 1] = 0;
        cus.map[n][i - 1][j] = 0;
        cus.rest += 2;
        cout << "退给您" << 2 * cus.price << "元";
    } else {
        cus.map[n][i - 1][j - 1] = 0;
        ++cus.rest;
        cout << "退给您" << cus.price << "元";
    }
    fstream out(f, ios::out | ios::binary);
    out.write((char *) &cus, sizeof(cus));
    out.close();
    cout << "退票成功" << endl;
    system("pause");
}