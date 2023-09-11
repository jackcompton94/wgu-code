//
//  main.cpp
//  sort-algorithms
//
//  Created by Jack Compton on 12/23/22.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> v = {};

void initVector() {
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 100);
    }
    
    // printVector()
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "|";
    }
    cout << endl << endl;
}

void printVector() {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "|";
    }
    cout << endl << endl;
}

void selectionSort() {
    int counter = 0;
    
    for (int i = 0; i < v.size(); i++) {
        int minVal = v[i];
        
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < minVal) {
                
                minVal = v[j];
                v[j] = v[i];
                v[i] = minVal;
                
                counter++;
            }
        }
    }
    cout << "swapped " << counter << " times" << endl;
    printVector();
}

void bubbleSort() {
    int counter = 0;
    int temp;
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[j] > v[i+1]) {
                
                temp = v[i+1];
                v[i+1] = v[j];
                v[j] = temp;
                
                counter++;
            }
        }
    }
    cout << "swapped " << counter << " times" << endl;
    printVector();
}

void insertionSort() {
    int counter = 0;
    int temp;
    
    for (int i = 1; i < v.size(); i++) {
        
        while (v[i] < v[i-1]) {
            
            temp = v[i-1];
            v[i-1] = v[i];
            v[i] = temp;
            
            i--;
            counter++;
        }
    }
    
    cout << "swapped " << counter << " times" << endl;
    printVector();
}

int main() {
    
    cout << "vector v: " << endl;
    initVector();
    
    //cout << "selection sort: ";
    //selectionSort();
     
    //cout << "bubble sort: ";
    //bubbleSort();

    //cout << "insertion sort: ";
    //insertionSort();
    
    cout << endl << endl;
    return 0;
}
