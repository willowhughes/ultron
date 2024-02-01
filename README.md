# ultron
Here is Ultron, my software based simulation of a computer in C

Ultron's memory consists of 32 integer registers/memory locations that are used to hold instructions and variables
There are 2 additional registers for the PC (program counter) and the AC (accumulator)

I created a RISC like instruction set for ultron to run programs with called U <br>
each instuction in U has 4 digits.The first 2 is the operation <br>
Here are the operations's encodings:
  -define READ      10    // read word from input to memory
  -define WRITE     11    // write word from memory to screen
  -define LOAD      20    // load word from memory into accumulator
  -define STORE     21    // store word from accumulator into memory
  -define ADD       30    // add to accumulator from value in memory
  -define SUBTRACT  31    // subtract from accumulator the value in memory
  -define BRANCHNEG 40    // if accumulator is negative, branch to memory location
  -define HALT      43    // stop executing
last 2 digits is the operand or the location in memory of which the operaton applies

# Running Ultron
To compile the program in a linux terminal type make
To run it you type in ./ultron [-i instructions] [-f filename]
you can write a program in a .u text file and run it with the .u flag
to get started there are a few programs already written to be run within the directory
  -example2.u adds to integer inputs together
  -example3.u prints the larger of two integer inputs
  -program.u prints the input - 1
  -ultron.u accepts an input and prints a countdown to 0. 
      This is especially interesting to disect because the only branch operation branches if the value in the ac is negative...
      ...which makes ultron.u particularly complex. This goes to show how much you can do with only 8 operations in a computer
After a program is run, Ultron dumps the memory for debugging!

if you want to write your own program to be ran type in -i [# of lines of instructions/variables you intend on inputing] (default is 32)
