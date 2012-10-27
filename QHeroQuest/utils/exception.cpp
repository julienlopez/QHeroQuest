#include "exception.hpp"

Utils::Exception::Exception(const std::string& message) : m_message(message)
{}

Utils::Exception::Exception(const QString& message) : m_message(message.toStdString())
{}

Utils::Exception::~Exception() throw()
{}

const std::string& Utils::Exception::message() const throw()
{
	return m_message;
}

const char* Utils::Exception::what() const throw()
{
	return m_message.c_str();
}
