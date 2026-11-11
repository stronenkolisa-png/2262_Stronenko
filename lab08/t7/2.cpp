int main() {
int x;
bool found = false;
while (std::cin >> x) {
    if (x < 0) {
        std::cout << x;
        found = true;
        break;
    }
}
if (found == false) {
    std::cout << "Отрицательных чисел нет";
 }
}
