#include "Parser.h"
#include <iostream>


Parser::Parser(std::string stream): m_lexer{Lexer(stream)}
{
	m_lastToken = m_lexer.nextToken();
	m_root = expression();
}

Parser::~Parser()
{
	delete this->m_root;
}

Parser & Parser::operator=(const Parser & other)
{
	this->m_root = new ExpressionNode(*static_cast<ExpressionNode*>(other.m_root));
	return *this;
}


std::unique_ptr<Token> Parser::accept(TokenType t)
{
	if (t == m_lastToken.m_type) {
		auto tmp = std::make_unique<Token>(m_lastToken);
		m_lastToken = m_lexer.nextToken();
		return tmp;
	}
	return nullptr;
}

std::unique_ptr<Token> Parser::expect(TokenType t)
{
	auto token = accept(t);
	if (token) {
		return token;
	}
	else {
		throw new std::runtime_error("Unexpected token");
	}
}

Node* Parser::expression()
{
	auto n = new ExpressionNode();
	std::unique_ptr<Token> token;
	if (token = accept(TokenType::PMOPERATOR)) {
		auto tmp = token->m_stringValue[0];
		n->addChild(new SignNode(tmp));
	}
	n->addChild(term());
	while (token = accept(TokenType::PMOPERATOR)) {
		n->addChild(new OperatorNode(token->m_stringValue[0]));
		n->addChild(term());
	}
	return n;
}

Node* Parser::term()
{
	auto n = new TermNode();
	std::unique_ptr<Token> token;

	n->addChild(factor());
	while (token = accept(TokenType::MDOPERATOR))
	{
		n->addChild(new OperatorNode(token->m_stringValue[0]));
		n->addChild(factor());
	}
	return n;
}

Node* Parser::factor()
{
	auto n = new FactorNode();
	std::unique_ptr<Token> token;
	if (token = accept(TokenType::NUMBER)) {
		n->addChild(new NumberNode(token->m_numValue));
	}
	else
	{
		expect(TokenType::LPAREN);
		n->addChild(new LParenNode());
		n->addChild(expression());
		expect(TokenType::RPAREN);
		n->addChild(new RParenNode());
	}
	return n;
}
