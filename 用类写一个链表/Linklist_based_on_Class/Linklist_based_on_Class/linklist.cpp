#include<iostream>
using namespace std;

//对typedef的说明：给类型更名，比如struct Node又名ListNode，ListNode*又名ListNodePtr；
//对ListPtr的说明：等效于ListNode*？有待考察...
//感觉我根本没学过指针...（菜鸡落泪

typedef int element;//存储的数据类型，这里习惯写成int；
typedef ListNodePtr List, *ListPtr;

typedef enum status//操作状态的枚举，书上这么教的，应该是定义返回类型？
{
	success,fail,fatal,error
}status;

typedef struct Node//不清楚可以看一下c的链表作业，lv1_p11；
{
	element data;
	struct Node *next;//指向下一个node的指针；
}ListNode,*ListNodePtr;

class linklist
{
public:
	status list_head(ListPtr L);//创建新的空链表，形参L；
	void list_destory(ListPtr L);//释放链表，形参L；
	void list_clear(ListPtr L);//清空数据，顺便删了Node；
	bool list_empty(ListPtr L);//判断是否只剩下头结点；
	int list_size(ListPtr L);//求链表长度；
	status list_pull(ListPtr L, element *elem, int point);//取出数据，需要知道在链表中的排序位置，返回该数据到elem中；
	status list_locate(ListPtr L, element elem, int *point);//查找指定数据，返回该数据的node编号到point中；
	status list_insert(ListPtr L, element elem, int point);//插入一个node，插入位置为point，自带元素elem；
	status list_remove(ListPtr L, int point);//移除一个node，移除位置为point；
	//status list_prior(ListPtr L, element *elem, int point);//求前驱，有需求在pull or locate的基础上修改；
	//status list_next(ListPtr L, element *elem, int point);//求后继，有需求在pull or locate的基础上修改；
private:
	ListNodePtr p,q,s;//各种操作里面需要用的自由移动指针；
	status result;//各种操作里面最后的结果；
	int count;//计数器
};

//函数定义阶段
status linklist::list_head(ListPtr L)
{
	result = fatal;
	*L = new ListNode;
	if (*L != NULL)
	{
		(*L).next = NULL;
		result = success;
	}
	return result;
}

void linklist::list_destory(ListPtr L)
{
	list_clear(L);
	delete (*L);
}

void linklist::list_clear(ListPtr L)
{
	p = (*L);
	q = p->next;
	while (q)//从第二位开始删，链表始终不断；
	{
		p->next = q->next;
		delete q;
		q = p->next;
	}
}

bool linklist::list_empty(ListPtr L)
{
	p = (*L);
	if (p->next == NULL) return true;
	else return false;
}

int linklist::list_size(ListPtr L)//头结点是不算在长度里面的；
{
	p = (*L);
	count = 0;
	while (p != NULL)
	{
		count += 1;
		p = p->next;
	}
	return count;
}

status linklist::list_pull(ListPtr L, element *elem, int point)
{
	result = error;
	p = (*L);
	count = 0;
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

status linklist::list_locate(ListPtr L, element elem, int *point)
{
	result = fail;
	p = (*L);
	count = 0;
	while (p != NULL)
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

status linklist::list_insert(ListPtr L, element elem, int point)
{
	result = error;
	s = new ListNode;
	s->data = elem;
	p = (*L);
	count = 0;
	while (p != NULL && count != point)
	{
		p = p->next;
		count += 1;
	}
	if (p != NULL)
	{
		q = p->next;
		p->next = s;
		s->next = q;
		result = success;
	}
	return result;
}

status linklist::list_remove(ListPtr L, int point)
{
	result = error;
	p = (*L);
	count = 0;
	while (p != NULL && count != point - 1)
	{
		p = p->next;
		count += 1;
	}
	if (p != NULL)
	{
		s = p->next;
		q = s->next;
		delete s;
		p->next = q;
		result = success;
	}
	return result;
}