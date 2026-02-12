/*************************************************************************
	> File Name: zuixiaogbs.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Feb 2026 03:14:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    else return gcd(b % a, a);
}

int main() {
    int a, b;
    cin >> a >> b;
    int c = gcd(a, b);
    cout << a * b / c << endl;

    return 0;
}
