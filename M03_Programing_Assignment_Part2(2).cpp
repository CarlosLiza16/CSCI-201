/* Program name: M03 Programming Assignment Part 2
 * Author: Carlos Lizarazu
 * Date last updated: 11/07/2024
 * Purpose: The program will open a file, save the informaion in a map.
 * Then the user will be able to enter the abreviation of any state. 
 * The program will display the abbreviation, the full name of the state,
 * the current Governos of the State and the state flower.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

//create the struct
struct state{
    string fullState;
    string governor;
    string stateFlower;
};

int main(){

    //creating the map, string will be the abreviation, and state is the struct
    map<string, state> stateMap;

    //Variables
    string line, abbreviation, fullName, governor, stateFlower, userInput;

    //open the file
    ifstream file("D:/Ivy Tech/Fall Semester 2024/CSCI - 201/C++ code/M03/M03_statesList.txt");

    //check if the file opens
    if(!file){
        cout<<"Error: the opening cannot open"<< endl;
        return 1;
    }

    while(getline(file, line)) {
        stringstream ss(line);

        //read each word form the line
        ss>> abbreviation;
        ss>> fullName;
        ss>>governor;
        getline(ss, stateFlower);

        //this code with help remove every extra space after the last word in the line
        if(!stateFlower.empty() && stateFlower[0] == ' '){
            stateFlower = stateFlower.substr(1);
        }

        //create the state in the map
        stateMap[abbreviation] = {fullName,governor,stateFlower};
    }

    file.close();

    while(true){
        cout<<"Enter the abbreviation of the state or 'exit' to quit: ";
        cin>>userInput;

        //exiting the code if the user wnats to exit
        if(userInput=="exit"){
            cout<<"Exiting program."<<endl;
            break;
        }

        //checking in hte map to see if the user input is correct
        auto it = stateMap.find(userInput);
        if (it != stateMap.end()){
            cout<<"\nTHe information is: "<<endl;
            cout<<"\nAbbreviation: "<<it->first<<endl;
            cout<<"State: "<<it->second.fullState<<endl;
            cout<<"Governor: "<<it->second.governor<<endl;
            cout<<"State Flower: "<<it->second.stateFlower<<endl;
        }else{
            cout<<"\nError: the abbreviation was not find. Try again: ";
        }

    }

    return 0;
}