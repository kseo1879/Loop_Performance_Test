# Matric Multiplication Perfomance Testing

This repository helps demonstrates that by optimizing the code we can get more cache hit which improves the performance.  

## How to use

1. First you need to build and link each object file:
HOWEVER you can simply type 'make' on your command line. 

```bash
make
```

2. After you build your program here is the option:

```bash
make test1
```

```bash
make test2
```
.
.
.
```bash
make test7
```

Each Test will test the matrix multiplication with different size of the array.
Test1 will test 32 x 32 sized matrix, 64 x 64, 128 x 128 upto 2048 x 2048.


3. To clean the directory

```bash
make clean
```

## Testing In detail

If you look at the matrix_multi.c file, in the main function, line 158 there is the use of multiply function

You can change the number of multiply function for example:

```bash
       multiply1(mata, mata_width, mata_height, matb, matb_width,
            matb_height, &result_mat, &res_width, &res_height);
```

to 

```bash
       multiply2(mata, mata_width, mata_height, matb, matb_width,
            matb_height, &result_mat, &res_width, &res_height);
```

There are total 4 options you can test with difference optimization technique. 
multiply1, multiply2, multiply3, multiply4

In details of how each function works will be handled in the report. 

## Data
All the data including the plot and Flame graph is under the 'data' folder. 