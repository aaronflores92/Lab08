/*****
	Aaron Flores
	1105995
	
	binSearch.cpp
	Write a function that accepts a sorted array and searches the array in a binary fashion, returning the index of 
	the found element, or -1 if not found.
*****/

#include <iostream>
#include <array>

using namespace std;

int binSearch(array <int, 10> (&array), int minIndex, int maxIndex, int sVal)
{
	int sIndex = (maxIndex - minIndex) / 2; //divides the array into half-sized portions
	if(sIndex < minIndex) sIndex += minIndex; //covers the case in which search index lands in a section we are not searching through
	
	if(sVal < array.front() || sVal > array.back()) return -1; //covers case in which the search value does not exist within the array. only works because the array is a sorted array. need to set better boundary condition
	//if array[searchIndex] == sVal return index
	else if(array[sIndex] == sVal) return sIndex;
	
	//else if array[searchIndex] > sVal return(binSearch(array, minIndex, sIndex - 1, sVal)
	else if(array[sIndex] > sVal) return binSearch(array, minIndex, sIndex - 1, sVal);
	
	//else if array[searchIndex] < sVal return(binSearch(array, sIndex + 1, maxIndex, sVal)
	else if(array[sIndex] < sVal) return binSearch(array, sIndex+1, maxIndex, sVal);
	
	//else return -1
	else return -1;
}

int main()
{
	array <int, 10> test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sVal = 0;
	int maxIters = 0;
	std::cout << "binSearch.cpp program execution. please enter a value from 1-10 to search for:" << endl;
	std::cin >> sVal;
	std::cout << binSearch(test, 0, test.size()-1, sVal) << endl;
}
