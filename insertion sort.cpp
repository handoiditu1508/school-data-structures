#include<iostream>
using namespace std;
int n,a[100];
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
	for(int i=1;i<n;i++)
	{
		int t=i;
		for(int j=i-1;j>=0;j--)
		if(a[t]<a[j])
		swap(a[t--],a[j]);
		else break;
	}
	xuat(a,n);
}