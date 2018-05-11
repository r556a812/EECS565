/**
*	@file : VigenereCipher.cpp
*	@author :  Richard Aviles
*	@date : 2018.02.13
*	Purpose: Creates the VigenereCipher and its methods.
*/

#include "VigenereCipher.h"


/**  The VigenereCipher constructor.  Takes in
***  a string, called key, that is used for
***  encrypt/decrypt. Sets m_key to given string
**/
VigenereCipher::VigenereCipher(std::string key)
{
  m_key = key;
}

/**  The VigenereCipher second constructor.
***  Takes in no paremeters allowing to set
***  the key value at a later time
**/
VigenereCipher::VigenereCipher()
{

}

VigenereCipher::~VigenereCipher()
{

}

/** Takes in a string, called key, and sets
*** the key to the given string
**/
void VigenereCipher::setKey(std::string key)
{
  m_key = key;
}

/**  Method to convert a given string, called text,
***  into a single string with no spaces and
***  converted into all uppercase letters. Returns
***  the converted string back
**/
std::string VigenereCipher::convertString(std::string text)
{
  //Remove spaces from the text
  std::string temp = text;
  temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end()); //Got the erase from https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c

  //Transform the string into all uppercase letters
  for(unsigned int i = 0; i < temp.length(); i++)
  {
    temp[i] = toupper(temp[i]);
  }

  return temp;
}

/**  Method that takes in a string, called plaintext,
***  and uses the key to encrypt the text into ciphertext.
***  Returns the encrypted text.
**/
std::string VigenereCipher::encrypt(std::string plaintext)
{
  int keyspot = 0;
  int keylength = m_key.length();
  std::string key = m_key;

  for(unsigned int i = 0; i < plaintext.length(); i++)
  {
    plaintext[i] = ( (plaintext[i]-65) + ((key[keyspot]-65)%26) )%26 + 65;

    if(keyspot == keylength-1)
    {
      keyspot = 0;
    }
    else
    {
      keyspot++;
    }
  }

  return plaintext;
}

/**  Method that takes in a string,called ciphertext,
***  and uses the key to decrypt the text into plaintext.
***  Returns the decrypted text.
**/
std::string VigenereCipher::decrypt(std::string ciphertext)
{
  int keyspot = 0;
  int keylength = m_key.length();
  int check = 0;
  std::string key = m_key;

  for(unsigned int i = 0; i < ciphertext.length(); i++)
  {
    check = ( (ciphertext[i]-65) - ((key[keyspot]-65)%26) )%26;
    if(check < 0)
    {
      check+=26;
    }
    ciphertext[i] = check + 65;

    if(keyspot == keylength-1)
    {
      keyspot = 0;
    }
    else
    {
      keyspot++;
    }
  }

  return ciphertext;
}
