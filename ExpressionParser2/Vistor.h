#pragma once
#include "node.h"
#include <iostream>

class Visitor
{
public:
	Visitor() {};
	~Visitor() {};
	virtual void visit(ExpressionNode n) {};
	virtual void visit(TermNode n) {};
	virtual void visit(FactorNode n) {};
	virtual void visit(SignNode n) {};
	virtual void visit(OperatorNode n) {};
	virtual void visit(NumberNode n) {};
	virtual void visit(LparenNode n) {};
	virtual void visit(RparenNode n) {};
private:

};

class PrintVisitor : public Visitor
{
public:
	virtual void visit(ExpressionNode n) override;
	virtual void visit(TermNode n) override;
	virtual void visit(FactorNode n) override;
	virtual void visit(SignNode n) override;
	virtual void visit(OperatorNode n) override;
	virtual void visit(NumberNode n) override;
	virtual void visit(LparenNode n) override;
	virtual void visit(RparenNode n) override;

private:

};

