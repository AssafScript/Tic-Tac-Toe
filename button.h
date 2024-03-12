#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
struct Button {
	sf::Font font;
	sf::Text title;
	sf::RectangleShape button;
	Button(string f, string s) {
		font.loadFromFile(f);
		title.setFont(font);
		title.setString(s);
		button.setSize(sf::Vector2f(title.getGlobalBounds().width + 20, title.getGlobalBounds().height + 20));
		button.setOrigin(button.getSize() / 2.0f);
		title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	}
	void setPosition(unsigned int x, unsigned int y)
	{
		button.setPosition(x, y);
		title.setPosition(x, y);
	}
	void setFillColor(sf::Color color)
	{
		title.setFillColor(color);
		button.setOutlineThickness(2);
		button.setOutlineColor(color);
	}
	void setTransparent() {
		button.setFillColor(sf::Color::Transparent);
	}
	void disableTransparent() {
		button.setFillColor(sf::Color::White);
	}
	void setString(string s)
	{
		title.setString(s);
		title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
		button.setSize(sf::Vector2f(title.getGlobalBounds().width + 20, title.getGlobalBounds().height + 40));
		button.setOrigin(button.getSize() / 2.0f);
	}
};