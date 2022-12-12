#include "createnode.h"
#include "main.h"
#include <iostream>

using namespace std;

node *createnode()
{
	node *n;
	n = (node *)malloc(sizeof(node));
	return (n);
}

