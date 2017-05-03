 ///
 /// @file    Vector.cc
 /// @author  heartinharbin
 /// @date    2017-05-01 21:39:26
 ///
#include <memory> 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Vector{
public:
	Vector();
	~Vector();

	void push_back(const T &);
	void pop_back();

	size_t size() const;
	size_t capacity() const;
	
	void display() const;
	T & operator[](size_t);
private:
	void reallocate();

private:
	static std::allocator<T> _alloc;
	T * _elem;
	T * _first_free;
	T * _end;
};//end of class Vector


template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
:_elem(0)
,_first_free(0)
,_end(0){}

template <typename T>
Vector<T>::~Vector(){
	while(size()){
		_alloc.destroy(--_first_free);
	}
	_alloc.deallocate(_elem, capacity());//忘记写这句了
}

template <typename T>
size_t Vector<T>::size() const{
	return _first_free - _elem;
}

template <typename T>
size_t Vector<T>::capacity() const{
	return _end - _elem;
}

template <typename T>
void Vector<T>::push_back(const T &var){
	size_t sz = size();
	size_t cap = capacity();

	if(sz == cap){
		reallocate();
	}
	_alloc.construct(_first_free, var);
	++_first_free;
}

template <typename T>
void Vector<T>::pop_back(){
	if(size()){
		_alloc.destroy(--_first_free);
	}
} 

template <typename T>
void Vector<T>::reallocate(){
	size_t oldcap = capacity();
	size_t newcap = oldcap > 0 ? 2 * oldcap : 1;
	
	T * p = _alloc.allocate(newcap);
	std::uninitialized_copy(_elem, _first_free, p);
//	while(size()){
	while(_first_free != _elem){
		_alloc.destroy(--_first_free);
	}
	_alloc.deallocate(_elem, oldcap);
	

	//下面的3句不要少了
	_elem = p;
	_first_free = _elem + oldcap;
	_end = _elem + newcap;
}

template <typename T>
T & Vector<T>::operator[](size_t ans){
	return *(_elem + ans);
}

template <typename T>
void Vector<T>::display() const{
	for(size_t idx = 0; idx != size(); ++idx){
		cout << _elem[idx] << " ";
	}
	cout << endl;
}

void test1(void){
	Vector<int> vecInt;
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
	vecInt.display();
	
	vecInt.push_back(1);
	vecInt.display();
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;

	vecInt.push_back(2);
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
	vecInt.push_back(3);
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
	vecInt.push_back(4);
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
	vecInt.push_back(5);
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
	vecInt.push_back(6);
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
	vecInt.push_back(7);
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
	vecInt.push_back(8);
	cout << "size:" << vecInt.size() << " cap:"<< vecInt.capacity() << endl;
}

int main(void){
	test1();
	return 0;
}

