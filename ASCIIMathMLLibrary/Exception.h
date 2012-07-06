#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

#include "Constants.h"

namespace ASCIIMathMLLibrary
{
	class ASCIIMathMLException : public std::exception
	{
	public:
		String Description;
		ASCIIMathMLException(String description) throw();
		const char* what() const throw();

		friend std::ostream& operator<<(std::ostream& os,
			const ASCIIMathMLException e);
	};
}

#endif