/*
	Title:      TravelAgent.cpp
	Author:     Joey Borrelli
	Date:       2-3/29-1/Anno Domini 2024
    Per Ipsum, et cum Ipso, et in Ipso, est tibi Deo Patri omnipotenti, in unitate Spiritus Sancti, omnis honor et gloria per omnia saecula saeculorum.
*/

#include "LinkedList.h"
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>

void printGavin();

int main(){
    LinkedList<Destination*> myLinkedList;
    std::cout << "Hello! My name is Gavin O Cleirigh and I am your professional travel agent, tour director, and guide!\n";
    printGavin();
    
    // open the file
    std::ifstream file;
    file.open("placeFile.txt");

    if(!file){ // if the file isn't open
        std::cout << "ERROR: Unable to open file input.txt\n";
        return 1;
    }else{ // if the file is open
        std::string tempString; // create a string variable to hold the current line
        
        /* temporary variables to hold from the text file before I create my destination object. */
        std::string tempName, tempDesc;
        float tempCost;
        int tempDanger;
        
        int i = 0; // this integer is used for incrimination and keeping track of what variable im on.
        while(getline(file, tempString, '#')){
            i++; // increment i val
            switch(i){
                case 1: // name
                    tempName = tempString;
                    break;
                case 2: // description
                    tempDesc = tempString;
                    break;
                case 3: // Cost
                    tempCost = std::stof(tempString);
                    break;
                case 4: // Danger
                    tempDanger = std::stoi(tempString);
                    
                    { // Compiler was throwing a error: jump to case label, and these brackets fix it apparently.
                        Destination* myDestination = new Destination(tempName, tempDesc, tempCost, tempDanger); // create object
                        myLinkedList.insertNode(myDestination); // place the new Destination into the linked list.
                    }

                    i = 0; // reset i val
                    break;
                default: 
                    std::cout << "dawg its broken";
                    break;
            }
        }

        // Close the file
        file.close();
    }


    /* Next, print out all the destinations that are now in the Linked List.  
    You can do this by having a for loop that will go from 0 to the number of nodes in the Linked List (call the getLength function) 
    and then in the for loop you will call the getNodeValue function (sending the position of the node you want) 
    and the function should return the value (which is a pointer to the Destination).  
    Then, you can print out the Destination.*/
    for(int i = 0; i < myLinkedList.getLength(); i++){
        std::cout << "**********DESTINATION #" << i+1 << "**********\n";
        std::cout << *myLinkedList.getNodeValue(i);
        std::cout << std::endl;
    }

    /* Now you will ask the user four questions.  
    This is to give the customer the false thought that you are actually choosing a destination based on something personal about them.  
    The first question needs to be their name (including spaces).  The second question needs to be their salary.  
    If the user enters a letter instead of a number then force them to re-enter their data and make sure it is a positive number.  
    The third and fourth questions can be whatever you want but they have to be yes/no questions.  
    Read in the user’s answer as a char (‘y’ or ‘n’).  If the user did not enter a character or did not enter in a ‘y’ or a ‘n’ then force them to re-enter their data.  
    You can validate the user’s data type to make sure it matches the variable you are reading into easily with !cin.  
    Look at my program segment below to check if the user entered in a character.*/
   
    std::string name; // customer name
    char likesFP; // likes fruity pebbles
    char thinksEF; // thinks earth is flat
    int grossAnnualIncome; // customers gross annual income

    std::cout << "********************************************************************************\n";
    std::cout << "Please answer the following four questions and I will determine the place you should travel.\n";
    
    std::cout << "          1. What is your full name? ";
    std::getline(std::cin, name);

    std::cout << "          2. How much money do you make per year? ";
    std::cin >> grossAnnualIncome;
    // Input validation
    while(!cin || grossAnnualIncome < 0){
        std::cin.clear(); // removes all error flags on the stream
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n'); // removes all leftover characters or numbers from keyboard buffer to start with fresh input.   
        std::cout << "Oops!  You entered something wonky.  Please enter a number with no symbols or commas.\n";
        std::cout << "          2. How much money do you make per year? ";
        std::cin >> grossAnnualIncome;
    }

    std::cout << "          3. Do you like the taste of fruity pebbles cereal? (y or n)? ";
    std::cin >> likesFP;
    // Input validation
    while((likesFP != 'y') && (likesFP != 'n')){
        std::cin.clear(); // removes all error flags on the stream
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n'); // removes all leftover characters or numbers from keyboard buffer to start with fresh input.   
        std::cout << "Oops!  You entered something wonky.  Please enter the letter y or n.\n";
        std::cout << "          3. Do you like the taste of fruity pebbles cereal? (y or n)? ";
        std::cin >> likesFP;
    }

    std::cout << "          4. Is planet Earth flat? (y or n)? ";
    std::cin >> thinksEF;
    // Input validation
    while((thinksEF != 'y') && (thinksEF != 'n')){
        std::cin.clear(); // removes all error flags on the stream
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n'); // removes all leftover characters or numbers from keyboard buffer to start with fresh input.   
        std::cout << "Oops!  You entered something wonky.  Please enter the letter y or n.\n";
        std::cout << "          4. Is planet Earth flat? (y or n)? ";
        std::cin >> thinksEF;
    }

    // Print out user's answers
    std::cout << std::endl << std::endl << name << ", based on your salary ($" << grossAnnualIncome << ") and the fact that you";
    if(likesFP != 'y'){
        std::cout << " don't";
    }
    std::cout << " like Fruity Pebbles cereal and you";
    if(thinksEF != 'y'){
        std::cout << " don't";
    }
    std::cout << " think that Earth is flat, you are going to travel to the following Destination!\n\n\n";

    /* Now, generate a random number between 0 and the number of nodes in the linked list (subtracting 1).  
    You will then call the getNodeValue Linked List function to get the value of the node at this position number.  
    Sample output is below.*/
    srand(time(0));

    int randomNumber = rand() % myLinkedList.getLength(); // generate random number

    std::cout << *myLinkedList.getNodeValue(randomNumber); // print out destination

    /* Last, print “HAVE FUN!!”*/
    std::cout << "\nHAVE FUN!!";
    
    return 0;
}

