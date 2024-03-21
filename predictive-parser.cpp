#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

string get_stack(stack<string> st)
{
    string content = "";
    while (!st.empty())
    {
        content = st.top() + content;
        st.pop();
    }
    return content;
}

int main()
{
    map<string, vector<string>> productions;
    productions["E"] = {"TX"};
    productions["X"] = {"+TX", "e"};
    productions["T"] = {"FY"};
    productions["Y"] = {"*FY", "e"};
    productions["F"] = {"i", "(E)"};

    map<string, vector<string>> first;
    first["E"] = {"i", "("};
    first["X"] = {"+", "e"};
    first["T"] = {"i", "("};
    first["Y"] = {"*", "e"};
    first["F"] = {"i", "("};

    map<string, vector<string>> follow;
    follow["E"] = {"$", ")"};
    follow["X"] = {"$", ")"};
    follow["T"] = {"$", ")", "+"};
    follow["Y"] = {"$", ")", "+"};
    follow["F"] = {"$", ")", "+", "*"};

    map<string, map<string, string>> table;
    table["E"]["i"] = "TX";
    table["E"]["("] = "TX";
    table["X"]["+"] = "+TX";
    table["X"]["$"] = "e";
    table["X"][")"] = "e";
    table["T"]["i"] = "FY";
    table["T"]["("] = "FY";
    table["Y"]["+"] = "e";
    table["Y"]["*"] = "*FY";
    table["Y"]["$"] = "e";
    table["Y"][")"] = "e";
    table["F"]["i"] = "i";
    table["F"]["("] = "(E)";

    string input;
    cout << "Enter the input string: ";
    cin >> input;

    input += "$";

    stack<string> st;

    st.push("$");
    st.push("E");
    
    int i = 0;
    cout << "Stack\t\tInput\t\tAction" << endl;
    cout << get_stack(st) << "\t\t" << input.substr(i) << endl;
    while (!st.empty())
    {
        string top = st.top();
        st.pop();

        if (top == input.substr(i, 1))
        {
            i++;
            continue;
        }

        if (table.find(top) == table.end())
        {
            cout << "Error" << endl;
            exit(1);
        }

        if (table[top].find(input.substr(i, 1)) == table[top].end())
        {
            cout << "Error" << endl;
            exit(1);
        }

        string production = table[top][input.substr(i, 1)];
        for (int j = production.size() - 1; j >= 0; j--)
        {
            if (production[j] != 'e')
            {
                st.push(production.substr(j, 1));
            }
        }

        cout << get_stack(st) << "\t\t" << input.substr(i) << "\t\t" << top << " -> " << production << endl;
    }

    cout << "Accepted" << endl;

    return 0;
}
