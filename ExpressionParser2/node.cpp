#include "node.h"
#include "Visitor.h"

// Base
Node::Node()
{
}

Node::~Node()
{
}

void Node::addChild(Node* n)
{
	m_children.push_back(n);
}




// Expression
ExpressionNode::ExpressionNode()
{
}

ExpressionNode::~ExpressionNode()
{
}

void ExpressionNode::accept(Visitor& v)
{
	v.visit(this);
}


// Term
TermNode::TermNode()
{
}

TermNode::~TermNode()
{
}

void TermNode::accept(Visitor& v)
{
	v.visit(this);
}


// Factor
FactorNode::FactorNode()
{
}

FactorNode::~FactorNode()
{
}

void FactorNode::accept(Visitor& v)
{
	v.visit(this);
}


// Sign
SignNode::SignNode(char sign) : m_sign{ sign }
{
}

SignNode::~SignNode()
{
}

char SignNode::GetSign()
{
	return m_sign;
}

void SignNode::accept(Visitor& v)
{
	v.visit(this);
}

// Operator
OperatorNode::OperatorNode(char op) : m_operator{ op }
{
}

OperatorNode::~OperatorNode()
{
}

char OperatorNode::GetOperator()
{
	return m_operator;
}

void OperatorNode::accept(Visitor& v)
{
	v.visit(this);
}


// Number
NumberNode::NumberNode(int value) : m_value{ value }
{
}

NumberNode::~NumberNode()
{
}

int NumberNode::GetValue()
{
	return m_value;
}

void NumberNode::accept(Visitor& v)
{
	v.visit(this);
}

// Left parenthesis
LParenNode::LParenNode()
{
}

LParenNode::~LParenNode()
{
}

void LParenNode::accept(Visitor& v)
{
	v.visit(this);
}

// Right parenthesis
RParenNode::RParenNode()
{
}

RParenNode::~RParenNode()
{
}

void RParenNode::accept(Visitor& v)
{
	v.visit(this);
}
