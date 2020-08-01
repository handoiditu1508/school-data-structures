#include<iostream>
using namespace std;
int n,a[100],q,w;
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
int main()
{
	nhap(a,n);
	q=0,w=n-1;
	zzz:
	if(q!=w)
	{
		for(int i=q;i<w;i++)
		if(a[i]>a[i+1])
		swap(a[i],a[i+1]);
		w--;
	}
	else goto sss;
	if(q!=w)
	{
		for(int i=w;i>q;i--)
		if(a[i]<a[i-1])
		swap(a[i],a[i-1]);
		q++;
		goto zzz;
	}
	sss:;
	xuat(a,n);
}