//
// Created by Mz on 2021/12/4.
//

#include "Mainwindow.h"
#include "manager.h"
#include "Customer.h"

void Mainwindow::welcome() {
    time_t systime; //获取系统时间的一些格式
    struct tm *timeinfo;
    time(&systime);
    timeinfo = localtime(&systime);
    cout << endl << endl << endl;

    cout << "\t\t\t\t当前时间：" <<asctime(timeinfo)<<endl;
    cout << "\t\t\t\t计科影院欢迎您\n\n\n";
    cout << "\t\t\t**********1.管理模块**********\n\n";
    cout << "\t\t\t**********2.售票模块**********\n\n";
}

void Mainwindow::managerwindow() {
    cout << "\t\t\t欢迎进入管理模块\n\n";
    while (1) {
        Manager admin;
        cout << "\t\t\t------------------------------\n";
        cout << "\t\t\t ******1.增加电影******\n";
        cout << "\t\t\t ******2.显示影片******\n";
        cout << "\t\t\t ******3.修改影片******\n";
        cout << "\t\t\t ******4.删除影片******\n";
        cout << "\t\t\t ******5.查找影片******\n";
        cout << "\t\t\t ****** 6.退出 ******\n";
        cout << "\t\t\t------------------------------\n";
        cout << "你的选择：";
        int choose; //选择
        cin >> choose;
        switch (choose) {
            case 1:
                admin.change();
                break; //电影录入
            case 2:
                admin.show();
                system("pause");
                break; //影片显示
            case 3:
                admin.change();
                break;
            case 4:
                admin.deletee();
                break;
            case 5:
                admin.find();
                break; //查找影片
            case 6:
                break; //退出
            default:
                cout << "输入错误！";
                break;
        }
        if (choose == 6)break;
    }
    cout << "已退出！！" << endl;
//    system("pause");
}

void Mainwindow::customerwindow() {
    Customer customer;
    cout << "\t\t\t\t 欢迎进入售票系统\n\n";
    while (1) {
        cout << "\t\t\t------------------------------\n";
        cout << "\t\t\t ******1.购票******\n";
        cout << "\t\t\t ******2.退票******\n";
        cout << "\t\t\t ******3.退出******\n";
        cout << "\t\t\t------------------------------\n";
        cout << "你的选择：";
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                customer.buytickets();
                break; //买票
            case 2:
                customer.refundtickets();
                break; //退票
            case 3:
                break; //退出
            default:
                cout << "输入错误！";
                break;
        }
        if (choose == 3) break;
    }
    cout << "已退出！！！" << endl;
    system("pause");

}