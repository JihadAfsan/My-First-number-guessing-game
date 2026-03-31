#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

int loadBestScore()
{
    ifstream file("Bestscore.txt");
    int best;

    if(file>>best)
        return best;
    return -1;
}

void saveBestScore(int score)
{
    ofstream file("Bestscore.txt");
    file<<score;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    bool playAgain=true;

    cout<<"======================================\n";
    cout<<"Number Guessing Game\n";
    cout<<"Jihad Afsan\n";
    cout<<"======================================\n\n";

    while(playAgain)
    {
        int difficulty;
        int maxNumber;
        int maxAttempts;

        cout<<"Choose Difficulty:\n";
        cout<<"1. Easy (1-50, 10 attempts)\n";
        cout<<"2.Medium (1-100, 8 attempts)\n";
        cout << "3. Hard   (1 - 500, 7 attempts)\n";
        cout << "Enter choice: ";
        cin >> difficulty;


        if(difficulty==1)
        {
            maxNumber=50;
            maxAttempts=10;
        }
        else if(difficulty==2)
        {
            maxNumber=100;
            maxAttempts=8;
        }
        else{
            maxNumber=500;
            maxAttempts=7;
        }
        int secretNumber=rand()%maxNumber+1;
        int guess;
        int attempts=0;
        bool won=false;


        cout << "\nI'm thinking of a number between 1 and " << maxNumber << ".\n";
        cout << "You have " << maxAttempts << " attempts. Good luck!\n\n";

        while (attempts < maxAttempts)
        {
            cout << "Attempt " << attempts + 1 << "/" << maxAttempts << " - Enter your guess: ";
            cin >> guess;

            if (cin.fail())
            {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (guess < 1 || guess > maxNumber)
            {
                cout << "Please enter a number between 1 and " << maxNumber << ".\n";
                continue;
            }

            attempts++;

            if (guess < secretNumber)
            {
                cout << "Too low!";
            }
            else if (guess > secretNumber)
            {
                cout << "Too high!";
            }
            else
            {
                won = true;
                cout << "\nCongratulations! You guessed the number in " << attempts << " attempts!\n";
                break;
            }

            // Hint system
            if (secretNumber % 2 == 0)
                cout << " Hint: The number is even.";
            else
                cout << " Hint: The number is odd.";

            if (secretNumber % 5 == 0)
                cout << " It is also divisible by 5.";

            cout << "\n\n";
        }
         if (!won)
        {
            cout << "\nGame Over! The secret number was " << secretNumber << ".\n";
        }

        int bestScore = loadBestScore();

        if (won)
        {
            if (bestScore == -1 || attempts < bestScore)
            {
                saveBestScore(attempts);
                cout << "New Best Score: " << attempts << " attempts!\n";
            }
            else
            {
                cout << "Best Score So Far: " << bestScore << " attempts.\n";
            }
        }
         char choice;
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y')
        {
            playAgain = false;
        }

        cout << "\n-------------------------------------\n\n";
    }
      cout << "Thanks for playing! Keep building more games.\n";

    return 0;
}







