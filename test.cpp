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
	List my_lis;     //����һ������
	my_lis.inser(node4, 0);   //0��λ�ýڵ����
	my_lis.inser(node5, 0);   //0��λ�ýڵ����
	my_lis.inser(node6, 0);   //0��λ�ýڵ����
	my_lis.inser(node7, 2);   //2��λ�ýڵ����
	my_lis.inser(node2, 2);   //2��λ�ýڵ����
	my_lis.inser(node3, 5);   //5��λ�ýڵ����
	my_lis.traverse('R');    //6->5->2->7->4->3
	my_lis.modification(3, node1);    //���ĵ�3�Žڵ�Ϊnode1
	my_lis.traverse('L');    //3->4->1->2->5->6

	Node temp;
	my_lis.get_i_node(3,&temp);    //��ȡ3��λ�ýڵ�
	cout << temp.data << endl;


	my_lis.delete_Node(5);    //ɾ��5�Žڵ�
	my_lis.delete_Node(0);    //ɾ��0�Žڵ�
	my_lis.delete_Node(2);    //ɾ��2�Žڵ�
	my_lis.traverse('R');    //5->2->4	
	my_lis.clean();		//���
	my_lis.traverse('R');     //�Ѿ���գ�����û�нڵ�
	return 0;
}

/*void menu1(void)
{
	int flag = 0;  //�����Ƿ��Ѿ�������־λ

	while (1)
	{
		cout << "����������ѡ������ֽ���ѡ��:" << endl;
		cout << "	1.����һ������\n	2.�������в�����\n	3.ɾ�����\n	4.��ȡָ���±��Ԫ��" << endl;
		cout << "	5.��ȡָ��Ԫ�ص��±�\n	6.�����ұ���\n	7.���ҵ������\n	8.ѭ������" << endl;
		cout << "	9.�޸�ָ���±��Ԫ��ֵ\n	10.�޸�Ԫ�ص�ֵ\n	11.�˳�"<< endl;
		int num = 0;
		cin >> num;
		cout << endl;
		switch (num)
		{
		case 1: 
			menu2(); return;
			break;
		case 2:	
			cout << "����,����δ����" << endl; break;
		case 3:	cout << "����,����δ����" << endl; break;
		case 4:	cout << "����,����δ����" << endl; break;
		case 5:	cout << "����,����δ����" << endl; break;
		case 6:	cout << "����,����δ����" << endl; break;
		case 7:	cout << "����,����δ����" << endl; break;
		case 8:	cout << "����,����δ����" << endl; break;
		case 9:	cout << "����,����δ����" << endl; break;
		case 10:	cout << "����,����δ����" << endl; break;
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
		cout << "����������ѡ������ֽ���ѡ��:" << endl;
		cout << "	1.����һ������\n	2.�������в�����\n	3.ɾ�����\n	4.��ȡָ���±��Ԫ��" << endl;
		cout << "	5.��ȡָ��Ԫ�ص��±�\n	6.�����ұ���\n	7.���ҵ������\n	8.ѭ������" << endl;
		cout << "	9.�޸�ָ���±��Ԫ��ֵ\n	10.�޸�Ԫ�ص�ֵ\n	11.�˳�" << endl;
		int num = 0;
		cin >> num;
		cout << endl;
		switch (num)
		{
		case 1:
			cout << "����,�����Ѿ�����" << endl; break;;
			break;
		case 2:
		{
			int data, i;
			Node node;
			cout << "�����������ݣ�" << endl;
			cin >> data;
			node.data = data;
			cout << "���������±꣺" << endl;
			cin >> i;
			my_lis.inser(node, i);
			break;
		}
		case 3:	
		{
			int i;
			cout << "����ɾ�������±�" << endl;
			cin >> i;
			my_lis.delete_Node(i);
			break;
		}
		case 4:	
		{
			int i;
			Node i_node;
			cout << "����ָ���±�" << endl;
			cin >> i;
			my_lis.get_i_node(i, &i_node);
			cout << "list[" << i << "]= " << i_node.data << endl;
			break;
		}
		case 5:	
		{
			Node node;
			cout << "������Ҫ��ѯ�±��Ԫ��ֵ��" << endl;
			cin >> node.data;
			cout << node.data<<"���ڵ��±�Ϊ " << my_lis.get_node_i(node) << endl;
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
			cout << "������Ҫ�޸�Ԫ�ص��±꣺" << endl;
			cin >> i;
			cout << "�����޸ĺ��Ԫ��ֵ��" << endl;
			cin >> node.data;
			my_lis.modification(i, node);
		}  break;
		case 10: 
		{
			Node old_node, new_node;
			cout << "������Ҫ�޸ĵ�Ԫ�أ�" << endl;
			cin >> old_node.data;
			cout << "�����޸ĺ��Ԫ��ֵ��" << endl;
			cin >> new_node.data;
			my_lis.modification(old_node, new_node);
		}break;
		case 11:	return; break;
		}
		cout << endl;
	}
}*/

