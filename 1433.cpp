#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN=16;

double ans=-1; 

int n;
struct Point{
	double x,y;
} arr[MAXN],use[MAXN];
bool lock[MAXN];

double getDis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void push(){
	Point last={0,0};
	double tot=0;
	for(int i=1;i<=n;i++){
		Point now=use[i];
		tot+=getDis(now,last);
		last=now;
	}
	if(tot<ans||ans==-1) ans=tot;
	//cout<<"push"<<tot<<endl;
}

void search(int x){
	for(int i=1;i<=n;i++){
		if(!lock[i]){
			lock[i]=true;
			use[x]=arr[i];
			if(x==n) push();
			else search(x+1);
			lock[i]=false;
		}
	}
}

int main(){
	
	//cout<<getDis({0,0},{1,1});
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i].x>>arr[i].y;
	search(1);
	printf("%0.2lf",ans);
	return 0;
}
