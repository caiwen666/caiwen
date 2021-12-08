#include<iostream>
#include<map>
#include<cstring>
using namespace std;

map<string,int> ds;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int opt;
        cin>>opt;
        if(opt==4){
            cout<<ds.size()<<endl;
            continue;
        } 
        string name;
        cin>>name;
        if(opt==1){
            int score;
            cin>>score;
            ds[name]=score;
            cout<<"OK"<<endl;
            continue;
        }
        if(ds.find(name)==ds.end()){
            cout<<"Not found"<<endl;
            continue;
        }
        if(opt==2){
            cout<<ds[name]<<endl;
        }
        if(opt==3){
            ds.erase(name);
            cout<<"Deleted successfully"<<endl;
        }
    }
    return 0;
}