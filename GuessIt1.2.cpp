#include <iostream>

using namespace std;

void playGuessIt();
void getPlayerRange(low, high);
int selectNumber(int lower, int high);
bool replayGuessIt();
char getPlayerAnswer();
int getPlayerScore(int playerTurn);
int getPlayerTurn(int turn);
void printResult(int playerTurn, int playerScore);

int main()
{
    bool replay;
    do
    {
        playGuessIt();
        replay = replayGuessIt();
    } while (replay == true);
    cout << "Thanks, have a nice day!";
    return 0;
}

int selectNumber(int low, int high)
{
    return (low+high)/2;
}

char getPlayerAnswer()
{
    char answer;
    cout << "This number is higher, lower or equal to your number?" << endl;
    do
    {
        cout << "Select '>' if your number higher than this number" << endl;
        cout << "Select '<' if your number lower than this number" << endl;
        cout << "Select '=' if your number equal to this number" << endl;
        cout << "[>/</=]? :";
        cin >> answer;
    } while (answer != '>' && answer != '<' && answer != '=');
    
    return answer;
}
void getPlayerRange(int& low, int& high)
{
    int tmpLow, tmpHigh;
    cout << "Please select your range" << endl;
    cout << "Low: ";
    cin >> tmpLow;
    cout << "High: ";
    cin >> tmpHigh;
    low = tmpLow;
    high = tmpHigh;
}
void playGuessIt()
{
    int x,low, high, playerTurn, playerScore;
    getPlayerRange(low, high);
    cout << low << " " << high << endl;
    char answer;
    int turn = 0;
    do{
        turn++;
        x = selectNumber(low, high);
        cout << x << endl;
        answer = getPlayerAnswer();
        if(answer == '=') 
            cout << "Your number is " << x << endl;
        if(answer == '<') low = x+1;
        if(answer == '>') high = x-1;
        
    }while(answer != '=');
    playerTurn = getPlayerTurn(turn);
    playerScore = getPlayerScore(playerTurn);
    printResult(playerTurn, playerScore);
}
bool replayGuessIt()
{
    char replay;
    cout << "Do you want to play again?" << endl;
    do
    {
        cout << "Select Y to play again" << endl << "Select N to stop" << endl << "[Y/N]?:";
        cin >> replay;
    } while (replay != 'Y' && replay != 'N');
    
    if(replay == 'Y')
        return true;
    return false;
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
int getPlayerScore(int playerTurn)
{
    return 100 - playerTurn;
}
