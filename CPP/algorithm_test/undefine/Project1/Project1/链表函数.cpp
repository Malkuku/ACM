//#define _CRT_SECURE_NO_WARNINGS 1
//#include"function_head.h"
//
//void Print(Node* head)//�򵥵Ĵ�ӡ
//{
//	if (head->next == NULL) return;
//	Node* h = head->next;
//	while (h != NULL)
//	{
//		std::cout << "val:" << h->val << " name:" << h->name << " order:" << h->order << std::endl;
//		h = h->next;
//	}
//}
//
//void Add(Node* head)//����
//{
//	Node* h = head;
//	
//	while (h != NULL)
//	{
//		if (h->next == NULL)
//		{
//			Node* tmp = new Node(h->val + 1);
//			h->next = tmp;
//			break;
//		}
//		h = h->next;
//	}
//}
//
//void Search(Node* head, std::string x)
//{
//	if (head->next != NULL) 
//	{
//		Node* h = head->next;
//		while (h != NULL)
//		{
//			if (h->name == x)
//			{
//				std::cout << "�ҵ���" << std::endl;
//				std::cout << "val:" << h->val << " name:" << h->name << " order:" << h->order << std::endl;
//				return;
//			}
//			h = h->next;
//		}
//	}
//	std::cout << "û�������" << std::endl;
//}
//
//
//void Det(Node* head, std::string x)
//{
//	Node* h = head;
//	while (h->next != NULL)
//	{
//		if (h->next->name == x)
//		{
//			Node* tmp = h->next;
//			h->next = tmp->next;
//			delete tmp;
//			std::cout << "ɾ���ɹ�" << std::endl;
//			return;
//		}
//		h = h->next;
//	}
//	if (h->name == x)
//	{
//		Node* tmp = h;
//		h = NULL;
//		delete tmp;
//		std::cout << "ɾ���ɹ�" << std::endl;
//		return;
//	}
//
//	std::cout << "û�������" << std::endl;
//}
//
