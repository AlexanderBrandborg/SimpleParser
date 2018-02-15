#include "node.h"


Node::Node()
{
}

Node::~Node()
{
}

void Node::addChild(Node n)
{
	m_children.push_back(n);
}

