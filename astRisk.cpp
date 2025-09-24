//Aaron Leonhard
//astRisk

#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
#include<conio.h>
using namespace std;

string sky = "--------------------";
string shipinsky, enemyinsky1, enemyinsky2, enemyinsky3, enemyinsky4;
string input;
int scorenum = 1;
bool quitgame = false;

void scoreManagement(string name, int score){
	if(score < 250)
	cout << "You have crashed! YOUR SCORE IS: " << score << endl << endl;
	else
	cout << "Your score: " << score << endl << endl;
	
	int newScore = 0;
	newScore = score;
	int numDigits = 1;
	while ( newScore /= 10 ){
		numDigits++;
	}
	
	if(numDigits == 1)
		score += 1000;
	else if(numDigits == 2)
		score += 2000;
	else if(numDigits == 3)
		score += 3000;
	else if(numDigits == 4)
		score += 4000;
	else
	{
		cout << "I spent about eight hours building this game in entirety. You have spent... much more than that playing it.\n";
		cout << "Go get a date or something because you have HOURS of time to give. ;D\n";
	}

	//output after a specific character
	ofstream fileoutput("astRiskscores.txt", ios_base::app);
	fileoutput << endl << score << " " << name;
	
	fileoutput.close();
	
	ifstream fileinput("astRiskscores.txt");
	string fileNum[10000];
	int totalFiles = 0;
	while(!fileinput.eof()){
		getline(fileinput, fileNum[totalFiles]);
		totalFiles++;
	}
	
	//sort scores into correct numerical order
	for(int i = 0; i < totalFiles - 1; i++){
		string currentMin = fileNum[i];
		int currentMinIndex = i;
		
	
		for(int j = i + 1; j < totalFiles; j++){
			if(currentMin > fileNum[j])
			{
				currentMin = fileNum[j];
				currentMinIndex = j;
			}
		}
		
		if(currentMinIndex != i){
			fileNum[currentMinIndex] = fileNum[i];
			fileNum[i] = currentMin;
		}
	}
	
	//erase first digit of every score
	for(int i = 0; i < totalFiles; i++){
		fileNum[i].erase(0, 1);
	}
	
	//print
	cout << "Highscores\n";
	for(int i = 1; i < 11; i++){
	cout << setw(3) << i << ". " << fileNum[totalFiles-i] << endl;
	}
	
	fileinput.close();
	
	return;
}

void fingame(string name, int score){
	system("cls");
	cout << "You,\n";
	Sleep(3000);
	system("cls");
	cout << "You are an amazing spectacle. \n";
	Sleep(3000);
	system("cls");
	cout << "You astonish me, player, for you have achieved the impossible. \n";
	Sleep(3500);
	system("cls");
	cout << "Evil was on your doorstep, no, it was across the threshold, \n";
	Sleep(3000);
	system("cls");
	cout << "But you pressed on, nonetheless. \n";
	Sleep(3000);
	system("cls");
	cout << "And you, oh hero of the gridrealm, live to see the bright light of day. \n";
	Sleep(3500);
	system("cls");
	cout << "The world hated you, darkness lingered not a pixel away, \n";
	Sleep(3500);
	system("cls");
	cout << "But you remained.\n";
	Sleep(3000);
	system("cls");
	cout << "The Xs and 0s admit they tried to destroy you, \n";
	Sleep(3000);
	system("cls");
	cout << "But their devious efforts were in vain. \n";
	Sleep(3000);
	system("cls");
	cout << "The mindless darkness of evil pressed hard against you,\n";
	Sleep(3000);
	system("cls");
	cout << "But you, oh sane remnant, remain unphased.\n";
	Sleep(3000);
	system("cls");
	cout << "May you sleep peacefully at night knowing that this game is completed.\n";
	Sleep(4000);
	system("cls");
	cout << "That there is not one thing to do that you have not already done, \n";
	Sleep(3800);
	system("cls");
	cout << "Not one defeat admitted, \n";
	Sleep(3000);
	system("cls");
	cout << "Not one decision neglected, \n";
	Sleep(3000);
	system("cls");
	cout << "Not one besiegement overlooked. \n";
	Sleep(3000);
	system("cls");
	cout << "For you have won. \n";
	Sleep(3000);
	system("cls");
	cout << "You win.\n";
	Sleep(6000);
	system("cls");
	cout << "\n";
	Sleep(6000);
	system("cls");
	cout << "But,\n";
	Sleep(4000);
	system("cls");
	cout << "This is NOT the end.\n";
	Sleep(3000);
	system("cls");
	cout << "THIS IS NOT EVEN NEAR IT.\n";
	Sleep(3000);
	system("cls");
	cout << "For there is something you have yet to do.\n";
	Sleep(3000);
	system("cls");
	cout << "With every bit of perseverance and courage you have played my game, \n";
	Sleep(4000);
	system("cls");
	cout << "Go. Persevere. Be Courageous.\n";
	Sleep(3000);
	system("cls");
	cout << "The world will hate you, \n";
	Sleep(3000);
	system("cls");
	cout << "Death will linger inches away, \n";
	Sleep(3000);
	system("cls");
	cout << "But you shall remain.\n";
	Sleep(3000);
	system("cls");
	cout << "Waste not the little time that you have, \n";
	Sleep(3000);
	system("cls");
	cout << "For greatness can be accomplished by anyone willing to put the hoe to the dirt. \n";
	Sleep(5000);
	system("cls");
	cout << "For the truth can be spotted in the world around you, not in the black pit of a screen.\n";
	Sleep(25000);
	scoreManagement(name, score);
	
	return;
}
	
