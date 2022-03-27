//
// Created by yw980 on 2022/3/24.
//

#include <cstring>
#include "Book.h"
#include "iostream"
#include "string"
#include "fstream"
#include "iomanip"
#include "Screen.h"

using namespace std;
cBook::cBook(char* cName, char* cISBN, char* cPrice, char* cAuthor) {
    strncpy(m_cName, cName, NUM1);
    strncpy(m_cISBN, cISBN, NUM1);
    strncpy(m_cPrice, cPrice, NUM2);
    strncpy(m_cAuthor, cAuthor, NUM2);
}

char* cBook::GetName()
{
    return m_cName;
}

void cBook::SetName(char* cName)
{
    strncpy(m_cName, cName, NUM1);
}

char* cBook::GetISBN()
{
    return m_cISBN;
}

void cBook::SetISBN(char* cISBN)
{
    strncpy(m_cISBN, cISBN, NUM1);
}

char* cBook::GetPrice()
{
    return m_cPrice;
}

void cBook::SetPrice(char* cPrice) {
    strncpy(m_cPrice, cPrice, NUM2);
}

char* cBook::GetAuthor() {
    return m_cAuthor;
}

void cBook::SetAuthor(char* cAuthor) {
    strncpy(m_cAuthor, cAuthor, NUM2);
}

// 读写文件函数

void cBook::WriteData() {
    ofstream ofile;
    ofile.open("book.dat", ios::binary|ios::app);
    try{
        ofile.write(m_cName,NUM1);
        ofile.write(m_cISBN, NUM1);
        ofile.write(m_cAuthor, NUM2);
        ofile.write(m_cPrice, NUM2);
    }
    catch (...)
    {
        throw "file error occurred";
        ofile.close();
    }
    ofile.close();
}

void cBook::GetBookFromFile(int iCount) {
    char cName[NUM1];
    char cISBN[NUM1];
    char cPrice[NUM2];
    char cAuthor[NUM2];
    ifstream ifile;
    ifile.open("book.dat", ios::binary);
    try{
        ifile.seekg(iCount*(NUM1+NUM1+NUM2+NUM2),ios::beg);
        ifile.read(cName,NUM1);
        if(ifile.tellg()>0)
            strncpy(m_cName, cName, NUM1);
        ifile.read(cISBN,NUM1);
        if(ifile.tellg()>0)
            strncpy(m_cISBN, cISBN, NUM1);
        ifile.read(cPrice,NUM2);
        if(ifile.tellg()>0)
            strncpy(m_cPrice, cPrice, NUM2);
        ifile.read(cAuthor,NUM2);
        if(ifile.tellg()>0)
            strncpy(m_cAuthor, cAuthor, NUM2);
    }
    catch (...)
    {
        throw "file error ocurred";
        ifile.close();
    }
    ifile.close();
}


