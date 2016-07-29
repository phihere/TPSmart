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

void PokerUtil::printPoker(vector<Poker*> pokerVec)
{
	for (auto poker:pokerVec)
	{
		cout << "printPoker===" << poker->getPokerDescription().c_str() << endl;
	}
}