#include<stdio.h>
#include<iostream>
using namespace std;

//��typedef��˵���������͸���������struct Node����ListNode��ListNode*����ListNodePtr��
//��ListNode��˵������Ч��ListNode*���д�����...
//�о��Ҹ���ûѧ��ָ��...���˼�����

typedef int element;//�洢���������ͣ�����ϰ��д��int��

typedef enum status//����״̬��ö�٣�������ô�̵ģ�Ӧ���Ƕ��巵�����ͣ�
{
	success,fail,fatal,error
}status;

typedef struct Node//��������Կ�һ��c��������ҵ��lv1_p11��
{
	element data;
	struct Node *next;//ָ����һ��node��ָ�룻
}ListNode;

class linklist
{
public:
	status list_head(ListNode *L);//�����µĿ������β�L��
	void list_destory(ListNode *L);//�ͷ������β�L��
	void list_clear(ListNode *L);//������ݣ�˳��ɾ��Node��
	bool list_empty(ListNode *L);//�ж��Ƿ�ֻʣ��ͷ��㣻
	int list_size(ListNode *L);//�������ȣ�
	status list_pull(ListNode *L, element *elem, int point);//ȡ�����ݣ���Ҫ֪���������е�����λ�ã����ظ����ݵ�elem�У�
	status list_locate(ListNode *L, element elem, int *point);//����ָ�����ݣ����ظ����ݵ�node��ŵ�point�У�
	status list_insert(ListNode *L, element elem, int point);//����һ��node������λ��Ϊpoint���Դ�Ԫ��elem��
	status list_remove(ListNode *L, int point);//�Ƴ�һ��node���Ƴ�λ��Ϊpoint��
	//status list_prior(ListNode L, element *elem, int point);//��ǰ������������pull or locate�Ļ������޸ģ�
	//status list_next(ListNode L, element *elem, int point);//���̣���������pull or locate�Ļ������޸ģ�
private:
	ListNode *p,*q,*s;//���ֲ���������Ҫ�õ������ƶ�ָ�룻
	status result;//���ֲ����������Ľ����
	int count;//������
};

//��������׶�
status linklist::list_head(ListNode *L){
	result = fatal;
	L = new ListNode;
	if (L != NULL)
	{
		(*L).next = NULL;
		result = success;
	}
	return result;
}

void linklist::list_destory(ListNode *L){
	list_clear(L);
	delete L;
}

void linklist::list_clear(ListNode *L){
	p = L;
	q = p->next;
	while (q)//�ӵڶ�λ��ʼɾ������ʼ�ղ��ϣ�
	{
		p->next = q->next;
		delete q;
		q = p->next;
	}
}

bool linklist::list_empty(ListNode *L){
	p = L;
	if (p->next == NULL) return true;
	else return false;
}

//ͷ����ǲ����ڳ�������ģ�
int linklist::list_size(ListNode *L){
	p = L;
	count = 0;
	while (p != NULL)
	{
		count += 1;
		p = p->next;
	}
	return count;
}

status linklist::list_pull(ListNode *L, element *elem, int point){
	result = error;
	p = L;
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

status linklist::list_locate(ListNode *L, element elem, int *point){
	result = fail;
	p = L;
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

status linklist::list_insert(ListNode *L, element elem, int point){
	result = error;
	s = new ListNode;
	s->data = elem;
	p = L;
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

status linklist::list_remove(ListNode *L, int point){
	result = error;
	p = L;
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