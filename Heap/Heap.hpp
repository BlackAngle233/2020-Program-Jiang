#ifndef HEAP_H
#define HEAP_H

#include <vector>
template<class T>
class Heap
{
private: std::vector<T> data; void Adjustdown(int root)
    {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        
        if(root >= data.size())
        {
            return ;
        }
        int minIndex =  left;
        if(right < data.size() && data[right] < data[left])
        {
            minIndex = right;
        }

        if(data[root] <= data[minIndex])
        {
            return ;
        }

        if(minIndex < data.size())
        {
            T t = data[minIndex];
            data[minIndex] =  data[root];
            data[root] = t;
        }
        Adjustdown(minIndex);
    }


public:
    Heap()  {}

    int size() const
    {
        return data.size();
    }

    void push(const T& _v) noexcept
    {
        data.push_back(_v);
        for(int i = data.size() / 2 - 1; i >= 0; --i)
        {
            Adjustdown(i);
        }
    }

    void pop()
    {
        if(data.empty()) return ;
        T t = data[0];
        data[0] = data[data.size() - 1];
        data[data.size() - 1] = t;
        data.resize(data.size() - 1);
        for(int i = data.size() / 2 - 1; i >= 0; --i)
        {
            Adjustdown(i);
        }
    }

    T front() const
    {
        return data[0];
    }

};

#endif /* HEAP_H */
