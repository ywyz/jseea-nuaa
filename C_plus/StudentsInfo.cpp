//
// Created by yw980 on 2022/4/15.
//

#include "StudentsInfo.h"
#include <iostream>
#include <string>

using namespace std;
StudentsInfo::StudentsInfo(string sName, long sID, char Sex, int sAge, float AverageAge) {
    studentName = sName;
    studentAge = sAge;
    studentID = sID;
    studentSex = Sex;
    averageGrade = AverageAge;
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

void StudentsInfo::setID(long ID){
    studentID = ID;
}

void StudentsInfo::setGrade(float grade) {
    averageGrade = grade;
}

float StudentsInfo::getGrade() {
    return averageGrade;
}

void StudentsInfo::showInfo() {
    cout << "学生姓名：" << studentName << endl;
    cout << "学号： " << studentID << endl;
    cout << "性别： " << studentSex << endl;
    cout << ""
}