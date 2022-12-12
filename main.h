#ifndef MAIN_H
#define MAIN_H

typedef struct node
{
	char word[100];
	char meaning[1000];
	char syno[1000];
	struct node *next;
}
node;
#endif
