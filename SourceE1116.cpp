#include "../std_lib_facilities.h"

void input_file(string& name_file, vector<double>&vn);              // Function for reading numbers from a file
void formatted_output_file(string& name_file, vector<double>&vn);   // Function for formatted output to a file

int main()
{
    vector<double>vn;
    cout << "Enter a file name for reading numbers:\n";
    string name_file;
    cin >> name_file;
    input_file(name_file, vn);
    sort(vn);
    cout << "Enter a file name for formatted output:\n";
    cin >> name_file;
    formatted_output_file(name_file, vn);
    return 0;
}

void input_file(string& name_file, vector<double>&vn)
{
    ifstream ist(name_file);
    if(!ist) error("Unable to open input file ", name_file);
    ist.exceptions(ist.exceptions() | ios_base::badbit);
    for(double temp_num; ist >> temp_num;)
    {
        vn.push_back(temp_num);
    }
}

void formatted_output_file(string& name_file, vector<double>&vn)
{
    ofstream ost{name_file};
   if (!ost) error("Unable to open output file ", name_file);
   ost << scientific << setprecision(8);
   int i = 0;
   for(double x: vn)
   {
       ++i; 
       ost << setw(20) << x;
       if(i == 4)
       {
           ost << '\n';
           i = 0;
       } 
   }
}