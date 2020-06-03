
#define LEN 10
#define MLEN 30


typedef struct bger_data_
{
	char name[LEN];	// 버거이름
	int  price;		// 버거 가격

}bger_data;

bger_data burger_menu[LEN] = {
	{"1_burger",5000},{"2_burger",5000},{"3_burger",5000},{"4_burger",5000},{"5_burger",5000},
	{"6_burger",5000},{"7_burger",5000},{"8_burger",5000},{"9_burger",5000},{"10_burger",5000}
};

typedef struct mOrder_
{
	bger_data my_buger; // 고객이 주문한 버거 저장

}Order;


#pragma once
