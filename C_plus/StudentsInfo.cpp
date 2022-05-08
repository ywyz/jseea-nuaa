//
// Created by yw980 on 2022/4/15.
//

#include "StudentsInfo.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
StudentsInfo::StudentsInfo(string sName, long sID, char Sex, int sAge) {
    studentName = sName;
    studentAge = sAge;
    studentID = sID;
    studentSex = Sex;
}

int StudentsInfo::getAge() {
    return studentAge;
}
void StudentsInfo::setAge(int age) {
    studentAge = age;
}

void StudentsInfo::setName(string Name) {
    studentName = Name;
}

string StudentsInfo::getName() {
    return studentName;
}

long StudentsInfo::getID() {
    return studentID;
}

void StudentsInfo::setSex(char sex) {
    studentSex = sex;
}

char StudentsInfo::getSex() {
    return studentSex;
}

void StudentsInfo::setID(long ID){
    studentID = ID;
}

void StudentsInfo::showInfo() {
    cout << "学生姓名：" << studentName << endl;
    cout << "学号： " << studentID << endl;
    cout << "性别： " << studentSex << endl;
    cout << "年龄： " << studentAge << endl;
}

void writeStuInfo(){
    int i;          //没看懂干嘛的
    ofstream  outFile("Student.dat", ios::out);

    if (!outFile)
    {
        cerr << "文件不存在，打开文件失败！"  << endl;
        exit(1);
    }


}