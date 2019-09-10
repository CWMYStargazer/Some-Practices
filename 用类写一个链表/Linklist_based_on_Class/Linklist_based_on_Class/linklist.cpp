#include<iostream>
using namespace std;

//��typedef��˵���������͸���������struct Node����ListNode��ListNode*����ListNodePtr��
//��ListPtr��˵������Ч��ListNode*���д�����...
//�о��Ҹ���ûѧ��ָ��...���˼�����

typedef int element;//�洢���������ͣ�����ϰ��д��int��
typedef ListNodePtr List, *ListPtr;

typedef enum status//����״̬��ö�٣�������ô�̵ģ�Ӧ���Ƕ��巵�����ͣ�
{
	success,fail,fatal,error
}status;

typedef struct Node//��������Կ�һ��c��������ҵ��lv1_p11��
{
	element data;
	struct Node *next;//ָ����һ��node��ָ�룻
}ListNode,*ListNodePtr;

class linklist
{
public:
	status list_head(ListPtr L);//�����µĿ������β�L��
	void list_destory(ListPtr L);//�ͷ������β�L��
	void list_clear(ListPtr L);//������ݣ�˳��ɾ��Node��
	bool list_empty(ListPtr L);//�ж��Ƿ�ֻʣ��ͷ��㣻
	int list_size(ListPtr L);//�������ȣ�
	status list_pull(ListPtr L, element *elem, int point);//ȡ�����ݣ���Ҫ֪���������е�����λ�ã����ظ����ݵ�elem�У�
	status list_locate(ListPtr L, element elem, int *point);//����ָ�����ݣ����ظ����ݵ�node��ŵ�point�У�
	status list_insert(ListPtr L, element elem, int point);//����һ��node������λ��Ϊpoint���Դ�Ԫ��elem��
	status list_remove(ListPtr L, int point);//�Ƴ�һ��node���Ƴ�λ��Ϊpoint��
	//status list_prior(ListPtr L, element *elem, int point);//��ǰ������������pull or locate�Ļ������޸ģ�
	//status list_next(ListPtr L, element *elem, int point);//���̣���������pull or locate�Ļ������޸ģ�
private:
	ListNodePtr p,q,s;//���ֲ���������Ҫ�õ������ƶ�ָ�룻
	status result;//���ֲ����������Ľ����
	int count;//������
};

//��������׶�
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
	while (q)//�ӵڶ�λ��ʼɾ������ʼ�ղ��ϣ�
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

int linklist::list_size(ListPtr L)//ͷ����ǲ����ڳ�������ģ�
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