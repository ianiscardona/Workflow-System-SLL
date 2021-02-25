#include <iostream>
#include <conio.h> // for clearing whitespaces and pausing the code

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

// Create Node
struct Node* getTDDNode(string getTask, string getDoer, string getDate){
    struct Node* getData = new Node; //create a node
    getData->task = getTask; // set Task
    getData->doer = getDoer; // set Doer
    getData->date = getDate; // set Date
    getData->next = NULL; // set next to NULL

    return getData;
};

// Insert task at position "pos", SINGLY LINKED LIST LIMITATIONS APPLIED
void InsertGoal(string inTask, string inDoer, string inDate, int pos){
    struct Node* temp1 = getTDDNode(inTask, inDoer, inDate);
    if (pos == 1){
        temp1->next = head; // set the newly created Node to whatever the existing head is
        head = temp1; // make it the inital head for the link
        cout << "\n[INFO] Task added\n";
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < pos - 2; i++){
        temp2 = temp2->next; // set the new node to the next of the head
    }
    temp1->next = temp2->next; // set the next of the newly created node at the next of the (n-1)th node
    temp2->next = temp1; // set the the next of (n-1)th node to point to the newly created node
    cout << "\n[INFO] Task added\n";
};

// Insert Task at the start
void InsertStart(string inTask, string inDoer, string inDate){
    struct Node* temp1 = getTDDNode(inTask, inDoer, inDate);
    if(head == NULL){
        head = temp1; // make it the initial head of the link
        cout << "\n[INFO] Task added.\n";
        return;
    }
    temp1->next = head; // set the newly created Node to whatever the existing head is
    head = temp1; // make it the initial head of the link
    cout << "\n[INFO] Task added.\n";
};

// Insert Node at the end
void InsertEnd(string inTask, string inDoer, string inDate){
    struct Node* temp1 = head; // point to head to keep track of the position
    struct Node* temp2 = getTDDNode(inTask, inDoer, inDate);
    temp2->next = NULL; // isolate the node

    if(head == NULL){
        head = temp2;
        cout << "\n[INFO] Task added\n";
        return;
    }
    while (temp1->next != NULL){
        temp1 = temp1->next; // find the end node 
    }
    temp1->next = temp2;
    cout << "\n[INFO] Task added\n";
};

// Edit list by putting a Node in another position
void EditGoalList(int currPos, int newPos){
    if(head == NULL){ // list is empty
        cout << "\n[WARNING] You have no task listed.\n\n";
        return;
    }
    if(currPos == newPos){ // the same position is entered
        cout << "\n[WARNING] Invalid Input.\n";
        cout << "\n[INFO] Task Order remains the same.\n\n";
        return;
    }
    struct Node* temp1 = head; // set temp1 to head
    struct Node* temp2 = NULL; // create temp2
    if(currPos == 1){ // move the first node
        head = temp1->next; // set the second node as the head
        temp2 = temp1;
    }else{
        for(int i = 0; i < currPos - 2; i++){
            temp1 = temp1->next;
        }
        temp2 = temp1->next; // set temp2 as the next of temp1
        temp1->next = temp2->next; // set the next of temp1 to the next of temp2
    }
    struct Node* temp3 = head; // set temp3 as head
    if(newPos == 1){ // simply set the selected node as the head
        temp2->next = head;
        head = temp2;
        cout << "\n[WARNING] Task moved.\n\n";
        return;
    }
    for (int j = 0; j < newPos - 2; j++){ // find the (pos-1)th position
        temp3 = temp3->next;
    }
    temp2->next = temp3->next; // put the selected node to the new position
    temp3->next = temp2; // set the next of temp3 as the selected node
    cout << "\n[WARNING] Task moved.\n\n";
};

// Display Current List of Tasks
void DisplayGoalList(){
    if(head == NULL){ // list is empty
        cout <<"\n[WARNING] You have no tasks to do.\n\n";
        return;
    }
    struct Node *temp=head; // create a pointer that will display the current task node
    int i = 1;
    cout << "\n[INFO] Tasks to do:\n";
    while(temp!=NULL){
        cout << i++ << ". " << temp->task << " by " << temp->doer << " until " << temp->date <<".\n"; // display and increment
        temp = temp->next;
    }
    cout << "\n--------------End of List.--------------\n\n";
};

