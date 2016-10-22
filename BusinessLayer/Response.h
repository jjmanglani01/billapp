#pragma once
#ifndef __RESPONSE_H_INCLUDED__
#define __RESPONSE_H_INCLUDED__

#include <string>
#define ERROR_CODE_NOT_NULL 101
#define ERROR_CODE_LENGTH 102
#define ERROR_CODE_NOT_ACCEPTED_VALUE 103
#define ERROR_CODE_DATABASE 104
#define ERROR_CODE_DUPLICATE 105

#define ALL_OK 200
#define LENGTH_100 100
#define LENGTH_200 200
#define LENGTH_15 15
#define LENGTH_20 20
#define LENGTH_50 50
#define LENGTH_30 30
#define LENGTH_13 13
#define LENGTH_5 5

#define NO_ERROR "No Error"
#define LENGTH_LESS_THAN_EQUAL " value lenth should be less than equal to "
#define LENGTH_LESS_THAN_200 "value length should be less than 200"
#define LENGTH_LESS_THAN_100 "value length should be less than 100"
#define LENGTH_LESS_THAN_15 "value length should be less than 15"
#define LENGTH_LESS_THAN_20 "value length should be less than 20"
#define LENGTH_LESS_THAN_50 "value length should be less than 50"
#define DATABASE_ERROR "Database error occured"
#define NOT_ACCEPTED_VALUE "Value is not accepted"
#define DUPLICATE_VALUE "Duplicate value is not allowed for this field"

struct Response {
	int iResponseCode;
	std::string strResponseMsg;
};

inline struct Response generateResponse(int iCode, std::string strResponse = "")
{
	Response stResponse;
	stResponse.iResponseCode = iCode;
	if (iCode == ALL_OK)
	{
		stResponse.strResponseMsg = (std::string)NO_ERROR;
	}
	else
	{
		stResponse.strResponseMsg = strResponse;
	}
	return stResponse;
}


inline struct Response getResponseForLength(int length, std::string strFieldValue, std::string strFieldName)
{
	Response stResponse;
	stResponse.iResponseCode = ALL_OK;
	stResponse.strResponseMsg = (std::string)NO_ERROR;

	if (strFieldValue.length() > length)
	{
		stResponse.iResponseCode = ERROR_CODE_LENGTH;
		stResponse.strResponseMsg = strFieldName + (std::string)LENGTH_LESS_THAN_EQUAL;
		stResponse.strResponseMsg.append(std::to_string(length));
	}

	return stResponse;
}
#endif