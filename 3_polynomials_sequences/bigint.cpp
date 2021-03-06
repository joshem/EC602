//Copyright 2017 Sihan Wang shwang95@bu.edu

#include <vector>
#include <string>

using namespace std;

typedef string BigInt;

BigInt multiply_int(const BigInt &a, const BigInt &b) {
  vector<int> x;
  vector<int> h;

  //Convert to int vector

  for(auto i = a.begin(); i != a.end(); ++i)
    x.push_back(*i - '0');
  for(auto i = b.begin(); i != b.end(); ++i)
    h.push_back(*i - '0');

  int M = x.size(), N = h.size();

  vector<int> c(M + N - 1);

  //Convolution

  for(int i = M; i < M + N - 1; i++)
    x.push_back(0);
  for(int i = N; i < M + N - 1; i++)
    h.push_back(0);
  for(int i = 0; i < M + N - 1; i++) {
    c[i] = 0;
    for(int j = 0; j <= i; j++)
      c[i] += (x[j] * h[i - j]);
  }

  //Drop 0s at the end of vectors

  int i = c.size() - 1;

  while(c.size() > 1) {
    if(c[i] == 0 && i != 0)
      c.pop_back();
    else
      break;
    i--;
  }

  //Convert to String

  vector<int> sol;
  int tmp = 0, co = 0, add = 0;

  for(int i = c.size() - 1; i >= 0; i--) {
    tmp = c[i] + co;
    add = tmp % 10;
    sol.insert(sol.begin(), add);
    co = tmp / 10;
    if(i == 0 && co != 0)
      sol.insert(sol.begin(), co);
  }

  BigInt str = "";
  for(auto i = sol.begin(); i != sol.end(); ++i)
    str += to_string(*i);

  return str;
}