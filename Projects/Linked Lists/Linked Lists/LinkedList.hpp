#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    Node()
    {
        ptrNext = nullptr;
        ptrPrev = nullptr;
    }

    Node<T>* ptrNext;
    Node<T>* ptrPrev;

    T data;
};

template <typename T>
class LinkedList
{
    public:
    LinkedList() // done
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList() // done
    {
        Free();
    }

    void Push( const T& newItem )
    {
		Node<T>* newNode = new Node<T>;
		newNode->data = newItem;
		
		if (m_ptrFirst == nullptr)
		{
			// Empty list
			m_ptrFirst = newNode;
			m_ptrLast = m_ptrFirst;
			m_itemCount++;
		}
		else
		{
			// Not empty
			// List
			// A <-> B <-> C -> nullptr
			newNode->ptrPrev = m_ptrLast;	// New node's previous is the old last
			m_ptrLast->ptrNext = newNode;	//
			m_ptrLast = newNode;
			m_itemCount++;
		}
    }

    bool Insert( int index, const T& newItem )
    {
		if (index < 0 || index > m_itemCount)
		{
			return false;
		}
		else if (index == m_itemCount)
		{
			Push(newItem);
			return true;
		}

		Node<T>* ptrCurrent = m_ptrFirst;
		int counter = 0;

		// Traverse the list until we get to position "index"
		while (counter < index)
		{
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}

		Node<T>* newNode = new Node<T>;
		newNode->data = newItem;
		
		newNode->ptrPrev = ptrCurrent->ptrPrev;
		newNode->ptrNext = ptrCurrent;
		ptrCurrent->ptrPrev->ptrNext = newNode;
		ptrCurrent->ptrPrev = newNode;


    }

    void Extend( const LinkedList& other )
    {
		// Use Get as reference to implement this
		// Use Push to add items to the end of the local list
		

		Node<T>* ptrCurrent = other.m_ptrFirst;
		// Add all elements from "other" with the Push() function
		for (int i = 0; i < other.Size(); i++)
		{
			Push(other.Get(i));
		}
    }

    bool Pop()
    {
		if (IsEmpty())
		{
			return false;
		}

		if (Size() > 1)		// if there's multiple items in list
		{
			Node<T>* ptrPenultimate = m_ptrLast->ptrPrev;
			delete m_ptrLast;
			m_ptrLast = ptrPenultimate;
			m_ptrLast->ptrNext = nullptr;
			m_itemCount--;
			return true;
		}
		else	// if there's only one item in list
		{
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
			return true;
		}
    }

    bool Remove( int index )
    {
		if (index < 0 || index >= m_itemCount)
		{
			return false;
		}

		else if (Size() == 1 || index == m_itemCount - 1)
		{
			Pop();
		}

		Node<T>* ptrCurrent = m_ptrFirst;
		int counter = 0;

		// Traverse the list until we get to position "index"
		while (counter < index)
		{
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}



    }

    T Get( int index ) const
    {
		// Error checking
		if (index < 0 || index >= m_itemCount)
		{
			return T();		// return new "T" item
		}
		Node<T>* ptrCurrent = m_ptrFirst;
		int counter = 0;

		// Traverse the list until we get to position "index"
		while (counter < index)
		{
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}

		// Return the data at this position
		return ptrCurrent->data;
    }

    int Size() const // done
    {
        return m_itemCount;
    }

    bool IsEmpty() const // done
    {
        return ( m_ptrFirst == nullptr );
    }

    T operator[]( int index ) // done
    {
        return Get( index );
    }

    LinkedList& operator=( const LinkedList& other )
    {
		Free();

		for (int i = 0; i < other.Size(); i++)
		{
			Push(other.Get(i));
		}

		return (*this);
    }

    bool operator==( const LinkedList& other )
    {
		if (Size() != other.Size())
		{
			return false;
		}
		else if (Size() == 0 && other.Size() == 0)
		{
			return true;
		}
		for (int i = 0; i < Size(); i++)
		{
			if (Get(i) != other.Get(i))
			{
				return false;
			}
		}
    }

    bool operator!=( const LinkedList& other )
    {
        return !( (*this) == other );
    }

    private:
    void Free() // done
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount;
};

#endif
