#include"standards.h"

int main(){

	auto root = Parser("+4*(2-((2+2)/4))");
	auto pv = PrintVisitor();
	root.m_root->accept(pv);
	
	//root = Parser("+2 + 2");
	//Parser("2 + 2");
	//Parser("+2 - ((2 + 2) / 4)");

	return 0;
}