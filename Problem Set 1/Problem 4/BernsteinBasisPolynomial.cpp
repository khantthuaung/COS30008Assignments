#include "BernsteinBasisPolynomial.h"
#include <cmath>
BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV,unsigned int aN){
    fFactor = Combination(aN,aV);
}
double BernsteinBasisPolynomial::operator()(double aX) const{
    size_t n = fFactor.getN();
    size_t v = fFactor.getK();
    double coe = fFactor();

    return coe* pow(aX,v) * pow(1-aX,n-v);
}