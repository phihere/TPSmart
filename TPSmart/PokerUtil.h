#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <map>
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

private:
	uint8_t m_pokerValue;
	uint8_t m_pokerNum;
	uint8_t m_pokerColor;


};
typedef std::vector<Poker*>					POKER_DATA_VEC;
typedef	std::map<uint8_t, POKER_DATA_VEC>	POKER_DATA_MAP;
typedef std::pair<uint8_t, POKER_DATA_VEC>	POKER_DATA_PAIR;

class PokerUtil
{
public:
	static std::vector<Poker*>	createNewPokers();

	static POKER_DATA_VEC	createNewPokers(std::vector<uint8_t> pokers);

	static void printPoker(const std::vector<Poker*>& pokerVec,const std::string& des ="");
	static void sortPokerB2SbyNum(std::vector<Poker*>& pokerVec);
	static void sortPokerB2SbyColor(std::vector<Poker*>& pokerVec);
	
	static POKER_DATA_MAP	getSortPointPokers(std::vector<Poker*>& pokerVec);
};
