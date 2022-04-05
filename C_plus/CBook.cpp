//
// Created by yw980 on 2022/4/4.
//

#include "CBook.h"
#include "CReader.h"
#include <string>
#include <iostream>
using namespace std;
CBook::CBook() {
    bookID = 0;
    bookName = "unnamed";
    isOnShelf = true;
    isExist = true;
}

CBook::CBook(int bID, string name) {
    bookID = bID;
    bookName = name;
    isExist = true;
    isOnShelf = true;
}

void CBook::setID(int n) {
    bookID = n;
}

int CBook::getID() {
    return bookID;
}

void CBook::setName(string name) {
    bookName = name;
}

string CBook::getName() {
    return bookName;
}

void CBook::setIsOnShelf(bool is) {
    isOnShelf = is;
}

bool CBook::getIsOnShelf(){
    return isOnShelf;
}

bool CBook::getIsExist(){
    return isExist;
}
void CBook::setIsExist(bool is){
    isExist = is;
}

void CBook::show(){
    if (isExist)
    {
        cout << "Ãû³Æ: " << bookName << "±àºÅ£º " << bookID;
        if(isOnShelf) cout << "ÔÚ¼Ü";
        else cout << "½è³ö";
        cout << endl;
    }
}
