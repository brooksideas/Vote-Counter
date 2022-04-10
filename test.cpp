 // C++ program to illustrate the array
// of Linked Lists
#include <iostream>
#include<sstream>  
using namespace std;

// Structure of Linked Lists

 
struct info {
    string key;
	int value;
	info* next;
};

// Driver Code
int main()
{
	int size = 10;

	// Pointer To Pointer Array
	info** head;

	// Array of pointers to info struct
	// of size
	head = new info*[size];

	// Initialize pointer array to NULL
	for (int i = 0; i < size; ++i) {
		*(head + i) = NULL;
	}

	// Traverse the pointer array
	for (int i = 0; i < size; ++i) {

		// To track last node of the list
		info* prev = NULL;

		// Randomly taking 4 nodes in each
		// linked list
		int s = 2;

		while (s--) {

			// Create a new node
			info* n = new info;
            // convert
              stringstream ss;  
              ss<<i;  
              string s;  
              ss>>s;  
			// Input the random data
			n->key = s;
			n->value = i * (i + 1);
			n->next = NULL;

			// If the node is first
			if (*(head + i) == NULL) {
				*(head + i) = n;
			}
			else {
				prev->next = n;
			}
			prev = n;
		}
	}

	// Print the array of linked list
	for (int i = 0; i < size; ++i) {
		info* temp = *(head + i);

		// Linked list number
		cout << i << "-->\t";

		// Print the Linked List
		while (temp != NULL) {
			cout << "Key ->" << temp->key << "-->value-->"<< temp->value << " ";
			temp = temp->next;
		}

		cout << '\n';
		
		cout << "secondArray" << head[2] <<endl;
	}

	return 0;
}
