#include "PokerUtil.h"
using namespace std;
using namespace PokerConst;
Poker::Poker(uint8_t value)
{
	
	m_pokerValue = value;
	m_pokerNum = value % 16;
	m_pokerColor = value / 16;

}

Poker::~Poker()
{

}

string Poker::getPokerDescription()
{
	string	numStr[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	string colorStr[] = { "Diamond", "Clubs", "Heart", "Spade" };
	auto description = colorStr[m_pokerColor-1] + "_" + numStr[m_pokerNum - 2];
	return description;
}

vector<Poker*>	PokerUtil::createNewPokers()
{
	vector<uint8_t> valueVec;
	vector<uint8_t> pokerNumVec = { P_2, P_3, P_4, P_5, P_6, P_7, P_8, P_9, P_10, P_J, P_Q, P_K, P_A };
	vector<uint8_t> pokerColorVec = { FC_Spade, FC_Heart, FC_Clubs, FC_Diamond };
	for (auto num:pokerNumVec)
	{
		for  (auto color:pokerColorVec)
		{
			valueVec.push_back(color<<4 | num);
		}
	}

	vector<Poker*> pokerVec;
	for (auto value:valueVec)
	{
		auto poker = new Poker(value);
		pokerVec.push_back(poker);
	}

	//对手牌进行随机;
	srand((unsigned int)time(0));
	
	vector<Poker*>	randPokerVec;
	while (pokerVec.size() > 0)
	{
		size_t index = rand() % pokerVec.size();
		randPokerVec.push_back(pokerVec.at(index));
		pokerVec.erase(pokerVec.begin() + index);
	}


	return randPokerVec;
}

POKER_DATA_VEC PokerUtil::createNewPokers(std::vector<uint8_t> pokers)
{
	POKER_DATA_VEC	pokerVec;
	for (auto pokerByte:pokers)
	{
		auto poker = new Poker(pokerByte);
		pokerVec.push_back(poker);
	}
	return pokerVec;
}

void PokerUtil::printPoker(const std::vector<Poker*>& pokerVec,const std::string& des)
{
	for (auto poker : pokerVec)
	{
		cout << des.c_str() <<"---printPoker==="<< poker->getPokerDescription().c_str() <<"---value==="<<(int)poker->getPokerValue()<<endl;
	}
}

void PokerUtil::sortPokerB2SbyNum(std::vector<Poker*>& pokerVec)
{
	for (size_t i = 0; i < pokerVec.size(); i++)
	{
		for (size_t j = i+1; j < pokerVec.size(); j++)
		{
			auto pokeri = pokerVec.at(i);
			auto pokerj = pokerVec.at(j);
			if (pokeri->getPokerNum()<pokerj->getPokerNum())
			{
				swap(pokerVec[i],pokerVec[j]);
			}
		}
	}
}

//static void sortPokerB2SbyNum(std::vector<uint8_t>& byteVec)
//{
//	for (size_t i = 0; i < byteVec.size(); i++)
//	{
//		for (size_t j = i + 1; j < byteVec.size(); j++)
//		{
//			auto pokeri = byteVec.at(i);
//			auto pokerj = byteVec.at(j);
//			if (pokeri%16 < pokerj%16)
//			{
//				swap(byteVec[i], byteVec[j]);
//			}
//		}
//	}
//}

void PokerUtil::sortPokerB2SbyColor(std::vector<Poker*>& pokerVec)
{
	for (size_t i = 0; i < pokerVec.size(); i++)
	{
		for (size_t j = i + 1; j < pokerVec.size(); j++)
		{
			auto pokeri = pokerVec.at(i);
			auto pokerj = pokerVec.at(j);
			if (pokeri->getPokerColor()<pokerj->getPokerColor())
			{
				swap(pokerVec[i], pokerVec[j]);
			}
		}
	}
}

POKER_DATA_MAP PokerUtil::getSortPointPokers(const std::vector<Poker*>& pokerVec)
{
	POKER_DATA_MAP	pokerMap;
	POKER_DATA_VEC	tempPokerVec(pokerVec);
	for (auto poker:pokerVec)
	{
		POKER_DATA_MAP::const_iterator	it = pokerMap.find(poker->getPokerNum());
		POKER_DATA_VEC samePokerVec;
		if (it != pokerMap.end())//若已存在对应的key，则直接用原有的vec
		{
			samePokerVec = it->second;
		}
		
		if (tempPokerVec.empty())
		{
			break;
		}
		size_t	j = 0;
		while (tempPokerVec.size()>j)
		{
			auto pokerTemp = tempPokerVec[j];
			if (pokerTemp->getPokerNum() == poker->getPokerNum())
			{
				samePokerVec.push_back(pokerTemp);
				tempPokerVec.erase(tempPokerVec.begin() + j);
			}
			else
			{
				j++;
			}
		}
		pokerMap.insert(POKER_DATA_PAIR(poker->getPokerNum(), samePokerVec));

	}

	return pokerMap;
}

std::vector<std::vector<uint8_t>> PokerUtil::getAllCombination(const std::vector<uint8_t>& NVec, size_t	countM)
{
	_ASSERTE(NVec.size() >= countM, "Nvec size must bigger than M!");
	auto allDataVec = NVec;
	std::vector<std::vector<uint8_t>>	allCombian;
	//sortPokerB2SbyNum(allDataVec);
	std::vector<uint8_t>	markVec(NVec.size(), 0);
	for (size_t i = 0; i < countM; i++)
	{
		markVec[i] = 1;
	}
	for (int i = 0; i < NVec.size()-1; i++)
	{
		if (markVec[i] == 1 && markVec[i+1] == 0)
		{
			std::vector<uint8_t>	perCombian;
			swap(markVec[i], markVec[i + 1]);
			sort(markVec.begin(), markVec.begin() + i, greater<uint8_t>());
			for (size_t j = 0; j < markVec.size(); j++)
			{
				if (markVec[j] == 1)
				{
					cout << "vilible num index====" << j << endl;
					perCombian.push_back(NVec[j]);
					if (perCombian.size() == countM)
					{
						allCombian.push_back(perCombian);
						break;
					}
				}
			}
			i = -1;
		}
	}
	cout << "allCombian size====" << allCombian.size() << endl;
	return allCombian;
}

