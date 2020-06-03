#include "list.h"

#define NUM 10

typedef struct Listarray_
{
	int front;				// Queue의 처음 들어온 고객 위치
	int rear;				// Queue에 가장 최근에 들어온 고객 위치

	List* Lst_ary;			// Queue의 동적할당을 위한 List 포인터(여러개의 링크드리스트를 만들기 위해)

	int buket;				// List* Lst_ary의 동적할당 받을때 사이즈
	int n_size;				// 고객의 현재 수


}Listarray;

#pragma once
