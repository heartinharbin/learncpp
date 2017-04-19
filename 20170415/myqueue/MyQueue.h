 ///
 /// @file    MyQueue.h
 /// @author  heartinharbin
 /// @date    2017-04-17 23:02:39
 ///
#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#define QUEUESIZE 10

class MyQueue{
public:
	MyQueue();

	bool isEmpty();
	bool isFull();
	bool enQueue(int elem);
	bool deQueue(int & elem);
	bool front(int & elem);
	bool rear(int & elem);

private:
	int _queue[QUEUESIZE];
	int _front;
	int _rear;
};//end of class MyQueue

#endif
