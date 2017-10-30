Make command
---

Consists of rules in the following manner:

```
Rule : [File Dependencies]
    Action to perform
```

Usually final program output will be at the top

If you type `make` without specifying a target, it will run the first directive

Variables are defined as `VARNAME = VALUE` and is accessed via `$(VARNAME)`
