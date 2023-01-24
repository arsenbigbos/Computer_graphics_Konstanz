#include <iostream>
#include "compile_and_link.h"

using std::cout;
using std::endl;

void forward_defined_function();

namespace mystuff {
    namespace nested {
        void my_function() {
            cout << "Namespaced function" << endl;
        }
    }
}

void my_function() {
    cout << "Global function" << endl;
}

void function_calling() {
    cout << "In a called function!" << endl;

    /*
    How did we get here?
    1) In CMakeLists.txt we enumerate all files involved in the project
    2) The compiler gets a list of all files
    3) The preprocessor resolves all #includes by copying them at the corresponding place
       NOTE: This is done blindly, you must prevent redefinitions yourself!
    4) The compiler translates all source files into executable machine code.
    5) The linker finds all places where one thing references another and links up those
       connections. 
    */
    
    // no_declaration(); // Compiler error: At this point this name was never seen before

    // no_definition(); // Linker error: Saw this in the header so the compiler sees no isse

    /*
    General rule: "Undefined reference to X" means you forgot to provide a definition for 
    something you declared. Causes are usually:
    1) Source file not added to CMakeLists.txt
    2) Source file added in the wrong ORDER in CMakeLists.txt
    3) Typo in declaration/definition
    4) Included header for a library but library not found by linker
    */ 

   forward_defined_function();

   my_function();
   ::my_function();
   mystuff::nested::my_function();
}

void no_declaration() {
    cout << "I am declared but not defined!" << endl;
}

void forward_defined_function() {
    cout << "I am forward defined!" << endl;
}