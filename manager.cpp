//
// Created by Mz on 2021/12/4.
//

#include "manager.h"
#include "string.h"
#include "fstream"

void Manager::insert() {
//    ���ӵ�Ӱ
    while (1) {
        Manager movie;
        l2:
        movie.show();
        cout << "���볡�κ�:\n";
        cin >> movie.num;
        char f[20] = ""; //����ͬ�ĵ�Ӱ���κ���Ӧ���ļ����Ӧ
        int n = movie.num;
        f[0] = movie.num + '0';
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
        strcat(f, ".dat"); //�� f ����Ϊ��Ӧ���ļ�
        fstream out(f, ios::out | ios::binary); //��Ӱ��Ϣ����
        if (!out.is_open()) {
            cout << "��ʧ��";
            goto l2;
        }
        cout << "�����Ӱ��ӳ������ �º��գ��� 1 1��:";
        cin >> movie.month >> movie.day;
        movie.hour = (movie.num * 17 + 7) % 12 + 10;
//        cout << movie.hour;
        cout << "�����Ӱ�����֣��� ��Ӱ���ߣ�:";
        cin >> movie.moviename;
        cout << "����Ʊ�ۣ��� 5��:";
        cin >> movie.price;
        out.write((char *) &movie, sizeof(movie));
        cout << "¼��ɹ�������" << endl << endl;
        cout << "�Ƿ����¼�루y/n����";
        char b;
        cin >> b;
        if (b != 'y' && b != 'Y')break;
        out.close();
    }
    cout << "¼��ɹ�������" << endl;
//    system("pause");

}

void Manager::show() { //��ʾ���е�Ӱ��Ϣ
    Manager movie;
    cout << "���еĵ�Ӱ��Ϣ��ʾ���£�" << endl;
    cout.width(15);
    cout << "  ����";
    cout.width(15);
    cout << "����";
    cout.width(15);
    cout << "ʱ��";
    cout.width(15);
    cout << "��Ӱ����";
    cout.width(15);
    cout << "Ʊ��";
    cout.width(15);
    cout << "��Ʊ\n";
    for (int i = 0; i < 20; i++) {
        char f[20] = "";
        int n = i;
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
        fstream fin(f, ios::in | ios::binary);

        if (fin.is_open()) {
            fin.read((char *) &movie, sizeof(movie));
            cout << movie;
            fin.close();
        } else remove(f); //ɾ��û�д����Ӱ��Ϣ���ļ�
    }
    cout << endl << endl;
}

void Manager::change() { //�ı��Ӱ��Ϣ
    Manager movie;
    while (1) {
        movie.show();
        l1:
        cout << "������Ҫ���ĵĵ�Ӱ���Σ����޸ó��������Ӹó��ε�Ӱ��:";
        int n;
        cin >> n;
        movie.num = n; //�����µĵ�Ӱ������Ϣ
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
        fstream out(f, ios::out | ios::binary);
        if (!out.is_open()) {
            cout << "��ʧ��";
            goto l1;
        }
        cout << "�����Ӱ��ӳ������ �º��գ��� 3 17��:";
        cin >> movie.month >> movie.day;
        while (!checkday(movie.month, movie.day)) {
            cout << "���ڷǷ�\n";
            cout << "�����Ӱ��ӳ������ �º��գ��� 3 17��:";
            cin >> movie.month >> movie.day;
        }

        movie.hour = (2 + movie.num * 17) % 12 + 10;
        cout << "�����Ӱ�����֣��� ��Ӱ���ߣ�:";
        cin >> movie.moviename;
        cout << "����Ʊ�ۣ��� 5��:";
        cin >> movie.price;
        out.write((char *) &movie, sizeof(movie));
        out.close();
        cout << "���ĳɹ�" << endl;
        cout << "�Ƿ�������ģ�y/n����";
        char b;
        cin >> b;
        if (b != 'y' && b != 'Y')break;
        out.close();
//        system("pause");
    }

}

void Manager::deletee() { //ɾ����Ӱ��Ϣ
    Manager movie;
    movie.show();
    cout << "������Ҫɾ���ĵ�Ӱ���Σ�";
    int n;
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
    remove(f); //ֱ��ɾ����Ӧ�ı����Ӱ���ļ�
    cout << "ɾ���ɹ�" << endl;
    system("pause");
}

void Manager::find() { //���ҵ�Ӱ
    Manager movie;
    int result = 0;
    cout << "������Ҫ���ҵĵ�Ӱ���ƣ�"; //ͨ����Ӱ��������Ӧ��Ӱ
    char tmpname[20] = "";
    cin >> tmpname;

    for (int i = 0; i < 30; i++) { //ͬ�������ļ��õ����ҵ���Ϣ
        char f[20] = "";
        int n = i;
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
        if (!in.is_open()) {
            remove(f);
            continue;
        }

        in.read((char *) &movie, sizeof(movie));
        if (!strcmp(movie.moviename, tmpname)) {
            if (!result) {
                cout << endl << "���ҵĽ����" << endl;
                cout.width(12);
                cout << "����";
                cout.width(12);
                cout << "����";
                cout.width(14);
                cout << "ʱ��";
                cout.width(12);
                cout << "��Ӱ����";
                cout.width(9);
                cout << "Ʊ��";
                cout.width(10);
                cout << "��Ʊ\n";
            }
            result = 1;
            cout << movie;
        }
        in.close();
    }
    if (result == 0)
        cout << endl << "\t\t δ�ҵ��õ�Ӱ" << endl;
    cout << endl;
    system("pause");
}

bool Manager::pd(string s) {
    if (s == passwd) {
        return 1;
    }
    return 0;
}

bool Manager::checkday(int m, int d) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 0 && d < 32)return 1;
    } else if (m == 2) {
        if (d > 0 && d < 29) return 1;
    } else if (d > 0 && d < 31 && (m > 0 && m < 13)) return 1;

    return 0;
}