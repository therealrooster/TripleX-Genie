#include <iostream>
#include <ctime>

// Welcome Message
void PrintIntro(int Difficulty)
{
    // Welcome message
    int RemainingLevels = 6 - Difficulty;
    std::cout << "\n            {}   _,\n        ___/__\\_//\n       (_\\_ L" << Difficulty << " _/\n        -' `)(`\n           ~``~\n\n";

    if (RemainingLevels == 5)
    {
        std::cout << "You've stumbled upon a genie lamp...\n";
        std::cout << "The lamp is locked by a code that must be cracked 5 times...\n";
    }
    else if (RemainingLevels > 1)
    {
        std::cout << "\nYou need to crack the code " << RemainingLevels << " more times in order to summon the genie...\n";
    }    
    else 
    {
        std::cout << "\nYou are so close! Crack the code one last time in order to summon the genie...\n\n";
    }
}

// Code for game play
bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "\n+ There are 3 numbers in the code\n" << "+ The numbers add-up to: " << CodeSum << "\n+ The numbers multiply to give: " << CodeProduct << "\n";
    
    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if guess matches
    int NumGuess = 1;

    while (NumGuess < 6)
    {
        if (NumGuess == 5)
        {
            std::cout << "\n*POOF! The lamp has disappeared!*\n\nGame Over!\n";
            exit (0);
        }
        else if (GuessSum == CodeSum && GuessProduct == CodeProduct)
        {
            break;
        }
        else if (NumGuess == 4)
        {
            std::cout << "\n*Genie: You are dumber than I thought!*\nFinal guess, make it count!\n";
            std::cin >> GuessA >> GuessB >> GuessC;
            GuessSum = GuessA + GuessB + GuessC;
            GuessProduct = GuessA * GuessB * GuessC;
            ++NumGuess;
        }
        else 
        {
            std::cout << "\n*The genie laughs at you...*\nTry again!\n";
            std::cin >> GuessA >> GuessB >> GuessC;
            GuessSum = GuessA + GuessB + GuessC;
            GuessProduct = GuessA * GuessB * GuessC;
            ++NumGuess;
        }
    }
    
    std::cout << "\n**You did it! You've cracked the L" << Difficulty << " code!**\n";
    return true;

}

// Main function
int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day

    int Level = 1;
    int const MaxLevel = 5;
    
    while (Level <= MaxLevel) // Loop until all guesses correctly made
    {
        bool bLevelComplete = PlayGame(Level);
        std::cin.clear(); // Clears errors
        std::cin.ignore(); // Discards buffer

        if (bLevelComplete)
        {
            ++Level;
        }
        
    }
    
    // Print winning message
    std::cout << "\n            Your wish is my command!\n";
    std::cout << "\n                    .,.'*`','`.,.,.\n                  ,'-.,  `.        `,\n            {}   _,    `.    *,     ;\n        ___/__\\_//      ` .,  .$. ,.`     \n       (_\\_ L5 _/            (+_+) \n        -' `)(`             6--*--9\n           ~``~              .| |.\n";
    return 0;
}