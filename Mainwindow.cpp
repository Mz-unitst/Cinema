//
// Created by Mz on 2021/12/4.
//

#include "Mainwindow.h"
#include "manager.h"
#include "Customer.h"

void Mainwindow::welcome() {
    time_t systime; //��ȡϵͳʱ���һЩ��ʽ
    struct tm *timeinfo;
    time(&systime);
    timeinfo = localtime(&systime);
    cout << endl << endl << endl;
    cout << "\t\t\t\t ����ʱ�䣺" << timeinfo->tm_hour << ":" << timeinfo->tm_min << endl;
    cout << "\t\t\t\t�ƿ�ӰԺ��ӭ��\n\n\n";
    cout << "\t\t\t**********1.����ģ��**********\n\n";
    cout << "\t\t\t**********2.��Ʊģ��**********\n\n";
}

void Mainwindow::managerwindow() {
    cout << "\t\t\t��ӭ�������ģ��\n\n";
    while (1) {
        Manager admin;
        cout << "\t\t\t------------------------------\n";
        cout << "\t\t\t ******1.���ӵ�Ӱ******\n";
        cout << "\t\t\t ******2.��ʾӰƬ******\n";
        cout << "\t\t\t ******3.�޸�ӰƬ******\n";
        cout << "\t\t\t ******4.ɾ��ӰƬ******\n";
        cout << "\t\t\t ******5.����ӰƬ******\n";
        cout << "\t\t\t ****** 6.�˳� ******\n";
        cout << "\t\t\t------------------------------\n";
        cout << "���ѡ��";
        int choose; //ѡ��
        cin >> choose;
        switch (choose) {
            case 1:
                admin.change();
                break; //��Ӱ¼��
            case 2:
                admin.show();
                system("pause");
                break; //ӰƬ��ʾ
            case 3:
                admin.change();
                break;
            case 4:
                admin.deletee();
                break;
            case 5:
                admin.find();
                break; //����ӰƬ
            case 6:
                break; //�˳�
            default:
                cout << "�������";
                break;
        }
        if(choose==6)break;
    }
    cout << "���˳�����" << endl;
//    system("pause");
}

void Mainwindow::customerwindow() {
    Customer customer;
    cout << "\t\t\t\t ��ӭ������Ʊϵͳ\n\n";
    while (1) {
        cout << "\t\t\t------------------------------\n";
        cout << "\t\t\t ******1.��Ʊ******\n";
        cout << "\t\t\t ******2.��Ʊ******\n";
        cout << "\t\t\t ******3.�˳�******\n";
        cout << "\t\t\t------------------------------\n";
        cout << "���ѡ��";
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                customer.buytickets();
                break; //��Ʊ
            case 2:
                customer.refundtickets();
                break; //��Ʊ
            case 3:
                break; //�˳�
            default:
                cout << "�������";
                break;
        }
        if(choose==3) break;
    }
    cout << "���˳�������" << endl;
    system("pause");

}