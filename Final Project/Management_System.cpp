/* Program name: Final Projet - Management System
* Author: Carlos Lizarazu 
* Date last updated: 12/13/2024
* Purpose: The Management System is designed to streamline to track office inventory. 
* Allow users to register new items arriving at the office, update inventory as items are used, add new employees, and place orders for more products. 
* The program will also be able to handle incorrect wrong information and tell user where is the error happening. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iostream>
#include <fstream>  



using namespace std;

//Creating the class for the user
class User
{
    private:
    int userID;
    string userName;
    string userRole;
    public:
    User(int uID, string uName, string uRole)
    {
        userID = uID;
        userName = uName;
        userRole = uRole;
    }
    
    //Creating the accesor methods
    int getUserID(){ return userID; }
    string getUserName(){ return userName; }
    string getUserRole(){ return userRole; }

    //String method to return a string value
    virtual string toString()const {
        return to_string(userID) + " - " + userName + " - " + userRole;
    }

    //desctructor to clean up for derived classes 
    virtual ~User() = default;
};

//Creating inherit class for the user
class Position : public User
{
    private:
    string title;
    string supervisor;
    string department;

    public:
    //Creating object
    Position(int uID, string uName, string uRole, string ttl, string spvs, string dpt):User(uID, uName, uRole){
        title = ttl;
        supervisor = spvs;
        department = dpt;
    }

    //Creating accessor methods for employee
    string getTitle(){ return title; }
    string getSupervisor(){ return supervisor; }
    string getDepartment() {return department; }

    //to string function, overriden the previous from beverage
    string toString() const override{
        return User::toString() + " - " + title + " - " + supervisor + " - " + department;
  }
};


//Creating class for the orders
class Order
{
    private:
    int employeeID;
    string item;
    public:
    Order (int eID, string it)
    {
        employeeID = eID;
        item = it;
    }
    
    //Creating the accesor methods
    int getEmployeeID(){ return employeeID; }
    string getItem(){ return item; }

    //String method to return a string value
    virtual string toString()const {
        return to_string(employeeID) + " - " + item;
    }

};


//Creating the add item class

class Additem
{
    private:
    int itemID;
    string itemName;
    string itemDescription;
    int itemQuantity;
    string itemCategory;
    public:
    Additem(int iID, string iName, string iDes, int iQtt, string iCat)
    {
        itemID = iID;
        itemName = iName;
        itemDescription = iDes;
        itemQuantity = iQtt;
        itemCategory = iCat;
    }
    
    //Creating the accesor methods
    int getItemID(){ return itemID; }
    string getItemName(){ return itemName; }
    string getItemDescriptino(){ return itemDescription; }
    int getItemQuantity(){ return itemQuantity; }
    string getItemCategory(){ return itemCategory; }

   //String method to return a string value
    virtual string toString()const {
        return to_string(itemID) + " - " + itemName + " - " + itemDescription + " - " + to_string(itemQuantity) + " - " + itemCategory;
    }

    //desctructor to clean up for derived classes 
    virtual ~Additem() = default;

};

//Creating inherit class for the add item class
class Category : public Additem
{
    private:
    string catDescription;
    string catBrand;

    public:
    //Creating object
    Category(int iID, string iName, string iDes, int iQtt, string iCat, string cD, string cB) : Additem(iID, iName, iDes, iQtt, iCat){
        catDescription = cD;
        catBrand = cB;
    }

    //Creating accessor methods for employee
    string getCatDescription(){ return catDescription; }
    string getCatBrand(){ return catBrand; }

    //String method to return a string value
    virtual string toString()const override{
        return Additem::toString() + " - " + catDescription + " - " + catBrand;
    }
};



//Function for the input
//validation for the integer numbers
int validateIntegers(const string& prompt) 
{
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "You must enter a valid number. Try again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

//validation for the strings
//validation for the strings
string validateStrings(const string& prompt)
{
    string col;

    while (true){
        cout<<prompt;
        cin.ignore(); //clen the buffer - empty space
        
        getline(cin, col); // Read the whole line

        // Check if the input contains only letters and spaces
        bool isValid = true;
        for (char c : col) {
            if (!isalpha(c) && !isspace(c) && c != ',') {
                isValid = false;
                break;
            }
        }

        // If the input is valid, break the loop; otherwise, prompt again
        if (isValid && !col.empty()) {
            break;
        } else {
            cout << "You must enter a word, do not use numbers."<< endl;
        }
   }

   return col;
}


//funtion to add a new user
string addnewuser(){
    //variables for the add a new user
    int userid;
    string username, userrole, title, supervisor, department;

    userid = validateIntegers("Enter your employee id: ");
    username = validateStrings("Enter your First Name and Last Name: ");
    userrole = validateStrings("Enter your role (Admi - Staff):");

    //Create the new user
    User newUser(userid, username, userrole);

    //Create the position inherit class
    title = validateStrings("Enter the title of your position:");
    supervisor = validateStrings("Enter your supervisor:");
    department = validateStrings("Enter your department:");

    //Create the inherit position of the user
    Position userPosition(userid, username, userrole, title, supervisor,department);

    ofstream outfile ("D:/Ivy Tech/Fall Semester 2024/CSCI - 201/C++ code/Final Project/employee_list.txt", ios::app);
    if (!outfile) {
        cout << "Error opening file for writing!" << endl;
        return "";
    }

    outfile << userPosition.toString() <<endl;
    outfile.close();

    return "New User added Successfully";

}


//Function to add a new item
string registerItem(){
    //variables for the add a new user
    int itemid, itemqtt;
    string itemname, itemdesc, itemcategory, catdesc,catbr;

    itemid = validateIntegers("Enter the id of the item: ");
    itemname = validateStrings("Enter the name of the item:");
    itemdesc = validateStrings("Description of the item:");
    itemqtt = validateIntegers("Quantity of the item:");
    itemcategory = validateStrings("Category(Office supply, students, fairs, employee, classes): ");

    //Create the new user
    Additem newItem(itemid, itemname, itemdesc, itemqtt, itemcategory);

    //Add infor for teh category inherit class
    catdesc = validateStrings("Describe the category:");
    catbr = validateStrings("What is the brand:");

    //Create the inherit position of the user
    Category itemcat(itemid, itemname, itemdesc, itemqtt, itemcategory, catdesc, catbr);

    ofstream outfile ("D:/Ivy Tech/Fall Semester 2024/CSCI - 201/C++ code/Final Project/inventory.txt", ios::app);
    if (!outfile) {
        cout << "Error opening file for writing!" << endl;
        return "";
    }

    outfile << itemcat.toString() <<endl;
    outfile.close();

    return "Item added Successfully";
}


//Function to check out the items

string checkoutItem(){

    //opening the file
    ifstream inputFile("D:/Ivy Tech/Fall Semester 2024/CSCI - 201/C++ code/Final Project/inventory.txt");

    if(!inputFile){
        return "Error opening the file";
    }

    //creating vector that will keep the lines
    vector<string> lines;
    string line;

    //read the file
    while(getline(inputFile, line)){
        lines.push_back(line);
    }

    //close file
    inputFile.close();

    //Print the file
    cout<<"Inventory of items"<<endl;
    for(size_t k=0; k<lines.size(); k++){
        cout<<"     ID  "<<endl;
        cout<< k+1 << " : "<< lines[k]<<endl;
    }


    //Looking for the item 
    int linechose = validateIntegers("Enter the number of the line of the item that you want: ");

    // Validar que la línea ingresada esté dentro del rango
    if (linechose < 1 || linechose > static_cast<int>(lines.size())) {
        return "Invalid line number. Please try again.";
    }

    // Obtener la línea seleccionada
    string &selectedLine = lines[linechose - 1];        

    //Look for the quantity
    size_t firstDash = selectedLine.find(" - ");
    size_t secondDash = selectedLine.find(" - ", firstDash + 1);
    size_t thirdDash = selectedLine.find(" - ", secondDash + 1);


    if (thirdDash != string::npos) {
        size_t start = thirdDash + 3; // Position of the quantity
        size_t end = selectedLine.find(" - ", start);
        
        string cqtt = selectedLine.substr(start, end - start);
        
        int currentQuantity = stoi(cqtt);
        cout<<"The quantity is: "<< currentQuantity<<endl;

        int outquantity = validateIntegers("Enter how many are you taking: ");
        if(outquantity>currentQuantity){
            
            return "You cannot take more than " + currentQuantity;
        }
        
        //Substraction of the items
        int newQuantity = currentQuantity - outquantity;

        //Reemplace the new quantity in the vector
        selectedLine.replace(start, end - start, to_string(newQuantity));
        cout << "Quantity Updated: " << selectedLine << endl;

        //Save the update in the file
        ofstream outputFile("D:/Ivy Tech/Fall Semester 2024/CSCI - 201/C++ code/Final Project/inventory.txt");
        if(!outputFile){
            return "Error saving the update";
        }

        for(const auto &updatedLine : lines){
            outputFile << updatedLine << endl;
        }
        outputFile.close();
        return "Quantity successfully updated";
    }
}


//Function for the new orders
string newOrderFunction(){
    //variables for the add a new order
    int employeeid;
    string order;

    employeeid = validateIntegers("Enter your employee id: ");
    order = validateStrings("Enter the items that you would like to order (comma separated): ");

    //Create the new user
    Order newOrder(employeeid, order);

    ofstream outfile ("D:/Ivy Tech/Fall Semester 2024/CSCI - 201/C++ code/Final Project/orders.txt", ios::app);
    if (!outfile) {
        cout << "Error opening file for writing!" << endl;
        return "";
    }

    outfile << newOrder.toString() <<endl;
    outfile.close();

    return "New Order added Successfully";
}

int main(){
    //Declaration of variables
    int option; //menu options

    //Vetor to hold information about the 
    vector<vector<string>> userList;

    //Variables for the add new user
    string newUser;

    //variable for adding a item
    string newItem;

    //variable for checking out a item
    string checkoutitem;

    //String for the new orders
    string neworders;

    while(true){
        cout<< "Management System"<<endl;
        cout<< "\nWhat would you like to do today: "<<endl;
        cout<< "1. Add a new user"<<endl;
        cout<< "2. Register New Items"<<endl;
        cout<< "3. Check out Items"<<endl;
        cout<< "4. PLace an order"<<endl;
        cout<< "5. Exit"<<endl;
        cout<<">>> "; cin>> option;

        //Meny of options
        switch (option)
        {
        
        //add a new user
        case 1:
            newUser = addnewuser();
            cout<<newUser<<endl;
            
            break;
        
        case 2:
            newItem = registerItem();
            cout<< newItem<<endl;
            break;
        
        case 3:

            checkoutitem = checkoutItem();
            cout<< checkoutitem<<endl;
            break;
        
        case 4:
            neworders = newOrderFunction();
            cout<< neworders<<endl;
            break;
        case 5:
            cout<<"Closing..."<<endl;
            return 1;
            break;

        default:
            cout<<"WRONG: You must enter a valid option"<<endl;
            break;
        }
    }
    

    return 0;
}
