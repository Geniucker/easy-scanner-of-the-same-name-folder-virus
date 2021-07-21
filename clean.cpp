#include "dep.h"

int main()
{
    vector<string> prob(findFile(".","txt"));
    int num = prob.size(),choose,total=0,success=0;
    string get,tem;
    smatch m;
    if(!num){
        cout << "未搜索到result+数字.txt文件，请先运行scan程序" << endl;
        system("pause");
        return 0;
    }
    cout << "找到如下配置文件：" << endl;
    for(int i=0;i<num;++i){
        cout << i+1 << ":\t" << prob[i] <<endl;
    }
    cout << "请选择要使用的配置文件（仅输入数字序号）：";
    while(true){
        getline(cin,tem);
        try{
            if(regex_match(tem,regex(R"(.*\..*)")))throw ERROR;
            if(stoi(tem)<1||stoi(tem)>num)throw ERROR;
            break;
        }
        catch(...){
            cout << "请输入正确的序号：";
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
    cout << "共" << total << "个，成功删除" << success << "个" <<endl;
    system("pause");
    return 0;
}