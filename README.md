# Semaphore and Mutex

This is a simple program to show the importance of process's synchronization & thread's synchronization

## Section 5.4:

1. Given two process that are executed in parallel as follows:

| PROCESS A                                                | PROCESS B                                                               |
| ---------------------------------------------------------| ----------------------------------------------------------------------- |
| processA<br>{<br>&emsp;while(true)<br>&emsp;&emsp;sells++<br>} | processB<br>{<br>&emsp;while(true)<br>&emsp;&emsp;products++<br>} |

   * Process A describes the quantity of goods sold: sells
   * Process B describes the number of products made: products
   *  Know that initially we have no stock and have not sold anything: sells = products = 0 
   *  Because the ability to create goods and the ability to sell are not equal, sometimes selling high will sell quickly, when selling low, selling will slow down. When workers work efficiently, they will create products quickly, whereas when workers are tired, they will make products slower. However, whether selling expensive or not, working fast or slow, one thing must still be guaranteed. “If there are goods, they can be sold”, in other words, we must ensure: products >= sells. 

❓**So the requirement is to use semaphore to synchronize 2 processes: A (sales) and B (create goods) according to the above condition?**
