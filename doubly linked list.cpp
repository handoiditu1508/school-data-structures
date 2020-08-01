#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next,*prev;
};
void emptylist(node *&head)
{
	head=NULL;
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
void addtail(node *&head,int x)
{
	node *p=new node;
	if(p)
	{
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
	}
	if(!head)
	head=p;
	else if(p)
	{
		node *q=head;
		while(q->next)
		q=q->next;
		q->next=p;
		p->prev=q;
	}
}
void addhead(node *&head,int x)
{
	node *p=new node;
	if(p)
	{
		p->data=x;
		p->next=NULL;
		p->prev=NULL;
	}
	if(!head)
	head=p;
	else if(p)
	{
		p->next=head;
		head->prev=p;
		head=p;
	}
}
void findnode(node *head,int x)
{
	int t=0;
	while(head)
	{
		if(head->data==x)
		{
			cout<<x<<" co vi tri la "<<t<<endl;return;
		}
		head=head->next;
		t++;
	}
	cout<<"khong tim thay"<<endl;
}
void deletenode(node *&head,int x)
{
	if(head)
	{
		node *p=head;
		if(p->data==x)
		{
			if(p->next)
			{
				head=p->next;
				head->prev=NULL;
			}
			else head=NULL;
			delete p;
			return;
		}
		while(p->next)
		{
			if(p->data==x)
			{
				p->prev->next=p->next;
				p->next->prev=p->prev;
				delete p;
				return;
			}
			p=p->next;
		}
		if(p->data==x)
		{
			p->prev->next=NULL;
			delete p;
		}
	}
}
void reverselist(node *&head)
{
	if(head)
	{
		node *p1=head,*p2=p1->next,*p3;
		while(p2)
		{
			p3=p2->next;
			p2->next=p1;
			p2->prev=p3;
			p1=p2;
			p2=p3;
		}
		head->prev=head->next;
		head->next=NULL;
		head=p1;
	}
}
void deletelist(node *&head)
{
	node *p;
	while(head)
	{
		p=head->next;
		delete head;
		head=p;

	}
}
void copylist(node *head1,node *&head2)
{
	deletelist(head2);
	while(head1)
	{
		addtail(head2,head1->data);
		head1=head1->next;
	}
}
bool cmplist(node *head1,node *head2)
{
	while(head1&&head2)
	{
		if(head1->data!=head2->data)
		return false;
		head1=head1->next;
		head2=head2->next;
	}
	if(!head1&&!head2)
	return true;
	return false;
}
int main()
{
	node *head1,*head2;
	emptylist(head1);
	emptylist(head2);
	addhead(head1,4);
	addhead(head1,3);
	addhead(head1,2);
	addhead(head1,1);
	outlist(head1);
	copylist(head1,head2);
	deletelist(head2);
	outlist(head2);
	if(cmplist(head1,head2))
	cout<<"co"<<endl;
	else cout<<"khong"<<endl;
}