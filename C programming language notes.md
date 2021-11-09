# The C Programming language notes(the book is written by brian W.Kernighan and dennis M.Ritchie)

## setting up your environment for compiling C programs

well,all i need is vim in Visual Studio Code as Editor and gcc,it's easily to set up on linux.<br>
**suplementary resource**:<br>
_blog post about vim operations: https://www.barbarianmeetscoding.com/blog/boost-your-coding-fu-with-vscode-and-vim#fn-latest-vscode_
_complementary materials of K&R 2nd version:https://www.eskimo.com/~scs/cclass/krnotes/top.html_

## Chapter 1<br>

### 1.1 Getting Started<br>

#### compile code and run executables<br>

_compile code_: `cc helloworld.c`<br>
_run executable_: `./a.out`<br>

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

#### how to input EOF on linux<br>

press **ENTER** ,then press **Ctrl + D**

#### character counting<br>

++nc means increment by one,which is more concise and efficient than writting nc = nc + 1:`++nc`<br>
the formatted output of long integer: `%ld`<br>

the following for loop has a null statement representing by a single semicolon:

```
for(nc = 0;getchar() != EOF;++nc)
  ;
```

the above code ensure the **boundary condition** ,for example,the input is empty,getchar() fails,works also correctly,which is very important for a funtional complete program.<br>

#### line counting

the character written in **single quotes** represents an integer value equals to the numerical value of the character in the machine's character set.

#### word counting

the magic of **status or flag** can describe whether the program in a word or not.the initial status of status is not in a word.by **using symbolic constants to replace magic number**,you can make extensive changes easily in bigger programs.<br>

##### assignment

`nl = nc = nw = 0` sets all three variables to zero.

##### if-else clause

```
if(condition1)
  statements1;
else
  statements2;
```

if-else clause execute statements1 if condition1 is true ,if the condition1 is false,it will execute statements2.

#### program testing

test cases:invalid input,valid input and boundary conditions.

#### get input from stdin on linux

By default, linux terminal will buffer all information until Enter is pressed, before even sending it to the C program.

### 1.6 Arrays

#### declare an array

for example,declare ndigits to be an array of 10 integers:
`int ndigits[10];`

#### the value of '0'

'getchar()' will return integer value of char type,'0'...'9',represent the numerical value of character '0'...'9'.since in all the char sets,from '0' to '9' the corresponding int value is consecutively increased, so we can use the c - '0' represents numerical value of '0'...'9',which is a valid subscript of array ndigits.

### 1.7 Functions

#### define a function

a function definition has the following form:<br>

```
return-type function name (parameter declarations,if any)
{
declarations
statements
}
```

very important to know is that,**you should declare a function before using it**.

#### return

Return need not to return a value, a return statement with no expression **causes control to be returned to the caller**,
and caller will ignore the value returned by the function.<br>
main is also a function that will return value to its caller which is in effect the environment in which the program executes.<br>
a return value _zero_ implies normal termination,_non-zeros_ signal errorneous termination.

### 1.8 Arguments-Call by Value

#### pass by value

All the function arguments are passed by value.<br>
The called function **is given the value of the arguments in temporary variables** instead of the originals.<br>
All by value is an asset,which leads to more compact programs.
Because **parameters can be treated as conveniently initialized local parameters**.<br>
If you want a function to change the variable in a calling routine.
**The caller must provide the address of the variable(typically a pointer to the variable) to be set**.<br>
The story is different for arrays,when the name of an array is used as an argument,the value passed to the function is the location or address of the beginning of the array.

### 1.9 Character Arrays

#### '\0'

in C language,'\0' (null character,whose value is 0)is the signal of the end of the string of characters.

#### Get Length Of Character Array

function strlen() will return the length of character array, excluding '\0'.

### 1.10 external variables

#### local or automatic variables

variables that are defined in a function is called local variables, no othter functions can have access to it.<br>
local variables come into existence only when the function is called and disappear when the function is exited.

#### external variables

it's also possible to define variables that is external to all functions,which can be accessed by name by any function.<br>
the external variable must be declared once outside of the function,this set storage for it.

## Chapter 2 Types, Operations and Expressions

### 2.1 Variable Names

