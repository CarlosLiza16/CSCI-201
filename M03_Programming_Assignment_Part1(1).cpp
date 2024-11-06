/* Program name: M03 Programming Assignment Part 1
 * Author: Carlos Lizarazu
 * Date last updated: 11/05/2024
 * Purpose: The program will store the grade of quizes from a student during
 * the whole semester. At the end the program will display all the grades from
 * the modules, the average grade, the highest and lowest grade.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Create the class for the grade
class Grade {
private:
  int quizTest;

public:
  // Creating the struct, automatically created when an object is created
  Grade(int score) {
    if (score < 0 || score > 15) {
      throw invalid_argument(
          "Score is INVALID! Grade must be between 0 and 15.");
    }
    quizTest = score;
  }

  // Creating accessor methods
  int getQuizTest() { return quizTest; }

}; // This brace closes the grade class

// Function to get the data from the different 16 modules
template <typename T> void getData(T &grades) {
  int score;

  for (int i = 1; i <= 16; i++) {
    cout << "Enter the grade of the quiz for module " << i << " : ";
    while (true) {
        cin>>score;

        if (cin.fail()) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore bad input
            cout << "Invalid input. Please enter a valid number: ";
            continue;  // Retry input
        }
      try {
        grades.push_back(Grade(score));
        break;
      } catch (const invalid_argument &e) {
        cout << e.what() << "try again: ";
      }
    }
  }
}

// Function for the get average
int average(vector<Grade> &grades) {
  int total = 0;
  for (int j = 0; j <= grades.size(); j++) {
    total += grades[j].getQuizTest();
  }
  return total / grades.size();
}

// Function to find the maximum value
int maximumValue(vector<Grade> &grades) {
  int maxValue = 0;
  for (int i = 1; i < grades.size(); i++) {
    if (grades[i].getQuizTest() > grades[maxValue].getQuizTest()) {
      maxValue = i;
    }
  }
  return maxValue;
}

////Function to find the minimum value
int minimumValue(vector<Grade> &grades) {
  int minValue = 0;
  for (int i = 1; i < grades.size(); i++) {
    if (grades[i].getQuizTest() < grades[minValue].getQuizTest()) {
      minValue = i;
    }
  }
  return minValue;
}

// Display the vector
void display(vector<Grade> &grades) {
  cout << "\nFall 2024 Quiz Grades" << endl;
  cout << "\n";
  for (int i = 0; i < grades.size(); i++) {
    cout << "Module " << i + 1 << ": " << grades[i].getQuizTest() << endl;
  }
}

// Main Function
int main() {
  vector<Grade> grades;

  // Getting the grade from the user
  getData(grades);

  // Display the list of grades
  display(grades);

  // call the funcitonto getthe average of the quizzes
  cout << "\nAverage Grade: " << average(grades) << endl;

  // calling the funciton for the minimun value
  int min = minimumValue(grades);
  cout << "\nYour lowest score was in Module: " << min + 1 << " with "
       << grades[min].getQuizTest() << endl;

  // calling the funciton for the maximun value
  int max = maximumValue(grades);
  cout << "\nYour highest score was in Module: " << max + 1 << " with "
       << grades[max].getQuizTest() << endl;

  return 0;
}
