#include "TPLogic.h"

PokerInfo::PokerInfo(std::vector<Poker*>& pokerData) :
	m_pokerType(0),
	m_pokerPoint(0)
{
	m_pokerData = pokerData;
}

PokerInfo::~PokerInfo()
{
}



TPPlayer::TPPlayer()
{

}

TPPlayer::~TPPlayer()
{

}

void TPPlayer::addPublicPokers(std::vector<Poker*>& publicPokers)
{
	for (auto poker:publicPokers)
	{
		m_publicPokerVec.push_back(poker);
	}
}

TPLogic::TPLogic()
{
}


TPLogic::~TPLogic()
{
}

PokerInfo TPLogic::checkPokers(std::vector<Poker*>& pokers)
{
	PokerInfo	info(pokers);

	return info;
}
