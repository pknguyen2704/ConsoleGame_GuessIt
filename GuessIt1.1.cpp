
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber();
int getPlayerGuess();
void printAnswer(int guessNumber, int randomNumer);
int getPlayerTurn(int turn);
int getPlayerScore(int playerTurn);
void printResult(int playerTurn, int playerScore);
void playGuessIt();
bool replayGuessIt();

int main()
{
    bool replay;
    do
    {
        playGuessIt();
        replay = replayGuessIt();
    } while (replay == true);
    
    return 0;
}

int generateRandomNumber()
{
    srand(time(NULL));
    return rand()%100 + 1;
}

int getPlayerGuess()
{
    int guessNumber;
    do
    {
        cout << endl << "Enter your number between 1 and 100: ";
        cin >> guessNumber;    
    } while (guessNumber  < 0);
    
    return  guessNumber;
}

void printAnswer(int guessNumber, int randomNumber)
{
    if(guessNumber > randomNumber)
        cout << "Your number is too big" << endl;
    else if(guessNumber < randomNumber)
        cout << "Your number is too small" << endl;
    else
        cout << "Congratulation! You win." << endl;
}
int getPlayerScore(int playerTurn)
{
    return 100 - playerTurn;
}
int getPlayerTurn(int turn)
{
    return turn;
}
void printResult(int playerTurn, int playerScore)
{
    cout << "Player has played " << playerTurn << " turns" << endl;
    cout << "Your Score: " << playerScore << endl << endl;
}
void playGuessIt()
{
    int randomNumber = generateRandomNumber();
    int guessNumber, guessTurn, playerScore, playerTurn;
    int turn = 0;
    do{
        guessNumber = getPlayerGuess();
        printAnswer(guessNumber, randomNumber);
        turn++;
    }while(guessNumber != randomNumber);
    playerTurn = getPlayerTurn(turn);
    playerScore = getPlayerScore(playerTurn);
    printResult(playerTurn, playerScore);
}
bool replayGuessIt()
{
    char event;
    cout << "Do you want to play again?" << endl << "Select Y to play again" << endl << "Select N to stop" << endl << "[Y/N]? : ";
    cin >> event;
    cout << endl;
    if(event == 'Y' || event == 'y')
        return true;
    else
        cout << "Goodluck and see you again! " << endl;
    return false;
}
