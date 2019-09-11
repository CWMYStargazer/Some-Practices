#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

//至今我对头文件到底怎么整都不甚明了...
typedef int element;
typedef enum status
{
	success, fail, fatal, error
}status;
typedef class Node
{
public:
	element data;
	class Node *next;
}ListNode;

status list_head(ListNode *L);
void list_destory(ListNode *L);
void list_clear(ListNode *L);
bool list_empty(ListNode *L);
int list_size(ListNode *L);
status list_pull(ListNode *L, element *elem, int point);
status list_locate(ListNode *L, element elem, int *point);
status list_insert(ListNode *L, element elem, int point);
status list_remove(ListNode *L, int point);

#endif // !LINKLIST_H
