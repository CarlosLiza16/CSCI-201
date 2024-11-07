/* Program name: M03 Programming Assignment Part 2
 * Author: Carlos Lizarazu
 * Date last updated: 11/07/2024
 * Purpose: The program will open a file with duplicated words, it will read the file and save the words in a set.
 * Finally the program will display all the words sorted and will eliminated all duplicated words.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

using namespace std;


//function to make sure we delete all the punctuation
string removePunctuation(const string& word) {
    string newWord;
    for (char c : word) {
        // If character is not a punctuation mark, add it to the result string
        if (!ispunct(c)) {
            newWord += c;
        }
    }
    return newWord;
}
int main(){
    //Variable that will insert the word in the set
    string word;
    int i=1;

    //creating the set
    set<string> uniqueWords;

    ifstream file("D:/Ivy Tech/Fall Semester 2024/CSCI - 201/C++ code/M03/M03_part2(1).txt");

    //checking if the file does not open
    if(!file){
        cout<<"Error opening the file!"<<endl;
        return 1;
    }

    

    //Read the file
    while(getline(file, word)){

        //extracting word by word from the file
        istringstream stream(word);
        string word;

        while(stream >> word){

            //check if the owrd has any punctuation
            word = removePunctuation(word);
            uniqueWords.insert(word);
            //cout<<i<<" "<<word<<endl;
            //i++;
            
        }
    }

    file.close();

    //display the set

    for(string listWord: uniqueWords){
        cout<<i<<" "<<listWord<<endl;
        i++;
    }
    return 0;
}