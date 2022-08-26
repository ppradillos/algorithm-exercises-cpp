# Magic triplet exercise

## Problem statement

Given an integer array arr of size n, find all magic triplets in it.

Magic triplet is a group of three numbers whose sum is zero.

Note that magic triplets may or may not be made of consecutive numbers in arr.


### Example One

Input: arr = [10, 3, -4, 1, -6, 9]

Output: [“10,-4,-6”, “3,-4,1”]


### Example Two


Input: arr = [12, 34, -46]

Output: [“12,-46,34”]


### Example Three

Input: arr = [0, 0, 0];

Output: [“0,0,0”]


### Example Four


Input: arr = [-2, 2, 0 -2, 2];

Output: [“2,-2,0”]


### Notes

Input Parameters: Function has one argument: array of integers arr.

Output: Function must return an array of strings. Each string (if any) in the array must represent a unique magic triplet and strictly follow this format: “1,2,-3” (no whitespace, one comma between numbers).

Order of the strings in the array is insignificant. Order of the integers in any string is also insignificant. For example, if [“1,2,-3”, “1,-1,0”] is a correct answer, then [“0,1,-1”, “1,-3,2”] is also a correct answer.

Triplets that only differ by order of numbers are considered duplicates, and duplicates must not be returned. For example, if “1,2,-3” is a part of an answer, then “1,-3,2”, “-3,2,1” or any permutation of the same numbers may not appear in the same answer (though any one of them may appear instead of “1,2,-3”).

Constraints:

1 n
-1000 arr
arr may contain duplicate numbers.
arr is not necessarily sorted.

## Solution implemented

As we are trying to reach efficiency and good performance, then brute force is not allowed as valid approach. We propose a kind of "divide & conquer" approach instead, so that we will carry out as less operations as needed to get all *magic triplets* from the array of integers.

To achieve our goal: 

1. - Sort the given array.
2. - Get the value of the mid position within the sorted array. Like in a binary search algortithm.
3. - Check such value. If less than 0, then there are more negative values than positives, so we reverse the array's order to start from positives.
4. - Iterating over an array from left to right is commonly more intuitive. In the previous step, we make sure we put negatives or positives on left side, depending on which subset is smaller, so we will iterate over less integers.
5. - Get maximum strictly iterations needed to reach the end of the (smaller) subset, starting from the left. Passing through such array index would be pointless.
6. - Start iterating over the array of integers. We add left bound position value + upper bound position value. Thank to the sorting operation, **this is actually a substraction** as both numbers should hold different sign. One of them should be positive or zero, the other one negative or zero.
7. - Inverse the result of the previous addition (that is, multiply by -1). That's the number we must search within the rest of the array to complete the magic triplet.
8. - Ensure the 3rd integer we shall look for is within the array's limits. If not, we don't even bother to look for it. Decrease upper bound and start from step 6.
9. - If it's possible to get the number, iterate over the array until we reach the number or bounds overlap.
10. - End of the nested loop. Increase lower bound until the value it holds no longer repeats to prevent repeated magic triplets from happening.
11. - Repeat from step 6 until the lower bound reaches "max iterations" index.

## Testing

Modify "arrayOfNumbers" in the source code to try different combinations.
