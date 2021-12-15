#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "Group.h"
#include "Matrix.h"

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

		cout << 'AAR:' << endl << group->getAAR();
		cout << 'AAR Std:' << endl << group->getAAR_STD();
		cout << 'CAAR:' << endl << group->getCAAR();
		cout << 'CAAR Std:' << endl << group->getCAAR_STD();
	}
}