Debugging
---

compiling with the `-g` option to enable debugging

`gcc -g -o main main.c`

`s` to step

`c` to continue

`b [line number]` to add break point

`d [break number]` to remove break point

`info b` to see break point information

Check your `ulimits` for `core file size`. You can change it via the command `ulimit -c unlimited`. This will produce a `core` file, which you can attach your debugger on to see the reason for the crash `gdb main core`

Valgrind!
