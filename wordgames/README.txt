5 Letter Guess
A secret ﬁve-letter word with no repeating letters is chosen. A player guesses ﬁve-letter words (also with no
repeating letters). For each word guessed, the player is informed how many letters in the word that they 
guessed are in the secret word. When the player guesses the correct word, the game is over and they win. 

• The program will read a single word (the “secret”) from a ﬁle speciﬁed on the commandline, which is the word
that the player should attempt to guess. The syntax for invoking is: wordguess [filename]
• The game will read a word from standard input (a “guess”), and provide feedback. Players can continue to 
enter guesses, one word at a time, until the secret word is guessed, or an EOF (Ctrl-D) is entered. 
• A valid word consists of ﬁve letters, with no letters repeating in a word (e.g. “poach” is a valid word; 
“speed” is not). Words do not include digits, or symbols, and do not contain spaces (i.e. words containing 
non-letter symbols are not valid). 
• If a guess does not match the secret word exactly, the game will return a message stating that “x letters
match” where x denotes the number of characters in that guess that are also in the secret word. Note that 
position does not matter; guessing “poach” against the secret word “crash” would match 3 characters, the ‘a’,
‘c’ and ‘h’, even through they had diﬀerent positions in the two words. The player is allowed to guess again. 
• If a word entered matches the secret word, the program will return a message “you guessed correctly!” and 
exit.


Hangman
Classic game of hangman with infinite lives. Invoke with: hangman [filename]

• File containing secret word should have the secret word as the first non-whitespace string. Any text following
the secret word will be printed out as a hint to the player. Refer to pineapple.txt file.
• Program will print out which letters were guessed correctly and which were not at every guess.
• Infinite attempts (more accurately 2^31 - 1 attempts). 
