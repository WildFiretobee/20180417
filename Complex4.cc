 ///
 /// @file    Complex4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-17 10:03:58
 ///
 
//#include "Mylogger.h"
#include <iostream>
#include <limits>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal = 0, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
//		LogDebug("Complex(double, double)");
	}
	void display() const
	{
		if(_dreal == 0 && _dimag != 0)
			cout << _dimag << "i" << endl;
		else
		{
			cout << _dreal;
			if(_dimag > 0)
				cout << "+" << _dimag << "i" << endl;
			else if(_dimag < 0)
				cout << _dimag << "i" << endl;
			else 
				cout << endl;
		}
	}

	//���ִ�������֮�󣬶������ֵ�����仯�������Գ�Ա������ʽ��������
	//
	// -= *=  /=   %=
	//
	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}

	//ǰ��++, ��Ч�ʱȺ��ø���
	Complex & operator++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}
	//����++
	Complex operator++(int) //int��Ϊ������ǰ�úͺ���
	{
		Complex ret(*this);
		++_dreal;
		++_dimag;
		return ret;
	}

	friend Complex operator+(const Complex & lhs, const Complex & rhs);
	friend bool operator<(const Complex & lhs, const Complex & rhs);
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);

	//���������������������ԣ�����Գ�Ա������ʽ�������أ���һ��������
	//������this�������������������������������������������;
	//����������������������ǳ�Ա����
	//operator<<();

private:
	double _dreal;
	double _dimag;
};

//����Ԫ��������ʽ���������
//
//+ - * /
//
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	if(rhs._dreal == 0 && rhs._dimag != 0)
		os << rhs._dimag << "i";
	else
	{
		os << rhs._dreal;
		if(rhs._dimag > 0)
			os << "+" << rhs._dimag << "i";
		else if(rhs._dimag < 0)
			os << rhs._dimag << "i";
	}
	return os;
}

void inputDouble(std::istream & is, double & value)
{
	while(is >> value, !is.eof())
	{
		if(is.bad())
		{
//			LogError("istream corrupted!");
			return;
		}else if(is.fail())
		{
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "pls input a double value: " << endl;
			continue;
		}
		break;
	}
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
	cout << "pls input real double value:";
	inputDouble(is, rhs._dreal);
	cout << "pls input image double value:";
	inputDouble(is, rhs._dimag);
	return is; 
} 
//�Զ���ȽϷ�ʽ
//
//>  >= <=  !=  ==
//
bool operator<(const Complex & lhs, const Complex & rhs)
{
	return lhs._dreal < rhs._dreal;
}
 
//int operator+(int,int);

int main(void)
{
	Complex c1(1, 2);
	cout << c1 << endl;
	return 0;
}

int test1(void)
{
	Complex c1;
	while(std::cin >> c1)
	{
		cout << "c1 = " << c1 << endl;
	}

	return 0;
}

int test0(void)
{
	int a = 3, b = 4;
	int c = a + b;
	cout << "c = " << c << endl;

	a += b;// a = a + b

	++a;
	a++;

	Complex c1(1, 2);
	cout << "c1 = " << c1 << endl;

	Complex c2(-3, 4);
	cout << "c2 = " << c2 << endl;

	Complex c3 = c1 + c2;// Complex c3 = operator+(c1, c2)
	cout << "c3 = " << c3 << endl;
	cout << endl;

	c1 += c2;// c1.operator+=(c2) 
	cout << "c1 = " << c1 << endl;//��ʽ���
	// operator<<(operator<<(operator<<(cout, "c1 = "), c1), endl);
	// operator<<(cout, c1);

	cout << "ǰ��++�����ʽ��ֵ:";
	cout << (++c1) << endl;
	cout << endl;
	cout << "ǰ��++ ֮��, c1 =" << c1 << endl;

	cout << "����++�����ʽ��ֵ:";
	cout << (c1++) << endl;
	cout << "����++ ֮��, c1 =";
	cout << "c1 = " << c1 << endl;

	cout << "�ȽϷ�ʽ��" << endl;
	cout << "c1 < c2 ? " << (c1 < c2) << endl;
	return 0;
}
