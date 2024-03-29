#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct tree_node *getNewNode(int x) // Creating a newnode
{
  struct tree_node *newnode = malloc(sizeof(struct tree_node));
  newnode->item = x;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

void inorder(struct tree_node *root) // Not working i think the goal was to print.
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
  // Checking if t==null. If the list is empty
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
  else (t->item > x)
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
struct tree_node *minValueNode(struct tree_node *t) // Creating a new struct called current.
{
  struct tree_node *current = t;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct tree_node *Remove(int x, struct tree_node *t) // Function for removing
{
  // base case
  if (t == NULL)
    return t;

  // If the key to be deleted is smaller than the root's key, then it lies in left subtree
  if (x < t->item)
    t->left = Remove(x, t->left);

  // The same just for the right one.
  else if (x > t->item)
    t->right = Remove(x, t->right);

  // If the key is the same as the roots key then the node will be deleted.
  else
  {
    if (t->left == NULL) // For ones with only 1 or no childs.
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

      //Nodes with the two children gets the inorders
    }
    struct tree_node *newnode = minValueNode(t->right);
    t->item = newnode->item;                    // Copy the inorders successors contont to this node.
    t->right = Remove(newnode->item, t->right); // Delete the inorders successor.
  }
  return t;
}

int Contains(int x, struct tree_node *t) // Search function
{
  if (t == NULL)
    return 0;
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
