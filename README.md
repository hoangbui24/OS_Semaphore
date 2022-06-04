# Semaphore and Mutex

This is a simple program to show the importance of process's synchronization & thread's synchronization

## Section 5.4:

1. Given two process that are executed in parallel as follows:

| PROCESS A                                                | PROCESS B                                                            |
| ---------------------------------------------------------| -------------------------------------------------------------------- |
| processA<br>{<br>&emsp;while(true)<br>&emsp;&emsp;sells++<br>} | processB<br>{<br>&emsp;while(true)<br>&emsp;&emsp;products++<br>} |
