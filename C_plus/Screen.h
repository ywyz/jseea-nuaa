//
// Created by yw980 on 2022/3/26.
// ����ģ�����
//


#include "string"
#include "iostream"
#include "iomanip"
#include "Book.h"


// ͨ��system����ִ��mode���������ʾ��Ϣ��������������������ɫ�ȡ�
void SetScreenGrid(int cols, int lines);
//���ÿ���̨�ı���
void SetSysCaption();


//����
void ClearScreen();

//��ʾͼ�����ϵͳ�Ļ�ӭ��Ϣ
void ShowWelcome();

// ��ʾϵͳ���˵�
void ShowRootMenu();

// ����������ĳһģ��󣬵ȴ��û����д���
void WaitUser();


int GetSelect();
// ��ѭ��
void mainloop();
