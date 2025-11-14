
#include <functional>
#include <random>



std::vector<unsigned int> birthday_attack_2(std::function<unsigned short(unsigned int)> hash_function);

unsigned short hash(unsigned int input) {
    const unsigned int a = 3177205741;
    const unsigned int b = 2371597069;
    return static_cast<unsigned short>(a*input + b);
}

unsigned short constant_hash(unsigned int input){
    return static_cast<unsigned short>(42);
}

unsigned short modulo_hash(unsigned int input) {
    return static_cast<unsigned short>(input % 100);
}

unsigned short double_hash(unsigned int input) {
    return static_cast<unsigned short>(hash(hash(input)));
}

unsigned short xor_hash(unsigned int input) {
    return static_cast<unsigned short>((input >> 16) ^ (input & 0xFFFF));
}

bool check_collision(std::function<unsigned short(unsigned int)> hf, int tries = 10) {
    for (int i = 0; i < tries; ++i) {
        std::vector<unsigned int> result = birthday_attack_2(hf);
        if (result.size() != 2) {
            continue;
        }
        if (result[0] == result[1]) {
            continue;
        }
        if (hf(result[0]) == hf(result[1])) {
            return true;
        }
    }
    return false;
}

int main() {
    double total_score = 5.0;
    double score = 0.0;
    
    if (check_collision(hash)) {
        printf("Found collision for hash function\n");
        score += 1.0;
    }

    if (check_collision(constant_hash)) {
        printf("Found collision for constant hash function\n");
        score += 1.0;
    }

    if (check_collision(modulo_hash)) {
        printf("Found collision for modulo hash function\n");
        score += 1.0;
    }

    if (check_collision(double_hash)) {
        printf("Found collision for double hash function\n");
        score += 1.0;
    }

    if (check_collision(xor_hash)) {
        printf("Found collision for XOR hash function\n");
        score += 1.0;
    }

    // RESULT(100*(score / total_score));

    printf("Score: %.2f / %.2f\n", score, total_score);

    
    return 0;
}
