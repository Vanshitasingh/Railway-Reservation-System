#include <iostream>
#include <string>
using namespace std;
int trainnumbers[] = {1111,1211,1311,1411,1511};
string sources[]={"Mumbai","Pune","Chennai","Delhi","Kolkata"};
string destinations[] = {"Pune","Nashik","Hyderabad","Chandigarh","Delhi"};
int cost_of_ticket[] = {250,200,350,200,500};

class Seat
{
    public:
    string name, ticketnumber;
    int age,cost;
    Seat* next=NULL;
};

class TrainNo
{
    public:
    int number,cost,position = 0;
    string source, destination;
    TrainNo* next = NULL;
    Seat* seatnext= NULL;
};

void appendTrain(TrainNo** head_ref, int new_num, string source,string dest,int cost);
void display(TrainNo *p,int trainnumber,string ticketno);
void ticketdetails(TrainNo *p, Seat *s);
void reserveseat(TrainNo *head_ref);
void getticketdetails(TrainNo *head, int choice);
void cancel(TrainNo **headref,int trainnumber,string ticketno);
TrainNo *gettrainno(TrainNo *p,int trainno);
Seat *getseat(Seat *s,string ticketno);

void appendTrain(TrainNo** head_ref, int new_num, string source,string dest,int cost)
{

    TrainNo* new_train = new TrainNo();
    TrainNo *last = *head_ref;
    new_train->number = new_num;
    new_train->source = source;
    new_train->destination = dest;
    new_train->cost = cost;
    new_train->next = NULL;
    new_train->seatnext = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_train;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_train;
    return;
}

void ticketdetails(TrainNo *p, Seat *s)
{
        cout<<"\n---------------TICKET DETAILS-------------------";
        cout<<"\n\nTrain Number: "<<p->number;
        cout<<"\nSource: "<<p->source;
        cout<<"\nDestination: "<<p->destination;
        cout<<"\nTicket No: "<<s->ticketnumber;
        cout<<"\nTicket Cost:"<<p->cost;
        cout<<"\nPassenger name: "<<s->name;
        cout<<"\nPassenger age: "<<s->age;
        cout<<"\n------------------------------------------------\n\n";
}

TrainNo *gettrainno(TrainNo *p,int trainno)
{
    while(p!=NULL)
    {
        if(p->number==trainno)
            return p;
        p = p->next;
    }
    return NULL;
}
Seat *getseat(Seat *s,string ticketno)
{
    while(s!=NULL)
    {
        if(s->ticketnumber == ticketno)
            return s;
        s = s->next;
    }
    return s;
}/*
void reserveseat(TrainNo *head_ref)
{
    string name,ticketnumber;
    char t;
    int age,trainno,seatnum = 0;
    cout<<"\nTrain no: ";
    cin>>trainno;
    cin.ignore();
    TrainNo *p1 = head_ref;
    TrainNo *p = gettrainno(p1,trainno);
    if(p == NULL)
    {
    return;
    }
    cout<<p->number<<" Source: "<<p->source<<"     Destination: "<<p->destination<<endl;
    cout<<"\nPassenger name: ";
    getline(cin,name);
    cout<<"Passenger age: ";
    cin>>age;
    cout<<"Confirm Reservation? (y/n)";
    cin>>t;
    if(t=='n')
    {
        cout<<"\nReservation cancelled";
        return;
    }
    Seat **new_seat = &(p->seatnext);
   // Seat *last= *h;
    if (*new_seat == NULL)             //First seat
    {
        Seat* new_seat = new Seat();
        new_seat->name = name;
        new_seat->age = age;
        new_seat->next = NULL;
        ticketnumber = to_string(trainno)+"S"+to_string(seatnum);
        new_seat->ticketnumber = ticketnumber;
        ticketdetails(p,new_seat);
        cout<<"\n Ticket number: "<<ticketnumber;
        cout<<"\nSeat reserved successfully ";
        seatnum+=1;
        return;
    }
    Seat *current=*new_seat;
    Seat *previous;
    while (current!= NULL)
       {
           previous=current;
           current= current->next;
           seatnum+=1;
           cout<<" "<<seatnum;
       }
    current = new Seat();
    current->name = name;
    current->age = age;
    current->next = NULL;
    ticketnumber = to_string(trainno)+"S"+to_string(seatnum);
    current->ticketnumber = ticketnumber;
    previous->next = current;
    ticketdetails(p,previous);
    cout<<"\n Ticket number: "<<ticketnumber;
    cout<<"\nSeat reserved successfully ";
    return;
}
*/
void reserveseat(TrainNo *head_ref)
{
    string name,ticketnumber;
    char t;
    int age,trainno,seatnum = 0;
    cout<<"\nTrain no: ";
    cin>>trainno;
    cin.ignore();
    TrainNo *p1 = head_ref;
    TrainNo *p = gettrainno(p1,trainno);
    if(p == NULL)
    {
    return;
    }
    cout<<p->number<<" Source: "<<p->source<<"     Destination: "<<p->destination<<endl;
    cout<<"\nPassenger name: ";
    getline(cin,name);
    cout<<"Passenger age: ";
    cin>>age;
    cout<<"Confirm Reservation? (y/n)";
    cin>>t;
    if(t=='n')
    {
        cout<<"\nReservation cancelled";
        return;
    }
    Seat* new_seat = new Seat();
    new_seat->name = name;
    new_seat->age = age;
    new_seat->next = NULL;
    Seat **h = &(p)->seatnext;
    Seat *last= *h;
    if (*h == NULL)             //First seat
    {
       // *h->position =1;
        ticketnumber = to_string(trainno)+"S"+to_string(seatnum);
        new_seat->ticketnumber = ticketnumber;
        *h = new_seat;
        cout<<p->seatnext->name;
        ticketdetails(p,*h);
        cout<<"\n Ticket number: "<<ticketnumber;
        cout<<"\nSeat reserved successfully ";
        seatnum+=1;
       // cout<<" "<<seatnum[index];
        return;
    }
    while (last->next != NULL)
       {
           last = last->next;
           seatnum+=1;
           cout<<" "<<seatnum;
       }
    ticketnumber = to_string(trainno)+"S"+to_string(seatnum);
    new_seat->ticketnumber = ticketnumber;
    last->next = new_seat;
    ticketdetails(p,last->next);
    cout<<"\n Ticket number: "<<ticketnumber;
    cout<<"\nSeat reserved successfully ";
    return;
}


