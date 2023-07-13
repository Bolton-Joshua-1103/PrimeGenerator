#include <iostream>
#include <fstream>
#include <vector>

#define dbgline(x) std::cout << #x << ": " << (x) << std::endl;
using namespace std;

int main() {
   std::vector<int> primes;
   primes.push_back(2);//Seeding with the first prime
   int index = 3;

   while (index < 1000) {
      int prime_count = primes.size();
      bool composite = false;
      for (unsigned int i = 0; i < prime_count; i++) {
         if (index % primes[i] == 0) {
            composite = true;
            break;
         }
      }
      if (composite == false) {
         primes.push_back(index);
      }
      index += 2;
   }

   cout << "PRIME COUNT : " << primes.size() << endl;
   std::ofstream outputfile;
   outputfile.open("primes.txt");

   for (const auto& prime : primes) {
      cout << prime << ", ";
      outputfile << prime << "\n";
   }
   outputfile.close();
}