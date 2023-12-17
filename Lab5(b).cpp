#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5 };

    auto min_it = min_element(numbers.begin(), numbers.end());
    auto max_it = max_element(numbers.begin(), numbers.end());

    iter_swap(min_it, max_it);

    for (auto num : numbers) {
        cout << num << " ";
    }

    return 0;
}
