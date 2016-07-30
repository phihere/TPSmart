#pragma once

#include <stdint.h>

namespace PokerConst//ͨ��poker�����뻨ɫ
{
	//��Ч����
	const static uint8_t P_0 = 0;
	//����
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

	//��ɫ
	const static uint8_t FC_Spade = 4;	//����
	const static uint8_t FC_Heart = 3;	//����
	const static uint8_t FC_Clubs = 2;	//÷��
	const static uint8_t FC_Diamond = 1; //����
}

namespace TPPokerData//����ר������
{
	const static uint8_t T_RoyalFlush = 10;			//�ʼ�ͬ��˳
	const static uint8_t T_StraightFlush = 9;		//ͬ��˳
	const static uint8_t T_FourK = 8;				//����
	const static uint8_t T_Fullhouse = 7;			//��«
	const static uint8_t T_Flush = 6;				//��һɫ
	const static uint8_t T_Straight = 5;			//˳��
	const static uint8_t T_ThreeK = 4;				//����
	const static uint8_t T_TwoPairs = 3;			//����
	const static uint8_t T_Pairs = 2;				//һ��
	const static uint8_t T_High = 1;				//����

	const static uint8_t T_Zero = 0;				//��Ч����
}
