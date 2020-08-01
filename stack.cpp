#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef node STACK;
void emptylist(node *&head)
{
	head=NULL;
}
void push(node *&head,int x)
{
	node *p=new node;
	if(p)
	{
		p->data=x;
		if(head==NULL)
		{
			head=p;
			p->next=NULL;
			return;
		}
		p->next=head;
		head=p;
	}
}
void outlist(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
int top(node *head)
{
	if(head)
	return head->data;
}
void pop(node *&head)
{
	if(head)
	{
		node *p=head;
		head=head->next;
		delete p;
	}
}
bool isempty(node *head)
{
	if(head==NULL)
	return true;
	return false;
}
int main()
{
	STACK *sta;
	emptylist(sta);
	push(sta,1);
	push(sta,2);
	push(sta,3);
	push(sta,4);
	outlist(sta);
	cout<<top(sta)<<endl;
	pop(sta);
	outlist(sta);
	cout<<top(sta);
}