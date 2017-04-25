 ///
 /// @file    templateQueue.cc
 /// @author  heartinharbin
 /// @date    2017-04-21 21:31:49
 ///
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

//_size为10时 只能放9个元素，切记
template <typename T, int _size = 10>
class Queue
{
public:
	Queue();
	~Queue();
	
	bool empty();
	bool full();
	bool enQueue(T elem);
	bool deQueue(T &elem);
	bool front(T &elem);
	bool rear(T &elem);

private:
	T * _arr;
	int _front;
	int _rear;
};//end of class Queue

template <typename T, int _size>
Queue<T, _size>::Queue()
:_arr(new T[_size])
,_front(0)
,_rear(0){
	cout << "Queue()" << endl;
}

template <typename T, int _size>
Queue<T, _size>::~Queue(){
	cout << "~Queue()" << endl;
	delete [] _arr;
}

template <typename T, int _size>
bool Queue<T, _size>::empty(){
	return _front == _rear;
}

template <typename T, int _size>
bool Queue<T, _size>::full(){
	return (_rear + 1) % _size == _front;
}

template <typename T, int _size>
bool Queue<T, _size>::enQueue(T elem){
	if(full()){
		return false;
	}
	_arr[_rear] = elem;
	_rear = (_rear + 1) % _size;
	return true;
}

template <typename T, int _size>
bool Queue<T, _size>::deQueue(T &elem){
	if(empty()){
		return false;
	}
	elem = _arr[_front];
	_front = (_front + 1) % _size;
	return true;
}

template <typename T, int _size>
bool Queue<T, _size>::front(T &elem){
	if(empty()){
		return false;
	}
	elem = _arr[_front];
	return true;
}

template <typename T, int _size>
bool Queue<T, _size>::rear(T &elem){
	if(empty()){
		return false;
	}
	elem = _arr[(_rear - 1 + _size) % _size];
	return true;
}




void test1(void){
	Queue<int> queue;
	cout << "队列是否为空：" << queue.empty() << endl;
	queue.enQueue(1);
	cout << "队列是否为空：" << queue.empty() << endl;
	for(int idx = 2; idx != 12; ++idx){
		if(!queue.enQueue(idx)){
			cout << "插入队列失败" << endl;
		}
	}
	cout << "队列是否为满：" << queue.full() << endl;
	while(!queue.empty()){
		int felem, relem, delelem;
		queue.front(felem);
		queue.rear(relem);
		cout << felem << "  " << relem << "  "; 
		queue.deQueue(delelem);
		cout << "del:" << delelem << endl;
	}
	cout << "队列是否为空：" << queue.empty() << endl;
}


int main(void){
	test1();
	return 0;
}
