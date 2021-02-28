# ipc - simple infix to postfix converter

Adapted from the topic presented in the second chapter of _Compilers Principles Techniques and Toolds, 2nd Edition (aka the Dragon Book)_. The book has a Java code snippet doing the same thing as this littel program. 

The program uses a simple predictive parser to convert an infix expression into a postfox form. Only single digit number are recognised by the parser.

This repository is part of the [Compilers101 project](https://github.com/fnoyanisi/Compilers101).

# The Grammar
Simple enough, so no extra explanations are required.
`E` stands for the epsilon symbol, which denotes the empty set.
```
        expr --> term rest
        
        rest --> + term { print("+") } rest
              |  - term { print("-") } rest
              |  E
        
        term --> 0 { print("0") }
              |  1 { print("1") }
              |  2 { print("2") }
              |  3 { print("3") }
              |  4 { print("4") }
              |  5 { print("5") }
              |  6 { print("6") }
              |  7 { print("7") }
              |  8 { print("8") }
              |  9 { print("9") }
```

# Building the code
You need `cmake` to compile the code. 

```
$ git clone https://github.com/fnoyanisi/ipc.git
$ cd ipc
$ mkdir build
$ cd build 
$ cmake ..
$ cmake --build .
$ ./src/ipc
```