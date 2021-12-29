//
// Created by Mz on 2021/12/4.
//

#include "Customer.h"
#include "cstring"
#include "fstream"
#include "manager.h"

void Customer::buytickets() { //��Ʊ����
    Customer cus;
    Manager tmp;
    char f[20] = "";
    int n;
    while (1) { //ѭ���жϵ�Ӱ�Ƿ��ʱ
        time_t systime; //��ȡϵͳʱ���һЩ��ʽ
        struct tm *timeinfo;
        time(&systime);
        timeinfo = localtime(&systime);
        tmp.show();
        cout << "������Ҫ��ĳ��Σ��� 5����";

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
            cout << "�޸ó��ε�Ӱ\n";
            continue;
        }
        in.read((char *) &cus, sizeof(cus));
        in.close(); //��ʱ��Ƚ�ת������ֵ�Ƚ�
        int curtime = (timeinfo->tm_mon + 1) * 1000 + timeinfo->tm_mday * 24 + timeinfo->tm_hour; //��ϵͳʱ�丳Ȩֵ
        int movietime = cus.month * 1000 + cus.day * 24 + cus.hour;
        if (curtime < movietime) {
            strcpy(f, f1);
            break;
        } //���ļ� f1 �����ָ��Ƹ� f���������´�
        cout << "\n ��ӰƬ�Ѿ����ţ�������ѡ��\n\n";
        system("pause");
    }
    cout << "��ǰ���εĶ�Ʊ�����" << endl;
    cout << cus << endl; //�����ǰ�Ķ�Ʊ������ĸ���λ���ˣ��Ǹ���λû��
    int i = 0, j = 0;
    for (i = 0; i < 9; i++) {
        cout << '\t';
        for (j = 0; j < 10; j++) {
            if (cus.map[n][i][j] == 0)
                cout << "[����]";
            else
                cout << "[����]";
        }
        cout << endl;
    }
    cout << "\t";
    for (i = 0; i < 5; i++) {
        cout.width(11);
        if (cus.map[n][9][i * 2] == 0) {
            cout << "[��    ��]";
        } else {
            cout << "[��    ��]";
        }
    }
    cout << endl;
//    system("pause");
    cout << "��������Ҫ����λ���� 3 5,����0 0�˳���ǰģ�飩��";
//    int i, j = 0;
    cin >> i >> j;
    if (i == 0 && j == 0) return;
    while ((!(i > 0 && i < 11 && j > 0 && j < 11)) || (i == 10 && (j < 1 || j > 5))) {
        cout << "��λ�Ƿ�\n";
        cout << "��������Ҫ����λ���� 3 5����";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    while (cus.map[n][i - 1][j - 1] == 1) { //�ж���λ�Ƿ��Ѿ�������
        cout << "���������λ�ѱ��������������룡" << endl;
        cout << "��������Ҫ����λ���� 3 5,����0 0�˳���ǰģ�飩��";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    if (i == 10) {
        cout << "��ѡ��������������ۼ�Ϊ" << cus.price * 2 << "Ԫ";
        cus.map[n][i - 1][j * 2 - 1] = 1;
        cus.map[n][i - 1][j * 2 - 2] = 1;
        cus.rest -= 2;
    } else {
        cout << "�ۼ�Ϊ" << cus.price << "Ԫ";
        cus.map[n][i - 1][j - 1] = 1;
        --cus.rest;
    }
    fstream out(f, ios::out | ios::binary);
    out.write((char *) &cus, sizeof(cus)); //���Ѿ����ĵ���Ϣ���±��浽�ļ���
    out.close();
    cout << "��Ʊ�ɹ�" << endl;
    system("pause");
}


void Customer::refundtickets() {
    Customer cus;
    cout << "��������Ҫ��Ʊ�ĳ��Σ��� 2����";
    int n; //������Ʊ�ĳ���
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
                cout << "[����]";
            else
                cout << "[����]";
        }
        cout << endl;
    }
    cout << "\t";
    for (i = 0; i < 5; i++) {
        cout.width(11);
        if (cus.map[n][9][i * 2] == 0) {
            cout << "[��    ��]";
        } else {
            cout << "[��    ��]";
        }
    }
    cout << endl;
    cout << "��������Ʊ����λ���� 3 5,����0 0�˳���ǰģ�飩��";
//    int i, j = 0; //��Ʊ����λ
    cin >> i >> j;
    if (i == 0 && j == 0) return;
    while ((!(i > 0 && i < 11 && j > 0 && j < 11)) || (i == 10 && (j < 1 || j > 5))) {
        cout << "��λ�Ƿ�\n";
        cout << "��������Ҫ��Ʊ����λ���� 3 5,����0 0�˳���ǰģ�飩��";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    while (cus.map[n][i - 1][j - 1] == 0) { //�ж���Ʊ����λ�Ƿ񱻹�Ʊ
        cout << "���������λδ���������������룡" << endl;
        cout << "��������Ʊ����λ���� 3 5,����0 0�˳���ǰģ�飩��";
        cin >> i >> j;
        if (i == 0 && j == 0) return;
    }
    cout << ".\n.\n.\n";
    if (i == 10) {
        if (j % 2 == 0)j--;
        cus.map[n][i - 1][j - 1] = 0;
        cus.map[n][i - 1][j] = 0;
        cus.rest += 2;
        cout << "�˸���" << 2 * cus.price << "Ԫ";
    } else {
        cus.map[n][i - 1][j - 1] = 0;
        ++cus.rest;
        cout << "�˸���" << cus.price << "Ԫ";
    }
    fstream out(f, ios::out | ios::binary);
    out.write((char *) &cus, sizeof(cus));
    out.close();
    cout << "��Ʊ�ɹ�" << endl;
    system("pause");
}