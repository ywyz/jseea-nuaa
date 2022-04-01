//
// Created by yw980 on 2022/3/26.
// 窗体模块设计
//


#include "string"
#include "iostream"
#include "iomanip"
#include "Book.h"

using namespace std;

// 通过system函数执行mode命令，控制显示信息的行数，列数，背景颜色等。
void SetScreenGrid(int cols, int lines){
    char sysSetBuf[80];
    sprintf(sysSetBuf, "mode con cols = %d lines = %d", cols, lines);
    system(sysSetBuf);
}
//设置控制台的标题
void SetSysCaption()
{
    system("Library System");
}

//清屏
void ClearScreen()
{
    system("cls");
}

//显示图书管理系统的欢迎信息
void ShowWelcome()
{
    for(int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << setw(40);
    cout << "********************" << endl;
    cout << setw(40);
    cout << "欢迎进入图书管理系统" << endl;
    cout << setw(40);
    cout << "********************" << endl;
}

// 显示系统主菜单
void ShowRootMenu()
{
    cout << setw(30);
    cout << "  请选择功能： " << endl;
    cout << endl;
    cout << setw(30);
    cout << "1.添加新书" << endl;
    cout << endl;
    cout << setw(30);
    cout << "2 浏览全部" << endl;
    cout << endl;
    cout << setw(30);
    cout << "3.删除图书" << endl;
}

// 负责程序进入某一模块后，等待用户进行处理
void WaitUser()
{
    int iInputPage = 0;
    cout << "enter 返回主菜单 q 推出" << endl;
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
// 主循环
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
