#include "list.h"

#define NUM 10

typedef struct Listarray_
{
	int front;				// Queue�� ó�� ���� �� ��ġ
	int rear;				// Queue�� ���� �ֱٿ� ���� �� ��ġ

	List* Lst_ary;			// Queue�� �����Ҵ��� ���� List ������(�������� ��ũ�帮��Ʈ�� ����� ����)

	int buket;				// List* Lst_ary�� �����Ҵ� ������ ������
	int n_size;				// ���� ���� ��


}Listarray;

#pragma once
