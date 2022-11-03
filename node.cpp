#include <iostream>
//#include <bits/stdc++.h>
using namespace std;


//time for the generic


//creating all of the related objects for the node
class Node
{    

public:
    int data;

    //pointer to the next node
    Node* next;

    //pointer to previous node
    Node* prev;

};




void insertFront(Node** head_ref, int new_data)
{
    //allocate the Container/node
    Node* intContainer = new Node();

    //inserting the data into the node
    intContainer -> data = new_data;

    //next of Container/node as head, previous as NULL
    intContainer ->next = (*head_ref);
    intContainer -> prev = NULL;

    //changing the prev of head node to the Container/node
    if((*head_ref) != NULL)
    {
        (*head_ref) ->prev = intContainer;
    }

    //move the head to point to the Container/node
    (*head_ref) = intContainer;
}

void insertEnd(Node** head_ref, int new_data)
{
    //allocate the new Container/node
    Node* intContainer = new Node();

    Node* last = *head_ref;

    //insert data in the container
    intContainer -> data = new_data;

    //since this is the last node in the deal, make its next = NULL
    intContainer ->next = NULL;

    //if the list is empty (it shouldn't be (really I COULD delete the method above and make this the only method but nah)) make the new node the head
    if(*head_ref == NULL)// THIS SHOULDN'T HAPPEN (GOD FORBID) BUT KNOWING ME LETS 
    {
        intContainer ->prev = NULL;
        *head_ref = intContainer;
        return;
    }

    //if it isn't empty (LIKE IT SHOULD BE) traverse the list until the end
    while(last -> next != NULL)
    {
        last = last -> next;
    }

    //changing the next of the last node
    last -> next = intContainer;

    //making the last node as the previous of the Container
    intContainer ->prev = last;

    return;
}

//I made this thinking I could delete this way, turns out I cant and im lazy
void deleteNode(Node** head_ref, Node* del)
{
    //if both head and deletion point == null then
    if(*head_ref == NULL || del == NULL)
    {
        return;
    }

    //Deleting the head node
    if(*head_ref == del)
    {
        *head_ref = del ->next;
    }

    //THIS WILL ONLY HAPPEN IF THE NODE THAT HAS TO BE DELETED ISN'T THE NEXT NODE
    if(del -> next != NULL)
    {
        del -> next -> prev = del ->prev;
    }

    //THIS WILL ONLY CHANGE THE PREV IF THE FIRST NODE ISN'T GETTING DELETED
    if(del -> prev != NULL)
    {
        del->prev->next = del->next;
    }

    //TIME TO FREE THE MEMORY EVEN THOUGH I HAVE 64 GIGS HAHAHAHAHAHA BAD COMPUTERS LMAO I RATIO BAD COMPUTERS L + BOZO
    free(del);
    return;
}

//the right way to delete based off of a value in the node
void deleteBoV(Node** head_ref, int value)
{
    //if the list is empty
    if((*head_ref) == NULL)
    {
        return;
    }

    Node* current = *head_ref;
    Node* next;

    //traverse the list until the end has been reached
    while (current != NULL)
    {

        //if the value of the value is found
        if (current -> data == value)
        {
            //save the current next node in the pointer next
            next = current ->next;

            //delete the node pointed to by current
            deleteNode(head_ref, current);

            //update the current pointer
            current = next;
        }

        else
        {
            current = current -> next;
        }
        

    }
    
}

void printList(Node* node)
{
    //22 should be at the front and 95 should be at the back for the final print.

    Node* last;

    cout << "\nThe list contains \n";

    while (node != NULL)
    {
        cout << " " << node ->data <<" ";
        last = node;
        node = node -> next;
    }
    
}

int main()
{


    /* CODE NOT NEEDED BECAUSE IT DOESN'T NEED TO BE ASKING FOR INPUTS
    int input;
    //start with the list empty
    Node* head = NULL;

    //get the number from the user
    cout << "Enter a number: ";
    cin >> input;

    //insert into front
    insertFront(&head, input);

    cout << "Enter another number: ";
    cin >> input;
    insertFront(&head, input);

    cout << "Enter another number: ";
    cin >> input;
    insertEnd(&head, input);

    cout << "Enter another number:";
    cin >> input;
    insertFront(&head, input);

    cout << "List created is: ";
    printList(head);  

    cout << "Enter number to be deleted: ";
    cin >> input;
    deleteBoV(&head, input);

    cout << "Enter number to be deleted: ";
    cin >> input;
    deleteBoV(&head, input);

    cout << "Enter number to be deleted: ";
    cin >> input;
    deleteBoV(&head, input);

    cout << "Enter another number:";
    cin >> input;
    insertFront(&head, input);

    cout << "Enter number to be deleted: ";
    cin >> input;
    deleteBoV(&head, input);

    cout << "List created is: ";
    printList(head); 
    */

   Node* head = NULL;

   //methods were designed to be given the head pointer
   //then the data we want to insert into the node.

   //insertion
   insertFront(&head, 33);
   insertFront(&head, 57);
   insertEnd(&head, 85);
   insertFront(&head, 95);

   //print
   printList(head);
   
    //Delete
    deleteBoV(&head, 57);
    deleteBoV(&head, 33);
    deleteBoV(&head, 33);

    //insert again
    insertFront(&head, 22);

    //delete again
    deleteBoV(&head, 95);

    //print again
    printList(head);


    return 0;
}

