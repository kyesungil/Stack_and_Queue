
#define LEN 10
#define MLEN 30


typedef struct bger_data_
{
	char name[LEN];	// �����̸�
	int  price;		// ���� ����

}bger_data;

bger_data burger_menu[LEN] = {
	{"1_burger",5000},{"2_burger",5000},{"3_burger",5000},{"4_burger",5000},{"5_burger",5000},
	{"6_burger",5000},{"7_burger",5000},{"8_burger",5000},{"9_burger",5000},{"10_burger",5000}
};

typedef struct mOrder_
{
	bger_data my_buger; // ���� �ֹ��� ���� ����

}Order;


#pragma once
