#include <iostream>
using namespace std;

int main() {
    double temp[3][3][3];   // temp[x][y][z]
    double layerAvg[3];

    // 1. Input temperatures
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << "Temperature at (" << x << "," << y << "," << z << "): ";
                cin >> temp[x][y][z];
            }
        }
    }

    // 2. Average temperature per layer (z-axis)
    cout << "\nAverage Temperature per Layer" << endl;
    for (int z = 0; z < 3; z++) {
        double sum = 0;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                sum += temp[x][y][z];
            }
        }
        layerAvg[z] = sum / 9;
        cout << "Layer " << z + 1 << ": " << layerAvg[z] << " C" << endl;
    }

    // 3. Hottest layer
    int hottest = 0;
    for (int z = 1; z < 3; z++) {
        if (layerAvg[z] > layerAvg[hottest]) {
            hottest = z;
        }
    }

    // 4. Maximum temperature point
    double maxTemp = temp[0][0][0];
    int mx = 0, my = 0, mz = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                if (temp[x][y][z] > maxTemp) {
                    maxTemp = temp[x][y][z];
                    mx = x;
                    my = y;
                    mz = z;
                }
            }
        }
    }

    // 5. Final results
    cout << "\nHottest Layer: Layer " << hottest + 1
         << " (Average = " << layerAvg[hottest] << " C)" << endl;
    cout << "Maximum Temperature: " << maxTemp << " C" << endl;
    cout << "Location (x, y, z): (" << mx << ", " << my << ", " << mz << ")" << endl;

    return 0;
}