#include <iostream>
#include <string>
#include <format>
#include "SeqList.h"
#include "LinkedList.h"
#include "TreeList.h"
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    string data="ABDH#K###E##CFI###G#J##";
    TreeList<char> tree((char *)data.c_str(),data.size());
    tree.print(1);
    printf("\n");
}
