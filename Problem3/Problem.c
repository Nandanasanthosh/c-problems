#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
    int info;
    struct node *link;
}*p, *start, *p1, *temp;
void insert_beg();
void insert_end();
void insert_mid();
void delete_beg();
void delete_end();
void delete_mid();
void display();
void main()
{
    int choose;
    clrscr;
    while(1) {
        printf("1.insert at front\n2.insert at end\n3.insert at any position\n4.delete from front\n5.delete from end\n6.delete from any position\n7.display\n8.exit\n");
        scanf("%d, &choose");
        switch(choose)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_mid();
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_mid();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        //default:
           // printf("invalid option");
        }
    }

}
void insert_beg()
{
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter the data to insert");
    scanf("%d",temp->info);
    temp->link=start;
    start=temp;
}
void insert_end()
{
    p=start;
    if(p==NULL) {
        printf("List is empty");
        return;
    }
    printf("Enter the element to insert");
    scanf("%d",temp->info);
    if(p->link==NULL)
    {
        p->link=temp;
        temp->link=NULL;
        return;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    while(p->link!=NULL)
    {
        p=p->link;
    }

    p->link=temp;
    temp->link=NULL;
}
void insert_mid()
{
    p=start;
    int key;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the key element");
    scanf("%d",&key);
    if(p==NULL) {
        printf("List is empty");
        return;
    }
    while((p->info!=key)&&(p->link!=NULL))
    {
        p1=p;
        p=p->link;
    }
    if(p->link==NULL)
    {
        printf("Key not found");
    }
    else
    {
        printf("Enter the element to insert");
        scanf("%d",temp->info);
        p1->link=temp;
        temp->link=p;
    }
}
void delete_beg()
{
    p=start;
    if(p==NULL) {
        printf("List is empty");
    }
    p1=p->link;
    printf("%d id deleted",p->info);
    free(p);
}
void delete_end()
{
    p=start;
    if(p==NULL)
    {
        printf("List is empty");
        return;
    }
    if(p->link==NULL)
    {
        printf("%d is deleted",p->info);
        free(p);
        return;
    }
    while(p->link!=NULL)
    {
        p1=p;
        p=p->link;
    }
    printf("%d is deleted",p->info);
    p1->link=NULL;
    free(p);
}
void delete_mid()
{
    int key;
    p=start;
    if((p->info==key)||(p==NULL)) {
        printf("Deletion cant be performed");
        return;
    }
    while(p->info!=key || p->link!=NULL)
    {
        p1=p;
        p=p->link;
    }
    if(p->link==NULL)
    {
        printf("Key not found");
        return;
    }
    else
    {   printf("%d is deleted", p->info);
        p1->link=p->link;
        free(p);
    }
}
void display()
{
    p=start;
    if(p==NULL)
    {
        printf("List is empty");
    }
    do
    {   printf("%d\t",p->info);
        p=p->link;
    } while(p->link!=NULL);
}
