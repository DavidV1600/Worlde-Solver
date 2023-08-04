# Description of the Project:
The word-finding algorithm is based on information theory, using Shannon's entropy. It calculates, for each letter in the alphabet, its probability of appearing in any position (1, 2, 3, 4, 5) in the remaining possible words. By analyzing all the words, it chooses the one that provides the most information. The algorithm uses the "easy mode" version, where it can use words even if they are no longer a possible correct answer. This version is better because there are situations where a word that cannot be the solution provides more information than any of the remaining possibilities to be the solution.

# Average solving time
The algorithm has an average of 4.35 (4.34922) attempts until it finds the correct answer, and it starts guessing with the word "LUTRE."

# Project Startup
To run the mode where the game solves itself, two consoles/terminals need to be opened simultaneously. In the first one, run the command "./AI," and then in the other one, run "./JOC."
To run only the game where the user inputs words, run only the command "./JOC."
If it doesn't work, try running "g++ main.cpp -o AI" and "g++ main2.cpp -o JOC" first, and then the two commands.

# References
https://youtu.be/v68zYyaEmEA,  
https://youtu.be/fRed0Xmc2Wg
