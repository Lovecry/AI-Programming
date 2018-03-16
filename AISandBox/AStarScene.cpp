#include "AStarScene.h"
#include "Application.h"

/*
Setto le posizioni dei quadrati
*/
void AStarScene::setTilePosition(std::vector<RectangleShape> &sprites)
{
		
	for (int index = 0; index < 100; ++index){

		sprites.at(index).setPosition((index/10)* 50.0f, (index%10)* 50.0f);
		
	}
	
}

AStarScene::AStarScene()
{
	
	alg.Init();
	
	for (int index = 0; index < 100; ++index)
	{
		//creo quadrato
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(50, 50));
		rectangle.setOutlineColor(sf::Color::Red);
		rectangle.setFillColor(sf::Color::White);
		rectangle.setOutlineThickness(1);
		rectangle.setPosition(0, 0);
			
		//inserisco alla fine dell array	
		sprites.push_back(rectangle);
		
	}

	setTilePosition( sprites);

}



AStarScene::~AStarScene()
{
    
}

/*
usere per intercettare eevnti tastiera o mouse ecc
*/
void AStarScene::OnIdle()
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		Application::Istance()->SetScene(SceneEnum::Scene_MainMenu);
		//alg.Finish();
	}
}


/*
Questo è il metodo che viene chiamato ogni frame
Creato dal prof
*/
void AStarScene::OnDraw(sf::RenderWindow& renderWindow)
{

	bool isFinish = alg.SearchStep();
	
	//se non è finita la ricerca, 
	
		for (int index = 0; index < 100; ++index){
			//mi ricavo il nodo iesimo
			Node* node = alg.getNodes(index);

			//mi ricavo le coordinate del nodo per sicurezza
			int X = node->X();
			int Y = node->Y();

			//associo un colore per ogni stato del nodo
			switch (node->eState)
			{
			case Unknown:
				sprites[(X * 10) + Y].setFillColor(sf::Color::White);
				break;
			case Open:
				sprites[(X * 10) + Y].setFillColor(sf::Color::Red);
				break;
			case Closed:
				sprites[(X * 10) + Y].setFillColor(sf::Color::Green);
				break;
			case Finish: 
				sprites[(X * 10) + Y].setFillColor(sf::Color::Blue);				
				break;
			default:
				break;
			}
		}
	

	//aggiorno la grafica
	for (int index = 0; index < 100; ++index){
		renderWindow.draw(sprites[index]);
	}

}
