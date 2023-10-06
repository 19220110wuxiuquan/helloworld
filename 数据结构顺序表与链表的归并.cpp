#include<iostream>
#include <algorithm>
using namespace std;
//顺序表的实现
template<class T,int MaxSize>
class SeqList {
private:
	T data[MaxSize];
	int length;
public:
	SeqList();
	SeqList(T a[], int n);
	void PrintSeqList();
    //归并两个有序（升序）顺序表（先判断是否是有序，若无序则先进行排序）
    friend SeqList<T, MaxSize> MergeSeqLists( SeqList<T, MaxSize>& list1,  SeqList<T, MaxSize>& list2)
    {
        // 检查顺序表是否已经有序，若无序则排序
        bool isList1Sorted = is_sorted(list1.data, list1.data + list1.length);
        bool isList2Sorted = is_sorted(list2.data, list2.data + list2.length);
        if (!isList1Sorted)
            sort(list1.data, list1.data + list1.length);
        if (!isList2Sorted)
            sort(list2.data, list2.data + list2.length);
        SeqList<T, MaxSize> mergedList;
        int i = 0; // 指向 list1 的指针
        int j = 0; // 指向 list2 的指针
        // 归并两个顺序表，直到其中一个顺序表遍历完
        while (i < list1.length && j < list2.length)
        {
            if (list1.data[i] <= list2.data[j])
            {
                mergedList.data[mergedList.length++] = list1.data[i++];
            }
            else
            {
                mergedList.data[mergedList.length++] = list2.data[j++];
            }
        }
        // 将剩余未遍历的元素添加到合并后的顺序表中
        while (i < list1.length)
        {
            mergedList.data[mergedList.length++] = list1.data[i++];
        }
        while (j < list2.length)
        {
            mergedList.data[mergedList.length++] = list2.data[j++];
        }
        return mergedList;
    };
};
//顺序表无参构造函数
template<class T,int MaxSize>
SeqList<T, MaxSize>::SeqList()
{
	length = 0;
}
//顺序表有参构造函数
template<class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n)
{
	if (n > MaxSize)
	{
		cerr << "参数非法";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}
//顺序表的遍历打印
template<class T, int MaxSize>
void SeqList<T, MaxSize>::PrintSeqList()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << endl;
	}
}

