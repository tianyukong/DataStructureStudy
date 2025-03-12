#pragma once

#include <iostream>
#include <format>
using std::cout;
using std::endl;

template <typename T>
class TreeList
{
private:
    /* data */
    struct TreeNode
    {
        T m_m_data;
        TreeNode *lchild;
        TreeNode *rchild;
        TreeNode(T data):m_m_data(data),lchild(nullptr),rchild(nullptr){
            printf("data:%c\n",data);
        }
    };
    TreeNode *m_tree=nullptr;   
    int m_pos=0;
    void* m_data;
public:
    TreeList(/* args */);
    TreeList(void* value,int length);
    ~TreeList();
    int insert(T value);                
    int remove(T value);
    void print(int type);

private:
    void print_qian(TreeNode *node);
    void print_zhong(TreeNode *node);
    void print_hou(TreeNode *node);
    void create_tree(TreeNode **node);
    void delete_tree(TreeNode *node);
};

template <typename T>
TreeList<T>::TreeList(/* args */)
{
    m_tree = new TreeNode(0);
}

template <typename T>
TreeList<T>::TreeList(void* value,int len)
{
    m_data = value;
    m_pos = 0;

    create_tree(&m_tree);
}

template <typename T>
void TreeList<T>::create_tree(TreeNode **node)
{
    T data=((T *) m_data)[m_pos++];
    if(data == '#')
    {
        node = nullptr;
    }
    else
    {
        *node = new TreeNode(data);     
        create_tree(&(*node)->lchild);
        create_tree(&(*node)->rchild);
    }
}




template <typename T>
TreeList<T>::~TreeList(/* args */)
{
    delete_tree(m_tree);
}



template <typename T>
void TreeList<T>::print(int type)
{
    if(type == 1)
    {
        print_qian(m_tree);
    }
    else if(type == 2)
    {
        print_zhong(m_tree);
    }
    else if(type == 3)
    {
        print_hou(m_tree);
    }
}

template <typename T>
void TreeList<T>::print_qian(TreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }
    cout<<node->m_m_data<<" ";
    print_qian(node->lchild);
    print_qian(node->rchild);
}


template <typename T>
void TreeList<T>::print_zhong(TreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }
    print_zhong(node->lchild);
    cout<<node->m_m_data<<" ";
    print_zhong(node->rchild);
}

template <typename T>
void TreeList<T>::print_hou(TreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }

    print_hou(node->lchild);
    print_hou(node->rchild);
    cout<<node->m_m_data<<" ";
}

template <typename T>
void TreeList<T>::delete_tree(TreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }

    delete_tree(node->lchild);
    delete_tree(node->rchild);
    delete node;
}
