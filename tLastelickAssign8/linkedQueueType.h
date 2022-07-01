//Header file linkedQueue.h

#ifndef NodeType
#define NodeType

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

#endif

#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>

using namespace std;

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations on a queue as a
// linked list.
//*************************************************************

template <class Type>
class linkedQueueType
{
	public:
		const linkedQueueType<Type>& operator=
		(const linkedQueueType<Type>&);
		//Overload the assignment operator.
		
		bool isEmptyQueue() const;
		//Function to determine whether the queue is empty.
		//Postcondition: Returns true if the queue is empty,
		//    otherwise returns false.
		
		bool isFullQueue() const;
		//Function to determine whether the queue is full.
		//Postcondition: Returns true if the queue is full,
		//    otherwise returns false.
		
		void initializeQueue();
		//Function to initialize the queue to an empty state.
		//Postcondition: queueFront = NULL; queueRear = NULL
		
		Type front() const;
		//Function to return the first element of the queue.
		//Precondition: The queue exists and is not empty.
		//Postcondition: If the queue is empty, the program
		//    terminates; otherwise, the first element of the
		//    queue is returned.
		
		Type back() const;
		//Function to return the last element of the queue.
		//Precondition: The queue exists and is not empty.
		//Postcondition: If the queue is empty, the program
		//    terminates; otherwise, the last element of the
		//    queue is returned.
		
		void addQueue(const Type& queueElement);
		//Function to add queueElement to the queue.
		//Precondition: The queue exists and is not full.
		//Postcondition: The queue is changed and queueElement is
		//    added to the queue.
		
		void deleteQueue();
		//Function  to remove the first element of the queue.
		//Precondition: The queue exists and is not empty.
		//Postcondition: The queue is changed and the first element
		//    is removed from the queue.
		
		void copyQueue(const linkedQueueType<Type>& otherQueue);
	
		
		void printQueue() const;
		// Output the content of the queue to the screen
		
		linkedQueueType();
		//Default constructor
		
		linkedQueueType(const linkedQueueType<Type>& otherQueue);
		//Copy constructor
		
		~linkedQueueType();
		//Destructor
		
		// Function that sorts a list in ascending order.
		// Keeps track of comparisons and dataMoves.
		// Precondition: Only accepts a pointer to a linked list head
		// Postcondition: The list has been sorted in ascending order
        void mergeSort(nodeType<Type>* &head);
		
		// mergesort interface function
		void mergeSort();
		
		// Function that finds the middle node of a list and divides one list
		// into two lists.
		// Postcondition: returns two pointers. Each is the head of a list. 
		void divideList(nodeType<Type>* first1, nodeType<Type>* &first2);
		
		// Function that takes two sorted lists, compares them, and 
		// begins to create a 'master' sorted list. 
		// Keeps track of comparisons and dataMoves made.
		// Precondition: Two pointer heads to two different lists (no identical values)
		// Postcondition: Returns a head pointer to a 'master' sorted list
		// that merges the two lists in ascending order. 
		nodeType<Type>* mergeList(nodeType<Type>* first1, nodeType<Type>* first2);
		
		// Function that gets the accumulated amount of dataMoves in the mergeSort function
		// Postcondition: returns dataSort mem var.
		int getdataMoves();
		
		// Function that gets the accumulated amount of comparisons in the mergeSort function
		// Postcondition: returns comparisons mem var. 
		int getComparisons();
		
		////////////////////////////////////////////////////////
		///////////INSERTION SORT (LINKED) BELOW //////////////
		//////////////////////////////////////////////////////
		
		// Function that sorts a list in ascending order.
		// Precondition: list must be a linked list.
		// Postcondition: sorts the list in ascending order permanently. 
		// if list has no nodes, or only 1 node, will cout appropriate message.
		void linkedInsertionSort();
		
		
	private:
		nodeType<Type> *queueFront; //pointer to the front of the queue
		nodeType<Type> *queueRear;  //pointer to the rear of the queue
		int dataMoves;
		int comparisons;
};

//Default constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
    queueFront = NULL; //set front to null
    queueRear = NULL;  //set rear to null
    dataMoves = 0;
    comparisons = 0;
} //end default constructor

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end isEmptyQueue

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;
	
	//while there are elements left in the queue
    while (queueFront != NULL)  
    {
        //set temp to point to the current node
		temp = queueFront;  
		//advance first to the next node
        queueFront = queueFront->link;
		//deallocate memory occupied by temp
        delete temp;
    }

    queueRear = NULL;  //set rear to NULL
} //end initializeQueue


