#include "list.h"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

int main() {
    engr101::list<int> l {1, 3, 5, 7, 9};
    cout << "Doubly linked list before reverse" << endl;
    std::for_each(l.begin(), l.end(), [](int i) { cout << i << endl; });

    l.reverse();
    cout << "Doubly linked list after reverse" << endl;
    std::for_each(l.begin(), l.end(), [](int i) { cout << i << endl; });

    engr101::forward_list<int> fl {0, 2, 4, 6, 8};
    cout << "Singly linked list before reverse: " << endl;
    std::for_each(fl.begin(), fl.end(), [](int i) { cout << i << endl; });

    fl.reverse();
    cout << "Singly linked list after reverse: " << endl;
    std::for_each(fl.begin(), fl.end(), [](int i) { cout << i << endl; });

    // Test that empty and single elements work
    engr101::list<int> l2;
    l2.reverse();
    cout << "Empty doubly linked list after reverse" << endl;
    std::for_each(l2.begin(), l2.end(), [](int i) { cout << i << endl; });
    l2.push_back(1);
    l2.reverse();
    cout << "Single item doubly linked list after reverse" << endl;
    std::for_each(l2.begin(), l2.end(), [](int i) { cout << i << endl; });
    
    engr101::forward_list<int> fl2;
    fl2.reverse();
    cout << "Empty singly linked list after reverse" << endl;
    std::for_each(fl2.begin(), fl2.end(), [](int i) { cout << i << endl; });
    fl2.push_back(1);
    fl2.reverse();
    cout << "Single item singly linked list after reverse" << endl;
    std::for_each(fl2.begin(), fl2.end(), [](int i) { cout << i << endl; });

    return 0;
}