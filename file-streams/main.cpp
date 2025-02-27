#include "../DebugEx.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

Debug io_db(false, true, false);

void process_input(istream &in, string &valp, vector<string> &lines_container,
                   const string &filename) {
  if (::io_db.any()) {
    cerr << "\nFilename: [" << filename << " ]\n\tFILE START-----------> "
         << endl;
  }

  while (getline(in, valp)) {

    if (!valp.empty()) {
      lines_container.push_back(valp);
      cout << "\n" << valp;
    }
  };
  cout << endl;
}

int main() {
  vector<string> all_lines;
  string test = "./test.txt", test2 = "./test2.txt", logs = "./logs.txt",
         temp_line;
  const string err_msg = "Failed to open file";
  ifstream file1(test), file2(test2);
  ofstream out("log.txt");
  vector<pair<ifstream &, string>> file_pairs = {{file1, test}, {file2, test2}};

  for (auto &[file, name] : file_pairs) {
    io_db.file_check(file, name, runtime_error(err_msg), out);
    while (true) {
      auto old_state = file.rdstate();
      file.clear(file.rdstate() & ~file.failbit & ~file.badbit);
      process_input(file, temp_line, all_lines, name);
      if (!file.good()) {
        if (file.rdstate() == (ios::eofbit | ios::failbit)) {
          if (io_db.any()) {
            cerr << "\n <---------- END OF FILE \n" << endl;
          }
        } else {
          if (io_db.any()) {
            const string err_msg("Failed reading input from: ");
            io_db.log_error(out, name, runtime_error(err_msg));
            cerr << err_msg << "\terror state: " << file.rdstate() << endl;
          }
        }
        break;
      }
      file.setstate(old_state);
    }
    if (file.is_open()) {
      file.close();
      io_db.log_message(out, "Input File Closed!", name);
    }
  }
  return 0;
}
