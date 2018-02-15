#include "Lexer.h"

Lexer::Lexer(std::string stream) : m_stream{stream}
{
}

Lexer::~Lexer()
{
}

Token Lexer::nextToken()
{
	Token tok = {};
	char lastChar;
	// Ignore whitespace
	do
	{
		lastChar = getStreamChar();
	} while (isspace(lastChar));

	// Terminator. Parser should not get here, I think.
	if (lastChar == '\0') {
		tok.type = TokenType::END;
	}

	// Numbers
	else if (isdigit(lastChar))
	{
		std::string numStr = "";
		numStr += lastChar;

		while (m_Position < m_stream.length() && isdigit(m_stream[m_Position])) // Hack???
		{
			lastChar = getStreamChar();
			numStr += lastChar;
		}

		tok.type = TokenType::NUMBER;
		tok.numValue = std::stoi(numStr);
	}

	// Operators
	else if (strchr("+-", lastChar)) {
		tok.type = TokenType::PMOPERATOR;
		tok.stringValue = lastChar;
	}

	else if (strchr("*/", lastChar)) {
		tok.type = TokenType::MDOPERATOR;
		tok.stringValue = lastChar;
	}

	// Left paran
	else if (lastChar == '(') {
		tok.type = TokenType::LPAREN;
		tok.stringValue = lastChar;
	}

	// Right paran
	else if (lastChar == ')') {
		tok.type = TokenType::RPAREN;
		tok.stringValue = lastChar;
	}

	

	// Token not recognized
	else
	{
		throw std::runtime_error("Unrecognized token");
	}

	return tok;
}

char Lexer::getStreamChar()
{
	auto str = m_stream[m_Position];
	++m_Position;
	return str;
}
