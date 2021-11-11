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

void inorder(struct tree_node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->item);
    inorder(root->right);
  }
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
struct tree_node *minValueNode(struct tree_node *t)
{
  struct tree_node *current = t;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct tree_node *Remove(int x, struct tree_node *t)
{
  // base case
  if (t == NULL)
    return t;
  if (x < t->item)
    t->left = Remove(x, t->left);
  else if (x > t->item)
    t->right = Remove(x, t->right);
  else
  {
    if (t->left == NULL)
    {
      struct tree_node *newnode = t->right;
      free(t);
      return newnode;
    }
    else if (t->right == NULL)
    {
      struct tree_node *newnode = t->left;
      free(t);
      return newnode;
    }
    struct tree_node *newnode = minValueNode(t->right);
    t->item = newnode->item;
    t->right = Remove(newnode->item, t->right);
  }
  return t;
}

int Contains(int x, struct tree_node *t)
{
  if (t == NULL || t->item == x)
    return 1;
  else if (x > t->item)
    return Contains(x, t->right);
  else
    return Contains(x, t->left);
}

struct tree_node *Initialize(struct tree_node *t)
{
  return t = NULL;
}

int Empty(struct tree_node *t)
{
  if (t == NULL)
    return 1;
  else
    return 0;
}

int Full(struct tree_node *t)
{
  if (t == NULL)
    return 1;
  if (t->left == NULL && t->right == NULL)
    return 1;
  if ((t->left) && (t->right))
    return (Full(t->left) && Full(t->right));
  return 0;
  // Test if full
  return 0;
}
