# ultron
Here is Ultron, my software based simulation of a computer in C

Ultron's memory consists of 32 integer registers/memory locations that are used to hold instructions and variables
There are 2 additional registers for the PC (program counter) and the AC (accumulator) <br>

I created a RISC like instruction set for ultron to run programs with called U <br>
Each instuction in U has 4 digits.The first 2 is the operation <br>
Here are the operations's encodings: <br>

&emsp;-define READ&emsp;     10    // read word from input to memory <br>
&emsp;-define WRITE&emsp;     11    // write word from memory to screen <br>
&emsp;-define LOAD&emsp;      20    // load word from memory into accumulator <br>
&emsp;-define STORE&emsp;     21    // store word from accumulator into memory <br>
&emsp;-define ADD&emsp;       30    // add to accumulator from value in memory <br>
&emsp;-define SUBTRACT&emsp;  31    // subtract from accumulator the value in memory <br>
&emsp;-define BRANCHNEG&emsp; 40    // if accumulator is negative, branch to memory location <br>
&emsp;-define HALT&emsp;      43    // stop executing <br>

last 2 digits is the operand or the location in memory of which the operaton applies <br>

# Running Ultron <br>
To compile the program in a linux terminal type make <br>
To run it you type in ./ultron [-i instructions] [-f filename] <br>
you can write a program in a .u text file and run it with the .u flag <br>
to get started there are a few programs already written to be run within the directory <br>
&emsp;-example2.u adds to integer inputs together <br>
&emsp;-example3.u prints the larger of two integer inputs <br>
&emsp;-program.u prints the input - 1 <br>
&emsp;-ultron.u accepts an input and prints a countdown to 0. <br>
&emsp;&emsp;&emsp;This is especially interesting to disect because the only branch operation branches if the value in the ac is <br> &emsp;&emsp;&emsp;negative, which makes ultron.u particularly complex. This goes to show how much you can do with only 8 <br> &emsp;&emsp;&emsp;operations in a computer <br>

After a program is run, Ultron dumps the memory for debugging! <br>

if you want to write your own program to be ran type in -i [# of lines of instructions/variables you intend on inputing] (default is 32) <br>
