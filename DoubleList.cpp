#include "DoubleList.h"
#include "iostream"
#include "windows.h"
using namespace std;
List::List()   /*构造函数，用于创建一个链表*/
{
	p = new Node;   /*堆中申请内存空间*/
	p->data = 0;     /*链表头不存放数据，所以此数据无意义*/
	p->next = NULL;
	p->pre = NULL;
	i_len =0;   /*链表长度初始化为0*/
	cout << "The linked list was created successfully" << endl;
}

List::~List()   /*析构函数，用于释放内存空间*/
{
	clean();
	delete p;
	p = NULL;
}

void List::clean()   /*清空所有链表*/
{
	Node *current = p->next;
	Node* temp = NULL;
	for(int i=0;i<i_len;i++)  /*按照链式结构依次找到下个结点并删除当前结点*/
	{
		temp = current->next;
		delete current;
		current = temp;
	}
	current = NULL;
	p->next = NULL;
	i_len = 0;  /*删除所有结点后，链表长度清零*/
}

bool List::empty()  /*判空*/
{
	return i_len == 0 ? true : false;
}

int List::length()  /*获取链表长度*/
{
	return i_len;
}

bool List::inser_head(Node node)   
{
	cout << "insert head_node" << endl;
	if (i_len == 0)   //如果链表为空，则头节点插入只需新增一个节点即可
	{
		Node* new_head = new Node;   /*因为是新插入的节点，所以必须在堆中申请内存，否则函数执行完成后会自动释放内存*/
		new_head->data = node.data;
		new_head->next = new_head;
		new_head->pre = new_head;
		p->next = new_head;
		i_len++;
	}
	else
	{
		Node* new_head = new Node;
		Node* old_head = p->next;
		new_head->data = node.data;
		new_head->next = old_head;
		old_head->pre = new_head;
		p->next = new_head;
		i_len++;    //此时新结点已经插入，所以++操作，否则接下来寻找的尾节点是错误的
		Node* tail_node=p;
		for (int i = 0; i < i_len; i++)   //根据链表长度找到链表尾节点
			tail_node = tail_node->next;
		new_head->pre = tail_node;         //头指向尾 
		tail_node->next = new_head;      //尾指向头
	}
	return true;
}

bool List::inser_tail(Node node)
{
	cout << "insert tail_node" << endl;
	if (i_len == 0)   //如果链表为空，则插入尾结点就相当于插入头结点
	{
		inser_head(node);   //注意inser_head函数里已经有i_len++,所以此处不用再i_len++
	}
	else
	{
		Node* new_tail = new Node;
		new_tail->data = node.data;
		Node* old_tail = p;
		for (int i = 0; i < i_len; i++)   //根据链表长度找到链表尾节点
		{
			old_tail = old_tail->next;
		}
		old_tail->next = new_tail;
		new_tail->pre = old_tail;
		new_tail->next = p->next;   //尾结点指向头结点
		p->next->pre = new_tail;	//头结点指向尾结点
		i_len++;
	}
	return true;
}

bool List::inser(Node node, int location)
{
	int i = location;
	if (i<0 || i>i_len)
	{
		cout << "can't insert" << endl;
		return false;
	}
	else if (i == 0 || i == i_len)
	{
		i == 0 ? inser_head(node) : inser_tail(node);
		return true;
	}
	else      //此时i_len至少大于等于2，因为若i_len==1时：i==1时，i == i_len成立，或者i==0时都是执行上一步
	{
		Node* i_node = new Node;
		i_node->data = node.data;
		Node* i_node_pre = p;
		while (i > 0)     //找到第i号结点的前一个结点
		{
			i_node_pre = i_node_pre->next;
			i--;
		}
		i_node->next = i_node_pre->next;
		i_node_pre->next->pre = i_node;
		i_node->pre = i_node_pre;
		i_node_pre->next = i_node;
		i_len++;
	}
	return true;
}

bool List::delete_head()
{
	if (p->next == NULL)
	{
		cout << "error,can not delete head_node" << endl;
		return false;
	}
	cout << "deleye head_node" << endl;
	if (i_len == 1)
	{
		Node* head = p->next;
		delete head;
		head = NULL;
		p->next = NULL;
		i_len--;
	}
	if (i_len >= 2)
	{
		Node* old_head = p->next;
		Node* new_head = old_head->next;
		new_head->pre = old_head->pre;
		p->next = new_head;
		delete old_head;
		old_head = NULL;
		i_len--;
	}
	return true;
}

