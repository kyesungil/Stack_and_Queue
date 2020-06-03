#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "List_array.h"
#include "order_data.h"


bool QueueIsFull(Listarray* Lst)
{
	return (Lst->front == ((Lst->rear + 1) % Lst->buket));
	//return Lst->n_size == Lst->buket
}

bool QueueIsEmpty(Listarray* Lst)
{
	return Lst->front == Lst->rear;
	//return Lst->n_size == 0
}

void buffer_clear()
{
	while (getchar() != '\n')
		continue;
}

void display_menu()
{
	printf("a = \"1_burger\" 5000��, b = \"2_burger\" 5000��\n");
}

/* �ʱ�ȭ �Լ� */
void Lit_ary_init(Listarray* Lst, int num, void (*destroy)(void* data))
{
	Lst->front = 0;
	Lst->rear = 0;

	Lst->Lst_ary = (List*)malloc(sizeof(List) * num);
	for (int i = 0; i < num; i++)
	{
		list_init(&Lst->Lst_ary[i], destroy);
		Lst->Lst_ary[i].client_number = i;
	}
	
	Lst->buket = num;
	Lst->n_size = 0;
}

/*
* function : ���° ��, ������ �ֱ�
*
* return   : ���� -1, ���� 0
* ����		1. Queue ���ִ��� Ȯ��
*			2. Order* data �����Ҵ�			
*			3. list_ins_next() ��ũ�帮��Ʈ ����
*			4. �߰��ֹ��� 2,3 �ݺ�
*			5. Listarray�� rear +1 (��ѷ��̼ǿ���)
			6. Listarray�� n_size +1
*/
int Lit_ary_insert_enqueue(Listarray* Lst)
{
	// �����ִ��� Ȯ��
	if (QueueIsFull(Lst))
	{
		printf("��Ⱑ ��á���ϴ�\n");
		return -1;
	}

	bool flag = true;

	// �޴�
	display_menu();

	// �޴� ���� -> list_ins_next
	while (1)
	{
		printf("�޴� �Է����ּ���\n>>");
		char ch = getchar();
		buffer_clear();

		// ������ �����Ҵ�
		Order* new_order = (Order*)malloc(sizeof(Order));
		if (new_order == NULL)
		{
			printf("Allocate Memory error\n");
			return -1;
		}

		switch (ch)
		{
		case 'a':
			new_order->my_buger = burger_menu[0];
			flag = true;
			break;
		case 'b':
			new_order->my_buger = burger_menu[1];
			flag = true;
			break;
		case 'e':
			free(new_order);
			exit(1);
			break;
		default:
			printf("���� �޴��Դϴ�. �ٽ� �������ּ���\n");
			flag = false;
			break;
		}

		if (flag)
		{
			// Linkedlist link
			if ((list_ins_next(&(Lst->Lst_ary[Lst->n_size]), (Lst->Lst_ary[Lst->n_size]).tail, new_order)) == 0)
				printf("�ֹ� ����\n");
			else
				printf("�ֹ� ����\n");

			// �߰� ���� -> list_ins_next
			printf("�߰� �ֹ� �Ͻðڽ��ϱ�?((Y)ES or (N)O)");
			ch = getchar();
			buffer_clear();

			if (ch == 'N')
				break;
		}
	}

	Lst->rear = (Lst->rear + 1) % Lst->buket;
	
	Lst->n_size++;		// �ֹ��� ���� ��
	return 0;
}

/*
* function : ��ü �ֹ��� �޴����
* 
* return   : ����
* ����		1. queue�� index�� Ȯ�� (��ⷹ�̼� �������� �����ϸ鼭 ���� Ȯ��)
*			2. Listarray 0-index���� ������ִ� �ֹ� ������ ��� (head���� ���)
*/
void print_client_order(Listarray* Lst)
{
	ListElmt* search;

	for (int i = Lst->front; i != Lst->rear; i = ((i + 1) % Lst->buket))
	{
		printf("Client_Number : [%d]\n", Lst->Lst_ary[i].client_number);
		for (search = Lst->Lst_ary[i].head; search != NULL; search = search->next)
		{
			printf("%-10s %-10d\n", ((Order*)search->data)->my_buger.name, ((Order*)search->data)->my_buger.price);
		}
		printf("=================================================\n");
	}
}

