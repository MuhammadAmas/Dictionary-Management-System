#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "DictionaryManagementSystem.h"
struct node
{
	char word[100];
	char meaning[1000];
	char syno[1000];
	struct node *next;
};
FILE *l;
node *start = NULL;
node *createnode()
{
	node *n;
	n = (node *)malloc(sizeof(node));
	return (n);
}

bool search(node *temp)
{
	node *t = start;
	while (t != NULL)
	{
		if (strcmpi(t->word, temp->word) == 0)
			return true;
		t = t->next;
	}
	return false;
}

void insert()
{
	node *temp, *prev;
	char value[100];
	temp = createnode();
	int value1;
	printf("\n\t\tEnter the Word:- ");
	fflush(stdin);
	gets(temp->word);
	if (search(temp) == 0)
	{
		strcpy(value, temp->word);
		printf("\n\t\tEnter the Synonym:- ");
		gets(temp->syno);
		fflush(stdin);
		printf("\n\t\tEnter the Meaning:- ");
		gets(temp->meaning);
		temp->next = NULL;
		if (start == NULL)
		{
			start = temp;
		}
		else if (start != NULL && strcmpi(value, start->word) < 0)
		{
			temp->next = start;
			start = temp;
		}
		else
		{
			node *t;
			prev = start;
			t = start->next;
			while (t != NULL && strcmpi(value, start->word) > 0)
			{
				prev = t;
				t = t->next;
			}
			if (t == NULL)
			{
				prev->next = temp;
			}
			else
			{
				temp->next = t;
				prev->next = temp;
			}
		}
	}
	else
		printf("\nWord already exists\n");
}

void search()
{
	node *t = start;
	char value1[100];
	printf("\n\t\tEnter the Word to be searched:- ");
	fflush(stdin);
	gets(value1);
	int flag = 0;
	while (t != NULL)
	{
		if (strcmpi(t->word, value1) == 0)
		{
			printf("\n\t\tWord->");
			puts(t->word);
			printf("\t\tSynonym->");
			puts(t->syno);
			printf("\t\tMeaning->");
			puts(t->meaning);
			printf("\n\n");
			flag = 1;
			break;
		}
		t = t->next;
	}
	if (flag == 0)
		printf("\n\t\tWord is'nt present in the list");
}

void display()
{
	node *t = start;
	while (t != NULL)
	{
		printf("\n\t\tWord->");
		puts(t->word);
		printf("\t\tSynonym->");
		puts(t->syno);
		printf("\t\tMeaning->");
		puts(t->meaning);
		t = t->next;
		printf("\n\n");
	}
}

void add()
{
	node *save;
	save = start;
	if (start == NULL)
	{
		printf("\n\t\tLinklist is empty[*Enter some data to save the linklist]\n");
	}
	else
	{
		l = fopen("Dictionary.txt", "a");
		while (save != NULL)
		{
			fprintf(l, "Word->");
			fprintf(l, "\t%s", save->word);
			fprintf(l, "\n");

			fprintf(l, "Synonym->");
			fprintf(l, "\t%s", save->syno);
			fprintf(l, "\n");

			fprintf(l, "Meaning->");
			fprintf(l, "\t%s", save->meaning);
			fprintf(l, "\n\n");
			save = save->next;
		}
		fclose(l);
		printf("\n\t\t[*Data added and saved successfully]\n");
	}
}

void del()
{
	node *save;
	save = start;
	if (start == NULL)
	{
		printf("\n\t\tLinklist is empty[*Enter some data to save the linklist]\n");
	}
	else
	{
		l = fopen("Dictionary.txt", "w");
		fclose(l);
		printf("\n\t\t[*Filedeleted successfully]\n");
	}
}