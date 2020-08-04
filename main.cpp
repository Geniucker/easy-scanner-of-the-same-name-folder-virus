#include <io.h>		//_finddata_t��ͷ�ļ�
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
    newpath += "\\*.*";    // ��Ŀ¼�������"\\*.*"���е�һ������
    intptr_t handle;
    _finddata_t findData;
    handle = _findfirst(newpath.c_str(), &findData);
    if (handle == -1)        // ����Ƿ�ɹ�
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
                ++num;     //�ж��ǲ���ָ�������ļ���������ͬ���ļ��в����Ĵ�С
                ofstream output(filename,ios::out|ios::app);
                output << path << findData.name << endl;
                output.close();
            }
        }
    }
    _findclose(handle);    // �ر��������
}

int main()
{
    string driver;
    int i,j=0;
    cout << "������Ҫɸ����ļ��У��������������������̷�����";
    getline(cin,driver);
    if(1==driver.length())driver += ":";
    for(i=1;exists("result"+to_string(i)+".txt");++i);
    findAllFile(driver.c_str(),"exe",("result"+to_string(i)+".txt").c_str(),j);
    if(j){
        cout << "��������ͬ���ļ��в���" << j << "��" << endl;
        cout << "��Ӧ�ļ�ȫ·���������������Ŀ¼�µ�" << "result"+to_string(i)+".txt" << "�ļ�" << endl;
    }
    else{cout << "δ��������ͬ���ļ��е��ļ�" << endl;}
    system("pause");
    return 0;
}
