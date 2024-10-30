/* Program name: M02 Programming Assignment Part 1
* Author: Carlos Lizarazu
* Date last updated: 10/29/2024
* Purpose: This program will create a class for a Date (mm,dd,yyyy). The class then will validate the inputs using try/catch handaling errors.
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

//Create the class for the cube
class Date
{
  private:
    int month;
    int day;
    int year;

  public:
  //Creating the struct, automacally created when an object is created
    Date(int mm, int dd, int yyyy){
      //validate the month
      if(mm<1 || mm>12){
        throw invalid_argument("Month must be between 1 and 12!!!");
      }
      //validate the day
      int monthDays;
      switch (mm){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          monthDays = 31;
          break;
        case 4: case 6: case 9: case 11:
          monthDays = 30;
          break;
        case 2:
          monthDays = 28;
          break;
        default:
          invalid_argument("The month you entered is invalid. Months must be between 1 - 12");
      }
      if(dd<1 || dd>monthDays){
        throw invalid_argument("The day is not valid for the entered month!");
      }
      //validate for the year
      if(yyyy<1900 || yyyy>2020){
        throw invalid_argument("Year must be between 1900 and 2020!!!");
      }

      //assigniing the values to the varaibles after checking
      month = mm;
      day = dd;
      year = yyyy;
    }

    //Creating accessor methods
    int getMonth(){
      return month;
    }
    int getDay(){
      return day;
    }
    int getYear(){
      return year;
    }

    //creating the mutator methods

    //validate the month
    void setMonth(int newMm){
      if(newMm<1 || newMm>12){
        throw invalid_argument("Month must be between 1 and 12!!!");
      }
      month = newMm;
    }

    //validate the day
    void setDay(int newDd){
      
      int monthDays;
      switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          monthDays = 31;
          break;
        case 4: case 6: case 9: case 11:
          monthDays = 30;
          break;
        case 2:
          monthDays = 28;
          break;
        default:
          invalid_argument("The month you entered is invalid. Months must be between 1 - 12");
      }
      if(newDd<1 || newDd>monthDays){
        throw invalid_argument("The day is not valid for the entered month!");
      }

      day = newDd;
    }

    //validate for the year
    void setYear(int newYyyy){
      if(newYyyy<1900 || newYyyy>2020){
        throw invalid_argument("Year must be between 1900 and 2020!!!");
      }
      year= newYyyy;
    }

    //create the string mutator
    string toString(){
      string months[] = {"January",
                         "Febryary",
                         "March",
                         "April",
                         "May",
                         "june",
                         "July",
                         "August",
                         "September",
                         "Octuber",
                         "November",
                         "December",
      };
      return months[month-1] + " " + to_string(day) + ", " + to_string(year);
    }

}; // This brace closes the Cube class

void displayDate(Date& date)//pass by reference
{
  cout<<"\n";
  cout<<"The date is: "<< date.toString() <<endl;
  cout<<"\n";
}

//Main Function
int main()
{
  int month, day, year; 
  Date myDate(1,1,2000);
  try{
    
    //Prompt the messages asking fot the month, day and year
    cout<<"Enter the month (mm): ";
    cin>>month;   
    if(cin.fail()){
      throw invalid_argument("You must enter a number");
    }
    cout<<"Enter the day (dd): ";
    cin>>day;
    if(cin.fail()){
      throw invalid_argument("You must enter a number");
    }
    cout<<"Enter the year (yyyy): ";
    cin>>year;
    if(cin.fail()){
      throw invalid_argument("You must enter a number");
    }

    //create the object
    myDate = Date(month, day, year);

    //display the object
    displayDate(myDate);
  } 
  catch(const invalid_argument& message){
    cout<<"\n";
    cout<<"******************************"<<endl;
    cout<<"ERROR: "<<message.what()<<endl;
  }
  
  //Let the user modify the information
  
  int newMonth, newDay, newYear; 

  //Prompt the messages asking fot the month, day and year
  cout<<"Enter the New month (mm): ";
  cin>>newMonth;   
  if(cin.fail()){
    throw invalid_argument("You must enter a number");
  }
  cout<<"Enter the day (dd): ";
  cin>>newDay;
  if(cin.fail()){
    throw invalid_argument("You must enter a number");
  }
  cout<<"Enter the year (yyyy): ";
  cin>>newYear;
  if(cin.fail()){
    throw invalid_argument("You must enter a number");
  }

  //setting the new values
  myDate.setMonth(newMonth);
  myDate.setDay(newDay);
  myDate.setYear(newYear);

  //Display the objects
  displayDate(myDate);
  
  return 0;
}