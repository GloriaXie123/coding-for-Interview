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
- create a dir as workspace in vscode,execute the following command from your command line terminal:
  ```
  mkdir projects
  cd projects
  mkdir HelloWorld
  cd HelloWorld
  code .
  ```
  *code*. opens vs code in the current folder,you can create a file named helloworld.c in the current folder or current workspace.
- compile source code:helloworld.c
  from the main menu of vs code,choose **Terminal -> Configure Default Build Task**，from the drop down list choose **gcc build active file**,then run CTRL+SHIFT+B,the program will begin to complie.if you want to choose specific build task,you can choose **Terminal -> Run Build Task**,also the program will compile.
- run the executable program
  after the program is compiled sucessfully,a binary file named 'helloworld' will generate,then type  `./helloworld`,the program will be running.
- debug program
  from the main menu of vs code,choose **Run -> Add Configuration**,then choose **C++(GDB/LLDB)**,from the drop down list,choose **gcc bulid and debug active file**,then select helloworld.c file and press F5 to start debug.
