//
// Created by yw980 on 2022/4/5.
//

#include "CReaderManager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


CReaderManager::CReaderManager()
{
}


CReaderManager::~CReaderManager()
{
}

CReader CReaderManager::getReader(int subscript)
{
    return rdArray[subscript];
}
void CReaderManager::addReader(CReader reader)
{
    rdArray.push_back(reader);
}

int CReaderManager::findReader(string readerName)
{
    for (int i = 0; i < rdArray.size(); i++)
    {
        if (rdArray[i].getUserName() == readerName) return i;
    }
    return -1;
}

int CReaderManager::findReader(int readerID)
{
    for (int i = 0; i < rdArray.size(); i++)
    {
        if (rdArray[i].getUserId() == readerID) return i;
    }
    return -1;
}

int CReaderManager::findReader(CBook book)
{
    for (int i = 0; i < rdArray.size(); i++)
    {
        if (rdArray[i].getBrBook().getID() == book.getID() && rdArray[i].getBrBook().getName() == book.getName()) return i;
    }
    return -1;
}

void CReaderManager::editReader(int subscript, CReader reader)
{
    rdArray[subscript] = reader;
}

void CReaderManager::editReader(int subscript, string readerName)
{
    rdArray[subscript].setUserName(readerName);
}

void CReaderManager::editReader(int subscript, int readerID)
{
    rdArray[subscript].setUserID(readerID);
}

void CReaderManager::editReader(int subscript, CBook book)
{
    rdArray[subscript].setBrBook(book);
}

void CReaderManager::editReader(int subscript, bool is_Borrow)
{
    rdArray[subscript].set_isBorrow(is_Borrow);
}

void CReaderManager::delReader(int subscript)
{
    rdArray[subscript].set_isExist(false);
}

void CReaderManager::listReaders()
{
    cout << "所有的读者为" << endl;
    for (int i = 0; i < rdArray.size(); i++)
    {
        if (rdArray[i].get_isExist()) rdArray[i].show();
    }
}

void CReaderManager::save(string filename)
{
    ofstream outfile(filename.c_str(), ios::binary);
    if (!outfile.is_open())
    {
        cout << "Error opening file";
        return;
    }
    int rdsize = rdArray.size();
    outfile.write((char*)(&rdsize), sizeof(rdsize));
    for (int i = 0; i < rdsize; i++)
        outfile.write((char*)(&rdArray[i]), sizeof(CReader));
    outfile.close();
}
void CReaderManager::load(string filename)
{
    ifstream infile(filename.c_str(), ios::binary);
    if (!infile.is_open())
    {
        cout << "Error opening file";
        return;
    }
    rdArray.clear();
    int rdsize;
    infile.read((char*)(&rdsize), sizeof(rdsize));
    rdArray.reserve(rdsize * 2);
    CReader * readerarray = new CReader[rdsize];
    for (int i = 0; i < rdsize; i++)
    {
        infile.read((char*)(&readerarray[i]), sizeof(CReader));
        rdArray.push_back(readerarray[i]);
    }
    infile.close();
}