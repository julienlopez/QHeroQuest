#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <QString>

namespace Utils {

class Exception : public std::exception
{
public:
	Exception(const std::string& message = std::string());

        Exception(const QString& message = QString());

	virtual ~Exception() throw();

	const std::string& message() const throw();

	const char* what() const throw();

private:
	std::string m_message;
};

}

#endif
