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

struct Token
{
	TokenType m_type;
	int m_numValue;
	std::string m_stringValue;
};