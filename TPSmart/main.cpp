#include <stdio.h>
#include <iostream>
#include "PokerUtil.h"
int main(int argc, char const *argv[])
{
	auto pokerVec = PokerUtil::createNewPokers();;
	PokerUtil::printPoker(pokerVec);
	
	while (true)
	{

	}
	return 0;
}