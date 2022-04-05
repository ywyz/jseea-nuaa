//
// Created by yw980 on 2022/4/5.
//

#ifndef C_PLUS_CREADERMANAGER_H
#define C_PLUS_CREADERMANAGER_H
#include <vector>
#include <string>
#include "CReader.h"
using namespace std;

class CReaderManager {
private:
    vector<CReader> rdArray;        // ʹ�������洢������Ϣ

public:
    CReaderManager();
    ~CReaderManager();
    CReader getReader(int subscript);
    void addReader(CReader reader);         // ��Ӷ���
    int findReader(string readerName);      // ͨ���������ֲ��Ҷ���
    int findReader(int readerID);           // ͨ�����߱�Ų��Ҷ���
    int findReader(CBook book);             // ͨ�������鼮���Ҷ���
    void editReader(int subscript, CReader reader);// �༭������Ϣ
    void editReader(int subscript, string readerName);// �༭������
    void editReader(int subscript, int readerID);// �༭���߱��
    void editReader(int subscript,bool is_Borrow);// �༭���߽����־
    void delReader(int subscript);           // ɾ������
    void listReaders();                      // ��ʾ���ж���
    void save(string filename = "readers.db"); // ���浽�ļ�
    void load(string filename = "readers.db"); // ���ļ���ȡ
};


#endif //C_PLUS_CREADERMANAGER_H
