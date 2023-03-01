// dH fileIO.cpp 2/28/23

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    // Open a file and read from it
    string myTextStr;

    // Create a one-dimensional array
    string lines[16];
    int lineNum = 0; 

    lines[lineNum] = " this that and the other";

    try {
        // Create a text string, used to output the text file
        ifstream myFile("C:/cStuff/arrivingAnimals.txt");
        // Read the file line by line
        cout << "\n\n Contents of C:/cStuff/arrivingAnimals.txt ...";
        while (getline(myFile, myTextStr)) {
            cout << "\n" << myTextStr;
            lines[lineNum] = myTextStr;
            lineNum++;
        }
        cout << "\n  End of C:/cStuff/arrivingAnimals.txt ...\n\n";
        // Close the file
        myFile.close();
    }
    catch (...) {
        cout << "\nException caught! \n";
    }

    // Let's look at our array...
    cout << "\n\n" << lines[3];
    cout << "\n\n" << lines[2];
    cout << "\n\n" << lines[1];
    cout << "\n\n" << lines[0];
    cout << "\n\n";
    cout << "\n" << lines[0].substr(",", 12);




   
}