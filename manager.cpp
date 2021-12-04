//
// Created by Mz on 2021/12/4.
//

#include "manager.h"
#include "string.h"
#include "fstream"

void Manager::insert() {
//    增加电影
    while (1) {
        Manager movie;
        cout << "输入场次号:";
        cin >> movie.num;
        char f[20] = ""; //将不同的电影场次和相应的文件相对应
        f[0] = movie.num + '0';
        strcat(f, ".dat"); //将 f 保存为相应的文件
        fstream out(f, ios::out | ios::binary); //电影信息输入
        cout << "输入电影放映的日期 月和日（如 1 1）:";
        cin >> movie.month >> movie.day;
        movie.hour = 6 + movie.num * 2;
        cout << movie.hour;
        cout << "输入电影的名字（如 火影忍者）:";
        cin >> movie.moviename;
        cout << "输入票价（如 5）:";
        cin >> movie.price;
        out.write((char *) &movie, sizeof(movie));
        cout << "录入成功！！！" << endl << endl;
        cout << "是否继续录入（y/n）：";
        char b;
        cin >> b;
        if (b != 'y' && b != 'Y')break;
        out.close();
    }
    cout << "录入成功！！！" << endl;
    system("pause");

}

void Manager::show() { //显示所有电影信息
    Manager movie;
    cout << "所有的电影信息显示如下：" << endl;
    cout.width(12);
    cout << "场次";
    cout.width(12);
    cout << "日期";
    cout.width(14);
    cout << "时间";
    cout.width(12);
    cout << "电影名称";
    cout.width(9);
    cout << "票价";
    cout.width(10);
    cout << "余票\n";
    for (int i = 0; i < 20; i++) {
        char f[20] = "";
        f[0] = i + '0';
        strcat(f, ".dat");
        fstream fin(f, ios::in | ios::binary);

        if (fin.is_open()) {
            fin.read((char *) &movie, sizeof(movie));
            cout << movie;
            fin.close();
        } else remove(f); //删除没有存入电影信息的文件
    }
    cout << endl << endl;
}

void Manager::change() { //改变电影信息
    Manager movie;
    movie.show();
    l1:
    cout << "输入你要更改的电影场次:";
    int n;
    cin >> n;
    char f[20] = "";
    f[0] = n + '0';
    strcat(f, ".dat");
    fstream out(f, ios::out | ios::binary);
    if (!out.is_open()) {
        cout << "打开失败";
        goto l1;
    }
    movie.num = n; //输入新的电影场次信息
    cout << "输入电影放映的日期 月和日（如 3 17）:";
    cin >> movie.month >> movie.day;
    movie.hour = 6 + movie.num * 2;
    cout << "输入电影的名字（如 火影忍者）:";
    cin >> movie.moviename;
    cout << "输入票价（如 5）:";
    cin >> movie.price;
    out.write((char *) &movie, sizeof(movie));
    out.close();
    cout << "更改成功" << endl;
    system("pause");
}

void Manager::deletee() { //删除电影信息
    Manager movie;
    movie.show();
    cout << "输入你要删除的电影场次：";
    int n;
    cin >> n;
    char f[20] = "";
    f[0] = n + '0';
    strcat(f, ".dat");
    remove(f); //直接删除相应的保存电影的文件
    cout << "删除成功" << endl;
    system("pause");
}

void Manager::find() { //查找电影
    Manager movie;
    int result = 0;
    cout << "输入你要查找的电影名称："; //通过电影名查找相应电影
    char tmpname[20] = "";
    cin >> tmpname;
    cout << endl << "查找的结果：" << endl;
    cout.width(12);
    cout << "场次";
    cout.width(12);
    cout << "日期";
    cout.width(14);
    cout << "时间";
    cout.width(12);
    cout << "电影名称";
    cout.width(9);
    cout << "票价";
    cout.width(10);
    cout << "余票\n";
    for (int i = 0; i < 10; i++) { //同样遍历文件得到查找的信息
        char f[20] = "";
        f[0] = i + '0';//样例只有1-9，不支持两位数
        strcat(f, ".dat");
        fstream in(f, ios::in | ios::binary);
        if (!in.is_open()) {
            remove(f);
            continue;
        }

        in.read((char *) &movie, sizeof(movie));
        if (!strcmp(movie.moviename, tmpname)) {
            result = 1;
            cout << movie;
        }
        in.close();
    }
    if (result == 0)
        cout << endl << "\t\t 未找到该电影" << endl;
    cout << endl;
    system("pause");
}