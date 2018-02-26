#include "node.h"
#include "Visitor.h"

// Base
Node::Node()
{
}

Node::~Node()
{
	// Do not use vector.clear here, as it just calls destructors on pointers.
	for (auto& child : m_children) {
		delete child;
	}
}

Node::Node(const Node & other)
{
	// Do not copy vector here, only copies pointers.
	// Used clone to call the constructor of the derived classes.
	for (auto& child : other. m_children) {
		m_children.push_back(child->clone());
	}
}

void Node::addChild(Node* n)
{
	m_children.push_back(n);
}

const std::vector<Node*>& Node::getChildren()
{
	return m_children; 
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

ExpressionNode * ExpressionNode::clone() const
{
	return new ExpressionNode(*this);
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

TermNode * TermNode::clone() const
{
	return new TermNode(*this);
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

FactorNode * FactorNode::clone() const
{
	return new FactorNode(*this);
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

SignNode * SignNode::clone() const
{
	return new SignNode(*this);
}

// Operator
OperatorNode::OperatorNode(char op) : m_operator{ op }
{
}

OperatorNode::OperatorNode(const OperatorNode & other) : Node(other), m_operator(other.GetOperator())
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

OperatorNode * OperatorNode::clone() const
{
	return new OperatorNode(*this);
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

NumberNode * NumberNode::clone() const
{
	return new NumberNode(*this);
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

LParenNode * LParenNode::clone() const
{
	return new LParenNode(*this);
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

RParenNode * RParenNode::clone() const
{
	return new RParenNode(*this);
}
