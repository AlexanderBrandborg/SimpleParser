#include "Lexer.h"

Lexer::Lexer(std::string& stream) : m_stream{stream}
{
}

Lexer::~Lexer()
{
}

Token Lexer::nextToken()
{
	auto tok = Token{};
	char lastChar;
	
	// Ignore whitespace
	do
	{
		lastChar = popCharFromStream();
	} while (isspace(lastChar));

	// Terminator, must be here as \0 also figures in strchr during later matches
	if (lastChar == '\0') {
		tok.m_type = TokenType::END;
	}

	// Numbers
	else if (isdigit(lastChar))
	{
		std::string numStr = "";
		numStr += lastChar;

		// Looks ahead to see if the next char is also a number
		while (m_StreamIndex < m_stream.length() && isdigit(m_stream[m_StreamIndex]))
		{
			lastChar = popCharFromStream();
			numStr += lastChar;
		}
		tok.m_type = TokenType::NUMBER;
		tok.m_numValue = std::stoi(numStr);
	}

	// Operators
	else if (strchr("+-", lastChar)) {
		tok.m_type = TokenType::PMOPERATOR;
		tok.m_stringValue = lastChar;
	}

	else if (strchr("*/", lastChar)) {
		tok.m_type = TokenType::MDOPERATOR;
		tok.m_stringValue = lastChar;
	}

	// Left paranthesis
	else if (lastChar == '(') {
		tok.m_type = TokenType::LPAREN;
		tok.m_stringValue = lastChar;
	}

	// Right paranthesis
	else if (lastChar == ')') {
		tok.m_type = TokenType::RPAREN;
		tok.m_stringValue = lastChar;
	}

	// Token not recognized
	else
	{
		throw new std::runtime_error("Unrecognized token");
	}

	return tok;
}

char Lexer::popCharFromStream()
{
	auto str = m_stream[m_StreamIndex];
	++m_StreamIndex;
	return str;
}
