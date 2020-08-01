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
	if(head)
	{
		cout<<head->data<<" ";
		node *p=head->next;
		while(head!=p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
	}
	cout<<endl;
	
}
void addtail(node *&head,int x)
{
	node *p=new node;
	if(p)
	{
		p->data=x;
		if(!head)
		head=p,p->next=p;
		else
		{
			node *p1=head;
			while(p1->next!=head)
			p1=p1->next;
			p1->next=p;
			p->next=head;
		}
	}
}
void addhead(node *&head,int x)
{
	node *p=new node;
	if(p)
	{
		p->data=x;
		if(!head)
		head=p,p->next=p;
		else
		{
			node *p1=head;
			while(p1->next!=head)
			p1=p1->next;
			p1->next=p;
			p->next=head;
			head=p;
		}
	}
}
void findnode(node *head,int x)
{
	if(head)
	{
		int t=0;
		if(head->data==x)
		{
			cout<<x<<" co vi tri la "<<t<<endl;
			return;
		}
		{
			node *p=head->next;
			while(p!=head)
			{
				t++;
				if(p->data==x)
				{
					cout<<x<<" co vi tri la "<<t<<endl;
					return;
				}
				p=p->next;
			}
		}
	}
	cout<<"khong tim thay"<<endl;
}
void deletenode(node *&head,int x)
{
	if(head)
	{
		node *p1=head,*p2=head->next;
		while(p2!=head)
		{
			if(p2->data==x)
			{
				p1->next=p2->next;
				delete p2;
				return;
			}
			p1=p2;
			p2=p2->next;
		}
		if(head->data==x)
		{
			if(p1==p2)
			head=NULL;
			else
			{
				head=p2->next;
				p1->next=p2->next;
			}
			delete p2;
		}
	}
}
void reverselist(node *&head)
{
	if(head)
	{
		node *p1=head,*p2=p1->next,*p3;
		while(p2!=head)
		{
			p3=p2->next;
			p2->next=p1;
			p1=p2;
			p2=p3;
		}
		p2->next=p1;
		head=p1;
	}
}
void deletelist(node *&head)
{
	if(head)
	{
		node *p=head->next;
		head->next=NULL;
		head=p;
		while(head)
		{
			p=head->next;
			delete head;
			head=p;
		}
	}
}
void copylist(node *head1,node *&head2)
{
	deletelist(head2);
	if(head1)
	{
		addtail(head2,head1->data);
		node *p=head1->next;
		while(p!=head1)
		addtail(head2,p->data),p=p->next;
	}
}
bool cmplist(node *head1,node *head2)
{
	if(head1&&head2)
	{
		node *p1=head1->next,*p2=head2->next;
		if(head1->data!=head2->data)
		return false;
		while(p1!=head1&&p2!=head2)
		{
			if(p1->data!=p2->data)
			return false;
			p1=p1->next;
			p2=p2->next;
		}
		if(p1==head1&&p2==head2)
		return true;
		return false;
	}
	else if(!head1&&!head2)
	return true;
	else return false;
}
int main()
{
	node *head1,*head2;
	emptylist(head1);
	emptylist(head2);
	addhead(head1,1);
	addhead(head1,2);
	addhead(head1,3);
	addhead(head1,4);
	addhead(head2,1);
	addhead(head2,2);
	addhead(head2,3);
	addhead(head2,4);
	if(cmplist(head1,head2))cout<<"1"<<endl;
//	outlist(head2);
}