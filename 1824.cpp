#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001],n,c;

bool check(int x){
    int last=1;
    for(int i=2;i<=c;i++){
        int now=last+1;
        while(arr[now]-arr[last]<x&&now<=n) now++;
        if(now>n) return false; 
        else last=now;
    }
    return true;
}

int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int l=0,r=arr[n]-arr[1],ans=0,mid;
    //cout<<check(3);
    while(l<=r){
        if(check(mid=l+(r-l)/2))
            ans=mid,l=mid+1;
        else 
            r=mid-1;
    }
    cout<<ans;
    return 0;
}