Names are made up of letters and digits. the first character must be a letter.

even though underscore "_" counts as a letter,but don't begin variable name with underscore "_",since library routines often use such names.

traditional c practice is to use UPPER CASE as symbolic constants and LOWER CASE as variable names.

it's wise to choose variable names that are related to the purpose of the variable that are unlikely to get mixed up typographical.

### 2.2 Data Types and Sizes

`char` a single byte, capable holding one character in the local character set.

`int` integer, typically reflecting the natural size of integers on the host machine

`float` single-precision floating point

`double` double-precision floating point

there are `qualifiers` that can be applied to basic types:

`short` and `long` can be applied to `int` types:

`short int sh` shorted as `short sh`

`long int l` shorted as `long l`

`short` and `long` should provide different length of integers.

`int` will be the natural size of a particular machine can provide, each compiler is free to choose appropriate size for it's hardware.

`signed` or `unsigned` qualifiers can be applied to char or integer.

`unsigned` character are always positive or zero, and obeys rules of arithmetic modulo `2^n`,while `signed` character have value between `-2^n/2` to `2^n/2`,

but whether a plain character is `signed` or `unsigned` character is up to the machine.

### 2.3 constants

#### Data Types Examples:

`int/decimal` : 1234, if an integer is too big, usually will be taken as long

`long`: 1234l or 1234L

`unsigned long`: 1234ul or 1234UL

`double`: 123.4 or 1e-2

`float`: 123.4f or 123.4F

`long double`: 123.4l or 123.4L

`octal`(八进制): 034

`hexadecimal`(十六进制): 0x23/0X23

#### character constants

character constant is an integer, such as 'x',for example, in the ASII character set, the characer set `0` has the value 48.

characer constants participate in numeric operations just as integers, also they often used in characer comparisons.

certain characer can be represented in character or string constant by escape sequences such as:`\n`,it looks like two characters, but represent only one.

the character constant `\0` represent the character with value 0, the `null` character.

#### string constants

string constants or string literals are characters surrounded by double quotes.those quotes are not part of strings, just serve only to delimit(划定界限) it.

technically, a string constant is an array of characters. the internal representation of string has a null character '\0' at the end.

#### enumeration constant

enumeration is a list of constant integer values, as in `enum boolean {YES, NO}`,

the first name in enum has value 0 and the second has the value 1, unless explicitly assigned.

names in enumerations must be distinct, values in the same enumration don't have to be the same.

#### Declarations

All variables can be declared before use. A declaration specifies a type and contains a list of variables of that type.

A variable can be initialized in a declaration. if a name is follwed by a equal sign and an expression, the expression serve as an initializer.

External and static variables are initialized to zero by default.

Automatic variables which are not explicitly initialized have undefined value(garbage).

the qualifier `const` can be applied to any variable to specify that it's value will not be changed.

#### 2.8 Increment and Decrement Operators

increment operator adds 1 to its operand while the decrement operator subtracts 1 from the operand.

the following code snippet can be more compact by using increment operator:

```
if(c == '\n'){
  s[i] = c;
  ++i;
}
```

can be rewritten as:

```
if(c == '\n'){
  s[i++] = c;
}
```

### 2.9 Bitwise Operators

C provides six operators for bit manipulation,these may only be applied to integral operands,

which is signed or unsigned short, long, int , char.

the bitwise AND(&) operator is often used to mask off some bits,the bitwise OR(|) operator is used to turn bits on:

`x & 1 -> x for any value of x`

`x & 0 -> 0 for any value of x`

the bitwise exclusive OR(^) operator sets a one if its operands have different bits.

one must distingush the bitwise operators & and | with logical operators && and || which implies to left-to-right evaluation of truth.

for example:`x & y` is zero while `x && y` is one.

the shift operators << and >> perform left and right shifts of their left oprand by the number of bit positions given by the right oprand,which must be non-negative.

the unary operator ~ yields the one's complement of an integer.

### 2.10 Assignment operators and Expressions

most binary operators have corresponding operator `op=`, where op is one of

`+ - * / % << >> & ^ |`

expression `expr1 = (expr1) + (expr2)` can be rewritten as `expr1 op= (expr2)`.

in the second expression, the expr1 is only computed once.

