#pragma once
#include <vector>
class Visitor;


class Node
{
protected:
	Node();

public:
	
	virtual ~Node();
	void addChild(Node* n);
	virtual void accept(Visitor& v)=0;
	const std::vector<Node*>& getChildren() { return m_children; }
private:
	std::vector<Node*> m_children;
	
};

class ExpressionNode : public Node {
public:
	ExpressionNode();
	~ExpressionNode();
	virtual void accept(Visitor& v) override;

};

class TermNode : public Node {
public:
	TermNode();
	~TermNode();
	virtual void accept(Visitor& v) override;
};

class FactorNode : public Node {
public:
	FactorNode();
	~FactorNode();
	virtual void accept(Visitor& v) override;
};

class SignNode : public Node {
public:
	SignNode(char sign);
	~SignNode();
	char GetSign();
	virtual void accept(Visitor& v) override;
private:
	char m_sign;
};

class OperatorNode : public Node {
public:
	OperatorNode(char op);
	~OperatorNode();
	char GetOperator();
	virtual void accept(Visitor& v) override;
private:
	char m_operator;
};

class NumberNode : public Node {
public:
	NumberNode(int value);
	~NumberNode();
	int GetValue();
	virtual void accept(Visitor& v) override;
private:
	int m_value;
};

class LParenNode : public Node {
public:
	LParenNode();
	~LParenNode();
	virtual void accept(Visitor& v) override;
private:
};

class RParenNode : public Node {
public:
	RParenNode();
	~RParenNode();
	virtual void accept(Visitor& v) override;
private:
};
