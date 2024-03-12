#include<SFML/Graphics.hpp>
#include<iostream>
#include "board.h"
#include "button.h"
using namespace std;

int main()
{
	//Render Window
	sf::RenderWindow window(sf::VideoMode(600, 600), "Tic-Tac-Toe",sf::Style::Close);
	window.setFramerateLimit(60);

	//Load primary font
	sf::Font font1 , font2;
	font1.loadFromFile("Data/Adumu.ttf");
	font2.loadFromFile("Data/R.ttf");

	//Color
	sf::Color color(106, 90, 205);

	//text
	sf::Text startTitle("TIC-TAC-TOE",font1,100);
	startTitle.setOrigin(startTitle.getGlobalBounds().width / 2, startTitle.getGlobalBounds().height / 2);
	startTitle.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f-200);
	startTitle.setFillColor(color);

	//buttons
	Button buttonStart("Data/Adumu.ttf", "Start"), playerOneX("Data/Adumu.ttf", "X"), playerOneO("Data/Adumu.ttf", "O");
	Button playerOne("Data/Adumu.ttf", "Player One: ");
	playerOne.setPosition(window.getSize().x / 2.0f - 130, window.getSize().y / 2.0f);
	playerOne.setFillColor(color);
	playerOneX.setPosition(window.getSize().x/2.0f,window.getSize().y/2.0f);
	playerOneO.setPosition(window.getSize().x/2.0f + 50,window.getSize().y/2.0f);
	buttonStart.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 100);
	buttonStart.setFillColor(color);
	playerOneX.setFillColor(color);
	playerOneO.setFillColor(color);
	buttonStart.setTransparent();
	playerOneO.setTransparent();
	playerOneX.setTransparent();
	Button winner("Data/Adumu.ttf","test");
	winner.title.setFont(font1);
	winner.title.setCharacterSize(70);
	winner.setFillColor(color);
	Button restart("Data/Adumu.ttf", "Restart");
	restart.setPosition(window.getSize().x / 2.0f , window.getSize().y / 2.0f);
	restart.setFillColor(color);
	restart.setPosition(window.getSize().y / 2, window.getSize().y / 2 + 150);
	Button exit("Data/Adumu.ttf", "Exit");
	exit.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
	exit.setFillColor(color);
	exit.setPosition(window.getSize().y / 2, window.getSize().y / 2 + 200);
	exit.setTransparent();
	//board
	Board board(window);
	board.setFillColor(color);

	//wallpaper
	sf::Texture texture;
	texture.loadFromFile("Data/wall.jpg");
	texture.setSmooth(true);
	sf::Sprite wallpaper;
	wallpaper.setTexture(texture);
	wallpaper.setScale(0.12, 0.12);

	//Logic Variables
	bool player1Turn = true, gameStarted = false;
	int playerOneSign = 1;
	int width = window.getSize().y;
	int winnerPLayer;
	bool win = false;

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		bool restartButton = false;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			winnerPLayer = board.Winner(board.moves, playerOneSign);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//Mouse Position & width of Screen
				auto mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				auto width = window.getSize().y;

				//Change Player one to X
				if (playerOneX.button.getGlobalBounds().contains(mouse))
					playerOneSign = 1;

				//ChangePlayer one to O
				else if (playerOneO.button.getGlobalBounds().contains(mouse))
					playerOneSign = -1;

				//Game Window Check
				if (buttonStart.button.getGlobalBounds().contains(mouse))
					gameStarted = true;
				//Game Logic
				else if (gameStarted && win == false )
				{
					if (mouse.x >= 25 && mouse.x <= width / 3 && mouse.y >= 25 && mouse.y <= width / 3)
						board.setSign(board.moves, 0, playerOneSign, player1Turn);
					else if (mouse.x >= width / 3 && mouse.x <= 2 * width / 3 && mouse.y >= 25 && mouse.y <= width / 3)
						board.setSign(board.moves, 1, playerOneSign, player1Turn);
					else if (mouse.x >= 2 * width / 3 && mouse.x <= width && mouse.y >= 25 && mouse.y <= width / 3)
						board.setSign(board.moves, 2, playerOneSign, player1Turn);
					else if (mouse.x >= 25 && mouse.x <= width / 3 && mouse.y >= width / 3 && mouse.y <= 2 * width / 3)
						board.setSign(board.moves, 3, playerOneSign, player1Turn);
					else if (mouse.x >= width / 3 && mouse.x <= 2 * width / 3 && mouse.y >= width / 3 && mouse.y <= 2 * width / 3)
						board.setSign(board.moves, 4, playerOneSign, player1Turn);
					else if (mouse.x >= 2 * width / 3 && mouse.x <= width && mouse.y >= width / 3 && mouse.y <= 2 * width / 3)
						board.setSign(board.moves, 5, playerOneSign, player1Turn);
					else if (mouse.x >= 25 && mouse.x <= width / 3 && mouse.y >= 2 * width / 3 && mouse.y <= width)
						board.setSign(board.moves, 6, playerOneSign, player1Turn);
					else if (mouse.x >= width / 3 && mouse.x <= 2 * width / 3 && mouse.y >= 2 * width / 3 && mouse.y <= width)
						board.setSign(board.moves, 7, playerOneSign, player1Turn);
					else if (mouse.x >= 2 * width / 3 && mouse.x <= width && mouse.y >= 2 * width / 3 && mouse.y <= width)
						board.setSign(board.moves, 8, playerOneSign, player1Turn);
				}

				//Restart Button
				else if (restart.button.getGlobalBounds().contains(mouse))
					restartButton = true;

				//Exit Button
				else if(exit.button.getGlobalBounds().contains(mouse))
					window.close();
			}
		}

		//Check Winner
		winnerPLayer = board.Winner(board.moves , playerOneSign);

		//main window
		window.clear();
		window.draw(wallpaper);
		window.draw(buttonStart.button);
		window.draw(startTitle);
		window.draw(playerOne.title);
		window.draw(playerOneX.button);
		window.draw(playerOneX.title);
		window.draw(playerOneO.button);
		window.draw(playerOneO.title);
		window.draw(buttonStart.title);
		window.draw(exit.button);
		window.draw(exit.title);

		//GameWindow
		if (gameStarted)
		{
			window.clear();
			window.draw(wallpaper);
			window.draw(board.rectH1);
			window.draw(board.rectH2);
			window.draw(board.rectV1);
			window.draw(board.rectV2);
			for (int i = 0; i < 9; i++)
			{
				sf::Text move;
				move.setFont(font2);
				if (board.moves[i] == 1)
					move.setString("X");
				else if (board.moves[i] == -1)
					move.setString("O");
				move.setFillColor(color);
				move.setCharacterSize(150);
				move.setOrigin(move.getGlobalBounds().width / 2, move.getGlobalBounds().height / 2);
				if (i == 0)
					move.setPosition(width / 6, width / 6 - 25);
				if (i == 1)
					move.setPosition(width / 6 + width / 3, width / 6 - 25);
				if (i == 2)
					move.setPosition(width / 6 + 2 * width / 3, width / 6 - 25);
				if (i == 3)
					move.setPosition(width / 6, width / 6 + width / 3 - 25 );
				if (i == 4)
					move.setPosition(width / 6 + width / 3, width / 6 + width / 3 - 25);
				if ( i == 5 )
					move.setPosition(width / 6 + 2 * width / 3, width / 6 + width / 3 - 25);
				if (i == 6)
					move.setPosition(width / 6, width / 6 + 2 * width / 3 - 25);
				if (i == 7)
					move.setPosition(width / 6 + width / 3, width / 6 + 2 * width / 3 - 25);
				if (i == 8)
					move.setPosition(width / 6 + 2 * width / 3, width / 6 + 2 * width / 3 - 25);
				window.draw(move);
			}
			if (winnerPLayer != -2)
			{
				if (winnerPLayer == 1 && !win)
					winner.setString("The Winner is\n   PlayerOne");
				else if (winnerPLayer == -1 && !win)
					winner.setString("The Winner is\n   PlayerTwo");
				else if (winnerPLayer == 0 && !win) 
					winner.setString("TIE ");
				//Edit Position
				playerOne.setPosition(width / 2-140, width / 2 + 50);
				playerOneX.setPosition(width / 2, width / 2 + 50);
				playerOneO.setPosition(width / 2+50, width / 2 + 50);
				playerOneO.disableTransparent();
				playerOneX.disableTransparent();
				winner.setPosition(width / 2, width / 2 - 100);
				exit.disableTransparent();
				//Draw
				window.draw(winner.button);
				window.draw(winner.title);
				window.draw(playerOne.button);
				window.draw(playerOne.title);
				window.draw(playerOneX.button);
				window.draw(playerOneX.title);
				window.draw(playerOneO.button);
				window.draw(playerOneO.title);
				window.draw(restart.button);
				window.draw(restart.title);
				window.draw(exit.button);
				window.draw(exit.title);
				win = true;
				if ( restartButton )
					win = false, board.restart(player1Turn);
			}
		}
		//Display
		window.display();
	}
	return 0;
}