in expression `x >>= 1`, declare x to be unsigned to ensure that when it't right-shifted, vacated bits will be filled with zeros intead of sign bits.

because unsigned type always hold positve value.

#### Assignment in an expression

the example of assignment in an expression is like:

`while( (c = getchar()) != EOF)`

in the above code line, the type of the assignment expression is the type of its left operand, and the value is the value after assignment.

### 2.11 Conditional Expression

the statements

```
if(a > b){
  z = a;
}
else
{
  z = b;
}
```

compute in z the maximum of a and b.

this can be rewritten with conditional expression and ternary operator.

`expr1 ? expr2: expr3`

in this case, the above code can be rewritten as `z = (a > b) ? a : b`

if expr2 and expr3 are different types, for example: `n > 0 ? f : n`, n is integer.

according to the conversion rule, n will finally be float type no matter n is positive or negative.

### 2.12 Precedence and Order of Evaluation

in the code line

`a[i] = i++`

which makes us confused is that whether the i is the old value or new.

compilers can intepret in different ways.

therefore such situation should be avoided.

the moral is that writting code that depends on **order of evaluation** is a bad programming practice in any language.

## Chapter 3 Control FLow

### 3.1 Statements and Blocks

In C, the semicolon is the statement terminator.

Braces { and } are used to group declarations and statements together into a compound statement or block so that they are syntatically equivalent to a single statement.

### 3.4 Switch

switch statement is a multi-way decision, as a matter of good form,put a break after the last case(the default here) is logically unnecessary, some day when another case gets added at the end, the defensive programming will save you.

### 3.5 Loops - While and For

comma is the operator in C with the least preference which most often finds use in the `for` statement.

```
for example:
#include <stdio.h>
/*reverse:reverse string s in place*/
main(){
  int c, i, j;
  for(i = 0, j = strlen(s) - 1; i < j; ++i,--j){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
```

or

```
  for(i = 0, j = strlen(s) - 1; i < j; ++i,--j){
    c = s[i], s[i] = s[j], s[j] = c;
  }
```

### 3.6 Loops-Do-While

Do-While is used much less than While and For clause, but it sometimes it's much useful which guarantees at lest statements are executed at least once.

### 3.7 Break and Continue

The `break` enables an earlier exit from the `while`, `for` and `do`,just the same as `switch`.
the `continue` causes next iteratation of inner loop `while`,`for` and `do`,just skips the execution statements, it doesn't work with `switch`.

### 3.8 Go to and Labels

`go to ` and `label` should be used rarely, code with `go to` is harder to understand and mantain.

## Chapter 4 Functions and Program Structures

Functions break large computing tasks into smaller ones and enable people to build on what others have done, instead of starting over from scratch again.

### 4.1 Basics of Functions

A minimal function is like:

`dummy(){}`

which does nothing and returns nothing, a do-nothing function is sometimes useful as a **place-holder** during program development. if the return type is ommitted, int is assumed.

a program is just a set of definitions of variables and functions, Communications between the functions is by arguments and values returned by the functions, and through external variables.

### 4.2 Functions Returning non-integers

if a name that has not been declared before occurs in an expression and is followed by a left parentheses.it's declared by context to be a function name,
the function is assumed to return an int and nothing is assumed about its arguments.

`%g` and `%G` is the simplifiers of %e and %E which is the **scientific notation folat**.

### 4.3 Scope Rules

The _scope of a name_ is the part of the program within which the name can be used.

The scope of an external variable or a function lasts from the point at which it's declared to the end of the file being compiled.

If an external variable is to be referred before it's defined, or it's being used in a different file from the one where it's defined, then an _extern declaration_ is mandatory.

It's import to distinguish _declarition of external variable_ and it's _definition_:

A declarition announces properties of variable(primarily type) and a definition also causes storage to be set aside. and initialization of an external variable only goes with definition.
`extern int a;`

`extern char s[];`

`int a = 0;`

`char s[MAXVAL];`

### Header Files

In realistic program we might put different part of a bigger program into different source files.

declarations and definitions are shared among files, and we want to centralize it and keep only one copy as the program evolves.

so we will put declarations and definitions into header file: _`cacl.h`_.

### Static Variables

