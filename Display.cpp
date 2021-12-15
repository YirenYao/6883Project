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

		cout << "AAR:" << endl;
		cout << group->getAAR();
		cout << "AAR Std:" << endl;
		cout << group->getAAR_STD();
		cout << "CAAR:" << endl;
		cout << group->getCAAR();
		cout << "CAAR Std:" << endl;
		cout << group->getCAAR_STD();
	}
}