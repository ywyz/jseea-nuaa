//
// Created by yw980 on 2022/4/4.
//

#ifndef C_PLUS_CUSER_H
#define C_PLUS_CUSER_H
#include "string"
using namespace std;

class CUser {
protected:
    int userID;                     // �����û����
    string userName;                //  �����û���
public:
    CUser();                        // Ĭ�Ϲ��캯��
    CUser(int uID, string na);      // ��ʼ���û���Ϣ
    void setUserID(int n);          // �����û����
    int getUserId();           // ��ȡ�û����
    void setUserName(string name);  // �����û���
    string getUserName();           // ��ȡ�û���
    void show();                    // ��ʾ�û���Ϣ
};


#endif //C_PLUS_CUSER_H
