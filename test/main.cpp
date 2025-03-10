#include <iostream>
#include <string>
#include <format>
#include "SeqList.h"
#include "LinkedList.h"
int main() {
    LinkedList<int> list;
    list.insert(10);  // 插入 10
    list.insert(20);  // 插入 20
    list.insert(30);  // 插入 30
    list.insert(2,666);
    list.print();     // 输出
    list.remove(20);  // 删除 20
    list.print();     // 输出
    return 0;
}