The `static declaration` applied to an external variable or function, limits the scope of that object to the rest of the source file being compiled.

With the `static declaration`, other files can use the same variable name and won't conflict with the ones in this file.

The `static keyword` can also be applied to function to limit it's scope to current file.

When `static keyword` is applied to internal variables, it's only avilable within the function, however it's storage is permanent.

### Register Variables

A register declaration advise the compiler that the variable will be heavily used.

The idea is that register variables is going to be placed in the machine registers.

The register declaration can only be applied to automatic variables and function parameters.

And only limited number of variables and specific type can be declared as register variables which varies machine by machine.

### Block Structure

In C, it's not allowed to define function inside a function.

As a matter of style, it's best to avoid variable names that conceal names in an outer scope. the potential for confusion and error is great.

### Initialization

External and static variables are guaranteed to be initialized to zero without explicit initialization. automatic and register variables have undefined initial values(maybe garbage).

for external and static variables the initializer must be constant expression and can only be initialized once.

instead, automatic and register variables can be initialized multiple times with any expression.

it's better code style to seperate declaration of automatic variables and it's initialization.

for example:

```
int i, c;

i = 0;

c = 0;
```

array initialization can be done by this way:

```
int days[] = {31,30,31,30......}
```

for missing initialization of array element, it will defaultly be zero for external, static and automatic type.

character array is a special case of initialization:

```
char pattern = "ould";
```

is equivalent to:

```
char pattern[] = {'o','u','l','d','\0'};
```

the length of the above char array should be 5.

### Recursion

when a function calls itself, each invocation get a fresh set of automatic variables, indepent of the previous set.

A good example of recursion is quick sort.

recursion may provide no saving in storage, because somewhere a stack of values being processed must be maintained, nor will it be faster, but somehow recursion code is more compact and easier to read.

## 4.11 The C Preprocessor

C preprocessor is conceptionally a seperate first step of compilation.

features are:

#include, to include the contents of file in compilation.

#define, to replace a token by an arbitrary sequence of strings.

others: conditional compilation and macros with arguments.

### File Inclusion

File inclusion makes it easier to handle collections of #defines and declarations.

#include "filename"

or

#include <filename>

will be replaced by the contents of the file to be included. if the filename is quoted, searching for the file typically begins where the source program was found, if the name is encluded in < and >, searching follows an implementation-defined rule to find the file.

naturally, when an included file has changed, all files depend on it must recompiled.

### Macro Substitution

```
#define name replacement text
```

it calls for the macro substitution of the simplest kind. subsequent

occurrences of token name will be replaced by the replacement text.

if a parameter name is preceded with #, the combination will be expanded into a quoted string.

### Conditional inclusion

It's possible to control preprocessing itself with conditional statements that

are evaluated during preprocessing.

The #if line evaluates a constant integer expression, if the expression is

non-zero, subsequent lines until an #endif or #elif or #else is included.

## Chapter 5 Pointers and Arrays

A pointer is a variable that contains the address of a variable, pointer is much used in C,partly because they are sometimes the only way to express the computation, and partly because they usually lead to more compact and efficient code.

### pointers and address

a typical machine has an array of consecutively numbered or addressed memory cells.

any byte can be a char, a pair of one-byte cells can be a short, and four adjacent bytes form a long,

a pointer is a group of cells(usually two or four) that can hold an address.

`p = &c`

assigns the address of c to the variable p, the & operator only applies to variables in memory: variables and array elements. it cannot be applied to constants, expressions or register variables.

`int *ip`

in the above expression, `*ip` is a pointer to int.

if `iq and ip` are both pointers.

`iq = ip`

makes `iq` points to the object `ip` points to.

### pointers and function arguments

since in c, functions pass arguments by value, so `swap(a,b)` function can't do the job by set a,b as `int` type, instead setting a,b as `pointers` solves the problem.

### Pointers and Arrays

In C, there is strong relationship between pointers and arrays. any operation that can be achieved by array subscripting can also be done with array pointers. they share the same implementation.

### Address Arithmetic

`p += i` increments it to point i elements beyond where it currently does.

C guarantees that **zero** is never a valid address for data.

Any pointer can be meaningfully compared for equality or inequality with zero.
