//
// Created by yw980 on 2022/4/4.
//

#ifndef CBOOK_H
#define CBOOK_H
#include <string>
using namespace std;
class CBook {
private:
    int bookID;             // ͼ����
    string bookName;    // ͼ������
    bool isOnShelf;     // trueΪ�ڼܣ� falseΪ���
    bool isExist;       // trueΪ���ڣ�falseΪɾ��
public:
    CBook();            // Ĭ�Ϲ��캯��
    CBook(int bID, string name);     // ��ʼ��ͼ����Ϣ
    void setID(int n);                  // ����ͼ����
    int getID();                        // ��ȡͼ����
    void setName(string name);          // ����ͼ������
    string getName();                   // ��ȡͼ������
    bool getIsOnShelf();                // ��ȡͼ���Ƿ��ڿ�
    void setIsOnShelf(bool is);         // ����ͼ���Ƿ��ڿ�
    bool getIsExist();                  // ��ȡͼ���Ƿ����
    void setIsExist(bool is);           // ����ͼ���Ƿ����
    void show();
};


#endif //C_PLUS_CBOOK_H
