//********************************************************************
//Name: Trevor Lastelick 
//Class: COSC 2437Fall20
//Instructor: Marwa Hassan
//Assignment 8
//Date: 11/21/20
//Program description:
// 8B #1 - Shows the list after each iteration of the outer loop using selection sort
// but only after proper comments are removed from selectionSort function in 
//arrayList.h
// 8B #2 - Shows the following list after 6 passes of insertionSort 
// but only after proper comments have been removed from insertionSort function in
// arrayList.h
// 8b #3 - Shows a list continually being sorted after each call to the partition 
//function (located in linkedQueueType.h) but only after proper comments are removed. 
// Creates an array list, prints it out, then sorts it via selectionSortDesc() in
// descending order, and then prints out the list again.
// Creates a linked list and prints it to the screen. Runs the 
// linkedInsertionSort() function which sorts in ascending order and prints
// the sorted list to the screen along with number of dataMoves and number of 
// comparisons made. 
// Copies the previous linked list, prints it to the screen, then sorts it 
// in ascending order using the mergeSort() function. Also prints out the number
// of comparisons and data moves made during the sort. 
// Commented out clocks does nothing without the clockType.h header file
// With the file, it prints out times hh:mm:ss and runs selectionSort()
// and selectionSortDesc() functions on the objects to show that those functions
// do not sort a list of objects. 
// *********************************************************************
#include <iostream>
#include "arrayList.h"
//#include "clockType.h"
#include <fstream>
#include "linkedQueueType.h"

using namespace std;

int main()
{
    int temp = 0;
    arrayList<int> intList(50);
    //fstream inFile;
    //inFile.open("lab13.dat");
    //while (inFile >> temp)
    //    intList.insert(temp);
    
    // 8B #1
    //arrayList<int> intList(50);
    //intList.insert(34);
    //intList.insert(46);
    //intList.insert(19);
    //intList.insert(66);
    //intList.insert(27);
    //intList.insert(56);
    //intList.insert(13);
    //intList.insert(18);
    
    //intList.selectionSort();
    
    // 8B #2
    //linkedQueueType<int> two;
    //two.addQueue(38);
    //two.addQueue(28);
    //two.addQueue(31);
    //two.addQueue(20);
    //two.addQueue(35);
    //two.addQueue(40);
    //two.addQueue(22);
    //two.addQueue(81);
    //two.addQueue(42);
    //two.addQueue(68);
    //two.addQueue(25);
    //two.linkedInsertionSort();

    //cout << endl;
    // 8B #4
    //intList.insert(17);
    //intList.insert(39);
    //intList.insert(55);
    //intList.insert(81);  
    //intList.insert(23);
    //intList.insert(66);
    //intList.insert(56);
    //intList.insert(49);
    //intList.insert(65);
    //intList.insert(96);
    //intList.insert(6);
    //intList.insert(101);
    //intList.insert(59);
    //intList.insert(26);
    //intList.insert(37);
    
    //intList.quickSort();

       
	// add descending sort function and test here
	intList.insert(34);
    intList.insert(46);
    intList.insert(19);
    intList.insert(66);
    intList.insert(27);
    intList.insert(56);
    intList.insert(13);
    intList.insert(18);
    cout << "Unsorted array list: " << endl;
    intList.print();
    cout << "Sorted array list using selectionSortDesc() " << endl;
	intList.selectionSortDesc();
	intList.print();

	
	linkedQueueType<int> q1;
	q1.addQueue(38);
    q1.addQueue(28);
    q1.addQueue(31);
    q1.addQueue(20);
    q1.addQueue(35);
    q1.addQueue(40);
    q1.addQueue(22);
    q1.addQueue(81);
    q1.addQueue(42);
    q1.addQueue(68);
    q1.addQueue(25);
    cout << endl << "Unsorted List: ";
    q1.printQueue();

	q1.linkedInsertionSort();
	cout << endl << "Sorted List after linkedInsertionSort: ";
	q1.printQueue();
	cout << endl;
	cout << "Total comparisons: " <<q1.getComparisons() << endl;
	cout << "Total dataMoves: " <<q1.getdataMoves() << endl;
	
	linkedQueueType<int> q2;
	q2.addQueue(38);
    q2.addQueue(28);
    q2.addQueue(31);
    q2.addQueue(20);
    q2.addQueue(35);
    q2.addQueue(40);
    q2.addQueue(22);
    q2.addQueue(81);
    q2.addQueue(42);
    q2.addQueue(68);
    q2.addQueue(25);
	
    q2.mergeSort();
    cout << "Unsorted List: ";
    q2.printQueue();
    cout << endl;
    cout << "The same list, sorted, after mergeSort: ";
    q2.printQueue();
    cout << endl;
    cout << "Total comparisons: " <<q2.getComparisons() << endl;
	cout << "Total dataMoves: " <<q2.getdataMoves() << endl;
    
	// modify the clockType class and test here
    
    
	 //arrayList<clockType> myClockList(10);	
	 //clockType tempClock;
	
    /*
	tempClock.setTime(15,16,45);
		//cout << tempClock;
	 myClockList.insert(tempClock);
       // myClockList.print();
	 tempClock.setTime(6,13,35);
	 myClockList.insert(tempClock);	
	 tempClock.setTime(6,40,33);
	 myClockList.insert(tempClock);	
	 tempClock.setTime(7,34,55);
	 myClockList.insert(tempClock);	
	 tempClock.setTime(7,34,25);
	 myClockList.insert(tempClock);

	 myClockList.print();
	 myClockList.selectionSort();
	 myClockList.print();	
	 myClockList.selectionSortDesc();
	 myClockList.print();	
	*/
	
	return 0;
}
