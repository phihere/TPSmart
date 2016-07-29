#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "PokerConst.h"

class Poker
{
public:

	Poker(uint8_t value);
	virtual ~Poker();
	uint8_t getPokerValue()	{return m_pokerValue;};
	uint8_t getPokerNum() { return m_pokerNum; };
	uint8_t getPokerColor() {return m_pokerColor; };
	std::string getPokerDescription();

public:
	uint8_t m_pokerValue;
	uint8_t m_pokerNum;
	uint8_t m_pokerColor;


};


class PokerUtil
{
public:
	static std::vector<Poker*>	createNewPokers();
	static void printPoker(std::vector<Poker*> pokerVec);
};
