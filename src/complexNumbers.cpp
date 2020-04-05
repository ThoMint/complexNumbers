//  Thomas Hofmann 2020
//  https://github.com/ThoMint/complexNumbers
//  definitions of the class members
#include <complexNumbers.hpp>

template <class T>
complexNumber<T>::complexNumber()
{
    this->realPart = 0.0;
    this->imaginaryPart = 0.0;
}

template <class T>
complexNumber<T>::complexNumber(T realPart, T imaginaryPart)
{
    this->realPart = realPart;
    this->imaginaryPart = imaginaryPart;
}

template <class T>
complexNumber<T>::complexNumber(const complexNumber<T> &z)
{
    this->realPart = z.getRealPart();
    this->imaginaryPart = z.getImaginaryPart();
}

template <class T>
T complexNumber<T>::getRealPart() const
{
    return this->realPart;
}

template <class T>
T complexNumber<T>::getImaginaryPart() const
{
    return this->imaginaryPart;
}

template <class T>
T complexNumber<T>::getAbsoluteValue() const
{
    return sqrt((this->realPart*this->realPart)+(this->imaginaryPart*this->imaginaryPart));
}

template <class T>
T complexNumber<T>::getPhase() const
{
    return atan(this->imaginaryPart/this->realPart);
}

template <class T>
void complexNumber<T>::setRealPart(T realPart)
{
    this->realPart = realPart;
}

template <class T>
void complexNumber<T>::setImaginaryPart(T imaginaryPart)
{
    this->imaginaryPart = imaginaryPart;
}

template <class T>
complexNumber<T> complexNumber<T>::conj(const complexNumber<T> &z)
{
    return complexNumber<T>(z.getRealPart(),z.getImaginaryPart()*(-1));
}

template <class T>
complexNumber<T> complexNumber<T>::polar(T value, T phase)
{
    return complexNumber<T>(value*cos(phase),value*sin(phase));
}

template <class T>
complexNumber<T> complexNumber<T>::operator+=(const complexNumber<T> &z)
{
    (*this)=(*this) + z;
    return (*this);
}

template <class T>
complexNumber<T> complexNumber<T>::operator-=(const complexNumber<T> &z)
{
    (*this)=(*this) - z;
    return (*this);
}

template <class T>
complexNumber<T> complexNumber<T>::operator*=(const complexNumber<T> &z)
{
    (*this)=(*this) * z;
    return (*this);
}

template <class T>
complexNumber<T> complexNumber<T>::operator/=(const complexNumber<T> &z)
{
    (*this)=(*this) / z;
    return (*this);
}

//operators with two parameters are implemented as friend and therfor not defined in the namespace of the class complexNumber

template <class T>
complexNumber<T> operator+(const complexNumber<T> &z1, const complexNumber<T> &z2)
{
    return complexNumber<T>(z1.getRealPart() + z2.getRealPart(), z1.getImaginaryPart() + z2.getImaginaryPart());
}

template <class T>
complexNumber<T> operator-(const complexNumber<T> &z1, const complexNumber<T> &z2)
{
    return complexNumber<T>(z1.getRealPart() - z2.getRealPart(), z1.getImaginaryPart() - z2.getImaginaryPart());
}

template <class T>
complexNumber<T> operator*(const complexNumber<T> &z1, const complexNumber<T> &z2)
{
    T realPart = (z1.getRealPart() * z2.getRealPart()) - (z1.getImaginaryPart() * z2.getImaginaryPart());
    T imaginaryPart = (z1.getRealPart() * z2.getImaginaryPart()) + (z1.getImaginaryPart() * z2.getRealPart());
    return complexNumber<T>(realPart, imaginaryPart);
}

template <class T>
complexNumber<T> operator/(const complexNumber<T> &z1, const complexNumber<T> &z2)
{
    T realPartNumerator = (z1.getRealPart() * z2.getRealPart()) + (z1.getImaginaryPart() * z2.getImaginaryPart());
    T realPartDenominator = (z2.getRealPart() * z2.getRealPart()) + (z2.getImaginaryPart() * z2.getImaginaryPart());
    T imaginaryPartNumerator = (z1.getImaginaryPart() * z2.getRealPart()) - (z1.getRealPart() * z2.getImaginaryPart());
    T imaginaryPartDenominator = (z2.getRealPart() * z2.getRealPart()) + (z2.getImaginaryPart() * z2.getImaginaryPart());
    return complexNumber<T>(realPartNumerator / realPartDenominator, imaginaryPartNumerator / imaginaryPartDenominator);
}

template <class T>
bool operator==(const complexNumber<T> &z1, const complexNumber<T> &z2)
{
    return ((z1.getRealPart()==z2.getRealPart())&&(z1.getImaginaryPart()==z2.getImaginaryPart()));
}

template <class T>
bool operator!=(const complexNumber<T> &z1, const complexNumber<T> &z2)
{
    return ((z1.getRealPart()!=z2.getRealPart())||(z1.getImaginaryPart()!=z2.getImaginaryPart()));
}

template <class T>
std::ostream &operator<<(std::ostream &out, const complexNumber<T> &z)
{
    out << z.getRealPart() << (z.getImaginaryPart() > 0 ? "+":"") << z.getImaginaryPart() << "i";   //printing the number to the console while considering the sign
    return out;                                                                                     //returning the outstream for furter use ex.: std::cout << z1 << z2 << ...
}