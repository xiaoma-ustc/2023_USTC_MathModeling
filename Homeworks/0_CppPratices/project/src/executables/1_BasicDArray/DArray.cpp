// implementation of class DArray
#include "DArray.h"
#include <iostream>
#include <cassert>
// default constructor
DArray::DArray()
{
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue)
	: m_pData(new double[nSize]), m_nSize(nSize)
{
	// TODO
	for(int i = 0; i < nSize; ++i)
	{
		m_pData[i] = dValue;
	}
}

DArray::DArray(const DArray &arr)
	: m_pData(new double[arr.GetSize()]), m_nSize(arr.GetSize())
{
	// TODO
	for(int i = 0; i < m_nSize; ++i)
	{
		m_pData[i] = arr.GetAt(i);
	}
}

// deconstructor
DArray::~DArray()
{
	Free();
}

// display the elements of the array
void DArray::Print() const
{
	// TODO
	std::cout<<"size : "<<m_nSize;
	for(int i = 0; i < m_nSize; ++i)
	{
		std::cout<<" "<<GetAt(i);
	}
	std::cout<<std::endl;
}

// initilize the array
void DArray::Init()
{
	// TODO
	m_nSize = 0;
	m_pData = NULL;
}

// free the array
void DArray::Free()
{
	// TODO
	delete[] m_pData;
	m_pData = NULL;
	m_nSize = 0;
}

// get the size of the array
int DArray::GetSize() const
{
	// TODO
	return m_nSize; // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize)
{
	// TODO
	if(m_nSize == nSize)
	{
		return;
	}

	double* new_pDate = new double[nSize];
	int copySize = m_nSize < nSize? m_nSize : nSize;
	for(int i = 0; i < copySize; ++i)
	{
		new_pDate[i] = m_pData[i];
	}
	for(int i = copySize; i < nSize; ++i)
	{
		new_pDate[i] = 0.0;
	}

	delete[] m_pData;
	m_pData = new_pDate;
	m_nSize = nSize;

}

// get an element at an index
const double &DArray::GetAt(int nIndex) const
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];		 // you should return a correct value
}

// set the value of an element
void DArray::SetAt(int nIndex, double dValue)
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	m_pData[nIndex] = dValue;
}

// overload operator '[]'
const double &DArray::operator[](int nIndex) const
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];
}

// add a new element at the end of the array
void DArray::PushBack(double dValue)
{
	// TODO
	SetSize(m_nSize + 1);
	SetAt(m_nSize - 1, dValue);
}

// delete an element at some index
void DArray::DeleteAt(int nIndex)
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	for(int i = nIndex; i < m_nSize - 1; ++i)
	{
		m_pData[i] = m_pData[i + 1];
	}
	SetSize(m_nSize - 1);
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue)
{
	// TODO
	assert(nIndex >= 0 && nIndex <= m_nSize);
	SetSize(m_nSize + 1);
	for(int i = m_nSize - 1; i > nIndex; --i)
	{
		m_pData[i] = m_pData[i - 1];
	}
	m_pData[nIndex] = dValue;
}

// overload operator '='
DArray &DArray::operator=(const DArray &arr)
{
	// TODO
	delete[] m_pData;
	m_nSize = arr.GetSize();
	m_pData = new double[m_nSize];
	for(int i = 0; i < m_nSize; ++i)
	{
		m_pData[i] = arr.GetAt(i);
	}
	return *this;
}
