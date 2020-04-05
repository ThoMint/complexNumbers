//  Thomas Hofmann 2020
//	https://github.com/ThoMint/complexNumbers
//  declarations of the class
#pragma once
#include <iostream>
#include <cmath>

template <class T>
class complexNumber;	//forwarding the declaration of the class in order to use it at the operator prototypes

template <class U>
complexNumber<U> operator+(const complexNumber<U> &z1, const complexNumber<U> &z2);	//since the operators with 2 parameteres

template <class U>
complexNumber<U> operator-(const complexNumber<U> &z1, const complexNumber<U> &z2);	//are friend functions, they have to

template <class U>
complexNumber<U> operator*(const complexNumber<U> &z1, const complexNumber<U> &z2);	//already be declared at the time they

template <class U>
complexNumber<U> operator/(const complexNumber<U> &z1, const complexNumber<U> &z2);	//are declared insed the class

template <class U>
std::ostream &operator<<(std::ostream &out, const complexNumber<U> &z);

template <class U>
bool operator==(const complexNumber<U> &z1, const complexNumber<U> &z2);

template <class U>
bool operator!=(const complexNumber<U> &z1, const complexNumber<U> &z2);

template <class T>
class complexNumber
{
private:	//internal representation of the complex number
	T realPart;
	T imaginaryPart;
public:		//constructors
	complexNumber();								//standard constructor
	complexNumber(T realPart, T imaginaryPart);		//construc a complex number with realPart and imaginaryPart
	complexNumber(const complexNumber<T> &z);		//copy constructor
public:		//getters (marked as const in order to use it with ref-to-const) and setters
	T getRealPart() const;			//get the real part of this complex number
	T getImaginaryPart() const;		//get the imaginary part of this complex number
	T getAbsoluteValue() const;		//get the value of this complex number
	T getPhase() const;				//get the phase of this complex number

	void setRealPart(T realPart);				//set the real part of this complex number
	void setImaginaryPart(T imaginaryPart);	//set the imaginary part of this complex number
public:		//static tools (can be called without an object)
	static complexNumber<T> conj(const complexNumber<T> &z);	//return the conjungated complex number of z
	static complexNumber<T> polar(T value, T phase);			//construct a complex number from value and phase
public:		//operators (complex numbers are passed by ref-to-const in order to cascade multiple operators, otherwise we would have
			//to create a temporary complex Number, for ex. std::cout << z1+z2) - this would not be neccessery with the visual studio compiler
	complexNumber<T> operator+=(const complexNumber<T> &z);		//add a complex number to this one										z1+=z2
	complexNumber<T> operator-=(const complexNumber<T> &z);		//subtract this complex number from another one							z1-=z2
	complexNumber<T> operator*=(const complexNumber<T> &z);		//multiply a complex number with this one								z1*=z2
	complexNumber<T> operator/=(const complexNumber<T> &z);		//divide this complex number by another one								z1/=z2
	friend complexNumber<T> operator+<T>(const complexNumber<T> &z1, const complexNumber<T> &z2);	//operators with more				z1+z2
	friend complexNumber<T> operator-<T>(const complexNumber<T> &z1, const complexNumber<T> &z2);	//than one parameter				z1-z2
	friend complexNumber<T> operator*<T>(const complexNumber<T> &z1, const complexNumber<T> &z2);	//have to be implemented			z1*z2
	friend complexNumber<T> operator/<T>(const complexNumber<T> &z1, const complexNumber<T> &z2);	//as friend							z1/z2
	friend std::ostream &operator<<<T>(std::ostream &out, const complexNumber<T> &z);	//used to print to the console with std::cout	std::cout << z1
	friend bool operator==<T>(const complexNumber<T> &z1, const complexNumber<T> &z2);	//check if two complex numbers are the same		z1==z2
	friend bool operator!=<T>(const complexNumber<T> &z1, const complexNumber<T> &z2);	//check if two complex numbers are diffrent		z1!=z2
};