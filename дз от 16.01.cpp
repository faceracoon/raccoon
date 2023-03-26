#include <iostream>

template<typename type>


type swap(type &a, type &b)
{
    type temp = a;
    a = b;
    b = temp;
}

int palindrome(std::string pal, int size) {

        int left = 0;
        int right = size - 1;
        int k;
        int count = 0;

        while (left < right) {
            if (pal[left] == pal[right]) {
                left++;
                right--;
                continue;
            }
            for (k = right - 1; k > left; k--) {
                if (pal[k] == pal[left]) {
                    break;
                }
            }
            for (int j = k; j < right; j++) {
                swap(pal[j], pal[j + 1]);
                count++;
            }
            left++;
            right--;
        }
        return count;
    }

int main() {
    std::string pal = "abcdefacdfeb";
    int size = pal.length();
    std::cout << "Number of swaps: " << palindrome(pal, size) << std::endl;
    return 0;
}
