#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
    return rand()%13 + 1;
}

int calScore(int x,int y,int z){
    if (x>10) x=10;
    if (y>10) y=10;
    if (z>10) z=10;
    
    int total=x+y+z;
    if (total>=10) return total%10;
    else return total;
}

int findYugiAction(int s){	
	if(s == 9) return 2;
	else if(s < 6) return 1;
	else{
	    int chance=rand()%100;
	    if (chance>=69) return 2;
	    else return 1;
	}
}

void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if (p==y) cout <<   "|             Draw!!!           |"; 
	else if (p>y)cout <<   "|         Player wins!!!        |";
	else cout <<   "|          Yugi wins!!!         |";
	cout << "\n---------------------------------\n";
}

int main(){	
	int playerScore, yugiScore, playerAction, yugiAction;
	srand(time(0));
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(),drawCard(),0};
	
	

	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(!(playerAction==1 || playerAction==2)); 
	if(playerAction == 1){

		cout << "Player draws the 3rd card!!!" << "\n";
		playerCards[2] = drawCard();
		
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		
		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Your new score: " << playerScore << "\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);


	if(yugiAction == 1){

		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2]=drawCard();

		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
		
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's new score: " << yugiScore << "\n";

	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}