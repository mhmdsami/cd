#include <iostream>
#include <string>

using namespace std;

int idx = 0;
string generate_label()
{
    return "L" + to_string(idx++);
}

void generate_if_code(const string &condition, const string &true_label, const string &false_label)
{
    cout << "IF " << condition << " GOTO " << true_label << " ELSE GOTO " << false_label << endl;
}

void generate_while_code(const string &condition, const string &start_label, const string &true_label, const string &end_label)
{
    cout << start_label << ":" << endl;
    cout << "IF " << condition << " GOTO " << true_label << " ELSE GOTO " << end_label << endl;
}

int main()
{
    string if_condition = "x < y";
    string if_true_label = generate_label();
    string if_false_label = generate_label();
    generate_if_code(if_condition, if_true_label, if_false_label);
    cout << if_true_label << ": cout << \"x is less than y\\n\" << endl;" << endl;
    cout << if_false_label << ": cout << \"x is not less than y\\n\" << endl;" << endl;

    string while_condition = "i < 5";
    string while_start_label = generate_label();
    string while_true_label = generate_label();
    string while_end_label = generate_label();
    generate_while_code(while_condition, while_start_label, while_true_label, while_end_label);
    cout << while_true_label << ": cout << \"i: \" << i << \"\\n\" << endl;" << endl;
    cout << "i++;" << endl;
    cout << "GOTO " << while_start_label << ";" << endl;
    cout << while_end_label << ":" << endl;

    return 0;
}
