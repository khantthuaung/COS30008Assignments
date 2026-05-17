#include "ShakerSortableIntVector.h"

// Constructor
ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[],size_t aNumberOfElements): SortableIntVector(aArrayOfIntegers, aNumberOfElements){}

// Cocktail Shaker Sort
void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
    if (size() <= 1)
    {
        return;
    }

    size_t left = 0;
    size_t right = size() - 1;

    while (left < right)
    {
        // Move from left to right
        for (size_t i = left; i < right; i++)
        {
            if (aOrderFunction(get(i), get(i + 1)))
            {
                swap(i, i + 1);
            }
        }

        right--;

        // Move from right to left
        for (size_t i = right; i > left; i--)
        {
            if (aOrderFunction(get(i - 1), get(i)))    
            {
                swap(i - 1, i);
            }
        }

        left++;
    }
}