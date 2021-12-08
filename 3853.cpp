#include<iostream>
#include<cstdio>
using namespace std;

int ll,n,k,arr[100001];

bool check(int x){
    int tot=0;
    for(int i=2;i<=n;i++){
        int d=arr[i]-arr[i-1];
        if(d>x){
            if(d%x==0)
                tot+=d/x-1;
            else   
                tot+=d/x;
        }
    }
    return tot<=k;
}

int main(){
    scanf("%d%d%d",&ll,&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    int l=0,r=ll,mid,ans=-1;
    while(l<=r){
        if(check(mid=l+(r-l)/2))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    cout<<ans;
    return 0;
}