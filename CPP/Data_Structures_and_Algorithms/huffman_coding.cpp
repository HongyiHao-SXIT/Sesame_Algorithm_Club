#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <memory>
using namespace std;

const int MAX_NODES = 100;

struct HuffmanNode {
    int weight;
    int parent;
    int left_child;
    int right_child;
};

struct MinPair {
    int first;
    int second;
};

class HuffmanEncoder {
private:
    vector<HuffmanNode> tree;
    vector<string> codes;
    string input_string;
    vector<int> weights;

    MinPair findTwoSmallestNodes(int range) {
        MinPair result = {-1, -1};
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int i = 1; i <= range; ++i) {
            if (tree[i].parent == 0) {
                if (tree[i].weight < min1) {
                    min2 = min1;
                    result.second = result.first;
                    min1 = tree[i].weight;
                    result.first = i;
                } else if (tree[i].weight < min2) {
                    min2 = tree[i].weight;
                    result.second = i;
                }
            }
        }
        return result;
    }

public:
    void encode(const string& str, const vector<int>& w) {
        input_string = str;
        weights = w;
        const int n = input_string.size();
        const int total_nodes = 2 * n - 1;

        tree.resize(total_nodes + 1);

        for (int i = 1; i <= n; ++i) {
            tree[i] = {weights[i-1], 0, 0, 0};
        }

        for (int i = n + 1; i <= total_nodes; ++i) {
            auto [s1, s2] = findTwoSmallestNodes(i - 1);
            tree[s1].parent = i;
            tree[s2].parent = i;
            tree[i] = {
                tree[s1].weight + tree[s2].weight,
                0, s1, s2
            };
        }

        codes.resize(n + 1);
        string temp_code(n, ' ');

        for (int i = 1; i <= n; ++i) {
            int current = i;
            int parent = tree[current].parent;
            int code_pos = n - 1;

            while (parent != 0) {
                if (tree[parent].left_child == current) {
                    temp_code[code_pos--] = '0';
                } else {
                    temp_code[code_pos--] = '1';
                }
                current = parent;
                parent = tree[current].parent;
            }

            codes[i] = temp_code.substr(code_pos + 1);
        }
    }

    void displayTree() const {
        cout << "Huffman Tree Structure:\n";
        cout << "Index\tWeight\tParent\tLeft\tRight\n";
        for (size_t i = 1; i < tree.size(); ++i) {
            cout << i << "\t" << tree[i].weight << "\t"
                 << tree[i].parent << "\t"
                 << tree[i].left_child << "\t"
                 << tree[i].right_child << "\n";
        }
    }

    void displayCodes() const {
        cout << "\nHuffman Codes:\n";
        cout << "Char\tWeight\tCode\n";
        for (size_t i = 1; i <= input_string.size(); ++i) {
            cout << input_string[i-1] << "\t"
                 << weights[i-1] << "\t"
                 << codes[i] << "\n";
        }

        cout << "\nCompact Code Representation:\n";
        for (size_t i = 1; i <= input_string.size(); ++i) {
            cout << codes[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    HuffmanEncoder encoder;
    string input;
    vector<int> weights;

    cout << "Enter the string to encode: ";
    getline(cin, input);

    weights.resize(input.size());
    cout << "Enter the weights for each character:\n";
    for (size_t i = 0; i < input.size(); ++i) {
        cout << input[i] << ": ";
        cin >> weights[i];
    }

    encoder.encode(input, weights);
    encoder.displayTree();
    encoder.displayCodes();

    return 0;
}