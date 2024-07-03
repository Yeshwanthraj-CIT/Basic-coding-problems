/*Write a C program to represent the bus stops in a bus route as circularly linked list. Write a
function to find the number of bus stops the bus has to cross before reaching the spot from
where a particular passenger is trying to find where the bus is.*/




#include<stdio.h>           //Usual header file inclusion.
#include<stdlib.h>          //Included for using Dynamic memory allocation.

struct node                 //Declaring a self-referential structure in a global position.
{
    int stop_no;
    struct node* next;
};

//To make a circular linked list, this function is declared.

void add_bus_stop(struct node *head,int passenger_stop)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    struct node *last=head;         //address of head node in last node makes a circular linked list.
    new->stop_no=passenger_stop;    //To insert a new bus stops.
    new->next=last->next;           
    last->next=new;                 //Lastly added bus stop will be the last node now.
}

//To locate where the bus and the passenger is (from the departure point).

int locate(struct node *head,int destination)
{
    struct node *now=head->next;
    int no_of_stops=0;              //Initiation.
    while(now!=head)
    {
        if(now->stop_no==destination)
        {
            break;                  //If next stop is destination, it breaks the iteration and exists.
        }
        else
        {
            now=now->next;          //To increment iteration.
            no_of_stops++;          //To count the stops.
        }
    }

    /*If the bus and the passenger are at the same stop, The value of "now" and
    "head" are same so that, the iteration would be skipped and returns the no_of_stops as '0'.
    (as initiated before).*/

    return no_of_stops;
}

void main()
{
    int n,m,bus,i,passenger,for_bus,for_passenger,in_reach,out_reach;
    printf("Enter the total no. of bus stops in that route\n");
    scanf("%d",&n);                                                 //User Input for bus stops.
    printf("\nEnter where the bus is\n");
    scanf("%d",&bus);                                               //User Input for current location of a bus.
    struct node *head=(struct node*)malloc(sizeof(struct node));    //Memory allocation.       

    for(i=1;i<=n;i++)
    {
        add_bus_stop(head,i);                            //Adding bus stops.
    }

    printf("\nEnter your stop\n");
    scanf("%d",&m);                                     //User input for passenger location.
    passenger=m;

    //If the bus or the passenger is out of total no.of stops in that route.  
    if(bus>n||passenger>n)
    {
        printf("Data Invalid.");
    }

    else
    {

    //Function call to find stops between bus and destination.
    for_bus=locate(head,bus); 

    //Function call to find stops between passenger and destination.                          
    for_passenger=locate(head,passenger);

    //To count the total no. of stops if the bus has not reached the passenger's bus stop.
    if(bus<passenger)
    {
        in_reach=for_bus-for_passenger;
        printf("You have to wait for %d stop(s)",in_reach);
    }

    //To count the total no. of stops if the bus had already reached the passenger's bus stop.
    else
    {
        out_reach=for_bus+for_passenger;
        printf("You have to wait for %d stop(s)",out_reach);
    }

    }

    //Code terminates.
}