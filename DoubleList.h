#ifndef LIST_H
#define LIST_H
#include "iostream"
using namespace std;
class Node
{
public:
	Node(int x) { data = x; }
	Node() {}
	int data;
	Node* next;
	Node* pre;
};

class List
{
public:
	List();     //构造函数，初始化链表
	~List();    //析构函数，释放堆中内存空间
	void clean();    //清空
	bool empty();    //  判空
	int length();    //  获取链表长度
	bool inser_head(Node node);          //插入头节点
	bool inser_tail(Node node);          //插入尾节点
	bool inser(Node node, int location);      //插入任意节点（不能插到已有链表空间外）
	bool delete_head();            //删除头节点
	bool delete_tail();            //删除尾节点
	bool delete_Node(int location);           //删除任意节点
	bool get_i_node(int i, Node* i_node);                //获取下标为i的节点
	int get_node_i(Node node);                //查找第一次遇见node时的下标
	bool get_pre_node(Node node, Node* pre_node);             //获取node的前一个节点
	bool get_next_node(Node node, Node* next_node);                 //获取node的后一个节点
	bool traverse(char direction);           //遍历链表
	bool modification(int i,Node node);
	bool modification(Node old_node,Node new_node);
private:
	Node* p;       //链表头指针
	int i_len;     //链表长度
};

#endif