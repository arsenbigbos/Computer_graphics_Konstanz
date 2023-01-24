#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void example_container() {
    // C++ arrays are fixed, coninuous memory:
    int array[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; ++i) {
        cout << "i = " << i << " -> " << array[i] << endl;
    }

    // what happens with i <= 5?

    cout << "wtf: " << 0 [array] << endl;

    // There is no way to determine the length of an array from the array itself, since it is only
    // n * sizeof(T) bytes in memory, one after the other.

    std::vector<int> my_vector = { 100, 101, 102, 103 };
    cout << "size: " << my_vector.size() << endl;

    // Vector access via index:
    for (int i = 0; i < my_vector.size(); ++i) {
        cout << my_vector.at(i) << endl;
    }

    // Range based for (new in C++14)
    for (int i : my_vector) {
        cout << i << endl;
    }

    // Iterators
    for (std::vector<int>::iterator i = my_vector.begin(); i != my_vector.end(); ++i) {
        cout << *i << endl;
    }

    /*
    An iterator is a templated object (template = exchangeable type) which "points" to an 
    element in the container. It can be dereferenced analogously to a pointer and you can do
    some arithmetic on it (depending on the type of iterator). It functions similar to a 
    pointer but it is NOT a pointer.

    E.g. vectors have bidirectional iterators, linked lists only forward iterators.
    */
}
