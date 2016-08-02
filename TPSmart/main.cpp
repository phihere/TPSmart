#include <stdio.h>
#include <iostream>
#include "PokerUtil.h"
#include "TPLogic.h"
int main(int argc, char const *argv[])
{
	auto pokerVec = PokerUtil::createNewPokers();
	PokerUtil::sortPokerB2SbyNum(pokerVec);

	std::vector<uint8_t>	pokerData = {46,45,44,43,42};
	auto handPokerVec = PokerUtil::createNewPokers(pokerData);
	PokerUtil::printPoker(handPokerVec,"mainPrintHandPokers---"); 

	std::vector<uint8_t>	allPokers;
	for (auto poker:pokerVec)
	{
		allPokers.push_back(poker->getPokerValue());
	}
	auto allCombain = PokerUtil::getAllCombination(allPokers,5);
	 //for (std::vector<std::vector<uint8_t>>::iterator it = allCombain.begin(); it != allCombain.end();it++)
	 //{
		// 
	 //}

	
	TPLogic	logic;
	auto info = logic.checkPokers(handPokerVec);
	std::cout << "pokerType==" << (int)info.getPokerType() << "---and poker point==" << (int)info.getPokerPoint() << std::endl;

	system("pause");
	return 0;
}