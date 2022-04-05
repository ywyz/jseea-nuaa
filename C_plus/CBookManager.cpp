//
// Created by yw980 on 2022/4/5.
//

#include "CBookManager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

CBookManager::CBookManager()
{
}


CBookManager::~CBookManager()
{
}

void CBookManager::addBook(CBook book)
{
    bkarray.push_back(book);
}

int CBookManager::findBook(string bookName)
{
    for (int i = 0; i < bkarray.size(); i++)
    {
        if (bkarray[i].getName() == bookName) return i;
    }
    return -1;
}

int CBookManager::findBook(int bookID)
{
    for (int i = 0; i < bkarray.size(); i++)
    {
        if (bkarray[i].getID() == bookID && bkarray[i].getIsExist()== true)
        {
            if (bkarray[i].getIsOnShelf() == true)
                return i;
            else return -2;
        }
    }
    return -1;
}

CBook CBookManager::getBook(int subscript)
{
    return bkarray[subscript];
}

void CBookManager::editBook(int subscript, CBook book)
{
    bkarray[subscript] = book;
}

void CBookManager::editBook(int subscript, int bookID)
{
    bkarray[subscript].setID(bookID);
}

void CBookManager::editBook(int subscript, string bookName)
{
    bkarray[subscript].setName(bookName);
}

void CBookManager::editBook(int subscript, bool isOnShelf)
{
    bkarray[subscript].setIsOnShelf(isOnShelf);
}

void CBookManager::delBook(int subscript)
{
    bkarray[subscript].setIsExist(false);
}

void CBookManager::listBooks()
{
    cout << "所有的图书为" << endl;
    for (int i = 0; i < bkarray.size(); i++)
    {
        if (bkarray[i].getIsExist())
            bkarray[i].show();
    }
}

void CBookManager::save(string filename)
{
    ofstream outfile(filename.c_str(), ios::binary);
    if (!outfile.is_open())
    {
        cout << "Error opening file";
        return;
    }
    int bksize = bkarray.size();
    outfile.write((char*)(&bksize), sizeof(bksize));
    for (int i = 0; i <bksize; i++)
        outfile.write((char*)(&bkarray[i]), sizeof(CBook));
    outfile.close();
}
void CBookManager::load(string filename)
{
    ifstream infile(filename.c_str(), ios::binary);
    if (!infile.is_open())
    {
        cout << "Error opening file";
        return;
    }
    bkarray.clear();
    int bksize;
    infile.read((char*)(&bksize), sizeof(bksize));
    bkarray.reserve(bksize * 2);
    CBook *bookarray = new CBook[bksize];
    for (int i = 0; i < bksize; i++)
    {
        infile.read((char*)(&bookarray[i]), sizeof(CBook));
        bkarray.push_back(bookarray[i]);
    }
    infile.close();
}