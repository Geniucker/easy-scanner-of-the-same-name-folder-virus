#include "dep.h"

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
