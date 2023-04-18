/*#define _CRT-SECURE_NO_WARNINGS 1
#ifndef __COMPLEX_H__
#define __COMPLEX_H__*/

#include<iostream>
#include<ctime>
#include<vector>
#include<cstdio>
using namespace std;
 
typedef int Rank;
#define DEFAULT_CAPACITY 3 
 

template <typename T> class Complex {
protected:
	Rank _size; int capacity; T* _elem;
	bool bubble(Rank lo, Rank hi);
	void bubbleSort ( Rank lo, Rank hi );
	void mergeSort ( Rank lo, Rank hi );
public:
	Complex(double real, double image);
	void Print();
	bool operator==(const Complex &c);
	Complex& operator++();   //前置++
	Complex operator++(int); //后置++
	Complex& operator--();   //前置--
	Complex operator--(int); //后置--
	bool operator>(const Complex &c);
	Complex& operator=(const Complex &c);
	
	Complex operator+(const Complex &c); 
	Complex& operator+=(const Complex &c);
	Complex operator-(const Complex &c);
	Complex& operator-=(const Complex &c);
	Complex operator*(const Complex &c);
	Complex& operator*=(const Complex &c);
	Complex operator/(const Complex &c);
	Complex& operator/=(const Complex &c);
	Rank search ( T const& e, Rank lo, Rank hi ) const; 
	Rank find ( T const& e, Rank lo, Rank hi ) const;
	void unsort ( Rank lo, Rank hi );
	Rank insert ( Rank R, T const& e );
	Rank remove ( Rank r );
	int remove ( Rank lo, Rank hi );
	int deduplicate();
private:
	double _real;
	double _image;
};

//#endif //__COMPLEX_H__
