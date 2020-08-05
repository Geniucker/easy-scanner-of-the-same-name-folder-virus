#include <io.h>		//_finddata_t的头文件
#include <iostream>
#include <cstring>
#include <regex>
#include <fstream>
#include <windows.h>
using namespace std;
inline bool exists(const string& name) {           //判断文件是否存在
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
                output << path << "\\" << findData.name << endl;
                output.close();
            }
        }
    }
    _findclose(handle);    // 关闭搜索句柄
}
vector<string> findFile(const char * path,const char * format)
{
    vector<string> result;
    string newpath=path;
    regex m_format("^result\\d+\\."+(string)format+"$");
    newpath += "\\*.*";
    intptr_t handle;
    _finddata_t findData;
    handle = _findfirst(newpath.c_str(), &findData);
    if (handle == -1)        // 检查是否成功
        return {};
    while (_findnext(handle, &findData) == 0){
        if(regex_match(findData.name,m_format)){
                result.push_back(findData.name);
            }
    }
    return result;
}

string getCmdResult(const char* cmd)  
{
	FILE *file;
	char ptr[1024] = { 0 };
	char tmp[1024] = { 0 };
	strcat_s(ptr, cmd);
	string result = "";
	if ((file = _popen(ptr, "r")) != NULL)
	{
		while (fgets(tmp, 1024, file) != NULL){
			result = result + tmp;
		}
		_pclose(file);
	}
	return result;
}