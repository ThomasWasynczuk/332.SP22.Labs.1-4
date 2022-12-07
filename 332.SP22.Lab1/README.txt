Thomas Wasynczuk
LAB1



Issues:
got warnings for all of my for loops, just needed to make my iterator an unsigned int instead, easy fix

had trouble getting fstream working, fixed once i moved the file to the debug folder

took a minute to figure this one out, but my results were A1 except for the word 'more' wouldnt appear in my output
this was bc my program incremented twice over it, that was immedeatly clear, but the fix took a bit. 
I ended up changing the nested iterator to max instead of the outermost iterator to +1, seems to have preserved all functionality and fix the bug.
just for fun i left a few failed attempts at that bug fix commented out in main() 

Output from sample file:
H:\Current 332\Lab1\Lab1\Debug>Lab1.exe input_file1.txt
these all are strings 7string str4ing string2 more strings
0
1
2
3
5
7
11
13
17
19

tested only that file but error messages are accurate for every case they've encountered (missing or additional arguments, file not found, etc.)

