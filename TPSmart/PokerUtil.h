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
	//�������һ��52�ŵ��˿���
	static std::vector<Poker*>	createNewPokers();

	//�������е����ݴ���һ����
	static POKER_DATA_VEC	createNewPokers(std::vector<uint8_t> pokers);

	//��ӡһ���Ƶ���Ϣ
	static void printPoker(const std::vector<Poker*>& pokerVec,const std::string& des ="");

	//���ݵ����Ӵ�С����һ����
	static void sortPokerB2SbyNum(std::vector<Poker*>& pokerVec);
	static void sortPokerB2SbyNum(std::vector<uint8_t>& byteVec);

	//������ɫ�Ӵ�С����һ����
	static void sortPokerB2SbyColor(std::vector<Poker*>& pokerVec);
	
	//��һ���ư��յ���Ϊkey��
	static POKER_DATA_MAP	getSortPointPokers(const std::vector<Poker*>& pokerVec);

	//������ϳ���ͬ��ϵ�����,��n����ͬԪ����ȡ��m��m��n����Ԫ�ؽ������
	static std::vector<std::vector<uint8_t>>	getAllCombination(const std::vector<uint8_t>& NVec,size_t	countM);

};
