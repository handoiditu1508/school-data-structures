#include<iostream>
#include<queue>
using namespace std;
struct arr
{
	int left,right;
};
arr q;
queue<arr>que;
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
int qksort(int a[],arr q)
{
	int pivot=a[(q.left+q.right)/2];
	while(q.left<q.right)
	{
		while(a[q.left]<pivot)q.left++;
		while(a[q.right]>pivot)q.right--;
		if(q.left<q.right)
		swap(a[q.left++],a[q.right--]);
	}
	if(a[q.left]>pivot)q.left--;
	return q.left;
}
int main()
{
	nhap(a,n);
	q.left=0,q.right=n-1,que.push(q);
	while(!que.empty())
	{
		int w=qksort(a,que.front());
		if(que.front().left<w)
		q.left=que.front().left,q.right=w,que.push(q);
		if(que.front().right>++w)
		q.left=w,q.right=que.front().right,que.push(q);
		que.pop();
	}
	xuat(a,n);
}