# Christmas Tree

## Task
Create a program which will print a christmas tree in the terminal with a given height with the character '*' and '|'

## Description
I did a function christmas_tree which will do all the printing by calling two function :
- trunk (which will print the trunk, line by line with the rigth width and length)
- tree (which will print all of the spine levels, one by one)

tree will call the function spine which will print one level of the tree

The function christmas_tree will be called in the main function.
The main function will calculate the length of the last line of the last level with the function max_length, 
and it will get the height given by the user in the call of the file.

## Installation
First you will need to have the file named my_christmas_tree.c and the Makefile

Next, to compile the program you will need to enter in the terminal :
```
$> make
```

If you wanna clean the compiled files enter in the terminal :
```
$> make fclean
```

## Usage
To use the file, you will need to call it like this:

```
$> ./my_christmas_tree [the height]
```
