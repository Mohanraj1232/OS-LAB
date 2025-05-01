#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <sys/types.h>  // for pid_t
#include <unistd.h>     // for fork(), getpid(), getppid()
#include <sys/wait.h>   // for wait()