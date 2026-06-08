#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAXN = 105;
const double EPS = 1e-8;

double a[MAXN][MAXN];  // 增广矩阵，a[i][n] 是常数项 b_i
double x[MAXN];        // 存储解

int main() {
    int n;
    cin >> n;

    // 读取增广矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    // 前向消元，将增广矩阵化为上三角矩阵
    for (int col = 0; col < n; ++col) {  // 处理第 col 列（主元列）
        // 步骤1：找到当前列及下方行中绝对值最大的元素（主元）
        int max_row = col;
        for (int row = col; row < n; ++row) {
            if (fabs(a[row][col]) > fabs(a[max_row][col])) {
                max_row = row;
            }
        }

        // 步骤2：若主元为0，说明无解或无穷多解
        if (fabs(a[max_row][col]) < EPS) {
            cout << "No Solution" << endl;
            return 0;
        }

        // 步骤3：交换主元行与当前行
        if (max_row != col) {
            swap(a[col], a[max_row]);
        }

        // 步骤4：归一化当前行，使主元（a[col][col]）变为1
        double div = a[col][col];
        for (int j = col; j <= n; ++j) {
            a[col][j] /= div;
        }

        // 步骤5：消去当前列下方所有行的该列元素（使其为0）
        for (int row = col + 1; row < n; ++row) {
            double factor = a[row][col];
            for (int j = col; j <= n; ++j) {
                a[row][j] -= factor * a[col][j];
            }
        }
    }

    // 后向回代，求解未知数
    x[n - 1] = a[n - 1][n];  // 最后一行只有一个未知数 x[n-1]
    for (int row = n - 2; row >= 0; --row) {
        x[row] = a[row][n];  // 初始值为常数项
        // 减去已求出的未知数的贡献
        for (int col = row + 1; col < n; ++col) {
            x[row] -= a[row][col] * x[col];
        }
    }

    // 输出结果，四舍五入保留2位小数
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; ++i) {
        cout << x[i] << endl;
    }

    return 0;
}
