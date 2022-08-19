/**
Given an integer array arr of size n, find all magic triplets in it.

Magic triplet is a group of three numbers whose sum is zero.

Note that magic triplets may or may not be made of consecutive numbers in arr.

Example One

Input: arr = [10, 3, -4, 1, -6, 9]

Output: [“10,-4,-6”, “3,-4,1”]

Example Two

Input: arr = [12, 34, -46]

Output: [“12,-46,34”]

Example Three

Input: arr = [0, 0, 0];

Output: [“0,0,0”]

Example Four

Input: arr = [-2, 2, 0 -2, 2];

Output: [“2,-2,0”]

Notes

Input Parameters: Function has one argument: array of integers arr.

Output: Function must return an array of strings. Each string (if any) in the array must represent a unique magic triplet and strictly follow this format: “1,2,-3” (no whitespace, one comma between numbers).

Order of the strings in the array is insignificant. Order of the integers in any string is also insignificant. For example, if [“1,2,-3”, “1,-1,0”] is a correct answer, then [“0,1,-1”, “1,-3,2”] is also a correct answer.

Triplets that only differ by order of numbers are considered duplicates, and duplicates must not be returned. For example, if “1,2,-3” is a part of an answer, then “1,-3,2”, “-3,2,1” or any permutation of the same numbers may not appear in the same answer (though any one of them may appear instead of “1,2,-3”).

Constraints:

1 n
-1000 arr
arr may contain duplicate numbers.
arr is not necessarily sorted.
*/

#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>


int main()
{
    // a bunch of numbers to generate magic triplets. Change the content of this array for testing
    int arrayOfNumbers[] = { 10, 3, -4, 1, -6, 9, -11, -1896, 1895, 0, 38, -564961648, 0, -4, 1, 1, -1, 0, 0, 1, -1, -6 };

    // put numbers into a vector and sort it
    std::vector<int> arr (arrayOfNumbers, arrayOfNumbers + sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]) );
    std::sort(arr.begin(), arr.end());
    
    // print current values of vector without using a loop
    std::ostream_iterator< int > output( std::cout, " " );
    std::cout << "\nVector content:\n";
    std::copy( arr.begin(), arr.end(), output );
    std::cout << std::endl;
    
    // Time to find magic triplets
    // We start getting the value of mid position to check if we have more positive or negative values in it
    int mid_position = arr[arr.size()/2];
    std::cout << "mid_position value: " << mid_position << "\n";
    
    if (mid_position < 0)
    {
        // There are more negative values than positive. 
        // Then, reverse the array's order so we can start with positive values easily
        std::reverse(arr.begin(), arr.end());
        std::cout << "new array order" << "\n";
        
        for(unsigned int i = 0; i < arr.size(); ++i)
        {
            std::cout << arr[i] << "\n";
        }
    }
    
    std::vector<std::string> triplets;
    int lowerBound = 0; 
    int upperBound = arr.size() - 1;
    int resultOfAddition = 0;
    int numberToSearch = 0;

    // Set the limit of strictly needed iterations for faster performance
    int maxIterations = 0;
    if (arr[lowerBound] < 0)
    {
        // if we start from negatives, get needed iterations to reach the first positive number
        while (arr[maxIterations] < 1 )
            ++maxIterations;
    }
    else
    {
        // if we start from positives, get needed iterations to reach the first negative number
        while (arr[maxIterations] > -1 )
            ++maxIterations;
    }
    
    while (lowerBound < maxIterations )
    {
        // we add lower bound value to upper bound value. As we have positives and negatives separated, 
        // the addition is actually a substraction. Then we get the 3rd number for magic triplet 
        // by reversing the sign of the result of the addition
        resultOfAddition = arr[lowerBound] + arr[upperBound];
        numberToSearch = resultOfAddition * -1;
        
        // if number to search is greater than the limit of our array
        // we don't even bother to search. The desired number will not be there
        if (std::abs(numberToSearch) > std::abs(arr[lowerBound]))
        {
            upperBound = upperBound - 1;
            continue;
        }
        
        // Iterating until either we get a match of the 3rd number or bounds overlap
        for (int i = lowerBound + 1; i < upperBound; ++i)
        {
            if (arr[i] == numberToSearch)
            {
                std::string triplet = "";
                triplet += std::to_string(arr[lowerBound]);
                triplet += ",";
                triplet += std::to_string(arr[upperBound]);
                triplet += ",";
                triplet += std::to_string(arr[i]);
                triplets.push_back(triplet);
                break;
            }
        }
        
        // We don't want repeated magic triplets, so we proceed with the next different value
        // to start the process again, but with a reduced set of numbers each time.
        int last_value = arr[lowerBound];
        while(last_value == arr[lowerBound])
            lowerBound = lowerBound + 1;
    }
    
    // print the found magic triplets
    if(triplets.empty())
    {
        std::cout << "No magic triplets found:\n";    
    }
    else
    {
        std::cout << "Magic triplets found:\n";
        for (auto i = triplets.begin(); i != triplets.end(); ++i)
            std::cout << "[" << *i << "]\n";
    }

    return 0;
}