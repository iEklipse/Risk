#include "stdafx.h"
#include "Dice.h"
#include "BattleHelper.h"

Dice::Dice()
{
	//this->dices = new vector<int*>(3);
}


Dice::~Dice()
{
	delete dices;
}

vector<int*>* Dice::getDices()
{
	return dices;
}

void Dice::initiateDices(int size, BattleHelper::DiceType diceType)
{
	if (diceType == BattleHelper::attacker && size >= 3) // Attacker has at most 3 Dice
	{
		dices = new vector<int*>(3);
		dices->at(0) = new int();
		dices->at(1) = new int();
		dices->at(2) = new int();
	}
	else if (diceType == BattleHelper::defender && size >= 2) // Defender has at most 2 Dice
	{
		dices = new vector<int*>(2);
		dices->at(0) = new int();
		dices->at(1) = new int();
	}
	else
	{
		dices = new vector<int*>(1);
		dices->at(0) = new int();
	}
}

void Dice::roll()
{
	for (vector<int>::size_type i = 0; i != dices->size(); i++) 
	{
		*(dices->at(i)) = (1 + rand() % 6);
	}
}

void Dice::sort()
{
	if (dices->size() == 2)
	{
		if (*(dices->at(1)) > *(dices->at(0)))
		{ 
			int valToSwap = *(dices->at(1));
			*(dices->at(1)) = *(dices->at(0));
			*(dices->at(0)) = valToSwap;
		}
	}
	else if (dices->size() == 3)
	{
		int valIndexZero = *(dices->at(0));
		int valIndexOne = *(dices->at(1));
		int valIndexTwo = *(dices->at(2));

		if (*(dices->at(2)) > *(dices->at(1)))
		{
			*(dices->at(2)) = valIndexOne;
			*(dices->at(1)) = valIndexTwo;	
		}
		if (*(dices->at(2)) > *(dices->at(0)))
		{
			*(dices->at(2)) = valIndexZero;
			*(dices->at(0)) = valIndexTwo;
		}
		if (*(dices->at(1)) > *(dices->at(0)))
		{
			*(dices->at(1)) = valIndexZero;
			*(dices->at(0)) = valIndexOne;
		}
	}
}

