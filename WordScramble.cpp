#include "WordScramble.h"
#include <vector>

// Takes a word and return a shuffled version
std::string shuffleWord(std::string myWord){
    std::string newWord = myWord;
    random_shuffle(newWord.begin(), newWord.end());
    return newWord;
}

void playDifficulty(std::vector<std::string> wordVector){
    std::string word = "", scrambledWord = "", guess = "";
    std::vector<std::string> myWord;
    
    // word = random, scrambled word from EasyWords
    std::sample(
        wordVector.begin(),
        wordVector.end(),
        std::back_inserter(myWord),
        1,
        std::mt19937{std::random_device{}()}
    );
    
    word = myWord[0];
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    scrambledWord = shuffleWord(word);
    
    do {
        std::cout << "Unscramble the word: " << scrambledWord << std:: endl;
        std::cout << " >>";
        std::cin >> guess;
        std:: cout << std::endl;
        std::transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        
        if (guess == word){
            std::cout << "You guessed the word!" << std::endl;
            myWord.pop_back();
        } 

    } while (guess != word);

    return;
}

int main(){

    std::string choice = "", guess = "";
    std::vector<std::string> wordVector;

    std::cout << "Welcome to Word Scramble!" << std:: endl;
    while (choice != "0")
    {
        std::cout << "Please select a difficult" << std:: endl;
        std::cout << "1: Easy" << std:: endl;
        std::cout << "2: Medium" << std:: endl;
        std::cout << "3: Hard" << std:: endl;
        std::cout << "4: About" << std:: endl;
        std::cout << "0: Quit" << std:: endl << " >>";
        std::cin >> choice;
        std::cout << std::endl;

        // if (choice == "0"){
        //     break;
        // }
        if (choice == "1"){
            playDifficulty(EasyWords);
        }
        else if (choice == "2"){
            playDifficulty(MediumWords);
        }
        else if (choice == "3"){
            playDifficulty(HardWords);
        }
        else if (choice == "4"){
            std::cout << "Created by Kyler Schnaible =)" << std::endl;
        }   
        std::cout << std::endl;     
    }

    return 0;
}