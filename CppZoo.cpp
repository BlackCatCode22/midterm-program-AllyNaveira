// References:
// https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/ 
// https://www.geeksforgeeks.org/substring-in-cpp/ 
// https://www.w3schools.com/cpp/cpp_functions.asp
// https://www.w3schools.com/cpp/cpp_switch.asp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Create 2D array for habitats
static string habitats[4][4];

string genUanimalID(string species, int numOfSpecies) 
{
    
    string uniqueID;

    if (species == "hyena") 
    {
        uniqueID = "hy0" + to_string(numOfSpecies);
    }
    else if (species == "lion") 
    {
        uniqueID = "li0" + to_string(numOfSpecies);
    }
    else if (species == "tiger") 
    {
        uniqueID = "ti0" + to_string(numOfSpecies);
    }
    else if (species == "bear") 
    {
        uniqueID = "be0" + to_string(numOfSpecies);
    }
    else 
    {
        uniqueID = "error";
    }

    return uniqueID;
}

// Takes two strings containing information on which animal we wish to generate a name for
// opens a file and reads from a list of names for each species of animal
string genAnimalName(string species, string ID)
{
    // Open a file and read from it
    string myTextStr;
    // create a string to save data from file
    string line;
    // Initialize variables used to find data elements in text string
    int lineNum = 0;
    int position = 0;
    int startPos = 0;
    int endPos = 0;
    string name;

    try 
    {
        // Create a text string, used to output the text file
        ifstream myFile("animalNames.txt");
        
        // Read the file line by line
        cout << "\n\n Contents of animalNames.txt ...";
        while (getline(myFile, myTextStr)) 
        {
            if (myTextStr.find(species) == 0)
            {
                getline(myFile, myTextStr);
                while(myTextStr=="")
                    getline(myFile, myTextStr);
                line = myTextStr;
                break;
            }
        }
        cout << "\n  End of animalNames.txt ...\n\n";
        // Close the file
        myFile.close();
    }
    catch (...) 
    {
        cout << "\nException caught! \n";
    }

    for(int i = 0; i < stoi(ID.substr(2,2)); i++)
    {
        startPos = position;
        endPos = line.find(",", startPos);
        name = line.substr(startPos, endPos - startPos);
        position = line.find(" ", startPos) + 1;
    }
    return name;
}

// Takes a string containg information on the animals and assigns them to their respective habitats
void genZooHabitats(string input)
{
    string species;
    int id;
    species = input.substr(0, 2);
    id = stoi(input.substr(2, 2));
    if (species == "hy") 
    {
        habitats[0][id-1] = input;
    }
    else if (species == "li") 
    {
        habitats[1][id-1] = input;
    }
    else if (species == "ti") 
    {
        habitats[2][id-1] = input;
    }
    else if (species == "be") 
    {
        habitats[3][id-1] = input;
    }
}


// genBirthDay() accepts an integer for years and a string for season
// returns birthdate as Month Day, Year
string genBirthDay(int years, string season) 
{
    int birthYear = 0;
    string birthDate;
    birthYear = 2023 - years;
    string monthDay;
    if (season == "spri") {
        monthDay = "Mar 21";
    }
    else if (season == "summ") {
        monthDay = "Jun 21";
    }
    else if (season == "fall") {
        monthDay = "Sep 21";
    }
    else if (season == "wint") {
        monthDay = "Dec 21";
    }
    else {
        monthDay = "Jan 1";
    }
    birthDate = monthDay + ", " + to_string(birthYear);
    return birthDate;
}



