#include "Parser.h"
#include "Visitor.h"
#include <iostream>

int main(){
	auto root =  Parser("+4*(2-((2+2)/4))");
	auto pv = PrintVisitor();
	root.m_root->accept(pv);
	std::cout << "\n";

	auto doot = ExpressionNode(*static_cast<ExpressionNode*>(root.m_root));
	
	root =  Parser("2 + 2");
	root.m_root->accept(pv);
	std::cout << "\n";

	system("PAUSE");

	return 0;
}