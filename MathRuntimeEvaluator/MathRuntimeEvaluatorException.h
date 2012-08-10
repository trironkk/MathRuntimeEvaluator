#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

class __declspec(dllexport) MathRuntimeEvaluatorException : public std::exception
{
public:
	std::string Description;
	int ErrorCode;
	MathRuntimeEvaluatorException(std::string description, int errorCode=1) throw();
	const char* what() const throw();

	friend std::ostream& operator<<(std::ostream& os,
		const MathRuntimeEvaluatorException e);
};

#endif