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

void StudentsInfo::writeStuInfo(){

    ofstream  outFile("Student.dat", ios::out);

    if (!outFile)
    {
        cerr << "文件不存在，打开文件失败！"  << endl;
        exit(1);
    }
    outFile << studentID << " ";
    outFile << studentName << " ";
    outFile << studentAge << " ";
    outFile << studentSex << " ";
    outFile << endl;
    outFile.close();
    cout << endl;
    cout << "----数据已成功保存----";
}

void StudentsInfo::readStuInfo() {
    fstream readFile("Student.dat");        // 打开文件操作
    int rows = 0;
    if (!readFile)                             // 判断文件是否存在
    {
        cerr << "文件不存在，打开文件失败！"  << endl;
        exit(1);
    }
    
}