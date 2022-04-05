//
// Created by yw980 on 2022/4/5.
//

#ifndef C_PLUS_CREADER_H
#define C_PLUS_CREADER_H
#include "CBook.h"
#include "CUser.h"
using namespace std;


class CReader : public CUser{
private:
    bool is_Exist;          // trueΪ�û�����
    bool is_Borrow;         // trueΪ�����
    CBook brBook;           // �������������
public:
    CReader();
    CReader(int readerID, string readerName);
    bool get_isExist();     // ��ȡ���ߴ��ڱ�־
    void set_isExist(bool isExist);     // ���ô��ڱ�־
    bool get_isBorrow();    // ��ȡ���߽������
    void set_isBorrow();    // ���ö��߽������
    void setBrBook(CBook br);    // ��¼���߽�����Ϣ
    CBook getBrBook();          // ������ȡ���߽�����Ϣ��
    void show();                // ��ʾ���ߵĻ�������ͽ������
};


#endif //C_PLUS_CREADER_H
