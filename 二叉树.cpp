#include<iostream>
#include<vector>
using namespace std;
//二叉链表结构
template<class T>
struct BiNode {
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};
//二叉树
template<class T>
class BiTree {
private:
	BiNode<T>* root;
	BiNode<T>* p;
	void InOrder(BiNode<T>* p);
	void PostOrder(BiNode<T>* p);
	BiNode<T>* CreateByPre(vector<T>& pre, int& i);
	BiNode<T>* CreateByPreMid(vector<T>& pre, vector<T>& mid);
	BiNode<T>* Copy(BiNode<T>* p);
	void Free(BiNode<T>* p);
	int Count(BiNode<T>* p);
	int Height(BiNode<T>* p);
	BiNode<T>* Search(BiNode<T>* p, T e);
	BiNode<T>* SearchParent(BiNode<T>* p, BiNode<T>* child);
public:
	BiTree() //无参构造函数
	{
		root = NULL;
	}
	BiTree(vector<T>& pre);//由带空指针标记的先序序列构造二叉树
	BiTree(vector<T>& pre, vector<T>& mid);//由先序序列和中序序列构造二叉树
	BiTree(BiTree<T>& tree);//拷贝构造函数
	~BiTree();//析构函数
	void PreOrder(BiNode<T>* p);
	void PreOrder();//前序序列
	void InOrder();//中序序列
	void PostOrder();//后续序列
	void LevelOrder();//层次序列
	int count();//统计节点个数
	int Height();//计算树高
	BiNode<T>* Search(T e);//根据值e查找节点
	BiNode<T>* SearchParent(BiNode<T>* child);//查找指定节点的父节点
};
//队列实现
template<class T>
class LinkQueue {
private:
	struct Node 
	{
		T data;
		Node* next;
	};
	Node* front;
	Node* rear;

public:
	LinkQueue() 
	{
		front = rear = nullptr;
	}
	~LinkQueue() 
	{
		while (!Empty()) 
		{
			DeQueue();
		}
	}

	bool Empty() 
	{
		return front == nullptr;
	}

	void EnQueue(T item) 
	{
		Node* newNode = new Node;
		newNode->data = item;
		newNode->next = nullptr;

		if (Empty()) 
		{
			front = rear = newNode;
		}
		else 
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	T DeQueue() 
	{
		if (Empty()) 
		{
			throw runtime_error("Queue is empty");
		}

		Node* temp = front;
		T item = front->data;
		front = front->next;
		delete temp;

		if (front == nullptr) 
		{
			rear = nullptr;
		}

		return item;
	}
};


//由带空指针标记的先序序列构造二叉树
template<class T>
BiNode<T>* BiTree<T>::CreateByPre(vector<T>& pre, int& i)
{
	T e = pre[i];
	i++;
	if (e == '*')
	{
		return NULL;
	}
	BiNode<T>* p = new BiNode<T>;
	p->data = e;
	p->lchild=CreateByPre(pre, i);
	p->rchild=CreateByPre(pre, i);
	return p;
}
template<class T>
BiTree<T>::BiTree(vector<T>& pre)
{
	int i = 0;
	root = CreateByPre(pre, i);
}

// 由先序序列和中序序列构造二叉树
template<class T>
BiNode<T>* BiTree<T>::CreateByPreMid(vector<T>& pre, vector<T>& mid)
{
	if (n == 0)
		return NULL;
	BiNode<T>* p = new BiNode<T>;
	p->data = pre[ipre];
	for (int i = 0; i < n; i++)
	{
		if (pre[ipre] == mid[imid + i])
			break;
		p->lchild = CreateByPreMid(pre, mid, ipre + 1, imid, i);
		p->rchild = CreateByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - 1 - i);
		return p;
	}
}
template<class T>
BiTree<T>::BiTree(vector<T>& pre, vector<T>& mid)
{
	n = pre.size();
	root = CreateByPreMid(pre, mid, 0, 0, n);
}

