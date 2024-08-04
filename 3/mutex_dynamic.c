#include "../errors.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

// Define a structure, with a mutex
typedef struct my_struct_tag {
  pthread_mutex_t mutex; // protects access to value
  int value;             // access protected by mutex
} my_struct_t;

int main(int argc, char *argv[]) {
  my_struct_t *data;
  int status;

  data = malloc(sizeof(my_struct_t));
  if (data == NULL)
    errno_abort("Allocate structure");
  status = pthread_mutex_init(&data->mutex, NULL);
  if (status != 0)
    err_abort(status, "Init mutex");
  // dynamically allocated mutexes should be cleaned/destroyed through
  // `pthread_mutex_destroy`
  status = pthread_mutex_destroy(&data->mutex);
  if (status != 0)
    err_abort(status, "Destroy mutex");
  // After the mutex has been destroyed we can free the data
  (void)free(data);
  return status;
}