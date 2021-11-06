#include <iostream>

double GetMedian(double daArray[], int iSize) {
    double* Sorted = new double[iSize];
    for (int i = 0; i < iSize; ++i) {
        Sorted[i] = daArray[i];
    }
    for (int i = iSize - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (Sorted[j] > Sorted[j + 1]) {
                double dTemp = Sorted[j];
                Sorted[j] = Sorted[j + 1];
                Sorted[j + 1] = dTemp;
            }
        }
    }

    double dMedian = 0.0;
    if ((iSize % 2) == 0) {
        dMedian = (Sorted[iSize / 2] + Sorted[(iSize / 2) - 1]) / 2.0;
    }
    else {
        dMedian = Sorted[iSize / 2];
    }
    delete[] Sorted;
    return dMedian;
}

double GetMode(double daArray[], int iSize) {

    int* Repetition = new int[iSize];
    for (int i = 0; i < iSize; ++i) {
        Repetition[i] = 0;
        int j = 0;
        bool bFound = false;
        while ((j < i) && (daArray[i] != daArray[j])) {
            if (daArray[i] != daArray[j]) {
                ++j;
            }
        }
        ++(Repetition[j]);
    }
    int MaxRepeat = 0;
    for (int i = 1; i < iSize; ++i) {
        if (Repetition[i] > Repetition[MaxRepeat]) {
            MaxRepeat = i;
        }
    }
    delete[] Repetition;
    return daArray[MaxRepeat];
}

double GetMean(double daArray[], int iSize) {
    double dSum = daArray[0];
    for (int i = 1; i < iSize; ++i) {
        dSum += daArray[i];
    }
    return dSum / iSize;
}

int main()
{
    double dValues[] = { 3.4, 4.8, 8.4, 9.6, 2.3, 9.6, 5.6, 9.6, 4.8, 2.2 };
    int ArraySize = 10;

    std::cout << "Median = " << GetMedian(dValues, ArraySize) << std::endl;
    std::cout << "Mode = " << GetMode(dValues, ArraySize) << std::endl;
    std::cout << "Mean = " << GetMean(dValues, ArraySize) << std::endl;

    return 0;
}


