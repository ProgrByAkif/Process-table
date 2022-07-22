# Process-table
In this section, we simulate the starting and stopping of different processes and the parallel execution of multiple processes. Processes are started from the command line and must be maintained in the process table. For simplicity, unlike the process table in Linux, it does not record which user a process belongs to. However, multiple processes must run concurrently, each executing a single statement to cover all processes. To run a process, we assume that the program is already loaded into memory. You must ensure that the program's instructions are executed. You can do this with the execute() function, passing it the address of the statement to execute. After each executed statement, returns the address of the next statement. The length of the show may vary.The following functions must be implemented:

- Create new processes
- print process list
- start process
- Terminate the process
- stop process
