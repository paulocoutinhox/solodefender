#pragma once

#include <sstream>

class StringConverter
{
	public:
		StringConverter(void);
		~StringConverter(void);

		static int toInt(const std::string& str);
		static std::string toString(int value);
};
