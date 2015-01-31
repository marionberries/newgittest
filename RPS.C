#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game
{
private:
    string rock;
    string paper;
    string scissor;
    static int wins;
    static int games;
public:
    Game(string = " ", string = " ", string = " ");
    string startGame();
    int makeDecision();
    int computerDecision();
    void showInfo(int, int);
    void compare(int, int);
    static void dispGame();
};

int Game::games = 0;
int Game::wins = 0;

Game::Game(string a, string b, string c)
{
    rock = a;
    paper = b;
    scissor = c;
}

string Game::startGame()
{
    string ans;

    cout << "Would you like to play a game of rock, paper, scissor? Type in 'yes' or 'no'" << endl;
    cin >> ans;

    return ans;
}

int Game::makeDecision()
{
    string ans;
    int ans2;

    do{
    cout << "\nType in 'rock', 'paper' or 'scissor' for the choice you want" << endl;
    cin >> ans;

    if (ans == "rock")
        ans2 = 1;
    else if (ans == "paper")
        ans2 = 2;
    else if (ans == "scissor")
        ans2 = 3;
    else
        ans2 = 4;

    if (ans2 == 4)
        cout << "\nThat is an invalid choice. Try again!" << endl;

    }while (ans2 == 4);

    return ans2;
}

int Game::computerDecision()
{
    int num;

    num = rand() % 3 + 1;

    return num;
}


void Game::showInfo(int a, int b)
{
    string user, comp;

    if (a == 1)
        user = "rock";
    else if (a == 2)
        user = "paper";
    else if (a == 3)
        user = "scissor";

    if (b == 1)
        comp = "rock";
    else if (b == 2)
        comp = "paper";
    else if (b == 3)
        comp = "scissor";

    cout << "\nYou: " << user << " computer: " << comp << endl;

}

void Game::compare(int a, int b)
{
    if (a == 1)
    {
        switch (b)
        {
            case 1: cout << "It's a draw! " << endl; break;
            case 2: cout << "You lose" << endl; break;
            case 3: cout << "You win!" << endl;
            wins++; break;
        }
    }

    else if (a == 2)
    {
        switch (b)
        {
            case 1: cout << "You win! " << endl;
            wins++; break;
            case 2: cout << "It's a draw! " << endl; break;
            case 3: cout << "You lose " << endl; break;
        }
    }

    else if (a == 3)
    {
        switch (b)
        {
            case 1: cout << "You lose " << endl; break;
            case 2: cout << "You win! " << endl;
            wins++; break;
            case 3: cout << "It's a draw " << endl; break;
        }
    }

}

void Game::dispGame()
{   games++;
    cout << "\nGames played: " << games << "   game(s) won: " << wins << endl;
}

int main()
{
    string start, ans;
    int userChoice, compChoice;

    Game a;

    do{
        start = a.startGame();

    if (start == "yes")
        userChoice = a.makeDecision();
    else if (start == "no")
        return 0;
    else
    {
        cout << "\nInvalid decision. Try again!" << endl;
    }
    }while(start != "yes");


    do{
    compChoice = a.computerDecision();

    a.showInfo(userChoice, compChoice);

    a.compare(userChoice, compChoice);

    Game::dispGame();

    do{
    cout << "\nWould you like to play another game? Type 'yes' or 'no' " << endl;
    cin >> ans;

    if (ans == "yes")
        userChoice = a.makeDecision();
    else if (ans == "no")
        return 0;
    else
    {
        cout << "\nInvalid decision. Try again!" << endl;
    }
    }while (ans != "yes");

    }while(ans == "yes");
    return 0;
}
