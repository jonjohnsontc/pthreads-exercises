#include "../errors.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

/*
  Declare a structure, with a mutex, statically initialized. This
  is the same as using pthread_mutex_init, with the default
  attributes
*/
typedef struct mystruct_tag {
  pthread_mutex_t mutex; // protects access to value
  int value;             // access protected by mutex
} my_struct_t;

// global variables inherently have static storage duration
my_struct_t data = {PTHREAD_MUTEX_INITIALIZER, 0};

int main(int argc, char *argv[]) { return 0; }