#include "manager.h"
#include "Customer.h"
#include "Mainwindow.h"

int main() {
    Mainwindow w;
    int iii = 1;
    while (iii) {
        w.welcome();
        cout << "������1��2\n";
        int choose;
        cin >> choose;
        if (choose == 1) {
            cout << "���������Ա����\n";
            string tmp;
            cin >> tmp;
            if (tmp == "1") {
                w.managerwindow();
            } else {
                cout << "�������!\n";
            }
        } else if (choose == 2) {
            w.customerwindow();
        } else {
            cout << "�����������������\n";
        }
        system("pause");
    }
    return 0;
}
