#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "Group.h"
#include "Matrix.h"

using namespace std;
namespace fre {
    
    //helper function for plotCAARGraph
    void plotResults(const Vector& xData, const Vector& miss_CAAR, const Vector& meet_CAAR, const Vector& beat_CAAR, const int dataSize) {
        FILE* gnuplotPipe, * tempDataFile;
        const char* label1 = "Miss CAAR";
        const char* label2 = "Meet CAAR";
        const char* label3 = "Beat CAAR";
        double x, y;
        int i;
        // gnuplotPipe = popen("/opt/local/bin/gnuplot","w");       for MAC
        gnuplotPipe = _popen("gnuplot.exe", "w");
        if (gnuplotPipe) {
            fprintf(gnuplotPipe, "plot \"%s\" with lines, \"%s\" with lines, \"%s\" with lines\n", label1, label2, label3);
            fflush(gnuplotPipe);

            // plot miss CAAR
            tempDataFile = fopen(label1, "w");
            for (i = 0; i < dataSize; i++) {
                x = xData[i];
                y = miss_CAAR[i];
                fprintf(tempDataFile, "%lf %lf\n", x, y);
            }
            fclose(tempDataFile);

            // plot meet CAAR
            tempDataFile = fopen(label2, "w");
            for (i = 0; i < dataSize; i++) {
                x = xData[i];
                y = meet_CAAR[i];
                fprintf(tempDataFile, "%lf %lf\n", x, y);
            }
            fclose(tempDataFile);

            // plot beat CAAR
            tempDataFile = fopen(label3, "w");
            for (i = 0; i < dataSize; i++) {
                x = xData[i];
                y = beat_CAAR[i];
                fprintf(tempDataFile, "%lf %lf\n", x, y);
            }
            fclose(tempDataFile);

            printf("press enter to continue...");
            getchar();
            remove(label1);
            remove(label2);
            remove(label3);
            fprintf(gnuplotPipe, "exit \n");
        }
        else {
            printf("gnuplot not found...");
        }
    }

	void plotCAARGraph(
		const Group* BeatGroup,
		const Group* MeetGroup,
		const Group* MissGroup)
	{
		// plot CAAR graph of all 3 groups
		int N = (int)(BeatGroup->getCAAR().size()/2);
		Vector xData(2*N);
		for (int i = 0; i < 2*N; i++) {
			xData[i] = -(N-1) + i ; 
		}

		plotResults(xData, MissGroup->getCAAR(), MeetGroup->getCAAR(), BeatGroup->getCAAR(), 2*N);
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