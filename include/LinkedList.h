#pragma once

#include <iostream>
#include <format>
using std::cout;
using std::endl;

template <typename T>
class LinkedList
{
private:
    /* data */
    struct Node
    {
        T m_data;
        Node *m_next;
        Node(T data):m_data(data),m_next(nullptr){}
    };
    Node *m_head;
    int m_length;    

public:
    LinkedList(/* args */);
    ~LinkedList();
    int insert_head(T value);                // 在链表尾部插入
    int insert(T value);                // 在链表尾部插入
    int insert(int pos, T value);       // 在指定位置插入
    int remove(T value);                // 删除指定值的节点
    void print();                       // 打印链表
};



template <typename T>
LinkedList<T>::LinkedList(/* args */):m_head(nullptr),m_length(0)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node *cur = m_head;
    while (cur->m_next != nullptr)
    {
        Node *next = cur->m_next;
        delete cur;
        cur = next;
    }
    delete cur;
    m_head = nullptr;
}


//头插法
template <typename T>
int LinkedList<T>::insert_head(T value){
    Node *node = new Node(value);
    node->m_next = m_head;
    m_head = node;
    m_length++;
    cout << std::format("insert {} success", value) << endl;
    return 0;
}


template <typename T>
int LinkedList<T>::insert(T value){
    Node *node = new Node(value);
    if(m_head == nullptr){
        m_head = node;
    }
    else{
        Node *cur = m_head;
        while(cur->m_next != nullptr)
        {
            cur =cur->m_next;
        }
        cur->m_next = node;
    }
    m_length++;
    cout << std::format("insert {} success", value) << endl;
    return 0;
}

template <typename T>
int LinkedList<T>::insert(int pos, T value) {
    if(pos < 0 || pos > m_length){
        cout << std::format("insert {} failed, pos {} out of range", value, pos) << endl;
        return -1;
    }
    if(pos == 0){
        return insert_head(value);
    }
    Node *node = new Node(value);
    Node *cur = m_head;
    for(int i = 0; i < pos - 2; i++){
        cur = cur->m_next;
    }
    node->m_next = cur->m_next;
    cur->m_next = node;
    m_length++;
    cout << std::format("insert {} success", value) << endl;
    return 0;
}


template <typename T>
int LinkedList<T>::remove(T value) {
    Node* cur = m_head;
    Node* pre = nullptr;
    while (cur != nullptr) {
        if (cur->m_data == value) {
            if (pre == nullptr) {
                m_head = cur->m_next;
            } else {
                pre->m_next = cur->m_next;
            }
            delete cur;
            m_length--;
            cout << std::format("remove {} success", value) << endl;
            return 0;
        }
        pre = cur;
        cur = cur->m_next;
    }
    cout << std::format("error the list does not contain {}", value) << endl;
    return -1;
}


template <typename T>
void LinkedList<T>::print() {
    if (m_length == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "List elements: ";
    Node* cur = m_head;
    while (cur != nullptr) {
        cout << cur->m_data << " ";
        cur = cur->m_next;
    }
    cout << endl;
}