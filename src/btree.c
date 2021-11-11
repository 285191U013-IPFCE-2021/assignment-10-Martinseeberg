#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct tree_node *getNewNode(int x)
{
  struct tree_node *newnode = malloc(sizeof(struct tree_node));
  newnode->item = x;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

struct tree_node *Insert(int x, struct tree_node *t)
{
  // Checking if t==null.
  if (t == NULL)
    return getNewNode(x);
  /*
     * if given x is greater than t->item,
     * we should find the correct place in the right subtree and insert the new node
     */
  if (t->item < x)
    t->right = Insert(x, t->right);
  /*
     * if given x is smallar than t->item,
     * we should find the correct place in the left subtree and insert the new node
     */
  else if (t->item > x)
    t->left = Insert(x, t->left);
  /*
     * It will handle two cases
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
  return t;

  // Insert item x into the tree t

  return NULL;
}

struct tree_node *Remove(int x, struct tree_node *t)
{

  // Remove one item from the tree t

  return NULL;
}

int Contains(int x, struct tree_node *t)
{
  if (t != 0)
  {
    {
      if (x == t->item)
        return true;
    }
    else if (x < t->item)
    {
      return contains(x, t->left)
    }
    else
    {
      return contains(x, t->right)
    }
    else return 0;
  }
}
struct tree_node *Initialize(struct tree_node *t)
{
  struct *getnewnode;
  getNewNode = (node *)malloc(sizeof(struct))
}

int Empty(struct tree_node *t)
{

  // Test if empty
  return 0;
}

int Full(struct tree_node *t)
{
  // Test if full
  return 0;
}
