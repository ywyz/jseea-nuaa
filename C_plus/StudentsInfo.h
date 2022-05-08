//
// Created by yw980 on 2022/4/15.
//

#ifndef C_PLUS_STUDENTSINFO_H
#define C_PLUS_STUDENTSINFO_H
#include <string>
using namespace std;


class StudentsInfo {
private:
    string studentName;         // ѧ������
    long studentID;              // ѧ��
    char studentSex;         // ѧ���Ա��л�Ů����������˵ֻҪ�����ַ��ռ�
    int studentAge;             // ѧ������

public:
    StudentsInfo(string sName, long sID, char Sex, int sAge);      //  ��ʼ��ѧ����Ϣ
    void setName(string Name); // ����ѧ������
    string getName(void);       // ��ȡѧ������
    void setID(long id);         // ����ѧ��
    long getID(void);            // ��ȡѧ��
    void setSex(char sex);      // ����ѧ���Ա�
    char getSex(void);          // ��ȡѧ���Ա�
    void setAge(int age);       // ����ѧ������
    int getAge(void);           // ��ȡѧ������

    void showInfo();            // ��ʾѧ����Ϣ
    void writeStuInfo();        // ��ѧ����Ϣд���ļ�
    void readStuInfo();         // ���ļ���ȡ��Ϣ
};


#endif //C_PLUS_STUDENTSINFO_H
