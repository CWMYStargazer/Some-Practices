#include"linklist.cpp"//�������Բ���дͷ�ļ�����֪ʶ��...�������.cpp�����Ƿ�ֻ�ܺ�����Ķ��壻

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