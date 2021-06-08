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
### 1.2 variables and arithmetic expressions<br>
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
### 1.3 for loop
the for loop is usually appropriate for loops in which the initialization and increment are single statement and logically related.
```
float fah;

for(fah = 300.0;fah >= 0.0;fah = fah - 20.0){
    printf("%3.0f\t%6.1f\n",fah,5.0 * (fah - 32.0) /9.0);
}
```
### 1.4 symbolic constants
it's bad practice to bury "magic number" in a program,because they convey little infomation to someone who might have to read the program later and they are hard to change in systematic way and one way to deal with it is to replace them with symbolic constants.
```
#define LOWER 0
#define UPPER 300
```
### 1.5 character input and output<br>
#### character counting<br>
++nc means increment by one,which is more concise and efficient by writting nc = nc + 1:`++nc`
the formatted output of long integer: `%ld`
#### 