//前序遍历
template<class T>
void BiTree<T>::PreOrder(BiNode<T>* p)
{
	if (p == NULL)
	{
		return;
	}
	cout << p->data;
	PreOrder(p->lchild);
	PreOrder(p->rchild);

}
template<class T>
void BiTree<T>::PreOrder()
{
	PreOrder(root);
}

//中序遍历
template<class T>
void BiTree<T>::InOrder(BiNode<T>* p)
{
	if (p == NULL)
	{
		return;
	}
	InOrder(p->lchild);
	cout << p->data;
	InOrder(p->rchild);
}

template<class T>
void BiTree<T>::InOrder()
{
	InOrder(root);
}

//后序遍历
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* p)
{
	if (p == NULL)
	{
		return;
	}
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data;
}

template<class T>
void BiTree<T>::PostOrder()
{
	PostOrder(root);
}
//层次遍历
template<class T>
void BiTree<T>::LevelOrder()
{
	if (root == NULL)
	{
		return;
	}
	LinkQueue<BiNode<T>*>Q;
	Q.EnQueue(root);
	while (!Q.Empty())
	{
		BiNode<T>* p = Q.DeQueue();
		cout << p -> data;
		if (p->lchild != NULL)
		{
			Q.EnQueue(p->lchild);
		}
		if (p->rchild != NULL)
		{
			Q.EnQueue(p->rchild);
		}
	}
}


//复制构造函数
template<class T>
BiNode<T>* BiTree<T>::Copy(BiNode<T>* p)
{
	if (p == NULL)
	{
		return NULL;
	}
	BiNode<T>* newp = new BiNode<T>;
	newp->data = p->data;
	newp->lchild = Copy(p->lchild);
	newp->rchild = Copy(p->rchild);
	return newp;
}
template<class T>
BiTree<T>::BiTree(BiTree<T>& tree)
{
	root = Copy(tree.root);
}


//析构函数
template<class T>
void BiTree<T>::Free(BiNode<T>* p)
{
	if (p == NULL)
	{
		return;
	}
	Free(p->lchild);
	Free(p->rchild);
	delete p;
}
template<class T>
BiTree<T>::~BiTree()
{
	Free(root);
}

//计算二叉树的节点数
template<class T>
int BiTree<T>::Count(BiNode<T>* p)
{
	if (p == NULL)
		return 0;
	left = Count(p->lchild);
	right = Count(p->rchild);
	return 1 + left + right;
}
template<class T>
int BiTree<T>::count()
{
	return Count(root);
}

//计算二叉树的高度
template<class T>
int BiTree<T>::Height(BiNode<T>* p)
{
	if (p == NULL)
	{
		return 0;
	}
	left = Height(p->lchild);
	right = Height(p->rchild);
	if (left > right)
	{
		return left + 1;
	}
	else
		return right + 1;
}
template<class T>
int BiTree<T>::Height()
{
	return Height(root);
}


//二叉树的查找
template<class T>
BiNode<T>* BiTree<T>::Search(BiNode<T>* p, T e)
{
	if (p = NULL)
	{
		return NULL;
	}
	if (p->data == e)
	{
		return p;
	}
	BiTreeNode<T>* q = Search(p->lchild, e);
	if (q != NULL)
	{
		return q;
	}
	return Search(p->rchild, e);
}
template<class T>
BiNode<T>* BiTree<T>::Search(T e)
{
	return Search(root, e);
}
//查找父节点
template<class T>
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* p, BiNode<T>* child)
{
	if (p = NULL || child == NULL)
	{
		return NULL;
	}
	if (p->lchild == child || p->rchild == child)
	{
		return p;
	}
	BiTreeNode<T>* q = SearchParent(p->lchild, child);
	if (q != NULL)
	{
		return q;
	}
	return SearchParent(p->child, child);
}
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* child)
{
	return SearchParent(root, child);
}
//main函数测试（菜单模式）
int main()
{
	return 0;
}
