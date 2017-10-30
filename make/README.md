Make command
---

Requires a `Makefile` to run

Consists of rules in the following manner:

```
Rule : [File Dependencies]
    Action to perform
```

Usually final program output will be at the top

If you type `make` without specifying a target, it will run the first directive

Variables are defined as `VARNAME = VALUE` and is accessed via `$(VARNAME)`

The `Makefile` uses the envrionment variables for building the program i.e. `export CFLAGS`, `CFLAGS` will be available to the `Makefile`

Wild cards can be used in the make directive `%.c` is equivalent to `*.c`

`make` has some implicit rules that automatically include `CFLAGS`

Implicit rule:

```
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
```

To trigger a make commands from another directory, call the command `make -C [Directory] [Command]` for example `make -C util clean`
