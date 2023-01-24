#include <iostream>

using std::cout;
using std::endl;

int pass_by_value(int other_int) {
    cout << "Got by value: " << other_int << endl;
    other_int += 1;
    cout << "Returning: " << other_int << endl;
    return other_int;
}

int pass_by_reference(int& other_int) {
    cout << "Got by reference: " << other_int << endl;
    other_int += 1;
    cout << "Returning: " << other_int << endl;
    return other_int;
}

int pass_a_pointer(int* other_int) {
    cout << "Got a pointer to " << other_int << " with value " << *other_int
         << endl;
    *other_int += 1; // Was wenn hier keine Dereferenzierung geschieht?
    cout << "Returning: " << *other_int << endl;
    return *other_int;
}

int multi_return(int modifier, int& a, int& b) {
    a += modifier;
    b += modifier;
    return 0;
}

int* bad_return_of_local_pointer() {
    int int_on_stack = 40;
    // return &int_on_stack;
    return nullptr;
}

void example_passing() {
    int my_int = 9000;

    cout << "My int before: " << my_int << endl;
    pass_by_value(my_int);
    cout << "My int after: " << my_int << endl << endl;

    cout << "My int before: " << my_int << endl;
    pass_by_reference(my_int);
    cout << "My int after: " << my_int << endl << endl;

    cout << "My int before: " << my_int << endl;
    pass_a_pointer(&my_int);
    cout << "My int after: " << my_int << endl << endl;

    int x = 0;
    int y = 2;
    multi_return(2, x, y);
    cout << "x = " << x << ", y = " << y << endl;

    int* bad_pointer = bad_return_of_local_pointer();
    // cout << "Bad address: " << bad_pointer << endl;
    // cout << "Bad value: " << *bad_pointer << endl;

    // Ways to access memory in C++
    // 1) Via a variable 
    // 2) Through a reference which is an alias for a variable
    // 3) A pointer
    //
    // Your responsibility: Ensure the memory you read is valid
}
