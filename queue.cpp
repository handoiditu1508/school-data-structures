#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef node QUEUE;
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
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
			return;
		}
		node *q=head;
		while(q->next)
		q=q->next;
		q->next=p;
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
int front(node *head)
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
	QUEUE *que;
	emptylist(que);
	push(que,1);
	push(que,2);
	push(que,3);
	push(que,4);
	outlist(que);
	if(isempty(que))
	cout<<"co"<<endl;
}