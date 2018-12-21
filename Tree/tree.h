#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
typedef int entrytype;
typedef struct nodetype
{
    entrytype info;
    struct nodetype *right;
    struct nodetype *left;
}nt;

typedef nt* treetype;
int find(treetype *pt , entrytype *pe , entrytype key);
void insert(treetype *pt , entrytype *pe);
void clear(treetype *pt);
int depth(treetype *pt);
int size(treetype *pt);
void preorder(treetype *pt , void(*pvisit)(entrytype));
void inorder(treetype *pt , void(*pvisit)(entrytype));
void create (treetype *pt);
int isempty(treetype t);
int isfull(treetype t);
int del(treetype *pt , entrytype *pe , entrytype key);
#endif // TREE_H_INCLUDED
