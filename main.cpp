#include "manager.h"
#include "Customer.h"
#include "Mainwindow.h"

int main() {
    Mainwindow w;
    int iii = 1;
    while (iii) {
        w.welcome();
        cout << "请输入1或2\n";
        int choose;
        cin >> choose;
        if (choose == 1) {
            cout << "请输入管理员密码\n";
            string tmp;
            cin >> tmp;
            if (tmp == "1") {
                w.managerwindow();
            } else {
                cout << "密码错误!\n";
            }
        } else if (choose == 2) {
            w.customerwindow();
        } else {
            cout << "输入错误，请重新输入\n";
        }
        system("pause");
    }
    return 0;
}
