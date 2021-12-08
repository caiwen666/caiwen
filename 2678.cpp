#include<iostream>
using namespace std;
int s,n,m,arr[50002];

bool check(int x){
    int last=0,tot=0,p=1;
    while(p<=n+1){
        while(arr[p]-arr[last]<x&&p<=n+1) p++,tot++;
        if(p>n+1) return false;
        last=p;
        p++;
    }
    return tot<=m;
}

int main(){
    cin>>s>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    arr[n+1]=s;
    int l=0,r=s,mid,ans=-1;

    cout<<check(4)<<endl;

    while(l<=r){
        if(check(mid=l+(r-l)/2))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    cout<<ans;
    return 0;
}