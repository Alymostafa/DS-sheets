#include <stdio.h>
#include <stdlib.h>
#include"tree.h"
void increment(entrytype x);
void display(entrytype x);
//void search(entrytype k);
int main()
{
    treetype t1;
    create(&t1);
    int x=41,y=0,m=0,z=65,q=11,w = 91;
    int i;
    for(i= 0 ; i<8 ; i++)
    {
    scanf("%d",&x);
    insert(&t1,&x);
    }
    //insert(&t1,&y);
    //insert(&t1,&z);
    //insert(&t1 ,&q);
    //insert(&t1 , &w);
    //preorder(&t1 , increment);
    //closetest(&t1 , 15);
    traverselevel(&t1);
    y=size(&t1);

   printf("%d",y);
   //inorder(&t1 , display);

    return 0;
}


void increment(entrytype x)
{
    printf("%d\n", x+1);

}

void display(entrytype x)
{

    printf("%d",x);
}




