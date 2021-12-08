#include<iostream>
using namespace std;

int arr[1000001],n,m;

bool check(int h){
    long long tot=0;
    for(int i=1;i<=n;i++){
        if(arr[i]>h)
            tot+=arr[i]-h;
    }
    return tot>=m;
}

int main(){
    int l=0,r=0,ans,mid;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(r==0||arr[i]>r){
            r=arr[i];
        }
    } 
    while(l<=r){
        if(check(mid=l+(r-l)/2))
            ans=mid,l=mid+1;
        else   
            r=mid-1;
    }
    cout<<ans;
    //system("pause");
    return 0;
}