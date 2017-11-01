Process
---

When you declare a variable like this `struct rusage rsg`, you are allocating memory on the stack

When you declare a variable and malloc it `struct rusage rsg = malloc(sizeof rsg)`, you are allocating memory from the heap

If you declare a variable as such `struct rusage *rsg`, you are only creating a pointer, but not allocating any memory

forking duplicates the process with a different PID. The stack is copied over to the child. Initially all variables are memory mapped to the same physical location, until a variable is changed

When you call `exec`, your process is replaced by another program

The bash shell implicitly calls `fork()` when you run programs

Running `system` calls `\bin\sh`, and passes the commands to it. This shell calls another fork to run the command. Two forks are called in this manner. This method is used to handle special characters, which `exec` cannot handle

When a child calls `setsid()`, it becomes the session leader. When the terminal is closed, no kill signal is sent to it
