/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* temp = root;
        vector<int> result;
        if (temp == NULL) return root;

        queue<Node*> q;
        q.push(temp);

        while (!q.empty()) {
            int count = q.size();

            while(count){
                Node* node = q.front();
                q.pop();

                
                if(count==1){
                    node->next  = NULL;
                }
                else{
                    node->next = q.front();
                }

                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
                count--;

            }
            
        }

        return root;
        
    }
};


------------------------------------- Follow-up:------------------------------------------------------

//You may only use constant extra space.


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* head = root;

        while (head != nullptr) {
            Node* dummy = new Node(0);  // Dummy node for the next level
            Node* temp = dummy;

            while (head != nullptr) {
                if (head->left != nullptr) {
                    temp->next = head->left;
                    temp = temp->next;
                }

                if (head->right != nullptr) {
                    temp->next = head->right;
                    temp = temp->next;
                }

                head = head->next;
            }

            head = dummy->next;  // Move to the next level
            delete dummy;        // Free memory
        }

        return root;
    }
};
