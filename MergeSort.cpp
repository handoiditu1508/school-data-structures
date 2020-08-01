#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct arr
{
	int left,right;
};
int n,a[100];
void mergesort(int a[],int n)
{
	int b[100],mid;
	arr q;
	queue<arr>que;
	stack<arr>sta;
	q.left=0,q.right=n-1;
	que.push(q);
	while(!que.empty())
	{
		if(que.front().left!=que.front().right)
		{
			mid=(que.front().left+que.front().right)/2;
			q.left=que.front().left;
			q.right=mid;
			que.push(q);
			sta.push(q);
			q.left=mid+1;
			q.right=que.front().right;
			que.push(q);
			sta.push(q);
		}
		que.pop();
	}
	int o,i,j;
	while(!sta.empty())
	{
		q=sta.top();
		sta.pop();
		o=sta.top().left;
		i=sta.top().left;
		j=q.left;
		while(i<=sta.top().right||j<=q.right)
		{
			if(i>sta.top().right)
			b[o++]=a[j++];
			else if(j>q.right)
			b[o++]=a[i++];
			else if(a[i]<a[j])
			b[o++]=a[i++];
			else b[o++]=a[j++];
		}
		for(i=sta.top().left;i<o;i++)
		a[i]=b[i];
		sta.pop();
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	mergesort(a,n);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}//7 9 5 7 4 8 1 3