#include "node.h"
#include "Visitor.h"

// Base
Node::Node()
{
}

Node::~Node()
{
	m_children.clear();
}

Node::Node(const Node & other)
{
	m_children = other.m_children;
}

void Node::addChild(Node* n)
{
	m_children.push_back(n);
}




// Expression
ExpressionNode::ExpressionNode()
{
}

ExpressionNode::ExpressionNode(const ExpressionNode & other) : Node(other)
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

TermNode::TermNode(const TermNode & other) : Node(other)
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

FactorNode::FactorNode(const FactorNode & other) : Node(other)
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

SignNode::SignNode(const SignNode & other) : Node(other), m_sign(other.GetSign()) 
{
}

SignNode::~SignNode()
{
}

const char SignNode::GetSign() const
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

OperatorNode::OperatorNode(const OperatorNode & other) : Node(other), m_operator(GetOperator())
{
}

OperatorNode::~OperatorNode()
{
}

const char OperatorNode::GetOperator() const
{
	return m_operator;
}

void OperatorNode::accept(Visitor& v)
{
	v.visit(this);
}

// Number
NumberNode::NumberNode(const NumberNode & other) : Node(other), m_value(other.GetValue())
{
}


NumberNode::NumberNode(int value) : m_value{ value }
{
}

NumberNode::~NumberNode()
{
}

const int NumberNode::GetValue() const
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

LParenNode::LParenNode(const LParenNode & other) : Node(other)
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

RParenNode::RParenNode(const RParenNode & other) : Node(other)
{
}

RParenNode::~RParenNode()
{
}

void RParenNode::accept(Visitor& v)
{
	v.visit(this);
}
