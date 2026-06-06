#include "ListPS3.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

template<typename T>
List<T>::List():fRoot(nullptr),fCount(0){}

template <typename T>
bool List<T>::empty() const {
    if (fCount == 0){
        return true;
    }
    return false;
}

template<typename T>
size_t List<T>::size() const {
    return fCount;
}
template<typename T>
void List<T>::push_front(const T& aElement){
    Node* lNode = new Node(aElement);
    if (fRoot == nullptr)
    {
        fRoot = lNode;
    }
    else{
        fRoot = &fRoot->push_front(*lNode);
    }
    fCount++;
}

template<typename T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(fRoot).begin();
}

template<typename T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(fRoot).end();
}

template<typename T>
typename List<T>::Iterator List<T>::rbegin() const {
    return Iterator(fRoot).rbegin();
}

template<typename T>
typename List<T>::Iterator List<T>::rend() const {
    return Iterator(fRoot).rend();
}