#pragma once
#include "Lexer.h"
#include <vector>

class Node
{
public:
	Node() {};
	~Node() {};
	void addChild(Node n) {
		m_children.push_back(n);
	};
	std::vector<Node> m_children = {};

private:
	
};

class ExpressionNode : public Node {
public:
	ExpressionNode() {};
	~ExpressionNode() {};
};

class TermNode : public Node {
public:
	TermNode() {};
	~TermNode() {};
};

class FactorNode : public Node {
public:
	FactorNode() {};
	~FactorNode() {};
};

class SignNode : public Node {
public:
	SignNode(char sign) : m_sign{ sign } {};
	~SignNode() {};
private:
	char m_sign;
};

class OperatorNode : public Node {
public:
	OperatorNode(char op) : m_operator{op} {};
	~OperatorNode() {};
private:
	char m_operator;
};

class NumberNode : public Node {
public:
	NumberNode(int value) : m_value{ value } {};
	~NumberNode() {};
private:
	int m_value;
};

class LparenNode : public Node {
public:
	LparenNode() {};
	~LparenNode() {};
private:
};

class RparenNode : public Node {
public:
	RparenNode() {};
	~RparenNode() {};
private:
};





