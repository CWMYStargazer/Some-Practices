//��Ϊʲô����ô����������ô���˻��ڽ����Ա�
//���������д�ˣ�֮ǰ����û��ô�������ʵд����������ԣ�˳��ĸ�ǰ�������е�ϰ�ߡ�����Ȼ�Ҿ��û���֮�����ÿ��ġ���
//�Ѻ�ջ��һ���ɣ�

typedef int element;

class Node {
public:
	element elem;
	Node *next;
};

class Stack {
private:
	Node *Top;
	int length;
public:
	Stack(element e);//�ع�
	void pop(element *e);//����
	void push(element e);//����
	void destroy();//����
};

Stack::Stack(element e) {
	Top = new Node;
	Top->elem = e;
	Top->next = 0;
	length += 1;
}

void Stack::pop(element *e) {
	Node *d;
	d = Top;
	*e = Top->elem;
	Top = Top->next;
	delete d;
	this->length -= 1;
}

void Stack::push(element e) {
	Node *s;
	s = new Node;
	s->elem = e;
	s->next = Top;
	Top = s;
	this->length += 1;
}

void Stack::destroy() {
	element *popout = 0;
	for (; length <= 0; length--) {
		pop(popout);
	}
	delete Top;
}