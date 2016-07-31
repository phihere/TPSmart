#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <functional>
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
	//随机生成一副52张的扑克牌
	static std::vector<Poker*>	createNewPokers();

	//根据已有的数据创建一手牌
	static POKER_DATA_VEC	createNewPokers(std::vector<uint8_t> pokers);

	//打印一手牌的信息
	static void printPoker(const std::vector<Poker*>& pokerVec,const std::string& des ="");

	//根据点数从大到小排列一手牌
	static void sortPokerB2SbyNum(std::vector<Poker*>& pokerVec);
	static void sortPokerB2SbyNum(std::vector<uint8_t>& byteVec);

	//根据颜色从大到小排列一手牌
	static void sortPokerB2SbyColor(std::vector<Poker*>& pokerVec);
	
	//将一手牌按照点数为key，
	static POKER_DATA_MAP	getSortPointPokers(const std::vector<Poker*>& pokerVec);

	//排列组合出不同组合的手牌,从n个不同元素中取出m（m≤n）个元素进行组合
	static std::vector<std::vector<uint8_t>>	getAllCombination(const std::vector<uint8_t>& NVec,size_t	countM);

};
