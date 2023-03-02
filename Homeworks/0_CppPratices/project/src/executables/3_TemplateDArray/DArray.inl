// implementation of class DArray
#include <iostream>
#include <cassert>
// default constructor
template<typename T>
DArray<T>::DArray()
{
	Init();
}

// set an array with default values
template<typename T>
DArray<T>::DArray(int nSize, const T& dValue)
	: m_pData(new T[nSize * 2]), m_nSize(nSize), m_nMax(nSize * 2)
{
	// TODO
	for(int i = 0; i < nSize; ++i)
	{
		m_pData[i] = dValue;
	}
}

template<typename T>
DArray<T>::DArray(const DArray &arr)
	: m_pData(new T[arr.GetSize() * 2]), m_nSize(arr.GetSize()), m_nMax(arr.GetSize() * 2)
{
	// TODO
	for(int i = 0; i < m_nSize; ++i)
	{
		m_pData[i] = arr.GetAt(i);
	}
}

// deconstructor
template<typename T>
DArray<T>::~DArray()
{
	Free();
}

// display the elements of the array
template<typename T>
void DArray<T>::Print() const
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
template<typename T>
void DArray<T>::Init()
{
	// TODO
	m_pData = NULL;
	m_nSize = 0;
	m_nMax = 0;
}

// free the array
template<typename T>
void DArray<T>::Free()
{
	// TODO
	delete[] m_pData;
	m_pData = NULL;
	m_nSize = 0;
	m_nMax = 0;
}

// get the size of the array
template<typename T>
int DArray<T>::GetSize() const
{
	// TODO
	return m_nSize; // you should return a correct value
}

// set the size of the array
template<typename T>
void DArray<T>::SetSize(int nSize)
{
	// TODO
	if(nSize <= m_nMax)
	{
		for(int i = m_nSize; i < nSize; ++i)
		{
			m_pData[i] = static_cast<T>(0);
		}
		m_nSize = nSize;
		
		return;
	}

	T* new_pData = new T[nSize * 2];
	m_nMax = nSize * 2;

	for(int i = 0; i < m_nSize; ++i)
	{
		new_pData[i] = m_pData[i];
	}
	for(int i = m_nSize; i < nSize; ++i)
	{
		new_pData[i] = static_cast<T>(0);
	}
	delete[] m_pData;
	m_pData = new_pData;
	m_nSize = nSize;
	
}

// get an element at an index
template<typename T>
const T& DArray<T>::GetAt(int nIndex) const
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];		 // you should return a correct value
}

// set the value of an element
template<typename T>
void DArray<T>::SetAt(int nIndex, const T& dValue)
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	m_pData[nIndex] = dValue;
}

// overload operator '[]'
template<typename T>
T &DArray<T>::operator[](int nIndex)
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];		 // you should return a correct value
}

// overload operator '[]'
template<typename T>
const T &DArray<T>::operator[](int nIndex) const
{
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];		 // you should return a correct value
}

// add a new element at the end of the array
template<typename T>
void DArray<T>::PushBack(const T& dValue)
{
	// TODO
	if(m_nSize + 1 <= m_nMax)
	{
		++m_nSize;
		m_pData[m_nSize - 1] = dValue;
		return;
	}

	T* new_pData = new T[(m_nMax + 1) * 2];
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
template<typename T>
void DArray<T>::DeleteAt(int nIndex)
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
template<typename T>
void DArray<T>::InsertAt(int nIndex, const T& dValue)
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

	T* new_pData = new T[(m_nMax + 1) * 2];
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
template<typename T>
DArray<T> &DArray<T>::operator=(const DArray &arr)
{
	// TODO
	delete[] m_pData;
	m_nSize = arr.GetSize();
	m_nMax = m_nSize * 2;
	m_pData = new T[m_nMax];
	for(int i = 0; i < m_nSize; ++i)
	{
		m_pData[i] = arr.GetAt(i);
	}
	return *this;
}
