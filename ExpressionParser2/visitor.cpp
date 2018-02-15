#include "Visitor.h"
#include "node.h"

PrintVisitor::PrintVisitor()
{
}

PrintVisitor::~PrintVisitor()
{
}

void PrintVisitor::visit(ExpressionNode* n)
{
	for (int i = 0; i < n->m_children.size(); ++i) {
	  n->m_children[i]->accept(*this);
	}
	
}

void PrintVisitor::visit(TermNode* n)
{
	for (int i = 0; i < n->m_children.size(); ++i) {
		n->m_children[i]->accept(*this);
	}
}

void PrintVisitor::visit(FactorNode* n)
{
	for (int i = 0; i < n->m_children.size(); ++i) {
		n->m_children[i]->accept(*this);
	}
}

void PrintVisitor::visit(SignNode* n)
{
	std::cout << n->GetSign();
}

void PrintVisitor::visit(OperatorNode* n)
{
	std::cout << n->GetOperator();
}

void PrintVisitor::visit(NumberNode* n)
{
	std::cout << n->GetValue();
}

void PrintVisitor::visit(LParenNode* n)
{
	std::cout << "(";
}

void PrintVisitor::visit(RParenNode* n)
{
	std::cout << ")";
}
