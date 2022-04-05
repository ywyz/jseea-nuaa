//
// Created by yw980 on 2022/4/4.
//

#ifndef C_PLUS_CUSER_H
#define C_PLUS_CUSER_H
#include "string"
using namespace std;

class CUser {
protected:
    int userID;                     // 定义用户编号
    string userName;                //  定义用户名
public:
    CUser();                        // 默认构造函数
    CUser(int uID, string na);      // 初始化用户信息
    void setUserID(int n);          // 设置用户编号
    int getUserId();           // 获取用户编号
    void setUserName(string name);  // 设置用户名
    string getUserName();           // 获取用户名
    void show();                    // 显示用户信息
};


#endif //C_PLUS_CUSER_H
