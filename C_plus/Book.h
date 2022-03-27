//
// Created by yw980 on 2022/3/24.
// 图书记录写入删除，m_cName  m_cISBN  m_cPrice  m_cAuthor 分别代表图书的名称，ISBN编号，价格、作者。
// 设置属性的函数以Set开头， 获取属性的函数以Get开头
//

#ifndef C_PLUS_BOOK_H
#define C_PLUS_BOOK_H
#define NUM1 128
#define NUM2 50

void DeleteBookFromFile();
void ViewData(int iSelPage = 1);
void GuideInput();

class cBook
{
public:
    cBook(){};
    cBook(char* cName, char* cISBN, char* cPrice, char* cAuthor);
    ~cBook(){}

public:
    char* GetName();            // 获取图书名称
    void SetName(char* cName);  // 设置图书名称
    char* GetISBN();            // 获取图书ISBN编号
    void SetISBN(char* cISBN);             // 设置图书ISBN编号
    char* GetPrice();           // 获取图书价格
    void SetPrice(char* cPrice);// 设置图书价格
    char* GetAuthor();          // 获取图书作者
    void SetAuthor(char* cAuthor);           // 设置图书作者
    void WriteData();           // 写入图书数据
    void DeleteData(int iCount); // 删除图书数据
    void GetBookFromFile(int iCount);   // 从文件中读取数据


protected:
    char m_cName[NUM1];
    char m_cISBN[NUM1];
    char m_cPrice[NUM2];
    char m_cAuthor[NUM2];
};


#endif //C_PLUS_BOOK_H
