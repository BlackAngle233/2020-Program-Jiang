#include <memory>
#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
	// 默认构造函数
	String(const char *str = nullptr);
	// 拷贝构造函数
	String(const String &str);
	// 析构函数
	//~String();
	// 字符串赋值函数
	String& operator=(const String &str);
	//数组下标重载
	char& operator[](int num);
	String& operator+(const String &str1);
	friend ostream& operator<<(ostream &out, String &str);
private:
	char Data;
	shared_ptr<char> m_data;
	//char *m_data;
	int m_size;
};

// 构造函数
String::String(const char *str)
{
	if (str == nullptr)
	{
		m_data = shared_ptr<char>(new char[1]);
		*(m_data.get()) = '\0';
		m_size = 0;
	}
	else
	{
		m_size = (size_t)strlen(str);
		m_data = shared_ptr<char>(new char[m_size + 1]);

		for (int i = 0; i < m_size + 1; i++)
		{
			*(m_data.get() + i) = str[i];
			//cout << *(m_data.get() + i);
		}
	}
}

ostream&  operator<<(ostream &out, String &str)
{
	for (int i = 0; i < str.m_size; i++)
		out << *(str.m_data.get() + i);
	return out;
}
// 拷贝构造函数
String::String(const String &str)
{
	m_size = str.m_size;
	m_data = shared_ptr<char>(new char[m_size + 1]);
	for (int i = 0; i < m_size + 1; i++)
	{
		*(m_data.get() + i) = *(str.m_data.get() + i);
	}
}

// 析构函数
//String::~String()
//{
//	//delete[] & m_data;
//}

// 字符串赋值函数
String& String::operator=(const String &str)
{
	if (this == &str)
	{
		return *this;
	}
	m_size = str.m_size;
	m_data = shared_ptr<char>(new char[m_size]);
	m_data = str.m_data;

	return *this;
}
//数组下标重载
char& String::operator[](int num)
{
	if (num < 0 || num >= m_size)
		throw "数组超界";
	if (!m_data.unique())
	{
		String temp;
		//temp.m_data= make_shared<char>(new char[m_size + 1]);
		for (int i = 0; i < m_size; i++)
			*(temp.m_data.get() + i) = *(m_data.get() + i);
		temp.m_size = m_size;
		m_data = temp.m_data;
	}
	return *m_data;// TODO: 在此处插入 return 语句
}
String & String::operator+(const String & str1)
{
	int max_size;
	max_size = str1.m_size + m_size;
	String new_string(new char[max_size]);
	new_string.m_data = shared_ptr<char>(new char[max_size]);
	for (int i = 0; i < max_size; i++)
	{
		if (i < m_size)
			*(new_string.m_data.get() + i) = *(m_data.get() + i);
		else
			*(new_string.m_data.get() + i) = *(str1.m_data.get() + i - m_size);
	}
	return new_string;// TODO: 在此处插入 return 语句
}