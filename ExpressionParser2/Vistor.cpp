#include "Vistor.h"

void PrintVisitor::visit(ExpressionNode n)
{
	for (int i; i < n.m_children.size(); ++i) {
		n.m_children[i].accept(this);
	}
}

void PrintVisitor::visit(TermNode n)
{
	for (int i; i < n.m_children.size(); ++i) {
		n.m_children[i].accept(this);
	}
}

void PrintVisitor::visit(FactorNode n)
{
	for (int i; i < n.m_children.size(); ++i) {
		n.m_children[i].accept(this);
	}
}

void PrintVisitor::visit(SignNode n)
{
	std::cout << n.
}

void PrintVisitor::visit(OperatorNode n)
{
}

void PrintVisitor::visit(NumberNode n)
{
}

void PrintVisitor::visit(LparenNode n)
{
}

void PrintVisitor::visit(RparenNode n)
{
}
