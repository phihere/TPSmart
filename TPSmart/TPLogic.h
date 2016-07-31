#pragma once

#include "PokerUtil.h"

class PokerInfo
{
public:
	PokerInfo(std::vector<Poker*>& pokerData);
	~PokerInfo();
	void setPokerPoint(uint8_t pokerPoint) { m_pokerPoint = pokerPoint; };
	void setPokerType(uint8_t pokerType) { m_pokerType = pokerType; };
	uint8_t	getPokerPoint() { return m_pokerPoint; };
	uint8_t getPokerType() { return m_pokerType; };
	const std::vector<Poker*>& getPokerData() { return m_pokerData; };

private:
	std::vector<Poker*>	m_pokerData;
	uint8_t	m_pokerType;
	uint8_t m_pokerPoint;

};

class TPPlayer
{
public:
	TPPlayer();
	~TPPlayer();
	void setHandPokers(std::vector<Poker*> &handPokers){ m_publicPokerVec = handPokers; };
	void addPublicPokers(std::vector<Poker*> &publicPokers);
	std::vector<Poker*> getHandPokers(){ return m_handPokersVec; };
	std::vector<Poker*> getPublicPokers(){ return m_publicPokerVec; };
private:
	//底牌
	std::vector<Poker*>	m_handPokersVec;

	//公共牌
	std::vector<Poker*> m_publicPokerVec;

};
class TPLogic
{
public:
	TPLogic();
	~TPLogic();
	PokerInfo checkPokers(std::vector<Poker*>& pokers);

private:
	//检测皇家同花顺、清一色、顺子，并赋值给pokerinfo
	void checkFlushAndColor(PokerInfo& pokerinfo);

	//检测金刚到高牌
	void checkFour2High(PokerInfo& pokerInfo);

	//检测数据是否为合法数据
	bool checkPokerInfoLegal(const PokerInfo& pokerInfo);

	//将牌型信息归零
	void clearPokerInfo(PokerInfo& pokerInfo);

	//比较两手牌的大小
	int comparePokers(const PokerInfo& selfPinfo, const PokerInfo& otherPinfo);

private:
	enum CompareResult
	{
		WIN = 1,
		TIE = 0,
		LOSE = -1

	};

	
};