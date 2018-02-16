#pragma once
#include"node.h"
#include"Lexer.h"

class Parser
{
public:
	Parser(std::string stream);
	~Parser();
	Node* m_root;
private:
	Token m_lastToken;
	Token m_treeToken;
	Lexer m_lexer;
	

	bool accept(TokenType t);
	bool expect(TokenType t);
	Node* expression();
	Node* term();
	Node* factor();
};
