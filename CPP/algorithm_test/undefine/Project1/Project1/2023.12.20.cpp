#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int i = 0, j = 1, k = 2;
//	k = i++ && j++;
//	std::cout << k;
//	while (i = 0) printf("S ");
//	printf("\n");
//	int x[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	for (int i = 0; i < 3; i++)printf("%d ", x[i][2 - i]);
//	char arr4[3] = { 'a',98,'c' };
//	char* p1 = (char*)"sdad";
//	int* p = &s, s;
//	int i = 5;void* p = &i;
//	int* p, i;
//	int i, * p = &i;
//	return 0;
//}

//#include<iostream>
//int main()
//{
//	float US$_;
//	int _int123;
//	int $;
//	int _123;
//
//	switch (1+1)
//	{
//	case 1+1:
//		printf("sb");
//	case 'A':;
//	}
//
//	int i = 10;
//	int* pi = &i;
//	void* pj = &i;
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//
//typedef struct Node
//{
//    int data;
//    Node* next;
//} Node;
//
//
//Node* mSortList(Node* head1, Node* head2) {
//    if (head1 == NULL) return head2;
//    if (head2 == NULL) return head1;
//    Node* res, * p;
//    if (head1->data < head2->data) {
//        res = head1;
//        head1 = head1->next;
//    }
//    else {
//        res = head2;
//        head2 = head2->next;
//    }
//    p = res;
//    while (head1 != NULL && head2 != NULL) {
//        if (head1->data < head2->data) {
//            p->next = head1;
//            head1->pre = p;
//            head1 = head1->next;
//        }
//        else {
//            p->next = head2;
//            head2->pre = p;
//            head2 = head2->next;
//        }
//        p = p->next;
//    }
//    if (head1 != NULL) {
//        p->next = head1;
//        head1->pre = p;
//    }
//    else if (head2 != NULL) {
//        p->next = head2;
//        head2->pre = p;
//    }
//    return res;
//}
//
//Node* MergeSortList(Node* head) {
//    if (head == NULL || head->next == NULL) return head;
//    //ʹ�ÿ���ָ�붨λ�е����partition
//    Node* fast = head, * slow = head;
//    while (fast->next != NULL && fast->next->next != NULL) {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    fast = slow;
//    slow = slow->next;
//    fast->next = NULL;
//    slow->pre = NULL;
//    fast = my_msort(head);
//    slow = my_msort(slow);
//    return merge(fast, slow);
//}
//


//#include <iostream>
//using namespace std;
//
//// ��������ڵ�ṹ��
//struct ListNode {
//    int val;
//    ListNode* next;
//
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
////�ϲ�������
//ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
//    if (l1 == nullptr) return l2;
//    else if (l2 == nullptr) return l1;
//
//    // �����µ�ͷ�ڵ�
//    ListNode* dummy = new ListNode(-1);
//    ListNode* curr = dummy;
//
//    while (l1 != nullptr && l2 != nullptr) {
//        if (l1->val <= l2->val) {
//            curr->next = l1;
//            l1 = l1->next;
//        }
//        else {
//            curr->next = l2;
//            l2 = l2->next;
//        }
//
//        curr = curr->next;
//    }
//
//    // ��δ��ɺϲ��Ĳ������ӵ����
//    if (l1 != nullptr) curr->next = l1;
//    if (l2 != nullptr) curr->next = l2;
//
//    ListNode* tmp = dummy->next;
//    delete dummy;
//    return tmp;
//}
//
////����
//ListNode* sortList(ListNode* head) { 
//    if (head == nullptr || head->next == nullptr) return head;//�����ٷ���
//
//    // ʹ�ÿ����ҵ������м�λ�õ�ָ��
//    ListNode* slow = head, * fast = head;
//    while (fast->next != nullptr && fast->next->next != nullptr) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    // �Ͽ�����Ϊ����
//    ListNode* mid = slow->next;
//    slow->next = nullptr;
//
//    // ��������������еݹ�����
//    ListNode* left = sortList(head), * right = sortList(mid);
//
//    // �ϲ��Ѿ����������������
//    return mergeTwoSortedLists(left, right);
//}
//
//int main() {
//    // ��������
//    ListNode* node4 = new ListNode(5);
//    ListNode* node3 = new ListNode(3);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node1 = new ListNode(1);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//
//    ListNode* sortedHead = sortList(node1);
//
//    // ���������
//    cout << "��������";
//    while (sortedHead != nullptr) {
//        cout << sortedHead->val << " ";
//        sortedHead = sortedHead->next;
//    }
//    cout << endl;
//
//    return 0;
//}


