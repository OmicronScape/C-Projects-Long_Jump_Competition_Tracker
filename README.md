# C-Projects-Long_Jump_Competition_Tracker
A C program for tracking and ranking long jump competition results. It records athletes' performances, finds the best jumps, and sorts results in descending order."

Long Jump Competition Tracker

Overview

This C program simulates a long jump competition with 8 athletes, each performing six jump attempts (three initial jumps and three additional jumps for the top four athletes). The program tracks, evaluates, and ranks the athletes based on their best performance.

Features

Athlete Registration – Users input unique athlete numbers (100-999).

Performance Recording – Validates and records jump attempts (valid range: 1-12 meters, -1 for a failed attempt).

Best Jump Calculation – Determines the highest valid jump for each athlete.

Sorting & Ranking – Sorts athletes in descending order based on their best performance.

Result Display – Prints a detailed table showing all attempts and the final ranking.

How It Works

The user inputs the athletes' numbers and their first 3 jump attempts.

The program calculates the best jump for each athlete and sorts them in descending order.

The top 4 athletes perform 3 additional attempts, and their best performance is updated.

The program re-sorts the results and prints the final rankings.

Compilation & Execution

Compiling the Program

To compile the program using GCC, run:

gcc -o long_jump long_jump.c

Running the Program

./long_jump

Example Output

----------------------------------------------
- INTERNATIONAL TRACK MEET - LONG JUMP FINAL RESULTS -
----------------------------------------------
A_A |    1   |    2   |   3    |    4   |    5   |    6   |  max  |
----------------------------------------------
101 |  6.45  |  6.80  |   X    |  7.10  |   X    |  7.25  |  7.25  |
...

Technologies Used

C Programming Language

GCC Compiler

Standard I/O Library (stdio.h)

Future Enhancements

Add file saving to store and retrieve competition results.

Implement graphical visualization of athlete performance.

Expand the program to support different sports and scoring methods.
