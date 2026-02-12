/*************************************************************************
	> File Name: hz40palouti.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Feb 2026 02:16:56 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 500

class BigInt : public vector<int> {
public:
    BigInt(){push_back(0);}
    BigInt(int x) {
        push_back(x);
        procsee_digit();
    }

    BigInt &operator+=(const BigInt &a) {
        for (int i = 0; i < a.size(); i++) {
            if (i > size())push_back(a[i]);
            else at(i) += a[i];
        }
        procsee_digit();
        return *this;
    }

    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        ret += a;
        return ret;
    }

    void procsee_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i == size() - 1) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }

};

BigInt a[MAX_N + 5];

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    a[1] = 0;a[2] = 1;a[3] = 1;
    for (int i = 4; i <= n; i++) {
        a[i] = a[i - 2] + a[i - 3];
    }
    cout << a[n] << endl;
    return 0;
} 
