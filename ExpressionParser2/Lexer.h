#pragma once
#include <string>
#include "Token.h"

class Lexer
{
public:
	Lexer(std::string& stream);
	~Lexer();
	Token nextToken();
private:
	int m_StreamIndex = 0;
	std::string m_stream;
	char popCharFromStream();
};
