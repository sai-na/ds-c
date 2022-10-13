#include<stdio.h>
#define MaxSize 5
int queue [5];
int rear = -1;
int front = 0 ;







void display(){

int i;
printf("The queue is :");
for(i=front; i<=rear ; i++)
printf("%d \n" , queue[i]);

}







int isFull(){

if(rear >= MaxSize -1) // array index
	return 1 ;
else return 0 ;

}




int isEmpty(){

if(front > rear)
	return 1;
else return 0;

}



void enqueue(int a ){

if( isFull())
  printf("Queue Overfolw");

else{
rear++;
queue [rear] = a ;
display();

}



}

void dequeue() {

if(isEmpty())
	printf("Queue underflow");
else {
printf(" The popped element element is %d" , queue[front]);
	front++;
 	display();
}


}


void main(){

int choice , a ;

do{

printf("Enter your choice 1. Enqueue 2. Dequeue 3. Display 4 .Exit");

scanf("%d" , &choice);

switch(choice){

case 1 : printf("Enter element to be added to the queue ");
 	 scanf("%d" , &a);
 	 enqueue(a);
 	 break;

case 2 :  dequeue(); 
	break;

case 3: display(); 
	 break;

case 4 : break;




}
}


while(choice!= 4);

}






