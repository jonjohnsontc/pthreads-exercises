#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  pthread_t thread;
  int status;

  /*
    Attempt to join with an uninitialized thread ID. On most
    implementations, this will return an ESRCH error code. If
    the local (and unitialized) pthread_t happens to be a valid
    thread ID, it is almost certainly that of the initial thread,
    which is running main(). In that case, your Pthreads
    implementation may either return EDEADLK (self-deadlock),
    or it may hang. If it hangs, quit and try again.
  */
  status = pthread_join(thread, NULL);
  if (status != 0)
    fprintf(stderr, "error %d: %s\n", status, strerror(status));
  return status;
}