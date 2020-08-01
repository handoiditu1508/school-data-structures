#include<iostream>
#include<queue>
using namespace std;
int n,a[100];
queue<int>que;
void nhap(int a[],int &n)
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
}
void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
void heap(int q,int n)
{
	int maxx=q,le=q*2+1,ri=q*2+2;
	if(le<n)
	if(a[le]>a[maxx])
	maxx=le;
	if(ri<n)
	if(a[ri]>a[maxx])
	maxx=ri;
	if(maxx!=q)swap(a[q],a[maxx]),que.push(maxx);
}
void heapsort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heap(i,n);
		while(!que.empty())
		heap(que.front(),n),que.pop();
	}
	while(n>1)
	{
		swap(a[0],a[--n]);
		heap(0,n);
		while(!que.empty())
		heap(que.front(),n),que.pop();
	}
}
int main()
{
	nhap(a,n);
	heapsort(a,n);
	xuat(a,n);
}