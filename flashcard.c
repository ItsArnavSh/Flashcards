//Creating a flashcards terminal app for a C
#include <stdio.h>  //for printf() and scanf().
//There will be two options, one to revise more flashcards, and another one to create more.
//We will use the FOP approach for this and create two seperate funtions, for either case
void create()
{
    //The user is prompted to either create a new deck or add cards to an existing deck or to delete an existing deck
    //If the user wants to edit an existing deck or delete it, he is sent to display() from here that displays all the decks that are available
    //After that, the user is sent to writer() for edit or deckDelete() in case of deletion with the code of the deck.
    //If user wants to add a new deck, he is sent to newDeck()
}
void newDeck()
{
    //The user is prompted to enter its name
    //The computer generates a 2 letter code for this deck.
    //Then the user is redirected to card append
}
void writer()
{
    //This function will generate the "flow" of control for all the data and send it

}
void cardappend()
{
    //This is used to add questions to a card
}
void carddelete()
{
    //This is used to delete a specific card from a deck

}
void deckDelete()
{
    //This will delete the entire deck.
    //Not really delete, but only remove its name from the header file.
}
void deleter()
{
    //Redirected here from deck delete and 
    //We will use a temp file, copy everything from the main file to the temp file, except for the element to be deleted
    //After that we take the temp file and write it over the main file.
}
//The code below this is for review purposes...literally
void review()
{
 //The user is directed to display()
 //The flow will return here after the display
}
void display()
{
    //This snippet is supposed to display all the files from the content file along with their codes
}
int main(void)
{
    
}