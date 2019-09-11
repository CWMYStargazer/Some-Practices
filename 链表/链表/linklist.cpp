//对typedef的说明：给类型更名，比如struct Node又名ListNode，ListNode*又名ListNodePtr；
//对ListNode的说明：等效于ListNode*？有待考察...
//感觉我根本没学过指针...（菜鸡落泪
#include<iostream>

typedef int element;//存储的数据类型，这里习惯写成int；
typedef enum status//操作状态的枚举，书上这么教的，应该是定义返回类型？
{
	success,fail,fatal,error
}status;
typedef class Node//不清楚可以看一下c的链表作业，lv1_p11；
{
public:
	element data;
	class Node *next;//指向下一个node的指针；
}ListNode;

//以下为操作列表（的声明）：
extern status list_head(ListNode *L);//创建新的空链表，形参L；
extern void list_destory(ListNode *L);//释放链表，形参L；
extern void list_clear(ListNode *L);//清空数据，顺便删了Node；
extern bool list_empty(ListNode *L);//判断是否只剩下头结点；
extern int list_size(ListNode *L);//求链表长度；
extern status list_pull(ListNode *L, element *elem, int point);//取出数据，需要知道在链表中的排序位置，返回该数据到elem中；
extern status list_locate(ListNode *L, element elem, int *point);//查找指定数据，返回该数据的node编号到point中；
extern status list_insert(ListNode *L, element elem, int point);//插入一个node，插入位置为point，自带元素elem；
extern status list_remove(ListNode *L, int point);//移除一个node，移除位置为point；
//status list_prior(ListNode L, element *elem, int point);//求前驱，有需求在pull or locate的基础上修改；
//status list_next(ListNode L, element *elem, int point);//求后继，有需求在pull or locate的基础上修改；

//函数定义阶段

status list_head(ListNode *L){
	status result = fatal;
	L = new ListNode;
	if (L != NULL)
	{
		(*L).next = NULL;
		result = success;
	}
	return result;
}

void list_destory(ListNode *L){
	list_clear(L);
	delete L;
}
//从第二位开始删，链表始终不断；
void list_clear(ListNode *L){
	ListNode *p = L, *q = p->next;
	while (q != NULL)//这里始终无法判断！！！
	{
		p->next = q->next;
		delete q;
		q = p->next;
	}
}

bool list_empty(ListNode *L){
	ListNode *p;
	p = L;
	if (p->next == NULL) return true;
	else return false;
}

//头结点算在长度里；
int list_size(ListNode *L){
	ListNode *p = L;
	int count = 1;
	while (p)//？？？咋不能判断了还
	{
		p = p->next;
		count += 1;
	}
	return count;
}

status list_pull(ListNode *L, element *elem, int point){
	status result = error;
	ListNode *p = L;
	int count = 1;
	while (p != NULL && count != point)
	{
		p = p->next;
		count += 1;
	}
	if (p != NULL)
	{
		*elem = p->data;
		result = success;
	}
	return result;
}

status list_locate(ListNode *L, element elem, int *point){
	status result = fail;
	ListNode *p = L;
	int count = 1;
	while (result == fail)
	{
		if (p->data == elem)
		{
			*point = count;
			result = success;
		}
		else
		{
			p = p->next;
			count += 1;
		}
	}
	return result;
}

status list_insert(ListNode *L, element elem, int point){
	status result = error;
	int count = 1;
	ListNode *s = new ListNode, *p = L, *q;
	s->data = elem;
	s->next = NULL;
	while (p && count != point)
	{
		p = p->next;
		count += 1;
	}
	if (p)
	{
		q = p->next;
		p->next = s;
		s->next = q;
		result = success;
	}
	return result;
}

status list_remove(ListNode *L, int point){
	status result = error;
	ListNode *p = L, *q, *s;
	int count = 1;
	while (p && count != point - 1)
	{
		p = p->next;
		count += 1;
	}
	if (p)
	{
		s = p->next;
		q = s->next;
		delete s;
		p->next = q;
		result = success;
	}
	return result;
}