#pragma once
#include <vector>
class Visitor;


class Node
{
protected:
	Node();

public:
	
	virtual ~Node();
	Node(const Node& other);
	void addChild(Node* n);
	virtual void accept(Visitor& v)=0;
	const std::vector<Node*>& getChildren() { return m_children; }
private:
	std::vector<Node*> m_children;
	
};

class ExpressionNode : public Node {
public:
	ExpressionNode();
	ExpressionNode(const ExpressionNode& other);
	~ExpressionNode();
	virtual void accept(Visitor& v) override;

};

class TermNode : public Node {
public:
	TermNode();
	TermNode(const TermNode& other);
	~TermNode();
	virtual void accept(Visitor& v) override;
};

class FactorNode : public Node {
public:
	FactorNode();
	FactorNode(const FactorNode& other);
	~FactorNode();
	virtual void accept(Visitor& v) override;
};

class SignNode : public Node {
public:
	SignNode(char sign);
	SignNode(const SignNode& other);
	~SignNode();
	const char GetSign() const;
	virtual void accept(Visitor& v) override;
private:
	char m_sign;
};

class OperatorNode : public Node {
public:
	OperatorNode(char op);
	OperatorNode(const OperatorNode& other);
	~OperatorNode();
	const char GetOperator() const;
	virtual void accept(Visitor& v) override;
private:
	char m_operator;
};

class NumberNode : public Node {
public:
	NumberNode(const NumberNode& other);
	NumberNode(int value);
	~NumberNode();
	const int GetValue() const;
	virtual void accept(Visitor& v) override;
private:
	int m_value;
};

class LParenNode : public Node {
public:
	LParenNode();
	LParenNode(const LParenNode& other);
	~LParenNode();
	virtual void accept(Visitor& v) override;
private:
};

class RParenNode : public Node {
public:
	RParenNode();
	RParenNode(const RParenNode& other);
	~RParenNode();
	virtual void accept(Visitor& v) override;
private:
};
