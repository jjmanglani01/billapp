#pragma once
#ifndef __RESPONSE_H_INCLUDED__
#define __RESPONSE_H_INCLUDED__

#include <string>
#define ERROR_CODE_NOT_NULL 101
#define ERROR_CODE_LENGTH 102
#define ERROR_CODE_NOT_ACCEPTED_VALUE 103
#define ERROR_CODE_DATABASE 104

#define ALL_OK 200
#define LENGTH_100 100
#define LENGTH_200 200
#define LENGTH_15 15
#define LENGTH_20 20
#define LENGTH_50 50
#define LENGTH_30 30
#define LENGTH_13 13

#define NO_ERROR "No Error"
#define LENGTH_LESS_THAN_200 "value length should be less than 200"
#define LENGTH_LESS_THAN_100 "value length should be less than 100"
#define LENGTH_LESS_THAN_15 "value length should be less than 15"
#define LENGTH_LESS_THAN_20 "value length should be less than 20"
#define LENGTH_LESS_THAN_50 "value length should be less than 50"
#define DATABASE_ERROR "Database error occured"

struct Response {
	int iResponseCode;
	std::string strResponseMsg;
};

inline struct Response generateResponse(int iCode, std::string strResponse)
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

#endif