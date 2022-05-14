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
    cout << "ѧ��������" << studentName << endl;
    cout << "ѧ�ţ� " << studentID << endl;
    cout << "�Ա� " << studentSex << endl;
    cout << "���䣺 " << studentAge << endl;
}

void StudentsInfo::writeStuInfo(){

    ofstream  outFile("Student.dat", ios::out);

    if (!outFile)
    {
        cerr << "�ļ������ڣ����ļ�ʧ�ܣ�"  << endl;
        exit(1);
    }
    outFile << studentID << " ";
    outFile << studentName << " ";
    outFile << studentAge << " ";
    outFile << studentSex << " ";
    outFile << endl;
    outFile.close();
    cout << endl;
    cout << "----�����ѳɹ�����----";
}

void StudentsInfo::readStuInfo() {
    fstream readFile("Student.dat");        // ���ļ�����
    int rows = 0;
    if (!readFile)                             // �ж��ļ��Ƿ����
    {
        cerr << "�ļ������ڣ����ļ�ʧ�ܣ�"  << endl;
        exit(1);
    }
    
}