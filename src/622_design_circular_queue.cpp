622. Design Circular Queue 设计循环队列
//作者：lilyyueli
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

using namespace std;

#include <vector>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};

class MyCircularQueue {
private:
	ListNode *head;
	ListNode *tail;
	int capacity;
	int size;

public:
	MyCircularQueue(int k) {
		this->capacity = k;
		this->size = 0;
		this->head = this->tail = nullptr;
	}

	bool enQueue(int value) {
		if (isFull())
			return false;
		ListNode* node = new ListNode(value);
		if (!head)
			head = tail = node;
		else
		{
			tail->next = node;
			tail = node;
		}
		this->size++;
		return true;
	}

	bool deQueue() {
		if (isEmpty())
			return false;
		ListNode* node = head;
		head = head->next;
		delete node;
		size--;
		return true;
	}

	int Front() {
		if (isEmpty())
			return -1;
		return head->val;
	}

	int Rear() {
		if (isEmpty())
			return -1;
		return tail->val;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}
};


int main (int argc, char* argv[])
{
	MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
	myCircularQueue->enQueue(1);
	myCircularQueue->enQueue(2);
	myCircularQueue->enQueue(3);
	myCircularQueue->enQueue(4);
	myCircularQueue->Rear();
	myCircularQueue->isFull();
	myCircularQueue->deQueue();
	myCircularQueue->enQueue(4);
	myCircularQueue->Rear();

	return 0;
}
