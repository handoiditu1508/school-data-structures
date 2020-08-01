#include<iostream>
#include<math.h>
using namespace std;
struct dathuc
{
	float so;
	unsigned int mu;
};
struct node
{
	dathuc data;
	node *next;
};
void emptylist(node *&head)
{
	head=NULL;
}
void outlist(node *head)
{
	if(head)
	cout<<head->data.so<<"x^"<<head->data.mu,head=head->next;
	while(head)
	{
		if(head->data.so>=0)
		cout<<"+";
		cout<<head->data.so<<"x^"<<head->data.mu;
		head=head->next;
	}
	cout<<endl;
}
void createdathuc(node *&head,int n)
{
	for(;n>-1;n--)
	{
		node *p=new node;
		if(p)
		{
			cout<<"nhap he so thu "<<n<<endl;cin>>p->data.so;p->data.mu=n;p->next=NULL;
			if(p->data.so)
			{
				if(!head)
				head=p;
				else
				for(node *p1=head;;p1=p1->next)
				if(!p1->next)
				{
					p1->next=p;
					break;
				}
			}
		}
	}
}
void adddonthuc(node *&head,node *p)
{
	if(p->data.so)
	{
		if(!head)
		head=p;
		else
		for(node *p1=head;;p1=p1->next)
		if(!p1->next)
		{
			p1->next=p;
			break;
		}
	}
}
double tinhx(node *head,int x)
{
	float kq=0;
	while(head)
	{
		kq+=head->data.so*pow(x,head->data.mu);
		head=head->next;
	}
	return kq;
}
node *congdathuc(node *head1,node *head2)
{
	node *head3;
	emptylist(head3);
	while(head1&&head2)
	{
		node *p=new node;
		if(p)
		{
			p->next=NULL;
			if(!head1)
			p->data.mu=head2->data.mu,p->data.so=head2->data.so,head2=head2->next;
			else if(!head2)
			p->data.mu=head1->data.mu,p->data.so=head1->data.so,head1=head1->next;
			else if(head2->data.mu>head1->data.mu)
			p->data.mu=head2->data.mu,p->data.so=head2->data.so,head2=head2->next;
			else if(head1->data.mu>head2->data.mu)
			p->data.mu=head1->data.mu,p->data.so=head1->data.so,head1=head1->next;
			else p->data.mu=head1->data.mu,p->data.so=head1->data.so+head2->data.so,head1=head1->next,head2=head2->next;
			adddonthuc(head3,p);
		}
	}
	return head3;
}

node *nhandondathuc(node *head1,node *head2)
{
	node *head3,*head4;
	emptylist(head3);
	while(head2)
	{
		head4=new node;
		if(head4)
		{
			head4->next=NULL;
			head4->data.mu=head1->data.mu+head2->data.mu;
			head4->data.so=head1->data.so*head2->data.so;
			adddonthuc(head3,head4);
		}
		head2=head2->next;
	}
	return head3;
}
node *nhandathuc(node *head1,node *head2)
{
	node *head3;
	emptylist(head3);
	if(head1&&head2)
	{
		head3=nhandondathuc(head1,head2);
		while(head1->next)
		{
			head1=head1->next;
			head3=congdathuc(head3,nhandondathuc(head1,head2));
		}
	}
	return head3;
}
int main()
{
	node *h1,*h2;
	emptylist(h1);
	emptylist(h2);
	createdathuc(h1,5);
	createdathuc(h2,8);
	outlist(nhandathuc(h1,h2));
}//5 7 -8 4 -2 -6 7 4 0 2 4 7 0 0 3