bool List::delete_tail()
{
	if (i_len==0)
	{
		cout << "error,can not delete tail_node" << endl;
		return false;
	}
	cout << "delete tail_node" << endl;
	if (i_len == 1)   //此时相当于删除头结点
	{
		delete_head();   //delete_head()函数里已经有i_len--,此处不用再i_len--
	}
	else if (i_len == 2)
	{
		Node* head = p->next;
		Node* old_tail = head->next;
		delete old_tail;
		old_tail = NULL;
		head->next = NULL;
		head->pre = NULL;
		i_len--;
	}
	else if (i_len > 2)
	{
		Node* old_tail = p;
		{
			for (int i = 0; i < i_len; i++)			//根据链表长度找到链表尾节点
				old_tail = old_tail->next;
		}
		Node* new_tail = old_tail->pre;
		new_tail->next = old_tail->next;
		Node* head = p->next;
		head->pre = new_tail;
		delete old_tail;
		old_tail = NULL;
		i_len--;
	}
	return true;
}

bool List::delete_Node(int location)    //3->4->1->5->6->2->7
{
	int i = location;
	if (i<0 || i>=i_len)    //第一个结点下标是从0开始的，所以尾结点的下标为i_len-1
	{
		cout << "can not delete" << endl;
		return false;
	}

	if (i == 0 || i == i_len-1)
	{
		i == 0 ? delete_head() : delete_tail();    //delete_head()函数与delete_tail()函数里已经有i_len--
		return true;
	}
	else   //此时i_len至少为3
	{
		cout << "delete node" << endl;
		Node* i_node = p->next;
		while (i > 0)   //找到下标为i的结点
		{
			i_node = i_node->next;
			i--;
		}
		Node* i_node_pre = i_node->pre;
		Node* i_node_next = i_node->next;
		i_node_pre->next = i_node_next;
		i_node_next->pre = i_node_pre;
		delete i_node;
		i_node = NULL;
		i_len--;
	}
	return true;
}

bool List::get_i_node(int i,Node* i_node)
{
	if (i<0 || i>=i_len)
	{
		cout << "can not get node " << i << endl;
		return false;
	}
	//cout << "node[" << i << "]="; 
	Node* current = p;
	while (i >= 0)
	{
		current = current->next;
		i--;
	}
	i_node->data = current->data;
	i_node->next = current->next;
	i_node->pre = current->pre;
	//cout << current->data << endl;
	return true;
}

int List::get_node_i(Node node)
{
	Node* current = p->next;
	int i = 0;
	while (current != NULL)
	{
		if (current->data == node.data)
		{
			return i;
		}
		current = current->next;
		i++;
	}
	cout << "can not find " << endl;
	return -1;
}

bool List::get_pre_node(Node node, Node* pre_node)
{
	int i=get_node_i(node);
	if (i <= 0)
	{
		cout << "no pre_node" << endl;
		return false;
	}
	get_i_node(i-1,pre_node);
	return true;
}

bool List::get_next_node(Node node, Node* next_node)
{
	int i = get_node_i(node);
	if (i < 0||i==i_len-1)
	{
		cout << "no next_node" << endl;
		return false;
	}
	get_i_node(i+1, next_node);
	return true;
}

bool List::traverse(char direction)
{
	if (p->next == NULL)
	{
		cout << "empty,can not traverse" << endl;
		return false;
	}
	if (direction == 'L')
	{
		Node* current = p;
		for (int i = 0; i < i_len; i++)    //根据链表长度找到链表尾节点
		{
			current = current->next;   
		}
		/*while (current->next != NULL)
		{
			current = current->next;
		}*/
		cout << "Traverse it from right to lift:" << endl;
		for(int i=0;i<i_len-1;i++)
		{
			cout << current->data << "->";
			current = current->pre;
		}
		cout << current->data;
		cout << endl;
	}
	else if (direction == 'R')
	{
		Node* current = p->next;
		cout << "Traverse it from lift to right:" << endl;
		for (int i = 0; i < i_len-1; i++)
		{
			cout << current->data << "->";
			current = current->next;
		}
		cout << current->data;
		cout << endl;
	}
	else
	{
		Node* current = p->next;
		cout << "Traverse it circularly" << endl;
		int i=100;
		while(i--)
		{
			cout << current->data << "->";
			current = current->next;
		}
		cout << current->data;
		cout << endl;
	}
	return true;
}

bool List::modification(int i,Node node)
{
	Node* temp = p->next;
	while (i)
	{
		temp = temp->next;
		i--;
	}
	temp->data = node.data;
	return true;
}

bool List::modification(Node old_node, Node new_node)
{
	Node* temp = p->next;
	while (temp->data != old_node.data)
	{
		temp = temp->next;
	}
	temp->data = new_node.data;
	return true;
}