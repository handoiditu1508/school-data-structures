#include<iostream>
#include<string>
using namespace std;
struct thisinh
{
	string hoten,sbd;
	int toan,ly,hoa;
};
struct node
{
	thisinh data;
	node *next;
};
void emptylist(node *&head)
{
	head=NULL;
}
void outlist(node *head)
{
	while(head)
	{cout<<head->data.sbd<<" "<<head->data.hoten<<endl;head=head->next;}
	cout<<endl;
}
void deletelist(node *&head)
{
	node *p;
	while(head)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
node *createthisinh()
{
	node *ts=new node;
	return ts;
}
void addthisinh(node *&head,node *ts)
{
	if(ts)
	{
		ts->next=NULL;
		cout<<"nhap ho ten thi sinh"<<endl;cin>>ts->data.hoten;
		cout<<"nhap so bao danh thi sinh"<<endl;cin>>ts->data.sbd;
		cout<<"nhap diem mon toan"<<endl;cin>>ts->data.toan;
		cout<<"nhap diem mon ly"<<endl;cin>>ts->data.ly;
		cout<<"nhap diem mon hoa"<<endl;cin>>ts->data.hoa;
		if(!head)
		head=ts;
		else
		for(node *p=head;;p=p->next)
		if(p->next==NULL)
		{
			p->next=ts;
			break;
		}
	}
}
void hskha(node *head)
{
	node *tam2;
	emptylist(tam2);
	for(node *tam=head;tam;tam=tam->next)
	if(tam->data.toan>=5)
	if(tam->data.ly>=5)
	if(tam->data.hoa>=5)
	{
		int tong=tam->data.toan+tam->data.ly+tam->data.hoa;
		if(tong>18)
		{
			node *tam3=new node;
			tam3->data=tam->data;
			if(!tam2)
			tam3->next=NULL,tam2=tam3;
			else if(tam2->data.toan+tam2->data.ly+tam2->data.hoa<=tong)
			tam3->next=tam2,tam2=tam3;
			else
			{
				node* tam4;
				for(tam4=tam2;tam4->next;tam4=tam4->next)
				if(tam4->next->data.toan+tam4->next->data.ly+tam4->next->data.hoa<=tong)
				break;
				tam3->next=tam4->next;
				tam4->next=tam3;
			}
		}
	}
	outlist(tam2);
	deletelist(tam2);
}
void deletethisinh(node *&head,string x)
{
	if(head)
	{
		if(head->data.sbd==x)
		{
			node *p=head;
			head=head->next;
			delete p;
		}
		else
		{
			for(node *p1=head;p1->next;p1=p1->next)
			if(p1->next->data.sbd==x)
			{
				node *p2=p1->next;
				p1->next=p2->next;
				delete p2;
				break;
			}
		}
	}
}
void suasbd(node *&head,string x)
{
	for(node *p=head;p;p=p->next)
	if(p->data.sbd==x)
	{
		cout<<"nhap diem mon toan"<<endl;cin>>p->data.toan;
		cout<<"nhap diem mon ly"<<endl;cin>>p->data.ly;
		cout<<"nhap diem mon hoa"<<endl;cin>>p->data.hoa;
		goto sss;
	}
	cout<<"khong tim thay thi sinh co so dao danh "<<x<<endl;
	sss:;
}
int main()
{
	node *h1,*h2;
	emptylist(h1);
	emptylist(h2);
	addthisinh(h1,createthisinh());
	addthisinh(h1,createthisinh());
	addthisinh(h1,createthisinh());
	addthisinh(h1,createthisinh());
	outlist(h1);
}//a1 a1 5 10 4 a2 a2 6 6 6 a3 a3 7 7 7 a4 a4 7 8 8