//
// Created by yw980 on 2022/4/4.
//

#ifndef C_PLUS_CUSER_H
#define C_PLUS_CUSER_H
#include "string"
using namespace std;

class CUser {
protected:
    int userID;                     //  用户编号
    string userName;                //  用户姓名
public:
    CUser();                        // 默认构造函数
    CUser(int uID, string na);      // 初始化用户信息
    void setUserID(int n);          // 设置用户编号
    int getUserId();           // 获取用户编号
    void setUserName(string name);  // 设置用户名称
    string getUserName();           // 获取用户名称
    void show();
};


#endif //C_PLUS_CUSER_H
