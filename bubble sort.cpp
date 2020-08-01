#include<iostream>
using namespace std;
int n,a[100],q;
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
	q=n-2;
	while(q)
	{
		for(int i=0;i<=q;i++)
		if(a[i]>a[i+1])
		swap(a[i],a[i+1]);
		q--;
	}
	xuat(a,n);
}