#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
void emptylist(node *&head)
{
	head=NULL;
}
void outlist(node *head)
{
	node *p=head;
	while(p)
	{cout<<p->data<<" ";p=p->next;}
	cout<<endl;
}
void addnode(node *&head,int x)
{
	node *q=new node;
	if(q)
	{
		q->data=x,q->next=NULL;
		if(head==NULL)
		head=q;
		else if(head->data>=x)
		q->next=head,head=q;
		else
		{
			node *tam=head;
			for(;tam->next;tam=tam->next)
			if(tam->next->data>=x)
			break;
			q->next=tam->next;
			tam->next=q;
		}
	}
}
void deletenode(node *&head,int x)
{
	if(head)
	{
		if(head->data==x)
		{
			node *p=head;
			head=head->next;
			delete p;
		}
		else
		{
			for(node *tam=head;tam->next;tam=tam->next)
			if(tam->next->data==x)
			{
				node *p=tam->next;
				tam->next=p->next;
				delete p;
				break;
			}
		}
	}
}
bool exist(node *head,int x)
{
	while(head)
	{
		if(head->data==x)
		return true;
		head=head->next;
	}
	return false;
}
node *copylist(node *head1)
{
	node *head2;
	emptylist(head2);
	while(head1)
	addnode(head2,head1->data),head1=head1->next;
	return head2;
}
void deletenode2(node *&head1,node *p)
{
	if(head1)
	{
		if(head1==p)
		head1=head1->next,delete p;
		else
		{
			node *o=head1;
			while(o->next)
			if(o->next==p)
			{
				o->next=p->next;
				delete p;
				break;
			}
		}
	}
}
node *hieu(node *head1,node *head2)
{
	node *head3=copylist(head1);
	head1=head3;
	while(head1&&head2)
	{
		if(head1->data>head2->data)
		head2=head2->next;
		else if(head1->data<head2->data)
		head1=head1->next;
		else
		{
			node *p=head1;
			head1=head1->next;
			head2=head2->next;
			deletenode2(head3,p);
		}
	}
	return head3;
}
node *hop(node *head1,node *head2)
{
	node *head3;
	emptylist(head3);
	while(head1||head2)
	{
		if(!head1)
		addnode(head3,head2->data),head2=head2->next;
		else if(!head2)
		addnode(head3,head1->data),head1=head1->next;
		else if(head1->data<head2->data)
		addnode(head3,head1->data),head1=head1->next;
		else if(head2->data<head1->data)
		addnode(head3,head2->data),head2=head2->next;
		else addnode(head3,head2->data),head2=head2->next,head1=head1->next;
	}
	return head3;
}
node *giao(node *head1,node *head2)
{
	node *head3;
	emptylist(head3);
	while(head1&&head2)
	{
		if(head1->data<head2->data)head1=head1->next;
		else if(head2->data<head1->data)head2=head2->next;
		else addnode(head3,head2->data),head2=head2->next,head1=head1->next;
	}
	return head3;
}
int main()
{
	node *h1,*h2;
	emptylist(h1);
	emptylist(h2);
	addnode(h1,8);
	addnode(h1,5);
	addnode(h1,6);
	addnode(h1,7);
	addnode(h2,1);
	addnode(h2,9);
	addnode(h2,2);
	addnode(h2,8);
	outlist(giao(h1,h2));
}