#include <iostream>
#include "LinkedList.hpp"

int main() {
    LinkedList<int> list;
    list.append(10);
    list.append(2);
    list.append(456789);

    std::cout << "list: " << list;
    list.clear();
    std::cout << "cleared list: " << list;

    list.append(5);
    list.append(7);
    std::cout << "new list: " << list;

    list.replace(0, 6);
    std::cout << "replaced list: " << list;



    



    return 0;
}
