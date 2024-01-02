#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

double solve(double x1, double y1, double x2, double y2, double R) {
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / 2.0;
    if (d >= R) return 2 * M_PI * R * R;

    double alpha = acos(d / R);

    return 2 * ((M_PI - alpha) * R * R + d * sqrt(R * R - d * d));
}

int main() {
    ifstream reader("INPUT", ios::in);
    ofstream writer("OUTPUT", ios::out);

    double x1, y1, x2, y2, R;
    reader >> x1 >> y1 >> x2 >> y2 >> R;

    writer << fixed << setprecision(3) << solve(x1, y1, x2, y2, R) << "\n";

    reader.close();
    writer.close();
    return 0;
}