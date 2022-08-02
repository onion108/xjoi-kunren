/* #lang = C++ */ #include <iostream>
/* #lang = C++ */ #include <string>
/* #lang = C++ */ using std::cin;
/* #lang = C++ */ using std::cout;
/* #lang = C++ */ using std::endl;
/* #lang = C++ */ using std::getline;
/* #lang = C++ */ 
/* #lang = C++ */ int char_to_times[0x80];
/* #lang = C++ */ 
/* #lang = C++ */ void init_char_to_times() {
/* #lang = C++ */   char_to_times['a'] = 1;
/* #lang = C++ */   char_to_times['b'] = 2;
/* #lang = C++ */   char_to_times['c'] = 3;
/* #lang = C++ */   char_to_times['d'] = 1;
/* #lang = C++ */   char_to_times['e'] = 2;
/* #lang = C++ */   char_to_times['f'] = 3;
/* #lang = C++ */   char_to_times['g'] = 1;
/* #lang = C++ */   char_to_times['h'] = 2;
/* #lang = C++ */   char_to_times['i'] = 3;
/* #lang = C++ */   char_to_times['j'] = 1;
/* #lang = C++ */   char_to_times['k'] = 2;
/* #lang = C++ */   char_to_times['l'] = 3;
/* #lang = C++ */   char_to_times['m'] = 1;
/* #lang = C++ */   char_to_times['n'] = 2;
/* #lang = C++ */   char_to_times['o'] = 3;
/* #lang = C++ */   char_to_times['p'] = 1;
/* #lang = C++ */   char_to_times['q'] = 2;
/* #lang = C++ */   char_to_times['r'] = 3;
/* #lang = C++ */   char_to_times['s'] = 4;
/* #lang = C++ */   char_to_times['t'] = 1;
/* #lang = C++ */   char_to_times['u'] = 2;
/* #lang = C++ */   char_to_times['v'] = 3;
/* #lang = C++ */   char_to_times['w'] = 1;
/* #lang = C++ */   char_to_times['x'] = 2;
/* #lang = C++ */   char_to_times['y'] = 3;
/* #lang = C++ */   char_to_times['z'] = 4;
/* #lang = C++ */   char_to_times[' '] = 1;
/* #lang = C++ */ }
/* #lang = C++ */ 
/* #lang = C++ */ int key_times_of(char c) {
/* #lang = C++ */   if ((c >= 'a' && c <= 'z') || c == 0x20) {
/* #lang = C++ */     return char_to_times[c];
/* #lang = C++ */   } else {
/* #lang = C++ */     return 0;
/* #lang = C++ */   }
/* #lang = C++ */ }
/* #lang = C++ */ 
/* #lang = C++ */ int main() {
/* #lang = C++ */   std::string s;
/* #lang = C++ */   getline(cin, s);
/* #lang = C++ */   init_char_to_times();
/* #lang = C++ */   
/* #lang = C++ */   int result = 0;
/* #lang = C++ */   for (auto i : s) {
/* #lang = C++ */     result += key_times_of(i);
/* #lang = C++ */   }
/* #lang = C++ */   cout << result << endl;
/* #lang = C++ */ }
/* #lang = C++ */ 
