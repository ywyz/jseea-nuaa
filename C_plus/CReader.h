//
// Created by yw980 on 2022/4/5.
//

#ifndef C_PLUS_CREADER_H
#define C_PLUS_CREADER_H
#include "CBook.h"
#include "CUser.h"
using namespace std;


class CReader : public CUser{
private:
    bool is_Exist;          // true为用户存在
    bool is_Borrow;         // true为借过书
    CBook brBook;           // 读者所借过的书
public:
    CReader();
    CReader(int readerID, string readerName);
    bool get_isExist();     // 获取读者存在标志
    void set_isExist(bool isExist);     // 设置存在标志
    bool get_isBorrow();    // 获取读者借阅情况
    void set_isBorrow();    // 设置读者借阅情况
    void setBrBook(CBook br);    // 记录读者借书信息
    CBook getBrBook();          // 用来获取读者借书信息；
    void show();                // 显示读者的基本情况和借书情况
};


#endif //C_PLUS_CREADER_H
