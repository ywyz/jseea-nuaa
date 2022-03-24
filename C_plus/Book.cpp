//
// Created by yw980 on 2022/3/24.
//

#include "Book.h"
#include "iostream"
#include "string"
#include "fstream"
#include "iomanip"
using namespace std;
CBook::CBook(char* cName, char* cISBN, char* cPrice, char* cAuthor) {
    strncpy(m_cName, cName, NUM1);
    strncpy(m_cISBN, cISBN, NUM1);
    strncpy(m_cPrice, cPrice, NUM2);
    strncpy(m_cAuthor, cAuthor, NUM2)
}