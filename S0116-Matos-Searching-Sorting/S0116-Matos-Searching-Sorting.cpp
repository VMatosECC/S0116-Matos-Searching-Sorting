// S0116-Matos-Searching-Sorting.cpp 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Prototypes -------------------------------------
void experiment01();
void experiment02();
void experiment03();
int binarySearch(vector<string>& vcountry, string countryName);
void bubbleSort(vector<int>& v);

int main()
{
    //experiment01();
    //experiment02();
    experiment03();

    cout << "\nAll done!\n";
}

//-----------------------------------------------------
// User-Defined functions
void experiment01()
{
    //Sequential search
    vector<string> vcountry;

    ifstream xcountry("c:/temp/xcountry.txt");
    if (!xcountry) {
        cout << "Error - file not found\n";
        exit(1);
    }

    //Read from disk - populate vector vcountry
    string countryName;
    while (getline(xcountry, countryName))
    {
        vcountry.push_back(countryName);
        //cout << "I READ " << countryName << endl;
    }
    xcountry.close();
    cout << "Number of countries: " << vcountry.size() << endl;

    //prompt user for a country name
    do {
        cout << "\nEnter a country [xxx to end]: ";
        getline(cin, countryName);
        if (countryName == "xxx") break;

        //sequential search
        bool found = false;

        for (int i = 0; i < vcountry.size(); i++) {
            if (vcountry[i] == countryName) {
                cout << "Country found at location " << i << endl;
                found = true;
                break;
            }
        }

        if (found == false) {
            cout << "Country not found\n";
        }

    } while (true);

}
 
//----------------------------------------------------------------------
void experiment02()
{
    //Binary search
    vector<string> vcountry;

    ifstream xcountry("c:/temp/xcountry.txt");
    if (!xcountry) {
        cout << "Error - file not found\n";
        exit(1);
    }

    //Read from disk - populate vector vcountry
    string countryName;
    while (getline(xcountry, countryName))
    {
        vcountry.push_back(countryName);
        //cout << "I READ " << countryName << endl;
    }
    xcountry.close();
    cout << "Number of countries: " << vcountry.size() << endl;

    //prompt user for a country name
    do {
        cout << "\nEnter a country [xxx to end]: ";
        getline(cin, countryName);
        if (countryName == "xxx") break;

        //Binary search
        int pos = binarySearch(vcountry, countryName);

        if (pos >= 0)
            cout << " country found at location " << pos << endl;
        else
            cout << " country not found \n";

    } while (true);

}
//------------------------------------------------------------
int binarySearch(vector<string>& vcountry, string countryName)
{
    int first = 0; 
    int last = vcountry.size() - 1;
    int mid;
    int counter = 0;

    while (first <= last) {
        mid = (first + last) / 2;
        cout << "DEBUG Bisection #" << ++counter << endl;
        if (vcountry[mid] == countryName)
            return mid;

        if (vcountry[mid] > countryName)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

//---------------------------------------------------------
void experiment03()
{
    vector<int> a { 222, 333, 777, 111, 222, 444, 555, 888 };
    bubbleSort(a);
    //show sorted vector
    for (int data : a) {
        cout << data << " ";
    }
    cout << endl;
}

//-------------------------------------------------------
void bubbleSort(vector<int>& v)
{
    for (int last = v.size() - 1; last > 0; last--)
    {
        for (int first = 0; first < last; first++)
        {
            if (v[first] > v[first + 1]) {
                //swap data cells
                int temp = v[first];
                v[first] = v[first + 1];
                v[first + 1] = temp;
            }
        }
    }
}