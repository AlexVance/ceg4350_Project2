# ceg4350_Project2

Project 2: Paging Algorithms

For this project you are to implement several page replacement algorithms: FIFO, Optimal, LRU, LFU, and MFU. Again, you must program in C for Linux. Your program will take several items as parameters: The first is the number of frames, and the second is a series (a string if you will) of integers representing the page references made by some fictional process. Assume that pages are accessed in left-to-right order by the fictional process.

For each replacement algorithm, output:
- How many page faults occurred for the process’s page references
- The final state of the frames, i.e., show which pages are in which frame of memory.

Building:
The project should build with the command:
gcc -o lastname lastname_project2.c

Running: 
Your program will be called as follows:

./lastname 3 0 1 5 5 5 0 2 3 4 1 1 9 9 10 0 2 1

In the above example, the first number (3) represents the number of frames that will be used in the program.

The subsequent numbers are the numbers that represent each of the page references. There are eight total pages that are referenced (pages 0 through 5, page 9 and page 10).

The important thing is the order in which they are referenced. This will determine which pages get paged out and which ones stay paged into memory, for that given number of frames you have available.

- You will be graded on how well each of the algorithms performs. Your program should be robust enough to handle incorrect or spurious input.
- Do not require the user to input any data while your program runs (such as to choose the algorithm). Instead, the user simply runs the program with an arbitrary string representing the number of frames and the page references, and your program should run each of the algorithms in turn and output the results of each.
- For the stack and queue based algorithms (like LRU), implement them using a stack or a queue (rather than using a counting solution). 
- For cases of ties (two pages have the same priority to be mapped back into memory), favor the one that was seen first.

- For stack and queue based solutions, the stack or queue size will be the same as the number of page frames you have to put things into. If you have 3 page frames, your stack should also be of size 3. In that case, when a page fault occurs and a new page is put on the top of the stack, the LRU page falls off the bottom. In the example in the text, this didn't happen since the stack size was 5 and there were 5 page numbers used. If you have a stack of 3 for the same reference string, it should be something like this (top of the stack to the left, with page faults showing in asterisks): 
4*
74*
074*
704
170*
017
107
210*
120
210
721*
172
217
