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

    // If repeated chars in a digraph add an X or Q if XX


    // if the size of input is odd, add a trailing Z
    // Loop over the input in Digraphs
    //- Find the coords in the grid for each digraph
    //- Apply the rules to these coords to get 'new' coords
    //- Find the letter associated with the new coords
    // return the text
    //return input;
    



    std::string outputText = inputText;

    return outputText;
}