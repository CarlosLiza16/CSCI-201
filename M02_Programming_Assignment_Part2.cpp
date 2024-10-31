/* Program name: M01 Programming Assignment Part 2
* Author: Carlos Lizarazu 
* Date last updated: 10/31/2024
* Purpose: Use the previous code created in module 1 (stereo receiver) 
           and implement the try/catch arguments to validate the inputs of the user. 
*/

#include <iostream>
#include <string>
#include <limits> 

using namespace std;

//validation for the strings
bool validateStrings(const string& col)
{
    while (true){
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
        }else{
            isValid = false;
            return isValid;
        }
   }
}

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

            //validate the manufacturer
            if(!validateStrings(ma)){
                throw invalid_argument("ERROR: The manufacturer is invalid. You must enter just letters");
            }
            
            //Validate the model
            if(!validateStrings(mo)){
                throw invalid_argument("ERROR: Model provided in not valid. Try just Letters");
            }

            //Validate the serial number
            if(sN<=0){
                throw invalid_argument("ERROR: The serial number must just numbers");
            }

            //Validate the wattage
            if(wa<=0 || wa>1000){
                throw invalid_argument("ERROR: The Wattage cannot go over 1000");
            }

            //Validate the number of channels
            if(nC<=0 || nC>20){
                throw invalid_argument("ERROR: The Wattage cannot go over 20");
            }

            //Assign the values
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
            if (v<0 || v>10){
                throw invalid_argument("Error: Volumen must be between 0-10");
                
            }
            volume = v;
            
        }
        
        void setBand(string b){
            //validate the manufacturer
            if(!validateStrings(b)){
                throw invalid_argument("ERROR: The band is invalid. You must enter AM or FM");
            }else if(b == "AM" || b == "FM"){
                band= b;
            }else{
                throw invalid_argument("ERROR: The band is invalid. You must enter AM or FM");
            }
            
        }
        
        void setFrequency(double f){
            if(f<87 || f>105){
                throw invalid_argument("ERROR: The frequence is invalid. Range frequence(87.0 - 105.0)");
            }
            frequency = f;
        }

        void setAux(bool a){
            aux = a;
        }

        void setCd(bool Cd){
            cd = Cd;
        }
        
};




//function to display the cube
void displayStereo(StereoReceiver& stereo)//pass by reference
{
    cout<<"                          "<<endl;
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
    //variables for the user to enter
    string Manufacturer, Model;
    int Wattage, NumberChannels, SerialNumber;
    StereoReceiver myStereo("a","a",1,1,1);

    //variable for the mutator values
    string changeBand;
    double changeFrequency;
    int changeVolume;

    //varibales for the option to change to aux or cd
    string option;
    int change;

    try{
        //Prompt the user to enter values for stero
    
        cout<<"Enter the manufacturer of the Stereo: ";
        cin>>Manufacturer;
        cout<<"Enter the model of the Stereo: ";
        cin>>Model;
        cout<<"Enter the serial number of the Stereo: ";
        cin>>SerialNumber;
        if(cin.fail()){
            throw invalid_argument("Serial number must be a number");
        }

        cout<<"Enter the wattage of the Stereo: ";
        cin>>Wattage;
        if(cin.fail()){
            throw invalid_argument("Wattage must be a number");
        }

        cout<<"Enter the number of the channels: ";
        cin>>NumberChannels;
        if(cin.fail()){
            throw invalid_argument("Number of Channels must be a number");
        }

        //Create the object
        myStereo = StereoReceiver(Manufacturer, Model, SerialNumber, Wattage, NumberChannels);
        

        //Display the objects
        displayStereo(myStereo);
    }
    catch(const invalid_argument& message){
        cout<<"\n************************"<<endl;
        cout<<"ERROR: "<<message.what()<<endl;
    }
    

   //Turn on the stereo
   myStereo.setPower(true);
   
   //Let the user modify the information

   //change to aux or cd
   cout<<("Would you like to change to AUX or CD? 'yes' or 'no' : ");
   cin>>option;

   if(option == "yes"){
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
    
        try{
            //Prompt the use for the new values changed by the user
            cout<<"What Band would you like? (AM - FM): ";
            cin>>changeBand;
            cout<<"What frequency would you like to listen (Ex. 88.7)";
            cin>>changeFrequency;
            if(cin.fail()){
                throw invalid_argument("You must enter a valid frequency ex(88.0 or 104.6)");
            }
            cout<<"Change the volumen: ";
            cin>>changeVolume;
            if(cin.fail()){
                throw invalid_argument("You must entered a number");
            }

            //setting the new values

            myStereo.setBand(changeBand);
            myStereo.setFrequency(changeFrequency);
            myStereo.setVolume(changeVolume);
    
            //Display the objects
            displayStereo(myStereo);
        }
        catch(const invalid_argument& message){
            cout<<"\n************************"<<endl;
            cout<<"ERROR: "<<message.what()<<endl;
        } 
   }

   return 0;
}