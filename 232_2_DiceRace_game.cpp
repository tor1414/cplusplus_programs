/*
Name: Victoria Hagan
Date: 2/11/2015
Assignment:  Asn3
Platform/IDE: Windows/VS2013

Description:
This program is race between Jack and Jill. There are 20 spaces
and the first to the top (20+) wins. However, if they are on any square
at the time, the first one there will tumble back. 
This was completed using a class called DiceRace that takes one string input,
of a player, keeps track of position, anmount of wins and compares to another player. 
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>  

using std::string;
using std::cout;
using std::cin;
using namespace std;

class DiceRace {
private:
	int position;
	bool tumble;
	string player;
	int won;

public:

	DiceRace();
	DiceRace(string name);
	int getPosition()const;
	int setPosition(int roll);
	string getPlayer()const;
	bool tumbles();
	string printPosition(int roll, DiceRace player2);
	int playerWin();
	int getWins()const;
	bool setTumble(bool value);
	bool getTumble()const;
	bool operator==(DiceRace& player2) const;
	int restart();
};

	DiceRace::DiceRace(){
		//intialize the class and set default values
		won = 0;
		position = 0;
		tumble = false;
		player = "";
	};

	DiceRace::DiceRace(string name){
		// intialize the class and set default values and pass new identifier
		won = 0;
		position = 0;
		tumble = false;
		player = name ;
	};
	
	int DiceRace::getPosition()const{
		//returns placement for comparison and printing
		return position;
	};

	int DiceRace::playerWin() {
		//keeps track of the number of wins during a run through the code
		won = won + 1;
		return won;
	};

	int DiceRace::getWins()const{
		//returns the number of wins for comparison and printing
		return won;
	};
	
	int DiceRace::setPosition(int roll){
		//checks to see if the player is moving forward or tumbling backward
		if (tumble == false){
			//player moves foward
			position = position + roll;
			return position;
		} 
		else if (tumble == true){
			//player tumbles back
			position = position - roll;
			return position;
		};
	};

	string DiceRace::getPlayer()const {
		return player;
	};

	bool DiceRace::setTumble(bool value){
		//sets the tumble to a new value
		return tumble = value;
	};

	bool DiceRace::getTumble()const{
		//returns the tumble for comparison
		return tumble;
	};

	bool DiceRace::operator==(DiceRace& player2)const{
		//changes the opporator == to compare 2 player positions
		return position == player2.getPosition();
	};

	string DiceRace::printPosition(int roll, DiceRace player2){
		// checks to see if a player has tumbled and prints the result
		if (player2.getTumble() == true){
			//player2 tumbles 
			cout << roll << "\t" << position << "\t" << player2.getPosition() << "\t" << player2.getPlayer() << " tumbles!" << endl;
			return "";
		}
		else if (player2.getTumble() == false){
			//player2 did not tumble
			if (tumble == true){
				//player1 tumbled
				cout << roll << "\t" << position << "\t" << player2.getPosition() << "\t" << player << " tumbles!" << endl;
				return "";
			}
			else if (tumble == false){
				//no one tumbled
				cout << roll << "\t" << position << "\t" << player2.getPosition() << endl;
				return "";
			};
		};
	};

	int DiceRace::restart(){
		//sets player back to start
		position = 0;
		return position;
	};

	int main(){
		//intialize variables and game
		srand(time(NULL));
		bool finished = false;
		string winner;
		int roll;
		int chance;
		DiceRace jack("Jack");
		DiceRace jill("Jill");
		
		// find the number of times to run Dice Race
		int numGames;
		do {
			cout << "please enter an odd interger value: ";
			cin >> numGames;
		} while (numGames % 2 != 1); //will not accept an even interger
		
		cout << "DiceRace will run for " << numGames << " games." << endl;
		//run the game for user determined amount
		for (int i = 0; i < numGames; i++){
			cout << "Roll \t Jack \t Jill " << endl;
			cout << "---------------------------------" << endl;
			do{
				//Jack's Turn
				roll = rand() % 6 + 1; // roll for Jack
				jack.setTumble(false); // set position to add
				jack.setPosition(roll);
				if (jack == jill){
					//compare position for tumble
					chance = rand() % 3 + 1;
					jill.setTumble(true);
					jill.setPosition(chance);
					jack.printPosition(roll, jill);
				}
				else {
					jack.printPosition(roll, jill);
				};
				//check to see if Jack won
				if (jack.getPosition() >= 20){
					finished = true;
					winner = jack.getPlayer();
					jack.playerWin();
				};

				if (!finished){
					//jill's turn
					jill.setTumble(false);
					roll = rand() % 6 + 1;
					jill.setPosition(roll);
					if (jill == jack){
						chance = rand() % 3 + 1;
						jack.setTumble(true);
						jack.setPosition(chance);
						jack.printPosition(roll, jill); //must always have jack as player1 for consitent printing
					}
					else{
						jack.printPosition(roll, jill);
					};
					//check to see if jill won
					if (jill.getPosition() >= 20){
						finished = true;
						winner = jill.getPlayer();
						jill.playerWin();
					};
				}


			} while (!finished);
			//print winner
			cout << winner << " wins!" << endl;
			cout << endl;
			//begin again
			finished = false;
			jill.restart();
			jack.restart();
		}
		//declare totals
		cout << jack.getPlayer() << " won " << jack.getWins() << " games and " << jill.getPlayer() << " won " << jill.getWins() << " games." << endl;
		cout << endl;
		//declare winner
		if (jack.getWins() > jill.getWins()){
			cout << jack.getPlayer() << " is the Dice Race Grand Champion!" << endl;
		}
		else {
			cout << jill.getPlayer() << " is the Dice Race Grand Champion!" << endl;
		};
		//pause for visual effect
		system("pause");
	};
