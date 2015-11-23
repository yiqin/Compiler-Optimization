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



### Part 4:




### Part 5:



### Part 6:




### Part 7:



### Part 8:



### Reference
http://stackoverflow.com/questions/868568/what-do-the-terms-cpu-bound-and-i-o-bound-mean

