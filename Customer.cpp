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
    while (1) { //ѭ���жϵ�Ӱ�Ƿ��ʱ
        time_t systime; //��ȡϵͳʱ���һЩ��ʽ
        struct tm *timeinfo;
        time(&systime);
        timeinfo = localtime(&systime);
        tmp.show();
        cout << "������Ҫ��ĳ��Σ��� 5����";
        int n;
        cin >> n;
        char f1[10] = "";
        int a, b; //������Ӧ��Ȩֵ�����ڱȽ�ϵͳʱ��͵�Ӱʱ��Ĵ�С
        f1[0] = n + '0';
        strcat(f1, ".dat");
        fstream in(f1, ios::in | ios::binary);
        in.read((char *) &cus, sizeof(cus));
        in.close(); //��ʱ��Ƚ�ת������ֵ�Ƚ�
        int curtime = (timeinfo->tm_mon + 1) * 1000 + timeinfo->tm_mday * 24 + timeinfo->tm_hour; //��ϵͳʱ�丳Ȩֵ
        int movietime = cus.month * 1000 + cus.day * 24 + cus.hour;
        if (curtime < movietime) {
            strcpy(f, f1);
            break;
        } //���ļ� f1 �����ָ��Ƹ� f���������´�
        cout << "\n ��ӰƬ�Ѿ����ţ�������ѡ��\n\n";
    }
    cout << "��ǰ���εĶ�Ʊ�����" << endl;
    cout << cus; //�����ǰ�Ķ�Ʊ������ĸ���λ���ˣ��Ǹ���λû��
    cout << "��������Ҫ����λ���� 3 5����";
    int i, j = 0;
    cin >> i >> j;
    while (cus.map[i - 1][j - 1] == 1 || (i == 20 && cus.map[i - 1][j] == 1)) { //�ж���λ�Ƿ��Ѿ�������
        cout << "���������λ�ѱ��������������룡" << endl;
        cout << "��������Ҫ����λ���� 3 5����";
        cin >> i >> j;
    }
    if (i == 20) {
        cout << "��ѡ��������������ۼ�Ϊ" << cus.price * 2 << "Ԫ";
        cus.map[i - 1][j - 1] = 1;
        if(j%2==0){
            cus.map[i - 1][j-2] = 1;
        } else{
            cus.map[i - 1][j] = 1;
        }

        cus.rest -= 2;
    } else {
        cout << "�ۼ�Ϊ" << cus.price << "Ԫ";
        cus.map[i - 1][j - 1] = 1;
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
    f[0] = n + '0';
    strcat(f, ".dat");
    fstream in(f, ios::in | ios::binary);
    in.read((char *) &cus, sizeof(cus));
    in.close();
    cout << "��������Ʊ����λ���� 3 5����";
    int i, j = 0; //��Ʊ����λ
    cin >> i >> j;
    while (cus.map[i - 1][j - 1] != 0) { //�ж���Ʊ����λ�Ƿ񱻹�Ʊ
        cout << "���������λδ���������������룡" << endl;
        cout << "��������Ʊ����λ���� 3 5����";
        cin >> i >> j;
    }
    cout << ".\n.\n.\n";
    if (i == 20) {
        if(j%2==0)j--;
        cus.map[i - 1][j - 1] = 0;
        cus.map[i - 1][j] = 0;
        cus.rest += 2;
        cout << "�˸���" << 2 * cus.price << "Ԫ";
    } else {
        cus.map[i - 1][j - 1] = 0;
        ++cus.rest;
        cout << "�˸���" << cus.price << "Ԫ";
    }
    fstream out(f, ios::out | ios::binary);
    out.write((char *) &cus, sizeof(cus));
    out.close();
    cout << "��Ʊ�ɹ�" << endl;
    system("pause");
}