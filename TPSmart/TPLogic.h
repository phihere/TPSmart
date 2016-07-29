#pragma once

#include "PokerUtil.h"
class TPDesk
{
public:
	TPDesk();
	~TPDesk();
	void setHandPokers(std::vector<Poker*> &handPokers){ m_publicPokerVec = handPokers; };
	void addPublicPokers(std::vector<Poker*> &publicPokers);
	std::vector<Poker*> getHandPokers(){ return m_handPokersVec; };
	std::vector<Poker*> getPublicPokers(){ return m_publicPokerVec; };
private:
	//µ×ÅÆ
	std::vector<Poker*>	m_handPokersVec;

	//¹«¹²ÅÆ
	std::vector<Poker*> m_publicPokerVec;

};
class TPLogic
{
public:
	TPLogic();
	~TPLogic();
};