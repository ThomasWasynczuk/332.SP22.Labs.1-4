# Lab3
Base repository for labs 1-4, initializes the repo and populates with an appropriate .gitignore file

Thomas Wasynczuk 455631

Base repository for labs 1-4, initializes the repo and populates with an appropriate .gitignore file

I wrote all of my code before testing anything in terminal, here were my errors when i first built my full solution:

I had ~100 errors, many of which saying that "game" (my main class) wasnt a class, and a bunch of other false stuff. I ran it all through an online debugger (onlinegdb) which didn't help at all. I eventually found a page on stack exchange that told me not to #include files redundantly. at the time, all of my files included all of my other files, which ran my program in circles and caused all of my compiler errors. quick fix once i figured it out.
Once the compiler was clear, I was getting a vector out of bounds error in terminal on the second iteration of ostream (which i learned from the debugger). I used breakpoints on all main functions & loops that used vectors and found that my "pieces" vector was pushing back 25 new empty game_pieces every iteration. I fixed so that it would only make the first 25, but still had the issue. it ended up being my print statement on the x moves, which i had mistakenly indexed incorrectly. again, quick fix once i figured it out.
last problem was finding an appropriate quit command, since abort didnt work. i tried a few and settled on exit(int).
to test, I ran the following scenarios: 1.every way to get 3 in a row, all were flagged as a W by the done() ftn 2.draws were flagged by the draw() ftn 3.quit 4.misspelled tictactoe as argv[1] 5.tried out of bounds locations (were not allowed by the program) 6.improper format 7.placing a game piece where one already exists

All scenarios behaved correctly in adherence with the Labs guidelines
