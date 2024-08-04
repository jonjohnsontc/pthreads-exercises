# Chapter 3 Notes

- Critical sections are areas of code that affect shared state.
- Critical sections generally need to protect some data invariant, or assumption that must remain about the data being operated on
- Invariants can be broken generally, it's just that they're repaired before another thread can access the data. Synchronization is the voluntary act of protecting your system from broken invariants.
- Predicates are the logical expressions that describe the state of invariants needed by your code
- The most common way to synchronize data between threads is to ensure that all memory access to the same data remains mutually exclusive
- Pthreads provide mutual exclusion through mutexes

A visual of a mutex guarding some data. Whenever a threads line is below the bold `time` line is when it has made a successful lock on the mutex.

![Example mutex operation](./imgs/3-2_mutex_operation.png)
