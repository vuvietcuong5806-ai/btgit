#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

const int Sotinh_max = 11;
const int INF = 1e9;    

const string DSTinh[Sotinh_max] = { "HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST" }; 

struct Matran {   // khai báo
    int Sotinhxet;
    int matrix[Sotinh_max][Sotinh_max];
};