// Displays the Current number of tasks
void CountGoalList(){
    int count = 0;
    if (head == NULL){ // list is empty
        cout << "[WARNING]You have no tasks to do.\n\n";
        return;
    };
    struct Node* temp = NULL; // create pointer
        temp = head; // point to head
    while(temp != NULL){ // find the end of list
        count++;
        temp = temp->next;
    }
    if(count != 0){ // print every task node
        cout << "\n[INFO] The number of current task/s to do is: " << count << "\n\n";}
    else{
        cout << "[WARNING]You have 0 tasks to do.\n\n";
    }
};

// Marks task #1 as done and removes it from list
void GoalDone(){
	if(head == NULL){
        cout << "\n[WARNING] All tasks are done.\n\n";
        return;
	}	
	struct Node* temp = head;
    if(head != NULL){
        head = temp->next; // head now points to the second node.
        cout << "\n[INFO] " << temp->task << " by " << temp->doer << " until " << temp->date << " is finished\n";
        cout << "[WARNING] Task will now be deleted.\n\n";
        free(temp);
        return;
	}
};

// Deletes node at position "pos"
void DeleteGoal(int pos){
    if(head==NULL){
        cout << "\n[WARNING] You have no tasks to delete.\n\n";
        return;
    }
    struct Node* temp1 = head;
    if(pos == 1){
        head = temp1->next; // head now points to the second node.
        cout << "[WARNNG] " << temp1->task << " by " << temp1->doer << " until " << temp1->date << " is removed" << "\n" << endl;
        free(temp1);
        return;
    }
    for(int i = 0; i < pos - 2; i++){
        temp1 = temp1->next; // temp1 points to (pos-1)th Node
    }
    struct Node* temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    cout << "[WARNING] " << temp2->task << " by " << temp2->doer << " until " <<  temp2->date << " is removed." << "\n" << endl;
    free(temp2); // delete temp2
};

// Quick Delete all current tasks
void DeleteAllGoal(){
    struct Node* temp1 = NULL;
    if(head == NULL){ // list is empty
        cout << "\n[WARNING] You have no tasks to delete.\n\n";
        return;
    }
    while(head != NULL){ // delete from start to end
        temp1 = head;
        head = head->next;
        free(temp1);
    }
    cout << "\n[WARNING] All Tasks are deleted successfully.\n\n";
};

