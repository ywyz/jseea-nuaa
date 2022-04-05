//
// Created by yw980 on 2022/4/5.
//

#ifndef C_PLUS_CREADERMANAGER_H
#define C_PLUS_CREADERMANAGER_H
#include <vector>
#include <string>
#include "CReader.h"
using namespace std;

class CReaderManager {
private:
    vector<CReader> rdArray;        // 使用容器存储读者信息

public:
    CReaderManager();
    ~CReaderManager();
    CReader getReader(int subscript);
    void addReader(CReader reader);         // 添加读者
    int findReader(string readerName);      // 通过读者名字查找读者
    int findReader(int readerID);           // 通过读者编号查找读者
    int findReader(CBook book);             // 通过借阅书籍查找读者
    void editReader(int subscript, CReader reader);// 编辑读者信息
    void editReader(int subscript, string readerName);// 编辑读者名
    void editReader(int subscript, int readerID);// 编辑读者编号
    void editReader(int subscript,bool is_Borrow);// 编辑读者借书标志
    void delReader(int subscript);           // 删除读者
    void listReaders();                      // 显示所有读者
    void save(string filename = "readers.db"); // 保存到文件
    void load(string filename = "readers.db"); // 从文件读取
};


#endif //C_PLUS_CREADERMANAGER_H
