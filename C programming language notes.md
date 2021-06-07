# The C Programming language notes(the book is written by brian W.Kernighan and dennis M.Ritchie)
## setting up your environment for compiling C programs
well,all i need is vim in Visual Studio Code as Editor and gcc,it's easily to set up on linux.<br>
**suplementary resource**:<br>
*blog post about vim operations: https://www.barbarianmeetscoding.com/blog/boost-your-coding-fu-with-vscode-and-vim#fn-latest-vscode*
## Chapter 1<br>
### 1.1 Getting Started<br>
#### compile code and run executables<br>
*compile code*: `cc helloworld.c`<br>
*run executable*: `./a.out`<br>
#### variables and arithmetic expressions<br>
##### comment<br>
`/*this is a comment*/`
##### declaration<br>
consist of type names and a list of variables:`int lower, upper, step;`
##### loop
while loop is executed until the condition inside the brace is unsatisfied: <br>
```
while (lower <= upper)
{
  /*the statements inside the while loop is usually indented to emphasize the logic structure of the program*/
  lower = lower + step;
  ...
}
```
you can ignore the braces if just one statement inside the while loop:
```
while (lower <= upper)
  lower = lower + step;
```
##### format printing
format the output:<br>
```
/*the fah is to be at least 3 characters wide and has no characters after the decimal point,celsius follows the same routine*/
printf("%3.0f\t%6.1f",fah,celsius)

```
#### for loop
the for loop is usually appropriate for loops in which the initialization and increcement are single statement and logically related.
