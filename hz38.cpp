/*************************************************************************
	> File Name: hz38.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Feb 2026 11:30:30 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 100

class BigInt : public vector<int> {
public :
    BigInt() {push_back(0);}
    BigInt(int x) {
        this->push_back(x);
        process_digit();
    }

    BigInt &operator+=(const BigInt &a) {
        for (int i = 0; i < a.size(); i++) {
            if (i >= size()) push_back(a[i]);
            else at(i) += a[i];
        }
        process_digit();
        return *this;
    }

    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        ret += a;
        return ret;
    }

    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

BigInt f[105];

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    f[1] = 1; f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;

    return 0;
}
