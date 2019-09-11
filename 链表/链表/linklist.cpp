//��typedef��˵���������͸���������struct Node����ListNode��ListNode*����ListNodePtr��
//��ListNode��˵������Ч��ListNode*���д�����...
//�о��Ҹ���ûѧ��ָ��...���˼�����
#include<iostream>

typedef int element;//�洢���������ͣ�����ϰ��д��int��
typedef enum status//����״̬��ö�٣�������ô�̵ģ�Ӧ���Ƕ��巵�����ͣ�
{
	success,fail,fatal,error
}status;
typedef class Node//��������Կ�һ��c��������ҵ��lv1_p11��
{
public:
	element data;
	class Node *next;//ָ����һ��node��ָ�룻
}ListNode;

//����Ϊ�����б�����������
extern status list_head(ListNode *L);//�����µĿ������β�L��
extern void list_destory(ListNode *L);//�ͷ������β�L��
extern void list_clear(ListNode *L);//������ݣ�˳��ɾ��Node��
extern bool list_empty(ListNode *L);//�ж��Ƿ�ֻʣ��ͷ��㣻
extern int list_size(ListNode *L);//�������ȣ�
extern status list_pull(ListNode *L, element *elem, int point);//ȡ�����ݣ���Ҫ֪���������е�����λ�ã����ظ����ݵ�elem�У�
extern status list_locate(ListNode *L, element elem, int *point);//����ָ�����ݣ����ظ����ݵ�node��ŵ�point�У�
extern status list_insert(ListNode *L, element elem, int point);//����һ��node������λ��Ϊpoint���Դ�Ԫ��elem��
extern status list_remove(ListNode *L, int point);//�Ƴ�һ��node���Ƴ�λ��Ϊpoint��
//status list_prior(ListNode L, element *elem, int point);//��ǰ������������pull or locate�Ļ������޸ģ�
//status list_next(ListNode L, element *elem, int point);//���̣���������pull or locate�Ļ������޸ģ�

//��������׶�

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
//�ӵڶ�λ��ʼɾ������ʼ�ղ��ϣ�
void list_clear(ListNode *L){
	ListNode *p = L, *q = p->next;
	while (q != NULL)//����ʼ���޷��жϣ�����
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

//ͷ������ڳ����
int list_size(ListNode *L){
	ListNode *p = L;
	int count = 1;
	while (p)//������զ�����ж��˻�
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