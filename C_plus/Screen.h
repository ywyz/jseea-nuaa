//
// Created by yw980 on 2022/3/26.
// 窗体模块设计
//


#include "string"
#include "iostream"
#include "iomanip"
#include "Book.h"


// 通过system函数执行mode命令，控制显示信息的行数，列数，背景颜色等。
void SetScreenGrid(int cols, int lines);
//设置控制台的标题
void SetSysCaption();


//清屏
void ClearScreen();

//显示图书管理系统的欢迎信息
void ShowWelcome();

// 显示系统主菜单
void ShowRootMenu();

// 负责程序进入某一模块后，等待用户进行处理
void WaitUser();


int GetSelect();
// 主循环
void mainloop();
