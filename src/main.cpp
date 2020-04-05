#include <iostream>
#include <complexNumbers.hpp>
#include "complexNumbers.cpp"   //Has to be included otherwise, the linker would not be able to find the definitions, this is due to the use of templates

int main(int argc, char** argv)
{
    complexNumber<float> z1(4,5);
    std::cout << "Z1: Value:" << z1.getAbsoluteValue() << " Phase:" << z1.getPhase() << std::endl;
    complexNumber<float> z2(-1,1);
    std::cout << "Z2:" << z2 << std::endl;
    z2 = complexNumber<float>::conj(z2);
    std::cout << "Z2 (conj):" << z2 << std::endl;
    complexNumber<float> z3;
    z3 = complexNumber<float>::polar(1.0,M_PI/4);
    std::cout << "Z3:" << z3 << std::endl;
    complexNumber<float> z4;
    z4 += (z1-z2*(z3/z1))+complexNumber<float>(3,1);
    std::cout << "Z4:" << z4 << std::endl;
    std::cout << (z1==z4 ? "Z1=Z4":"Z1!=Z4") << std::endl;
}