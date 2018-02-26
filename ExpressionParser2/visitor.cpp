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
	for (int i = 0; i < n->getChildren().size(); ++i) {
		n->getChildren()[i]->accept(*this);
	}
}

void PrintVisitor::visit(TermNode* n)
{
	auto children = n->getChildren();
	for (int i = 0; i < children.size(); ++i) {
		children[i]->accept(*this);
	}
}

void PrintVisitor::visit(FactorNode* n)
{
	auto children = n->getChildren();
	for (int i = 0; i < children.size(); ++i) {
		children[i]->accept(*this);
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
