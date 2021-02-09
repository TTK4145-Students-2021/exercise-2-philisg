Exercise 2 - Theory questions
-----------------------------

### What is an atomic operation?
> An atomic action operation is when a processor reads and writes during the same data transmission. 

### What is a critical section?
> A critical section is the part of the progrom which tries to access a shared resource. If multiple threads are in the same critical
> section at the same time, data may be corrupted.

### What is the difference between race conditions and data races?
> Data race happens when two or more threads access a shared variable at the same time, and at least one thread tries to modify it.
> In data race the threads race against eachother to modify the data.
> Race conditions is a condition where two or more threads access the same shared data and its behavior depends on relative timing
> and interleaving of multiple threads or processes. 
> A data race can occur inside a race condition but not the other way around.

### What are the differences between semaphores, binary semaphores, and mutexes?
> Mutex is a mutual excusion technique which locks a resource when it needs to use it. If more than one thread wishes to use
> the resource they have to wait until its unlocked. It can be looked at like a gate keeper.
> A semaphore is a variable that is used for controlling access to a resource. it has no mutual exclusion. semaphore (counting semaphore)
> uses a count that helps task to be acquired and released numerous times. 
> A binary semaphore is like a counting semaphore but is its values i restricted to 0 and 1. It also has mutual exclusion.

### What are the differences between channels (in Communicating Sequential Processes, or as used by Go, Rust), mailboxes (in the Actor model, or as used by Erlang, D, Akka), and queues (as used by Python)? 
> *Your answer here*

### List some advantages of using message passing over lock-based synchronization primitives.
> *Your answer here*

### List some advantages of using lock-based synchronization primitives over message passing.
> *Your answer here*