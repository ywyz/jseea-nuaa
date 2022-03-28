//
// Created by yw980 on 2022/3/26.
//

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include "conio.h"
#include "string"
#include "fstream"
#include "Book.h"
#include "Screen.h"

#define CMD_COLS 80
#define CMD_LINES 25
using namespace std;

int main()
{
    SetScreenGrid(CMD_COLS, CMD_LINES);             //设置控制台背景
    SetSysCaption();                                          // 设置控制台标题
    mainloop();
}
