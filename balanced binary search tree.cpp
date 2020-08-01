#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
struct pnode
{
	node *pointto;
};
struct ppnode
{
	node **pointto;
};
bool leafnode(node *q)
{
	if(!q->left)
		if(!q->right)
			return true;
	return false;
}
void deletetree(node *&root)
{
	if(root)
	{
		pnode p;
		queue<pnode>que1;
		p.pointto=root;
		que1.push(p);
		while(!que1.empty())
		{
			if(que1.front().pointto->left)
			{
				p.pointto=que1.front().pointto->left;
				que1.push(p);
			}
			if(que1.front().pointto->right)
			{
				p.pointto=que1.front().pointto->right;
				que1.push(p);
			}
			delete que1.front().pointto;
			que1.pop();
		}
		root=NULL;
	}
}
void browsebfs(node *root)
{
	if(root)
	{
		queue<node>que1;
		que1.push(*root);
		while(!que1.empty())
		{
			cout<<que1.front().data<<" ";
			if(que1.front().left)
			que1.push(*que1.front().left);
			if(que1.front().right)
			que1.push(*que1.front().right);
			que1.pop();
		}
	}
	cout<<endl;
}
node *createnode(int x)
{
	node *p=new node;
	if(p)
	{
		p->data=x;
		p->left=NULL;
		p->right=NULL;
	}
	return p;
}
void insertnode(node *&root,int x)
{
	node *p=new node;
	if(p)
	{
		p->left=NULL;
		p->right=NULL;
		p->data=x;
		if(!root)
		root=p;
		else
		{
			node *q=root;
			while(1)
			{
				if(p->data<q->data)
					if(!q->left)
					{
						q->left=p;
						break;
					}
					else q=q->left;
				else if(!q->right)
				{
					q->right=p;
					break;
				}
				else q=q->right;
			}
		}
	}
}
void initnode(node *&root)
{
	root=NULL;
}
int leftof(node *p)//chieu cao node ben trai
{
	if(p->left)
	return p->left->data;
	return -1;
}
int rightof(node *p)//chieu cao node ben phai
{
	if(p->right)
	return p->right->data;
	return -1;
}
void rotateleft(node *&pp)
{
	node *p=pp->right;
	pp->right=p->left;
	p->left=pp;
	pp=p;
}
void rotateright(node *&pp)
{
	node *p=pp->left;
	pp->left=p->right;
	p->right=pp;
	pp=p;
}
void balancetree(node *&root1)
{
	node *root2=NULL;
	queue<ppnode>que1,que2;
	stack<ppnode>sta1,sta2;
	ppnode tam;
	
	start:;
	while(!sta1.empty())
	sta1.pop(),sta2.pop();
	deletetree(root2);

	tam.pointto=&root1;
	que1.push(tam);
	tam.pointto=&root2;
	que2.push(tam);
	while(!que1.empty())
	{
		if(que1.front().pointto[0])
		{
			sta1.push(que1.front());
			
			sta2.push(que2.front());
			
			que2.front().pointto[0]=createnode(0);
			
			tam.pointto=&que1.front().pointto[0]->left;
			que1.push(tam);
			tam.pointto=&que1.front().pointto[0]->right;
			que1.push(tam);
			
			tam.pointto=&que2.front().pointto[0]->left;
			que2.push(tam);
			tam.pointto=&que2.front().pointto[0]->right;
			que2.push(tam);
		}
		que1.pop();
		que2.pop();
	}

	while(!sta1.empty())
	{
		int lef=leftof(sta2.top().pointto[0]),rig=rightof(sta2.top().pointto[0]);
		if(lef-rig>1)
		{
			if(rightof(sta2.top().pointto[0]->left)>leftof(sta2.top().pointto[0]->left))
				rotateleft(sta1.top().pointto[0]->left);
			rotateright(sta1.top().pointto[0]);
			goto start;
		}
		if(lef-rig<-1)
		{
			if(leftof(sta2.top().pointto[0]->right)>rightof(sta2.top().pointto[0]->right))
				rotateright(sta1.top().pointto[0]->right);
			rotateleft(sta1.top().pointto[0]);
			goto start;
		}
		sta2.top().pointto[0]->data=max(lef,rig)+1;
		sta1.pop();
		sta2.pop();
	}
	deletetree(root2);
}
int main()
{
	node *root1;
	initnode(root1);
	insertnode(root1,100);
	insertnode(root1,90);
	insertnode(root1,80);
	insertnode(root1,85);
	insertnode(root1,87);
	insertnode(root1,70);
	insertnode(root1,75);
	insertnode(root1,60);
	insertnode(root1,50);
	insertnode(root1,40);
	insertnode(root1,110);
	insertnode(root1,105);
	insertnode(root1,120);
	insertnode(root1,130);
	insertnode(root1,140);
	balancetree(root1);
	browsebfs(root1);
}