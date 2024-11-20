/* Program name: M05 Programming Assignment 
 * Author: Carlos Lizarazu
 * Date last updated: 11/19/2024
 * Purpose: Create a class, and sub classes from that class (inherit classes).
 */


#include <iostream>
#include <string>
#include <type_traits> // for std::is_same_v
#include <limits> // Add this line to include the <limits> heade
#include <iomanip>

using namespace std;

// Create the class Beverage
class Beverage {
private:
  string name;
  string description;
  int servingSize;
  int calories;
  float price;

public:
  // Constructor, automatically created with an object
  Beverage(string nm, string descp, int serSize, int cal, float pr) {
    name = nm;
    description = descp;
    servingSize = serSize;
    calories = cal;
    price = pr;
  }

  // Accessor methods
  string getName(){ 
    return name; 
  }
  string getDescription(){
    return description;
  }
  int getServingSize(){
    return servingSize;
  }
  int getCalories(){
    return calories;
  }
  float getPrice(){
    return price;
  }

  //the string method , we use virtual becaus eof the overriding
  virtual string toString()const {
    stringstream fprice;
    fprice<< fixed << setprecision(2) << price;
    return "\n" + name + ", " + description + ", " + to_string(servingSize)+ "ml, "+
           to_string(calories)+ "calories, $" + fprice.str();
  }

  //destructor to clea up for derived classes
  virtual ~Beverage() = default;
}; // End of class


//Creating the coffe class
class Coffee : public Beverage{
  private:
  string hotCold;
  bool isCaffeinated;
  string roastType;
  string strength;
  string creamer;
  string sweetener;

  public:
  Coffee(string nm, string descp, int serSize, int cal, float pr, string hc, bool caffe,
  string roast, string str, string cream, string sweet):Beverage(nm, descp, serSize, cal, pr){
    
    hotCold = hc;
    isCaffeinated = caffe;
    roastType = roast;
    strength = str;
    creamer = cream;
    sweetener = sweet;
  }

  //Accessor methods
  string getHotCold() { return hotCold; }
  bool getIsCaffeinated() { return isCaffeinated; }
  string getRoastType() { return roastType; }
  string getStrength() { return strength; }
  string getCreamer() { return creamer; }
  string getSweetener() { return sweetener; }

  //to string function, overriden the previous from beverage
  string toString() const override{
    return Beverage::toString() + ", " + hotCold + ", " + 
      (isCaffeinated ? "Caffeinated" : "Decaffeinated") //if/else statement
      + ", Roast: " + roastType + ", Strength: " + strength + ", Creamer: " + creamer 
      + ", Sweetener: " + sweetener;
  }
};

//Creating the Tea Class
class Tea : public Beverage{
  private:
    string type;
    string hotCold;
    string creamer;
    string sweetener;
    bool hasLemon;

  public:
    // Constructor automatically created with an object
    Tea(string nm, string descp, int serSize, int cal, float pr, string t, string hc, 
        string cream, string sweet, bool lemon) : Beverage(nm, descp, serSize, cal, pr) {
      
      type = t;
      hotCold = hc;
      creamer = cream;
      sweetener = sweet;
      hasLemon = lemon;
    }

    // Accessor methods
    string getType() { return type; }
    string getHotCold() { return hotCold; }
    string getCreamer() { return creamer; }
    string getSweetener() { return sweetener; }
    bool getHasLemon() { return hasLemon; }

  //to string function, overriden the previous from beverage
  string toString() const override{
    return Beverage::toString() + ", " + type + ", hot/cold: " + hotCold + 
      ", Creamer: " + creamer + ", Sweetener: " + sweetener + ", Lemon: " 
      + (hasLemon ? "Yes" : "No");//lemon is be if/else 
                     
  }
};

//Creating the soda Class
class Soda : public Beverage{
  private:
    string brand;
    string type;
    bool diet;

  public:
    // Constructor automatically created with an object
    Soda(string nm, string descp, int serSize, int cal, float pr, 
         string br, string t, bool dt) : Beverage(nm, descp, serSize, cal, pr) {
      
      brand = br;
      type = t;
      diet = dt;
      
    }

    // Accessor methods
    string getBrand() { return brand; }
    string getType() { return type; }
    bool getDiet() { return diet; }

  //to string function, overriden the previous from beverage
  string toString() const override{
    return Beverage::toString() + ", brand: " + brand + ", Type: " + type + 
      ", Diet: " + (diet ? "Yes" : "No");//diet is be if/else 
  }
};


