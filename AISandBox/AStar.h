#ifndef __AStar__AStar__
#define __AStar__AStar__

#include <iostream>
#include <list>
#include "Node.h"

class AStar
{
public:
    void Run();
	std::list<Node*> qOpenList;

	void Init();
	void Finish();
	bool SearchStep();
	Node* getNodes(int i) const;
    
private:
    const static int xMax = 10;
    const static int yMax = 10;
    const static int iStartNode = 0;
    const static int iEndNode = 99;
    
	void CreateGraph();
	void CreateGraphAdjs();
	void CreateNodeAdj(const int iRow, const int iCol);

	void ComputeGraphHeuristics();
	void ComputeNodeHeuristic(Node* pNode);

	void Clean();

	void Search();
    
    Node* VisitNode();
    void AddNodeToOpenList(Node* pParent, Node* pNode);
    
    void PrintPath(Node* pNode) const;
    
    Node* tRoot[xMax * yMax];
    
};

#endif /* defined(__AStar__AStar__) */
