#pragma once
#include <iostream>
class ExpressionNode;
class TermNode;
class FactorNode;
class SignNode;
class OperatorNode;
class NumberNode;
class LParenNode;
class RParenNode;


class Visitor
{
public:
	Visitor() {};
	~Visitor() {};
	virtual void visit(ExpressionNode* n) {};
	virtual void visit(TermNode* n) {};
	virtual void visit(FactorNode* n) {};
	virtual void visit(SignNode* n) {};
	virtual void visit(OperatorNode* n) {};
	virtual void visit(NumberNode* n) {};
	virtual void visit(LParenNode* n) {};
	virtual void visit(RParenNode* n) {};

private:

};


class PrintVisitor : public Visitor
{
public:
	PrintVisitor();
	~PrintVisitor();
	virtual void visit(ExpressionNode* n) override;
	virtual void visit(TermNode* n) override;
	virtual void visit(FactorNode* n) override;
	virtual void visit(SignNode* n) override;
	virtual void visit(OperatorNode* n) override;
	virtual void visit(NumberNode* n) override;
	virtual void visit(LParenNode* n) override;
	virtual void visit(RParenNode* n) override;

private:

};
