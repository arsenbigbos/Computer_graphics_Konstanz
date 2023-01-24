/*
 * C++ uses block comments.
 *
 * Like this one.

   This also works

 */

// one line comments exist too.

/* 
C++ code is split into header and source files (.hpp and .cpp)
#include is a preprocessor directive to *literally* copy a header
at the indicated location. Only do this for headers, never for source 
files. By convention we use <> for system libraries and "" for our 
own headers. 
*/

#include <iostream>

/*
General rule:
Header -> only contains declarations
Sources -> contain actual definition/implementation

Note: C++ distinguishes "Declaration" and "Definition"
Declaration: Makes a name known without giving anything concrete. You can refer
to declared things, but must define them before using.
Definition: Actual assignment of a variable or function with code.

Header with declaration == "I promise to hand in my definition later"

(More on this later.)
*/

#include "compile_and_link.h"
#include "container.h"
#include "memory.h"
#include "passing.h"
#include "polygon.h"

/*
Lots of C++ features exist in the "std" namespace. Namespaces are scopes which
are provided by libraries or which you can define yourself. Standard output
(analog to javas System.out.println or pythons print()) is called "cout". Since it
is a member of the std namespace its full name is "std::cout". If you do not provide
the namespace it will not be found: "cout" and "std::cout" are two different names
for C++!

Benefit: You can define your own colloding names and then just pick a namespace.

In order to avoid typing, we can clarify which elements of a namespace we are using:
*/
using std::cout;
using std::endl;

// Bad: using namespace std;  This is basically import * and will cause conflicts.

// Finally running code! C++ programs always start running in main():
int main() {
    // Text output is done using streams
    cout << "Hello world!" << endl;

    // C++ is a typed language and all types must be given explicitly (mostly).
    int a = 0;
    int b = 1;

    for (int i = 0; i < 50; ++i) {
        int result = a + b;
        a = b;
        b = result;

        if (i != 0 && i % 10 == 0) {
            cout << result << endl;
        } else {
            cout << result << ", ";
        }
    }
    cout << endl;

    // for, while, if etc. are all analogous to Java/Python since they all are derivedfrom
    // C, which is derived from B which is derived from BCPL which is derived from Algol 58
    // which is derived from FORTRAN (1954)

    /*
    This example computes fibonacci numbers but we see there is an integer overflow. This 
    triggers no runtime error or exception. C++ is very close to the hardware and this is 
    mostly a thin veneer over direct byte manipulation. For example this works:
    */

    int c = 'A';
    cout << "A in an int:" << c << endl;

    // Great way to shoot yourself in the foot. Also we access memory in creative ways:

    // int* pointer;
    // pointer = 0;
    // *pointer = 0xDEADBEEF;
    // Segmentation fault: The operating system just killed our code for accessing places
    // we shouldn't! You can cause undefined behaviour, which is the cost of having a 
    // mighty language. You need to be aware of much more details compared to many other
    // languages, since there are way fewer safety nets.

    const int nextExample = 4;

    switch(nextExample) {
        case 0:
            function_calling();
            break; // remove this? -> Fall through!
        case 1:
            example_memory();
            break;
        case 2:
            example_passing();
            break;
        case 3:
            example_container();
            break;

        default: {
            Polygon p;
            p.addPoint(vec2(0, 0));
            p.addPoint(vec2(2, 0));
            p.addPoint(vec2(2, 3));
            p.addPoint(vec2(0, 3));
            cout << p.getArea() << endl;
        }
    }

    /* Hints and ressources:
    
    General documentation: https://en.cppreference.com/w/

    Beware of old tutorials full of old style code and undefined behaviour

    "Effective C++"
    "More Effective C++"
    "Effective Modern C++" -> Series by Scott Meyers on how to use C++ properly

    ---

    1) Keep it simple: If you don't understand your program anymore you are screwed. 
        - You don't need 3 levels of pointers or random inline lambda functions
        - Never sacrifice understandability for brevity
        - Your program should be so simple that there are obviously no bugs, never so complex that there 
          are no obvious bugs.
        - If we don't understand your program you get no points. Use comments :)
    2) Use your debugger. Without it you have speculation. With it you have certain measurements.
    3) Make use of data types! They tell 80% of the story of what is going on in a program:

        float foo(int a, int b);  -> this might perform division?

        vec3i center_pos(3DMesh*)
        void point_camera_at(vec3f)  -> looks like these functions could fit together

       Using "auto" everywhere robs you of this understanding. Avoid it, except to cut down on redundancy.
    4) It is never a compiler bug.
    5) "Undefined reference to": Check CMakeLists.txt, includes, and their order.
    */


    return 0;
}
