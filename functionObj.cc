 ///
 /// @file    Demo.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-17 11:45:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;


struct Function
{
	//�������������
	int operator()(int x, int y)
	{
		++_count;
		return x + y;
	}

	int operator()(int x, int y, int z)
	{
		return x * y * z;
	}

	int getCount() const {	return _count;	}

	int _count = 0;// �����״̬
};

//������������ͨ�����Ĳ��
//���������ڲ����Դ洢�Լ���״̬
//
//�հ�
//
void display(void)
{
	static int count = 0;
	++count;
}
 
int main(void)
{
	Function func;
	cout << "1 + 2 = " << func(1, 2) << endl;//��������: �����˺�������������Ķ���
	cout << "3 + 4 =" << func(3, 4) << endl;
	cout << "func(1, 2, 3) = " << func(1, 2, 3) << endl;

	cout << "func��ִ���� " << func.getCount() << "��" << endl;

	Function func2;
	cout << "5 + 6 = " << func2(5, 6) << endl;
	cout << "func2��ִ���� " << func2.getCount() << "��" << endl;

	return 0;
}