//链表的实现
template<class T>
struct Node {
    T data;
    Node<T>* next;
};
template<class T>
class LinkList {
    Node<T>* head;
public:
    LinkList();
    LinkList(T a[], int n);
    ~LinkList();
    void PrintLinkList();
    void SortLinkList();
    bool IsSorted();
    friend void MergeLinkLists(LinkList<T>& L1, LinkList<T>& L2)
    {
        
        // 检查链表是否已经有序，若无序则排序
        if (!L1.IsSorted())
            L1.SortLinkList();
        if (!L2.IsSorted())
            L2.SortLinkList();

        // 归并两个有序链表
        Node<T>* mergedHead = new Node<T>;
        Node<T>* cur = mergedHead;
        Node<T>* p = L1.head->next;
        Node<T>* q = L2.head->next;

        while (p && q) {
            if (p->data <= q->data) {
                cur->next = p;
                p = p->next;
            }
            else {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }

        // 处理剩余未遍历的元素
        cur->next = p ? p : q;

        // 释放原链表的节点
        Node<T>* temp = L2.head;
        while (temp) {
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        // 更新头节点指针
        L1.head = mergedHead;
        L2.head = nullptr;
    }
};
// 链表的无参构造函数
template<class T>
LinkList<T>::LinkList()
{
    head = new Node<T>;
    head->next = NULL;
}
// 链表的有参构造函数
template<class T>
LinkList<T>::LinkList(T a[], int n)
{
    head = new Node<T>;
    Node<T>* rear = head;
    for (int i = 0; i < n; i++) {
        Node<T>* s = new Node<T>;
        s->data = a[i];
        rear->next = s;
        rear = s;
    }
    rear->next = NULL;
}
// 链表的析构函数
template<class T>
LinkList<T>::~LinkList()
{
    Node<T>* p = head;
    while (p)
    {
        Node<T>* q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}
// 链表的遍历打印
template<class T>
void LinkList<T>::PrintLinkList()
{
    Node<T>* p = head;

    while (p != NULL) {
        cout << p->data<<endl; 
        p = p->next; 
    }
    cout << endl; 
}
template<class T>
void LinkList<T>::SortLinkList() {
    if (!head || !head->next || !head->next->next)
        return;

    Node<T>* p = head->next->next;
    Node<T>* lastSorted = head->next;

    while (p) {
        Node<T>* prev = head;
        Node<T>* q = head->next;

        // 在已排序部分中找到插入位置
        while (q != p && q->data <= p->data) {
            prev = q;
            q = q->next;
        }

        if (q != p) {
            // 将 p 从原位置删除
            lastSorted->next = p->next;

            // 将 p 插入到正确的位置
            p->next = prev->next;
            prev->next = p;

            // 更新 p 的位置
            p = lastSorted->next;
        }
        else {
            // p 已经在正确的位置上，继续向后遍历
            lastSorted = lastSorted->next;
            p = p->next;
        }
    }
}

template<class T>
bool LinkList<T>::IsSorted() {
    Node<T>* p = head->next;
    while (p && p->next) {
        if (p->data > p->next->data)
            return false;
        p = p->next;
    }
    return true;
}
//main测试函数
int main() {
    int choice;
    SeqList<int, 100> seqList1;
    SeqList<int, 100> seqList2;
    LinkList<int> linkList1;
    LinkList<int> linkList2;
    cout << "Menu:" << endl;
    cout << "1. 创建并打印顺序表" << endl;
    cout << "2. 归并两个顺序表" << endl;
    cout << "3. 创建并打印链表" << endl;
    cout << "4. 归并两个链表" << endl;
    cout << "5. 退出" << endl;
    while (true) {
        cout << "请输入您的选择：";
        cin >> choice;
        switch (choice) {
        case 1: {
            int n1, n2;
            cout << "请输入顺序表1的元素个数：";
            cin >> n1;
            cout << "请输入顺序表1的元素：";
            int arr1[100];
            for (int i = 0; i < n1; i++) {
                cin >> arr1[i];
            }
            seqList1 = SeqList<int, 100>(arr1, n1);
            cout << "请输入顺序表2的元素个数：";
            cin >> n2;
            cout << "请输入顺序表2的元素：";
            int arr2[100];
            for (int i = 0; i < n2; i++) {
                cin >> arr2[i];
            }
            seqList2 = SeqList<int, 100>(arr2, n2);
            cout << "顺序表1的元素为：" << endl;
            seqList1.PrintSeqList();
            cout << "顺序表2的元素为：" << endl;
            seqList2.PrintSeqList();
            break;
        }
        case 2: {
            SeqList<int, 100> mergedList = MergeSeqLists(seqList1, seqList2);
            cout << "合并后的顺序表元素为：" << endl;
            mergedList.PrintSeqList();
            break;
        }
        case 3: {
            int n1, n2;
            cout << "请输入链表1的元素个数：";
            cin >> n1;
            cout << "请输入链表1的元素：";
            int arr1[10];
            for (int i = 0; i < n1; i++) {
                cin >> arr1[i];
            }
            linkList1 = LinkList<int>(arr1, n1);
           
            cout << "请输入链表2的元素个数：";
            cin >> n2;
            cout << "请输入链表2的元素：";
            int arr2[10];
            for (int i = 0; i < n2; i++) {
                cin >> arr2[i];
            }
            linkList2 = LinkList<int>(arr2, n2);

            cout << "链表1的元素为：" << endl;
            linkList1.PrintLinkList();
            cout << "链表2的元素为：" << endl;
            linkList2.PrintLinkList();
            break;
        }
        case 4: {
            MergeLinkLists(linkList1, linkList2);
            cout << "合并后的链表元素为：" << endl;
            linkList1.PrintLinkList();
            break;
        }
        case 5:
            exit(0);
        default:
            cout << "无效的选择，请重新输入。" << endl;
        }
    }
    return 0;
}
