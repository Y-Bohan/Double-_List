#include "DoubleList.h"
#include "iostream"
#include "windows.h"
using namespace std;
List::List()   /*���캯�������ڴ���һ������*/
{
	p = new Node;   /*���������ڴ�ռ�*/
	p->data = 0;     /*����ͷ��������ݣ����Դ�����������*/
	p->next = NULL;
	p->pre = NULL;
	i_len =0;   /*�����ȳ�ʼ��Ϊ0*/
	cout << "The linked list was created successfully" << endl;
}

List::~List()   /*���������������ͷ��ڴ�ռ�*/
{
	clean();
	delete p;
	p = NULL;
}

void List::clean()   /*�����������*/
{
	Node *current = p->next;
	Node* temp = NULL;
	for(int i=0;i<i_len;i++)  /*������ʽ�ṹ�����ҵ��¸���㲢ɾ����ǰ���*/
	{
		temp = current->next;
		delete current;
		current = temp;
	}
	current = NULL;
	p->next = NULL;
	i_len = 0;  /*ɾ�����н�������������*/
}

bool List::empty()  /*�п�*/
{
	return i_len == 0 ? true : false;
}

int List::length()  /*��ȡ������*/
{
	return i_len;
}

bool List::inser_head(Node node)   
{
	cout << "insert head_node" << endl;
	if (i_len == 0)   //�������Ϊ�գ���ͷ�ڵ����ֻ������һ���ڵ㼴��
	{
		Node* new_head = new Node;   /*��Ϊ���²���Ľڵ㣬���Ա����ڶ��������ڴ棬������ִ����ɺ���Զ��ͷ��ڴ�*/
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
		i_len++;    //��ʱ�½���Ѿ����룬����++���������������Ѱ�ҵ�β�ڵ��Ǵ����
		Node* tail_node=p;
		for (int i = 0; i < i_len; i++)   //�����������ҵ�����β�ڵ�
			tail_node = tail_node->next;
		new_head->pre = tail_node;         //ͷָ��β 
		tail_node->next = new_head;      //βָ��ͷ
	}
	return true;
}

bool List::inser_tail(Node node)
{
	cout << "insert tail_node" << endl;
	if (i_len == 0)   //�������Ϊ�գ������β�����൱�ڲ���ͷ���
	{
		inser_head(node);   //ע��inser_head�������Ѿ���i_len++,���Դ˴�������i_len++
	}
	else
	{
		Node* new_tail = new Node;
		new_tail->data = node.data;
		Node* old_tail = p;
		for (int i = 0; i < i_len; i++)   //�����������ҵ�����β�ڵ�
		{
			old_tail = old_tail->next;
		}
		old_tail->next = new_tail;
		new_tail->pre = old_tail;
		new_tail->next = p->next;   //β���ָ��ͷ���
		p->next->pre = new_tail;	//ͷ���ָ��β���
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
	else      //��ʱi_len���ٴ��ڵ���2����Ϊ��i_len==1ʱ��i==1ʱ��i == i_len����������i==0ʱ����ִ����һ��
	{
		Node* i_node = new Node;
		i_node->data = node.data;
		Node* i_node_pre = p;
		while (i > 0)     //�ҵ���i�Ž���ǰһ�����
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
	if (i_len == 1)   //��ʱ�൱��ɾ��ͷ���
	{
		delete_head();   //delete_head()�������Ѿ���i_len--,�˴�������i_len--
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
			for (int i = 0; i < i_len; i++)			//�����������ҵ�����β�ڵ�
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
	if (i<0 || i>=i_len)    //��һ������±��Ǵ�0��ʼ�ģ�����β�����±�Ϊi_len-1
	{
		cout << "can not delete" << endl;
		return false;
	}

	if (i == 0 || i == i_len-1)
	{
		i == 0 ? delete_head() : delete_tail();    //delete_head()������delete_tail()�������Ѿ���i_len--
		return true;
	}
	else   //��ʱi_len����Ϊ3
	{
		cout << "delete node" << endl;
		Node* i_node = p->next;
		while (i > 0)   //�ҵ��±�Ϊi�Ľ��
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
		for (int i = 0; i < i_len; i++)    //�����������ҵ�����β�ڵ�
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