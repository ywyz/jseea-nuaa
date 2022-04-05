//
// Created by yw980 on 2022/4/5.
//

#ifndef C_PLUS_CBOOKMANAGER_H
#define C_PLUS_CBOOKMANAGER_H
#include <vector>
#include <string>
#include "CBook.h"

using namespace std;

class CBookManager {
private:
    vector <CBook> bkarray;         // 使用容器存储图书信息
public:
    CBookManager();
    ~CBookManager();
    void addBook(CBook book);       // 添加图书
    int findBook(string bookName);  // 通过图书名字查找图书
    int findBook(int bookID);       // 通过图书编号查找图书
    CBook getBook(int subscript);   // 通过编号返回图书信息
    void editBook(int subscript, CBook book);   //编辑图书
    void editBook(int subscript, int bookID);   //编辑图书编号
    void editBook(int subscript, string bookName);   //编辑图书名字
    void editBook(int subscript, bool isOnShelf);   //编辑图书在架情况
    void delBook(int subscript);    //删除图书
    void listBooks();               // 显示全部图书
    void save(string filename = "books.db");        // 保存到文件
    void load(string filename = "books.db");        //读取文件

};


#endif //JSEEA_NUAA_CBOOKMANAGE_H
