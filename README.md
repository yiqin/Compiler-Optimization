# Compiler-Optimization

We will discuss how to do optimization in Compiler. We will take the dot product as the example.

### System Requirement
- GNU gprof 2.24

MacOS doesn't have gprof.

### Part 1 - Run dotproduct:
Steps:
- Download the file
- Compile the file
```gcc dotproduct.c –o dotproduct –O0 ```
- Run the binary dotproduct
- Success if the code run correctly


### Part 2 - gprof:
- ```make clean```
- ```gcc dotproduct.c -pg -o dotproduct```
- ```./dotproduct```
- ```gprof ./dotproduct gmoun.out```




### Part 3:
Is the code computation-bound or memory-bound?

Memory-bound. From the the flat profile in the question 2, we can see that init_matrix use 100.79 % time. It’s larger than the % time of dot_product. init_matrix is to about the memory allocation, so it’s the memory-bound.

Here are more about computer-bound and memory-bound. Computer-bound means the rate at which process progresses is limited by the speed of the CPU. If the calculations take most of the time, it’s likely to be computer-bound. Memory-bound means the rate at which a process progress is limited by the amount memory available and the speed of that memory access. 

Reference:
http://stackoverflow.com/questions/868568/what-do-the-terms-cpu-bound-and-i-o-bound-mean 


### Part 4:

Step 1: make clean
Step 2: make
Step 3: time ./dotproduct

real    0m0.020s
user   0m0.015s
sys     0m0.004s

- Explain the different values of this command.
Real shows the total turn around time for a process. User shows the execution time for user-defined instructions. Sys is for time for executing system calls.

- Why user is so different from real?
Real is time from start to finish of the call. It is all elapsed time including time slices used by other processes and time the process spend blocked. For example, it includes the waiting time for I/O. However user only includes time spent in user-mode code within the process. 

- How can you fix this problem?
We can put the execution job in a higher priority. The time slices and the time the process spend blocked decrease. Another option is to use a multicore system. On a multicore system, the sum of the user and sys time can actually exceed the real time. 


### Part 5:



### Part 6:

In the dataset - 1, there is no plateau. In the dataset -2, we can see plateaus.

First, we check CPU details on the machine:

| Architecture:      |	x86_64 |
| CPU op-mode(s):    |    32-bit, 64-bit |
| Byte Order:        |	Little Endian |
| CPU(s):            |	8 |
| On-line CPU(s) list:|   0-7 |
| Thread(s) per core:|    2 |
| Core(s) per socket:|	4 |
| Socket(s): |        	1 |
| NUMA node(s):|      	1 |
| Vendor ID:    |     	GenuineIntel |
| CPU family:    |    	6 |
| Model:          |     	60 |
| Stepping:       |   	3 |
| CPU MHz:         |  	3200.000 |
| BogoMIPS:         | 	6784.63 |
| Virtualization:    |	VT-x |
| L1d cache:     |    	32K |
| L1i cache:      |   	32K |
| L2 cache:       |   	256K |
| L3 cache:       |   	8192K |
| NUMA node0 CPU(s):| 	0-7 |

L1d cache and L1i cache are 32K, which is 32768 bytes. The int is 4 bytes. So each cache can hold 8192 int. It’s possible that one vector is stored in two caches. If one vector is stored in two different caches, the normalized execution increases. 

The reason is that it’s cache-unfriendly.  Elements that are adjacent in a row are supported to be adjacent in memory. So accessing them in sequence means accessing them in ascending memory order. This is called cache-friendly, since the cache tends to prefetch contiguous blocks of memory. However, if the elements that are adjacent in a row are not adjacent in memory, the cache fails to prefetch contiguous blocks of memory. Elements are distant in memory from each other. It jumps around in memory, potentially wasting the effort of the caches of retrieving the elements. 

Reference: http://stackoverflow.com/questions/16699247/what-is-cache-friendly-code 



### Part 7:
In Makefile:
```
dotproduct_timer:
    gcc dotproduct_timer.c -o $@ -O0
dotproduct_timer_optimized:
    gcc dotproduct_timer.c -o $@ -O3
```
dotproduct_timer_optimized is to use -O3

Here are optimize options which gcc provides. More details are in the reference.
-O0 (do no optimization, the default if no optimization level is specified)
-O1 (optimize minimally)
-O2 (optimize more)
-O3 (optimize even more)
-Ofast (optimize very aggressively to the point of breaking standard compliance)
-Os: Optimize for code size. This can actually improve speed in some cases, due to better I-cache behavior.

The different between the 2 assembly codes is that the one with -O3 is optimized. -O3 includes a lot of methods, which can be found in the reference.

Reference: 
- http://stackoverflow.com/questions/1778538/how-many-gcc-optimization-levels-are-there 
- https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html 




### Part 8:



### Reference

