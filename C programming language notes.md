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
the character written in **single quotes** represents an integer value  equals to the numerical value of the character in the machine's character set.
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
'getchar()' will return integer value of char type,'0'...'9',represent the numerical value of character '0'...'9'.since in all the char sets,from '0' to '9' the corresponding  int value is consecutively  increased, so we can use the c - '0' represents numerical value of '0'...'9',which is a valid subscript of array ndigits.

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
a return value *zero* implies normal termination,*non-zeros* signal errorneous termination.

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

###  2.3 constants
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

### 3.2 If-Else


## Chapter 5 Pointers and Arrays

A pointer is a variable that contains the address of a variable, pointer is much used in C,partly because they are sometimes the only way to express the computation, and partly because they usually lead to more compact and efficient code.

### pointers and address


