# Stack_and_Queue
# 2. Queue  
# 2.2 Ring_Queue or Circle_queue  
## A. 구성  
- __마커(위치 표시)__  

	- tail은 다음칸에 저장되어야할 위치  
	- head는 현재 첫번째 데이터 위치    
- __Enqueue(인큐)동작 :__ 큐의 tail에 데이터 저장  
- __Dequeue(디큐)동작 :__ 큐의 head에서 데이터를 retrieval 
#### code>>  
```c  
/* Queue */
typedef struct Queue_
{
	int head;
	int tail;
	int item_size; // 아이템 개수
	student st_data[QSIZE]; // 학생 데이터 표현

}Queue;  
```  
## B. 함수 구현  
### 1. Full확인: IsFull(Queue* q)    
- (Tail+1) % QSIZE == Head 이면 Full  
- QSIZE(Queue공간)이 4라고 할때, 공간 모두 enqueue(data를 넣으면)하면 Empty와 구별이 되지 않기 때문에 부득이하게 한 공간은 사용하지 않는다.  
#### code>>  
```c  
/* queue 차있는지 확인 */
bool IsFull(Queue* q)
{
	return q->head == (q->tail + 1) % QSIZE;
}  
```  

### 2. Empty확인: IsEmpty(Queue* q)      
- Head와 Tail이 같으면 Empty  
#### code>>  
```c  
/* queue 비어있는지 확인 */
bool IsEmpty(Queue* q)
{
	return q->head == q->tail;
}  
```  

### 3. Enqueue: Enqueue(Queue* q, student st_data)      
1. Full인지 확인  
2. Tail index에 데이터 저장  
3. Tail = Tail + 1 (Tail = (Tail+1) % QSZIE) QSIZE 오버 방지 
#### code>>  
```c  
/* Enqueue */
bool Enqueue(Queue* q, student st_data)
{
	if (IsFull(q))
	{
		printf("Queue is Full\n");
		return false;
	}
	else
	{
		// 현재 tail index에 data 넣어주고, tail + 1 
		q->st_data[q->tail] = st_data; 
		q->tail = (q->tail + 1) % QSIZE; // QSIZE 넘지 못하게 하기위해서 % 이용

		q->item_size++;
		return true;
	}
}  
```   
### 4. equeue: Dequeue(Queue* q, student* st_data)   
1. Empty인지 확인    
2. Head index에서 데이터 retrieval  
3. Head = Head + 1 (Head = (Head+1) % QSIZE)  
#### code>>  
```c  
/* Dequeue */
bool Dequeue(Queue* q, student* st_data)
{
	if (IsEmpty(q))
	{
		printf("Queue is Empty\n");
		return false;
	}
	else
	{
		// 현재 head index에 st_data 뻬고, head + 1
		*st_data = q->st_data[q->head];
		q->head = (q->head + 1) % QSIZE;

		q->item_size--;
		return true;
	}
}  
```  
## 그림으로 Ring_queue동작 확인  
### 1) 초기상태> Head = 0, Tail = 0  
![1](https://user-images.githubusercontent.com/41607872/83040081-d730ad80-a079-11ea-8fd4-c871f294099b.jpg)  
### 2) Enqueue>  Head = 0, Tail = 1 ( 0-index에 "Jame"저장 / Tail 한칸 이동 )  
![2](https://user-images.githubusercontent.com/41607872/83040089-d8fa7100-a079-11ea-942f-319c3f8ac745.jpg)  
### 3) Enqueue>  Head = 0, Tail = 2 ( 1-index에 "Jone"저장 / Tail 한칸 이동 )  
![3](https://user-images.githubusercontent.com/41607872/83040094-da2b9e00-a079-11ea-8b9b-04990151a0dc.jpg)  
### 4) Enqueue>  Head = 0, Tail = 3 ( 2-index에 "Kane"저장 / Tail 한칸 이동 ) -> Full상태: Head와 Tail 한칸차
![4](https://user-images.githubusercontent.com/41607872/83040099-dac43480-a079-11ea-9a30-3d8eae43ed11.jpg)  
### 5) Dequeue>  Head = 1, Tail = 3 ( 0-index에 "Jame" retrieval / Head 한칸 이동 )
![5](https://user-images.githubusercontent.com/41607872/83040100-dbf56180-a079-11ea-90f1-ceeacf1b09ca.jpg)
### 6) Dequeue>  Head = 2, Tail = 3 ( 1-index에 "Jone" retrieval / Head 한칸 이동 )
![6](https://user-images.githubusercontent.com/41607872/83040104-dc8df800-a079-11ea-933f-85e6f4cce272.jpg)
### 7) Dequeue>  Head = 3, Tail = 3 ( 2-index에 "Kane" retrieval / Head 한칸 이동 ) -> Empty상태: Head와 Tail 같은칸
![7](https://user-images.githubusercontent.com/41607872/83040109-ddbf2500-a079-11ea-9b2f-99e7195a102b.jpg)
