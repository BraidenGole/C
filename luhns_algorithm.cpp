/*
	FILE			:	luhns_algorithm.cpp
	PROJECT			:	None
	PROGRAMMER		:	Braiden Gole
	FIRST VERSION	:	2019-10-29
	DESCRIPTION		:	This is luhns algorithm,
						practicing (C). This is a credit
						card verification algorithm this
						program specifically targets the
						validations of: VISA, MASTERCARD,
						AMERICAN EXPRESS, and DISCOVER.
*/
#include <iostream>
#include <string>

#define KMAX_CRED_LEN 19
#define KMASTERCARD_NUM_LEN 5

// Function Prototypes.
long long get_credit_card(void);
std::string method_of_payment(const std::string card_num, short amount_of_digits);

int main(void)
{	
	// Credit card number.
	long long credit_card = get_credit_card();

	// Convert credit_card int a C++ style string.
	std::string scredit_card = std::to_string(credit_card);

	// Get the length of the credit card.
	short card_len = scredit_card.length();

	// Check the length of the credit card.
	if ((card_len != 13) && (card_len != 15) &&
		(card_len != 16) && (card_len != 19))
	{	
		get_credit_card();
	}

	// Luhns algorithm.
	int cred_array[KMAX_CRED_LEN] = { 0 };
	int multibytwo[KMAX_CRED_LEN] = { 0 };
	
	short cred = KMAX_CRED_LEN - 1;
	short even_sum = 0;
	short odd_sum = 0;

	short total = 0;
	
	std::string stotal = "";
	std::string card_num_reference = scredit_card;

	for (--cred; cred >= 0; --cred)
	{	
		// Convert a string to an (INT) array.
		cred_array[cred] = scredit_card[cred] - '0';

		if (cred % 2 == 0)
		{	
			// Multiply each element by two and the add the products.
			multibytwo[cred] = cred_array[cred] * 2;
			even_sum += multibytwo[cred];
		}
		else
		{	
			/*
				Add the remaining elements to get a sum
				then add the even_sum to the odd_sum
				creating a total.
			*/ 
			odd_sum += cred_array[cred];
			even_sum += odd_sum;
			total = even_sum;

			// Convert the total to a string then get the length.
			stotal = std::to_string(total);
		}
	}
	
	// Initializing parameters for the method_of_payment function.
	const std::string card_num = card_num_reference;
	short amount_of_digits = card_len;

	const std::string cardType = method_of_payment(card_num, amount_of_digits);

	std::cout << cardType;

	main();

	return 0;
}

/*
	FUNCTION	:	method_of_payment
	DESCRIPTION	:	This function takes in the validated credit card
					number and determines which bank the card is
					associated with.
	PARAMETERS	:	card_num
	RETURN		:	type_of_bank
*/
std::string method_of_payment(const std::string card_num,
	short amount_of_digits)
{
	std::string type_of_bank = "";

	//========================= VISA ========================
	if ((amount_of_digits == 13) || (amount_of_digits == 16))
	{
		if (card_num[0] == '4')
		{
			type_of_bank = "\tVALID: VISA\n";
			return type_of_bank;
		}
		else
		{	
			//================ MASTERCARD ===================
			const char numeric_strings[KMASTERCARD_NUM_LEN] =
			{ '1', '2', '3', '4', '5' };

			char snumeric_element = ' ';

			short sNums = 0;

			while (sNums < KMASTERCARD_NUM_LEN)
			{	
				// Checks for a 2 in the first and second index.
				if (card_num[0] && card_num[1] == '2')
				{
					type_of_bank = "\tVALID: MASTERCARD\n";
					return type_of_bank;
				}
				if (card_num[0] == '5')
				{
					/*
						Assigns the new character every iteration
						then compares each element for a match.
					*/
					snumeric_element = numeric_strings[++sNums];
					if (card_num[1], snumeric_element)
					{
						type_of_bank = "\tVALID: MASTERCARD\n";
						return type_of_bank;
					}
				}
				//=================== DISCOVER ==========
				else if (card_num[0] == '6')
				{
					type_of_bank = "\tVALID: DISCOVER\n";
					return type_of_bank;
				}
			}
		}
	}
	else
	{	
		//=============== AMERICAN EXPRESS ==================
		if (amount_of_digits == 15)
		{
			if (card_num[0] == '3')
			{
				if ((card_num[1] == '4') || (card_num[1] == '7'))
				{
					type_of_bank = "\tVALID: AMERICAN EXPRESS\n";
					return type_of_bank;
				}
			}
		}
	}

	return "";
}

/*
	FUNCTION	:	get_credit_card
	DESCRIPTION	:	This function gets the users credit card number.
	PARAMETERS	:	None
	RETURNS		:	card_num
*/	
long long get_credit_card(void)
{
	long long card_num = 0;

	do
	{
		std::cout << "Please enter in a credit card number: ";
		std::cin >> card_num;
		std::cin.clear();
		fflush(stdin);
	} while (card_num <= 0);

	return card_num;
}