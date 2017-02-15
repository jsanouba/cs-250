#include "SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray()
{
	m_itemCount = 0;
	m_arraySize = 0;
	m_data = nullptr;
}

SmartDynamicArray::~SmartDynamicArray()
{
	Free();
}

bool SmartDynamicArray::Push( const string& newItem )
{
	if (IsFull())
	{
		Resize();
		return false;
	}
	
	m_data[m_itemCount] = newItem;
	m_itemCount++;
}


bool SmartDynamicArray::Insert( int index, const string& newItem )
{
	return false; // temp
}


bool SmartDynamicArray::Extend( const SmartDynamicArray& other )
{
	return false; // temp
}


bool SmartDynamicArray::Pop()
{
	if (IsEmpty())
	{
		return false;
	}

	m_itemCount--;
	return true;
}


bool SmartDynamicArray::Remove( int index )
{
	if (index < 0 || index >= m_itemCount)
	{
		return false;
	}

	for (int i = index; i < m_itemCount; i++)
	{
		if (i == m_itemCount - 1)
		{
			m_itemCount--;
			return true;
		}

		m_data[i] = m_data[i + 1];

	}
}


string SmartDynamicArray::Get( int index ) const
{
	if (index < 0 || index >= m_itemCount)
	{
		return "";
	}

	return m_data[index];
}


int SmartDynamicArray::Size() const
{
	return m_itemCount;
}

int SmartDynamicArray::GetMaxSize() const
{
    return -1; // temp
}

bool SmartDynamicArray::IsFull() const
{
	if (m_itemCount == m_arraySize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SmartDynamicArray::IsEmpty() const
{
	if (m_itemCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string SmartDynamicArray::operator[]( int index )
{
	return ""; // temp
}

SmartDynamicArray& SmartDynamicArray::operator=( const SmartDynamicArray& other )
{
    return *this; // temp
}

bool SmartDynamicArray::operator==( const SmartDynamicArray& other )
{
	int compareCount = 0;
	
	for (int i = 0; i < m_arraySize; i++)
	{
		if (m_data[i] == other.Get(i))
		{
			compareCount++;
		}
	}

	if (compareCount == m_arraySize)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool SmartDynamicArray::operator!=( const SmartDynamicArray& other )
{
	return false; // temp
}

void SmartDynamicArray::Free()
{
	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}
}

void SmartDynamicArray::Resize()
{
	Resize(m_arraySize + 10);
}


void SmartDynamicArray::Resize( int newSize )
{
	//create a new dynamic array w/ larger size
	string* newArray = new string[newSize];

	//copy over the contents of old array to new array
	for (int i = 0; i < newSize; i++)
	{
		newArray[i] = m_data[i];
	}

	//free the memorry being pointed to by the old array
	delete[] m_data;

	//update m_data's pointer to the new array
	m_data = newArray;

	//update the m_arraySize value to the new size
	m_arraySize = newSize;


}