// Workflow System - Singly Linked List (Main Program)
int main(){

    int SelectFunc;
    int GivenPos;
    string GivenTask, GivenName, GivenDeadline;

    cout << "\n\n------------ WORKFLOW MANAGEMENT SYSTEM ----------------\n\n";

    do{
        cout << "[INSTRUCTIONS]\n1. Select the corresponding number of the desired function.\n";
        cout << "\n[1] Insert Task\n[2] Edit List\n[3] Mark Task as Done\n[4] Display task\n[5] Delete Task\n[6] About us\n[7] Exit\n";
        cout << "\n[ATTENTION] Select the corresponding number: ";
        cin >> SelectFunc;

        switch(SelectFunc)
            {
            case 1:
                int SelectInFunc;
                cout << "\n[1] Insert Task\n[2] Quick Insert Task (Start)\n[3] Quick Insert Task (End)\n";
                cout << "\n[ATTENTION] Select the corresponding number: ";
                cin >> SelectInFunc;

                switch (SelectInFunc)
                {
                case 1:
                    cout << "\n[WARNING] If this is the first task, please input 1 on position.\n\n";
                    cout << "Enter Task: ";
                    cin.ignore();
                    getline(cin, GivenTask);
                    cout << "Enter Name: ";
                    getline(cin, GivenName);
                    cout << "Enter Deadline: ";
                    getline(cin, GivenDeadline);
                    cout << "Enter Position: ";
                    cin >>GivenPos;
                    InsertGoal(GivenTask, GivenName, GivenDeadline, GivenPos);
                    cout << "\n[ATTENTION] Press Enter to Continue.\n";
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    cin.ignore();
                    cout << "Enter Task: ";
                    getline(cin, GivenTask);
                    cout << "Enter Name: ";
                    getline(cin, GivenName);
                    cout << "Enter Deadline: ";
                    getline(cin, GivenDeadline);
                    InsertStart(GivenTask, GivenName, GivenDeadline);
                    cout << "\n[ATTENTION] Press Enter to Continue\n";
                    cin.get();
                    break;
                case 3:
                    cin.ignore();
                    cout << "Enter Task: ";
                    getline(cin, GivenTask);
                    cout << "Enter Name: ";
                    getline(cin, GivenName);
                    cout << "Enter Deadline: ";
                    getline(cin, GivenDeadline);
                    InsertEnd(GivenTask, GivenName, GivenDeadline);
                    cout << "\n[ATTENTION] Press Enter to Continue.\n";
                    cin.get();
                    break;

                default:
                    cin.ignore();
                    cout << "\n[WARNING] Invalid Input. Please Try Again.\n";
                    cout << "\n[ATTENTION] Press Enter to Continue.\n";
                    cin.get();
                    break;
                }
                break;
            case 2:
                int editCurrPos, editNewPos;
                cout << "\n[INFO] Edit List\n";
                cout << "Enter initial task number: ";
                cin >> editCurrPos;
                cout << "Enter new task number: ";
                cin >> editNewPos;
                EditGoalList(editCurrPos, editNewPos);
                cout << "[ATTENTION] Press Enter to Continue.\n";
                cin.ignore();
                cin.get();
                break;
        	case 3:
        	    cin.ignore();
        		GoalDone();
        		cout << "[ATTENTION] Press Enter to Continue.\n";
                cin.get();
                break;
            case 4:
                cin.ignore();
                DisplayGoalList();
                cout << "[ATTENTION] Press Enter to Continue.\n";
                cin.get();
                break;
            case 5:
                int SelectDelFunc;
                cout << "\n";
                cout << "[WARNING] Make sure to Display first before deleting to avoid mistakes!";
                cout << "\n";
                cout << "\n[1] Delete Task\n[2] Quick Delete All Tasks\n";
                cout << "\n[ATTENTION] Select the corresponding number: ";
                cin >> SelectDelFunc;
                
                switch (SelectDelFunc)
                {
                case 1:
                    int delCurrPos;
                    cout << "Delete Task #: ";
                    cin >> delCurrPos;
                    DeleteGoal(delCurrPos);
                    cout << "[ATTENTION] Press Enter to Continue.\n";
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    cin.ignore();
                    DeleteAllGoal();
                    cout << "[ATTENTION] Press Enter to Continue.\n";
                    cin.get();
                    break;
                default:
                    cin.ignore();
                    cout << "\n[WARNING] Invalid Input. Please Try Again.\n";
                    cin.get();
                    break;
                }
                break;
            case 6:
                cout << "\n ABOUT US!!!\n"; // BACKGROUND NATIN
                cout << "\nGroup 5 Case Study (Singly Linked List)\n\n";
                cout << "Members:\n";
                cout << "\nLeader: Angelo Ian Michael Cardona = Creator of the Backbone of the Code \n";
                cout << "\nJohn Carlo Natividad = Code Tester and Handler of Code Display\n";
                cout <<	"\nJeroen Aaron Velasco = Presenter and Handler of Code Revisions\n";
                cout << "\n[ATTENTION] Press Enter to Continue.\n";
                cin.ignore();
                cin.get();
                break;
            case 7:
                cout << "\n[WARNING] Exit.\n";
                cout << "\n------------- THANK YOU --------------\n";
                break;
            default:
                cout << "\n[WARNING] Invalid Input. Please Try Again.\n";
                cout << "\n[ATTENTION] Press Enter to Continue.\n";
                cin.ignore();
                break;
    }
    }while(SelectFunc != 7);

    return 0;
}