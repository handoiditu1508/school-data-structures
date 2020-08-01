#include<iostream>
using namespace std;
int n,a[100],x;
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
	cout<<"nhap so can tim: ";
	cin>>x;
	a[n]=x;
	int i=0;
	while(a[i]!=x)i++;
	if(i==n)
	cout<<"khong tim thay"<<endl;
	else cout<<x<<" nam o vi tri thu "<<i<<endl;
}