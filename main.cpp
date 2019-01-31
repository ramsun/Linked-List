/*
Ramamurthy Sundar
Fall 2018

main.cpp

This is the driver for the program.  It creates 2 linked lists with 20 and 15 random
integers, sorts, then merges them.

The floating point average and sum of the spliced linked list is then calculated.

All operations are posted to an output text file.
*/

#include "class.h"

int main() {
	//initialize variables
	int randNum; int max = 100; int min = 0;
	LinkedList<int> List1, List2, List3;
	std::ofstream outfile;
	outfile.open("Output.txt");

	//create list of 20 random integers between 0 and 100
	for (int i = 0; i < 20; i++) {
		randNum = rand() % (max - min + 1) + min;
		List1.insert_front(randNum);
		
	}
	//create a list of 15 random inetegers between 0 and 100
	for (int i = 0; i < 15; i++) {
		randNum = rand() % (max - min + 1) + min;
		List2.insert_front(randNum);
	}

	//make the lists ordered
	List1.bubble_sort(); List2.bubble_sort();

	//print the lists to the output file
	outfile << "The first list has: " << "\n";
	List1.print_to_txt(outfile);
	outfile << "\n";
	outfile << "The second list has: " << "\n";
	List2.print_to_txt(outfile);
	outfile << "\n";

	//create the joined list
	LinkedList<int>::Iterator iter1 = List1.begin();
	LinkedList<int>::Iterator iter2 = List2.begin();
	List1.remove_duplicates(); List2.remove_duplicates();
	List3.splice(iter1, iter2);
	List3.bubble_sort();
	List3.remove_duplicates();
	
	//print the new list to the output file
	outfile << "The new list contains: " << "\n";
	List3.print_to_txt(outfile);
	outfile << "\n";

	//print the average and sum of the new list
	int total = List3.sum();
	double mean = List3.average();
	outfile << "The sum of the final list's elements is: " << total << "\n";
	outfile << "The average of the final list's elements is: " << mean << "\n";

	//close output file and exit program
	outfile.close();
	return 0;
}