void getticketdetails(TrainNo *head,int choice)
{
    int trainnumber;
    string ticketno;
    cout<<"\nTrain number: ";
    cin>>trainnumber;
    cin.ignore();
    cout<<"\nTicket number: ";
    cin>>ticketno;
    if (choice==2)
       {
           cancel(&head,trainnumber,ticketno);
       }
    if(choice==3)
        display(head,trainnumber,ticketno);
}
void cancel(TrainNo **headref,int trainnumber,string ticketno)
{
    display(*headref,trainnumber,ticketno);
    TrainNo *p = *headref;
    p = gettrainno(p,trainnumber);
    if(p == NULL)
        return;
    char ch;
    cout<<"\nAre you sure you want to cancel reservation?(y/n) ";
    cin>>ch;
    if(ch=='n')
    {
        cout<<"\nReservation is not cancelled";
        return;
    }
        Seat *s = p->seatnext;
        Seat *t = s;
        if(s->ticketnumber == ticketno)
        {
            Seat*temp = s;
            p->seatnext = s->next;
            cout<<"Reservation cancelled successfully ";
            free(s);
            return;
        }
        while(s->ticketnumber != ticketno)
        {
            t = s;
            s = s->next;
        }
        if(s!=NULL)
        {
            t->next = s->next;
            cout<<"Reservation cancelled successfully ";
            free (s);
            return;
        }
        cout<<"\nTicket number not found. Try Again";
        return;
}

void display(TrainNo *p,int trainnumber,string ticketno)
{

    p = gettrainno(p,trainnumber);
    if(p==NULL)
    {
    cout<<"\nTrain Number not found. Try Again";
    return;
    }
        Seat *s = p->seatnext;
        s = getseat(s,ticketno);
        if(s == NULL)
        {
            cout<<"\nTicket number not found. Try Again";
            return;
        }
        ticketdetails(p,s);
        return;
}

void printList(TrainNo *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->number<<" "<<node->source<<" "<<node->destination<<" "<<node->cost<<endl;
        node = node->next;
    }
}


int main()
{
    TrainNo *head = NULL;
    int len = sizeof(trainnumbers)/sizeof(trainnumbers[0]);
    for(int i=0;i<len;i++)
    {
            appendTrain(&head,trainnumbers[i],sources[i],destinations[i],cost_of_ticket[i]);
    }
    //printList(head);
    int choice=0;
    while(choice!=4){
    cout<<"**************************************************";
    cout<<"\n..........RAILWAY RESERVATION SYSTEM..............";
    cout<<"\n**************************************************";
    cout<<"\n1 - Reserve a ticket \n2 - Cancel reservation \n3 - Display details \n4 - Exit\n\n";
    cout<<"\nWhat would you like to do: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            reserveseat(head);
            break;
        case 2:
            getticketdetails(head,choice);
            break;
        case 3:
            getticketdetails(head,choice);
            break;
        case 4:
            cout<<"\nBye! Have a Nice Day! :)";
            break;
        default:
            cout<<"\nInvalid Choice";
    }
    cout<<"\n\n";
    }
}
