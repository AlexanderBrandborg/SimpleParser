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
	//TODO: Implement to follow rule of three
	//Node& operator =(const Node& other);
	void addChild(Node* n);
	virtual void accept(Visitor& v)=0;
	virtual Node* clone() const = 0;
	const std::vector<Node*>& getChildren();
private:
	std::vector<Node*> m_children;
	
};

class ExpressionNode : public Node {
public:
	ExpressionNode();
	ExpressionNode(const ExpressionNode& other);
	virtual ~ExpressionNode();
	virtual void accept(Visitor& v) override;
	virtual ExpressionNode* clone() const;
};

class TermNode : public Node {
public:
	TermNode();
	TermNode(const TermNode& other);
	virtual ~TermNode();
	virtual void accept(Visitor& v) override;
	virtual TermNode* clone() const;
};

class FactorNode : public Node {
public:
	FactorNode();
	FactorNode(const FactorNode& other);
	virtual ~FactorNode();
	virtual void accept(Visitor& v) override;
	virtual FactorNode* clone() const;
};

class SignNode : public Node {
public:
	SignNode(char sign);
	SignNode(const SignNode& other);
	virtual ~SignNode();
	const char GetSign() const;
	virtual void accept(Visitor& v) override;
	virtual SignNode* clone() const;
private:
	char m_sign;
};

class OperatorNode : public Node {
public:
	OperatorNode(char op);
	OperatorNode(const OperatorNode& other);
	virtual ~OperatorNode();
	const char GetOperator() const;
	virtual void accept(Visitor& v) override;
	virtual OperatorNode* clone() const;
private:
	char m_operator;
};

class NumberNode : public Node {
public:
	NumberNode(const NumberNode& other);
	NumberNode(int value);
	virtual ~NumberNode();
	const int GetValue() const;
	virtual void accept(Visitor& v) override;
	virtual NumberNode* clone() const;
private:
	int m_value;
};

class LParenNode : public Node {
public:
	LParenNode();
	LParenNode(const LParenNode& other);
	virtual ~LParenNode();
	virtual void accept(Visitor& v) override;
	virtual LParenNode* clone() const;
private:
};

class RParenNode : public Node {
public:
	RParenNode();
	RParenNode(const RParenNode& other);
	virtual ~RParenNode();
	virtual void accept(Visitor& v) override;
	virtual RParenNode* clone() const;
private:
};
