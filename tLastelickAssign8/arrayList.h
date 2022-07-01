#ifndef H_arrayList
#define H_arrayList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of array-based lists.
//***********************************************************

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class arrayList
{
public:
    const arrayList<elemType>& operator=
                         (const arrayList<elemType>&);
      //Overloads the assignment operator
    bool isEmpty() const;
      //Function to determine whether the list is empty
      //Postcondition: Returns true if the list is empty; 
      //    otherwise, returns false.
    bool isFull() const;
      //Function to determine whether the list is full.
      //Postcondition: Returns true if the list is full; 
      //    otherwise, returns false.
    int listSize() const;
      //Function to determine the number of elements in the list
      //Postcondition: Returns the value of length.
    int maxListSize() const;
      //Function to determine the size of the list.
      //Postcondition: Returns the value of maxSize.
    void print() const;
      //Function to output the elements of the list
      //Postcondition: Elements of the list are output on the 
       //   standard output device.
    bool isItemAtEqual(int location, const elemType& item) const;
      //Function to determine whether the item is the same 
      //as the item in the list at the position specified by
      //Postcondition: Returns true if the list[location] 
      //    is the same as the item; otherwise, 
      //               returns false.
   void insertAt(int location, const elemType& insertItem);
      //Function to insert an item in the list at the 
      //position specified by location. The item to be inserted 
      //is passed as a parameter to the function.
      //Postcondition: Starting at location, the elements of the
      //    list are shifted down, list[location] = insertItem;,
      //    and length++;. If the list is full or location is
      //    out of range, an appropriate message is displayed.
   void insertEnd(const elemType& insertItem);
      //Function to insert an item at the end of the list. 
      //The parameter insertItem specifies the item to be inserted.
      //Postcondition: list[length] = insertItem; and length++;
      //    If the list is full, an appropriate message is 
      //    displayed.
    void removeAt(int location);
      //Function to remove the item from the list at the 
      //position specified by location 
      //Postcondition: The list element at list[location] is removed
      //    and length is decremented by 1. If location is out of 
      //    range,an appropriate message is displayed.
    void retrieveAt(int location, elemType& retItem) const;
      //Function to retrieve the element from the list at the  
      //position specified by location. 
      //Postcondition: retItem = list[location] 
      //    If location is out of range, an appropriate message is
      //    displayed.
    void replaceAt(int location, const elemType& repItem);
      //Function to replace the elements in the list at the 
      //position specified by location. The item to be replaced 
      //is specified by the parameter repItem.
      //Postcondition: list[location] = repItem 
      //    If location is out of range, an appropriate message is
      //    displayed.
    void clearList();
      //Function to remove all the elements from the list. 
      //After this operation, the size of the list is zero.
      //Postcondition: length = 0;
    int seqSearch(const elemType& item) const;
      //Function to search the list for a given item. 
      //Postcondition: If the item is found, returns the location 
      //    in the array where the item is found; otherwise,
      //    returns -1.
    void insert(const elemType& insertItem);
      //Function to insert the item specified by the parameter 
      //insertItem at the end of the list. However, first the
      //list is searched to see whether the item to be inserted 
      //is already in the list. 
      //Postcondition: list[length] = insertItem and length++
      //     If the item is already in the list or the list
      //     is full, an appropriate message is displayed.
    void remove(const elemType& removeItem);
      //Function to remove an item from the list. The parameter 
      //removeItem specifies the item to be removed.
      //Postcondition: If removeItem is found in the list,
      //      it is removed from the list and length is 
      //      decremented by one.

    arrayList(int size = 100);
      //constructor
      //Creates an array of the size specified by the 
      //parameter size. The default array size is 100.
      //Postcondition: The list points to the array, length = 0, 
      //    and maxSize = size
	
    arrayList(const arrayList<elemType>& otherList);
      //copy constructor

    ~arrayList();
      //destructor
      //Deallocates the memory occupied by the array.

    //////////////////////////////////////////////////////////
    ///////////////// SELECTION SORT FUNCTIONS //////////////

    //Function to sort the elements in a list in ascending order.
    //Postcondition: List permanently changed into ascending 
    // order. 
    void selectionSort();
    
    // Function that finds the largest element in a list. 
    // Postcondition: returns the largest element between 
    // first and last's index
    int maxLocation(int first, int last);
    
    //Function to sort the elements in a list in descending order.
    // Postcondition: List has been sorted in descending order. 
    void selectionSortDesc();
    
    ////////////////////////////////////////////////////////////
    /////////// QUICKSORT FUNCTIONS ///////////////////////////
    
    // Function that picks a number out of a list (pivot), creates two sublists,
    // one sublist contains elements bigger than pivot, the other list elements
    // less than pivot. Then puts pivot back into the middle of the list.
    // Postcondition: Pivot is back at the middle of the list at this point. 
    // list has been modified where all numbers > pivot are 
    // on one side of pivot, all numbers < pivot on the other side. 
    int partition(int first, int last);
    
    // Function that sorts a list in ascending order.
    // Precondition: needs an appropriate interface function to run in main.
    // Postcondition: The list has been sorted in ascending order. 
    void recQuickSort(int first, int last);
    
    // Function that is the interface function for recQuickSort
    // Postcondition: The list has been sorted in ascending order
    void quickSort();
    
protected:
    elemType *list;  //array to hold the list elements
    int length;      //to store the length of the list
    int maxSize;     //to store the maximum size of the list
    // Helper function used in selectionSort() 
    // Finds and returns the smallest element in a list. 
    // Postcondition: returns the smallest element between
    // first and last's index.
    int minLocation(int first, int last);
    
    // Swaps the index of the two arguments. 
    // Postcondition: first is now in second's index; 
    // second is now in first's index.  
    void swap(int first, int second);
    
    
};

