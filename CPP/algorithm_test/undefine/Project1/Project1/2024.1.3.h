
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>

typedef struct MENU //MenuSystem
{
	char name[20];
	int price;
	char type[10];
	struct MENU* next;
}MU;

void tips();

int Menuemp(MU* key);
void Menupush(MU* key);
void Menupop(MU* key);
void MenuFind(MU* key);
void Menurev(MU* key);
void Menuinit(MU* key);
void Menustore(MU* key);
void Price(MU* pHead);
void Menuallshow(MU* key);
void Menutypeshow(MU* key);