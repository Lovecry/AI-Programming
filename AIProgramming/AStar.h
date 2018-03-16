#pragma once

#include <iostream>
#include <list>
#include "Node.h"
#include <vector>

namespace ASnamespace
{
	class AStar
	{
	public:
		void Run(std::vector<Node> &result);
		void Setup();

	private:
		void CreateGraph();
		void CreateGraphAdjs(Node* currentNode);
		void CreateNodeAdj(Node* currentNode, int* adjNodeConfiguration);
		int* CreateNewConfiguration(int[], int*, int);

		void ComputeGraphHeuristics();
		void ComputeNodeHeuristic(Node* pNode);

		void Clean();

		void Search(std::vector<Node> &result);
		Node* VisitNode();
		void AddNodeToOpenList(Node* pParent, Node* pNode);

		void PrintPath(Node* pNode) const;

		Node* iStartNode;
		Node* iEndNode;

		int startConfig[16];
		int endConfig[16];
		int adjNodeConfiguration[16];

		std::list<Node*> tRoot; //Lista di tutti i nodi (contenenti configurazioni)
		std::list<Node*> qOpenList;
	};
}