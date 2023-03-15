// Jessica Nelle: May 1, 2022
// I just wanted to make a random drawing prompt generator.
// Things to add at a later time:
    // make words come from a txt file
        // completed May 10
    // Just remembered to make an option to repeat.  Start at the random number generator
        // completed May 15, 2022
    // After some time away, I've decided to make an option to decide what kind of prompt
    //you want.
        // first on the list, get two animals and an option to draw one or a combo
            // completed March 15, 2023

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

    // open animals file
    ifstream fileD("Animals.txt");
    if(!fileD)
    {
        cout << "Cannot open file";
        return 0;
    }
        // read all words in file into an array
    tempInt = 0;
    string myAnimals[734];
    while(getline (fileD, tempString))
    {
        myAnimals[tempInt] = tempString;
        tempInt++;
    }
    fileD.close();

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
        cout << "Do you want to draw an animal (A) or get a three-word prompt(B)?" << endl;
        cin >> answer;
        
            // display the prompt
        if(answer == "A" || answer == "a")
        {
                // set random numbers for the animal(s) chosen and whether to draw one
                // or a combo
            random1 = (rand() % 734) + 1;
            random2 = (rand() % 734) + 1;
            random3 = (rand() % 2) + 1; // if 1, it's a single animal. 2 is a combo

                // just in case the two animals are the same
            if(random1 == random2)
            {
                random3 = 1;
            }
                // just in case random3 turns out to be 0. 
                // probably won't happen, but better safe than sorry.
            if(random3 == 0)
            {
                random3 = 1;
            }
            
            switch(random3)
            {
                case 1:
                    cout << "The animal you are to draw is: " << myAnimals[random1] 
                    << endl;
                    break;
                case 2:
                    cout << "The animal you are to draw is a combination between " 
                        << myAnimals[random1] << " and " << myAnimals[random2] << endl;
                    break;
            }

        } 
        else if(answer == "B" || answer == "b")
        {
                // assign random numbers to be used for each set of words
            random1 = (rand() % 25) + 1;
            random2 = (rand() % 25) + 1;
            random3 = (rand() % 25) + 1;

                // output words for the prompt
            cout << "The writing prompt for today is: " << myAdjetives[random1] << 
                    ", " << myNouns[random2] << ", " << myVerbs[random3] << endl;
        }
        else
        {
            cout << "You didn't pick a choice." << "\n";
        }
        

        cout << endl << "Do you want to get a new prompt? Y/N:" << endl;
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
