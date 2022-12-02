#include <iostream>
#include <torch/torch.h>

using namespace std;

int main() {
    torch::Tensor X = torch::rand({5, 3}, torch::kCUDA);
    cout << X;
    return 0;
}
