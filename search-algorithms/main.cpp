//
//  main.cpp
//  search-algorithms
//
//  Created by Jack Compton on 12/23/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> vect;

void initializeVect() {
    for (int i = 0; i < 10000; i++) {
        vect.push_back(i);
    }
}

void print() {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << endl;
    }
}

void linearSearch(int userNum) {
    
    for (int i = 0; i < vect.size(); i++) {
        if (userNum != vect[i]) {
            cout << vect[i] << endl;
        }
        else if (userNum == vect[i]) {
            cout << "Found your number: " << userNum << "!";
            break;
        }
    }
}

void binarySearch(vector<int> vect, int userNum, int high, int low) {
    if (high - low > 1) {
        int mid = ((high + low) / 2);

        if (userNum == mid) {
            cout << "Found your number: " << userNum << "!" << endl;
        }

        if (userNum > mid) {
            cout << "Low: " << low << " Mid: " << mid << " High: " << high << endl;
            low = mid;
            binarySearch(vect, userNum, high, low);
        }

        else if (userNum < mid) {
            cout << "Low: " << low << " Mid: " << mid << " High: " << high << endl;
            high = mid;
            binarySearch(vect, userNum, high, low);
        }
    }
}

int main() {

    initializeVect();
    
    int userNum;
    cout << "enter a value < 10000: ";
    cin >> userNum;

    linearSearch(userNum);
    cout << endl << endl;

    // binary search initializers
    int high = (vect.size() - 1);
    int low = vect[0];
    binarySearch(vect, userNum, high, low);

    cout << endl;
    return 0;
}
