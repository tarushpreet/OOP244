/* Tarushpreet Singh
#136579166
ts3@myseneca.ca */

#ifndef AMA_ERROR_STATE_H
#define AMA_ERROR_STATE_H
#include<iostream>
namespace AMA
{
	class ErrorState
	{
		char *_message;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;

	};

	std::ostream& operator<<(std::ostream& ostr, const ErrorState& em);
}
#endif
