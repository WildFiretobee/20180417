 ///
 /// @file    arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-17 16:12:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data()
	{
		cout << "Data()" << endl;
	}
	void display()
	{
		cout << "Data::display()" << endl;
	}

	~Data()
	{
		cout << "~Data()" << endl;
	}
};

class SecondLayer
{
public:
	SecondLayer(Data * pdata)
	: _pdata(pdata)
	{
		cout << "SecondLayer(Data *)" << endl;
	}

	void print() 
	{
		cout << "SecondLayer::print()" << endl;
	}

	Data * getDataPtr()
	{
		return _pdata;
	}

	//ָ���������� �����ǳ�Ա��������ʽ
	//
	Data * operator->()
	{
		return _pdata;
	}

	//�����������
	//�Ƽ��Գ�Ա��������ʽ����
#if 1
	Data & operator*()
	{
		return *_pdata;
	}
#endif

	//friend Data & operator*(SecondLayer & sl);

	~SecondLayer()
	{
		cout << "~SecondLayer()" << endl;
		delete _pdata;
	}
private:
	Data * _pdata;
};

//�����÷����������������Ԫ��ʽ
#if 0
Data & operator*(SecondLayer & sl)
{
	return *(sl._pdata);
}
#endif

class ThirdLayer
{
public:
	ThirdLayer(Data * pdata)
	:_sl(pdata)
	{
		cout << "ThirdLayer()" << endl;
	}
	
	SecondLayer & operator->()
	{
		return _sl;
	}

	~ThirdLayer()
	{
		cout << "~ThirdLayer()" << endl;
	}
	
private:
	SecondLayer _sl;
};



 
int main(void)
{
	Data * p = NULL;
	p->display();
	cout << endl;

	SecondLayer sl(new Data);//sl�Ƕ���
	//sl.print();
	
	//sl.getDataPtr()->display();
	sl->display();//��д����ָ����һ����
	//sl.operator->()->display();
	(*sl).display();

	cout << endl;
	ThirdLayer tl(new Data);
	tl->display();

	return 0;
}