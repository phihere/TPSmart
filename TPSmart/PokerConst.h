#pragma once

#include <stdint.h>

namespace PokerConst//通用poker点数与花色
{
	//无效点数
	const static uint8_t P_0 = 0;
	//点数
	const static uint8_t P_2 = 2;
	const static uint8_t P_3 = 3;
	const static uint8_t P_4 = 4;
	const static uint8_t P_5 = 5;
	const static uint8_t P_6 = 6;
	const static uint8_t P_7 = 7;
	const static uint8_t P_8 = 8;
	const static uint8_t P_9 = 9;
	const static uint8_t P_10 = 10;
	const static uint8_t P_J = 11;
	const static uint8_t P_Q = 12;
	const static uint8_t P_K = 13;
	const static uint8_t P_A = 14;

	//花色
	const static uint8_t FC_Spade = 4;	//黑桃
	const static uint8_t FC_Heart = 3;	//红心
	const static uint8_t FC_Clubs = 2;	//梅花
	const static uint8_t FC_Diamond = 1; //方块
}

namespace TPPokerData//德扑专用牌型
{
	const static uint8_t T_RoyalFlush = 10;			//皇家同花顺
	const static uint8_t T_StraightFlush = 9;		//同花顺
	const static uint8_t T_FourK = 8;				//四条
	const static uint8_t T_Fullhouse = 7;			//葫芦
	const static uint8_t T_Flush = 6;				//清一色
	const static uint8_t T_Straight = 5;			//顺子
	const static uint8_t T_ThreeK = 4;				//三条
	const static uint8_t T_TwoPairs = 3;			//两对
	const static uint8_t T_Pairs = 2;				//一对
	const static uint8_t T_High = 1;				//高牌

	const static uint8_t T_Zero = 0;				//无效点数
}
