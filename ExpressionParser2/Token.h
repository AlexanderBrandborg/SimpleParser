#pragma once
enum TokenType
{
	PMOPERATOR,
	MDOPERATOR,
	NUMBER,
	LPAREN,
	RPAREN,
	END
};

//TODO: Make a toke hierachy, where each class contains token type and additional data.
struct Token
{
	TokenType m_type;
	int m_numValue;
	std::string m_stringValue;
};