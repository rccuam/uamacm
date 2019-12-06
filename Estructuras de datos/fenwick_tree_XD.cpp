#include <iostream>
#include <vector>

class fenwick_tree {
public:
   fenwick_tree(int n)
   : mem_(n + 1) {
   }

   void actualiza(int i, int v) {
      for (i += 1; i < mem_.size( ); i += (i & -i)) {
         mem_[i] += v;
      }
   }

   int cuenta(int i) {
      int res = 0;
      for (i += 1; i != 0; i -= (i & -i)) {
         res += mem_[i];
      }
      return res;
   }

private:
   std::vector<int> mem_;
};

class fenwick_tree_2d {
public:
   fenwick_tree_2d(int n, int m)
   : mem_(n + 1, fenwick_tree(m)) {
   }

   void actualiza(int i, int j, int v) {
      for (i += 1; i < mem_.size( ); i += (i & -i)) {
         mem_[i].actualiza(j, v);
      }
   }

   int cuenta(int i, int j) {
      int res = 0;
      for (i += 1; i != 0; i -= (i & -i)) {
         res += mem_[i].cuenta(j);
      }
      return res;
   }

private:
   std::vector<fenwick_tree> mem_;
};

int main( ) {
   fenwick_tree_2d arbol(10, 10);

   arbol.actualiza(2, 2, +1);
   for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
         std::cout << arbol.cuenta(i, j) << " ";
      }
      std::cout << "\n";
   }
}
