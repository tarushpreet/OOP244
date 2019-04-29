// Final Project Milestone 2
// Version 1.0
// Date 
// Author       
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//////////////////////////////////////////////////////////////
// Tarushpreet Singh
// 136579166
// ts3@mysenecacollege.com
//////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "ErrorState.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict {
	ErrorState::ErrorState()
	{
		message_ = nullptr;
	}

	ErrorState::ErrorState(const char* ErrorState)
	{
		message_ = nullptr;
		message(ErrorState);
	}
	//ErrorState::ErrorState(const ErrorState& em) = delete;

	//ErrorState& ErrorState::operator=(const ErrorState& em) = delete;

	ErrorState& ErrorState::operator=(const char* ErrorState)
	{
		clear();
		message(ErrorState);
		return *this;
	}

	ErrorState:: ~ErrorState()
	{
		delete[] message_;
	}

	void ErrorState::clear()
	{
		delete message_;
		message_ = nullptr;
	}

	bool ErrorState::isClear()const
	{
		if (message_ == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	void ErrorState::message(const char* value)
	{
		delete[] message_;
		int len = strlen(value);
		message_ = new char[len + 1];
		strncpy(message_, value, len);
	}

	const char* ErrorState::message() const
	{
		return message_;
	}

	std::ostream& operator << (std::ostream& ostr, ErrorState& msg)
	{
		if (msg.ErrorState::isClear())
		{
			return ostr;
		}
		else
		{
			int len = strlen(msg.message());
			const char* message = msg.message();
			for (int a = 0; a < len; a++)
			{
				ostr << message[a];
			}
			return ostr;
		}
	}

}
