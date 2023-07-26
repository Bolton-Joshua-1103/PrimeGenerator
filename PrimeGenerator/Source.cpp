#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#define dbgline(x) std::cout << #x << ": " << (x) << std::endl;
using namespace std;

/*
I want to compare this method with a seive method. This is brute force checking each number to see if it is divisible by a prime we've already catpured. If not it's a new prime and we capture it

*/


int main() {
   std::vector<int> primes;
   primes.push_back(2);//Seeding with the first prime
   int index = 3;

   const auto start = std::chrono::steady_clock::now();

   while (primes.size() < 100000) {
      int prime_count = primes.size();
      bool composite = false;
      for (unsigned int i = 1; i < prime_count; i++) {
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

   const auto end = std::chrono::steady_clock::now();
   const std::chrono::duration<double> elapsed_seconds = end - start;

   cout << "PRIME COUNT : " << primes.size() << endl;
   cout << "DURATION: " << elapsed_seconds.count() << endl;

   cout << "Writing to file..." << endl;
   std::ofstream outputfile;
   outputfile.open("primes.txt");

   for (const auto& prime : primes) {
      outputfile << prime << "\n";
   }

   outputfile.close();
}