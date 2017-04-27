 ///
 /// @file    templateQueue.cc
 /// @author  heartinharbin
 /// @date    2017-04-26 21:00:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T, int SIZE = 10>
class Queue{
public:
	Queue();
	~Queue();

	bool full();
	bool empty();
	void push(const T &elem);
	void pop();
	T front();
	T back();

private:
	int _front;
	int _rear;
	T * _arr;
};//end of class Queue


template <typename T, int SIZE>
Queue<T, SIZE>::Queue()
:_front(0)
,_rear(0)
,_arr(new T[SIZE]){}

template <typename T, int SIZE>
Queue<T, SIZE>::~Queue(){
	delete [] _arr;
}

template <typename T, int SIZE>
bool Queue<T, SIZE>::full(){
	return _front == (_rear + 1) % SIZE;
}

template <typename T, int SIZE>
bool Queue<T, SIZE>::empty(){
	return _front == _rear;
}

template <typename T, int SIZE>
void Queue<T, SIZE>::push(const T & elem){
	if(!full()){
		_arr[_rear++] = elem;
		_rear %= SIZE;
	}else{
		cout << "队列已满" << endl;
	}
}

template <typename T, int SIZE>
void Queue<T, SIZE>::pop(){
	if(!empty()){
		++_front;
		_front %= SIZE;
	}else{
		cout << "队列空" << endl;
	}	
}

template <typename T, int SIZE>
T Queue<T, SIZE>::front(){
	return _arr[_front];
}

template <typename T, int SIZE>
T Queue<T, SIZE>::back(){
	return _arr[(_rear - 1 + SIZE) % SIZE];
}

int main(void){
	Queue<int> que;
	cout << "queue is empty()?" << que.empty() << endl;
	que.push(1);
	cout << "queue is empty()?" << que.empty() << endl;

	for(int idx = 2; idx != 12; ++idx){
		que.push(idx);
	}
	cout << "que is full()?" << que.full() << endl;

	cout << "que front elem:" << que.front() << endl;
	que.pop();

	cout << "que is full()?" << que.full() << endl;
	que.push(10);
	cout << "que front and back elem:" << que.front() << " " << que.back() << endl;
}