template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;
	
    newNode = new nodeType<Type>;   //create the node
	
    newNode->info = newElement; //store the info
    newNode->link = NULL;  //initialize the link field to NULL
	
    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info;
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;
	
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the first node
        queueFront = queueFront->link; //advance queueFront
		
        delete temp;    //delete the first node
		
        if (queueFront == NULL) //if after deletion the queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


//Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() 
{
	initializeQueue();
} //end destructor

template <class Type>
void linkedQueueType<Type>::copyQueue (const linkedQueueType<Type>& otherQueue) 
{
	nodeType<Type> *newNode, *current, *last;
	
    if (queueFront != NULL) //if queue is nonempty, make it empty
        initializeQueue();
	
    if (otherQueue.queueFront == NULL)
        queueFront = NULL;
	else 
	{
		//set current to point to the queue to be copied
        current = otherQueue.queueFront;  
		
        queueFront = new nodeType<Type>;  //create the node
		
        queueFront->info = current->info; //copy the info
        queueFront->link = NULL;  //set the link field of the node to NULL
        last = queueFront;        //set last to point to the node
        current = current->link;  //set current to point to the next node
		
		//copy the remaining queue
        while (current != NULL) {
            newNode = new nodeType<Type>;
			
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
		
		queueRear = last;
    }//end else
}

template <class Type>
void linkedQueueType<Type>::printQueue() const {
	nodeType<Type> *temp;
	
	temp = queueFront;
	
	while(temp != NULL) {
		cout << temp->info << " ";
		temp = temp->link;
	}
}

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue) 
{
	
	if (this != &otherQueue) //avoid self-copy
        copyQueue(otherQueue);
	
    return *this;
	
} //end assignment operator

//copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) 
{
    queueFront = NULL;
    copyQueue(otherQueue);
} //end copy constructor

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
////////////////// MERGE SORT FUNCTIONS ///////////////////////////
//////////////////////////////////////////////////////////////////

template <class Type>
void linkedQueueType<Type>::divideList(nodeType<Type>* first1, nodeType<Type>* &first2)
{
    // first1 = head;
    // first2 = otherHead (of the new list)

    // if the list is an empty list
    // end function
    if (first1 == NULL || first1->link == NULL)
    {
        first2 = NULL;
        comparisons++;
        dataMoves++;
        return;
    }
    nodeType<Type> *middle;
    nodeType<Type> *current;
    middle = first1;
    dataMoves++;
    current = first1->link;
    dataMoves++;
    // makes sure there is a node to the right before traversing
    if (current != NULL)
    {
    current = current->link; // to avoid segmentation fault
    comparisons++;
    dataMoves++;
    }
    
    // traverse the list
    // middle will = the middle node by the end of run
    while (current != NULL)
    {
        middle = middle->link;
        current = current->link;
        dataMoves+=2;
            
        // makes sure there is a node to the right before traversing    
        if (current != NULL) 
        {
        current = current->link; // to avoid segmentation fault
        comparisons++;
        dataMoves++;
        }
    }
    
    first2 = middle->link;
    dataMoves++;
    middle->link = NULL;
    dataMoves++;
    return;   
}

template <class Type>
nodeType<Type>* linkedQueueType<Type>::mergeList(nodeType<Type>* first1, nodeType<Type>* first2)
{
    if (first1 == NULL) 
    {
    comparisons++;
    return first2;
    }
    if (first2 == NULL)
    {
    comparisons++;
    return first1;
    }
    nodeType<Type> *lastSmall;
    nodeType<Type> *newHead;
    
    // if element in first list is less than element in second list,
    // that element becomes the new head of a 'master' sorted list that combines both these
    // sorted lists.
    if (first1->info < first2->info)
    {
        newHead  = first1;
        first1   = first1->link;
        comparisons++;
        dataMoves+=2;
    }
    // the second list element is less than the first element of the lists,
    // that element becomes the head of our new 'master' sorted list
    else
    {
        newHead  = first2;
        first2   = first2->link;
        comparisons++;
        dataMoves+=2;
    }
    lastSmall = newHead;    // set lastSmall to the last merged node
    dataMoves++; // data moved from location at newHead to lastSmall
    
    // traverse both lists
    while (first1 != NULL && first2 != NULL)
    {
        // compare both sorted lists for the smallest element
        // update 'master' sorted list
        if (first1->info < first2->info)
        {
            lastSmall->link = first1;
            first1          = first1->link;
            comparisons++;
            dataMoves+=2;
        }
        // else other list has the smaller element of the two sorted lists
        // add that smaller element between the two sorted lists and add it to the 'master' sorted list
        else
        {
            lastSmall->link = first2;
            first2          = first2->link;
            comparisons++;
            dataMoves+=2;
        }
        lastSmall = lastSmall->link;
        dataMoves++;
    }
    
    // if one list is merged with the 'master' sorted list first
    // the other list must have only larger elements remaining
    // that entire list is then appended to the sorted list
   // if (first1==NULL) lastSmall->link = first2; comparisons++;
   // else              lastSmall->link = first1; comparisons++;
   if (first1==NULL)
   { 
   lastSmall->link = first2; 
   comparisons++;
   dataMoves++;
   }
   else
   {
   lastSmall->link = first1; 
   comparisons++;
   dataMoves++;
   } 
    return newHead;
    
}

