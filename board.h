#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
using namespace std;
struct Board {
	sf::RectangleShape rectH1, rectH2, rectV1, rectV2;
	vector<int> moves = vector<int>(9,0);
	Board(sf::RenderWindow& window)
	{
		int width = window.getSize().y;
		rectH1.setSize(sf::Vector2f(10, width - 50));
		rectH2.setSize(sf::Vector2f(10, width - 50));
		rectV1.setSize(sf::Vector2f(width - 50, 10));
		rectV2.setSize(sf::Vector2f(width - 50, 10));
		rectH1.setOrigin(sf::Vector2f(rectH1.getSize() / 2.0f));
		rectH2.setOrigin(sf::Vector2f(rectH2.getSize() / 2.0f));
		rectV1.setOrigin(sf::Vector2f(rectV1.getSize() / 2.0f));
		rectV2.setOrigin(sf::Vector2f(rectV2.getSize() / 2.0f));
		rectH1.setPosition(sf::Vector2f(width / 3, width / 2));
		rectH2.setPosition(sf::Vector2f((2 * width / 3), width / 2));
		rectV1.setPosition(sf::Vector2f((width / 2), (width / 3)));
		rectV2.setPosition(sf::Vector2f((width / 2), (2 * width / 3)));
	}
	void setFillColor(sf::Color color) {
		rectH1.setFillColor(color);
		rectH2.setFillColor(color);
		rectV1.setFillColor(color);
		rectV2.setFillColor(color);
	}
	int Winner(vector<int> &v , int &playerOneMove )
	{
		if (v[0] == v[1] && v[0] == v[2] && v[0] != 0)
		{
			if (v[0] == playerOneMove)
				return 1;
			return -1;
		}
		else if (v[3] == v[4] && v[3] == v[5] && v[3] != 0 )
		{
			if (v[2] == playerOneMove)
				return 1;
			return -1;
		}
		else if (v[6] == v[7] && v[6] == v[8] && v[6] != 0 )
		{
			if (v[6] == playerOneMove)
				return 1;
			return -1;
		}
		else if (v[0] == v[3] && v[0] == v[6] && v[0] != 0 )
		{
			if (v[0] == playerOneMove)
				return 1;
			return -1;
		}
		else if (v[1] == v[4] && v[1] == v[7] && v[1] != 0 )
		{
			if (v[1] == playerOneMove)
				return 1;
			return -1;
		}
		else if (v[2] == v[5] && v[2] == v[8] && v[2] != 0 )
		{
			if (v[2] == playerOneMove)
				return 1;
			return -1;
		}
		else if (v[0] == v[4] && v[0] == v[8] && v[0] != 0 )
		{
			if (v[0] == playerOneMove)
				return 1;
			return -1;
		}
		else if (v[2] == v[4] && v[2] == v[6] && v[2] != 0 )
		{
			if (v[2] == playerOneMove)
				return 1;
			return -1;
		}
		else
		{
			for (int i = 0; i < 9; i++)
			{
				if (v[i] == 0)
					return -2;
			}
			return 0;
		}
	}
	void setSign(vector<int>& move, int indx, int playerOneSign , bool &turn)
	{
		if (move[indx] == 0)
		{
			if (turn)
				move[indx] = playerOneSign;
			else
			{
				if (playerOneSign == 1)
					move[indx] = -1;
				else
					move[indx] = 1;
			}
			turn = !turn;
		}
	}
	void restart(bool &turn) {
		for (int i = 0; i < 9; i++)
			this->moves[i] = 0;
		turn = true;
	}
};