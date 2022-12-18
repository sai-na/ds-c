#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node* next;
};
struct node *create(struct node *head,int coeff,int exp)
{
    struct node *temp,*flag;
    if(head==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->coeff=coeff;
        temp->exp=exp;
        temp->next=NULL;
        head=temp;
    }
    else
    {
     temp=head;
     while(temp->next!=NULL)
     temp=temp->next;   
     flag=(struct node*)malloc(sizeof(struct node));
     flag->coeff=coeff;
     flag->exp=exp;
     flag->next=NULL;
     temp->next=flag;
    }
    return head;
}
struct node* polyAdd(struct node*   p1,struct node *p2,struct node *sum)
{
    struct node *poly1=p1,*poly2=p2,*res;
    if(poly1!=NULL && poly2==NULL)
    {
        sum=poly1;
        return sum;
    }
    else if(poly1 == NULL && poly2!=NULL)
    {
        sum=poly2;
        return sum;
    }
    while(poly1!= NULL && poly2!=NULL)
    {
        if(sum == NULL)
        {
            sum=(struct node*)malloc(sizeof(struct node));
            res=sum;
        }
        else
        {
            res->next=(struct node*)malloc(sizeof(struct node));
            res=res->next;
        }
        if(poly1->exp<poly2->exp)
        {
         res->coeff=poly2->coeff;
         res->exp=poly2->exp;
         poly2=poly2->next;   
        }
        else if(poly1->exp>poly2->exp)
        {
         res->coeff=poly1->coeff;
         res->exp=poly1->exp;
         poly1=poly1->next;   
        }
        else if(poly1->exp==poly2->exp)
        {
         res->coeff=poly1->coeff+poly2->coeff;
         res->exp=poly1->exp;
         poly1=poly1->next;
         poly2=poly2->next;   
        }
    }
    while(poly1!=NULL)
    {
        res->next=(struct node*)malloc(sizeof(struct node));
        res=res->next;
        res->coeff=poly1->coeff;
        res->exp=poly1->exp;
        poly1=poly1->next;
    }
    while(poly2 != NULL)
    {
        res->next=(struct node*)malloc(sizeof(struct node));
        res=res->next;
        res->coeff=poly2->coeff;
        res->exp=poly2->exp;
        poly2=poly2->next;
    }
    res->next=NULL;
    return sum;
}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%dX^%d+",temp->coeff,temp->exp);
        temp=temp->next;
    }
     /*if(temp!=NULL) 
       printf(" + "); 
     else
      printf("\n");*/
    printf("0");
    printf("\n");
}
void main()
{
    struct node *p1=NULL, *p2=NULL,*sum=NULL;
    int ch,coeff,exp;
    while(1)
    {
        printf("\n*****Polynomial Addition*****\n");
        printf("\n1.First Polynomial");
        printf("\n2.Second Polynomial");
        printf("\n3.Add");
        printf("\n4.Exit");
        printf("\nEnter an Option : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("\nEnter coefficient : ");
            scanf("%d",&coeff);
            printf("\nEnter Exponent : ");
            scanf("%d",&exp);
            p1=create(p1,coeff,exp);
            break;
        case 2:printf("\nEnter co-efficient :");
            scanf("%d",&coeff);
            printf("\n Enter exponent :");
            scanf("%d",&exp);
            p2=create(p2,coeff,exp);
            break;
        case 3:
        { 
            sum=polyAdd(p1,p2,sum);
            printf("\n Polynomial 1\n");
            display(p1);
            printf("\nPolynomial 2\n");
            display(p2);
            printf("\nsum \n");
            display(sum);
            break;
        }
        case 4:exit(-1);
        default:printf("Invalid choice");
            break;
        }
    }
}
