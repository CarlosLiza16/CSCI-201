/* Program name: M06 Programming Assignment Programming Assignment
 * Author: Carlos Lizarazu
 * Date last updated: 12/02/2024
 * Purpose: Create a program for an NFL football team Program. The base class will have a name and player id.
 *          Subclasses will extend the information of the players. The base class will be an abstract class. So,
 *          It cannot create objects, and the subclasses will inherit the base class.
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;

//Create the base class
class Player{
    private:
    int playerID;
    string playerName;

    public:
    //constructor
    Player(int pl, string nm) : playerID(pl), playerName(nm){}

    //Accesor methods
    int getPlayerID() const { return playerID; }
    string getPlayerName() const { return playerName; }

    //abstract methods (have to be virtual)
    virtual string getPlayerPosition() const = 0;
    virtual void play() const = 0;
    virtual string toString() const = 0; 

    //destructor
    virtual ~Player() {}
};

//creating the subclasses 

//Offense class
class Offense : public Player{
    public:
        using Player::Player; //this line will allow us to access to the player constructor
};

class QuarterBack : public Offense{
    public:
        QuarterBack(int id, string name) : Offense(id, name){}

        string getPlayerPosition() const override { return "QuarterBack"; }
        void play() const override { cout<< getPlayerName() << "  throws the ball"<<endl; }
        string toString() const override {
            return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
        }
};

class WideReceiver : public Offense{
    public:
        WideReceiver(int id, string name) : Offense(id, name){}

        string getPlayerPosition() const override { return "Wide Receiver"; }
        void play() const override { cout<< getPlayerName() << "  catches the ball"<<endl; }
        string toString() const override {
            return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
        }
};


class TightEnd : public Offense{
    public:
        TightEnd(int id, string name) : Offense(id, name){}

        string getPlayerPosition() const override { return "Tight End"; }
        void play() const override { cout<< getPlayerName() << "  Blocks and Receives"<<endl; }
        string toString() const override {
            return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
        }
};


class RunningBack : public Offense{
    public:
        RunningBack(int id, string name) : Offense(id, name){}

        string getPlayerPosition() const override { return "Running Back"; }
        void play() const override { cout<< getPlayerName() << "  catches and runs with the ball"<<endl; }
        string toString() const override {
            return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
        }
};

class OffensiveLineman : public Offense{
    public:
        OffensiveLineman(int id, string name) : Offense(id, name){}

        string getPlayerPosition() const override { return "Offensive Lineman"; }
        void play() const override { cout<< getPlayerName() << "  block opposing players"<<endl; }
        string toString() const override {
            return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
        }
};


//Creating the defense class
class Defense : public Player {
    public:
        using Player::Player;
};

class DefensiveLineman : public Defense{
    public:
    DefensiveLineman(int id, string name) : Defense(id, name) {}

    string getPlayerPosition() const override { return "Defensive Lineman"; }
    void play() const override { cout<< getPlayerName() << "  Tackles the opponet"<<endl; }
    string toString() const override {
        return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
    }
};

class Linebacker : public Defense{
    public:
    Linebacker(int id, string name) : Defense(id, name) {}

    string getPlayerPosition() const override { return "Linebacker"; }
    void play() const override { cout<< getPlayerName() << "  Defends the end zone"<<endl; }
    string toString() const override {
        return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
    }
};

class DefensiveBack: public Defense{
    public:
    DefensiveBack(int id, string name) : Defense(id, name) {}

    string getPlayerPosition() const override { return "Defensive Back"; }
    void play() const override { cout<< getPlayerName() << "  Disrupts the offense"<<endl; }
    string toString() const override { 
        return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
    }
};

//Create the Special Teams
class SpecialTeams : public Player {
    public:
        using Player::Player;
};

class Kicker: public SpecialTeams{
    public:
    Kicker(int id, string name) : SpecialTeams(id, name) {}

    string getPlayerPosition() const override { return "Kicker"; }
    void play() const override { cout<< getPlayerName() << "  Kicks the ball"<<endl; }
    string toString() const override {
        return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
    }
};

class Holder: public SpecialTeams{
    public:
    Holder(int id, string name) : SpecialTeams(id, name) {}

    string getPlayerPosition() const override { return "Holder"; }
    void play() const override { cout<< getPlayerName() << "  holds the ball"<<endl; }
    string toString() const override {
        return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
    }
};

class Punter: public SpecialTeams{
    public:
    Punter(int id, string name) : SpecialTeams(id, name) {}

    string getPlayerPosition() const override { return "Punter"; }
    void play() const override { cout<< getPlayerName() << "  Kicks the ball (Flip the field)"<<endl; }
    string toString() const override {
        return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
    }
};

class Returner: public SpecialTeams{
    public:
    Returner(int id, string name) : SpecialTeams(id, name) {}

    string getPlayerPosition() const override { return "Returner"; }
    void play() const override { cout<< getPlayerName() << "  Returns the kickoff"<<endl; }
    string toString() const override {
        return "ID: " + to_string(getPlayerID()) + " - Name: "+ getPlayerName() + " - Position: " + getPlayerPosition();
    }
};

//Main code
int main(){

    vector<Player*> team; //vector of the class Player 
    int option, id; //id of the player, and type of player
    string name; //user will enter the name of the player
    string answer="Y";

    cout<<" Football TEAM            \n"<< endl;
    
    while(answer == "Y"){
        //Menu
        cout<<"Offense:\n"
            <<"  1. QuaterBack\n"
            <<"  2. Wide Receiver\n"
            <<"  3. Tight End\n"
            <<"  4. Running Back\n"
            <<"  5. Offensive Lineman\n"
            <<"Defense:\n"
            <<"  6. Defensive Lineman\n"
            <<"  7. LineBacker\n"
            <<"  8. Defensive Back\n"
            <<"Special Teams:\n"
            <<"  9. Kicker\n"
            <<"  10. Holder\n"
            <<"  11. Punter\n"
            <<"  12. Returner\n"<<endl;
        cout<<"Enter what kind of player do you want to add? ==> "; cin>> option;
    
        switch (option)
        {
            case 1: 
                cout<<"Enter the Player ID: ";cin>> id;
                //cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new QuarterBack(id, name));
                break;
            
            case 2: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new WideReceiver(id, name));
                break;

            case 3: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new TightEnd(id, name));
                break;

            case 4: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new RunningBack(id, name));
                break;
            
            case 5: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new OffensiveLineman(id, name));
                break;
            
            case 6: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new DefensiveLineman(id, name));
                break;
            
            case 7: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new Linebacker(id, name));
                break;

            case 8: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new DefensiveBack(id, name));
                break;

            case 9: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new Kicker(id, name));
                break;

            case 10: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new Holder(id, name));
                break;

            case 11: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new Punter(id, name));
                break;

            case 12: 
                cout<<"Enter the Player ID: ";cin>> id;
                cin.ignore(); //clean the buffer, extra space 
                cout<<"Enter the PLayer Name: ";
                getline(cin,name);
                team.push_back(new Returner(id, name));
                break;
            
            default:
                cout<<"Wrong option entered. Try again"<<endl;
                break;
        }

        cout<<"\nDo you want to keep adding more players? enter [Y] for yes or [N] for no: ";cin>>answer;
    }

    //display the list of players
    cout<<"\nThe list of players is: "<<endl;
    for(auto& player : team){
        cout<< player->toString() <<endl;
        player->play();
    }
    cout<<"The total players is: "<< team.size()<<endl;
    return 0;
}