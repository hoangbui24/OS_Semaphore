# Semaphore and Mutex

This is a simple program to show the importance of process's synchronization & thread's synchronization

## Section 5.4:

### 1. Given two process that are executed in parallel as follows:

| PROCESS A                                                | PROCESS B                                                               |
| ---------------------------------------------------------| ----------------------------------------------------------------------- |
| processA<br>{<br>&emsp;while(true)<br>&emsp;&emsp;sells++<br>} | processB<br>{<br>&emsp;while(true)<br>&emsp;&emsp;products++<br>} |

   * Process A describes the quantity of goods sold: sells
   * Process B describes the number of products made: products
   *  Know that initially we have no stock and have not sold anything: sells = products = 0 
   *  Because the ability to create goods and the ability to sell are not equal, sometimes selling high will sell quickly, when selling low, selling will slow down. When workers work efficiently, they will create products quickly, whereas when workers are tired, they will make products slower. However, whether selling expensive or not, working fast or slow, one thing must still be guaranteed. “If there are goods, they can be sold”, in other words, we must ensure: products >= sells. 

❓**So the requirement is to use semaphore to synchronize 2 processes: A (sales) and B (create goods) according to the above condition?**

<br>------------------------------------------<br>

### 2. Given an array a declared as an array of integers that can contain n elements, a is declared as a global variable. Write a program that includes 2 threads running in parallel:
- A thread is responsible for generating a random integer and then putting it in a. Then count and output the number of elements of a obtained immediately after adding.
- The other thread retrieves an element in a (any element, depends on the programmer). Then count and output the number of elements of a obtained immediately after taking out, if there are no elements in a, output the screen "Nothing in array a"

❓**Run the test and find the error when running the above program when it is not synchronized. Perform synchronization with semaphore.**

<br>------------------------------------------<br>

### 3. Given two process that are executed in parallel as follows:

| PROCESS A                                                | PROCESS B                                                               |
| ---------------------------------------------------------| ----------------------------------------------------------------------- |
| processA<br>{<br>&emsp;while(1)<br>&emsp;&emsp;x++;<br>&emsp;&emsp;if (x == 20)<br>&emsp;&emsp;&emsp;x = 0;<br>&emsp;&emsp;print(x);<br>} | processB<br>{<br>&emsp;while(1)<br>&emsp;&emsp;x++;<br>&emsp;&emsp;if (x == 20)<br>&emsp;&emsp;&emsp;x = 0;<br>&emsp;&emsp;print(x);<br>} |

❓**Implement the model on C in Linux operating system and comment on the results.**

<br>------------------------------------------<br>

### 4. Synchronize with the mutex to correct the unreasonable errors in the results of the Lesson 3 model.

❓**Synchronize with the mutex to correct the unreasonable errors in the results of the Lesson 3 model.**

## Section 5.5:

### 1. The variable ans is calculated from the variables x1, x2, x3, x4, x5, x6 as follows:
&emsp;&emsp;&emsp;&emsp;w = x1 * x2; (a)<br>
&emsp;&emsp;&emsp;&emsp;v = x3 * x4; (b)<br>
&emsp;&emsp;&emsp;&emsp;y = v * x5; (c)<br>
&emsp;&emsp;&emsp;&emsp;z = v * x6; (d)<br>
&emsp;&emsp;&emsp;&emsp;y = w * y; (e)<br>
&emsp;&emsp;&emsp;&emsp;z = w * z; (f)<br>
&emsp;&emsp;&emsp;&emsp;ans = y + z; (g)<br>
