/* Program name: M01 Programming Assignment Part 1
* Author: Carlos Lizarazu 
* Date last updated: 10/24/2024
* Purpose: create a cube object and display its volume. The class will have methods for the user to access the object,
  mutate the object, and find the volumen
*/

#include <iostream>
#include <string>
#include <limits> 

using namespace std;

//Create the class for the cube
class Cube
{
    private:
        int length;
        int width;
        int height;
        string color;
    public:
        //Creating the struct, automacally created when an object is created
        Cube(int l, int w, int h, string c){
            length = l;
            width= w;
            height= h;
            color= c;
        }
        
        //Creating accessor methods
        int getLength(){
            return length;
        }
        
        int getWidth(){
            return width;
        }
        
        int getHeight(){
            return height;
        }
        
        string getColor(){
            return color;
        }
        
        //creating the mutator methods
        void setLength(int l){
            length = l;
        }
        
        void setWidth(int w){
            width = w;
        }
        
        void setHeight(int h){
            height= h;
        }
        
        void setColor(string c){
            color = c;
        }
        
        //Creating method for calculate the volumen
        int calculateVolumen(int l, int w, int h){
            int volume=l*w*h;
            return volume;
        }
};

//validation for the numbers
int validateInput() 
{
    int value;
    while (true) {
        cout << "Enter the length of the cube: ";
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

//validation for the color
string validateColor()
{
    string col;

    while (true){
        cout<<"Enter the color of the cube: ";
        cin.ignore(); //cleans the buffer, space created
        
        getline(cin, col); // Read the whole line

        // Check if the input contains only letters and spaces
        bool isValid = true;
        for (char c : col) {
            if (!isalpha(c) && !isspace(c)) {
                isValid = false;
                break;
            }
        }

        // If the input is valid, break the loop; otherwise, prompt again
        if (isValid && !col.empty()) {
            break;
        } else {
            cout << "You must enter a valid color and not a number."<< endl;
        }
   }

   return col;
}

//function to display the cube
void displayCube(Cube& cube)//pass by reference
{
    cout<<"Cube information: "<<endl;
    cout<<"Length: "<< cube.getLength()<<endl;
    cout<<"Width: "<< cube.getWidth()<<endl;
    cout<<"Height: "<< cube.getHeight()<<endl;
    cout<<"Color: "<< cube.getColor()<<endl;
    cout<<"Volumen: "<< cube.calculateVolumen(cube.getLength(),cube.getWidth(),cube.getHeight())<<endl;
}
int main()
{

   string color;
   
   //Prompt the lenght and validate the data
   
   int length = validateInput();
   int width = validateInput();
   int height = validateInput();
   
   //Prompt the color and validate the data
   color = validateColor();
   

   //Create the object
   Cube myCube(length,width,height,color);

   //Display the objects
   displayCube(myCube);
   
   //Let the user modify the information
   
   int newlength = validateInput();
   int newwidth = validateInput();
   int newheight = validateInput();
   string newColor = validateColor();

   //setting the new values

   myCube.setLength(newlength);
   myCube.setWidth(newwidth);
   myCube.setHeight(newheight);
   myCube.setColor(newColor);
   
   //Display the objects
   displayCube(myCube);



   return 0;
}