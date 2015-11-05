// These #includes tell the compiler to include the named
// header files, similar to imports in Java. The code for
// these is generally located under /usr/include/, such
// as /usr/include/assert.h. assert.h contains the
// declaration of the assert() function, stdio.h contains
// the declaration of the printf() function, and stdlib.h
// contains the declaration of the malloc() and free()
// functions, all of which are used in the code below.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Fill the given array with values. Note that C doesn't
// keep track of the length of arrays, so we have to
// specify it explictly here.
void fillArray(int* array, int len) {
  printf("Filling an array at address %p with %d "
         "values\n", array, len);
  for (int i = 0; i < len; ++i) {
    array[i] = i * 3 + 2;
    // assert() verifies that the given condition is true
    // and exits the program otherwise. This is just a
    // "sanity check" to make sure that the line of code
    // above is doing what we intend.
    assert(array[i] == i * 3 + 2);
  }
  printf("Done!\n");
}

// Structs are simply storage for memory of various types.
// In this case, we are typedef-ing (as in naming) a
// struct containing four integers as FourInts.
typedef struct {
  int a, b, c, d;
} FourInts;

// main() is the entry point of the program.
int main(int argc, char* argv[]) {
  // Create a new array capable of storing 10 elements
  // and fill it with values using the function declared
  // above. Arrays declared in this manner are located on
  // the stack, which is where statically allocated (as
  // in not at runtime) memory is stored.
  int array[10];
  // The "array" that we pass here is actually a pointer
  // to a block of memory capable of storing 10 integers.
  // array[0] is the first integer in this block of
  // memory, array[1] is the second, and so on. Since
  // C does not track array lengths, we have to specify
  // how many elements the array contains.
  //
  // TODO(1): What happens if the second argument is set
  // to 11 instead? How about 100? 1000? Make sure to set
  // the second argument back to 10 when you are done
  // testing.
  // Answer: 11, nothing wrong; 100, Segmentation fault (core dumped)
  // 1000, Segmentation fault (core dumped)
  fillArray(array, 10);

  int value;
  // In C, we can take the address of something using the
  // & operator. &value is of the type int*, meaning that
  // it is a pointer to an integer (as in it stores the
  // address in memory of where the actual int is located).
  //
  // TODO(2): qe can actually use the address of the value
  // declared here as if it were an array of a single
  // element; why is this possible?
  // Answer: Because an int can be treated as an int array whose length is 1;
  fillArray(&value, 1);
  // fillArray should set value to 0 * 3 + 2 = 2.
  assert(value == 2);

  // The following creates an instance of FourInts on the
  // stack. FourInts is really just an array of four ints,
  // although we can refer to the ints stored in it by
  // name as well.
  FourInts four_ints;
  // Set the first int to have a value of 0 and verify
  // that the value changed.
  four_ints.a = 0;
  assert(four_ints.a == 0);

  // Depending on whether or not you like to live
  // dangerously, the following is either exciting or
  // terrifying. Though &four_ints is of type FourInts*
  // (as in a pointer to a FourInts struct), we can
  // use a cast to pretend that it is actually an array
  // of integers instead.
  fillArray((int*) &four_ints, 4);
  // We can confirm that fillArray updated the values
  // in the FourInts struct:
  assert(four_ints.a == 2);
  assert(four_ints.b == 5);
  assert(four_ints.c == 8);
  assert(four_ints.d == 11);

  // In the case that the size of an array is not known
  // until runtime, the malloc() function can be used to
  // allocate memory dynamically. Memory that is
  // allocated dynamically is stored on the heap, which
  // is separate from the stack. C is unlike Java,
  // however, in that dynamically-allocated memory must
  // be freed explicitly when the program is done using
  // it via the free() function. malloc() takes a single
  // argument, which is the number of bytes to allocate.
  // sizeof(int) gives how many bytes an int contains
  // (which is four), so sizeof(int) * 5 is 20.
  int* heap_array = (int*) malloc(sizeof(int) * 5);
  fillArray(heap_array, 5);
  // Now that we have finished with the heap-allocated
  // array, free() the memory associated with it.
  //
  // TODO(3): What happens if we remove the free()
  // statement below? Try running "valgrind ./arrays"
  // after compiling the program both with and without
  // it. valgrind is a tool for analyzing how programs
  // use memory, which is often invaluable for C and
  // C++ programming.
  // Answer:
  // with free:
  // ==2209== 
  // ==2209== HEAP SUMMARY:
  // ==2209==     in use at exit: 0 bytes in 0 blocks
  // ==2209==   total heap usage: 1 allocs, 1 frees, 20 bytes allocated
  // ==2209== 
  // ==2209== All heap blocks were freed -- no leaks are possible
  // without free:
  //==2249== HEAP SUMMARY:
  //==2249==     in use at exit: 20 bytes in 1 blocks
  //==2249==   total heap usage: 1 allocs, 0 frees, 20 bytes allocated
  //==2249== 
  //==2249== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
  //==2249==    at 0x4C2981C: malloc (vg_replace_malloc.c:270)
  //==2249==    by 0x40077E: main (arrays.c:109)
  //==2249== 
  //==2249== LEAK SUMMARY:
  //==2249==    definitely lost: 20 bytes in 1 blocks
  //==2249==    indirectly lost: 0 bytes in 0 blocks
  //==2249==      possibly lost: 0 bytes in 0 blocks
  //==2249==    still reachable: 0 bytes in 0 blocks
  //==2249==         suppressed: 0 bytes in 0 blocks
  free(heap_array);

  // TODO(4): Now it's your turn to write some code.
  // Using malloc(), allocate a FourInts struct
  // dynamically (on the heap) and use fillArray to
  // populate it with values. Make sure to free the
  // memory when you are done, and use the valgrind
  // tool mentioned above to check that there aren't
  // any errors. As a "sanity check," add four assert
  // statements to verify that the a, b, c, and d
  // fields of the FourInts struct are set to what
  // you would expect. (Hint, you'll need to use the
  // -> operator to access fields of a FourInts*
  // variable instead of the . operator).
  FourInts* heap_struct = (FourInts*) malloc(sizeof(FourInts));

  fillArray((int*) heap_struct, 4);

  assert(heap_struct->a == 2);
  assert(heap_struct->b == 5);
  assert(heap_struct->c == 8);
  assert(heap_struct->d == 11);

  free(heap_struct);
  //Filling an array at address 0x7ff0005d0 with 10 values
  //Done!
  //Filling an array at address 0x7ff0005cc with 1 values
  //Done!
  //Filling an array at address 0x7ff0005b0 with 4 values
  //Done!
  //Filling an array at address 0x4c30040 with 5 values
  //Done!
  //Filling an array at address 0x4c300a0 with 4 values
  //Done!
  //==26250== 
  //==26250== HEAP SUMMARY:
  //==26250==     in use at exit: 0 bytes in 0 blocks
  //==26250==   total heap usage: 2 allocs, 2 frees, 36 bytes allocated

  return 0;
}
