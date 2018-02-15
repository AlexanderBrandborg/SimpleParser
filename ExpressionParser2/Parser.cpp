#include "Parser.h"
#include <iostream>

Parser::Parser(std::string stream): m_lexer{Lexer(stream)}
{
	m_lastToken = m_lexer.nextToken();
	m_root = expression();
}

Parser::~Parser()
{
}

bool Parser::accept(TokenType t)
{
	if (t == m_lastToken.type) {
		m_treeToken = m_lastToken;
		m_lastToken = m_lexer.nextToken();
		return true;
	}
	return false;
}

bool Parser::expect(TokenType t)
{
	if (accept(t)) {
		return true;
	}
	throw std::runtime_error("Unexpected token");
	return false;
}


Node Parser::expression()
{
	auto n = ExpressionNode();
	if (accept(TokenType::PMOPERATOR)) {
		n.addChild(SignNode(m_treeToken.stringValue[0]));
	}
	n.addChild(term());
	while (accept(TokenType::PMOPERATOR)) {
		n.addChild(OperatorNode(m_treeToken.stringValue[0]));
		std::cout << "AddSub";
		n.addChild(term());
	}
	return n;
}

Node Parser::term()
{
	auto n = TermNode();
	n.addChild(factor());
	while (accept(TokenType::MDOPERATOR))
	{
		n.addChild(OperatorNode(m_treeToken.stringValue[0]));
		std::cout << "MultDiv ";
		n.addChild(factor());
	}
	return n;
}

Node Parser::factor()
{
	auto n = FactorNode();
	if (accept(TokenType::NUMBER)) {
		n.addChild(NumberNode(m_treeToken.numValue));
	}
	else
	{
		expect(TokenType::LPAREN);
		n.addChild(LparenNode());
		std::cout << "LParen ";
		n.addChild(expression());
		expect(TokenType::RPAREN);
		n.addChild(RparenNode());
		std::cout << "RParen ";
	}
	return n;
}
