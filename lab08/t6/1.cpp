int main() {
     for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
    i++;
}
std::cout << '\n';
int cnt = 0;
int end = 5;
for (const int &i = cnt; i < end; cnt++) {
    std::cout << i << " ";
    i++;  
   }
}
