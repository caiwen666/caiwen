#include<iostream>
#include<cstring>
using namespace std;

void build(string middle,string after){
    if(middle.size()>0){
        char root=after[after.size()-1];
        cout<<root;
        int k=middle.find(root);
        build(middle.substr(0,k),after.substr(0,k));
        build(middle.substr(k+1),after.substr(k,middle.size()-k-1));
    }
}

int main(){
    string middle,after;
    cin>>middle>>after;
    build(middle,after);
    return 0;
}