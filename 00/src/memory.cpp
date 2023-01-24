#include <iostream>
#include <memory>
#include <random>
using std::cout;
using std::endl;

void example_memory() {
    // C++ allows direct memory access:
    int my_int = 20;
    cout << "Variable my_int = " << my_int << " is located at " << &my_int
         << endl;

    /*
    There are two memory types in C++: STACK and HEAP. Anything we declare like my_int
    gets allocated on the stack. Allocation of an int: 4 bytes are reserved for it.
    The stack is deallocated after the associated scope is left. Deallocation is not
    deletion! Memory still contains the old content and can be used but that is 
    undefined behaviour (more in next section).

    The heap is a user managed memory block where we do allocation and deallocation
    */ 
    int* my_heap_int = new int;
    *my_heap_int = 20;
    cout << "Variable my_heap_int = " << *my_heap_int << " is located at "
         << my_heap_int << endl;

    /*
    Why are we not using "&" here? The operator & returns the memory address of a variable
    i.e. &my_int gives us a number corresponding to the variables address on the stack. 
    "new int" just gave us a number which is the address of the memory it allocated on the heap
    which we store in my_heap_int. The type of my_heap_int is "pointer_to_int", not "int".

    The operator "*" takes some variable and uses its content as a memory address to read from.
    &variable -> address
    *address -> variable content

    Using "*" is called "dereferencing" a pointer
    */

    // RULE: A pointer is just an int which is interpreted as a memory address.
    cout << "What my_heap_int contains: " << my_heap_int << endl;
    cout << "What my_heap_int points to: " << *my_heap_int << endl;
    cout << "Where my_heap_int is located: " << &my_heap_int << endl << endl;

    // We can point to any other variable too
    int* pointer = &my_int;
    cout << "What pointer contains: " << pointer << endl;
    cout << "What points to: " << *pointer << endl;
    cout << "Where my_int is located: " << &my_int << endl;
    cout << "Where pointer is located: " << &pointer << endl;

    // Pointer arithmetic is possible and often useful:
    cout << "What lies beyond pointer: " << *(pointer + 1) << endl;

    // deallocation:
    cout << "my_heap_int before deletion:" << *my_heap_int << endl;
    delete my_heap_int;
    cout << "Deleted my_heap_int:" << *my_heap_int << endl;
    my_heap_int = nullptr;  // defusing the gun

    // Russian roulette
    /*
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1000, 10000);
    int* random_sample = nullptr;
    random_sample = (int*) uniform_dist(e1);
    cout << "I'm feeling lucky: " << *random_sample << endl;
    */

    // Since you can easily rebuild the random access by accident (read invalid memory and dereference it)
    // we prefer "smart pointers": These are objects which manage memory for us but can be used like raw 
    // pointers. Unless you have a very good reason not to, stick with these:
    auto my_smart_pointer = std::make_shared<int>(100);
    cout << "Smart pointer content: " << my_smart_pointer << endl;
    cout << "Smart pointer" << my_smart_pointer << endl;
    // cout << "Smart pointer content: " << *(my_smart_pointer + 1) << endl;

    // C++ wierdness: & is an operator to get the address of something AND used 
    // to define a reference to something. Note the difference between a pointer 
    // and a reference:

    int my_stack_int = 2;
    int* my_pointer_to_int = &my_stack_int;
    int& my_reference_to_int = my_stack_int;

    // my_pointer_to_int is a pointer which can change what it points to and allows access to my_stack_int
    // my_reference_to_int is an ALIAS for my_stack_int. It is no separate instance in memory and it can never 
    // refer to anything else
    // RULE: Pointers ARE NOT references, although they share the functionality to access other things.

    // What about * being the deREFERENCE operator?! ... This is an unfortunate naming collision :)

    return;
}
