//
// Created by yw980 on 2022/4/15.
//

#ifndef C_PLUS_STUDENTSINFO_H
#define C_PLUS_STUDENTSINFO_H
#include <string>
using namespace std;


class StudentsInfo {
private:
    string studentName;         // 学生姓名
    long studentID;              // 学号
    char studentSex;         // 学生性别，男或女，理论上来说只要两个字符空间
    int studentAge;             // 学生年龄
    float averageGrade;         // 平均分

public:
    StudentsInfo(string sName, long sID, char Sex, int sAge, float AverageAge);      //  初始化学生信息
    void setName(string Name); // 设置学生姓名
    string getName(void);       // 获取学生姓名
    void setID(long id);         // 设置学号
    long getID(void);            // 获取学号
    void setSex(char sex);      // 设置学生性别
    char getSex(void);          // 获取学生性别
    void setAge(int age);       // 设置学生年龄
    int getAge(void);           // 获取学生年龄
    void setGrade(float grade); // 设置学生平均分
    float getGrade(void);       // 获取学生平均分
    void showInfo();            // 显示学生信息
    void writeStuInfo();        // 将学生信息写入文件
    void readStuInfo();         // 从文件读取信息
};


#endif //C_PLUS_STUDENTSINFO_H
