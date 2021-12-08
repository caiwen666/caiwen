#include<iostream>
using namespace std;

string a,b;

struct Node{
    char a='\\';
    bool leaf=false; 
    int il=-1,ir=-1;
    string sleft,sright;    
} arr[27];

int ch2node[27];

void _print(int i){
    if(arr[i].il!=-1) _print(arr[i].il);
    if(arr[i].ir!=-1) _print(arr[i].ir);
    cout<<arr[i].a;
}



int main(){
    
    cin>>a>>b;
    


    _print(1);

    return 0;
}