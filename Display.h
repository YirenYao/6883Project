#pragma once
#include "Group.h"

using namespace std;
namespace fre {
	void plotCAARGraph(
		const Group* BeatGroup,
		const Group* MeetGroup,
		const Group* MissGroup);

	void showReturnMatrix(const Group* group);
}