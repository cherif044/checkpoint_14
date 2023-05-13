#ifndef FILE_H
#define FILE_H
using namespace std;
#include <fstream>

class File
{
public:
    File();
};

#endif // FILE_H
class file {
private:
    ifstream file_x, file_y;

public:

    virtual void readFile() = 0;
    ifstream&  getFile_x();
    ifstream&  getFile_y();
    void setFile_x(string fileName);
    void setFile_y(string fileName);
    bool isfilexopen();
    bool isfileyopen();
};
