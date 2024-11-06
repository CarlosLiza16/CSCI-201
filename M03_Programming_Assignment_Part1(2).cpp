/* Program name: M03 Programming Assignment Part 1 (2)
 * Author: Carlos Lizarazu
 * Date last updated: 11/05/2024
 * Purpose: This program creates a object for personal computers. THe user is able to enter as many computers they want.
 * THe program will validate the input from the user, and will display a list of all the personal computers created. 
 */

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// validation for the strings
bool validateStrings(const string &col) {
  while (true) {
    // Check if the input contains only letters and spaces
    bool isValid = true;
    for (char c : col) {
      if (!isalpha(c) && !isspace(c)) {
        isValid = false;
        return isValid;
      }
    }

    // If the input is valid, break the loop; otherwise, prompt again
    if (isValid && !col.empty()) {
      return isValid;
    } else {
      isValid = false;
      return isValid;
    }
  }
}

// Create the class for the Personal Computer
class Computer {
private:
  string manufacturer;
  string factor; //(laptop or desktop)
  int serialNumber;
  string processor;
  int ram;
  string storage;     //(UFS, SDD, HDD)
  string storageSize; //(1GB, 256GB, 1TB)

public:
  // Creating the struct, automacally created when an object is created
  Computer(string ma, string fa, int sN, string pr, int rm, string strg,
           string strgSize) {
    // attributes the user will set

    // validate the manufacturer
    if (!validateStrings(ma)) {
      throw invalid_argument(
          "ERROR: The manufacturer is invalid. Try entering just letters");
    }

    // Validate the factor
    if (!validateStrings(fa)) {
      throw invalid_argument(
          "ERROR: factor provided in not valid. Try entering just Letters");
    }

    // Validate the serial number
    if (sN <= 0) {
      throw invalid_argument("ERROR: The serial number is invalid");
    }

    // validate the ram
    if (rm <= 0) {
      throw invalid_argument("ERROR: RAM memory is invalid!");
    }
    // Validate the storage
    if (!validateStrings(strg)) {
      throw invalid_argument("ERROR: Storage type is invalid. TRY (SSD, HDD)");
    }

    // Assign the values
    manufacturer = ma;
    factor = fa;
    serialNumber = sN;
    processor = pr;
    ram = rm;
    storage = strg;
    storageSize = strgSize;
  }

  // Creating accessor methods
  string getManufacturer() { return manufacturer; }

  string getFactor() { return factor; }

  int getSerialNumber() { return serialNumber; }

  string getProcessor() { return processor; }

  int getRAM() { return ram; }

  string getStorage() { return storage; }

  string getStorageSize() { return storageSize; }

  // Creating the tostring method
  string toString() {
    stringstream ss;
    ss << manufacturer << " " <<factor << " " << serialNumber << " " << processor << " " << ram << "GB " << storage << " " << storageSize;
    return ss.str();
  }

  // creating the mutator methods
  void setRAM(int rm) {
    // validate the ram
    if (rm <= 0) {
      throw invalid_argument("ERROR: RAM memory is invalid!");
    }
    ram = rm;
  }

  void setStorage(string strg) {
    // Validate the storage
    if (!validateStrings(strg)) {
      throw invalid_argument("ERROR: Storage type is invalid. TRY (SSD, HDD)");
    }
    storage = strg;
  }

  void setStorageSize(string strgSize) { storageSize = strgSize; }
};

int main() {
  // variables for the user to enter
  string Manufacturer, Factor, Processor, Storage, StorageSize;
  int SerialNumber, Ram;
  Computer myComputer("a", "a", 1, "a", 1, "a", "a");
  
  //Variable for the option to edit or not
  string option;
  int change;

  vector<string> personalComputers;

  string answer="yes";
  
  while(answer=="yes"){
    try {
      // Prompt the user to enter values for stero

      cout << "Enter the manufacturer of the computer: ";
      cin >> Manufacturer;
      cout << "Enter the factor of the computer(laptop - desktop): ";
      cin >> Factor;
      cout << "Enter the serial number of the computer: ";
      cin >> SerialNumber;
      if (cin.fail()) {
        throw invalid_argument("Serial number must be a number");
      }

      cout << "Enter the processor of the computer: ";
      cin.ignore();
      getline(cin, Processor);
      cout << "Enter the the ram of the computer in GB: ";
      cin >> Ram;
      if (cin.fail()) {
        throw invalid_argument("Make sure you entering just numbers");
      }
      cout << "Enter the storage type of the computer: ";
      cin >> Storage;
      cout << "Enter the storage size of the computer (GB or TB): ";
      cin.ignore();
      getline(cin, StorageSize);

      // Create the object
      myComputer  = Computer(Manufacturer, Factor, SerialNumber, Processor, Ram,
                          Storage, StorageSize);

      // Display the objects
      cout<<"\nComputer created: "<<endl;
      cout <<myComputer.toString() << endl;

    } catch (const invalid_argument &message) {
      cout << "\n************************" << endl;
      cout << "ERROR: " << message.what() << endl;
    }


    //Let the user modify the information

    //ask if the user wnat to edit any information
    cout<<("\nWould you like to change the ram, storage type or size [yes] or [no]: ");
    cin>>option;

    if(option == "yes"){
         cout<<"1. Change Ram"<<endl;
         cout<<"2. Change storage type"<<endl;
         cout<<"3. Change storage size"<<endl;
         cin>>change;
         switch(change){
             case 1:
                 try{
                     //Prompt the use for the new values changed by the user
                     cout << "Enter the the ram of the computer in GB: ";
                     cin >> Ram;
                     if (cin.fail()) {
                       throw invalid_argument("Make sure you entering just numbers");
                     }
                     //setting the new values
                     myComputer.setRAM(Ram);
                  }
                  catch(const invalid_argument& message){
                    cout<<"\n************************"<<endl;
                    cout<<"ERROR: "<<message.what()<<endl;
                  }
                 break;
             case 2:
                  try{
                    //Prompt the use for the new values changed by the user
                     cout << "Enter the storage type of the computer: ";
                     cin >> Storage;
                    //setting the new values
                    myComputer.setStorage(Storage);
                  }
                 catch(const invalid_argument& message){
                   cout<<"\n************************"<<endl;
                   cout<<"ERROR: "<<message.what()<<endl;
                 }
                 break;
             case 3:
                  try{
                    //Prompt the use for the new values changed by the user
                      cout << "Enter the storage size of the computer (GB or TB): ";
                      cin.ignore();
                      getline(cin, StorageSize);
                    //setting the new values
                    myComputer.setStorageSize(StorageSize);
                  }
                 catch(const invalid_argument& message){
                   cout<<"\n************************"<<endl;
                   cout<<"ERROR: "<<message.what()<<endl;
                 }
                 break;
         }
    }

    //pushing the information in the vector
      personalComputers.push_back(myComputer.toString());
      //cout<<personalComputers[0];
    cout<<"Would you like to enter new computers [yes] or [no]: ";
    cin>>answer;
  }//end while

  cout<<"\nThe computers are: "<<endl;
  for(int i=0; i<personalComputers.size(); i++){
    cout<<"Personal computer number "<<i+1<<" : ";
    cout<<personalComputers[i]<<endl;
  }
  return 0;
}