#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <dos.h>
#include <time.h>
#include "WriteDat.cpp"

int i;
char option;
int ch;
const int MAX=80;
const int MAX_TRIES=5;

struct node
{
char list[80];
node *next;
};
node *start= NULL;
ifstream BData("BOLLY.txt");
ifstream HData("HOLLY.txt");

void ReadBData()
{
node *fresh;

if(!BData)
 {
cout<<"ERROR 404\n";
 }
else
 {
while(!BData.eof())
  {
fresh = new node;
BData.getline(fresh->list,80);
if(start==NULL)
  {
fresh->next=NULL;
start=fresh;
  }
else
  {
fresh->next=start;
start=fresh;
  }

}

}
}

void ReadHData()
{
node *fresh;
if(!HData)
{
cout<<"ERROR 404\n";
}
while(!HData.eof())
{
fresh= new node;
HData.getline(fresh->list,80);
if(start==NULL)
{
fresh->next=NULL;
start=fresh;
}
else
{
fresh->next=start;
start=fresh;
}

}
}


int count;
void CalEntry()
{
count=0;
node *ptr;
for(ptr=start->next;ptr!=NULL;ptr=ptr->next)
{
count++;
}
}
void reset()
{
count=0;
}
char movies[MAX][MAX];
void insert()
{
int j=0;
int n;
node *ptr;
for(ptr=start->next;ptr->next!=NULL;ptr=ptr->next,j++)
{
if(ptr==NULL)
{
break;
}
else
{
strcpy(movies[j],ptr->list);
}
}
strcpy(movies[j],ptr->list);
}

struct Bollywood
{
void AddMovie()
{
clrscr();
load();
cout<<"-------BOLLYWOOD-------\n";
do
{
WriteData("Bolly.txt");
cout<<"Do you wish to continue?[Y/N] :";
cin>>option;
}
while(option=='Y' || option =='y');
menu();
}


};

struct Hollywood
{

void AddMovie()
{
clrscr();
load();
cout<<"--------HOLLYWOOOD--------\n";
do
{
WriteData("Holly.txt");
cout<<"Do you wish to continue?[Y/N] :";
cin>>option;
}
while(option=='Y' || option=='y');
menu();
}

};

Bollywood Bolly;
Hollywood Holly;

class game
{
char toguess[MAX];
char letter;
char movie[MAX];

public:

void Initialize (char word[], char unknown[])
{
int i;
int length = strlen(word);
for(i=0;i<length;i++)
{
if(word[i]=='A' || word[i]=='a')
{
unknown[i]='A';
}
else if(word[i]=='E' || word[i]=='e')
{
unknown[i]='E';
}
else if(word[i]=='I' || word[i]=='i')
{
unknown[i]='I';
}
else if(word[i]=='O' || word[i]=='o')
{
unknown[i]='O';
}
else if(word[i]=='U' || word[i]=='u')
{
unknown[i]='U';
}
else if(word[i]==' ')
{
unknown[i]=' ';
}
else
{
unknown[i]='_';
}

}

unknown[i]='\0';
}
int CheckLetter (char guess, char movie[], char toguess[])
{
int i;
int matches=0;
guess=toupper(guess);
for(i=0;toguess[i]!='\0';i++)
{
if(guess == toguess[i])
{
return 0;
}
if(guess==movie[i])
{
toguess[i]=guess;
matches++;
}
}
return matches;
}
void display(int len)
{
for(int k=0;k<len;k++)
{
if(toguess[k]==' ')
{
cout<<"/ ";
}
else
{
cout<<toguess[k]<<" ";
}
}
cout<<"\n";
}
void gameplay()
{
int MAX_TRIES = 10;
int Wrong_Guess = 0;
int win=0;
int level = 0;
int score=1;
cout<<"\n\t\tGUESS THE MOVIE\n";
cout<<"\t\tYou have "<< MAX_TRIES <<" tries to try and guess the movie!\n";
delay(500);
cout<<"\t\tLETS PLAY!\n";
delay(1000);
while(win==0)
{
randomize();
int pos=rand()%count;
strcpy(movie,movies[pos]);
Initialize(movie, toguess);
int len = strlen(movie);
clrscr();
cout<<"\t\t\t------LEVEL "<<level+1<<"---------\n";
cout<<"\t\t\tPress any key to continue....\n";
getch();
load();
while(Wrong_Guess < MAX_TRIES )
{
clrscr();
display(len);

cout<<"\n";
cout<<"Guess the letter : ";
cin >> letter;

if(CheckLetter(letter, movie, toguess)==0)
{
clrscr();
display(len);
cout<<"\nWhoops! That letter isn't there or has already occured!\n";
Wrong_Guess++;
delay(500);
}
else
{
cout<<"\n You found a letter! Isn't that exciting?!\n";
delay(500);
}

if(strcmp(movie,toguess) == 0)
{
clrscr();
cout<< movie <<endl;
cout<<"Congratulations! You've guessed the movie!\n";
score=score + (MAX_TRIES - Wrong_Guess)*20;
cout<<"Your Score : "<<score;
delay(2000);
level++;
Wrong_Guess = 0;
break;
}
cout<<"You have "<< MAX_TRIES - Wrong_Guess<<" tries left!\n";
delay(1000);

}
if(Wrong_Guess == MAX_TRIES)
{
cout<<" Sorry, you loose... better luck next time!\n";
cout<<" The movie was : " << movie <<endl;
cout<<" Your Score : "<<score;
char choice;
cout<<"\nDo you want to try again?[Y/N]\n";
cin>>choice;
if(choice=='Y' || choice=='y')
{
win=0;
}
else
{
win=1;
}
}
}
}


};
game Obj;

