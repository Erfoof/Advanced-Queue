#include <iostream>
#include <string>
#include<map>
using namespace std;
//Queue v 1.3

class Queue {
private:
    int rear;
    int front;
    //Pointer to store the address of the dynamic array(queue).
    int* Array;
    int Size; 
    int Numofobj = 0;
    int item;
    string Queuename;
    int Queueposition = 0;
    /*const int Sizecpy;*/
    
public:

   //constructor. The name and the size of the queue are retrieved from the user.
    Queue(string queuename, int size) {
        Numofobj++;
        rear = -1;
        front = -1;
        Size = size;
        //dynamic array is created. Because the size of the array is determined by the user at run time.
        Array = new int[Size];
        Queuename = queuename;
    };

    //destructer for when user wants the object to be deleted
    ~Queue() {
        delete[] Array;
        Numofobj--;
        
    }

    //Copy constructor
    //rhs stands for right hand side (the object we're copying)
    /*Queue(const Queue& rhs) {
        Array = new int[Size];
        for(i = 0; i < Size; i++)

    };*/


    //getter for the current size of the class.

    int currentsize() {
        return Numofobj;
    };
    

    //function to perform enqueue operation
    void enqueue(int item) {
        // checking overflow condition
        if (rear == Size - 1) {
            cout << "Overflow!" << endl;
            return;
        }
        else {
            // front and rear both are at -1 then 
            // set front and rear at 0 otherwise increment rear
            if (front == -1 && rear == -1) {
                front = 0;
                rear = 0;
            }
            else {
                rear++;
            }
            //inserting element at rear
            Array[rear] = item;
            cout << "Element inserted" << endl;
        }
    }
    //function to implement dequeue operation
    void dequeue() {
        //checking underflow condition
        if (front == -1 || front > rear) {
            cout << "Underflow!" <<endl;
            return;
        }
        else {
            item = Array[front];
            //displaying dequeued element
            cout << "Element deleted from queue is : " << item << endl;
            // if front and rear reach at end then initialize it at -1
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                //incrementing the front
                front++;
            }
        }
    }
    //function to display all elements of queue
    void display() {
        //checking whether queue is empty or not
        if (front == -1) {
            //if queue is empty simply return
            cout << "Queue is empty" << endl;
            return;
        }
        else {
            // if queue is not empty print all the elements from rear to front
            cout << "Elements are : ";
            for (int i = front; i <= rear; i++)
                cout << Array[i] << " ";
            cout << endl;
        }
    }
    //function to display front element of queue
    void fronte() {
        //checking whether queue is empty or not
        if (front == -1) {
            //if queue is empty simply return
            cout << "Queue is empty" << endl;
            return;
        }
        else {
            // if queue is not empty print front element
            cout << "Front Element is :" << Array[front] << endl;
        }
    }

    
};
//The object is dynamically allocated.
//function with the type of a pointer to the queue class is used to return the address of the object.
//The data type of this function is a pointer to a class object.
//because its returning that specific data type (A pointer pointing to an object in a class).
Queue *newqueue(string name,int size) { 
    Queue* pointer = new Queue(name, size);
        return pointer;
};




int main() {
    int ch;
    //This map creates a dictionary that relates the name of the queue to the address of where its stored inside the heap.
    //This is necessary because all the objects (queues) are made DYNAMICALLY. Which is done at run time.
    //Dynamic objects can be deleted and created during run time, which is what we want.
    map<string,Queue* > link;
    string Qname;
    int Qsize;
    int element;
    //displaying options of enqueue, dequeue, front, display to the user
    cout << "1: Create new Queue" << endl;
    cout << "2: Dequeue" << endl;
    cout << "3: Display all the elements of queue" << endl;
    cout << "4: Display front element of queue" << endl;
    cout << "5: Enqueue" << endl;
    cout << "6. Delete a Queue" << endl;
    cout << "7. Exit" <<endl;

    do {
        //taking user choice 
        cout << "Enter your choice: " << endl;
        cin >> ch;
        
        switch (ch) {
            //calling functions according to the choice of user
        case 1: {
            cout << "Input the name of the queue you would like to create: ";
            cin >> Qname; //Name of the DS
            cout << "Input the size of the queue you would like to create: ";
            cin >> Qsize;
            ///pointer2 (data type of the class "Queue") stores the object's address,
            //which is returned as a pointer from the "newqueue" method. (pointer pointing to a pointer)
            //the reason we store the objects address is because whenever an object is created at run time, we will not have 
            //its name, we will only have its address. So the address will be used as our reference to that specific object.
            //i did mention the pointer is of data type of the class "Queue". this is because pointers can only store the address of the same data type
            //Which in our case, is a pointer to the address of a CLASS. hence, our data type being the CLASS "Queue".
            Queue *pointer2 = newqueue(Qname, Qsize);

            //as soon as the object is made,a pair of string and a pointer (to the objects address) is made.
            //The pair will use the name of the queue as a key to reference the address of the object.
            //This way we can use the objects methods and whatnot using the name and not the adress.
            //The mapping of the name and address looks like this -->link[Qname]->METHOD(); (link is the name of the map)
            link.insert(pair<string,Queue* >(Qname,pointer2));
            break;
        }
        case 2:
            cout << "Input the name of the queue you would like to dequeue: ";
            cin >> Qname;
            //the name of the queue is used as a key. so a pointer will be returned as a value, and that pointer will be used to call the method.
            link[Qname]->dequeue();
            break;


        case 3: 
            cout << "Input the name of the queue you would like to display: ";
            cin >> Qname;
            link[Qname]->display();
            break;


        case 4: 
            cout << "Input the name of the queue you would like to output the front of: ";
            cin >> Qname;
            link[Qname]->fronte();
            break;


        case 5: 
            cout << "Input the name of the queue you would like to enqueue: ";
            cin >> Qname;
            cout << "Input the value you would like to enqueue: ";
            cin >> element;
            link[Qname]->enqueue(element);
            break;


        case 6:
            cout << "Input the name of the queue you would like to delete: ";
            cin >> Qname;
            link[Qname]->~Queue();
            cout << "Queue Deleted: " <<endl;
            break;

        case 7:
            cout << "Exit" << endl;
            break;

        default: cout << "Invalid choice" << endl;

        }
        } while (ch != 7);
        return 0;
    };
