#include <iostream>
#include <string>
#include <format>
#include "SeqList.h"
int main()
{
    SeqList<double> list(10);
    list.insert(1.1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);
    list.insert(9);
    list.insert(10);
    list.insert(11);
    list.print();
    list.remove(5);
    list.print();
    list.remove(11);
    list.print();
    list.remove(1);
    list.print();
    list.remove(10);
    list.print();
    list.remove(10);
    list.print();
    return 0;
}
