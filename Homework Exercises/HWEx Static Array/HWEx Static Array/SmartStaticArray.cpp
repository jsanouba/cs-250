#include "SmartStaticArray.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push( const string& newItem )
{
	if ( IsFull() )
	{
		return false; // temp
	}

	m_data[m_itemCount] = newItem;
	m_itemCount++;
}


bool SmartStaticArray::Insert( int index, const string& newItem )
{
	if (index < 0 || index > m_itemCount || index == MAX_SIZE)
	{
		return false; // temp
	}
	else if (index == m_itemCount)
	{
		m_data[index] = newItem;
	}
	else
	{
		for (int i = m_itemCount; i >= index; i--)
		{
			m_data[i] = m_data[i - 1];
		}
	}
	m_data[index] = newItem;
}


bool SmartStaticArray::Extend( const SmartStaticArray& other )
{
	//if (m_itemCount + other.Size() > MAX_SIZE)
	//{
	//	return false; // temp
	//}

	//for (int i = m_itemCount; i < m_itemCount + other.Size(); i++)
	//{
	//	m_data[i] = other[i - m_itemCount];
	//}
	return false;
}


bool SmartStaticArray::Pop()
{
	if ( IsEmpty() )
	{
		return false;
	}

	m_itemCount--;
}


bool SmartStaticArray::Remove( int index )
{
	if (index < 0 || index >= m_itemCount)
	{
		return false;
	}

	for (int i = index; i < m_itemCount; i++)
	{
		if (i == m_itemCount - 1)
		{
			m_data[i] = "";
		}
		else
		{
			m_data[i] = m_data[i + 1];
		}
	}
}


string SmartStaticArray::Get( int index ) const
{
	if (index < 0 || index >= m_itemCount)
	{
		return "";
	}

	return m_data[index];
}


int SmartStaticArray::Size() const
{
	return m_itemCount; // temp
}


bool SmartStaticArray::IsFull() const
{
	if (m_itemCount == MAX_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SmartStaticArray::IsEmpty() const
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


string SmartStaticArray::operator[]( int index )
{
	if (index < 0 || index >= m_itemCount)
	{
		return "";
	}

	return m_data[index];
}


SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
    SmartStaticArray blorp; // temp
    return blorp; // temp
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
	return false; // temp
}
