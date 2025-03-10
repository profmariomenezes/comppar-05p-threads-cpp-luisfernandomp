#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const int N = 1000;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    auto inicio = std::chrono::high_resolution_clock::now();
   
    for(int j = 0; j < N; j++)
        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                C[i][j] += A[i][k] * B[k][j];

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    std::cout << "Tempo de execucao: " << duracao.count() << " microsegundos" << std::endl;

    return 0;
}
