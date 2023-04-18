//#define _CRT_SECURE_NO_WARNINGS 1
#include"complex.h"

using namespace std;

Complex::Complex(double real=0.0,double image=0.0)  //构造函数
	:_real(real)
	,_image(image)
{}
 
void Complex::Print()
{
	if(_image == 0.0)   //虚部为0
	{
		cout<<_real<<endl;
	}
	else
	{
		cout<<_real<<"+"<<_image<<"*i"<<endl;
	}
}
 
Complex Complex::operator+(const Complex &c)
{
	Complex tmp;
	tmp._real=_real+c._real;
	tmp._image=_image+c._image;
	return tmp;
}
 
Complex Complex::operator-(const Complex &c)
{
	Complex tmp;
	tmp._real=_real-c._real;
	tmp._image=_image-c._image;
	return tmp;
}
 
Complex Complex::operator*(const Complex &c)
{
	Complex tmp;
	tmp._real=_real*c._real-_image*c._image;
	tmp._image=_real*c._image+_image*c._real;
	return tmp;
}
 
Complex Complex::operator/(const Complex &c)
{
	Complex tmp;
	double t=c._real*c._real+c._image*c._image;
	tmp._real=(_real*c._real-_image*(-c._image))/t;
	tmp._image=(_real*(-c._image)+_image*c._real)/t;
	return tmp;
 
}
 
Complex& Complex::operator+=(const Complex &c)
{
	_real+=c._real;
	_image+=c._image;
	return *this;
}
 
Complex& Complex::operator-=(const Complex &c)
{
	_real-=c._real;
	_image-=c._image;
	return *this;
}
 
Complex& Complex::operator*=(const Complex &c)
{
	Complex tmp(*this);  //拷贝构造函数
	_real=tmp._real*c._real-_image*c._image;
	_image=tmp._real*c._image+tmp._image*c._real;
	return *this;
}
 
Complex& Complex::operator/=(const Complex &c)
{
	Complex tmp(*this);
	double t=c._real*c._real+c._image*c._image;
	_real=(tmp._real*c._real-tmp._image*(-c._image))/t;
	_image=(tmp._real*(-c._image)+tmp._image*c._real)/t;
	return *this;
}
 
bool Complex::operator==(const Complex &c)
{
	return (_real == c._real)&&
		(_image == c._image);
}
 
Complex& Complex::operator++()  //前置++
{
	_real++;
	_image++;
	return *this;
}
 
Complex Complex::operator++(int) //后置++
{
	Complex tmp(*this);  //拷贝构造函数暂存this所指向的值
	_real++;
	_image++;
	return tmp;
}
 
Complex& Complex::operator--()   //前置--
{
	_real--;
	_image--;
	return *this;
}
 
Complex Complex::operator--(int) //后置--
{
	Complex tmp(*this);
	_real--;
	_image--;
	return tmp;
}
 
bool Complex::operator>(const Complex &c)
{
	return (_real > c._real)&&
		(_image > c._image);
}
 
Complex& Complex::operator=(const Complex &c)
{
	if(this != &c)
	{
		_real=c._real;
		_image=c._image;
	}
	return *this;
}


template <typename T> bool Complex<T>::bubble ( Rank lo, Rank hi ) {
	bool sorted = true;
	while ( ++lo < hi )
	if ( _elem[lo - 1] > _elem[lo] ) {
		sorted = false;
		swap ( _elem[lo - 1],_elem[lo] );
	}
	return sorted;
}

template <typename T> void Complex<T>::bubbleSort ( Rank lo, Rank hi ) {
	while ( !bubble ( lo, hi-- ) );} 

template <typename T> void Complex<T>::mergeSort ( Rank lo, Rank hi ) {
	if ( hi - lo < 2 ) 
	return;
	int mi = ( lo + hi ) / 2;
	mergeSort ( lo, hi );
	mergeSort ( mi, hi );
	merge ( lo, mi, hi );
}

template <typename T> Rank Complex<T>::search ( T const& e, Rank lo, Rank hi ) const
{
	return ( rand() % 2 ) ? binSearch ( _elem, e, lo, hi ) : fibSearch ( _elem, e, lo, hi );
}

template <typename T> Rank Complex<T>::find ( T const& e, Rank lo, Rank hi ) const {
	while ( ( lo < hi-- ) && ( e != _elem[hi] ) );
	return hi;
}

template <typename T> void Complex<T>::unsort ( Rank lo, Rank hi ) {
	T* V = _elem + lo;
	for ( Rank i = hi - lo; i > 0; i-- ) 
	swap ( V[i - 1], V[rand() % i] );
}

template <typename T> Rank Complex<T>::insert ( Rank r, T const& e ) {
	expand;
	for ( int i = _size; i > r; i--) _elem[i] = _elem[i-1];
	_elem[r] = e;
	_size++;
	return r; 
}

template <typename T> int Complex<T>::remove ( Rank lo, Rank hi ) {
	if ( lo == hi ) 
	return 0;
	while ( hi < _size ) _elem[lo++] = _elem[hi++]; 
	_size = lo;
	shrink();
	return hi - lo; 
}

template <typename T> int Complex<T>::remove ( Rank r ) {
	T e = _elem[r];
	remove ( r, r+1 );
	return e;
}

template <typename T> int Complex<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while ( i < size )
	( find ( _elem[i], 0, 1 ) < 0 ) ?
	i++ : remove ( i );
	return oldSize - _size;
}
