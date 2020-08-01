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
bool leafnode(node *q)
{
	if(!q->left)
	if(!q->right)
	return true;
	return false;
}
void swapnode(node *p1,node *p2)
{
	int p3=p1->data;
	p1->data=p2->data;
	p2->data=p3;
}
void initnode(node *&root)
{
	root=NULL;
}
bool searchnode(node *root,int x)
{
	while(root)
	{
		if(root->data==x)
		return true;
		if(x>root->data)
		root=root->right;
		else root=root->left;
	}
	return false;
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
void browseLNR(node *root)
{
	if(root)
	{
		pnode tam;
		tam.pointto=root;
		queue<pnode>que1;
		stack<pnode>sta1;
		que1.push(tam);
		while(!que1.empty())
		{
			while(!que1.empty())
			{
				if(que1.front().pointto->left)
				{
					tam.pointto=que1.front().pointto->left;
					que1.push(tam);
				}
				sta1.push(que1.front());
				que1.pop();
			}
			while(!sta1.empty())
			{
				if(sta1.top().pointto->right)
				{
					tam.pointto=sta1.top().pointto->right;
					que1.push(tam);
					cout<<sta1.top().pointto->data<<" ";
					sta1.pop();
					break;
				}
				cout<<sta1.top().pointto->data<<" ";
				sta1.pop();
			}
		}
	}
	cout<<endl;
}
void browseLRN(node *root)
{
	if(root)
	{
		pnode tam;
		queue<pnode>que1;
		stack<pnode>sta1;
		stack<bool>sta2;
		tam.pointto=root;
		que1.push(tam);
		while(!que1.empty())
		{
			while(!que1.empty())
			{
				if(que1.front().pointto->left)
				{
					tam.pointto=que1.front().pointto->left;
					que1.push(tam);
				}
				sta1.push(que1.front());
				sta2.push(false);
				que1.pop();
			}
			while(!sta1.empty())
			{
				if(sta2.top())
				{
					cout<<sta1.top().pointto->data<<" ";
					sta1.pop();
					sta2.pop();
				}
				else
				{
					if(sta1.top().pointto->right)
					{
						tam.pointto=sta1.top().pointto->right;
						que1.push(tam);
						sta2.top()=true;
						break;
					}
				cout<<sta1.top().pointto->data<<" ";
				sta1.pop();
				sta2.pop();
				}
			}
		}
	}
	cout<<endl;
}
void browseNLR(node *root)
{
	if(root)
	{
		pnode tam;
		queue<pnode>que1;
		stack<pnode>sta1;
		tam.pointto=root;
		que1.push(tam);
		while(!que1.empty())
		{
			while(!que1.empty())
			{
				cout<<que1.front().pointto->data<<" ";
				if(que1.front().pointto->left)
				{
					tam.pointto=que1.front().pointto->left;
					que1.push(tam);
				}
				sta1.push(que1.front());
				que1.pop();
			}
			while(!sta1.empty())
			{
				if(sta1.top().pointto->right)
				{
					tam.pointto=sta1.top().pointto->right;
					que1.push(tam);
					sta1.pop();
					break;
				}
				sta1.pop();
			}
		}
	}
	cout<<endl;
}
void browsebfs(node *root)
{
	if(root)
	{
		pnode tam;
		queue<pnode>que1;
		tam.pointto=root;
		que1.push(tam);
		while(!que1.empty())
		{
			cout<<que1.front().pointto->data<<" ";
			if(que1.front().pointto->left)
			{
				tam.pointto=que1.front().pointto->left;
				que1.push(tam);
			}
			if(que1.front().pointto->right)
			{
				tam.pointto=que1.front().pointto->right;
				que1.push(tam);
			}
			que1.pop();
		}
	}
	cout<<endl;
}
void deletenode3(node *&root,int x)
{
	node **p=&root;
	while(p[0])
	{
		if(p[0]->data==x)
			break;
		else if(p[0]->data>x)
			p=&p[0]->left;
		else p=&p[0]->right;
	}
	if(p[0])
	{
		if(p[0]->left)//11111111111
		{
			node **p1=&p[0]->left;
			while(p1[0]->right)
				p1=&p1[0]->right;
			p[0]->data=p1[0]->data;
			node *p2=p1[0];
			p1[0]=p1[0]->left;
			delete p2;
			return;
		}
		if(p[0]->right)//11111111111
		{
			node **p1=&p[0]->right;
			while(p1[0]->left)
				p1=&p1[0]->left;
			p[0]->data=p1[0]->data;
			node *p2=p1[0];
			p1[0]=p1[0]->right;
			delete p2;
			return;
		}
		delete p[0];//11111111111
		p[0]=NULL;
	}
}
void deletenode4(node *&root,int x)
{
	node **p=&root;
	while(p[0])
	{
		if(p[0]->data==x)
			break;
		else if(p[0]->data>x)
			p=&p[0]->left;
		else p=&p[0]->right;
	}
	if(p[0])
	{
		node *p2=p[0];
		if(!p[0]->left)
		{
			p[0]=p[0]->right;
			delete p2;
		}
		else if(!p[0]->right)
		{
			p[0]=p[0]->left;
			delete p2;
		}
		else
		{
			node **p1=&p[0]->left;
			while(p1[0]->right)
				p1=&p1[0]->right;
			p[0]->data=p1[0]->data;
			p2=p1[0];
			p1[0]=p1[0]->left;
			delete p2;
		}
	}
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
int main()
{
	int x;
	node *root1;
	initnode(root1);
	insertnode(root1,60);
	insertnode(root1,40);
	insertnode(root1,70);
	insertnode(root1,20);
	insertnode(root1,50);
	insertnode(root1,90);
	insertnode(root1,80);
	insertnode(root1,10);
	insertnode(root1,30);
	insertnode(root1,9);
	insertnode(root1,8);
	insertnode(root1,7);
	insertnode(root1,61);
	insertnode(root1,69);
	insertnode(root1,62);
	insertnode(root1,68);
	insertnode(root1,63);
	
	node *root2;
	initnode(root2);
	insertnode(root2,60);
	insertnode(root2,40);
	insertnode(root2,70);
	insertnode(root2,20);
	insertnode(root2,50);
	insertnode(root2,90);
	insertnode(root2,80);
	insertnode(root2,10);
	insertnode(root2,30);
	insertnode(root2,9);
	insertnode(root2,8);
	insertnode(root2,7);
	insertnode(root2,61);
	insertnode(root2,69);
	insertnode(root2,62);
	insertnode(root2,68);
	insertnode(root2,63);
	
	deletenode3(root1,63);
	deletenode4(root2,63);
	browsebfs(root1);
	browsebfs(root2);
}//60 40 70 90 80 20 50 30 10