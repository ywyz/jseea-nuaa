//
// Created by yw980 on 2022/3/26.
// ����ģ�����
//


#include "string"
#include "iostream"
#include "iomanip"
#include "Book.h"

using namespace std;

// ͨ��system����ִ��mode���������ʾ��Ϣ��������������������ɫ�ȡ�
void SetScreenGrid(int cols, int lines){
    char sysSetBuf[80];
    sprintf(sysSetBuf, "mode con cols = %d lines = %d", cols, lines);
    system(sysSetBuf);
}
//���ÿ���̨�ı���
void SetSysCaption()
{
    system("Library System");
}

//����
void ClearScreen()
{
    system("cls");
}

//��ʾͼ�����ϵͳ�Ļ�ӭ��Ϣ
void ShowWelcome()
{
    for(int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << setw(40);
    cout << "********************" << endl;
    cout << setw(40);
    cout << "��ӭ����ͼ�����ϵͳ" << endl;
    cout << setw(40);
    cout << "********************" << endl;
}

// ��ʾϵͳ���˵�
void ShowRootMenu()
{
    cout << setw(30);
    cout << "  ��ѡ���ܣ� " << endl;
    cout << endl;
    cout << setw(30);
    cout << "1.�������" << endl;
    cout << endl;
    cout << setw(30);
    cout << "2 ���ȫ��" << endl;
    cout << endl;
    cout << setw(30);
    cout << "3.ɾ��ͼ��" << endl;
}

// ����������ĳһģ��󣬵ȴ��û����д���
void WaitUser()
{
    int iInputPage = 0;
    cout << "enter �������˵� q �Ƴ�" << endl;
    char buf[256];
    gets(buf);
    if (buf[0] == 'q')
        system("exit");
}

int GetSelect()
{
    char buf[256];
    gets(buf);
    return atoi(buf);
}
// ��ѭ��
void mainloop()
{
    ShowWelcome();
    while(1)
    {
        ClearScreen();
        ShowWelcome();
        ShowRootMenu();
        switch (GetSelect()) {
            case 1:
                ClearScreen();
                GuideInput();
                break;

            case 2:
                ClearScreen();
                ViewData();
                break;

            case 3:
                ClearScreen();
                DeleteBookFromFile();
                break;
        }
    }
}
