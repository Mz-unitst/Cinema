#include "manager.h"
#include "Customer.h"
#include "Mainwindow.h"

int main() {
    Mainwindow w;
    Manager op;
    while (1) {
        w.welcome();
        cout << "������1��2\n" << endl;
        int choose;
        cin >> choose;
        if (choose == 1) {
            cout << "���������Ա����\n";
            string tmp;
            cin >> tmp;
            if (op.pd(tmp)) {
                w.managerwindow();
            } else {
                cout << "�������!\n";
            }
        } else if (choose == 2) {
            w.customerwindow();
        } else {
            cout << "�����������������\n";
        }
//        system("pause");
    }
    return 0;
}