void cBook::DeleteData(int iCount) {
    long respos;
    int iDataCount = 0;
    fstream file;
    fstream tmpfile;
    ofstream ofile;
    char cTempBuf[NUM1+NUM1+NUM2+NUM2];
    file.open("book.dat", ios::binary|ios::in|ios::out);
    tmpfile.open("temp.dat", ios::binary|ios::in|ios::out|ios::trunc);
    file.seekg(0,ios::end);
    respos = file.tellg();
    iDataCount = respos / (NUM1+NUM2+NUM1+NUM2);
    if(iCount < 0 && iCount > iDataCount)
    {
        throw "Input Number Error";
    }
    else
    {
        file.seekg(iCount* (NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
        for(int j = 0; j < (iDataCount - iCount); j++)
        {
            memset(cTempBuf, 0, NUM1+NUM1+NUM2+NUM2);
            file.read(cTempBuf,NUM1+NUM1+NUM2+NUM2 );
            tmpfile.write(cTempBuf, NUM1+NUM1+NUM2+NUM2);
        }
        file.close();
        tmpfile.seekg(0, ios::beg);
        ofile.open("book.dat");
        ofile.seekp((iCount-1)*(NUM1+NUM1+NUM2+NUM2),ios::beg);
        for(int i = 0; i < (iDataCount - iCount); i++)
        {
            memset(cTempBuf, 0 , NUM1+NUM1+NUM2+NUM2);
            tmpfile.read(cTempBuf, NUM1+NUM1+NUM2+NUM2);
            ofile.write(cTempBuf,NUM1+NUM1+NUM2+NUM2);
        }
    }
    tmpfile.close();
    ofile.close();
    remove("temp.dat");
}

//添加新书模块
void GuideInput()
{
    char inName[NUM1];
    char inISDN[NUM1];
    char inPrice[NUM2];
    char inAuthor[NUM2];
    cout << "输入书名" << endl;
    cin >> inName;
    cout << "输入ISBN" << endl;
    cin >> inISDN;
    cout << "输入价格" << endl;
    cin >> inPrice;
    cout << "输入作者" << endl;
    cin >> inAuthor;
    cBook book(inName, inISDN, inPrice, inAuthor);
    book.WriteData();
    cout << "Write Finish" << endl;
    WaitUser();
}

// 获取文件长度
long GetFileLength(ifstream & ifs)
{
    long tmppos;
    long respos;
    tmppos = ifs.tellg();
    ifs.seekg(0, ios::end);
    respos = ifs.tellg();
    ifs.seekg(tmppos, ios::beg);
    return respos;
}

// 浏览全部模块
void ViewData(int iSelPage = 1)
{
    int iPage = 0;
    int iCurPage = 0;
    int iDataCount = 0;
    char inName[NUM1];          // 存储图书名称的变量
    char inISBN[NUM1];          // 存储图书ISBN编号的变量
    char inPrice[NUM2];         // 存储图书价格的变量
    char inAuthor[NUM2];        // 存储图书作者的变量

    bool bIndex = false;
    int iFileLength;
    iCurPage = iSelPage;
    ifstream ifile;
    ifile.open("book.dat", ios::binary);
    iFileLength = GetFileLength(ifile);
    iDataCount = iFileLength / (NUM1 + NUM2 + NUM1 + NUM2);         //根据文件长度，计算文件中总的记录数


    if (iDataCount >= 1)
        bIndex = true;
    iPage = iDataCount / 20 + 1;
    ClearScreen();                                                  //清除屏幕信息


    cout << " 共有记录 " << iDataCount << "  ";
    cout << " 共有页数 " << iPage << "  ";
    cout << " 当前页数 " << iCurPage << "  ";
    cout << " n 下一页 r 返回"  << endl;
    cout << setw(5) << "Index";
    cout << setw(22) << "Name" << setw(22) << "ISBN" ;
    cout << setw(15) << "Price" << setw(15) << "Author";
    cout << endl;
    try{
        // 根据图书记录编号查找在文件中的位置。
        ifile.seekg((iCurPage - 1) * 20 * (NUM1 + NUM2 + NUM1 + NUM2), ios::beg);
        if(!ifile.fail())
        {
            for(int i = 1; i<21;i++)
            {
                memset(inName, 0, 128);               // 将变量清零
                memset(inISBN, 0,  128);
                memset(inAuthor,0, 50);
                memset(inPrice, 0, 50);
                if(bIndex)
                    cout << setw(3) << ((iCurPage - 1) * 20 + i);

                ifile.read(inName, NUM1);              //读取图书名字
                cout << setw(24) << inName;
                ifile.read(inISBN, NUM1);              //读取图书ISBN
                cout << setw(24) << inISBN;
                ifile.read(inPrice, NUM2);              //读取图书价格
                cout << setw(12) << inPrice;
                ifile.read(inAuthor, NUM1);              //读取图书作者
                cout << setw(12) << inAuthor;
                cout << endl;

                if (ifile.tellg() < 0)
                    bIndex = false;
                else
                    bIndex = true;
            }
        }
    }
    catch (...)
    {
        cout << "throw file exception" << endl;
        throw "file error occurred";                // 抛出异常
        ifile.close();                              // 关闭文件流
    }

    if (iCurPage < iPage)
    {
        iCurPage = iCurPage + 1;
        WaitUser();
    }
    else
        WaitUser();
    ifile.close();
}