int main()
{
    // Open a file and read from it
    string myTextStr;

    // Create a one-dimensional array
    string lines[16];

    // Initialize variables used to find data elements in text string
    int lineNum = 0;
    int position = 0;
    int startPos = 0;
    int endPos = 0;
    int numOfHyenas = 0;
    int numOfLions = 0;
    int numOfTigers = 0;
    int numOfBears = 0;

    lineNum = 0;
    try 
    {
        // Create a text string, used to output the text file
        ifstream myFile("arrivingAnimals.txt");
        
        // Read the file line by line
        cout << "\n\n Contents of arrivingAnimals.txt ...";
        while (getline(myFile, myTextStr)) 
        {
            // Output one line at a time
            cout << "\n" << myTextStr;
            // Create an array line by line
            lines[lineNum] = myTextStr;
            lineNum++;
        }
        cout << "\n  End of arrivingAnimals.txt ...\n\n";
        // Close the file
        myFile.close();
    }
    catch (...) 
    {
        cout << "\nException caught! \n";
    }

    // The input file was opened, read into an array, and closed
    // Process a single element of the array
    // process each line, one at a time, until you have resolved all issues from the input file
    //string lines[i] = lines[3];
    for(int i = 0; i < 16; i++)
    {   
        cout << "\n\n" << lines[i] << "\n\n";
        // First line of arrivingAnimals...
        // 4 year old female hyena, born in spring, tan color, 70 pounds, from Friguia park, Tunisia
        // Parse the above line into birthday, species, sex, color, weight, origin.
        
        // Variables needed to process input data into output information.
        int numYears = 0;
        string sex;
        string species;
        string uniqueID;
        string birthSeason;
        string color;
        int weight = 0;
        string origin;
        string name;
        string habitats;

        // Get numYears to calculate birthdate
        // 2 chars starting at index 0, stoi(): string to int
        numYears = stoi(lines[i].substr(0, 2));
        cout << "\n numYears = " << numYears;

        // Find birthSeason
        // What will find() return if "born in" is not found?
        //   how will you handle this?
        position = lines[i].find("born in");
        cout << "\n position = " << position;
        if (position == -1)
            birthSeason = "N/A";
        else
            birthSeason = lines[i].substr(position + 8, 4);
        cout << "\n birthSeason = " << birthSeason;

        // Call the genBirthDay() function 
        cout << "\n Birth Date is... " << genBirthDay(numYears, birthSeason);

        // Find sex 
        // How many char spaces?
        position = lines[i].find(" ");
        position = lines[i].find(" ", position+1);
        position = lines[i].find(" ", position+1);
        startPos = position + 1;
        // find the end position
        endPos = lines[i].find(" ", startPos);
        sex = lines[i].substr(startPos, endPos - startPos);
        cout << "\n sex is... " << sex;

        // Find species
        // Notice that species follows sex, and is terminated with a comma, so we are already there!
        startPos = endPos + 1;
        endPos = lines[i].find("," , startPos);
        species = lines[i].substr(startPos, endPos - startPos);
        cout << "\n species is... " << species;

        // Now that we have a species, update the global variable for the species count (we will get rid 
        // of this when we code this up with classes and lists) and get a uniqueID.
        if (species == "hyena") 
        {
            numOfHyenas++;
            uniqueID = genUanimalID("hyena", numOfHyenas);
        }
        else if (species == "lion") 
        {
            numOfLions++;
            uniqueID = genUanimalID("lion", numOfLions);
        }
        else if (species == "tiger") 
        {
            numOfTigers++;
            uniqueID = genUanimalID("tiger", numOfTigers);
        }
        else if (species == "bear") 
        {
            numOfBears++;
            uniqueID = genUanimalID("bear", numOfBears);
        }
        else 
        {
            // error
        }

        cout << "\n uniqueID is... " << uniqueID;

        //Find color
        startPos = endPos + 1;
        startPos = lines[i].find("," , startPos) + 2;
        endPos = lines[i].find("," , startPos);
        color = lines[i].substr(startPos, endPos - startPos);
        cout << "\n Color is... " << color;

        //Find weight
        startPos = endPos + 1;
        endPos = lines[i].find("," , startPos);
        weight = stoi(lines[i].substr(startPos, endPos - startPos));
        cout << "\n Weight is... " << weight << " pounds";

        //Generate name
        name = genAnimalName(species, uniqueID);
        cout << "\n Name is... " << name;

        //Find origin
        startPos = lines[i].find("from");
        origin = lines[i].substr(startPos);
        cout << "\n Origin is... " << origin;

        lines[i] = uniqueID + "; " + name + "; " + to_string(numYears) + " years old; " + genBirthDay(numYears, birthSeason) + "; " + color + "; " + sex + "; " + to_string(weight) + " pounds; " + origin;
        genZooHabitats(lines[i]);
    }   

    try 
    {
        // Create a text string, used to output the text file
        ofstream myFile("zooPopulation.txt");
        
        // Read the file line by line
        cout << "\n\n Contents of zooPopulation.txt ...";
        for (int i = 0; i < 4; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                // Output one line at a time
                myFile << habitats[i][j] << "\n";
            }
        }
        cout << "\n  End of zooPopulation.txt ...\n\n";
        // Close the file
        myFile.close();
    }
    catch (...) 
    {
        cout << "\nException caught! \n";
    }
}