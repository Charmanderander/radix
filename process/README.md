Process
---

When you declare a variable like this `struct rusage rsg`, you are allocating memory on the stack

When you declare a variable and malloc it `struct rusage rsg = malloc(sizeof rsg)`, you are allocating memory from the heap

If you declare a variable as such `struct rusage *rsg`, you are only creating a pointer, but not allocating any memory

