#include "../errors.h"
#include <pthread.h>

// Start thread routine
void *thread_routine(void *arg) { return arg; }

int main(int argc, char *argv[]) {
  pthread_t thread_id;
  void *thread_result;
  int status;

  // Thread initialized to ready state
  status = pthread_create(&thread_id, NULL, thread_routine, NULL);
  if (status != 0) {
    err_abort(status, "Create thread");
  }
  // If we don't care about the return value of the thread, we can pass NULL as
  // the thread_ret value
  status = pthread_join(thread_id, &thread_result);
  if (status != 0) {
    err_abort(status, "Join thread");
  }
  if (thread_result == NULL)
    return 0;
  else
    return 1;
}