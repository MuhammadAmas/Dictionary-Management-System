#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "DictionaryManagementSystem.h"
using namespace std;

int main()
{
	int ch; 
	int ch2;
	do {
		printf("\n\t\t***WELCOME TO DICTIONARY MANAGMENT SYSTEM***\n");
		printf("\n1.Add a new Word.\n");
		printf("2.Search in dictionary\n");
		printf("3.Show Dictionary.\n");
		printf("4.Export in Dictionary.txt\n");
		printf("5.Delete from Dictionary.txt\n");
		printf("0.Close Dictionary.\n");
		printf("\n\t\tEnter your Choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			insert();
			break;
		case 2:
			search();
			break;
		case 3:
			display();
			break;
		case 4:
			add();
			break;
		case 5:
			del();
			break; 

		case 0:
			return 0;
		}
		printf("\n\n\t\tYou want to use Dictionary again?");
		printf("\n\t\t1.Yes\n\t\t2.No\n");
		printf("\n\t\tEnter your Choice: ");
		scanf("%d", &ch2);
	} 
	while (ch2 == 1);

		return 0;
	}