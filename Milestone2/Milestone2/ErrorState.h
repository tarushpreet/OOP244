#pragma once
// Final Project Milestone 2
// Version 1.0
// Date 
// Author       
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//////////////////////////////////////////////////////////////
// Tarushpreet Singh
// 136579166
// ts3@mysenecacollege.com
//////////////////////////////////////////////////////////////
#ifndef SICT_ErrorState_H__ 
#define SICT_ErrorState_H__
#include <iostream>
using namespace std;
namespace sict {
	class ErrorState {
		char* message_;
	public:
		ErrorState();
		ErrorState(const char* ErrorState);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		ErrorState& operator=(const char* ErrorState);
		virtual ~ErrorState();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char * message() const;

	};
	std::ostream& operator << (std::ostream& ostr, ErrorState& msg);
}
#endif
