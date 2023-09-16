# TheFlashcardApp

Created: September 9, 2023 11:58 AM

**Here is another cool project for C, A flashcard app**

This app will completely rely on file handling, and the fact that C does not support csv or editing the files, this is going to be a rather intresting one.

Terms:

Deck→ Each set of flashcards

### What are we dealing with

The goal of this code is to make a sort of “cheap remnote”, which will be offline and local so I guess it will be better.

**The Objectives**

- The program will begin with two options, one to revise the previous cards and the other to create more
- Create
    - The User will be now asked to either create a new deck or add cards to an existing deck.
    - In either case, there will always be an option to delete any previous card. While being in teh option of entering cards, The user will press 0 and a menu with all the cards, with tehir 4 digit codes will open. The user can enter teh codes one by one and the cards will be removed from the list. Then the user can press 0 again to move on.
    - The user can press 1 to assign a new “motive” to the card, from 1 to 3 on how actively you want to be quizzed on that topic.
        - If the user creates a new deck, He will be asked to enter its name. The computer will generate a 4 digit code for the deck.
        - If the user adds to an existing deck, the things will go as expected, nothing new. Just appending the cards to the existing decks.
- Revise
    - The user is presented with a list along with a 3 letter Hexa (16^3 decks possible.) code for all the decks there exist.
    - The user is supposed to enter the deck code and then the deck starts quizzing the user based on the spaced repitition algorithm I will discuss below.
    - Every time, a new question will be flashed. The user has to rate how well he could recall an answer from 0 to 4, where 0 being forgot and 4 being remembered very well.
    - Everytime the user answers, the file gets edited. Or we can store the edits in an array and then shift them to the file to make the process less draining on the computer.
- TheInsider
    - There is a contents file, that contains name of all the existing decks
        - Whenever the person searches for a deck, we refer from this file only.
    - Then there are the respective files of all the given decks.
        - These files are stored in a csv manner, just the ‘,’ are replaced with ‘\n’. Yes.
        - This is just becuse it is easy to handle it.
        - Each section contains:
            - The Question
            - The Answer
            - The Code of the question
            - and some othe variables for spaced rep.