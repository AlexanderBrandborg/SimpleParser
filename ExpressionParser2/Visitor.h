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
protected:
	Visitor() = default;
public:
	virtual ~Visitor() = default;
	virtual void visit(ExpressionNode* n) = 0;
	virtual void visit(TermNode* n) = 0;
	virtual void visit(FactorNode* n) = 0;
	virtual void visit(SignNode* n) = 0;
	virtual void visit(OperatorNode* n) = 0;
	virtual void visit(NumberNode* n) = 0;
	virtual void visit(LParenNode* n) = 0;
	virtual void visit(RParenNode* n) = 0;

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
