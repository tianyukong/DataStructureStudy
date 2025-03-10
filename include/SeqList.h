#pragma once

#include <iostream>
#include <format>
using std::cout;
using std::endl;

template <typename T>
class SeqList
{
private:
    T *m_data;       // 将 int 改为 T
    int m_size;
    int m_length;

public:
    SeqList(int size);
    ~SeqList();
    int insert(T value);  // 参数类型改为 T
    int insert(int pos, T value); 
    int remove(T value);
    void print();
};

template <typename T>
SeqList<T>::SeqList(int size)
{
	m_size = size;
	m_length = 0;
	m_data = new T[size];
}

template <typename T>
SeqList<T>::~SeqList()
{
    delete[] m_data;
    m_data = nullptr;
}

template <typename T>
int SeqList<T>::insert(T value)  // 参数类型改为 T
{
    if (this->m_length == this->m_size)
    {
        cout<<std::format("error the list is full")<<endl;    
        return -1;
    }
    this->m_data[this->m_length] = value;
    this->m_length++;
    cout<<std::format("insert {} success", value)<<endl;
    return 0;    
}


template <typename T>
int SeqList<T>::insert(int pos, T value)
{
    if (pos < 0 || pos > this->m_length)
    {
        cout<<std::format("error the position is invalid")<<endl;
        return -1;
    }
    if (this->m_length == this->m_size)
    {
        cout<<std::format("error the list is full")<<endl;
        return -1;
    }
    for (size_t i = this->m_length-1; i >= pos - 1; i--)
    {
        this->m_data[i+1] = this->m_data[i];
    }
    this->m_data[pos-1] = value;
    this->m_length++;
    cout<<std::format("insert {} success", value)<<endl;
    return 0;
} 


template <typename T>
int SeqList<T>::remove(T value)
{
    for (size_t i = 0; i < this->m_length; i++)
    {
        if (this->m_data[i] == value)
        {
            for (size_t j = i; j < this->m_length-1; j++)
            {
                this->m_data[j] = this->m_data[j+1];
            }
            this->m_length--;
            cout<<std::format("remove {} success", value)<<endl;
            return 0;
        }
    }
    cout<<std::format("error the list is not exist {}", value)<<endl;
    return 0;
}


template <typename T>
void SeqList<T>::print()
{
    if (this->m_length == 0)
    {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "List elements: ";
    for (size_t i = 0; i < this->m_length; i++)
    {
        cout << this->m_data[i] << " ";
    }
    cout << endl;
}