void main_menu();
void menu();
void screen();
void load();
void rules();
void play();

void main()
{
clrscr();

screen();





getch();
}

void main_menu()
{
clrscr();
int choice;
cout<<"\t  ========================================================"<<endl;
cout<<"\t  ||                   1. Start                         ||"<<endl;
cout<<"\t  ||                   2. Rules                         ||"<<endl;
cout<<"\t  ||                   3. Add Movies                    ||"<<endl;
cout<<"\t  ||                   4. Exit                          ||"<<endl;
cout<<"\t  ========================================================"<<endl;
cout<<"\t  Enter the NUMBER against the OPTION you wish to SELECT\n";
cout<<"\t  Select Option - ";
cin>>choice;
switch(choice)
{
case 1: play();
break;
case 2: rules();
break;
case 3: menu();
if(ch==1)
{
Bolly.AddMovie();
}
else if(ch==2)
{
Holly.AddMovie();
}

break;
case 4: exit(0);
break;
default : cout<<"Wrong Option selected\n Please try again\n";
main_menu();
}

}

void rules()
{
clrscr();
load();

}
void play()
{
clrscr();
int choice;
cout<<"SELECT THE CATEGORY YOU WOULD LIKE TO PLAY\n";
cout<<"\t\t=============================================\n";
cout<<"\t\t||               1.BOLLYWOOD               ||\n";
cout<<"\t\t||               2.HOLLYWOOD               ||\n";
cout<<"\t\t||               3.BACK TO MENU            ||\n";
cout<<"\t\t=============================================\n";
cout<<"Enter the option (1-3) : ";
cin>>choice;
switch(choice)
{
case 1:ReadBData();
CalEntry();
insert();
Obj.gameplay();
reset();
break;
case 2:ReadHData();
CalEntry();
insert();
Obj.gameplay();
reset();
break;
case 3: main_menu();
break;
default: cout<<"Wrong Option Entered!\nRetry\n";
play();
}
}

void menu()
{
clrscr();
load();
cout<<"       ======================================="<<endl;
cout<<"       |             1. Bollywood            |"<<endl;
cout<<"       |             2. Hollywood            |"<<endl;
cout<<"       |             3. Back                 |"<<endl;
cout<<"       ======================================="<<endl;
cout<<"       Select the Option (1-3) : ";
cin>>ch;
if(ch==3)
{
main_menu();
}
}

void screen()
{
load();



cout<<"           ====================================================="<<endl;delay(50);
cout<<"           |           ____                                    |"<<endl;delay(50);
cout<<"           |          / ___|  _   _    ___   ___   ___         |"<<endl;delay(50);
cout<<"           |         | |  _  | | | |  / _ \\ / __| / __|        |"<<endl;delay(50);
cout<<"           |         | |_| | | |_| | |  __/ \\__ \\ \\__ \\        |"<<endl;delay(50);
cout<<"           |          \\____|  \\__,_|  \\___| |___/ |___/        |"<<endl;delay(50);
cout<<"           |                                                   |"<<endl;delay(50);
cout<<"           |                _____   _                          |"<<endl;delay(50);
cout<<"           |               |_   _| | |___    ___               |"<<endl;delay(50);
cout<<"           |                 | |   | '_  \\  / _ \\              |"<<endl;delay(50);
cout<<"           |                 | |   | | | | |  __/              |"<<endl;delay(50);
cout<<"           |                 |_|   |_| |_|  \\___|              |"<<endl;delay(50);
cout<<"           |                                                   |"<<endl;delay(50);
cout<<"           |           __  __                   _              |"<<endl;delay(50);
cout<<"           |          |  \\/  |   ___   __   __ (_)   ___       |"<<endl;delay(50);
cout<<"           |          | |\\/| |  / _ \\  \\ \\ / / | |  / _ \\      |"<<endl;delay(50);
cout<<"           |          | |  | | | (_) |  \\ V /  | | |  __/      |"<<endl;delay(50);
cout<<"           |          |_|  |_|  \\___/    \\_/   |_|  \\___|      |"<<endl;delay(50);
cout<<"           |                                                   |"<<endl;delay(50);
cout<<"           ====================================================="<<endl;delay(1000);
cout<<"                           |  by KUSHAAN KAPOOR   |       "<<endl;delay(50);
cout<<"                           |        XII - B       |       "<<endl;delay(50);
cout<<"                           |      Roll No. 14     |       "<<endl;delay(50);
cout<<"                           ========================       "<<endl;delay(500);
cout<<"\n\t\t\t  Press any key to continue..... "<<endl;
getch();
clrscr();
load();
main_menu();

}

void load()
{
clrscr();
randomize();
int n=rand()%6+2;

for(i=0;i<n;i++)
{
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"                                    Loading";cout<<".";delay(150);cout<<".";delay(150);cout<<".";delay(150);
clrscr();
}

}
