Push Swap - 42 Project
======================

Push\_swap is a program that sorts a stack of integers in ascending order using a limited set of operations on two stacks named `a` and `b`. The program consists of two parts: push\_swap and checker.

Functionality
-------------

The program must be able to execute the above operations on two stacks named "a" and "b". At the beginning, stack "a" must contain a random amount of negative and/or positive numbers which cannot be duplicated, and stack "b" must be empty.

The goal of the program is to sort the numbers in ascending order into stack "a".

Push Swap
----------

The push\_swap program takes a list of integers as arguments and sorts them using a set of predefined operations. The program then outputs a list of instructions that can be used to sort the list of integers in ascending order.

Checker
-------

The checker program takes a list of integers as arguments and a list of instructions from standard input. The program then executes these instructions on the list of integers and checks if the stack is sorted in ascending order. If the stack is sorted, the program outputs "OK", otherwise it outputs "KO". If an error occurs, such as an incorrect instruction or a stack with duplicate integers, the program outputs "Error".

Compilation
-----------
### To compile the program:

>1.  Clone this repository to your local machine. \
>2.  Run `make` to compile push swap and the checker. \
>3.  Run `./push_swap [list of integers]` to sort the list. \
>4.  Run `./checker [list of integers]` to verify whether the list is sorted or not. \

Operations
----------

The operations are described as follows:

*   `sa`: Swap the first two elements at the top of stack a.
*   `sb`: Swap the first two elements at the top of stack b.
*   `ss`: sa and sb at the same time.
*   `pa`: Take the first element at the top of b and put it at the top of a.
*   `pb`: Take the first element at the top of a and put it at the top of b.
*   `ra`: Shift up all elements of stack a by 1.
*   `rb`: Shift up all elements of stack b by 1.
*   `rr`: ra and rb at the same time.
*   `rra`: Shift down all elements of stack a by 1.
*   `rrb`: Shift down all elements of stack b by 1.
*   `rrr`: rra and rrb at the same time.

How to use
----------

To use push swap, compile the program and run it with a list of integers as arguments:
```bash
./push_swap 3 1 4 2
```
The program will output a list of instructions to sort the integers in ascending order.

To use checker, compile the program and run it with a list of integers as arguments, followed by a list of instructions:

```bash
./checker 3 1 4 2
# The program will then read instructions from standard input and will execute the commands
```

```bash
# Combining push swap and the checker
ARG="3 6 1 0 92 123 53 12"
./push_swap $ARG | ./checker $ARG
```
The program will execute the instructions on the stack and output "OK" if the stack is sorted and "KO" otherwise.

## Warning Against Blindly Copying Code
> Copying code without understanding it is not a good practice. While it may help you pass a project or assignment, 
it won't help you learn and grow as a programmer. It's important to take the time to understand the code you're working 
with, as it will help you catch errors, make improvements, and build better solutions in the future. Additionally, copying 
code without attribution or permission can be a violation of academic integrity and may result in penalties. \
So, take the time to learn and understand the code you're working with, and use it as a starting point to build your own solutions.
