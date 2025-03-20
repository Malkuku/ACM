//#define _CRT_SECURE_NO_WARNINGS 1
//#include"function_head.h"
//
//void menu()
//{
//	printf("请输入要进行的操作：\n");
//	printf("****** 1.增加 ******\n");
//	printf("****** 2.搜索 ******\n");
//	printf("****** 3.删除 ******\n");
//	printf("****** 4.打印 ******\n");
//	printf("****** 0.退出 ******\n");
//	printf(":");
//}
//
//int main()
//{
//	Node* head = new Node(0, 0);
//	std::string n;
//
//	int num;
//	do
//	{
//		menu();
//		std::cin >> num;
//		switch (num)
//		{
//		case 0:
//			std::cout << "退出！" << std::endl;
//			continue;
//		case 1:
//			Add(head);
//			continue;
//		case 2:
//			std::cout << "输入名字：";
//			std::cin >> n;
//			Search(head, n);
//			continue;
//		case 3:
//			std::cout << "输入名字：";
//			std::cin >> n;
//			Det(head, n);
//			continue;
//		case 4:
//			Print(head);
//			continue;
//		case 5:
//			continue;
//		default: std::cout << "nodata!" << std::endl;
//		}
//
//	} while(num);
//
//
//	//释放链表空间
//
//	return 0;
//}