#include<iostream>
#include<map>
#include<unordered_map>
#include<cstdio>
using namespace std;

unordered_map<int,int> ds;

inline int read()
{
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

int main(){
    int t;
    t=read();
    for(int i=0;i<t;i++){
        int n=read();
        ds.clear();
        for(int j=0;j<n;j++){
            int now=read();
            if(ds.find(now)!=ds.end()) continue;
            ds[now]++;
            printf("%d ",now);
        }
        puts("");
    }
    return 0;
}