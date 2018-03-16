#pragma once

#include <list>
#include "NodeState.h"
#include <iostream>

namespace ASnamespace
{
	class Node
	{
	public:

		Node();
		bool operator==(const Node& other) const;
		bool operator!=(const Node& other) const;

		void setConfiguration(int config[]);
		int* getConfiguration();
		int getConfigurationIndexed(int index) { return configuration[index]; };


		friend std::ostream& operator<<(std::ostream& out, Node* a);

		NodeState           eState;
		Node*				pParent;
		int					iF;
		int					iG;
		int					iH;
		std::list<Node*>	lAdj;

	private:
		//configurazione scacchiera corrente
		int					configuration[16];
	};
}