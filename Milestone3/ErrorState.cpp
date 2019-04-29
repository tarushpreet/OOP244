/* Tarushpreet Singh
#136579166
ts3@myseneca.ca */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA
{
	ErrorState::ErrorState(const char* errorMessage)
	{
		if (errorMessage == nullptr)
		{
			_message = nullptr;
		}
		else
		{
			long long length = strlen(errorMessage);
			_message = new char[length + 1];
			strcpy(_message, errorMessage);

		}
	}
	ErrorState::~ErrorState()
	{
		delete[] _message;
	}
	void ErrorState::clear()
	{
		delete _message;
		_message = nullptr;
	}
 bool ErrorState::isClear() const
	{
		if (_message == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ErrorState::message(const char* str)
	{
		delete[] _message;
		long long length = strlen(str);
		_message = new char[length + 1];
		strcpy(_message, str);
	}
	const char* ErrorState::message()const
	{
		return _message;
	}
	std::ostream& operator<<(std::ostream& ostr, const ErrorState & em) {
		if (em.isClear())
		{
			return ostr;
		}
		else
		{
			ostr << em.message();
			return ostr;
		}
	}
}
