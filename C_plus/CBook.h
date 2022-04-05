//
// Created by yw980 on 2022/4/4.
//

#ifndef CBOOK_H
#define CBOOK_H
#include <string>
using namespace std;
class CBook {
private:
    int bookID;             // 图书编号
    string bookName;    // 图书名字
    bool isOnShelf;     // true为在架， false为借出
    bool isExist;       // true为存在，false为删除
public:
    CBook();            // 默认构造函数
    CBook(int bID, string name);     // 初始化图书信息
    void setID(int n);                  // 设置图书编号
    int getID();                        // 获取图书编号
    void setName(string name);          // 设置图书名称
    string getName();                   // 获取图书名称
    bool getIsOnShelf();                // 获取图书是否在库
    void setIsOnShelf(bool is);         // 设置图书是否在库
    bool getIsExist();                  // 获取图书是否存在
    void setIsExist(bool is);           // 设置图书是否存在
    void show();
};


#endif //C_PLUS_CBOOK_H
