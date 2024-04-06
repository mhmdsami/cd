#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void print_tree(Node *root, string prefix = "", bool is_left = true)
{
    if (root == NULL)
    {
        return;
    }

    cout << prefix;

    cout << (is_left ? "├──" : "└──");

    cout << root->data << endl;

    print_tree(root->left, prefix + (is_left ? "│  " : "   "), true);
    print_tree(root->right, prefix + (is_left ? "│  " : "   "), false);
}

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node *parse_expression(string expression)
{
    Node *root = NULL;

    int operator_index = -1;

    for (int i = 0; i < expression.length(); i++)
    {
        if (is_operator(expression[i]))
        {
            operator_index = i;
            break;
        }
    }

    if (operator_index == -1)
    {
        root = new Node(expression[0]);
    }
    else
    {
        root = new Node(expression[operator_index]);

        string left_expression = expression.substr(0, operator_index);
        string right_expression = expression.substr(operator_index + 1);

        root->left = parse_expression(left_expression);
        root->right = parse_expression(right_expression);
    }

    return root;
}

void preorder_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

float evaluate_expression(Node *root)
{
    if (root == NULL)
    {
        return 0.0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root->data - '0';
    }

    float left = evaluate_expression(root->left);
    float right = evaluate_expression(root->right);

    if (root->data == '+')
    {
        return left + right;
    }
    else if (root->data == '-')
    {
        return left - right;
    }
    else if (root->data == '*')
    {
        return left * right;
    }
    else if (root->data == '/')
    {
        return left / right;
    }

    return 0.0;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <expression>" << endl;
        return 1;
    }

    string expression = argv[1];
    cout << "Expression: " << expression << endl;
    Node *root = parse_expression(expression);

    cout << "Syntax Tree:" << endl;
    print_tree(root);

    cout << "Preorder Traversal: ";
    preorder_traversal(root);
    cout << endl;

    cout << "Result: " << evaluate_expression(root) << endl;
}
