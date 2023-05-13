#include "file.h"
using namespace std;
#include <iostream>>
File::File()
{

}
ifstream& file::getFile_x()
{
    return file_x;
}
ifstream& file:: getFile_y()
{
    return file_y;
}
void file::setFile_x(string fileName)
{
    file_x.open( fileName );

}
void file::setFile_y(string fileName)
{
    file_y.open(fileName);
}
bool file::isfilexopen()
{
    if(!file_x.is_open())
        return false;
    else
        return true;
}
bool file::isfileyopen()
{
    if(!file_y.is_open())
        return false;
    else
        return true;
}
