#include<iostream>
#include<cassert>
#include<vector>

using namespace std;

class My_Shared_Ptr {
public:
	My_Shared_Ptr(int* ptr)
	{
		if (ptr) {
			data_ptr = new Data{ ptr, 1 };
		}
	}
	~My_Shared_Ptr()
	{
		release();
	}
	//My_Shared_Ptr();
	My_Shared_Ptr(const My_Shared_Ptr& other)
		:data_ptr{other.data_ptr}
	{
		if (data_ptr) {
			data_ptr->ref_count++;
		}
	}

	int* get()
	{
		return data_ptr ? data_ptr->ptr : nullptr;
	}

	My_Shared_Ptr& operator=(const My_Shared_Ptr& other)
	{
		if (this == &other)
		{
			return *this;
		}
		release();
		data_ptr = other.data_ptr;
	}
	size_t ref_count() const
	{ 
		return data_ptr ? data_ptr->ref_count : 0; 
	}
	int& operator * ()
	{
		assert(data_ptr);
		return *data_ptr->ptr;
	}
	int* operator ->()
	{
		return data_ptr ? data_ptr->ptr : nullptr;
	}
private:
	void release() {
		if (data_ptr)
			if (--data_ptr->ref_count == 0)
				data_ptr = nullptr;
	}
private:
	struct Data {//这是一个智能指针，要求在无人调用的时候删除自己
		int* ptr;
		size_t ref_count{};
		~Data() {
			delete ptr;
		}
	};
	Data* data_ptr{};
};

class MyString {
public:
	using iterator = char*;//迭代器
	iterator begin() { return buff_ ? buff_->p : nullptr; };//返回起始地址
	iterator end(){return buff_ ? buff_->p + buff_->length : nullptr;}//返回下一个
	MyString()
	{
		this->len = 0;
	}
	MyString(char c)
	{
		;
	}
	MyString(const char* p)
	{
		if (str == NULL)
		{
			this->len = 0;
			this->str = NULL;
		}
		else
		{
			this->len = strlen(str) + 1;
			this->str = new char[len];
			strcpy(this->str, str);
		}
	}
	~MyString()
	{
		delete[] this->str;
	}
	MyString(const MyString& other)
	{
		if (other.str == NULL)
		{
			this->len = 0;
			this->str = NULL;
		}
		else
		{
			this->len = other.len;
			this->str = new char[len];
			strcpy(this->str, other.str);
		}
	}
	MyString& operator = (const MyString& other)
	{
		if (other.str == NULL)
		{//如果我要复制的是空，那么我就空了
			this->len = 0;
			this->str = NULL;
		}
		else
		{
			this->len = other.len;
			if (this == &other)
				return *this;//已经相等了，那么直接返回
			if (this->str != NULL)
				delete[] this->str;//对方不是空，我就可以删除自身
			this->str = new char[len];//将对方复制给自己
			strcpy(this->str, other.str);
		}
		return *this;
	}
	MyString(MyString&& other)
	{
		if (other.str == NULL)
		{
			this->len = 0;
			this->str = NULL;
		}
		else
		{
			this->len = other.len;
			strcpy(this->str, other.str);
		}
	}
	MyString& operator = (MyString&& other)
	{
		if (other.str == NULL)
		{//如果我要复制的是空，那么我就空了
			this->len = 0;
			this->str = NULL;
		}
		else
		{
			this->len = other.len;
			if (this == &other)
				return *this;//已经相等了，那么直接返回
			if (this->str != NULL)
				delete[] this->str;//对方不是空，我就可以删除自身
			this->str = new char[len];//将对方复制给自己
			strcpy(this->str, other.str);
		}
		return *this;
	}
	bool empty() const
	{
		if (this->len == 0)
		{
			return true;
		}
		else
			return false;
	}
	size_t length() const
	{
		return len;
	}
	MyString& operator + (const MyString& other)
	{
		MyString sum;
		if (this->str == NULL && other.str == NULL)
			return sum;//都是空的，返回空的
		if (this->str == NULL && other.str != NULL)
		{
			sum.len = other.len;
			sum.str = new char[sum.len];
			strcpy(sum.str, other.str);
			return sum;//如果我是空的，对方不空，那么返回对方
		}
		if (this->str != NULL && other.str == NULL)
		{
			sum.len = this->len;
			sum.str = new char[sum.len];
			strcpy(sum.str, this->str);
			return sum;//如果对方是空的，我不空，那么返回我
		}
		if (this->str != NULL && other.str != NULL)
		{
			sum.len = this->len + other.len;
			sum.str = new char[sum.len];
			memset(sum.str, 0, sum.len);//将开辟出来的新空间里的值设为0
			strcpy(sum.str, this->str);//先把我拷贝进去再加
			char *point = sum.str;
			while (true)
			{
				if (*point == '\0')
					break;
				point++;
			}//先定一个指针找到我拷贝的末尾
			strcpy(point, other.str);//再吧对方拷贝到这个位置
			return sum;
		}
		return sum;
	}
	//char& operator[](size_t index);//不强制要求
private:
	std::shared_ptr<vector<char>> a;
	char * str;
	int len;
	//或者
	struct Buf {
		size_t length;
		char* p;
	};
	std::shared_ptr<Buf> buff_;
};


int main()
{
	//{
	//	My_Shared_Ptr p1(new int{ 5 });
	//	{
	//		//My_Shared_Ptr p2 = p1;
	//		//My_Shared_Ptr p2 = std::move(p1);
	//		auto&& p = std::move(p1);
	//		My_Shared_Ptr p2 = p;
	//		cout << *p2 << " ref count " << p1.ref_count() << endl;
	//		*p2 = 6;
	//	}
	//	cout << *p1 << " ref count " << p1.ref_count() << endl;
	//	My_Shared_Ptr p3{ new int{6} };
	//	p3 = p1;
	//	cout << *p3 << " ref count " << p3.ref_count() << endl;
	//}
	//std::shared_ptr<int> p4{ new int{6} };//一种新的方法
	//*p4 = 7;//智能指针可以直接用这个功能，不需要自己再写新的
	MyString s1;
	MyString::iterator it = s1.begin();

	system("pause");
	return 0;
}


