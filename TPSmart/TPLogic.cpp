#include "TPLogic.h"

PokerInfo::PokerInfo(std::vector<Poker*>& pokerData) :
	m_pokerType(0),
	m_pokerPoint(0)
{
	_ASSERTE(pokerData.size() == 5,"poker count must be equal 5");
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
	_ASSERTE(pokers.size()>0);
	PokerUtil::sortPokerB2SbyNum(pokers);
	PokerInfo	info(pokers);
	checkFlushAndColor(info);
	if (!checkPokerInfoLegal(info))
	{
		checkFour2High(info);
	}
	return info;
}


void TPLogic::checkFlushAndColor(PokerInfo & pokers)
{
	bool sameColor = true;
	bool gradePoint = true;
	for (size_t i = 0; i < pokers.getPokerData().size() - 1; i++)
	{
		auto poker = pokers.getPokerData()[i];
		auto poker1 = pokers.getPokerData()[i + 1];
		if (poker->getPokerNum() - poker1->getPokerNum() != 1)
		{
			gradePoint = false;
		}
		if (poker->getPokerColor() != poker1->getPokerColor())
		{
			sameColor = false;
		}
	}

	pokers.setPokerPoint(pokers.getPokerData()[0]->getPokerNum());

	if (sameColor && gradePoint)
	{
		//�ж��Ƿ�Ϊ�ʼ�ͬ��˳
		if (pokers.getPokerPoint() == PokerConst::P_A)
		{
			pokers.setPokerType(TPPokerData::T_RoyalFlush);
		}
		else
		{
			pokers.setPokerType(TPPokerData::T_StraightFlush);
		}
	}
	else if (sameColor)
	{
		//������ɫһ��Ϊͬ��
		pokers.setPokerType(TPPokerData::T_Flush);
	}
	else if (gradePoint)
	{
		//�����Ȳ�����Ϊ˳��
		pokers.setPokerType(TPPokerData::T_Straight);
	}
	if (!checkPokerInfoLegal(pokers))
	{
		clearPokerInfo(pokers);
	}
}

void TPLogic::checkFour2High(PokerInfo & pokerInfo)
{
	unsigned int samePokerNum = 0;
	auto pokerData = pokerInfo.getPokerData();
	auto pokerMap = PokerUtil::getSortPointPokers(pokerData);

	//��ͬ�������Ƴ��ֵĴ�������KKKAA��«���� �����ź�һ�Ը����һ�� threeCardCount = 1; twoCardCount = 1;
	unsigned int fourCardCout = 0;
	unsigned int threeCardCount = 0;
	unsigned int twoCardCount = 0;
	unsigned int oneCardCount = 0;

	//�����Ƶ�ʵ�ʵ�����С
	uint8_t	fourKKey = 0;
	uint8_t	threeKey = 0;
	uint8_t twoKey = 0;
	uint8_t	oneKey = 0;
	for (POKER_DATA_MAP::const_iterator it = pokerMap.begin(); it != pokerMap.end();++it)
	{
		//����map�е�key�������е����ԣ�ʵ������˵����������У�����ȡ����key�϶����Ǹ������е���������
		if (it->second.size() == 4)
		{
			fourKKey = it->first;
			fourCardCout++;
		}
		else if(it->second.size() == 3)
		{
			threeKey = it->first;
			threeCardCount++;
		}
		else if (2 == it->second.size())
		{
			twoKey = it->first;
			twoCardCount++;
		}
		else
		{
			oneKey = it->first;
			oneCardCount++;
		}
		
	}

	if (fourCardCout)
	{
		pokerInfo.setPokerType(TPPokerData::T_FourK);
		pokerInfo.setPokerPoint(fourKKey);
		return;
	}
	if (threeCardCount>0)
	{
		if (twoCardCount>0)
		{
			pokerInfo.setPokerType(TPPokerData::T_Fullhouse);
			pokerInfo.setPokerPoint(threeKey);
			return;
		}
		if (twoCardCount == 0)
		{
			pokerInfo.setPokerType(TPPokerData::T_ThreeK);
			pokerInfo.setPokerPoint(threeKey);
			return;
		}

	}
	if (twoCardCount > 0)
	{
		if (twoCardCount == 2)
		{
			pokerInfo.setPokerType(TPPokerData::T_TwoPairs);
			pokerInfo.setPokerPoint(twoKey);
			return;
		}
		if (twoCardCount == 1)
		{
			pokerInfo.setPokerType(TPPokerData::T_Pairs);
			pokerInfo.setPokerPoint(twoKey);
			return;
		}
	}
	pokerInfo.setPokerType(TPPokerData::T_High);
	pokerInfo.setPokerPoint(oneKey);
}


bool TPLogic::checkPokerInfoLegal(const PokerInfo &pokerInfo)
{
	PokerInfo info = pokerInfo;
	if (info.getPokerPoint() == 0 || info.getPokerType() == 0)
	{
		return false;
	}
	return true;
}

void TPLogic::clearPokerInfo(PokerInfo & pokerInfo)
{
	pokerInfo.setPokerPoint(PokerConst::P_0);
	pokerInfo.setPokerType(TPPokerData::T_Zero);
}

