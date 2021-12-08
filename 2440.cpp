#include<iostream>
#include<cstdio>
using namespace std;

int n,k,arr[100001];

bool check(int x){
    int tot=0;
    for(int i=1;i<=n;i++){
        tot+=arr[i]/x;
    }
    return tot>=k;
}


int main(){
    scanf("%d%d",&n,&k);
    long long sum1=0;
    long long sum2=0;
    bool flag1=false;
    bool flag2=false;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        if(!flag1){
            sum1+=arr[i];
            if(sum1>k) flag1=true;
        }
        if(!flag2) sum2+=arr[i];
        if(!flag2&&sum2>100000000) flag2=true;
    }
    if(!flag1){
        cout<<"0";
        return 0;
    }
    int ans,l=1,r=flag2? 100000000:sum2,mid;
    while(l<=r){
        if(check(mid=l+(r-l)/2))
            ans=mid,l=mid+1;
        else   
            r=mid-1;
    }
    cout<<ans;
    return 0;
}