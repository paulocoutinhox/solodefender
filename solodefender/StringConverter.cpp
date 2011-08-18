#include "StringConverter.h"

StringConverter::StringConverter(void)
{
}

StringConverter::~StringConverter(void)
{
}

int StringConverter::toInt( const std::string& str )
{
	std::istringstream stream(str);
	int value;
	stream >> value;
	return value; 
}

std::string StringConverter::toString( int value )
{
	std::ostringstream stream;
	stream << value;
	return stream.str(); 
}
