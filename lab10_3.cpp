#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    ifstream source("score.txt");
    vector<double> scores;
    double num, sum = 0, mean, stddev = 0;
    while (source >> num) {
        scores.push_back(num);
        sum += num;
    }
    source.close();
    int n = scores.size();
    if (n == 0) {
        cout << "No data available in the file." << endl;
        return 0;
    }
    mean = sum / n;
    for (double score : scores) {
        stddev += pow(score - mean, 2);
    }
    stddev = sqrt(stddev / n);
    cout << "Number of data = " << n << endl;
    cout << "Mean = " << setprecision(3) << mean << endl;
    cout << "Standard deviation = " << setprecision(3) << stddev << endl;
    return 0;
}
