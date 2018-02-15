#pragma once
#include "Lexer.h"
#include "node.h"

class Parser
{
public:
	Parser(std::string stream);
	~Parser();
private:
	Token m_lastToken;
	Token m_treeToken;
	Lexer m_lexer;
	Node m_root;

	bool accept(TokenType t);
	bool expect(TokenType t);
	Node expression();
	Node term();
	Node factor();
};