void flipline(int shipPos){
	string temp;
	
		if(scorenum == 1){
			enemyinsky1[rand() % 20] = '0';
			
			//swap rows 1 and 2
			temp = enemyinsky1;
			enemyinsky1 = enemyinsky2;
			enemyinsky2 = temp;
			
			scorenum++;
			enemyinsky1[rand() % 20] = 'X';
		}
		else if(scorenum == 2){
			//swap rows 2 and 3
			temp = enemyinsky2;
			enemyinsky2 = enemyinsky3;
			enemyinsky3 = temp;
			
			scorenum++;
			
		}
		else if(scorenum == 3){
			//swap rows 3 and 4
			temp = enemyinsky3;
			enemyinsky3 = enemyinsky4;
			enemyinsky4 = temp;
			
			scorenum++;
		}
		else if(scorenum == 4){
			
			//swap rows 4 and 0
			temp = shipinsky;
			shipinsky = enemyinsky4;
			enemyinsky4 = temp;
			
			enemyinsky4[shipPos] = '-';
			scorenum++;
		}
		else if(scorenum == 5){
			//swap rows 0 and 1
			temp = shipinsky;
			shipinsky = enemyinsky1;
			enemyinsky1 = temp;
			
			enemyinsky1[shipPos] = '-';
			scorenum -= 4;
		}
	
	return;
}

int main(void){
	
	srand(time(0));
	string name;
	string randomCharacter;
	
	system("cls");
	cout << endl << "Welcome to AsteRisk!" << endl << endl;
	cout << "How To Play: Press a or d to move the asterisk." << endl;
	cout << "Avoid hitting the X's and 0's! Get 250 points to win!" << endl << endl;
	
	cout << "Please input a username and press enter: ";
	getline(cin, name);
    
	for(int i = 0; i < 6; i++){
		int shipPos = sky.length()/2;
		int score = 0;
		int ch = 0;
		int kbd_key;
	
		shipinsky = sky;
		shipinsky[shipPos] = '*';
		enemyinsky1 = sky;
		enemyinsky2 = sky;
		enemyinsky3 = sky;
		enemyinsky4 = sky;
		
		while((shipPos > -1 && shipPos < sky.length())){
			int temp;
			
			//refresh
			system("cls");
			
			//display whole field
			cout << enemyinsky1 << endl << enemyinsky2 << endl << enemyinsky3 << endl << enemyinsky4 << endl << shipinsky << endl;
			
			while(!(kbd_key == 27)){
				ch = getch();
				
				//move the ship based on input
				if(ch == 100)
				{
					shipinsky[shipPos] = '-';
					shipPos++;
					break;
				}
				else if(ch == 97)
				{
					shipinsky[shipPos] = '-';
					shipPos--;
					break;
				}
				else
				{
					temp = rand() % 2;
					if(temp == 1)
					{
						shipinsky[shipPos] = '-';
						shipPos++;
						break;
					}
					else if(temp == 0)
					{
						shipinsky[shipPos] = '-';
						shipPos--;
						break;
					}
				}
			}
			
			//change the line positions
			flipline(shipPos);
			
			//add to the score
			score++;
			
			if(score == 150)
			{
				fingame(name, score);
				return 0;
			}
			
			//test if the new movement is going to collide if so then break
			if(shipinsky[shipPos] == 'X')
				break;
			else if(shipinsky[shipPos] == '0')
				break;
			
			//place the player at the new location
			shipinsky[shipPos] = '*';
		}
		
		scoreManagement(name, score);
		
		cout << endl << "Press ESCAPE to close the game or press ENTER to play again: ";
		while(!(kbd_key == 27)){
			ch = getch();
			if(ch == 13)
			{
				break;
			}
			else if(ch == 27)
			{
			quitgame = true;
				break;
			}
		}
		
		if(quitgame == true)
			break;
	}
	
	if(quitgame == false)
		cout << endl << "You should take a break." << endl;
	else
		system("cls");
	
    return 0;
}