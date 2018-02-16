#pragma once
#include <string>
#include <regex>
#include "Token.h"




class Lexer
{
public:
	Lexer(std::string& stream);
	~Lexer();
	Token nextToken();
private:
	int m_Position = 0;
	std::string m_stream;
	char getStreamChar();
};
