#include <iostream>

using namespace std;

// Declare Node
struct Node {
    string task;
    string doer;
    string date;

    struct Node* next;
};

// Declare starting node
struct Node* head = NULL;

struct Node* getTDDNode(string getTask, string getDoer, string getDate){
    struct Node* getData = new Node; //create a node
    getData->task = getTask; // set Task
    getData->doer = getDoer; // set Doer
    getData->date = getDate; // set Date
    getData->next = NULL; // set next to NULL
    return getData;
};

// Insert task at position "pos", SINGLY LINKED LIST LIMITATIONS APPLIED
void InsertGoal(string inTask, string inDoer, string inDate, int pos) {
    struct Node* temp1 = getTDDNode(inTask, inDoer, inDate);
    if (pos == 1){
        temp1->next = head; // set the newly created Node to whatever the existing head is
        head = temp1; // make it the inital head for the link
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < pos - 2; i++) {
        temp2 = temp2->next; // set the new node to the next of the head
    }
    temp1->next = temp2->next; // set the next of the newly created node at the next of the (n-1)th node
    temp2->next = temp1; // set the the next of (n-1)th node to point to the newly created node
};
void DisplayCurrent(){
    if(head == NULL){
        cout <<"[WARNING] You have no tasks to do.\n"<<endl;
        return;
    }
    struct Node *temp=head;
    int i = 1;
    cout << "[INFO] Tasks to do:\n";
    while(temp!=NULL){
        cout << i++ << ". " << temp->task << " by " << temp->doer << " until " << temp->date <<".\n";
        temp = temp->next;
    }
    cout<<endl;
};
// Deletes node at position "pos"
void DeleteGoal(int pos){
    if(head==NULL){
        cout<<"[WARNING] You have no tasks listed.\n"<<endl;
        return;
    }
    struct Node* temp = head;
    if(pos == 1)
    {
        head = temp->next; // head now points to the second node.
        cout << "[WARNNG] " << temp->task << " by " << temp->doer << " until " << temp->date << " is removed" << "\n" << endl;
        free(temp);
        return;
    }
    int i;
    for( i = 1; i< pos - 1; i++)
        temp = temp->next; // temp points to (pos-1)th Node
    struct Node* temp2 = temp->next; // nth Node
    temp->next = temp2->next; // (n+1)th Node
    cout << "[WARNNG] " << temp2->task << " by " << temp2->doer << " until " <<  temp->date << " is removed." << "\n" << endl;
    free(temp2); // delete temp2
};

int main() {

    cout << "\nWorkflow System\n" << endl;
    cout << "[ATTENTION] \n" << endl;
    
    InsertGoal("Task1", "Name1", "09-01-21", 1);
    InsertGoal("Task2", "Name2", "12-10-21", 2);
    InsertGoal("Task3", "Name3", "08-9-21", 3);

    DisplayCurrent();

    DeleteGoal(2);

    DisplayCurrent();
    
    DeleteGoal(1);

    InsertGoal("Task4", "Name4", "06-05-21", 1);

    DisplayCurrent();

    DeleteGoal(1);
    DeleteGoal(1);

    DisplayCurrent();

    DeleteGoal(1);

    return 0;
}
