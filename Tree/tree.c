#include "tree.h"
void create (treetype *pt)
{
    *pt = '\0';
}

int isempty(treetype t)
{
    return (!t);
}

int isfull(treetype t)
{
    return 0;
}

void inorder(treetype *pt , void(*pvisit)(entrytype))
{

    if(*pt)
    {
        inorder(&(*pt)->left , pvisit);
        (*pvisit)((*pt)->info);
        inorder(&(*pt)->right,pvisit);
    }
}

void preorder(treetype *pt , void(*pvisit)(entrytype))
{
    if(*pt)
    {
        (*pvisit)((*pt)->info);
        preorder(&(*pt)->left , pvisit);
        preorder(&(*pt)->right , pvisit);
    }
}



int size(treetype *pt)
{

    if(!*pt)
        return 0;
    else
    return (1+size(&(*pt)->left)+size(&(*pt)->right));
}

int depth(treetype *pt)
{
    if(!*pt)
        return 0;

        int x = depth(&(*pt)->left);
        int y = depth(&(*pt)->right);
        return (x>y) ? 1+x : 1+y;

}

void clear(treetype *pt)
{
    if(*pt)
    {
        clear(&(*pt)->left);
        clear(&(*pt)->right);
        free(*pt);
        *pt='\0';

    }
}


void insert(treetype *pt , entrytype *pe)
{
    nt *p , *pre, *cur;

    p = (nt*)malloc(sizeof(nt));

    p->info = *pe;
    p->left = '\0';
    p->right = '\0';
    if(!*pt)
    {
        *pt = p;
    }

    else
    {
        cur = *pt;
        while(cur)
        {
            pre  = cur;
            if(*pe < cur->info)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if(*pe < pre->info)
            pre->left = p;
        else
            pre->right = p;
    }
}


int find(treetype *pt , entrytype *pe , entrytype key)
{
     int found = 0;

    nt *p = *pt;

    while(p && !(found =(p->info == key)))
    {
        if(key < p->info)
            p = p->left;
        else
            p = p->right;
    }
        if(found)
            *pe = p->info;
        return found;

}


int del(treetype *pt , entrytype *pe , entrytype key)
{

    int found = 0;
    nt *q = *pt ,*r = '\0';
    while(q && !(found =(q->info == key))){
        r=q;
        if(key < q->info)
            q = q->left;
        else
            q = q->right;
    }
        if(found)
            *pe = q->info;

        if(!r)
        {
            deletenode(pt);
        }

        else if(key < r->info)
        {
            deletenode(&r->left);
        }
        else
            deletenode(&r->right);

}


void deletenode(treetype *pt)
{
    nt *q = *pt ,*r;

    if(!(*pt)->left)
        *pt = (*pt)->right;
    else if(!(*pt)->right)
        *pt = (*pt)->left;

    else
    {
        q = (*pt)->left;
        if(!q->right){
            (*pt)->info = q->info;
            (*pt)->left = q->left;
        }

        else{

            do{

            r=q;
            q = q->right;
            }while(q->right);
            (*pt)->info = q->info;
            r->right = q->left;
        }
    }

    free(q);

}


void closetest(treetype *pt , entrytype k)
{
    entrytype diff , s, tmp , b , r;
    nt *q = *pt;

    if(k < q->info)
    {
        diff = q->info - k;
    }
    else
        diff = k - q->info;

    while(q)
    {
        if(k < q->info)
        {
            b = q->info;
            q = q->left;
            tmp = b - k;

            if(tmp < diff)
                {
                s= tmp;
                r = b;
                }
            else{
                s = diff;
                r = b;
                }
        }

        else{
            if(k > q->info)
        {
            b = q->info;
            q = q->right;
            tmp = b - k;

            if(tmp < diff)
                {
                s= tmp;
                r = b;
                }
            else
            {
             s = diff;
             r = b;
            }
        }
        }



    }

    printf("%d" , r);


}

void traverselevel(treetype *pt)
{
    int h = depth(pt);
    int i;
    for(i=1; i <= h ;i++)
    {
        levelAUX(pt , i);
    }
}


void levelAUX(treetype *pt , int d)
{
    nt *q = *pt;
    if(q == '\0')
        return;
    else if(d == 1)
        printf("%d" , q->info);
    else if(d > 1)
    {
        levelAUX(&q->left , d-1);
        levelAUX(&q->right , d-1);
    }

}




































