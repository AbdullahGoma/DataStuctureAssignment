#include <iostream>
#include <string>

using namespace std;

struct Data
{
    string name;
    int degree[4];
    float average;
};

struct node
{
    Data data;
    node* next;
};

node* head = NULL;

void insertNode(Data Data)
{
    node* new_node;
    node* last;
    new_node = new node;
    (*new_node).data = Data;
    if(head == NULL)
    {
        head = new_node;
        new_node -> next = NULL;
    }
    else
    {
        last = head; 
        while(last -> next != NULL)
        {
            last = last -> next;
        }
        last -> next = new_node;
        new_node -> next = NULL;
    }
}

void displayall()
{
    node* currentNode;
    if(head == NULL)
    {
        cout << "There is no node to display." << endl << endl;
    }
    else
    {
        currentNode = head;
        while(currentNode != NULL)
        {
            cout << "Name : " <<currentNode -> data.name << endl;
            cout << "Degrees : ";
            for(int i = 0;i < 4;i++)
            {
                cout << currentNode -> data.degree[i] << "\t";
            }
            cout << endl << "Average : " << currentNode -> data.average << endl;
            currentNode = currentNode -> next;
        }
    }
}

void deleteAnyNode(string name)
{
    node* current;
    node* previous;
    current = head;
    previous = head;

    if(current -> data.name == name)
    {
        head = current -> next;
        free(current);
        return;
    }
    while(current -> data.name != name)
    {
        previous = current;
        current = current -> next;
    }
    //If name does not exist??
    previous -> next = current -> next;
    free(current);
}

void insertatbeginning(Data dat)
{
    node* new_node = new node;
    new_node -> data = dat;
    new_node -> next = head;
    head = new_node;
}

bool search(string key)
{
    node* current = head;

    while(current != NULL)
    {
        if(current -> data.name == key)
        {
            return true;
        }
        current = current -> next;
    }  
    return false;
    
}

void deletebeginning()
{
    if(head == NULL)
    {
        cout << "There is no node in the list." << endl;
    }
    else
    {
        node* firstNode = head;
        head = firstNode -> next;
        free(firstNode);
    }
}

void deleteend()
{
    // node* lastNode = head;
    // node* previous = head;
    // if(lastNode == NULL){
    //     cout << "There is no node in the list." << endl;
    //     return;
    // }
    // else if(lastNode -> next == NULL)
    // {
    //     lastNode = NULL;
    //     return;
    // }
    // while(lastNode -> next != NULL)
    // {
    //     previous = lastNode;
    //     lastNode = lastNode -> next;
    // }
    // previous -> next = lastNode ->next;
    // free(lastNode);
    //.......................................................
    if(head == NULL)
    {
        cout << "There is no node in the list." << endl;
        return;
    }
    else if (head -> next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    else
    {
        node* lastNode = head;
        while(lastNode -> next -> next != NULL){
            lastNode = lastNode -> next;
        }
        free(lastNode -> next);
        lastNode -> next = NULL;
    }
    
}

int main()
{
    Data dat;
    while(1)
    {
        char choise;
        cout << "Enter your choise from the next list :" << endl;
        cout << "1.To display all nodes.\n2.To insert nodes.\n3.To delete any node.\n4.To insert at the beginning.\n5.To search.\n6.To delete at beginning.\n7.To delete at end.\nAny thing else to break." << endl;

        cin >> choise;
        switch (choise)
        {
        case '1':
        {
            displayall();
            break;
        }
        case '2':
        {
            int n;
            cout << "Enter the number of nodes : " << endl;
            cin >> n;
            for(int i = 0;i < n;i++)
            {
                int average = 0;
                int sum = 0;
                cout << "Enter the " << i+1 << " th name : " << endl;
                cin >> dat.name;
                for(int j = 0;j < 4;j++)
                {
                    cout << "Enter the " << j << " th degree : " << endl;
                    cin >> dat.degree[j];
                    sum += dat.degree[j];
                }
                average =  sum / 4.0;
                dat.average = average;
                insertNode(dat);
            }
            break;
        }
        case '3':
        {
            string name;
            cout << "Enter name of node you want to delete it : " << endl;
            cin >> name;
            deleteAnyNode(name);
            break;
        }
        case '4':
        {
            int sum = 0;
            int n;
            for(int i = 0;i < n;i++)
            {
                cout << "Enter the " << i+1 << " th name : " << endl;
                cin >> dat.name;
                for(int j = 0;j < 4;j++)
                {
                    cout << "Enter the " << j << " th degree : " << endl;
                    cin >> dat.degree[j];
                    sum += dat.degree[j];
                }
                dat.average = sum / 4.0;
            }
            insertatbeginning(dat);
        }
        case '5':
        {
            string name;
            cout << "Enter name of node you want to search : " << endl;
            cin >> name;
            bool found = search(name);
            if(found == true)
            {
                cout << "Name found." << endl;
            }
            else
            {
                cout << "Name not found." << endl;
            }
            break;
        }
        case '6':
        {
            deletebeginning();
            break;
        }
        case '7':
        {
            deleteend();
            break;
        }
        default:
            break;
        }
    }
    return 0;
}