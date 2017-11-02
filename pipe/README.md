Pipes and IO
---

A FIFO is a tunnel

`mkfifo [filename]` to create a fifo file

`pipe(fd)` where `fd` is an array of size two will create a pipe with the file descriptor of thepipe reader in `fd[0]` and the file descriptor of the writer in `fd[1]`
