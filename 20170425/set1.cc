 ///
 /// @file    set1.cc
 /// @author  heartinharbin
 /// @date    2017-04-26 23:08:45
 ///
 
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

int test1(void){
	set<int> setInt{2, 1, 3, 5, 4, 5, 3, 5, 6};
	set<int>::iterator it = setInt.begin();
	for(; it != setInt.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

int test2(void){
	set<int, std::greater<int> > setInt{2, 1, 3, 5, 4, 5, 3, 5, 6};
	set<int>::iterator it = setInt.begin();
	for(; it != setInt.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

class Complex{
public:
	Complex(double dreal, double dimag)
	:_dreal(dreal)
	,_dimag(dimag){}
	
	friend std::ostream & operator<<(std::ostream &os, const Complex &rhs);
	friend bool operator<(const Complex &lhs, const Complex &rhs);
	friend bool operator>(const Complex &lhs, const Complex &rhs);

private:
	double _dreal;
	double _dimag;
};//end of class Complex

std::ostream & operator<<(std::ostream &os, const Complex &rhs){
	os << rhs._dreal << "+" << rhs._dimag << "i";
	return os;
}

bool operator<(const Complex &lhs, const Complex &rhs){
	if(lhs._dreal < rhs._dreal)
		return true;
	else
		return false;
}

bool operator>(const Complex &lhs, const Complex &rhs){
	if(lhs._dreal > rhs._dreal)
		return true;
	else
		return false;
}

void test3(){
	set<Complex> setComplex{Complex(3, 2), Complex(1, 4), Complex(5, 6), Complex(9, 1)};
	for(auto & elem : setComplex){
		cout << elem << endl;
	}

}

void test4(){
	set<Complex, std::greater<Complex> > setComplex{Complex(3, 2), Complex(1, 4), Complex(5, 6), Complex(9, 1)};
	for(auto & elem : setComplex){
		cout << elem << endl;
	}
}

int main(void){
	test4();
	return 0;
}


