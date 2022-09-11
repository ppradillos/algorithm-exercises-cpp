/**
 * @file minimum_number_of_coins.cpp
 * @author ppradillos
 * @brief Solution of "minimum number of coins" problem, a classic algorithm exercise with data structures involved
 * @version 1.0
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>

/* Data from the exercise statement */

// Coin types. Modify to test different combinations
static std::vector<unsigned int> COIN_TYPES = { 1, 3, 5, 9, 18, 100, 5348 };

// money amount to reach. Modify to test different results
static unsigned int MONEY_AMOUNT = 630u;

/* solution struct */
typedef struct solution_t {
    std::string coinTypesUsed;  // This string represents the coin types used to achieve the amount of money
    int coinsNumberNeeded;      // how many coins were needed to get the money
} solution_t;

int main()
{
    // print current values of vector without using a loop
    std::ostream_iterator<unsigned int> output( std::cout, " " );
    std::cout << "\nCoin types:\n";
    std::copy( COIN_TYPES.begin(), COIN_TYPES.end(), output );
    std::cout << std::endl;

    // print desired amount of money
    std::cout << "Desired money amount: " << MONEY_AMOUNT << "\n";

    // sort the array in reverse order, so that higher coin types are placed at the beginning of the vector
    std::reverse(COIN_TYPES.begin(), COIN_TYPES.end());
    
    // time to get minimum number of coins to solve the problem
    solution_t solution;

    // fast check. Let's see if the desired amount matches a given coin type
    bool found = false;
    for (unsigned int i = 0; i < COIN_TYPES.size(); ++i)
    {
        if(MONEY_AMOUNT == COIN_TYPES[i])
        {   
            solution.coinTypesUsed.append("[");
            solution.coinTypesUsed.append(std::to_string(COIN_TYPES[i]));
            solution.coinTypesUsed.append("]");
            solution.coinsNumberNeeded = 1;
            found = true;
            break;
        }
    }

    if (!found)     // fast check failed. Let's see how many coins are strictly needed to get the desired amount of money
    {
        unsigned int lowerBound = 0; 
        unsigned int coinCounter = 0;
        unsigned int resultOfAddition = 0;
        
        while (!found && (lowerBound < COIN_TYPES.size()))
        {
            // if the coin type is just too big for the desired amount of money, just skip it and go to the next
            if(MONEY_AMOUNT < COIN_TYPES[lowerBound])
            {
                ++lowerBound;
                continue;
            }

            std::string coins;
            coins.append("[");

            // iterate as much until the desired amount of money is reached, or we pass over it
            while (MONEY_AMOUNT >= resultOfAddition)
            {
                resultOfAddition += COIN_TYPES[lowerBound];             // add the same value over and over
                coins.append(std::to_string(COIN_TYPES[lowerBound]));   // add the value to the string result
                coins.append(",");                                      // comma for a better presentation
                ++coinCounter;

                if (MONEY_AMOUNT == resultOfAddition)
                {
                    /* replace last comma for bracket */
                    std::size_t tokenFound = coins.find_last_of(",");
                    coins = coins.substr(0, tokenFound);
                    coins.append("]");

                    /* solution populated. Game over */
                    solution.coinTypesUsed = coins;
                    solution.coinsNumberNeeded = coinCounter;
                    found = true;
                    break;
                }
                else if (MONEY_AMOUNT < resultOfAddition)
                {
                    // assuming we got too far adding coins. Let's get back one iteration
                    resultOfAddition -= COIN_TYPES[lowerBound];
                    --coinCounter;
                    ++lowerBound;

                    /* removing extra info from the solution string. It's garbage now */
                    std::size_t tokenFound = coins.find_last_of(",");
                    coins = coins.substr(0, tokenFound);
                    tokenFound = coins.find_last_of(",");
                    coins = coins.substr(0, tokenFound + 1);
                }
            }
        }
    }

    if (found)
    {
        std::cout << "Coins needed to reach the desired money amount: " << solution.coinsNumberNeeded << "\n";
        std::cout << "Coins types used: " << solution.coinTypesUsed << "\n";
    }
    else
        std::cout << "No combination can reach the desired amount.\n";

    return 0;
}