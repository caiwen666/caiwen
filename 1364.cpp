#include <iostream>
using namespace std;

struct Node{
    int right,left,w;
} tree[101];

int dis[101][101];//the shortest distance from a to b

inline void put(int id,int l,int r,int w){
    //build
    tree[id].right=r;
    tree[id].left=l;
    tree[id].w=w;
    //distance
    dis[id][l]=1;
    dis[l][id]=1;
    dis[id][r]=1;
    dis[r][id]=1;
    dis[id][id]=0;
}

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[i][j]=100000;
    }

    for(int i=1;i<=n;i++){
        int w,l,r;
        cin>>w>>l>>r;
        put(i,l,r,w);
    }
    
    for(int i=1;i<=n;i++){//i is the agent
        for(int j=1;j<=n;j++){//j is a choice
            for(int k=1;k<=n;k++){//k is another choice
                if(dis[j][k]>dis[i][k]+dis[i][j]){
                    dis[j][k]=dis[i][k]+dis[i][j];
                    dis[k][j]=dis[i][k]+dis[i][j];
                }
            }
        }
    }

    long long ans=-1;

    for(int i=1;i<=n;i++){
        long long tmp=0;
        for(int j=1;j<=n;j++){
            tmp+=dis[i][j]*tree[j].w;
        }
        if(tmp<ans||ans==-1) ans=tmp;
    }
    
    cout<<ans;
    return 0;
}