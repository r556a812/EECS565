/**
*	@file : VigenereCipher.h
*	@author : Richard Aviles
*	@date : 2018.02.13
	Purpose: The header file for VigenereCipher.
*/

#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <iostream>
#include <algorithm>

class VigenereCipher
{
    public:
        VigenereCipher(std::string key); //@pre Takes in a string for the key @post Creates a constructor for VigenereCiphere @return None
        VigenereCipher(); //@pre None @post Creates a constructor for VigenereCiphere @return None
        ~VigenereCipher(); //@pre None @post Deletes the VigenereCiphere @return None
        void setKey(std::string key); //@pre Takes in a string to set the key as @post Sets the key value @return None
        std::string convertString(std::string text); //@pre Takes in a string to be converted @post Removes spaces from string and makes all letters lowercase @return Converted string
        std::string encrypt(std::string plaintext); //@pre Takes in a string to be encrypted @post Encrypts the given string using the key @return Encypted key
        std::string decrypt(std::string ciphertext); //@pre Takes in a string to be dencrypted @post Decrypts the given string using the key @return Dencypted key

      private:
        std::string m_key; //String holding the key

};

#endif
