// RankTeamsbyVotes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

uint16_t chartoIndexMapping(char newChar)
{
	//cast the char into decimal and subtract 65 which is the value of A
	//So our 0 index is A, B is 1 and so on
	return (static_cast <uint16_t>(newChar) - 65U);
}


char IndexBacktoChar (uint16_t index)
{
	//give me back my Uppercase letter from the index + 65U for the A which is 1st letter
	return (static_cast <char>(index + 65U));
}


string rankTeams(vector<string>& votes) 
{
	if (votes.size() <= 1)
	{
		return votes[0];
	}
	//this vector holds 
	vector<uint32_t> IndexVector(26);
	string FinalRank { };
	uint16_t Place = 0U;

	while (Place < votes[0].size())
	{
		
		for (uint32_t i = 0U ; i < votes.size(); ++i)
		{
			IndexVector[chartoIndexMapping(votes[i][Place])]++;
		}

		// Get the iterator pointing to largest element in vector
		auto it = std::max_element(IndexVector.begin(), IndexVector.end());

		if (it != IndexVector.end())
		{
			// Get the distance of iterator from the beginning of vector
			uint16_t index = std::distance(IndexVector.begin(), it);
			FinalRank.push_back({IndexBacktoChar(index)});
		}
		Place++;
		fill(IndexVector.begin(), IndexVector.end(), 0U);
	}

	return FinalRank;
}


int main()
{
	vector<string> votes = { "WXYZ","XYZW" };
	string FinalRank = rankTeams(votes);

	cout << "The final rank is : " << FinalRank << endl;
	while (true)
	{

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
