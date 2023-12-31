#include "monty.h"

/**
* nop - do not do anything
* @h: pointer to dll
* @l: line number
*
* Return: "void" Nothing
*/
void nop(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;
}

/**
* queue - change behavior to queue
* @h: pointer to dll
* @l: line number
*
* Return: "void" Nothing
*/
void queue(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;

	flag = "queue";
}

/**
* stack - change behavior to stack
* @h: pointer to dll
* @l: line number
*
* Return: "void" Nothing
*/
void stack(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;

	flag = "stack";
}

