#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
struct list
{
	node *head,*tail;
};
void emptylist(list &l)
{
	l.head=l.tail=NULL;
}
void addtail(list &l,int x)
{
	node *q=new node;
	if(q)
	{
		q->data=x,q->next=NULL;
		if(l.head==NULL)
		l.head=l.tail=q;
		else
		l.tail->next=q,l.tail=q;
	}
}
void addhead(list &l,int x)
{
	node *q=new node;
	if(q)
	{
		q->data=x,q->next=NULL;
		if(l.head==NULL)
		l.head=l.tail=q;
		else
		q->next=l.head,l.head=q;
	}
}
void outlist(list l)
{
	while(l.head)
	{cout<<l.head->data<<" ";l.head=l.head->next;}
	cout<<endl;
}
void findnode(list l,int x)
{
	int t=0;
	while(l.head!=NULL)
	{
		if(l.head->data==x)
		{cout<<x<<" co vi tri la "<<t<<endl;return;}
		l.head=l.head->next;
		t++;
	}
	cout<<"khong tim thay"<<endl;
}
void deletenode(list &l,int x)
{
	if(l.head)
	{
	node *q;
	if(l.head->data==x)
	{
		q=l.head;
		l.head=l.head->next;
		delete q;
		if(l.head==NULL)l.tail==NULL;
		return;
	}
	q=l.head;
	node *w;
	while(q!=l.tail)
	{
		w=q->next;
		if(w->data==x)
		{
			q->next=w->next;
			if(l.tail==w)
			l.tail=q;
			delete w;
			return;
		}
		q=q->next;
	}
	}
}
void reverselist(list &l)
{
	if(l.head)
	{
	node *q1=l.head,*q2=q1->next,*q3;
	while(q2)
	{
		q3=q2->next;
		q2->next=q1;
		q1=q2;
		q2=q3;
	}
	l.head->next=NULL;
	q1=l.head;
	l.head=l.tail;
	l.tail=q1;
	}
}
void deletelist(list &l)
{
	while(l.head)
	{
		l.tail=l.head->next;
		delete l.head;
		l.head=l.tail;
	}
}
void copylist(list l,list &l1)
{
	deletelist(l1);
	while(l.head)
	{
		addtail(l1,l.head->data);
		l.head=l.head->next;
	}
}
bool cmplist(list l,list l1)
{
	while(l.head&&l1.head)
	{
		if(l.head->data!=l1.head->data)
		return false;
		l.head=l.head->next;
		l1.head=l1.head->next;
	}
	if((!l.head&&!l1.head))
	return true;
	return false;
}
int main()
{
	list l;
	emptylist(l);
	addhead(l,3);
	addhead(l,3);
	outlist(l);
}