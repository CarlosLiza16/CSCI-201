/* Program name: M04 Programming Assignment Part 2
 * Author: Carlos Lizarazu
 * Date last updated: 11/12/2024
 * Purpose: The program will create a class for a nerfgun. The gun will be able to fire and reload.
 * The class will also work with overload operators to look for the maximum ammunition, fire, reload 
 * and display the informaiton of the gun after that.
 */

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// Create the class for the nerfGun
class Nerfgun {
private:
  string model;
  int range;
  int capacity;
  int numberDarts;

public:
  // Creating the struct, automacally created when an object is created
  Nerfgun(string mo, int rg, int cpct, int nD) {
    // Validating parameters
    if (cpct > 144) {
      throw invalid_argument(
          "ERROR: the capacity of the gun cannot exceed 144");
    }

    if (nD > cpct) {
      throw invalid_argument(
          "ERROR: darts cannot exceed the capacity of the gun");
    }
    // Assign the values
    model = mo;
    range = rg;
    capacity = cpct;
    numberDarts = nD;
  }

  // Creating accessor methods
  string getModel() { return model; }

  int getRange() { return range; }

  int getCapacity() { return capacity; }

  int getNumberDarts() { return numberDarts; }


  // New fire method
  void fire() {
    if (numberDarts <= 0) {
      throw invalid_argument("ERROR: There are no darts left in the gun");
    }
    numberDarts--;
  }

  // reload method
  void reload(int quantity) {
    if (quantity < 0) {
      throw invalid_argument("ERROR: we cannot reload a negative number");
    }
    if ((numberDarts + quantity) > capacity) {
      throw invalid_argument("ERROR: the reload goes beyond the capacity");
    }
    numberDarts += quantity;
  }

  // adding the overload operators

  // Overload for the same amount of ammunition
  bool operator==(const Nerfgun &other) {
    return this->numberDarts == other.numberDarts;
  }

  // Overload for if an gun has lees ammunition that another one
  bool operator<(const Nerfgun &other) {
    return this->numberDarts < other.numberDarts;
  }
  // overload for prefix
  Nerfgun &operator--() {
    fire(); // call the fire, and reduces one
    return *this;
  }
  // overload for the postfix
  Nerfgun operator--(int) {
    Nerfgun temp = *this; // creates a copy of the current Nerfgun
    fire();               // decrease the darts
    return temp;          // returns the value before the decrement
  }
  // Overload for the reloaded
  Nerfgun &operator+=(int quantity) {
    reload(quantity);
    return *this;
  }
  // Overload the << to print
  friend ostream &operator<<(ostream &os, const Nerfgun &ng) {
    os << "Model: " << ng.model 
       << " - Range: " << ng.range
       << " - Capacity: " << ng.capacity
       << " - Number of darts: " << ng.numberDarts;
    return os;
  }
};

int main() {

  // Creating vector
  vector<Nerfgun> personalGuns;
  try {
    Nerfgun myGun1("Beretta", 25, 35, 20);
    personalGuns.push_back(myGun1);

    Nerfgun myGun2("Sig Sauer", 50, 20, 20);
    personalGuns.push_back(myGun2);

    Nerfgun myGun3("Ak47", 300, 50, 50);
    personalGuns.push_back(myGun3);

    Nerfgun myGun4("Airsoft", 450, 50, 50);
    personalGuns.push_back(myGun4);

    Nerfgun myGun5("Revolver", 10, 10, 10);
    personalGuns.push_back(myGun5);

    //For loop to print all the guns in the vector
    cout<<"Initial status of the guns\n"<<endl;
    for (int i = 0; i < personalGuns.size(); i++) {
      cout <<"\n"<<i+1<<" "<< personalGuns[i] << endl;
    }
    
    //Show each gun individually
    //cout<< myGun1;

    //Comparing guns and looking for the the one with most ammunition
    Nerfgun maxGun = personalGuns[0];
    for (int j = 0; j < personalGuns.size(); j++) {
      if(personalGuns[j].getNumberDarts() > maxGun.getNumberDarts()){
        maxGun = personalGuns[j];
      }
    }
    cout<<"\nThe gun with maximum amount of ammunition is: "<<endl;
    cout<<maxGun<<endl;

    //Operation are happening here
    cout<<"\nOperations start here: \n"<<endl;
    
    for(int h=0; h<personalGuns.size(); h++){
      //Randomly fire and reload guns
      random_device rd;
      //This is a high-quality random number generator that produces numbers with good distribution.
      mt19937 gen(rd());
      //generates number between 1-5
      uniform_int_distribution<> dist(1,5);

      //Select a random gun from the vector
      int gunIndex = rand() % personalGuns.size();

      //either fire or reaload
      if (dist(gen) <= 3 && personalGuns[gunIndex].getNumberDarts()>0){
        cout<<personalGuns[gunIndex].getModel()<<" fired"<<endl;
        personalGuns[gunIndex]--;
      }else{
        int reloadAmount = rand() % 5+1; // reload amount betwen 1 and 5
        cout<< "Reloading gun: "<< personalGuns[gunIndex].getModel()<<endl;
        personalGuns[gunIndex] += reloadAmount;
      }

      //display guns after the operations
      cout<<personalGuns[gunIndex]<<endl;
    }
    
    
    
  } catch (const invalid_argument &message) {
    cout << message.what() << endl;
  }

  return 0;
}