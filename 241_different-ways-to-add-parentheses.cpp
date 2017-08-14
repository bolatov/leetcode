class Solution {
private:
    struct Node {
        Node* left;
        Node* right;
        bool isLeaf;
        char sign;
        int value;
        Node(int v, bool l, char ch) : value(v), isLeaf(l), sign(ch) {}
    };
    
    vector<int> solve(vector<Node*> nodes) {
        // printf("nodes.size() = %d\n", nodes.size());
        if (nodes.size() == 1) {
            return {nodes[0]->value};
        } else if (nodes.size() == 3 && nodes[0]->isLeaf && nodes[2]->isLeaf) {
            int a = nodes[0]->value;
            int b = nodes[2]->value;
            int res = -1;
            switch (nodes[1]->sign) {
                case '-':
                    res = a - b;
                    break;
                case '+':
                    res = a + b;
                    break;
                case '*':
                    res = a * b;
                    break;
                default:
                    printf("Something is wrong here: %d %c %d\n", a, nodes[1]->sign, b);
                    break;
            }
            return {res};
        }
        
        vector<int> vi;
        for (int i = 1; i + 1 < nodes.size(); i += 2) {
            auto v1 = solve(vector<Node*>(nodes.begin(), nodes.begin() + i));
            auto v2 = solve(vector<Node*>(nodes.begin() + i + 1, nodes.end()));
            
            for (int a : v1) {
                for (int b : v2) {
                    int res = -1;
                    switch (nodes[i]->sign) {
                        case '-':
                            res = a - b;
                            break;
                        case '+':
                            res = a + b;
                            break;
                        case '*':
                            res = a * b;
                            break;
                        default:
                            printf("Something is wrong here: %d %c %d\n", a, nodes[1]->sign, b);
                            break;
                    }
                    vi.push_back(res);
                }
            }
        }
        
        return vi;
    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        int idx = 0;
        input += '-'; // add dummy last character
        vector<Node*> nodes;
        for (int i = 0; i < input.size(); i++) {
            char ch = input[i];
            if (ch == '-' || ch == '+' || ch == '*') {
                string s = input.substr(idx, i - idx);
                int num = stoi(s);
                idx = i + 1;
                
                Node* numNode = new Node(num, true, 'x');
                nodes.push_back(numNode);
                if (i + 1 != input.size()) {
                    Node* signNode = new Node(-1, false, ch);
                    nodes.push_back(signNode);
                }
            }
        }
        return solve(nodes);
    }
};
