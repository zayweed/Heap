/*
Zayeed Saffat
4/6/2022
This project creates a max heap stored as an array from file input or user input.
It also prints out a tree representing the array and the sorted input.
*/

#include <bits/stdc++.h>

using namespace std;

//function prototypes
void fileInput(int*& array, int& size);
void userInput(int*& array, int& size);
void print(int* array);
void add(int*& array, int num, int index);
void displayTree(int index, int* array, int depth, int size);
void displaySort(int*& array, int& size);

int main() {
    cout << "Welcome to Heap!" << endl;

    int* array = new int[100];
    for (int i = 0; i < 100; i++) { //fills heap array with 0s
        array[i] = 0;
    }
    int size = 0;
    
    cout << "Would you like to add by 'FILE' or by 'INPUT'?" << endl;
    char input[100]; cin >> input;

    if (strcmp(input, "FILE") == 0) { //file input
        fileInput(array, size);
        //print(array);
    }
    if (strcmp(input, "INPUT") == 0) { //user input
        userInput(array, size);
        //print(array);
    }
    //cout << "SIZE: " << size << endl;

    displayTree(1, array, 0, size);
    displaySort(array, size);

}

void fileInput(int*& array, int& size) { //adds from file input
    fstream fin;
    fin.open("numbers.txt"); //opens file

    int input;
    int index = 1;
    while(fin >> input) { //adds numbers to heap until it goes through the entire file
        add(array, input, index); //add to heap array
        index++;
    }
    size = index - 1; //updates size

    fin.close(); //closes file
}

void userInput(int*& array, int& size) { //adds from user input
    cout << "How many numbers would you like to add?" << endl;
    int n, input;
    cin >> n;
    size = n; //updates size
    for (int index = 1; index < n + 1; index++) { //adds specificied amount of inputted numbers to heap
        cin >> input;
        add(array, input, index); //add heap array
    }
}

void print(int* array) { //prints heap array for debugging
    cout << "PRINT" << endl;
    for (int i = 0; i < 100; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void add(int*& array, int num, int index) { //adds number to the heap array
    int pIndex = index / 2;
    array[index] = num; //add to heap array
    while (array[index] > array[pIndex] && index > 1 ) { //swap and update indices
        int temp = array[index];
        array[index] = array[pIndex];
        array[pIndex] = temp;
        index = pIndex;
        pIndex = pIndex / 2;
    }
}

void displayTree(int index, int* array, int depth, int size) { //displays the heap as a tree
    if (size >= index * 2 + 1  && array[index*2+1] != 0) { 
        displayTree(index * 2 + 1, array, depth + 1, size); //recursive call
    }

    for(int i = 0; i < depth; i++) { //prints tabs based off depth
        cout << "\t";
    }

    cout << array[index] << endl;
    if (index * 2 <= size && array[index * 2] != 0) {
        displayTree(index * 2, array, depth + 1, size); //recursive call
    }
}

void displaySort(int*& array, int& size) { //prints sorted descending input using heap array
    cout << array[1] << " "; //print root

    array[1] = array[size];
    array[size] = 0;  
    size--;
    
    int index = 1;
    while(array[index * 2] != 0) { //if element has not been swapped
        if (array[index * 2] > array[index] || array[index * 2 + 1] > array[index]) {
            //swap current element with left 
            if (array[index * 2] > array[index * 2 + 1]) {
            int temp = array[index];
            array[index] = array[index * 2];
            array[index * 2] = temp;
            index = index * 2;
            } 

            //swap current element with right 
            else {
            int temp = array[index];
            array[index] = array[index * 2 + 1];
            array[index * 2 + 1] = temp;
            index = index * 2 + 1;
            } 
        } 

        else {
            break;
        }
    }

    if (size != 0) {
        displaySort(array, size); //recursive call
    }
}

/*
Test Data:
15
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/
