//
// Created by yw980 on 2022/4/5.
//

#include "CReader.h"
#include <iostream>
#include <string>
using namespace std;
CReader::CReader()
{
    is_Borrow = true;
    is_Exist = true;
}

CReader::CReader(int readerID, string readerName) :CUser(readerID, readerName)
{
    is_Borrow = true;
    is_Exist = true;
}

bool CReader::get_isExist()
{
    return is_Exist;
}

void CReader::set_isExist(bool is)
{
    is_Exist = is;
}

bool CReader::get_isBorrow()
{
    return is_Borrow;
}

void CReader::set_isBorrow(bool is)
{
    is_Borrow = is;
}

void CReader::setBrBook(CBook br)
{
    brBook = br;
}

CBook CReader::getBrBook()
{
    return brBook;
}

void CReader::show()
{
    CUser::show();
    if (brBook.getIsOnShelf()==false)
        cout << " 书名是" << brBook.getName() <<" 书号是"<<brBook.getID()<< endl;
}