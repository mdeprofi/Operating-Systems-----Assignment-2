# Operating-Systems-----Assignment-2

The repository contains the following files:
1. bankers.c - Contains the implementation for the Banker's Algorithm in C.
2. input.txt - Input file that provides the initial resource allocation, maximum resource needs, and available resources for the system.

Before any compilation, make sure you are working in a Linux environment. For example, this project was tested on the Kent State University hornet server. 

Step 1: Creating The Files
Once in your Linux environment, you need to create both the bankers and input files:

`- touch bankers.c`

`- touch input.txt`

After creating your files, copy the provided C source code into bankers.c, and the resource data into input.txt.

Step 2: Compilation
In order to run the program you first have to compile it using this command:

`- gcc bankers.c -o bankers`

This command will create an executable file called bankers.

Step 3: Execution
Once the program is compiled, run it using this command:

`- ./bankers`

This command will run the Banker's Algorithm program.
