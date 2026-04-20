#include "Polynomial.h"
double Polynomial::operator()(double aX) const{
    double result = 0.0;
    for(size_t i= fDegree+1;i>0;i--){
        result = result * aX + fCoeffs[i-1];
    }
    return result;
}
Polynomial Polynomial::getDerivative() const{
    Polynomial result;

    if (fDegree == 0)
    {
        result.fDegree = 0;
        result.fCoeffs[0] = 0.0;
        return result;
    }

    result.fDegree = fDegree - 1;

    for (size_t i = 1; i <= fDegree; ++i)
    {
        result.fCoeffs[i - 1] = fCoeffs[i] * i;
    }

    return result;

}
Polynomial Polynomial::getIndefiniteIntegral() const{
    Polynomial result;

    result.fDegree = fDegree + 1;
    result.fCoeffs[0] = 0.0; // constant of integration

    for (size_t i = 0; i <= fDegree; ++i)
    {
        result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
    }

    return result;
}
double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const{
    Polynomial integral = getIndefiniteIntegral();

    return integral(aXHigh) - integral(aXLow);
}