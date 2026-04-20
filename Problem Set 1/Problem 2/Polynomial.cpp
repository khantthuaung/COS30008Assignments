#include <iostream>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial()
{
	fDegree = 0;
	for (int i = 0; i <= MAX_DEGREE; i++)
		fCoeffs[i] = 0;
}

bool Polynomial::operator==(const Polynomial& aRHS) const
{
	if (fDegree != aRHS.fDegree)
		return false;
	for (int i = 0; i <= fDegree; i++)
	{
		if (fCoeffs[i] != aRHS.fCoeffs[i])
			return false;
	}
	return true;
}

istream& operator>>(istream& aIStream, Polynomial& aObject)
{
	aIStream >> aObject.fDegree;
	for (int i = aObject.fDegree; i >= 0; i--)
	{
		aIStream >> aObject.fCoeffs[i];
	}
	return aIStream;
}

ostream& operator<<(ostream& aOStream, const Polynomial& aObject)
{
	for (int i = aObject.fDegree; i >= 0; i--)
	{
		aOStream << aObject.fCoeffs[i] << "x^" << i;
		if (i != 0)
			cout << " + ";
	}
	return aOStream;
}

Polynomial Polynomial::operator*(const Polynomial& aRHS) const
{
	Polynomial result;

	result.fDegree = fDegree + aRHS.fDegree;
	for (int i = fDegree; i>=0; i--)
	{
		for (int j = aRHS.fDegree; j >= 0; j--)
		{
			double coeff = fCoeffs[i] * aRHS.fCoeffs[j];
			size_t degree = i + j;
			result.fCoeffs[degree] += coeff;
		}
	}
	return result;
}
