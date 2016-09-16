#include "stdafx.h"
#include "ValidationHelper.h"


ValidationHelper::ValidationHelper()
{
}


ValidationHelper::~ValidationHelper()
{
}


bool ValidationHelper::isCharacter(const char character)
{
	return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
	//Checks if a Character is a Valid A-Z, a-z Character, based on the ascii value
}
bool ValidationHelper::isSpecialCharacter(const char character)
{
	std::string allowedcharacter = " .'@+-[]()";
	return (allowedcharacter.end() != std::find(allowedcharacter.begin(), allowedcharacter.end(), character));
}
bool ValidationHelper::isNumber(const char character)
{
	return (character >= '0' && character <= '9');
	//Checks if a Character is a Valid 0-9 Number, based on the ascii value
}

bool ValidationHelper::isValidPhoneNumber(const std::string & strNumber)
{
	if (strNumber.length() < 10)
	{
		return false;
	}

	if (strNumber[0] != '+' && !isNumber(strNumber[0]))
	{
		return false;
	}

	for (auto numberChar = strNumber.begin(); numberChar != strNumber.end(); ++numberChar)
	{
		if (!isNumber(*numberChar))
		{
			return false;
		}
	}
	return true;
}


bool ValidationHelper::isValidEmailAddress(const std::string&  strEmailAddress)
{
	if (strEmailAddress.empty()) // If cannot read the Email Address...
		return 0;
	if (!isCharacter(strEmailAddress[0])) // If the First character is not A-Z, a-z
		return 0;
	int AtOffset = -1;
	int DotOffset = -1;
	unsigned int Length = strEmailAddress.length(); // Length = StringLength (strlen) of EmailAddress
	for (unsigned int i = 0; i < Length; i++)
	{
		if (strEmailAddress[i] == '@') // If one of the characters is @, store it's position in AtOffset
			AtOffset = (int)i;
		else if (strEmailAddress[i] == '.') // Same, but with the dot
			DotOffset = (int)i;
	}
	if (AtOffset == -1 || DotOffset == -1) // If cannot find a Dot or a @
		return 0;
	if (AtOffset > DotOffset) // If the @ is after the Dot
		return 0;
	return !(DotOffset >= ((int)Length - 1)); //Check there is some other letters after the Dot
}

bool ValidationHelper::isValidString(const std::string & strValue)
{
	for (char character : strValue)
	{
		if (!( isNumber(character) || isCharacter(character) || isSpecialCharacter(character) ) )
		{
			return false;
		}
	}
	return true;
}
