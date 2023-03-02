#include "PolynomialMap.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#define EPSILON 1.0e-10
using namespace std;

PolynomialMap::PolynomialMap(const PolynomialMap &other)
{
	// TODO
	m_Polynomial = other.m_Polynomial;
}

PolynomialMap::PolynomialMap(const string &file)
{
	ReadFromFile(file);
}

PolynomialMap::PolynomialMap(const double *cof, const int *deg, int n)
{
	// TODO
	for(int i = 0; i < n; ++i)
	{
		coff(deg[i]) = cof[i];
	}
}

PolynomialMap::PolynomialMap(const vector<int> &deg, const vector<double> &cof)
{
	assert(deg.size() == cof.size());
	
	// TODO
	for(int i = 0; i < deg.size(); ++i)
	{
		coff(deg[i]) = cof[i];
	}
}

double PolynomialMap::coff(int i) const
{
	// TODO
	if(m_Polynomial.find(i) == m_Polynomial.end())
	{
		return 0.0;
	}

	return m_Polynomial.find(i)->second; // you should return a correct value
}

double &PolynomialMap::coff(int i)
{
	// TODO
	return m_Polynomial[i];
}

void PolynomialMap::compress()
{
	// TODO
	map<int, double> hashtable = m_Polynomial;
	m_Polynomial.clear();
	for(auto& it : hashtable)
	{
		if(fabs(it.second) > EPSILON)
		{
			coff(it.first) = it.second;
		}
	}
	hashtable.clear();
}

PolynomialMap PolynomialMap::operator+(const PolynomialMap &right) const
{
	// TODO
	PolynomialMap temp(right);
	for(auto it : m_Polynomial)
	{
		temp.coff(it.first) += it.second;
	}
	temp.compress();
	return temp; // you should return a correct value
}

PolynomialMap PolynomialMap::operator-(const PolynomialMap &right) const
{
	// TODO
	PolynomialMap temp(right);
	for(auto it : m_Polynomial)
	{
		temp.coff(it.first) -= it.second;
	}
	temp.compress();
	return temp; // you should return a correct value
}

PolynomialMap PolynomialMap::operator*(const PolynomialMap &right) const
{
	// TODO
	PolynomialMap temp(right);
	for(auto it : m_Polynomial)
	{
		for(auto it2 : right.m_Polynomial)
		{
			int deg = it.first + it2.first;
			double cof = it.second * it2.second;
			temp.coff(deg) += cof;
		}
	}
	temp.compress();
	return temp; // you should return a correct value
}

PolynomialMap &PolynomialMap::operator=(const PolynomialMap &right)
{
	// TODO
	m_Polynomial = right.m_Polynomial;
	return *this;
}

void PolynomialMap::Print() const
{
	// TODO
	if(m_Polynomial.empty())
	{
		cout<<"0"<<endl;
		return;
	}
	for(auto it : m_Polynomial)
	{
		if(it.second > 0)
		{
			cout<<"+";
		}
		
		cout<<it.second;
		cout<<"x^"<<it.first;
		
	}
	cout<<endl;
}

bool PolynomialMap::ReadFromFile(const string &file)
{
	m_Polynomial.clear();

    ifstream inp;
    inp.open(file.c_str());
    if (!inp.is_open()) {
        cout << "ERROR::PolynomialList::ReadFromFile:" << endl
            << "\t" << "file [" << file << "] opens failed" << endl;
        return false;
    }

    char ch;
    int n;
    inp >> ch;
    inp >> n;
    for (int i = 0; i < n; i++) {
        int deg;
        double cof;
        inp >> deg;
        inp >> cof;
        coff(deg) = cof;
    }

    inp.close();

    return true;
}
