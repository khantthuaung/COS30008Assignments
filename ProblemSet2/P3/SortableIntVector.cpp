#include "SortableIntVector.h"

// Constructor
SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : IntVector(aArrayOfIntegers, aNumberOfElements)
{
}

// Bubble Sort
void SortableIntVector::sort(Comparable aOrderFunction)
{
    for (size_t i = 0; i < size(); i++)
    {
        for (size_t j = 0; j < size() - i - 1; j++)
        {
            if (!aOrderFunction(get(j), get(j + 1)))
            {
                swap(j, j + 1);
            }
        }
    }
}   