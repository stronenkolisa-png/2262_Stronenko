int main() {
    int n = 4;
for (int i = 0; i < n; i++) {
    std::cout << i << " ";
    n = 2;
}
std::cout << '\n';
n = 4;
int cnt = 0;
int end = n;
for (const int &i = cnt; i < end; cnt++) {
    std::cout << i << " ";
    n = 2;
}
