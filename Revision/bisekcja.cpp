#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double power(double base, int exp) {
  double result = 1.0;
  for (int i = 1; i <= exp; i++) {
    result *= base;
  }
  return result;
}

double function_value_at_x(double given_x, const vector<double>& x) {
  double result = 0.0;
  int tabSize = x.size();
  for (int i = 0; i < tabSize; i++) {
    result += x[i] * power(given_x, i);
  }
  return result;
}

double binary_search(double a, double b, const vector<double>& x, double epsilon) {
  double mid = (a + b) / 2.0;
  double value_at_mid = function_value_at_x(mid, x);

  if (fabs(value_at_mid) < epsilon || (b - a) / 2.0 < epsilon) {
    return mid;
  }

  if (value_at_mid * function_value_at_x(a, x) < 0) {
    return binary_search(a, mid, x, epsilon);
  } else {
    return binary_search(mid, b, x, epsilon);
  }
}

int main() {
  double a, b;
  int n;

  cout << "a: "; cin >> a;
  cout << "b: "; cin >> b;
  cout << "n: "; cin >> n;

  vector<double> x(n + 1);

  for (int i = 0; i <= n; i++) {
    cout << "x" << i << ": "; cin >> x[i];
  }

  if (b <= a) {
    cout << "B musi być większe niż a" << endl;
    return 1;
  }

  double epsilon = 1e-6; //Dopuszczalny błąd
  double result = binary_search(a, b, x, epsilon);
  cout << fixed << setprecision(3) << "Miejsce zerowe: " << result << endl;

  return 0;
}
