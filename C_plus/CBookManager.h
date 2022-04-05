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
    vector <CBook> bkarray;         // ʹ�������洢ͼ����Ϣ
public:
    CBookManager();
    ~CBookManager();
    void addBook(CBook book);       // ���ͼ��
    int findBook(string bookName);  // ͨ��ͼ�����ֲ���ͼ��
    int findBook(int bookID);       // ͨ��ͼ���Ų���ͼ��
    CBook getBook(int subscript);   // ͨ����ŷ���ͼ����Ϣ
    void editBook(int subscript, CBook book);   //�༭ͼ��
    void editBook(int subscript, int bookID);   //�༭ͼ����
    void editBook(int subscript, string bookName);   //�༭ͼ������
    void editBook(int subscript, bool isOnShelf);   //�༭ͼ���ڼ����
    void delBook(int subscript);    //ɾ��ͼ��
    void listBooks();               // ��ʾȫ��ͼ��
    void save(string filename = "books.db");        // ���浽�ļ�
    void load(string filename = "books.db");        //��ȡ�ļ�

};


#endif //JSEEA_NUAA_CBOOKMANAGE_H
