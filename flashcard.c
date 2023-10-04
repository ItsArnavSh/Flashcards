//Creating a flashcards terminal app for a C
#include <stdio.h>  //for printf() and scanf().
#include <stdlib.h> //for cls
#include <windows.h>//For Sleep
//There will be two options, one to revise more flashcards, and another one to create more.
//We will use the FOP approach for this and create two seperate funtions, for either case
int *contents;
//Contents is the header of the array that will store the page data
void cls()
{
    system("cls");    
}
void loadingscreen()
{
    cls();
    printf("...Press Enter to Start...");
    int p;
    scanf("%c",&p);
    cls();
    for(int i=0;i<=3;i++)
    {
        printf("Loading");
        for(int j=0;j<i;j++)
        {
            printf(".");
        }
        Sleep(200);
        cls();
    }
    options();//After this the user is sent to options
}
void options()
{
    asking:
    printf("Welcome to The Flashcard App\n");
    printf("Enter 1 to create the card\nEnter 2 to review existing decks\nEnter 3 for Help");
    int choice;
    printf("\n----Enter here: ");
    scanf("%d",choice);
    Sleep(100);
    cls();
    switch(choice)
    {
        case 1:
        create();
        break;
        case 2:
        review();
        break;
        case 3:
        docs();
        break;
        default:
        printf("Please enter 1 2 or 3!");
        cls();
        goto asking;
    }
}
void docs()
{
    //This is a wikihow that will be displayed in the cml
    printf("Welcome to Flashcard Help\n");
    //This will have a directory structure, using nested switch cases
    //Press 1 to know more about this and press any other button to go back
    //There will always be a press 0 to exit and go back to the main menu
    printf("When you log into, you are presented with two options, apart from the help section\n");
    printf("The Create and The Review Buttons");
    printf("\nPress an even number to know more about create and an odd number to know more about Review");
    printf("\n:- ");
    int choice;
    scanf("%d",choice);
    switch(choice%2)
    {
        case 1://Odd
        //Tell more about create
        //Add an option to go back one menu
        break;
        case 0://Even
        //Tell more about Review
        //Add an option to go back one menu
        break;
    }
}
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
    //The loading screen comes up, with the ususal press enter to start.
    loadingscreen();
}