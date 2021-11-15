#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <math.h>   // to square

/* functions to create lists */
node *make_node(int v, node *q)
{
  node *p = malloc(sizeof(node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p)
{
  node *q = p;
  while (q != &SENTINEL_node)
  {
    node *t = q->next;
    free(q);
    q = t;
  }
}

/* print list to console */
void print_list(node *p)
{
  if (p->next == NULL)
    return; // Exit condition/ until the last element.
  else
    printf("%d", p->value); // Prints first value of node printing p's value/data until the last element
  print_list(p->next);      // Recursive call
}

int sum_squares(node *p)
{
  int sum;
  if (p == NULL) // Exit condition // i've changed the &SENTINELNODE because there was a problem we saw in the café, but i dont know how to fix the test case.
    return 0;
  else if (p->next == NULL)
    return square(p->value);
  else
    return (pow(p->value, 2) + sum_squares(p->next)); // Recursive call, taking the data of p, and sets it to the power of 2
  // Add your code for excercise 2                    // And adding the new value of p on top of the sum squares.
  // You can find the tests in tests.cpp
}

node *map(node *p, int (*f)(int))
{
  if (p == NULL)
    return NULL;
  else
    return make_node((*f)(p->value), map((p->next), *f)); //recursive call, Calling make_node function for the given value of p. I need to make a new list, with the p->value squared. Then i go to the next p->next, for det next p until list is empty.
}

int square(int x)
{
  return x * x;
}
