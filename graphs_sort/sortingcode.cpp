#include<vector>
#include<chrono>
#include<random>
#include<iostream>
#include<algorithm>
#include<cassert>

using namespace std;
using namespace std::chrono;

constexpr int max_value = 100000;

//символ "&" позволяет менять непосредственно ту переменную, которая передана в функцию
//как питоновский объект
//это замена указателя в современном c++
void bubble(vector<int>& v) {
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = 0; j < v.size() - i - 1; j++) {
      if (v[j] > v[j + 1])
        swap(v[j], v[j + 1]);
    }
  }
}

void heap(vector<int> &v) {
    make_heap(v.begin(), v.end());
    for (auto i = v.end(); i != v.begin(); --i) {
        pop_heap(v.begin(), i);
    }
}

void merge(vector<int>& v) {
    if (1 < v.size()) {
        vector<int> array1(v.begin(), v.begin() + v.size() / 2);
        merge(array1);
        vector<int> array2(v.begin() + v.size() / 2, v.end());
        merge(array2);
        merge(array1.begin(), array1.end(), array2.begin(), array2.end(), v.begin());
    }
}

void gnom(vector<int> &v) {
    for (int i = 0; i < v.size();) {
        if (i == 0 || v[i - 1] <= v[i]) i++;
        else swap(v[i--], v[i - 1]);
    }
}

void self(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) {
            swap(v[i], v[i - 1]);
            i = 0;
        }
    }
}

void std_sort(vector<int>& v) {
    sort(v.begin(), v.end());
}


vector<int> generate_random_vector(uint64_t n) {

    vector<int> ret(n);

    //это математически строгий и надежный способ генерировать случайные числа
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, max_value);

    for (int i = 0; i < n; ++i) {
        ret[i] = dist(gen);
    }

    return ret;
}


//это магическая строчка
//благодаря этому функция может принимать аргумент произвольного типа
//название для конкретно этого типа вы придумываете сами (я назвал его SortFunction)
template<typename SortFunction>
int benchmark(SortFunction f, uint64_t n) {

    auto v = generate_random_vector(n);

    auto start = steady_clock::now();
    //время засекается внутри этого блока
    f(v);
    auto finish = steady_clock::now();

    //это проверка на то, верно ли проведена сортировка
    //в случае ошибки программа падает с сообщением "assertion failed"
    assert(is_sorted(begin(v), end(v)));

    //возвращаем время работы в мс
    return duration_cast<milliseconds>(finish - start).count();
}
