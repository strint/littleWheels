## Forward Declaration 前置声明

* 能够解决循环引用的问题
* 将#incude的头文件中的部分声明直接写过来，可以减少预处理器引用过来的头文件的数量，加快编译速度

## Why forward-declare is necessary in C++

The compiler wants to ensure you haven't made spelling mistakes or passed the wrong number of arguments to the function. So, it insists that it first sees a declaration of 'add' (or any other types, classes or functions) before it is used.

This really just allows the compiler to do a better job of validating the code, and allows it to tidy up loose ends so it can produce a neat looking object file. If you didn't have to forward declare things, the compiler would produce an object file that would have to contain information about all the possible guesses as to what the function 'add' might be. And the linker would have to contain very clever logic to try and work out which 'add' you actually intended to call, when the 'add' function may live in a different object file the linker is joining with the one that uses add to produce a dll or exe. It's possible that the linker may get the wrong add. Say you wanted to use int add(int a, float b), but accidentally forgot to write it, but the linker found an already existing int add(int a, int b) and thought that was the right one and used that instead. Your code would compile, but wouldn't be doing what you expected.

So, just to keep things explicit and avoid the guessing etc, the compiler insists you declare everything before it is used.

Difference between declaration and definition

As an aside, it's important to know the difference between a declaration and a definition. A declaration just gives enough code to show what something looks like, so for a function, this is the return type, calling convention, method name, arguments and their types. But the code for the method isn't required. For a definition, you need the declaration and then also the code for the function too.

How forward-declarations can significantly reduce build times

You can get the declaration of a function into your current .cpp or .h file by #includ'ing the header that already contains a declaration of the function. However, this can slow down your compile, especially if you #include a header into a .h instead of .cpp of your program, as everything that #includes the .h you're writing would end up #include'ing all the headers you wrote #includes for too. Suddenly, the compiler has #included pages and pages of code that it needs to compile even when you only wanted to use one or two functions. To avoid this, you can use a forward-declaration and just type the declaration of the function yourself at the top of the file. If you're only using a few functions, this can really make your compiles quicker compared to always #including the header. For really large projects, the difference could be an hour or more of compile time bought down to a few minutes.

Break cyclic references where two definitions both use each other

Additionally, forward-declarations can help you break cycles. This is where two functions both try to use each other. When this happens (and it is a perfectly valid thing to do), you may #include one header file, but that header file tries to #include the header file you're currently writing.... which then #includes the other header, which #includes the one you're writing. You're stuck in a chicken and egg situation with each header file trying to re #include the other. To solve this, you can forward-declare the parts you need in one of the files and leave the #include out of that file.

Eg:

File Car.h
```
#include "Wheel.h"  // Include Wheel's definition so it can be used in Car.
#include <vector>

class Car
{
    std::vector<Wheel> wheels;
};

File Wheel.h
```
//Hmm... the declaration of Car is required here as Wheel has a pointer to a Car, but Car.h can't be included here as it would result in a compiler error. If Car.h was included, that would then try to include Wheel.h which would include Car.h which would include Wheel.h and this would go on forever, so instead the compiler raises an error. The solution is to forward declare Car instead:

class Car;     // forward declaration

class Wheel
{
    Car* car;
};
```
If class Wheel had methods which need to call methods of car, those methods could be defined in Wheel.cpp and Wheel.cpp is now able to include Car.h without causing a cycle.

Reference: http://stackoverflow.com/questions/4757565/c-forward-declaration
