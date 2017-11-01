File access
---

If take away `x` for a directory, cannot access the folder and execute things inside

If take away `r` for the directory, cannot read the folder and things inside

To change the `umask`, run `umask 077`. This give the permission `000 111 111`, which denies rwx for group and everyone else

Reverse of `umask` is `chmod`

C library has a buffer to store messages. To remove this buffer, run `fflush(stdout)`

functions that return a pointer, but you did not give them a buffer to store the data, it is not thread safe.

The address the pointer points to is store in the `data` section of the process. When another thread calls, it overwrite the data (threads all share the same memory in a process)

Different processes however, are safe, because they have a separate memory space
