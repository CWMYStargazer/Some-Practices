//然后我觉得栈和队列区别不大，写在一个工程里面算了
//链表毕竟是基础就不放一起了，给之后的我参观一下当年乱七八糟的代码hhh

typedef int element;

class Node {
public:
	element elem;
	Node *next;
};

class Queue {
private:
	Node *front, *rear;//好迷哦为什么不用head和tail呢……
	int length;
public:
	Queue(element e);
	void enqueue(element e);
	void dequeue(element *e);
	void destroy();
};

Queue::Queue(element e) {
	front = new Node;
	rear = front;
	front->next = 0;
	front->elem = e;
	length += 1;
}

void Queue::enqueue(element e) {
	Node *s;
	s = new Node;
	s->elem = e;
	rear->next = s;
	rear = rear->next;
	length += 1;
}

void Queue::dequeue(element *e) {
	Node *d;
	d = front;
	*e = front->elem;
	front = front->next;
	length -= 1;
	delete d;
}

void Queue::destroy() {
	element *out = 0;
	for (; length <= 0; length--) {
		dequeue(out);
	}
	delete front;
}