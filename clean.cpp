#include "dep.h"

int main()
{
    vector<string> prob(findFile(".","txt"));
    int num = prob.size(),choose,total=0,success=0;
    string get,tem;
    smatch m;
    if(!num){
        cout << "δ������result+����.txt�ļ�����������scan����" << endl;
        system("pause");
        return 0;
    }
    cout << "�ҵ����������ļ���" << endl;
    for(int i=0;i<num;++i){
        cout << i+1 << ":\t" << prob[i] <<endl;
    }
    cout << "��ѡ��Ҫʹ�õ������ļ���������������ţ���";
    while(true){
        getline(cin,tem);
        try{
            if(regex_match(tem,regex(R"(.*\..*)")))throw ERROR;
            if(stoi(tem)<1||stoi(tem)>num)throw ERROR;
            break;
        }
        catch(...){
            cout << "��������ȷ����ţ�";
        }
    }
    choose = stoi(tem);
    string getPro = getCMD("tasklist");
    ifstream input(prob[choose-1],ios::in);
    while(!input.eof()){
        getline(input,get);
        if(""!=get){
            ++total;
            regex_search(get,m,regex(R"(([^<>/\\\|:""\*\?]+)\.\w+$)"));
            tem = string(m[0]);
            for(int i=0;i<tem.size();++i){
                if(tem[i]=='$'||tem[i]=='('||tem[i]==')'||tem[i]=='+'||tem[i]=='.'||tem[i]=='['||tem[i]==']'||tem[i]=='^'||tem[i]=='{'||tem[i]=='}'){
                    tem = tem.substr(0,i)+"\\"+tem.substr(i);
                    i=i+1;
                }
            }
            if(regex_search(getPro,regex(tem)))system(("taskkill /im \""+string(m[0])+"\" /f").c_str());
            system("cls");
            if(!remove(get.c_str()))++success;
        }
    }
    input.close();
    cout << "��" << total << "�����ɹ�ɾ��" << success << "��" <<endl;
    system("pause");
    return 0;
}