#include <stdio.h>
#include <iostream>
#include "PokerUtil.h"
#include "TPLogic.h"
int main(int argc, char const *argv[])
{
	auto pokerVec = PokerUtil::createNewPokers();;
	PokerUtil::sortPokerB2SbyNum(pokerVec);

	std::vector<uint8_t>	pokerData = {46,45,44,43,42};
	auto handPokerVec = PokerUtil::createNewPokers(pokerData);
	PokerUtil::printPoker(handPokerVec,"mainPrintHandPokers---");

	TPLogic	logic;
	auto info = logic.checkPokers(handPokerVec);
	std::cout << "pokerType==" << (int)info.getPokerType() << "---and poker point==" << (int)info.getPokerPoint() << std::endl;

	while (true)
	{

	}
	return 0;
}