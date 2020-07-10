#include "DoubleList.h"
#include "iostream"
using namespace std;
//void menu1(void);
//void menu2(void);

int main()
{
	//menu1();
	Node node1(1);
	Node node2(2);
	Node node3(3);
	Node node4(4);
	Node node5(5);
	Node node6(6);
	Node node7(7);
	List my_lis;     //创建一个链表
	my_lis.inser(node4, 0);   //0号位置节点插入
	my_lis.inser(node5, 0);   //0号位置节点插入
	my_lis.inser(node6, 0);   //0号位置节点插入
	my_lis.inser(node7, 2);   //2号位置节点插入
	my_lis.inser(node2, 2);   //2号位置节点插入
	my_lis.inser(node3, 5);   //5号位置节点插入
	my_lis.traverse('R');    //6->5->2->7->4->3
	my_lis.modification(3, node1);    //更改第3号节点为node1
	my_lis.traverse('L');    //3->4->1->2->5->6

	Node temp;
	my_lis.get_i_node(3,&temp);    //获取3号位置节点
	cout << temp.data << endl;


	my_lis.delete_Node(5);    //删除5号节点
	my_lis.delete_Node(0);    //删除0号节点
	my_lis.delete_Node(2);    //删除2号节点
	my_lis.traverse('R');    //5->2->4	
	my_lis.clean();		//清空
	my_lis.traverse('R');     //已经清空，所以没有节点
	return 0;
}

/*void menu1(void)
{
	int flag = 0;  //链表是否已经创建标志位

	while (1)
	{
		cout << "请输入以下选项的数字进行选择:" << endl;
		cout << "	1.创建一个链表\n	2.向链表中插入结点\n	3.删除结点\n	4.获取指定下标的元素" << endl;
		cout << "	5.获取指定元素的下标\n	6.从左到右遍历\n	7.从右到左遍历\n	8.循环遍历" << endl;
		cout << "	9.修改指定下标的元素值\n	10.修改元素的值\n	11.退出"<< endl;
		int num = 0;
		cin >> num;
		cout << endl;
		switch (num)
		{
		case 1: 
			menu2(); return;
			break;
		case 2:	
			cout << "错误,链表未创建" << endl; break;
		case 3:	cout << "错误,链表未创建" << endl; break;
		case 4:	cout << "错误,链表未创建" << endl; break;
		case 5:	cout << "错误,链表未创建" << endl; break;
		case 6:	cout << "错误,链表未创建" << endl; break;
		case 7:	cout << "错误,链表未创建" << endl; break;
		case 8:	cout << "错误,链表未创建" << endl; break;
		case 9:	cout << "错误,链表未创建" << endl; break;
		case 10:	cout << "错误,链表未创建" << endl; break;
		case 11:	return; break;
		}
		cout << endl;
	}
}

void menu2()
{
	List my_lis;
	while (1)
	{
		cout << "请输入以下选项的数字进行选择:" << endl;
		cout << "	1.创建一个链表\n	2.向链表中插入结点\n	3.删除结点\n	4.获取指定下标的元素" << endl;
		cout << "	5.获取指定元素的下标\n	6.从左到右遍历\n	7.从右到左遍历\n	8.循环遍历" << endl;
		cout << "	9.修改指定下标的元素值\n	10.修改元素的值\n	11.退出" << endl;
		int num = 0;
		cin >> num;
		cout << endl;
		switch (num)
		{
		case 1:
			cout << "错误,链表已经创建" << endl; break;;
			break;
		case 2:
		{
			int data, i;
			Node node;
			cout << "输入插入的数据：" << endl;
			cin >> data;
			node.data = data;
			cout << "输入插入的下标：" << endl;
			cin >> i;
			my_lis.inser(node, i);
			break;
		}
		case 3:	
		{
			int i;
			cout << "输入删除结点的下标" << endl;
			cin >> i;
			my_lis.delete_Node(i);
			break;
		}
		case 4:	
		{
			int i;
			Node i_node;
			cout << "输入指定下标" << endl;
			cin >> i;
			my_lis.get_i_node(i, &i_node);
			cout << "list[" << i << "]= " << i_node.data << endl;
			break;
		}
		case 5:	
		{
			Node node;
			cout << "输入需要查询下标的元素值：" << endl;
			cin >> node.data;
			cout << node.data<<"所在的下标为 " << my_lis.get_node_i(node) << endl;
			break;
		}
		case 6:	
			my_lis.traverse('R');
			break;
			break;
		case 7:	
			my_lis.traverse('L'); break;
		case 8:
			my_lis.traverse('C');
			 break;
		case 9:
		{
			int i;
			Node node;
			cout << "输入需要修改元素的下标：" << endl;
			cin >> i;
			cout << "输入修改后的元素值：" << endl;
			cin >> node.data;
			my_lis.modification(i, node);
		}  break;
		case 10: 
		{
			Node old_node, new_node;
			cout << "输入需要修改的元素：" << endl;
			cin >> old_node.data;
			cout << "输入修改后的元素值：" << endl;
			cin >> new_node.data;
			my_lis.modification(old_node, new_node);
		}break;
		case 11:	return; break;
		}
		cout << endl;
	}
}*/

