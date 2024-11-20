#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include "CipherMode.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <map>


/**
 * \file PLayfairCipher.hpp
 * \brief Contains the declaration of the PlayfairCipher class
 */

/**
 * \class PlayfairCipher
 * \brief Encrypt or decrypt text using the Playfair cipher with the given key
 */
class PlayfairCipher {
  public:
    /**
     * \brief Create a new PlayfairCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit PlayfairCipher(const std::string& key);


    /**
     * \brief Set the key 
     *
     * \param key the key used in the cipher
     * \return no return 
     */
    void setKey(const std::string& key) ;

    

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const;

  private:
    

    /// The cipher key
    std::string key_{""};

    /// The grid size
    const std::string::size_type gridSize_{5};

    /// The key length = grid size^2
    const std::string::size_type keyLength_{gridSize_ * gridSize_};

    /// Lookup tables using the key

    /// Type definition for cordinates of the 5x5 grid
    using PlayfairCoords = std::pair<std::size_t, std::size_t>;

    /// Lookup table to go from the character to the coordinates
    std::map<char,PlayfairCoords> ChartoCoordsMap_;

    /// Lookup table to go from the coordinates to the character
    std::map<PlayfairCoords,char> CoordstoCharMap_;
};



#endif