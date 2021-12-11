#include<iostream>
using namespace std;

string a,b;
int p;

void build(string middle,string before){
    if(middle.size()>0){
        char root=before[0];
        int k=middle.find(root);
        build(middle.substr(0,k),before.substr(1,k));
        build(middle.substr(k+1),before.substr(k+1));
        cout<<root;
    }
}

void build(char code,int l1,int l2,int r1,int r2){
    //always complete the left
    //build left
    p++;
    if(l2-l1!=0){
        build(b[p],l1,a.find(b[p]),a.find(b[p]),l2-1);
    }
    if(r2-r1!=0){
        build(b[p],r1+1,a.find(b[p]),a.find(b[p]),r2);
    }
    //build right
    //print this
    cout<<code;

}

int main(){
    cin>>a>>b;
    p=0;
    build(a,b);
    //build(b[0],0,a.find(b[0]),a.find(b[0]),a.size()-1);
    return 0;
}