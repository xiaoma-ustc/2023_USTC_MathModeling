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
	: m_pData(new double[nSize * 2]), m_nSize(nSize), m_nMax(nSize * 2)
{
	// TODO
	for(int i = 0; i < nSize; ++i)
	{
		m_pData[i] = dValue;
	}
}

DArray::DArray(const DArray &arr)
	: m_pData(new double[arr.GetSize() * 2]), m_nSize(arr.GetSize()), m_nMax(arr.GetSize() * 2)
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
	std::cout<<"size = "<< m_nSize << "|";
	for(int i = 0; i < m_nSize; ++i)
	{
		std::cout<<" "<<m_pData[i];
	}
	std::cout<<std::endl;
}

// initilize the array
void DArray::Init()
{
	// TODO
	m_pData = NULL;
	m_nSize = 0;
	m_nMax = 0;
}

// free the array
void DArray::Free()
{
	// TODO
	delete[] m_pData;
	m_pData = NULL;
	m_nSize = 0;
	m_nMax = 0;
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
	if(nSize <= m_nMax)
	{
		for(int i = m_nSize; i < nSize; ++i)
		{
			m_pData[i] = 0.0;
		}
		m_nSize = nSize;
		
		return;
	}

	double* new_pData = new double[nSize * 2];
	m_nMax = nSize * 2;

	for(int i = 0; i < m_nSize; ++i)
	{
		new_pData[i] = m_pData[i];
	}
	for(int i = m_nSize; i < nSize; ++i)
	{
		new_pData[i] = 0.0;
	}
	delete[] m_pData;
	m_pData = new_pData;
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
double &DArray::operator[](int nIndex)
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];		 // you should return a correct value
}

// overload operator '[]'
const double &DArray::operator[](int nIndex) const
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];		 // you should return a correct value
}

// add a new element at the end of the array
void DArray::PushBack(double dValue)
{
	// TODO
	if(m_nSize + 1 <= m_nMax)
	{
		++m_nSize;
		m_pData[m_nSize - 1] = dValue;
		return;
	}

	double* new_pData = new double[(m_nMax + 1) * 2];
	m_nSize = m_nMax + 1;
	m_nMax = m_nSize * 2;

	for(int i = 0; i < m_nSize - 1; ++i)
	{
		new_pData[i] = m_pData[i];
	}
	new_pData[m_nSize - 1] = dValue;

	delete[] m_pData;
	m_pData = new_pData;
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

	--m_nSize;
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue)
{
	// TODO
	assert(nIndex >= 0 && nIndex <= m_nSize);
	if(m_nSize + 1 <= m_nMax)
	{
		for(int i = m_nSize; i > nIndex; --i)
		{
			m_pData[i] = m_pData[i - 1];
		}
		m_pData[nIndex] = dValue;
		++m_nSize;
		return;
	}

	double* new_pData = new double[(m_nMax + 1) * 2];
	m_nSize = m_nMax + 1;
	m_nMax = m_nSize * 2;

	for(int i = 0; i < nIndex; ++i)
	{
		new_pData[i] = m_pData[i];
	}
	new_pData[nIndex] = dValue;
	for(int i = m_nSize - 2; i >= nIndex; --i)
	{
		new_pData[i + 1] = m_pData[i];
	}
	delete[] m_pData;
	m_pData = new_pData;


}

// overload operator '='
DArray &DArray::operator=(const DArray &arr)
{
	// TODO
	delete[] m_pData;
	m_nSize = arr.GetSize();
	m_nMax = m_nSize * 2;
	m_pData = new double[m_nMax];
	for(int i = 0; i < m_nSize; ++i)
	{
		m_pData[i] = arr.GetAt(i);
	}
	return *this;
}
