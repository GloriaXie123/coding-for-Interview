# how to compile and debug code in vscode on linux
## prerequisite
- Visual Stdio Code
- C/C++ extension for VS Code(install from vs code market)
- you also need gcc to compile and gdb to debug
  - check gcc is installed or not: `g++ -v`
  - if you don't have gcc installed,try the following command:
    ```
    sudo apt-get update
    sudo apt-get install build-essential gdb
    ```
- create a dir as workspace in vscode,execute the follwing command from your command line terminal:
  ```
  mkdir projects
  cd projects
  mkdir HelloWorld
  cd HelloWorld
  code .
  ```
  *code*. opens vs code in the current folder,you can create a file named helloworld.c in the current folder or current workspace.
- compile source code:helloworld.c
  from the main menu of vs code,choos **Terminal -> Configure Default Build Task**
