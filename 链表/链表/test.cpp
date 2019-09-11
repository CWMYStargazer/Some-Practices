#include"linklist.h"
#include<iostream>
using namespace std;

int main()
{
	ListNode list;
	int point = NULL, elem = NULL;
	cout << list_head(&list) << endl;
	cout << list_insert(&list, 1, 1) << endl;
	cout << list_insert(&list, 2, 1) << endl;
	//cout << list_size(&list) << endl;
	cout << list_locate(&list, 1, &point) << "Number is:" << point << endl;
	cout << list_pull(&list, &elem, 1) << "Element is:" << elem << endl;
	list_destory(&list);
}