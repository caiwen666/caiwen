#include<iostream>
#include<cstring>
using namespace std;

struct Node{
    bool leaf;
    char code;
    int left,right;
} tree[27];

int root;

int n;

void _print(int x){
    if(x==-1) return;
    cout<<tree[x].code;
    _print(tree[x].left);
    _print(tree[x].right);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){//build
        
        string opt;
        cin>>opt;

        if(i==0) root=opt[0]-'a';

        tree[opt[0]-'a'].code=opt[0];

        if(opt[1]=='*') tree[opt[0]-'a'].left=-1;
        else tree[opt[0]-'a'].left=opt[1]-'a';

        if(opt[2]=='*') tree[opt[0]-'a'].right=-1;
        else tree[opt[0]-'a'].right=opt[2]-'a';
        
    }

    _print(root);

    return 0;
}