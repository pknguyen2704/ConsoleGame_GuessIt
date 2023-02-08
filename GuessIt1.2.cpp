#include <iostream>

using namespace std;

void playGuessIt();
int selectNumber(int lower, int high);
bool replayGuessIt();
char getPlayerAnswer();
void getPlayerRange();

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

int selectNumber(int low, int high)
{
    return (low+high)/2;
}

char getPlayerAnswer()
{
    char answer;
    cout << "This number is higher, lower or equal to your number?" << endl;
    cout << "Select '>' if your number higher than this number" << endl;
    cout << "Select '<' if your number lower than this number" << endl;
    cout << "Select '=' if your number equal to this number" << endl;
    cout << "[>/</=]? :";
    cin >> answer;
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
    int x,low, high;
    getPlayerRange(low, high);
    cout << low << " " << high << endl;
    char answer;
    do{
        x = selectNumber(low, high);
        cout << x << endl;
        answer = getPlayerAnswer();
        if(answer == '=') 
            cout << "Your number is " << x << endl;
        if(answer == '>') low = x+1;
        if(answer == '<') high = x-1;
        
    }while(answer != '=');
}
bool replayGuessIt()
{
    char replay;
    cout << "Do you want to play again?" << endl << "Select Y to play again" << endl << "Select N to stop" << endl << "[Y/N]?:";
    cin >> replay;
    if(replay == 'Y' || replay == 'y')
        return true;
    else
        cout << "Thanks, see you again!" << endl;
    return false;
}