/* 
* function : Queue dequeue, �ֹ��޴� ��� 
*
* return   :  ���� -1, ����: �ֹ���ȣ
* ����		1. Queue ����ִ��� Ȯ��
*			2. Listarray�� front��ġ �ֹ������͵� dequeue (list_destroy�� �̿��ؼ�)
*			3. Listarray�� front +1 (��ⷹ�̼ǿ��� �̿�)
*			4. Listarray �� �����ͼ� -1
*/
int Lit_ary_insert_Dequeue(Listarray* Lst)
{
	int tmp;

	// ����ִ��� Ȯ��
	if (QueueIsEmpty(Lst))
	{
		printf("Queue is empty\n");
		return -1;
	}

	tmp = Lst->Lst_ary[Lst->front].client_number;
	list_destroy(&(Lst->Lst_ary[Lst->front]));

	Lst->front = (Lst->front + 1) % Lst->buket;

	Lst->n_size--;

	return tmp;
}

/*
* function : k�� ����->�ֹ������� �̸����� �ֹ����(����)
*
* return   : ����
* ����		1. k���� �ֹ��� �޴��� ��� (print_client_order(Listarray* Lst) ����)
*			2. ����� �޴� �Է� (char mfind[20])
*			3. �ֹ������͵�� �Է��� ��Ҹ޴� head���� strcmp�� �̿��ؼ� ��, 
*			   (search = heead, search = search->next�� �ϳ��� ���� ��)
*			4. strcmp == 0�̸� break; (prev�� search�� �������)
*			5. list_rem_next()�Լ� �̿��ؼ� ����
*			6. k���� �ֹ��� �ֹ������Ͱ� ������ list_destroy()�Լ� �̿��ؼ� k�� ����, Listarray�� n_size(��������) -1 
*/
void Lit_ary_cancel(Listarray* Lst, int k)
{
	ListElmt* search;
	printf("%d���� �ֹ��� �޴�\n", Lst->Lst_ary[k].client_number);
	for (search = Lst->Lst_ary[k].head; search != NULL; search = search->next)
	{
		printf("%-10s %-10d\n", ((Order*)search->data)->my_buger.name, ((Order*)search->data)->my_buger.price);
	}
	printf("=================================================\n");


	printf("-----------------------------------------\n");

	char mfind[20];
	int i = 1;

	// ã�� �ܾ� �Է�
	printf("�ֹ� ����� �޴�\n>>");
	while (1)
	{
		// mfind�� �Է� �ߴ��� Ȯ��
		if (scanf("%[^\n]%*c", mfind) == 0)
		{
			printf("Please enter a word to find\n>>");
			buffer_clear(); // ���۸� �������� ������ ���� �ݺ��ȴ�.
		}
		else
			break;
	}

	ListElmt* prev = NULL;
	Order* dlt_data;
	// mfind�� ���Ե� diary���
	for (search = Lst->Lst_ary[k].head; search != NULL; search = search->next)
	{
		if (strcmp(((Order*)search->data)->my_buger.name, mfind) == 0)
			break;
		else
			prev = search;
	}

	if (list_rem_next(&Lst->Lst_ary[k], prev, &dlt_data) == 0)
	{
		printf("�޴� %s ���\n", dlt_data->my_buger.name);
		free(dlt_data);
	}
	else
		printf("�ص� �޴� ����\n");
	
	if (&Lst->Lst_ary[k].size == 0)
	{
		list_destroy(&Lst->Lst_ary[k]);
		Lst->n_size--;
	}
}


int main()
{
	Listarray my_listarry;

	Lit_ary_init(&my_listarry, 5, NULL);
	
	Lit_ary_insert_enqueue(&my_listarry);

	Lit_ary_insert_enqueue(&my_listarry);

	printf("�ֹ���ȣ [%d] ����\n", Lit_ary_insert_Dequeue(&my_listarry));

	Lit_ary_cancel(&my_listarry, 1);

	print_client_order(&my_listarry);


	return 0;
}