template <class elemType>
bool arrayList<elemType>::isEmpty() const
{
    return (length == 0);
}

template <class elemType>
bool arrayList<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayList<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayList<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayList<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl;
}

template <class elemType>
bool arrayList<elemType>::isItemAtEqual
                            (int location, const elemType& item) const
{
    return (list[location] == item);
}

template <class elemType>
void arrayList<elemType>::insertAt
                  (int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
             << "is out of range" << endl;
    else
        if (length >= maxSize)  //list is full
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                 list[i] = list[i - 1];   //move the elements down

            list[location] = insertItem;  //insert the item at the 
                                          //specified position

            length++;     //increment the length
    }
} //end insertAt

template <class elemType>
void arrayList<elemType>::insertEnd(const elemType& insertItem)
{

    if (length >= maxSize)  //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
         list[length] = insertItem;   //insert the item at the end
         length++;   //increment the length
    }
} //end insertEnd

template <class elemType>
void arrayList<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
             << "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];

        length--;
    }
} //end removeAt

template <class elemType>
void arrayList<elemType>::retrieveAt
                             (int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
             << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt


template <class elemType>
void arrayList<elemType>::replaceAt
                          (int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
             << "out of range." << endl;
    else
        list[location] = repItem;

} //end replaceAt

template <class elemType>
void arrayList<elemType>::clearList()
{
    length = 0;
} //end clearList

template <class elemType>
int arrayList<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
        if (list[loc] == item)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void arrayList<elemType>::insert(const elemType& insertItem)
{
    int loc;

    if (length == 0)   //list is empty
        list[length++] = insertItem;    //insert the item and 
                                //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);

        if (loc == -1)    //the item to be inserted 
                          //does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
                 << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template<class elemType>
void arrayList<elemType>::remove(const elemType& removeItem)
{
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
} //end remove

template <class elemType>
arrayList<elemType>::arrayList(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
             << "an array of size 100. " << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;

    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayList<elemType>::~arrayList()
{
    delete [] list;
}


template <class elemType>
arrayList<elemType>::arrayList
                   (const arrayList<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL);         //terminate if unable to allocate
                                  //memory space

    for (int j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
} //end copy constructor

template <class elemType>
const arrayList<elemType>& arrayList<elemType>::operator=
                      (const arrayList<elemType>& otherList)
{
    if (this != &otherList)   //avoid self-assignment
    {
        delete [] list; 
        maxSize = otherList.maxSize; 
        length = otherList.length; 
 
        list = new elemType[maxSize];  //create the array
        assert(list != NULL);   //if unable to allocate memory 
                                //space, terminate the program 
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i]; 
    }

    return *this; 
}
//////////////////////////////////////////////
/////////////////////////////////////////////
// selectionSort and helper functions //////
////////////////////////////////////////////
template <class elemType>
void arrayList<elemType>::swap(int first, int second)
{
    elemType temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
  
}

template <class elemType>
int arrayList<elemType>::minLocation(int first, int last)
{
    // logic for ascending order functionality
    
    int minIndex;
    minIndex = first;
    for (int loc = first + 1; loc <= last; loc++)
        {
        if (list[loc] < list[minIndex])
            minIndex = loc;
        }   
    return minIndex;
}


// used in selectionSortDesc function
// replaces minLocation in selectionSort
template <class elemType>
int arrayList<elemType>::maxLocation(int first, int last)
{
    int maxIndex;
    maxIndex = first;

    for (int loc = first+1; loc <= last; loc++)
        {
        if (list[loc] > list[maxIndex])
            maxIndex = loc;
        }
    return maxIndex;
}

template <class elemType>
void arrayList<elemType>::selectionSort()
{
    int minIndex;
    for (int loc = 0; loc<length-1; loc++)
    {
        minIndex = minLocation(loc, length-1);
        swap(loc, minIndex);
        // used to print list to answer Assignment 8B #1
        //for (int i=0; i<length; i++)  
        //    cout << list[i] << " ";

       //cout << endl;
    }
}

template <class elemType>
void arrayList<elemType>::selectionSortDesc()
{
    int maxIndex;
    for (int loc = 0; loc<length-1; loc++)
    {
        maxIndex = maxLocation(loc, length-1);
        swap(loc, maxIndex);
    }
}

//////////////////////////////////////////////////////////
///////////////// QUICK SORT FUNCTIONS //////////////////
////////////////////////////////////////////////////////

template <class elemType>
int arrayList<elemType>::partition(int first, int last)
{
    elemType pivot;
    int index, smallIndex;
    swap(first, (first+last)/2);    // finds the middle element and assigns it to first
    pivot = list[first]; // pivot is the first element (found from middle of list)
    smallIndex = first;
    // index starts at second item in the list (first is pivot)
    // index stops at last item in the list
    for (index = first+1; index<= last; index++)
        // if node info is less than pivot info, add it to lowerSublist
        if (list[index] < pivot)
        {
            smallIndex++;   // increment the last index that distinguishes lowerSublist
            swap(smallIndex, index);    // swap, now smallIndex still distinguishes lowerSublist
        }
    swap(first, smallIndex);  // put the pivot back into the middle of the list
                              // distinguishes between lowerSublist and upperSublist
    // will print out list every run of this partition function
    // this->print();
    return smallIndex;
}

// has already been defined in this class
// shows that swap is used in quicksort function
//template <class elemType>
//void arrayList<elemType>::swap(int first, int second)
//{
//    elemType temp;
//    temp = list[first];
//    list[first] = list[second];
//    list[second] = temp;
//  
//}

template <class elemType>
void arrayList<elemType>::recQuickSort(int first, int last)
{
    
    int pivotLocation;
    if (first < last)
    {
        pivotLocation = partition(first, last);           
        recQuickSort(first, pivotLocation-1);
        recQuickSort(pivotLocation+1, last);
    }
}

// interface function; sorts list in ascending order
template <class elemType>
void arrayList<elemType>::quickSort()
{
    recQuickSort(0, length -1);
}
#endif
