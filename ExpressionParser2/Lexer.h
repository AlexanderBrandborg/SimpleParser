#pragma once
#include <string>
#include <regex>


enum TokenType
{
	PMOPERATOR,
	MDOPERATOR,
	NUMBER,
	LPAREN,
	RPAREN,
	END
};

struct Token
{
	TokenType type;
	int numValue;
	std::string stringValue;
};


class Lexer
{
public:
	Lexer(std::string stream);
	~Lexer();
	Token nextToken();
private:
	int m_Position = 0;
	std::string m_stream;
	char getStreamChar();
};
