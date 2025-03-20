#pragma once
#include<iostream>
#include<cstring>
#include<algorithm>

struct learn
{
	;
};

class stu
{
private:

public:
	std::string name;
	int order;
	struct learn;

	void Set()
	{
		std::cout << "name:";
		std::cin >> name;
		std::cout << "order:";
		std::cin >> order;
		std::cout << std::endl;
	}
};

typedef struct Node : stu
{
	friend class stu;
	int val;
	Node* next;
	Node(int x) : val(x), next(NULL) { Set(); }
	Node(int x,int set) : val(x), next(NULL) {}
	Node(int x, Node* next) : val(x), next(next = NULL) {}
};

//funtion
void Print(Node*);
void Add(Node*);
void Search(Node*,std::string);
void Det(Node*,std::string);
