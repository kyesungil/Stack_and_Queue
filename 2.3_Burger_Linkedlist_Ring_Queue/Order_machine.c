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
	printf("a = \"1_burger\" 5000원, b = \"2_burger\" 5000원\n");
}

/* 초기화 함수 */
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
* function : 몇번째 고객, 데이터 넣기
*
* return   : 실패 -1, 성공 0
* 설명		1. Queue 차있는지 확인
*			2. Order* data 동적할당			
*			3. list_ins_next() 링크드리스트 연결
*			4. 추가주문시 2,3 반복
*			5. Listarray의 rear +1 (모둘레이션연산)
			6. Listarray의 n_size +1
*/
int Lit_ary_insert_enqueue(Listarray* Lst)
{
	// 꽉차있는지 확인
	if (QueueIsFull(Lst))
	{
		printf("대기가 꽉찼습니다\n");
		return -1;
	}

	bool flag = true;

	// 메뉴
	display_menu();

	// 메뉴 선택 -> list_ins_next
	while (1)
	{
		printf("메뉴 입력해주세요\n>>");
		char ch = getchar();
		buffer_clear();

		// 데이터 동적할당
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
			printf("없는 메뉴입니다. 다시 선택해주세요\n");
			flag = false;
			break;
		}

		if (flag)
		{
			// Linkedlist link
			if ((list_ins_next(&(Lst->Lst_ary[Lst->n_size]), (Lst->Lst_ary[Lst->n_size]).tail, new_order)) == 0)
				printf("주문 성공\n");
			else
				printf("주문 실패\n");

			// 추가 선택 -> list_ins_next
			printf("추가 주문 하시겠습니까?((Y)ES or (N)O)");
			ch = getchar();
			buffer_clear();

			if (ch == 'N')
				break;
		}
	}

	Lst->rear = (Lst->rear + 1) % Lst->buket;
	
	Lst->n_size++;		// 주문한 고객의 수
	return 0;
}

/*
* function : 전체 주문고객 메뉴출력
* 
* return   : 없음
* 설명		1. queue의 index을 확인 (모듈레이션 연산으로 증가하면서 전부 확인)
*			2. Listarray 0-index부터 저장되있는 주문 데이터 출력 (head부터 출력)
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
* function : Queue dequeue, 주문메뉴 출력 
*
* return   :  실패 -1, 성공: 주문번호
* 설명		1. Queue 비어있는지 확인
*			2. Listarray의 front위치 주문데이터들 dequeue (list_destroy을 이용해서)
*			3. Listarray의 front +1 (모듈레이션연산 이용)
*			4. Listarray 고객 데이터수 -1
*/
int Lit_ary_insert_Dequeue(Listarray* Lst)
{
	int tmp;

	// 비어있는지 확인
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
* function : k고객 선택->주문데이터 이름비교후 주문취소(삭제)
*
* return   : 없음
* 설명		1. k고객이 주문한 메뉴들 출력 (print_client_order(Listarray* Lst) 참조)
*			2. 취소할 메뉴 입력 (char mfind[20])
*			3. 주문데이터들과 입력한 취소메뉴 head부터 strcmp을 이용해서 비교, 
*			   (search = heead, search = search->next로 하나씩 전부 비교)
*			4. strcmp == 0이면 break; (prev에 search전 노드저장)
*			5. list_rem_next()함수 이용해서 삭제
*			6. k고객이 주문한 주문데이터가 없으면 list_destroy()함수 이용해서 k고객 삭제, Listarray의 n_size(고객데이터) -1 
*/
void Lit_ary_cancel(Listarray* Lst, int k)
{
	ListElmt* search;
	printf("%d고객이 주문한 메뉴\n", Lst->Lst_ary[k].client_number);
	for (search = Lst->Lst_ary[k].head; search != NULL; search = search->next)
	{
		printf("%-10s %-10d\n", ((Order*)search->data)->my_buger.name, ((Order*)search->data)->my_buger.price);
	}
	printf("=================================================\n");


	printf("-----------------------------------------\n");

	char mfind[20];
	int i = 1;

	// 찾을 단어 입력
	printf("주문 취소할 메뉴\n>>");
	while (1)
	{
		// mfind에 입력 했는지 확인
		if (scanf("%[^\n]%*c", mfind) == 0)
		{
			printf("Please enter a word to find\n>>");
			buffer_clear(); // 버퍼를 지워주지 않으면 무한 반복된다.
		}
		else
			break;
	}

	ListElmt* prev = NULL;
	Order* dlt_data;
	// mfind가 포함된 diary출력
	for (search = Lst->Lst_ary[k].head; search != NULL; search = search->next)
	{
		if (strcmp(((Order*)search->data)->my_buger.name, mfind) == 0)
			break;
		else
			prev = search;
	}

	if (list_rem_next(&Lst->Lst_ary[k], prev, &dlt_data) == 0)
	{
		printf("메뉴 %s 취소\n", dlt_data->my_buger.name);
		free(dlt_data);
	}
	else
		printf("해동 메뉴 없음\n");
	
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

	printf("주문번호 [%d] 나옴\n", Lit_ary_insert_Dequeue(&my_listarry));

	Lit_ary_cancel(&my_listarry, 1);

	print_client_order(&my_listarry);


	return 0;
}
