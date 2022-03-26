//
// Created by yw980 on 2022/3/24.
//

#include <cstring>
#include "Book.h"
#include "iostream"
#include "string"
#include "fstream"
#include "iomanip"
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


void cBook::DelteData(int iCount) {
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