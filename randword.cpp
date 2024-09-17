//
//  randword.cpp
//  Project1
//
//  Created by Kaustubh on 9/11/24.
//

#include "randword.hpp"

static std::vector<std::string> dictionary;

int main() {
    
    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "I will choose a secret word. On each turn, you guess a letter." << std::endl;
    std::cout << "If the letter is in my secret word, I will show you where it appears--" << std::endl;
    std::cout << "if not, an extra part of your body gets added to the gallows." << std::endl;
    std::cout << "Guess incorrectly eight times, and you lose and are left to hang.\n" << std::endl;
    
    // edit file name here
    std::string fileName = "dictionary.txt";
    dictionary = initDictionary(fileName);
    std::string secretWord = chooseRandomWord();
    int guessesLeft = 8;
    std::string currentGuess = "";
    for(int i = 0; i < secretWord.size(); i++) {
        currentGuess.append("-");
    }
    bool wordFound = false;
    
    while(guessesLeft > 0 && !wordFound) {
        std::cout << "The word now looks like this: " << currentGuess << std::endl;
        std::cout << "You have " << guessesLeft << " guesses left." << std::endl;
        std::cout << "Guess a letter: ";
        char letterGuess;
        std::cin >> letterGuess;
        
        bool correct = false;
        for(int i = 0; i < secretWord.size(); i++) {
            if(letterGuess == secretWord[i]) {
                currentGuess[i] = letterGuess;
                correct = true;
            }
        }
        if(correct) {
            std::cout << "That guess is correct!" << std::endl;
        } else {
            guessesLeft--;
            std::cout << "That guess is incorrect. You now have " << guessesLeft << " guesses remaining." << std::endl;
        }
        if(!(currentGuess.find("-") != std::string::npos)) {
            wordFound = true;
            std::cout << "Congratulations! You guessed the word " << secretWord << "." << std::endl;
        }
        if(guessesLeft == 0) {
            std::cout << "Sorry, you're out of guesses. The word was " << secretWord << "." << std::endl;
        }
    }
    
    return 0;
    
}

std::string chooseRandomWord() {
    srand(time(NULL));
    int index = rand() % dictionary.size();
    return dictionary[index];
}

std::vector<std::string> initDictionary(std::string dict) {
    std::vector<std::string> entries;
    std::ifstream inputFile;
    inputFile.open(dict);
    std::string currentLine;
    while(getline(inputFile, currentLine)) {
        entries.push_back(currentLine);
    }
    return entries;
}
