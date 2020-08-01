#include<iostream>
using namespace std;
int n,a[100],minn;
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
	for(int i=0;i<n-1;i++)
	{
		minn=i;
		for(int j=i+1;j<n;j++)
		if(a[j]<a[minn])
		minn=j;
		if(minn!=i)
		swap(a[i],a[minn]);
	}
	xuat(a,n);
}