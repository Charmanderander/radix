System Calls
---

`perror` reads `errno` and displays the error string obtained from the `sys_errlist[]` array

PID 0 is the scheduler

PID 1 is the init

Real UID, Saved UID, Effective UID

The one displayed to us is the Effective UID

By running `chmod u+s` as root to a command, you are allowing the command to be ran as a root user, even if you are not

e.g. `chmod u+s /bin/cp` when you are not root and run `cp`, `cp` will be ran as root account

