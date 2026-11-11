   int n;
   std::cin >> n;
   std::vector<int> a(n);
   for (int &x : a){
      std::cin >> x;
      }
   int last = a[n-1];
   int pos =0;
   int neg = 0;
   for (int &x : a) {
      x += last;
   if (x > 0){
      ++pos;
      }
   if (x < 0){
      ++neg;
      }
   }
   std::cout << pos << " " << neg << endl;
   }
