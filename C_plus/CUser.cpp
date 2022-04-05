//
// Created by yw980 on 2022/4/4.
//

#include "CUser.h"
#include <string>
#include <iostream>
using namespace std;

CUser::CUser() {
    userID = 0;
    userName = "unnamed";
}

CUser::CUser(int uID, string na) {
    userID = uID;
    userName = na;
}

void CUser::setUserID(int n) {
    userID = n;
}

int CUser::getUserId() {
    return userID;
}

void CUser::setUserName(string name) {
    userName = name;
}

string CUser::getUserName() {
    return userName;
}

void CUser::show() {
    cout << "ÐÕÃû£º " << userName << "±àºÅ£º " << userID << endl;
}