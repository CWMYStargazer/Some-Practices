#include"linklist.cpp"//这样可以不用写头文件，长知识了...但不清楚.cpp里面是否只能含有类的定义；

int main()
{
	linklist l;
	ListNode list;
	int point = NULL, elem = NULL;
	cout << l.list_head(&list) << endl;
	cout << l.list_insert(&list, 1, 1) << endl;
	cout << l.list_insert(&list, 2, 1) << endl;
	cout << l.list_size(&list) << endl;
	cout << l.list_locate(&list, 1, &point) << "Number is:" << point << endl;
	cout << l.list_pull(&list, &elem, 1) << "Element is:" << elem << endl;
	l.list_destory(&list);
}