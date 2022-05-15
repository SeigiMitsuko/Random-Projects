// Jessica Nelle: May 1, 2022
// I just wanted to make a random drawing prompt generator.
// Things to add at a later time:
    // make words come from a txt file
        // completed May 10
    // Just remembered to make an option to repeat.  Start at the random number generator
        // completed May 15

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

int randomNum(int min, int max)
{
    return 0;
}

int main()
{
    srand((unsigned) time(0));
    int random1, random2, random3;

    bool repeatProgram = true;
    string answer;
    char answerChar;

        // open adgetives file
    ifstream fileA("Adjetives.txt");
    if(!fileA) 
    {
        cout << "Cannot open file";
        return 0;
    }

    string tempString;


        // read all words in file into an array
    string myAdjetives[25];
    int tempInt = 0;
    while(getline (fileA, tempString))
    {
        myAdjetives[tempInt] = tempString;
        tempInt++;
    }
    fileA.close();


        // open nouns file
    ifstream fileB("Nouns.txt");
    if(!fileB) 
    {
        cout << "Cannot open file";
        return 0;
    }


        // read all words in file into an array
    tempInt = 0;
    string myNouns[25];
    while(getline (fileB, tempString))
    {
        myNouns[tempInt] = tempString;
        tempInt++;
    }
    fileB.close();


        // open verbs file
    ifstream fileC("Verbs.txt");
    if(!fileC) 
    {
        cout << "Cannot open file";
        return 0;
    }

        // read all words in file into an array
    tempInt = 0;
    string myVerbs[25];
    while(getline (fileC, tempString))
    {
        myVerbs[tempInt] = tempString;
        tempInt++;
    }
    fileC.close();

    // first draft code commented out below

    //string myAdjetives[25] = {"thirsty", "selfish", "defective", "exuberant", "bent",
    //                            "freezing", "bouncy", "glistening", "goofy", "material",
    //                            "legal", "jobless", "precious", "sassy", "grey",
    //                            "unequaled", "naive", "honorable", "needy", "nice",
    //                            "nosy", "modern", "joyous", "blue", "happy"};
    //string myNouns[25] = {"butter", "engine", "doll", "corn", "hydrant", "twig", "stove",
    //                        "egg", "wheel", "sheet", "playground", "spiders", "church",
    //                        "discovery", "front", "bulb", "mind", "men", "reaction", 
    //                        "grain", "eye", "fire", "moon", "loss", "thumb"};
    //string myVerbs[25] = {"deserve", "owe", "sparkle", "close", "place", "attract",
    //                        "succeed", "desert", "flow", "jam", "carve", "grate",
    //                        "prevent", "rescue", "argue", "spoil", "report", "water",
    //                        "refuse", "check", "concern", "box", "measure", "join",
    //                        "change"};

    while(repeatProgram == true)
    {
            // assign random numbers to be used for each set of words
        random1 = (rand() % 25) + 1;
        random2 = (rand() % 25) + 1;
        random3 = (rand() % 25) + 1;

            // output words for the prompt
        cout << "The writing prompt for today is: " << myAdjetives[random1] << ", " << 
                                                    myNouns[random2] << ", " << 
                                                    myVerbs[random3] << endl;

        cout << endl << "Do you want to get a new prompt? Y/N:";
        cin >> answer;

        answerChar = answer.at(0);

        switch(answerChar)
        {
            case 'N':
                repeatProgram = false;
                break;
            case 'n':
                repeatProgram = false;
                break;
            case 'Y':
                repeatProgram = true;
                break;
            case 'y':
                repeatProgram = true;
                break;
            default:
                repeatProgram = false;
                break;
        }

    }

    return 0;
}
