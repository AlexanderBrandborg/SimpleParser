#include "Parser.h"
#include "Visitor.h"

int main(){
	auto root =  Parser("+4*(2-((2+2)/4))");
	auto pv = PrintVisitor();
	root.m_root->accept(pv);

	auto doot = ExpressionNode(*static_cast<ExpressionNode*>(root.m_root));

	root =  Parser("2 + 2");
	root.m_root->accept(pv);

	/*
	Parser root3("+2 - ((2 + 2) / 4)");
	root3.m_root->accept(pv);
	*/
	return 0;
}