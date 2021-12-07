#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "Group.h"

using namespace std;
namespace fre {
	void plotCAARGraph(
		const Group* BeatGroup,
		const Group* MeetGroup,
		const Group* MissGroup)
	{
		// plot CAAR graph of all 3 groups
	}

	void showReturnMatrix(const Group* group)
	{
		// show AAR, AAR_STD, CAAR, CAAR_STD matrix of one group
	}
	void showReturnMatrix(
		const Group* BeatGroup,
		const Group* MeetGroup,
		const Group* MissGroup)
	{
		// show AAR, AAR_STD, CAAR, CAAR_STD matrix of all 3 groups

	}
}