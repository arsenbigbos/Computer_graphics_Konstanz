Author: Mārtiņš Dāvis Jembergs

#### What is a pointer? (1 point)

A pointer is a variable that instead of storing an actual value, it stores the address of the variable.

```
string pet = "cat";
string* ptr = &pet;
```

The variable ptr (pointer) stores the address of the variable pet.

#### What is the difference between a variable on the stack and a variable on the heap? (1 point)

On the call of a function, a block is reserved on top of the stack where local variables will be stored. Once that function returns, the block becomes unused and is free for the next function call. Stacks work with the principle of LIFO (last in first out).

A heap is used for dynamic allocation. A block can be allocated at any time and freed at any time. Compared to stacks, it is much harder to keep track of which parts of a heap are free and which aren't.

#### Name at least three differences between a pointer and a reference (2 points).

A pointer can be declared and initialised in the same line or in multiple lines, while a reference can only be declared and initialised in the same line.

```
//POINTER
int num = 10;
int *ptr = &num;
//or
int *p;
p = &num;

//REFERENCE
int a = 10;
int &p = a;
```

- Reassignment

A pointer can be reassigned (useful for implementation of data structures) while a reference can only be assigned at initialisation.

- Memory Address

A pointer has its own memory address (and block on the stack) whereas a reference shares the address of the variable (though it takes up its own space on the stack as well)

- NULL value

A pointer can be assigned to NULL directly, while a reference can't. Due to the constraints of references (no reassignment and no NULL) underlying operations don't run into an exception situation.

#### The following statement shows three different versions for declaring a function in C++. How do they differ? What is the difference between call-by-value and call-by-reference? Name one application scenario for each of these two approaches (2 points).

#### Function declaration:

- `void functionA ( int param1 , int param2 );`

- `void functionB ( int &param1 , int &param2 );`

- `void functionC ( int ∗param1 , int ∗param2 );`

<br/>

- call-by-value

Values of parameters are copied to a function’s parameters and the two types of parameters are stored in different memory locations. Any changes made inside functions are not reflected in actual parameters of the caller.

An example of this would be a function where you explicitly do not wish to change any of the variables but instead perform some sort of action with them inside of the function instead, like performing different mathematical operations and saving the result in a different variable.

- call-by-reference

Both the actual and formal parameters refer to the same locations, so any changes made inside the function are actually reflected in actual parameters of the caller.

A good example for this would be a number swapping function as the changes in the function immidiately would reflect on the parameters.
