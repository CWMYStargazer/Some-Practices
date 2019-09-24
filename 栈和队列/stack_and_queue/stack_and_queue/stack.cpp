//他为什么讲这么慢诶……这么久了还在讲线性表？
//这次是用类写了，之前还是没怎么懂类的真实写法，这次试试；顺便改改前花括换行的习惯……虽然我觉得换行之后蛮好看的……
//堆和栈不一样吧？

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
	Stack(element e);//重构
	void pop(element *e);//弹出
	void push(element e);//推入
	void destroy();//销毁
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