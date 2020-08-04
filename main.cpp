#include <io.h>		//_finddata_t的头文件
#include <iostream>
#include <cstring>
#include <regex>
#include <fstream>
#include <windows.h>
using namespace std;
inline bool exists(const string& name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}
void findAllFile(const char * path,const char * format,const char * filename,int & num)
{
    string newpath=path;
    regex m_format(".*\\."+(string)format);
    newpath += "\\*.*";    // 在目录后面加上"\\*.*"进行第一次搜索
    intptr_t handle;
    _finddata_t findData;
    handle = _findfirst(newpath.c_str(), &findData);
    if (handle == -1)        // 检查是否成功
        return;
     while (_findnext(handle, &findData) == 0){
        if (findData.attrib & _A_SUBDIR){
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;
            newpath = path;
            newpath += "\\";
            newpath += findData.name;
            findAllFile(newpath.c_str(),format,filename,num);
        }
        else{
            if(regex_match(findData.name,m_format)&&348156==findData.size){
                ++num;     //判断是不是指定类型文件，数字是同名文件夹病毒的大小
                ofstream output(filename,ios::out|ios::app);
                output << path << findData.name << endl;
                output.close();
            }
        }
    }
    _findclose(handle);    // 关闭搜索句柄
}

int main()
{
    string driver;
    int i,j=0;
    cout << "请输入要筛查的文件夹（若是整个磁盘请输入盘符）：";
    getline(cin,driver);
    if(1==driver.length())driver += ":";
    for(i=1;exists("result"+to_string(i)+".txt");++i);
    findAllFile(driver.c_str(),"exe",("result"+to_string(i)+".txt").c_str(),j);
    if(j){
        cout << "发现疑似同名文件夹病毒" << j << "个" << endl;
        cout << "相应文件全路径已输出到本程序目录下的" << "result"+to_string(i)+".txt" << "文件" << endl;
    }
    else{cout << "未发现疑似同名文件夹的文件" << endl;}
    system("pause");
    return 0;
}
