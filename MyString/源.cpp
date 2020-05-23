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
	struct Data {//����һ������ָ�룬Ҫ�������˵��õ�ʱ��ɾ���Լ�
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
	using iterator = char*;//������
	iterator begin() { return buff_ ? buff_->p : nullptr; };//������ʼ��ַ
	iterator end(){return buff_ ? buff_->p + buff_->length : nullptr;}//������һ��
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
		{//�����Ҫ���Ƶ��ǿգ���ô�ҾͿ���
			this->len = 0;
			this->str = NULL;
		}
		else
		{
			this->len = other.len;
			if (this == &other)
				return *this;//�Ѿ�����ˣ���ôֱ�ӷ���
			if (this->str != NULL)
				delete[] this->str;//�Է����ǿգ��ҾͿ���ɾ������
			this->str = new char[len];//���Է����Ƹ��Լ�
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
		{//�����Ҫ���Ƶ��ǿգ���ô�ҾͿ���
			this->len = 0;
			this->str = NULL;
		}
		else
		{
			this->len = other.len;
			if (this == &other)
				return *this;//�Ѿ�����ˣ���ôֱ�ӷ���
			if (this->str != NULL)
				delete[] this->str;//�Է����ǿգ��ҾͿ���ɾ������
			this->str = new char[len];//���Է����Ƹ��Լ�
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
			return sum;//���ǿյģ����ؿյ�
		if (this->str == NULL && other.str != NULL)
		{
			sum.len = other.len;
			sum.str = new char[sum.len];
			strcpy(sum.str, other.str);
			return sum;//������ǿյģ��Է����գ���ô���ضԷ�
		}
		if (this->str != NULL && other.str == NULL)
		{
			sum.len = this->len;
			sum.str = new char[sum.len];
			strcpy(sum.str, this->str);
			return sum;//����Է��ǿյģ��Ҳ��գ���ô������
		}
		if (this->str != NULL && other.str != NULL)
		{
			sum.len = this->len + other.len;
			sum.str = new char[sum.len];
			memset(sum.str, 0, sum.len);//�����ٳ������¿ռ����ֵ��Ϊ0
			strcpy(sum.str, this->str);//�Ȱ��ҿ�����ȥ�ټ�
			char *point = sum.str;
			while (true)
			{
				if (*point == '\0')
					break;
				point++;
			}//�ȶ�һ��ָ���ҵ��ҿ�����ĩβ
			strcpy(point, other.str);//�ٰɶԷ����������λ��
			return sum;
		}
		return sum;
	}
	//char& operator[](size_t index);//��ǿ��Ҫ��
private:
	std::shared_ptr<vector<char>> a;
	char * str;
	int len;
	//����
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
	//std::shared_ptr<int> p4{ new int{6} };//һ���µķ���
	//*p4 = 7;//����ָ�����ֱ����������ܣ�����Ҫ�Լ���д�µ�
	MyString s1;
	MyString::iterator it = s1.begin();

	system("pause");
	return 0;
}


