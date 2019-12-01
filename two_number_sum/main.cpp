//
//  main.cpp
//  two_number_sum
//
//  Created by adeeb mohammed on 29/11/19.
//  Copyright © 2019 adeeb mohammed. All rights reserved.
//
/*
    this programs will take one empty array and an integer and check whether the sum of
    any two intgers will make up the sum of that integer number
    Step 1 :- Sort the array [Good sorting algorithm will in nlogn]
    
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
    Solution without using hashtable
    here the time complexity will be O(logn)
    sort the array in ascending order
    sort function complexity is O(logn)
    Step 1: set leftPointer to left of the array
    Step 2: Set right pointer to the right of the array
    Step 3: check l+r == target sum, if yes return left and right number
    Step 4: if l+r is less than target number advance left to next position
    Step 5: repeat Step 3 and 4:
    Step 6: If l+r is greater than target sum advance right pointer one position to left.
    Step 7: repeat step 3 to 6
 */

std::vector<int> _twoNumberSum(std::vector<int> array,int targetSum){
    
    std::vector<int> result;
    int currentLeft  = 0;
    int currentRight = 0;
    int currentSum   = 0;
    
    std::sort(array.begin(),array.end());
    auto rIt = array.rbegin();
    auto it = array.begin();
    currentRight = *rIt;
    currentLeft = *it;
    
    while(currentLeft < currentRight){
        currentSum = currentLeft + currentRight;
        if(currentSum == targetSum){
            result.push_back(currentLeft);
            result.push_back(currentRight);
            return result;
        }else if(currentSum > targetSum){
            currentRight = *(++rIt);
        }else{
            currentLeft =*(++it);
        }
    }
    
    return result;
 }

/*
    Solution using hash Table .
    Time Complexity o(n) :-> order of the length of n
    space complexity O(n) hash map takes space complexty [hash map has to occupy all of the elements if  the sum second element is found at the end of the array]
        or the two elements are not found
        x+y  = 10
        Step1: iterate each element in the array.
        Stpe2: Take the difference of each element
        Step3: check whether it exists in the hash map
        Step4: If yes insert the element found in the array and the current element and return back
        Step5: if no insert the current element to the hash map
 */
std::vector<int> twoNumberSum(std::vector<int>array,int targetSum){
    std::vector<int> result;
    std::unordered_map<int,int> checkList;
    int difference = 0;
    for(auto currentNum : array){
        difference = targetSum - currentNum;
        if(checkList.find(difference) != checkList.end()){
            result.push_back(difference);
            result.push_back(currentNum);
            break;
        }
        checkList[currentNum] = 1;
    }
    checkList.clear();
    return result;
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> array;
    int targetSum = 0;
    int arrLength = 0;
    int inputNum  = 0;
    
    std::cout << "Enter result sum"<< std::endl;
    std::cin>> targetSum;
    std::cout << "Enter the number of elements in the array" << std::endl;
    std::cin >> arrLength;
    std::cout << "Enter the numbers"<< std::endl;
    
    for(auto i = 1; i <=arrLength; i++ ){
        std::cin >> inputNum;
        array.push_back(inputNum);
    }
    auto result = _twoNumberSum(array,targetSum);
    std::cout << "The result Numbers are" << std::endl;
    for(auto it : result){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}
