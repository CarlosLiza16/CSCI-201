/* Program name: M01 Programming Assignment Part 2
* Author: Carlos Lizarazu 
* Date last updated: 10/26/2024
* Purpose: The program will create a clas for a stereo receiver 
*/

#include <iostream>
#include <string>
#include <limits> 

using namespace std;

//Create the class for the Stereo
class StereoReceiver
{
    private:
        string manufacturer;
        string model;
        int serialNumber;
        int wattage;
        int numberChannels;
        string band; //(AM/FM)
        double frequency;
        int volume; //(0-10)
        bool power; //(on-true -- off-false)
        bool aux; //(on-true -- off-false
        bool cd; //(on-true -- off-false

    public:
        //Creating the struct, automacally created when an object is created
        StereoReceiver (string ma, string mo, int sN, int wa, int nC){
            //attributes the user will set
            manufacturer = ma;
            model = mo;
            serialNumber = sN;
            wattage = wa;
            numberChannels = nC;

            //attributes already set

            band = "AM";
            frequency = 88.7;
            volume = 5;
            power= false;
            aux = false;
            cd = false;

        }


        //Creating accessor methods
        string getManufacturer(){
            return manufacturer;
        }
        
        string getModel(){
            return model;
        }
        
        int getSerialNumber(){
            return serialNumber;
        }

        int getWattage(){
            return wattage;
        }
        
        int getNumberChannels(){
            return numberChannels;
        }

        string getBand(){
            return band;
        }

        double getFrequency(){
            return frequency;
        }

        int getVolume(){
            return volume;
        }

        bool getPower(){
            return power;
        }

        bool getAux(){
            return aux;
        }

        bool getCd(){
            return cd;
        }

        
        //creating the mutator methods
        void setPower(bool p){
            power = p;
        }
        
        void setVolume(int v){
            if (v>=0 && v<=10){
                volume = v;
            }else{
                cout<<"Volumen is between 0-10"<<endl;
            }
            
        }
        
        void setBand(string b){
            band= b;
        }
        
        void setFrequency(double f){
            frequency = f;
        }

        void setAux(bool a){
            aux = a;
        }

        void setCd(bool Cd){
            cd = Cd;
        }
        
};

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

//validation for the frequency numbers
int validateFrequency(const string& prompt) 
{
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "You must enter a valid frequency. Try again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

//validation for the strings
string validateStrings(const string& prompt)
{
    string col;

    while (true){
        cout<<prompt;
        
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
            cout << "You must enter a word, do not use numbers."<< endl;
        }
   }

   return col;
}

//function to display the cube
void displayStereo(StereoReceiver& stereo)//pass by reference
{
    if (stereo.getPower() == false){
        cout<<"Power: OFF "<<endl;
    }else{
        cout<<"Power: ON "<<endl;
    }
    cout<<"Stereo Receiver information"<<endl;
    cout<<"___________________________"<<endl;
    cout<<"Manufacturer: "<< stereo.getManufacturer()<<endl;
    cout<<"Model: "<< stereo.getModel()<<endl;
    cout<<"Serial Number: "<< stereo.getSerialNumber()<<endl;
    cout<<"Wattage: "<< stereo.getWattage()<<endl;
    cout<<"Number of Channels: "<< stereo.getNumberChannels()<<endl;
    cout<<"Band (AM/FM): "<< stereo.getBand()<<endl;
    cout<<"Frequency: "<< stereo.getFrequency()<<endl;
    cout<<"Volumen (0-10): "<< stereo.getVolume()<<endl;
    if(stereo.getAux() == false){
        cout<<"Aux: OFF "<<endl;
    }else{
        cout<<"Aux: CONECTED "<<endl;
    }
    if(stereo.getCd() == false){
        cout<<"CD: OFF "<<endl;
    }else{
        cout<<"CD: CONECTED "<<endl;
    }
    
}
int main()
{
   //varibales for the option to change to aux or cd
   char option;
   int change;

   //Prompt the lenght and validate the data
   
   string Manufacturer = validateStrings("Enter the manufacturer of the Stereo: ");
   string Model = validateStrings("Enter the model of the Stereo: ");
   int SerialNumber = validateIntegers("Enter the serial number of the Stereo: ");
   int Wattage = validateIntegers("Enter the wattage of the Stereo: ");
   int NumberChannels = validateIntegers("Enter the number of the channels: ");
   

   //Create the object
   StereoReceiver myStereo(Manufacturer, Model, SerialNumber, Wattage, NumberChannels);
   

   //Display the objects
   displayStereo(myStereo);

   //Turn on the stereo
   myStereo.setPower(true);
   
   //Let the user modify the information

   //change to aux or cd
   cout<<("Would you like to change to AUX or CD? [Y]es or [N]o: ");
   cin>>option;
   if(char option="y" || "Y"){
        cout<<"1. Switch to AUX"<<endl;
        cout<<"2. Switch to CD"<<endl;
        cin>>change;
        switch(change){
            case 1:
                //Turn on the AUX
                myStereo.setAux(true);

                //Display the objects
                displayStereo(myStereo);

                //Turn off the stereo
                myStereo.setPower(false);
                break;
            case 2:
                //Turn on the CD
                myStereo.setCd(true);

                //Display the objects
                displayStereo(myStereo);

                //Turn off the stereo
                myStereo.setPower(false);
                break;
        }
   }else{
        string changeBand = validateStrings("What Band would you like? (AM - FM): ");
        double changeFrequency = validateFrequency("What frequency would you like to listen (Ex. 88.7)");
        int changeVolume = validateIntegers("Change the volumen: ");

        //setting the new values

        myStereo.setBand(changeBand);
        myStereo.setFrequency(changeFrequency);
        myStereo.setVolume(changeVolume);
   
        //Display the objects
        displayStereo(myStereo);
   }


   return 0;
}