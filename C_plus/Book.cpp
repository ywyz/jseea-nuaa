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

// ��д�ļ�����

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
void GuideInput()
{
    char inName[NUM1];
    char inISDN[NUM1];
    char inPrice[NUM2];
    char inAuthor[NUM2];
    cout << "��������" << endl;
    cin.getline(inName, NUM1);
    cout << "����ISBN" << endl;
    cin.getline(inISDN, NUM1);
    cout << "����۸�" << endl;
    cin.getline(inPrice, NUM2);
    cout << "��������" << endl;
    cin.getline(inAuthor, NUM2);
    cBook book(inName, inISDN, inPrice, inAuthor);
    book.WriteData();
    cout << "Write Finish" << endl;
    WaitUser();
}

// ��ȡ�ļ�����
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

// ���ȫ��ģ��
void ViewData(int iSelPage)
{
    int iPage = 0;
    int iCurPage = 0;
    int iDataCount = 0;
    char inName[NUM1];          // �洢ͼ�����Ƶı���
    char inISBN[NUM1];          // �洢ͼ��ISBN��ŵı���
    char inPrice[NUM2];         // �洢ͼ��۸�ı���
    char inAuthor[NUM2];        // �洢ͼ�����ߵı���

    bool bIndex = false;
    int iFileLength;
    iCurPage = iSelPage;
    ifstream ifile;
    ifile.open("book.dat", ios::binary);
    iFileLength = GetFileLength(ifile);
    iDataCount = iFileLength / (NUM1 + NUM2 + NUM1 + NUM2);         //�����ļ����ȣ������ļ����ܵļ�¼��


    if (iDataCount >= 1)
        bIndex = true;
    iPage = iDataCount / 20 + 1;
    ClearScreen();                                                  //�����Ļ��Ϣ


    cout << " ���м�¼ " << iDataCount << "  ";
    cout << " ����ҳ�� " << iPage << "  ";
    cout << " ��ǰҳ�� " << iCurPage << "  ";
    cout << " n ��һҳ r ����"  << endl;
    cout << setw(5) << "Index";
    cout << setw(22) << "Name" << setw(22) << "ISBN" ;
    cout << setw(15) << "Price" << setw(15) << "Author";
    cout << endl;
    try{
        // ����ͼ���¼��Ų������ļ��е�λ�á�
        ifile.seekg((iCurPage - 1) * 20 * (NUM1 + NUM2 + NUM1 + NUM2), ios::beg);
        if(!ifile.fail())
        {
            for(int i = 1; i<21;i++)
            {
                memset(inName, 0, 128);               // ����������
                memset(inISBN, 0,  128);
                memset(inAuthor,0, 50);
                memset(inPrice, 0, 50);
                if(bIndex)
                    cout << setw(3) << ((iCurPage - 1) * 20 + i);

                ifile.read(inName, NUM1);              //��ȡͼ������
                cout << setw(24) << inName;
                ifile.read(inISBN, NUM1);              //��ȡͼ��ISBN
                cout << setw(24) << inISBN;
                ifile.read(inPrice, NUM2);              //��ȡͼ��۸�
                cout << setw(12) << inPrice;
                ifile.read(inAuthor, NUM1);              //��ȡͼ������
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
        throw "file error occurred";                // �׳��쳣
        ifile.close();                              // �ر��ļ���
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


// ɾ��ͼ��ģ��
void DeleteBookFromFile() {
    int iDelCount;
    cout << "Input delete index" << endl;
    cin >> iDelCount;
    cBook tmpBook;
    tmpBook.DeleteData(iDelCount);
    cout << "Delete Finish" << endl;
    WaitUser();
}