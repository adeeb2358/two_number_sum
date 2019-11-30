//
//  main.cpp
//  two_number_sum
//
//  Created by adeeb mohammed on 29/11/19.
//  Copyright © 2019 adeeb mohammed. All rights reserved.
//
/*
    this programs will take one empty array and an integer and check whether the sum of any two intgers will make up the sum of that integer number
 */

#include <iostream>
#include <vector>
#include <unordered_map>
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
    int currentNum = 0;
    for(auto it=array.begin();it != array.end(); ++it){
        currentNum = *it;
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
    auto result = twoNumberSum(array,targetSum);
    std::cout << "The result Numbers are" << std::endl;
    for(auto it = result.begin(); it!= result.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
