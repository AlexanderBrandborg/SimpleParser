#pragma once
#include"node.h"
#include"Lexer.h"
#include <memory>

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
	

	std::unique_ptr<Token> accept(TokenType t);
	std::unique_ptr<Token> expect(TokenType t);
	Node* expression();
	Node* term();
	Node* factor();
};
