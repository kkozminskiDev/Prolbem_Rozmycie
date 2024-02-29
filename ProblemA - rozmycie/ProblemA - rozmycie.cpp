#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<double>> reconstructImage(const vector<vector<double>>& blurredImage, int W, int H, int k) {
    vector<vector<double>> originalImage(H, vector<double>(W, 0.0));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            double sum = 0.0;
            int count = 0;

            for (int x = max(0, i - k); x <= min(H - 1, i + k); ++x) {
                for (int y = max(0, j - k); y <= min(W - 1, j + k); ++y) {
                    sum += blurredImage[x][y];
                    ++count;
                }
            }

            originalImage[i][j] = sum / count;
        }
    }

    return originalImage;
}

int main() {
    int W, H, k;

    while (true) {
        cin >> W >> H >> k;

        vector<vector<double>> blurredImage(H, vector<double>(W, 0.0));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> blurredImage[i][j];
            }
        }

        auto originalImage = reconstructImage(blurredImage, W, H, k);

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cout << fixed << setprecision(2) << setw(8) << originalImage[i][j];
            }
            cout << endl;
        }

        if (cin.peek() == '\n') cin.ignore();
        cout << endl;
    }

    return 0;
}
