#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//All the user defined functions
void cls();
void stop(int milliseconds);
void start();
void help();
void display();
void loading();
void input();
int checkSize(char buffer[20]);
int exists(char buffer[20]);
char code[5];
void opener(char buffer[20]);
void writer(char buffer[20]);
void appender(char buffer[20]);
void qizzer(char buffer[20]);
int main()
{
    start();
    loading();

    return 0;
}
void cls()
{
    system("clear");
}
void stop(int milliseconds)
{
    sleep(milliseconds/1000);
}
void loading()
{
    for(int i=0;i<4;i++)
    {
        printf("Loading");
        for(int j=0;j<=i;j++)
        {
            printf(".");
        }
        stop(200);
        cls();
    }
}
void start()
{
    printf("Welcome to Flashcards!\n");
    ///stop(2000);
    cls();
    printf("This is a program that will help you study.\n");
    ///stop(2000);
    cls();
    printf("Press h for help, or any other character to continue\n");
    char choice;
    scanf("%c", &choice);
    if (choice == 'h' || choice == 'H')
    {
        help();
    }
    cls();
    display();
}
void help()
{
    //All the help will be entered here.
    /*
    - Welcome to the Flashcards App that will help you study
    - It works on the principle of Active Recall, which states the best way to put information in your brain is by taking it out of it
    - It is a very effective method of memorization and learning.
    - The following is a guide on how to use this software
    - The code will display the list of all the existing files, or decks
    - They will be displayed in a pattern name - CODE
    - Then you will be prompted to enter the code.
    - If you enter an existing code, then the file will open up
    - You will be asked if you want to be quizzed on that code or if you want to edit it
    - If you choose to be quizzed, then the code will simply ask you questions
    - If you choose to edit the file, then follow the instructions
    */
}
void display()
{
    printf("Below is the list of all the files, with their codes \n");
    FILE *file = fopen("contents.txt","r");
    char data[100];
    int i=0;
    while(fgets(data, sizeof(data), file))
    {
        *(data+strlen(data)-1) = '\0';
        if(i%2==0)
        {
            printf("%s\t",data);
        }
        else
        {
            printf("%s\n",data);
        }
        i++;
    }
    input();
}
void input()
{
    printf("--------------------------");
    printf("\nEnter the code: ");
    char buffer[20];
    scanf("%s",buffer);
    int a = checkSize(buffer);
    int b = exists(buffer);
    if(a == 1)
    {
        if(b == 1)
        {
            opener(buffer);
        }
        else
        {
            writer(buffer);
        }
    }
    else
    {
        printf("The code should be 4 letters long!\n");
    }
    stop(1000);
}
int checkSize(char buffer[20])
{
    int size = strlen(buffer);
    if(size==4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int exists(char buffer[20])
{
    FILE *file = fopen("contents.txt","r");
    char data[100];
    int i=0;
    while(fgets(data, sizeof(data), file))
    {
        *(data+strlen(data)-1) = '\0';
        if(i%2==0)
        {
            if(strcmp(data,buffer)==0)
            {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
void opener(char buffer[20])
{
    printf("The Deck has been opened!\n");
    printf("Press 1 to add new questions\n");
    printf("Press 2 to practice the deck\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        appender(buffer);
    }
    else if(choice==2)
    {
        qizzer(buffer);
    }
    else
    {
        printf("Invalid Choice!\n");
    }
}
void writer(char buffer[20])
{
    printf("A new deck with the code %s has been created.\n",buffer);
    printf("Enter the name of the deck: ");
    char name[20];
    scanf("%s",name);
    FILE *file = fopen("contents.txt","a");
    fprintf(file,"%s\n",buffer);
    fprintf(file,"%s\n",name);
    fclose(file);
    char location[30];
    strcpy(location,"decks/");
    strcat(location,buffer);
    strcat(location,".txt");
    file = fopen(location,"w");
    while(1==1)
    {
    printf("Enter the question: ");
    char question[100];
    scanf("%s",question);
    if(strcmp(question,"0")==0)
    {
        restart();
        break;
    }
    fprintf(file,"%s\n",question);
    printf("Enter the answer: ");
    char answer[100];
    scanf("%s",answer);
    fprintf(file,"%s\n",answer);
    }
    fclose(file);
}
void appender(char buffer[20])
{
    char location[30];
    strcpy(location,"decks/");
    strcat(location,buffer);
    strcat(location,".txt");
    FILE *file = fopen(location,"a");
    while(1==1)
    {
    char question[100];
    scanf("%s",question);
    if(strcmp(question,"0")==0)
    {
        restart();
        break;
    }
    fprintf(file,"%s\n",question);
    printf("Enter the answer: ");
    char answer[100];
    scanf("%s",answer);
    fprintf(file,"%s\n",answer);
    }
    printf("Enter the question: ");
    fclose(file);
}
void qizzer(char buffer[20])
{
    char location[30];
    strcpy(location,"decks/");
    strcat(location,buffer);
    strcat(location,".txt");
    FILE *file = fopen(location,"r");
    char data[100];
    int i=0;
    while(fgets(data, sizeof(data), file))
    {
        *(data+strlen(data)-1) = '\0';
        if(i%2==0)
        {
            printf("%s\n",data);
        }
        else
        {
            printf("Press any key to see the answer\n");
            char ch;
            scanf("%c",&ch);
            printf("%s\n",data);
        }
        i++;
    }
    fclose(file);
}
restart()
{
    cls();
    main();
}
//