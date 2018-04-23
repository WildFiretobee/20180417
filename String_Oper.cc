 ///
 /// @file    String_Oper.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-17 20:36:13
 ///
#include "Mylogger.h"
#include <string.h>
#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;

class String
{
public:
	String(size_t size=10)
	: _size(size)
	, _pstr(new char[_size]())
	{
		LogError("String(size_t)");
		cout << "String()" << endl;
	}
	String(const char *pstr)
	: _pstr(new char[strlen(pstr)+1]())
	{
		strcpy(_pstr,pstr);
		cout << "String(const char *)" << endl;
	}

	String(const String &rhs)
	: _pstr(new char[strlen(rhs._pstr)+1]())
	{
		strcpy(_pstr,rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	~String()
	{
		cout << "~String()" << endl;
//		if(this->_pstr)
//			delete [] _pstr;
	}

	String &operator=(const String &rhs)
	{
		cout << "String &operator=(const String &)" << endl;
		if(this!=&rhs)
		{
			delete [] _pstr;
			_pstr=new char[strlen(rhs._pstr)+1]();
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}

	String &operator=(const char *rhs)
	{
		cout << "String &operator=(const char *)" << endl;
		for(size_t idx=0;idx!=strlen(rhs);++idx)
		{
			_pstr[idx]=rhs[idx];
		}
		return *this;
	}

	String &operator+=(const String &rhs)
	{
		cout << "String &operator+=(const String &)" << endl;
		strcat(_pstr,rhs._pstr);
		return *this;
	}
	
	String &operator+=(const char *rhs)
	{
		cout << "String &operator+=(const char *)" << endl;
		strcat(_pstr,rhs);
		return *this;
	}

	char &operator[](size_t index) const
	{
		if(index<size())
		{
			return _pstr[index];
		}else
		{
			static char nullchar='\0';
			return nullchar;
		}
	}


	size_t size() const
	{
		return _size;
	}

	const char* c_str() const
	{
		cout << "const char* c_str() const" << endl;
		return _pstr;
	}

	friend String operator+(const String & lhs,const String & rhs);
	friend String operator+(const String &lhs,const char *rhs);
	friend String operator+(const char *lhs,const String &rhs);
	friend bool operator==(const String & ,const String & );

	friend bool operator!=(const String & ,const String & );

	friend bool operator<(const String & ,const String &);
	friend bool operator>(const String & ,const String &);
	friend bool operator<=(const String & ,const String &);
	friend bool operator>=(const String & ,const String &);

	friend std::ostream &operator<<(std::ostream &os,const String &s);
	friend std::istream &operator>>(std::istream &is,String &s);
	
	void print() const
	{
		cout << _pstr << endl;
	}

private:
	size_t _size;
	char * _pstr;
};

   String operator+(const String &lhs,const String &rhs)
   {
	   cout << "String operator+(const String &,const String &)" << endl;
	   return String(strcat(lhs._pstr,rhs._pstr));
   }

	String operator+(const String &lhs,const char *rhs)
	{
		cout << "String operator+(const String &,const char *)" << endl;
		return String(strcat(lhs._pstr,rhs));
	}		
	
	String operator+(const char *lhs,const String &rhs)
	{
		cout << "String operator+(const char*,const String&)" << endl;
		char *p=new char[strlen(lhs)+1];
		strcpy(p,lhs);
		return String(strcat(p,rhs._pstr));
	}

	bool operator==(const String &lhs,const String &rhs)
	{
		cout << "bool operator==(const String&,const String&)" << endl;
		if(0==strcmp(lhs._pstr,rhs._pstr))
			return 1;
		else
			return 0;
	}
	
	bool operator!=(const String &lhs,const String &rhs)
	{
		cout << "bool operator!=(const String&,const String&)" << endl;
		if(0==strcmp(lhs._pstr,rhs._pstr))
			return 0;
		else
			return 1;
	}
	
	bool operator<(const String &lhs,const String &rhs)
	{
		
		cout << "bool operator<(const String&,const String&)" << endl;
		if(strcmp(lhs._pstr,rhs._pstr)>0)
			return 1;
		else
			return 0;
	}
	
	bool operator>(const String &lhs,const String &rhs)
	{
		cout << "bool operator>(const String&,const String&)" << endl;
		if(strcmp(lhs._pstr,rhs._pstr)<0)
			return 1;
		else
			return 0;
	}

	bool operator<=(const String &lhs,const String &rhs)
	{
		cout << "bool operator<=(const String&,const String&)" << endl;
		if(strcmp(lhs._pstr,rhs._pstr)<0)
			return 0;
		else
			return 1;
	}

	bool operator>=(const String &lhs,const String &rhs)
	{
		cout << "bool operator>=(const String&,const String&)" << endl;
		if(strcmp(lhs._pstr,rhs._pstr)>0)
			return 0;
		else
			return 1;
	}
	std::ostream &operator<<(std::ostream &os,const String &s)
	{
//		cout << "std::ostream &operator<<(std::ostream &,const String &)" << endl;
		os << s._pstr ;
		return os;
	}
	
	std::istream &operator>>(std::istream &is,String &s)
	{
		cout << "std::istream &operator>>(std::istream &is,String&)" << endl;
		is.getline(s._pstr,100);
		return is;
	}

int main(void)
{
	String str;
	str.print();

	String str2("I am a student");
	str2.print();

	cout << endl;
	String str3=str2;
	str3.print();
	
	cout << endl;
	String str4("This is a test");
	str2=str4;
	str4.print();

	cout << endl;
	const char * words="hello,world";
	String str5(strlen(words)+1);
	for(size_t idx=0;idx!=strlen(words);++idx)
	{
		str5[idx]=words[idx];
	}
	cout << "char &operator[](size_t )" << endl;

	for(size_t idx=0;idx!=str5.size();++idx)
	{
		cout << str5[idx];
	}
	cout << endl<<endl;

	String str6=str2+str3;
	str6.print();
	cout << endl;
	
	String str7="How are you";
	str7.print();
	cout << endl;

	str7+=str3;
	str7.print();
	cout << endl;
	
	str6+="this is operator +=";
	str6.print();
	cout << endl;
	
	const char *str8=str2.c_str();
	cout<< str8 << endl;
	cout << endl;

	String str9=str2+"this is str9";
	str9.print();
	cout << endl;

	String str10="str10=look here,look here"+str5;
	str10.print();
	cout << endl;

	cout << "str2 == str3 ? " << (str2==str3)  << endl;
	cout << "str3 == str3 ? " << (str3==str3) << endl;
	cout << endl;

	
	cout << "str2 != str3 ? " << (str2!=str3)  << endl;
	cout << "str3 != str3 ? " << (str3!=str3) << endl;
	cout << endl;

	cout << "str2 < str3 ? " << (str2 < str3)  << endl;
	cout << "str3 > str3 ? " << (str3 > str3) << endl;
	cout << endl;
	
	cout << "str2 <= str3 ? " << (str2 <= str3)  << endl;
	cout << "str3 <= str3 ? " << (str3 <= str3) << endl;
	cout << endl;

	cout << "str2 >= str3 ? " << (str2 >= str3)  << endl;
	cout << "str3 >= str3 ? " << (str3 >= str3) << endl;
	cout << endl;

	cout << "str2 = " << str2 << endl;
	cout << "str4 = " << str4 << endl;
	cout << endl;
	
	
	cin >> str;
	cout << "输入数据为：";
	str.print();
	cout << endl;

	return 0;
}


