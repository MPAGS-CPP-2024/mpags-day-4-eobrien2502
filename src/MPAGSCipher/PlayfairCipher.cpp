#include "PlayfairCipher.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

PlayfairCipher::PlayfairCipher(const std::string& key)
{
    this->setKey(key);

}

void PlayfairCipher::setKey(const std::string& key) {

    // store the original key
    key_ = key;
    
    // Append the alphabet
    key_ =+ "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   
    // Make sure the key is upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_), ::toupper);

    // Remove non-alpha characters
    auto nonalpha = [] (char str_char){
        if (std::isalpha(str_char))
            return false;
        else
            return true;
    };

    auto iter = std::remove_if(key_.begin(), key_.end(), nonalpha);
    key_.erase(iter,key_.end());

    // Change J -> I
    auto jtoi = [] (char letter){
        if (letter == 'J'){
            letter = 'I';
            return letter;
        }
        else {
            return letter;
        }

    };

    std::transform(key_.begin(), key_.end(), key_.begin(), jtoi);

    // Remove duplicated letters
    std::string l_encountered{""};

    auto rem_dup = [&] (char l){
        // check the char against a string of letters already found
        std::size_t found = l_encountered.find(l);
        // if char is in the list, mark for removal (return true)
        if (found != std::string::npos){
            return true;
        // if char isn't already in list, add it to list and return false
        }
        else {
            l_encountered += l;
            return false;
        }

    };  

    auto iter2 = std::remove_if(key_.begin(), key_.end(), rem_dup);
    key_.erase(iter2,key_.end());

    // Store the coords of each letter
    // looping over each letter and storing coordinates and the letter in a map

    // the position divided by 5 (as an integer) tells us the row number
    // the position mod 5 tells us the column number
   
    for (std::size_t i{0}; i < keyLength_; i++){
        std::size_t row_ind{i / gridSize_};
        std::size_t col_ind{i % gridSize_};
        
        auto coords = std::make_pair(row_ind,col_ind);

        ChartoCoordsMap_[key_[i]] = coords;
        CoordstoCharMap_[coords] = key_[i];

      
    };

    
}

std::string PlayfairCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {

   

    // Change J → I
    auto jtoi = [] (char letter){
        if (letter == 'J'){
            letter = 'I';
            return letter;
        }
        else {
            return letter;
        }

    };

    std::transform(inputText.begin(), inputText.end(), inputText.begin(), jtoi);

    std::string examinedDigraphs{""};

    // If repeated chars in a digraph add an X or Q if XX
    // Look at each character in inputText
    // If the character before is the same as the current one, replace with X + current character
    // If both the characters are XX, replace with QX.
    for (std::size_t i{0}; i < inputText.size(); i++){
        // only doing something on every second letter
        if (i == 1 % 2){
            // checking if there are pairs of repeated letters
            if (inputText[i] == inputText[i-1]){
                // if the repeated letters are XX, populate examinedDigrahs with QX
                if (inputText[i] == 'X'){
                    examinedDigraphs+= "QX";
                    
                }
                // if the repeated letters are not XX, populate examinedDigraphs with X(letter)
                else{
                    examinedDigraphs+= "X";
                    examinedDigraphs+= inputText[i];
                    

                }
            }
            // if the pair are not the same letter, populate examinedDigraphs with the letters
            else{
                examinedDigraphs+= inputText[i-1];
                examinedDigraphs+= inputText[i];
                
            }


        }
    }


    // If the length of inputText is odd, then the above loop did not add the last letter to examinedDigraphs.
    // We need to add this letter and a Z to examinedDigraphs
    // if the size of input is odd, add a trailing Z
    if (inputText.size() == 1 % 2){
        examinedDigraphs+= inputText[inputText.size()-1];
        examinedDigraphs+= "Z";
    }


    // Loop over the input in Digraphs

    //- Find the coords in the grid for each digraph
    //- Apply the rules to these coords to get 'new' coords
    //- Find the letter associated with the new coords
    // return the text
    //return input;
    



    std::string outputText = inputText;

    return outputText;
}