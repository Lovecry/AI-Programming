#include "Node.h"

namespace ASnamespace
{
	Node::Node() : eState(NodeState::Unknown),
		iF(0),
		iG(0),
		iH(0)
	{
	}

	std::ostream& operator<<(std::ostream& out, Node* myNode)
	{
		int i;
		for (i = 0; i < 15; ++i){
			out << myNode->getConfigurationIndexed(i) << ",";
		}
		out << myNode->getConfigurationIndexed(15);
		/*out << endl <<
			"Stato : " << myNode->eState << endl <<
			"F : " << myNode->iF << endl <<
			"G : " << myNode->iG << endl <<
			"H : " << myNode->iH << "\n\n" << endl;*/
		return out;
	}

	bool Node::operator==(const Node& other) const
	{
		bool result = true;
		for (int i = 0; i < 16 && result; ++i)
		{
			result = (configuration[i] == other.configuration[i]);
		}
		return result;
	}

	bool Node::operator!=(const Node &other) const
	{
		int i;
		for (i = 0; i < 16; ++i)
		{
			if (configuration[i] != other.configuration[i])
			{
				return true;
			}
		}
		return false;
	}

	void Node::setConfiguration(int config[])
	{
		for (int i = 0; i < 16; i++)
		{
			configuration[i] = config[i];
		}
	}

	int* Node::getConfiguration()
	{
		return configuration;
	}
}