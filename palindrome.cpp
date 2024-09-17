//
//  palindrome.cpp
//  Project1
//
//  Created by Kaustubh on 9/11/24.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int reverse(int input);
bool isPalindrome(int input);
void printOut(std::vector<int> inputs);

int main() {
    
    std::cout << "Enter input:" << std::endl;
    int iterations;
    std::cin >> iterations;
    std::vector<int> inputs;
    std::cout << "Enter " << iterations << " numbers:" << std::endl;
    
    for(int i = 0; i < iterations; i++) {
        int temp;
        std::cin >> temp;
        inputs.push_back(temp);
    }
    std::cout << std::endl;
    printOut(inputs);
    
    return 0;
}

int reverse(int input) {
    int output = 0;
    while (input > 0) {
        output *= 10;
        output += input % 10;
        input /= 10;
    }
    return output;
}

bool isPalindrome(int input) {
    return (input == reverse(input));
}

void printOut(std::vector<int> inputs) {
    std::vector<std::pair<int, int> > outputs;
    for(int i = 0; i < inputs.size(); i++) {
        bool done = false;
        int iterations = 0;
        while(!done && iterations < 1000) {
            int temp = reverse(inputs[i]);
            inputs[i] += temp;
            iterations++;
            if(isPalindrome(inputs[i])) done = true;
        }
        std::pair<int, int> pair1 (iterations, inputs[i]);
        outputs.push_back(pair1);
    }
    for(std::pair<int, int> j : outputs) {
        std::cout << j.first << " " << j.second << std::endl;
    }
}