template <class Type>
void linkedQueueType<Type>::mergeSort(nodeType<Type>* &head)
{
    if (head == NULL || head->link == NULL) return;
    nodeType<Type> *otherHead;
    divideList(head, otherHead);
    mergeSort(head);
    mergeSort(otherHead);
    head = mergeList(head, otherHead);
    return;
}

template<class Type>    // interface function
void linkedQueueType<Type>::mergeSort()
{
    mergeSort(queueFront);
    // identifies the list start and end nodes
    if (queueFront == NULL) queueRear = NULL;
    else
    {
        queueRear = queueFront;
        while (queueRear->link != NULL)
            queueRear = queueRear->link;
    }
    return;
}

template <class Type>
int linkedQueueType<Type>::getdataMoves()
{ return dataMoves; }

template <class Type>
int linkedQueueType<Type>::getComparisons()
{ return comparisons; }

///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/////////////////////// INSERTION SORT FUNCTION /////////////////////
////////////////////////////////////////////////////////////////////
template <class Type> 
void linkedQueueType<Type>::linkedInsertionSort()
{
    nodeType<Type> *lastInOrder;
    nodeType<Type> *firstOutOfOrder;
    nodeType<Type>* current;
    nodeType<Type>* trailCurrent;
    
    //nodeType<Type>* first;  // to traverse list after 6 iterations
    //int count = 0;  // Assignment 8B #2
    
    lastInOrder = queueFront;
    if (queueFront == NULL)
        cerr << "Cannot sort an empty list. " << endl;
    else if (queueFront->link == NULL)
        cout << "The list is of length 1. It is already in order." << endl;
    else
        // traverse list of 2+ nodes
        while (lastInOrder->link != NULL)
        {
            
            firstOutOfOrder = lastInOrder->link; // points to node after sorted list
            dataMoves++;
            // if node to be sorted is the smallest element in whole sorted list
            // move it to the first node (head) of the list
            if (firstOutOfOrder->info < queueFront->info)
            {
                lastInOrder->link = firstOutOfOrder->link;
                firstOutOfOrder->link = queueFront;
                queueFront = firstOutOfOrder;
                comparisons++;
                dataMoves+=3;
            }
            // else if not to be inserted as first node
            else
            {
                trailCurrent = queueFront;
                current = queueFront->link;
                dataMoves+=2;
                comparisons++;
                // traverse sorted list 
                // looking for spot to insert unsorted node
                while (current->info < firstOutOfOrder->info)
                {
                    trailCurrent = current;
                    current = current->link;
                    dataMoves+=2;
                    comparisons++;
                }
                // insert the unsorted node into the sorted list
                // adjust the pointers accordingly
                if (current != firstOutOfOrder)
                {
                    lastInOrder->link = firstOutOfOrder->link;
                    firstOutOfOrder->link = current;
                    trailCurrent->link = firstOutOfOrder;
                    comparisons++;
                    dataMoves+=3;
                }
                // else insert as last node in sorted list
                else
                {
                    lastInOrder = lastInOrder->link;
                    comparisons++;
                    dataMoves+=3;
                }
                //count++;    // when count is 6 print list 
                            // show resulting list after 6 passes 
                            // answers Assignment 8B #2
               // if (count == 6)
               // {
               //    first = queueFront;
               //    while (first != NULL)
               //   {
               //     cout << first->info << " ";
               //     first = first->link;
               //    }
               // }
          } 
//**************************************************
// firstOutOfOrder - pointer node to be moved to its proper location
// lastInOrder - pointer to last node of the sorted portion of the list
// queueFront - head of the list (first node in list).
// current - pointer to traverse the list
// trailCurrent - pointer to traverse the list for special cases
//**************************************************
                  
      } // end while
}//end linkedInsertionSort

#endif
