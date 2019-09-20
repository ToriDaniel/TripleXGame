#include <iostream>

void PrintIntroduction(int Difficulty)
{
    //Welcome messages
    std::cout << "You are a secret agent breaking into level " << Difficulty;
    std::cout << "secure server room...\nEnter the correct code to continue...\n\n";
    //previous code had std::cout << std::endl; 
    //these all changed to have \n included into the quotation marks
    //also instead of two lines, combined to one.
}

bool PlayGame(int Difficulty)
{
    //call function to print introduction message
    PrintIntroduction(Difficulty)    ;

    //the numbers that the users will need to guess
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty; 

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print CodeSum and Code Product to the terminal
    
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    //the player's guesses
    int GuessA, GuessB, GuessC;
    
    //These three lines below can be condensed to the 4th line below.
    //std::cin >> GuessA;
    //std::cin >> GuessB;
    //std::cin >> GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    //check guesses
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true; 
    }

    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}



int main()
{
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty) //loop game until reach max difficulty
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}

