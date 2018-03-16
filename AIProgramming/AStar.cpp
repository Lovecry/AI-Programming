#include <cmath>
#include <list>

#include "AStar.h"

namespace ASnamespace
{
	void AStar::Setup()
	{
		int startConfig[16] = { 2, 5, 3, 4, 1, 10, 6, 8, 9, 14, 7, 11, 13, 16, 15, 12 };
		//int startConfig[16] = { 5,14,13,6,3,11,15,2,1,10,8,4,12,7,9,16 };

		int endConfig[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
		int adjNodeConfiguration[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		iStartNode = new Node;
		iEndNode = new Node;

		iStartNode->pParent = NULL;
		iStartNode->setConfiguration(startConfig);
		iStartNode->iG = 0;
		ComputeNodeHeuristic(iStartNode);
		iStartNode->iF = iStartNode->iG + iStartNode->iH;

		iEndNode->setConfiguration(endConfig);
	}

	void AStar::Run(std::vector<Node> &result)
	{
		CreateGraph();

		Search(result);

		//Clean();
	}

	//aggiungo soltanto il nodo root
	void AStar::CreateGraph()
	{
		std::cout << "Creating Root Node...\n";

		tRoot.push_front(iStartNode);

		std::cout << "Creating Nodes...DONE\n\n";

	}

	void AStar::CreateGraphAdjs(Node* currentNode)
	{
		int* currentNodeConfiguration = currentNode->getConfiguration();
		std::cout << "\nCreating Node Adj : " << currentNode << "\n";
		std::cout << "Adjs: \n\n";
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
			{
				if (currentNodeConfiguration[(4 * y) + x] == 16)
				{
					if (x != 0) {
						CreateNewConfiguration(adjNodeConfiguration, currentNodeConfiguration, -1);
						CreateNodeAdj(currentNode, adjNodeConfiguration);
					}
					if (x != 3) {
						CreateNewConfiguration(adjNodeConfiguration, currentNodeConfiguration, +1);
						CreateNodeAdj(currentNode, adjNodeConfiguration);
					}
					if (y != 0) {
						CreateNewConfiguration(adjNodeConfiguration, currentNodeConfiguration, -4);
						CreateNodeAdj(currentNode, adjNodeConfiguration);
					}
					if (y != 3) {
						CreateNewConfiguration(adjNodeConfiguration, currentNodeConfiguration, +4);
						CreateNodeAdj(currentNode, adjNodeConfiguration);
					}
					std::cout << "\nCreating Node Adj...DONE  \n\n";
				}
			}
		}
	}

	int* AStar::CreateNewConfiguration(int* adjNodeConfiguration, int* currentNodeConfiguration, int swapIndex)
	{
		int temp;
		for (int i = 0; i < 16; i++) {
			adjNodeConfiguration[i] = currentNodeConfiguration[i];
			if (currentNodeConfiguration[i] == 16) {
				temp = i;
				adjNodeConfiguration[i] = currentNodeConfiguration[i + swapIndex];
			}
		}
		adjNodeConfiguration[temp + swapIndex] = 16;
		return adjNodeConfiguration;
	}

	void AStar::CreateNodeAdj(Node* currentNode, int* adjNodeConfiguration)
	{
		Node* adjNode = new Node();

		adjNode->setConfiguration(adjNodeConfiguration);
		ComputeNodeHeuristic(adjNode);

		if (currentNode->pParent != NULL){
			if (*(currentNode->pParent) == *adjNode){
				std::cout << "CONFIGURAZIONE GIA ESISTENTE\n";
				return;
			}
			else{
				currentNode->lAdj.push_back(adjNode);
				std::cout << adjNode << std::endl;
			}
		}
		else {
			currentNode->lAdj.push_back(adjNode);
			std::cout << adjNode << std::endl;
		}
	}

	void AStar::ComputeNodeHeuristic(Node* currentNode)
	{
		int* currentNodeConfiguration = currentNode->getConfiguration();
		int val;
		for (int i = 0; i < 16; ++i)
		{
			val = currentNodeConfiguration[i] - 1;
			int j = abs(i / 4 - val / 4) + abs(i % 4 - val % 4);
			currentNode->iH += j;
		}
	}

	void AStar::Search(std::vector<Node> &result)
	{
		AddNodeToOpenList(NULL, tRoot.front());
		Node* pCurrentNode = NULL;

		while (!qOpenList.empty())
		{
			pCurrentNode = VisitNode();
			if (*pCurrentNode == *iEndNode)
			{
				PrintPath(pCurrentNode);
				break;
			}
		}
		while (pCurrentNode != NULL)
		{
			result.push_back(*pCurrentNode);
			pCurrentNode = pCurrentNode->pParent;
		}
	}

	Node* AStar::VisitNode()
	{
		Node* pCurrentNode = qOpenList.front();
		qOpenList.pop_front();
		pCurrentNode->eState = NodeState::Closed;

		std::cout << "\nVisiting Node(" << pCurrentNode << ")...\n";

		CreateGraphAdjs(pCurrentNode);

		std::cout << "Adding Adj Node to Open List...\n";

		std::list<Node*>::iterator iAdjEnd(pCurrentNode->lAdj.end());
		for (std::list<Node*>::iterator iter = pCurrentNode->lAdj.begin(); iter != iAdjEnd; ++iter)
		{
			AddNodeToOpenList(pCurrentNode, *iter);
		}
		std::cout << "Adding Adj Node...DONE\n";


		std::cout << "  OPENLIST - START Elements: " << qOpenList.size() << "\n";
		std::list<Node*>::iterator iEnd(qOpenList.end());
		for (std::list<Node*>::iterator iter = qOpenList.begin(); iter != iEnd; ++iter)
		{
			std::cout << "      (" << *iter << ") F = " << (*iter)->iF << " = G(" << (*iter)->iG << ") + H(" << (*iter)->iH << ")\n";
		}
		std::cout << "  OPENLIST - END \n";

		std::cout << "Visiting Node(" << pCurrentNode << ")... DONE\n";

		return pCurrentNode;
	}

	void AStar::AddNodeToOpenList(Node* pParent, Node* pNode)
	{
		std::cout << "(" << pNode << ")";

		switch (pNode->eState)
		{
		case NodeState::Closed:
			if (pNode->iG <= pParent->iG + 1)
			{
				std::cout << " already visited.\n";
				return;
			}
			break;

		case NodeState::Open:
			if (pNode->iG <= pParent->iG + 1)
			{
				std::cout << " already in open list.\n";
				return;
			}
			else
			{
				qOpenList.remove(pNode);
			}
			break;

		default:
			break;
		}

		pNode->pParent = pParent;
		pNode->iG = (pParent == NULL) ? 0 : pParent->iG + 1;
		pNode->iF = pNode->iG + pNode->iH;
		pNode->eState = NodeState::Open;

		bool bInserted(false);

		std::list<Node*>::iterator iEnd(qOpenList.end());
		for (std::list<Node*>::iterator iter = qOpenList.begin(); iter != iEnd; ++iter)
		{
			Node* pIterNode(*iter);
			if (pIterNode->iF > pNode->iF)
			{
				qOpenList.insert(iter, pNode);
				bInserted = true;
				std::cout << " correctly added.\n";
				break;
			}
		}

		if (!bInserted)
		{
			qOpenList.push_back(pNode);
			std::cout << " correctly added.\n";
		}
	}

	void AStar::PrintPath(Node* pNode) const
	{
		std::list<Node*> lPath;
		while (pNode != NULL)
		{
			lPath.push_front(pNode);
			pNode = pNode->pParent;
		}

		std::cout << "\n\nPATH FOUND - ";

		std::list<Node*>::iterator iEnd(lPath.end());
		for (std::list<Node*>::iterator iter = lPath.begin(); iter != iEnd; ++iter)
		{
			std::cout << "(" << *iter << ")";
		}

		std::cout << "\n\n\n";
	}

	void AStar::Clean()
	{/*
	 std::cout << "Deleting Nodes...\n";
	 for (int iRow = 0; iRow < xMax; ++iRow)
	 {
	 std::cout << "  ";
	 for (int iCol = 0; iCol < yMax; ++iCol)
	 {
	 delete tRoot[(iRow * yMax) + iCol];
	 std::cout << "(" << iRow << "," << iCol << ") - ";
	 }
	 std::cout << "\n";
	 }
	 std::cout << "Deleting Nodes...\n\n";*/
	}
}