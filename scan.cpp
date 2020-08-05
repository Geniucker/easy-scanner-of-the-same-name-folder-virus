#include "dep.h"

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
