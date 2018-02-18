#include "Parser.h"
#include "Visitor.h"

int main(){

	auto root = Parser("+4*(2-((2+2)/4))");
	auto pv = PrintVisitor();
	root.m_root->accept(pv);

	/*
	Using the same variable name will result in the deconstructor being called after construction...
	root = Parser("2 + 2");
	root.m_root->accept(pv);

	root = Parser("+2 - ((2 + 2) / 4)");
	root.m_root->accept(pv);
	*/

	return 0;
}