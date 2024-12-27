#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
        {
            prev->next = nullptr;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

void preorderTraversal(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

ListNode *createLinkedList(const vector<int> &nums)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int num : nums)
    {
        ListNode *newNode = new ListNode(num);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    ListNode *head = createLinkedList(nums);

    Solution solution;
    TreeNode *root = solution.sortedListToBST(head);

    cout << "Preorder Traversal of the BST: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