void printGavin(){
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ".,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,%@@@,@@@@&@@,&#,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,%@@@@@@@@@@@@@@@@@@@@@@@@@@@@*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@%,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,&@@@@@@(@@@@@@@@@@@&@@(@%@@@@@@@@@@%,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@@@@@@&@@@@@@@@(@%@@@@@@@@@@@@#@@@@@/,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,/@@@@@@@@@@@@(@@@@@@@@@@@@(@@@@@@@@@@@@@@@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@@@@@@@@@,,,/@@@@@@@@@@@@@@@@,,,,@@@@@%,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,/@@@@@@@@@@@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@@@@@@/,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@@@@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*@@@@@@@@@@@@%,,,,,,,,,*@@@@#,,,,,,,,,/@@@@@@*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@@@@@,&,,,,,,,@@,,,,,,,,,,,,,,,,,,,,@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@@@@,,,,,,,,,,,,,(*,,,,,,,,,,,,,,,,@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,&@@@@@@@@,,,,,,,,,,,,/@@@@ @/,,,,,.(/@* ,@@.,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@@@@@@@@@,,,,,,,,,,,,,,,,,,,,,,,,,.@/,*,,@@&,,,,,,,,,,,,,,,,,,,@@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@,@@@@,,@@@@,,,,,,,,,,,,,,,....,,,,,...@,..,@@&,,,,,.,,,,,,,,,,,@@,...@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@(,,,,@%,,%,,,,,,,,,,,,,,,...,,,,,,,,...@,,,,@@,,,,,,,,,,,,,,,,,@@,,...@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@,,/@,@,,,,,,,,,,,,,,,,,,,,/,,*,,(&@,,&,,@,,@@,,,,,,,,,,,,,,,,,@@,,...@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@/,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@,@@,,,,,,,,,,,,,,,,,@@,,,..@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*@@,,,@@,,,,,,,,,,,,,,,,,@@#,         @,#@@,,,,,,,,,,,,,,,,,,@@,,..@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,#@@@@(,,,,,,,,,,,,,,,,,,&@@     #@@,,,@@,,,,,,,,,,,,,,,,,,@&,...@@@@@@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,*,,,@@,,,,,,,,,,,,,,,,,,,@,,,..@#,(......(@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@,,,,,,,,,,,,,,,,,,,,,,,....,,@@,,,,,,,,,,,,,,,,,,,@@,,,,@,,,,..........%@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,(@@@,,,,@,,,,,,,,,,,,,,,,,,,,,,@@#,,,,,,,,,,,,,,,,,,/@,,,,,@@(,,..,%@#....@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,%@@@,@,,,,,,,,,,,,,,,,,,,,,,,,@@@,,,,,,,,,,,,,,,,,,,@@,,,,@,,,#.........../@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,.,,,,,,,,,,,,,,,,,,,,,,,,,,,@@#@@@*/@,,,,,,,,#@@@@@@@@@@@@@@,,,,,,,.,,,,,,,,,,,,,@@,,,,@,,,,,,...........@@,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@       @@@@@&,,,,,@@@@@@@@@@@@@@@,,,,,,,,,,,,,,,,,,,*@,,,,,@,,,............@@*,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@              *@@@@#@@@@@@@@@@    @@@,,,,,,,,,,,,,,,,@(,,,@.,,,............@@.,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.@@@@@@@@@@@                ( @@@@@@@@@    *@@@@@@@,,,,,,,,,,.(@@,,,,@,,,,..,(#*/.../@#,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,(@@@@@@@@@@@@@###@@@@%        ,@@@@&&@@@@@@@  @@@@@&@@@@@@@@@@,,,,,,*@&,,,,#@,,,,.........@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,,,,,,(@@@@@@@@@@@@#############@@@@@@* @@@@@     @@@@@@@@@@@@@#######%@@@@@@,,,*@@@,,,,,,@@,,,,,,,,@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,,,(@@@@@@@@@@@%%#####################%@@@@@@@        @@@@@@@@@#########@###@@@@@*,@@@@,,,,,,,,,&@@@@@&,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,,,@@@@@@@@##############@@&##############@####%@@@@@@@@@@@@@@#############@@@##@@@@@#@@@,,,,,,,,,,,,,,@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,,@@@@@@###############@@@#########################&@@&%####%@@%#############%@@@@%@@@@@@@@,,,,,,,,,,,,,,,%@@@.,,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,,,@@@@@@####################@@@@################################################@@@@@@@@@@@@@,,,,,,,,,,,,,,,,*@@@,,,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << ",,,,,,,,,,,@@@@@@@#########################@@@##########################################@@@@@@@@@@@@@@@@@@,,,,,,,,,,,,,,,,,@@@,,,,,,,,,,,,,,,,,,,,,,,,\n";
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n";
}