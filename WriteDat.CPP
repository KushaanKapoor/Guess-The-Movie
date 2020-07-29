#include <iostream.h>
#include <ctype.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>


void WriteData(char *str)
{
char movie[80];
ofstream data(str,ios::app);
clrscr();
cout<<"Enter the name of the movie : ";
gets(movie);
if(!data)
{
cout<<"ERROR, file not found!\n";
}
else
{
for(int i=0;movie[i]!='\0';i++)
{
movie[i]=toupper(movie[i]);
data.put(movie[i]);
}
data<<"\n";
}

}