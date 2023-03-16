# NaN-Demo
A couple of short demos demonstrating the properties of NaNs in C++.
There are three such demos present: 

- Demo #1: Demonstrate how one can arrive at a NaN in their own code.
- Demo #2: Demonstrate how one can detect if a given variable is a NaN or not.
- Demo #3: Demonstrate how an initial NaN can propogate through a larger codebase. 

To be used for CDS Wednesday group programming project.

# How to use
- Method #1: Run `python3 nan.py a b c`, where a. b and c are either 0 or 1. Setting 
a = 1 will execute Demo #1 from above, b = 1 will execute Demo #2 from above,
and c = 1 will execute Demo #3 from above.

- Method #2: Compile nan.cpp manually with, say, `g++ nan.cpp -o nan` and execute
the binary with the command `./nan a b c`. a, b, and c hold the same definitions
as in Method #1.