//Creating the Energy Drink Class
class Energydrink : public Beverage{
  private:
    string brand;
    string stimulant;
    string sweetener;

  public:
    // Constructor automatically created with an object
    Energydrink(string nm, string descp, int serSize, int cal, float pr, 
         string br, string stml, string swtn) : Beverage(nm, descp, serSize, cal, pr) {
      
      brand = br;
      stimulant = stml;
      sweetener = swtn;
      
    }

    // Accessor methods
    string getBrand() { return brand; }
    string getStimulant() { return stimulant; }
    string getSweetener() { return sweetener; }

  //to string function, overriden the previous from beverage
  string toString() const override{
    return Beverage::toString() + ", brand: " + brand + ", Stimulant: " + stimulant + 
      ", Sweetener: " + sweetener;
  }
};


// Template function to handle input
template <typename T>
T input(const string& prompt) {
  T variable;
  cout << prompt;cin>>variable;
  return variable;
}
//for the string
string inputString(const string& prompt) {
  string str;
  cout << prompt; getline(cin, str);
  return str;
}

//display function
void display(const Beverage& drink){
  cout<<drink.toString()<<endl;
}

// Main function
int main() {

  try
  {
    string name = inputString("Enter the name of the drink: ");
    if(name!="coffee" && name!="tea" && name!="soda" && name!="energy drink"){
      throw invalid_argument("Currently we only have coffee, tea, soda, and energy drink");
    }

    string description = inputString("Enter the description of the drink: ");
    int size = input<int>("Enter the serving size of the drink: "); 
    int calories = input<int>("Enter the calories of the drink: ");
    float price = input<float>("Enter the price of the drink: ");
    cin.ignore();

    //create the beverage
    Beverage mydrink(name, description, size, calories, price);

    //display
    display(mydrink);


    if(name == "coffee"){ 
      // Create the coffee
      string hotCold = inputString("\nIs the coffee hot or cold? ");
      bool isCaffeinated = input<bool>("Would you like the coffee caffeinated (1 for yes, 0 for no)? ");
      cin.ignore();
      string roastType = inputString("Enter the roast type (Light, Medium, Dark): ");
      string strength = inputString("Enter the strength of the coffee (Weak, Medium, Strong): ");
      string creamer = inputString("Enter the creamer (none, milk, soy): ");
      string sweetener = inputString("Enter the sweetener (none, sugar, honey): ");
      // Create the Coffee object
      Coffee myCoffee(name, description, size, calories, price, hotCold, isCaffeinated, roastType, 
                      strength, creamer, sweetener);

      // Display the coffee details
      display(myCoffee);
    }
    else if (name == "tea"){
      //create the tea object
      string teatype = inputString("\nWhat kind of tea would like? (Black, Green, etc): ");
      string teaHotCold = inputString("is the tea hot or cold? ");
      string teaCreamer = inputString("Enter the creamer (none, milk, soy): ");
      string teaSweeter = inputString("Enter the sweetener (none, sugar, honey): ");
      bool lemon = input<bool>("Would you like lemon with your tea (1 for yes, 0 for no)? ");
      cin.ignore();
      //Creating a tea object
      Tea mytea(name, description, size, calories, price, teatype, teaHotCold, teaCreamer, teaSweeter, lemon);
      display(mytea);
    }
    else if(name == "soda"){
      //create the tea object
      string sodaBrand = inputString("\nWhat is the brand of the soda? ");
      string sodaType = inputString("What type of soda do you have? ");
      bool sodaDiet = input<bool>("Would you like your soda diet (1 for yes, 0 for no)? ");
      cin.ignore();
      //Creating a tea object
      Soda mySoda(name, description, size, calories, price, sodaBrand, sodaType, sodaDiet);
      display(mySoda);
    }
    else if(name == "energy drink"){
      //create the tea object
      string energyBrand = inputString("\nWhat is the brand of the energy? ");
      string energyStimulant = inputString("What type of stimulant does it have? ");
      string energySweetener = inputString("Enter the sweetener: ");

      //Creating a tea object
      Energydrink myEnergyDrink(name, description, size, calories, price, energyBrand, energyStimulant, energySweetener);
      display(myEnergyDrink);
    }
  }
  catch(const invalid_argument& message){
    cout<<"\n";
    cout<<"******************************"<<endl;
    cout<<"ERROR: "<<message.what()<<endl;
  }
  
  return 0;
}
